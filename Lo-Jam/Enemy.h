#pragma once
#ifndef ENEMY_H
#define ENEMY_H
#include "Entity.h"
#include <random>

class Enemy : public Entity
{

public:
	static sf::Clock timelapse;
	static std::default_random_engine pgenerator;
private:
	sf::IntRect sourceRectImage;
	sf::Vector2<float> playerPosition;
	bool isTriggered;
	bool isVisible;
	class Camera *camera;
public:
	Enemy(std::string ID);
	~Enemy(); 

	void Update();
	
	
	void SetPlayerPosition(sf::Vector2<float>);

	void StartPatrolMovement();
	bool InView();


private:
	void Animate();

};


#endif // !ENEMY_H
