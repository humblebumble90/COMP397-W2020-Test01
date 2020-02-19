#pragma once
#ifndef __DICE5__
#define __DICE5__

#include"DisplayObject.h"
#include "Config.h"
#include <SDL_hints.h>

class Dice5 : public DisplayObject
{
public:
	Dice5(std::string imagePath = "../Assets/textures/5.png",
		std::string name = "Dice5",
		GameObjectType type = DICE5,
		glm::vec2 position = glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.1f), bool isCentered = false);
	~Dice5();
	void draw() override;
	void update() override;
	void clean() override;
private:
	std::string m_name;
	Uint8 m_alpha;
	bool m_isCentered;
};
#endif /*Defined(__DICE5__)*/
