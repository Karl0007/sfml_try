#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>

void fun1();
void check_keyboard(const sf::Event &event);
void check_mouse(const sf::Event &event);


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


void fun1(){
	sf::RenderWindow window(sf::VideoMode(500,500),"new window"); //RenderWindow 绘制图形
	sf::Color co(123,123,123,255); //设置颜色
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


		window.display();//显示绘制内容
	}

}
