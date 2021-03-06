#include "Menu.h"
#include "MusicPlayer.h"

Menu::Menu(sf::RenderWindow * window_) : window(window_)
{
}


Menu::~Menu()
{
}

bool Menu::Initialize() {
	sceneName = "Menu";
	changeScene = false;

	if (!font.loadFromFile("arial.ttf")) printf("Error: cannot load font\n");

	// Create title text
	title = sf::Text("Symptomania", font);
	title.setCharacterSize(75);
	title.setStyle(sf::Text::Bold);
	title.setFillColor(sf::Color::Cyan);
	title.setOrigin(title.getLocalBounds().width / 2, title.getLocalBounds().height / 2);
	title.setPosition(window->getView().getCenter().x, window->getView().getCenter().y / 3);

	backdrop = sf::RectangleShape(sf::Vector2f(window->getSize()));
	backdrop.setPosition(0, 0);
	backdrop.setFillColor(sf::Color::Black);
	
	//Create playButton
	playButton = sf::RectangleShape(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 10));
	playButton.setOrigin(playButton.getSize().x / 2, playButton.getSize().y / 2);
	playButton.setPosition(window->getSize().x / 2, (window->getSize().y / 5) * 2);
	playButton.setFillColor(sf::Color::Cyan);
	//playButton text
	playText = sf::Text("Play", font);
	playText.setCharacterSize(40);
	playText.setStyle(sf::Text::Bold);
	playText.setFillColor(sf::Color::Black);
	playText.setOrigin(playText.getLocalBounds().width / 2, playText.getLocalBounds().height / 2);
	playText.setPosition(playButton.getPosition());

	//Create quitButton
	quitButton = sf::RectangleShape(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 10));
	quitButton.setOrigin(quitButton.getSize().x / 2, quitButton.getSize().y / 2);
	quitButton.setPosition(window->getSize().x / 2, (window->getSize().y / 5) * 3);
	quitButton.setFillColor(sf::Color::Cyan);
	//quitButton text
	quitText = sf::Text("Quit", font);
	quitText.setCharacterSize(40);
	quitText.setStyle(sf::Text::Bold);
	quitText.setFillColor(sf::Color::Black);
	quitText.setOrigin(quitText.getLocalBounds().width / 2, quitText.getLocalBounds().height / 2);
	quitText.setPosition(quitButton.getPosition());

		

	return true;
}

void Menu::Destroy() {

}

void Menu::HandleEvents(const sf::Event event) {
	if (event.type == sf::Event::MouseButtonPressed) {
		if (event.mouseButton.button == sf::Mouse::Left) {
			sf::Vector2i pixelPos = sf::Mouse::getPosition(*window);
			//if clicked on play button
			if (pixelPos.x <= playButton.getPosition().x + (playButton.getSize().x / 2)
				&& pixelPos.x >= playButton.getPosition().x - (playButton.getSize().x / 2)
				&& pixelPos.y <= playButton.getPosition().y + (playButton.getSize().y / 2)
				&& pixelPos.y >= playButton.getPosition().y - (playButton.getSize().y / 2))
			{
				MusicPlayer::GetInstance()->PlaySelectSound();
				changeScene = true;
			}

			if (pixelPos.x <= quitButton.getPosition().x + (quitButton.getSize().x / 2)
				&& pixelPos.x >= quitButton.getPosition().x - (quitButton.getSize().x / 2)
				&& pixelPos.y <= quitButton.getPosition().y + (quitButton.getSize().y / 2)
				&& pixelPos.y >= quitButton.getPosition().y - (quitButton.getSize().y / 2))
			{
				MusicPlayer::GetInstance()->PlaySelectSound();
				quit = true;
			}
		}

	}
}

void Menu::Update() {

}

void Menu::Render() {
	window->clear();

	window->draw(backdrop);
	window->draw(playButton);
	window->draw(quitButton);
	
	window->draw(playText);
	window->draw(quitText);
	window->draw(title);

	window->display();
}