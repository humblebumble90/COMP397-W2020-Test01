#pragma once
#ifndef __LEVEL_1_SCENE__
#define __LEVEL_1_SCENE__

#include "Scene.h"
#include "RollButton.h"
#include "Dice1.h"
#include "Dice2.h"
#include "Dice3.h"
#include "Dice4.h"
#include "Dice5.h"
#include "Dice6.h"
#include "Label.h"

class Level1Scene : public Scene
{
public:
	Level1Scene();
	~Level1Scene();
	
	void draw() override;
	void update() override;
	void clean() override;
	void handleEvents() override;
	void start() override;

	void roll();

	// getters
	glm::vec2 getMousePosition();

private:
	// game objects
	RollButton* m_pRollButton;
	
	Dice1* m_pDice1;
	Dice2* m_pDice2;
	Dice3* m_pDice3;
	Dice4* m_pDice4;
	Dice5* m_pDice5;
	Dice6* m_pDice6;

	
	Label* m_pfirstNumLabel;
	Label* m_psecondNumLabel;


	// private data member
	glm::vec2 m_mousePosition;
	int firstNum = 0;
	int secondNum = 0;
	
	
};

#endif /* defined (__LEVEL_1_SCENE__) */
