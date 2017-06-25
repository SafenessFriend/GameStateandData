#include "PlayState.h"
#include "GSMApp.h"
#include <iostream>
#include <Input.h>
#include "GameStateManager.h"
#include <Factory.h>
#include "ResourceManager.h"
#include <random>
#include <time.h>
#include <memory>
#include "Entity.h"

PlayState::PlayState(GSMApp *pApp) : IGameState(pApp)
{
	// Constructor - load assets here
}

PlayState::~PlayState()
{
	//destructor - unload assets here
}

bool PlayState::startup() {
	
	m_2dRenderer = new aie::Renderer2D();
	
	
	srand(time(NULL));
	
	m_factory = std::unique_ptr<Factory>(new Factory());
	
		// create some entities to store in the factory
	std::shared_ptr<Entity> car(new Entity("car", "./textures/car.png"));
	car->setPosition(200, 100);
	
	std::shared_ptr<Entity> bullet(new Entity("bullet", "./textures/bullet.png"));
	bullet->setPosition(500, 400);
	
	m_factory->addPrototype(car);
	m_factory->addPrototype(bullet);
	
	return true;
	
}

void PlayState::shutDown()
{
	delete m_2dRenderer;
}

void PlayState::Update(float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();
	// do update logic here
	std::cout << "Play - Update" << std::endl;

	m_factory = std::unique_ptr<Factory>(new Factory());

			static float timer = 0;
		
			if (timer <= 0) {
			timer = 0.5f;
			
				std::shared_ptr<IPrototype> entityClone;
			if (rand() % 2 == 0)
				 entityClone = m_factory->create("car");
			else
				 entityClone = m_factory->create("bullet");
			
			// dynamically cast the shared pointer from IPrototype to entity
			std::shared_ptr<Entity> entity = std::dynamic_pointer_cast<Entity>(entityClone);
			entity->setVelocity(50 - rand() % 100, 50 - rand() % 100);
			m_entities.push_back(entity);
			
		}
		timer -= deltaTime;
		
			for (auto it = m_entities.begin(); it != m_entities.end(); ) {
			(*it)->update(deltaTime);
			Vector2 pos = (*it)->getPosition();
			if (pos.x < 0 || pos.y < 0 || pos.x > 1280 || pos.y > 720) {
				it = m_entities.erase(it);
				
			}
			else {
				++it;
				
			}
			
		}


}

void PlayState::Draw()
{
	// do draw logic here
	std::cout << "Play - Draw" << std::endl;

		// wipe the screen to the background colour
				//clearScreen();
			
					// begin drawing sprites
				m_2dRenderer->begin();
			
					// draw your stuff here!
				for (std::shared_ptr<Entity> entity : m_entities) {
				entity->draw(m_2dRenderer);
				
			}
	
			
					// done drawing sprites
				m_2dRenderer->end();
			
}
