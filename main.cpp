#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>


int main()
{
	sf::Window window(sf::VideoMode(500,500),"new window",sf::Style::Titlebar);
	sf::Window window2(sf::VideoMode(200,200),"another");
	while (window.isOpen()){
		sf::Event event,event2;
		while (window2.pollEvent(event2) || window.pollEvent(event)){
			std::cout << 123;
			//window2.pollEvent(event2);
			if (event2.type == sf::Event::Closed){
				window.close();
				window2.close();
			}
		}
	}


	return 0;
}