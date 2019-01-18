#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>

void fun1();
void check_keyboard(const sf::Event &event);
void check_mouse(const sf::Event &event);
sf::Texture init_texture(const std::string &s);
sf::Sprite init_sprite(const sf::Texture & tex);
void modify_sprite(sf::Sprite &spr);
sf::Text init_text(const std::wstring & s,const sf::Font & font);
sf::Font init_font(const std::string & s);
sf::VertexArray init_vertexarray();
sf::View init_view ();


//class　

int main()
{
	fun1();
	return 0;
}


void check_keyboard(const sf::Event &event){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){ //检测键盘信息
		std::cout << "up\n";
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
		std::cout << "down\n";
	}
}

void check_mouse(const sf::Event &event)
{
	if (event.type == sf::Event::MouseButtonPressed){ //检测鼠标
		if (event.mouseButton.button == sf::Mouse::Right){
			std::cout << event.mouseButton.x << std::endl;
			std::cout << event.mouseButton.y << std::endl;
		}
	}

	if (event.type == sf::Event::MouseButtonReleased){ //检测鼠标释放
		std::cout << "realease" << std::endl;
	}

}

sf::Sprite init_sprite(const sf::Texture & tex){
	sf::Sprite spr;
	spr.setTexture(tex);//设置纹理
	spr.setTextureRect(sf::IntRect(0,0,100,100));//选择纹理区域
	spr.setColor(sf::Color(255,0,0,120));//设置颜色透明度
	spr.setPosition(sf::Vector2f(100,100));//设置位置
	spr.setRotation(90);//旋转
	spr.setScale(sf::Vector2f(2,2));//设置大小
	spr.setOrigin(sf::Vector2f(50,50));//设置中心点
	return spr;
}

sf::Texture init_texture(const std::string &s){
	sf::Texture tex;//纹理
	if (tex.loadFromFile(s)) std::cout << "success!\n";//打开图片作为纹理 s 为图片路径
	tex.setSmooth(true); //平滑
	tex.setRepeated(false); //重复 当选择的区域大于图片时是否重复
	return tex;
}

void modify_sprite(sf::Sprite &spr){
		spr.move(sf::Vector2f(0.01,0.01));//移动
		spr.rotate(0.1);//旋转
		spr.scale(sf::Vector2f(0.9999,0.9999));//大小
}

sf::Text init_text(const std::wstring & s,const sf::Font & font){
	sf::Text text;
	text.setString(s); //设置字符串
	text.setFont(font); //设置字体
	text.setCharacterSize(36); //文字大小
	text.setFillColor(sf::Color::Blue); //颜色
	text.setStyle(sf::Text::Bold | sf::Text::Underlined | sf::Text::Italic | sf::Text::StrikeThrough);
	//属性
	return text;
}

sf::Font init_font(const std::string & s){
	sf::Font font;
	if (font.loadFromFile(s)) std::cout << "font success\n";
	return font;
}

sf::VertexArray init_vertexarray(){
/*
	初始化一个vertex
	sf::Vertex ver (sf::Vector2f(20,20),sf::Color::Magenta,sf::Vector2f(30,40));
	ver.position = sf::Vector2f(20,20);
	ver.color = sf::Color::Magenta;
	ver.texCoords = sf::Vector2(30,40);
*/
	sf::VertexArray ver(sf::Triangles,3);
	ver[0] = sf::Vertex(sf::Vector2f(20,20),sf::Color::Blue,sf::Vector2f(0,0));
	ver[1] = sf::Vertex(sf::Vector2f(100,100),sf::Color::Green,sf::Vector2f(0,0));
	ver[2] = sf::Vertex(sf::Vector2f(100,20),sf::Color::Red,sf::Vector2f(0,0));
	
	return ver;
}

sf::View init_view (){
	sf::View vi(sf::Vector2f(0,0),sf::Vector2f(1000,1000));// 设置视角的中心和大小
	vi.setViewport(sf::FloatRect(0,0,0.9,0.9)); // 设置视角在窗口的相对位置 (起始x,起始y,x大小,y大小)
	return vi;
}

template<typename T1,typename T2>
bool check_collision(const T1 &a,const T2 &b){ //碰撞检测
	sf::FloatRect box1 = a.getGlobalBounds();
	sf::FloatRect box2 = b.getGlobalBounds();
	return box1.intersects(box2);
}

void fun1(){
	sf::RenderWindow window(sf::VideoMode(500,500),"new window"); //RenderWindow 绘制图形
	sf::Color co(123,123,123,255); //设置颜色
	auto tex = init_texture("tex.png");
	auto spr = init_sprite(tex); //精灵和对应的纹理要在一个生存周期里面
	auto font = init_font("font.ttf");
	auto text = init_text(L"123啦hello啦world啦!",font); //中文需要宽字符
	auto ver = init_vertexarray();
	auto vi = init_view();
/*	sf::View vi(sf::Vector2f(0,0),sf::Vector2f(300,300));// 设置视角的中心和大小
	vi.setViewport(sf::FloatRect(0,0,0.5,0.5)); // 设置视角在窗口的相对位置 (起始x,起始y,x大小,y大小)

	sf::View vi2(sf::Vector2f(0,0),sf::Vector2f(300,300));// 设置视角的中心和大小
	vi2.setViewport(sf::FloatRect(0.5,0.5,0.5,0.5)); // 设置视角在窗口的相对位置 (起始x,起始y,x大小,y大小)
*/	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			check_keyboard(event);
			check_mouse(event);
			if (event.type == sf::Event::Closed){ // 检测关闭
				window.close();
			}
		}

		window.clear(co);//清屏
		modify_sprite(spr);
		//vi.zoom(1.0002);//改变视图大小
//		window.setView(vi2); //先设置视图 再draw
//		window.draw(text);
//		window.draw(ver);
//		window.draw(spr);
		window.setView(vi);
		if (check_collision(spr,text)) window.draw(ver);
		window.draw(text);
		window.draw(spr);
		window.display();//显示绘制内容
	}

}
