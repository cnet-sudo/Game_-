#include "GameEngine.h"

GameEngine::GameEngine() {

	m_window.create(sf::VideoMode(1280, 720), L"Моя игра", sf::Style::Default);
	m_background.setFillColor(sf::Color::Green);
	if (!m_icon.loadFromFile("game.png")) exit(3); 
	m_window.setIcon(128, 128, m_icon.getPixelsPtr());

}




void GameEngine::input() {
	
	sf::Event event;

	while (m_window.pollEvent(event)) {

		if ((event.key.code == sf::Keyboard::Escape) || (event.type == sf::Event::Closed)) 	m_window.close(); 
	}
}

void GameEngine::update(sf::Time const& deltaTime) {


}

void GameEngine::draw() {
	
	m_window.clear();
	m_window.draw(m_background);
	m_window.display();
}



void GameEngine::run() {

	sf::Clock clock;
	
	while (m_window.isOpen()) {
		
		sf::Time dt = clock.restart();

		input();
		update(dt);
		draw();
	}
}
