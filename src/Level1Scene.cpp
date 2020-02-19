#include "Level1Scene.h"
#include "Game.h"
#include <iostream>
/*
 * Author: 'Phillip' Hyungseok lee.
 * Reference: Provided several templates from the professor Tom Tsiliopoulos's 2020 Winter COMP397 course.
 * StudentNumber: 301011097
 * Written date : 02-20-2020
 * Description: The dice game's level1 scene.
 */
Level1Scene::Level1Scene()
{
	start();
}

Level1Scene::~Level1Scene()
{
}

void Level1Scene::draw()
{
	m_istruct->draw();
	m_pfirstNumLabel->draw();
	m_psecondNumLabel->draw();
	
	m_pRollButton->draw();

	switch(firstNum)
	{
	case 1:
		m_pDice1 = new Dice1();
		m_pDice1->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.25f, Config::SCREEN_HEIGHT * 0.25f));
		m_pDice1->draw();		
			break;
		case 2:
			m_pDice2 = new Dice2();
			m_pDice2->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.25f, Config::SCREEN_HEIGHT * 0.25f));
			m_pDice2->draw();
			break;
		case 3:
			m_pDice3 = new Dice3();
			m_pDice3->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.25f, Config::SCREEN_HEIGHT * 0.25f));
			m_pDice3->draw();
			break;
		case 4:
			m_pDice4 = new Dice4();
			m_pDice4->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.25f, Config::SCREEN_HEIGHT * 0.25f));
			m_pDice4->draw();
			break;
		case 5:
			m_pDice5 = new Dice5();
			m_pDice5->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.25f, Config::SCREEN_HEIGHT * 0.25f));
			m_pDice5->draw();
			break;
		case 6:
			m_pDice6 = new Dice6();
			m_pDice6->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.25f, Config::SCREEN_HEIGHT * 0.25f));
			m_pDice6->draw();
			break;
	}
	switch (secondNum)
	{
	case 1:
		m_pDice1 = new Dice1();
		m_pDice1->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.75f, Config::SCREEN_HEIGHT * 0.25f));
		m_pDice1->draw();
		break;
	case 2:
		m_pDice2 = new Dice2();
		m_pDice2->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.75f, Config::SCREEN_HEIGHT * 0.25f));
		m_pDice2->draw();
		break;
	case 3:
		m_pDice3 = new Dice3();
		m_pDice3->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.75f, Config::SCREEN_HEIGHT * 0.25f));
		m_pDice3->draw();
		break;
	case 4:
		m_pDice4 = new Dice4();
		m_pDice4->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.75f, Config::SCREEN_HEIGHT * 0.25f));
		m_pDice4->draw();
		break;
	case 5:
		m_pDice5 = new Dice5();
		m_pDice5->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.75f, Config::SCREEN_HEIGHT * 0.25f));
		m_pDice5->draw();
		break;
	case 6:
		m_pDice6 = new Dice6();
		m_pDice6->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.75f, Config::SCREEN_HEIGHT * 0.25f));
		m_pDice6->draw();
		break;
	}
	
}

void Level1Scene::update()
{
	m_pRollButton->setMousePosition(m_mousePosition);
	if( m_pRollButton->ButtonClick())
	{
		std::cout << "Cicked!\n";
		roll();
		m_pRollButton->setMouseButtonClicked(false); /*
		The boolean has to be restricted after implemented once. Otherwise, the if statement infinitely works while button is pushed*/
	}
	if(firstNum > 0 && secondNum > 0)
	{
		m_pfirstNumLabel->setText(std::to_string(firstNum));
		m_psecondNumLabel->setText(std::to_string(secondNum));
	}
}

void Level1Scene::clean()
{
}

void Level1Scene::handleEvents()
{
	int wheel = 0;

	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			m_mousePosition.x = event.motion.x;
			m_mousePosition.y = event.motion.y;
			break;

		case SDL_MOUSEBUTTONDOWN:
			switch(event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pRollButton->setMouseButtonClicked(true);
				break;
			}
		
			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pRollButton->setMouseButtonClicked(false);
				break;
			}
			break;
		case SDL_MOUSEWHEEL:
			wheel = event.wheel.y;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			case SDLK_1:
				TheGame::Instance()->changeSceneState(SceneState::START_SCENE);
				break;
			case SDLK_2:
				TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
				break;
			case SDLK_3:
				TheGame::Instance()->changeSceneState(SceneState::LEVEL2_SCENE);
				break;
			

				/************************************************************************/
			case SDLK_w:
				
				break;
			case SDLK_s:
				
				break;
			case SDLK_a:

				break;
			case SDLK_d:

				break;

			case SDLK_SPACE:
					roll();
					break;
			}
			
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				
				break;

			case SDLK_s:
				
				break;

			case SDLK_a:

				break;
			case SDLK_d:

				break;
			}
			
			break;
		default:
			break;
		}
	}
}

void Level1Scene::start()
{
	SDL_Color black = { 0,0,0,255 };
	m_istruct = new Label("push 3 for bonus stage", "lazy", 25,
		black, glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.25f));
	m_istruct->setParent(this);
	addChild(m_istruct);
	m_pfirstNumLabel = new Label("", "lazy", 25,
		black, glm::vec2(Config::SCREEN_WIDTH * 0.25f, Config::SCREEN_HEIGHT * 0.55f));
	m_pfirstNumLabel->setParent(this);
	addChild(m_pfirstNumLabel);
	m_psecondNumLabel = new Label("", "lazy", 25,
		black, glm::vec2(Config::SCREEN_WIDTH * 0.75f, Config::SCREEN_HEIGHT * 0.55f));
	m_psecondNumLabel->setParent(this);
	addChild(m_psecondNumLabel);
	
	m_pRollButton = new RollButton();
	m_pRollButton->setPosition(glm::vec2(Config::SCREEN_WIDTH*0.5f, Config::SCREEN_HEIGHT * 0.75f));
	m_pRollButton->setParent(this);
	addChild(m_pRollButton);	
}

void Level1Scene::roll() // Roll the dice to make random number 1 to 6
{
	firstNum = rand() % 6 + 1;
	secondNum = rand() % 6 + 1;
	std::cout << "FirstNum: " + std::to_string(firstNum) << std::endl;
	std::cout << "SecondNum: " + std::to_string(secondNum) << std::endl;
}


glm::vec2 Level1Scene::getMousePosition()
{
	return m_mousePosition;
}

