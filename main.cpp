#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>


int main()
{
	sf::RenderWindow window(sf::VideoMode(500,500),"new window");
	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			//std::cout << 123;
			//window2.pollEvent(event2);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
				std::cout << "up\n";
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
				std::cout << "down\n";
			}
			
			if (event.type == sf::Event::MouseButtonPressed){
				if (event.mouseButton.button == sf::Mouse::Right){
					std::cout << event.mouseButton.x << std::endl;
					std::cout << event.mouseButton.y << std::endl;
				}
			}

			if (event.type == sf::Event::Closed){
				window.close();
			}
		}
	}


	return 0;
}