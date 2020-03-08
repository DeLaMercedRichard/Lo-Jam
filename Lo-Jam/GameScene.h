#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "Scene.h"

class GameScene : public Scene
{
	
private:
	class Camera* camera;
	class Player* player;
	class Entity* dog;
	class Enemy* enemy;
	std::vector<Enemy*> enemies;


	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	std::string	backgroundTextureName;

	sf::RenderWindow* window;
	sf::View view;
	sf::Clock worldTimer;

	bool triggered;
	
public:
	GameScene(sf::RenderWindow * window_);
	GameScene(sf::RenderWindow * window_, std::string backgroundTexture);
	~GameScene();

	bool Initialize();
	void Destroy();
	void HandleEvents(sf::Event event) const;
	void Update();
	void Render();

	bool SetBackground(std::string textureName);
};

#endif // !GAMESCENE_H