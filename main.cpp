#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>

void fun1();
void check_keyboard(const sf::Event &event);
void check_mouse(const sf::Event &event);
sf::Texture init_texture(const std::string &s);
sf::Sprite init_sprite(const sf::Texture & tex);
void modify_sprite(sf::Sprite &spr);


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
	std::cout << "success";
	return tex;
}

void modify_sprite(sf::Sprite &spr){
		spr.move(sf::Vector2f(0.01,0.01));//移动
		spr.rotate(0.1);//旋转
		spr.scale(sf::Vector2f(0.9999,0.9999));//大小
}

void fun1(){
	sf::RenderWindow window(sf::VideoMode(500,500),"new window"); //RenderWindow 绘制图形
	sf::Color co(123,123,123,255); //设置颜色
	auto tex = init_texture("tex.png");
	auto spr = init_sprite(tex); //精灵和对应的纹理要在一个生存周期里面
	while (window.isOpen()){
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
		window.draw(spr);

		window.display();//显示绘制内容
	}

}
