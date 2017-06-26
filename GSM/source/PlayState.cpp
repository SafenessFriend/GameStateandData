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
#include <Texture.h>

PlayState::PlayState(GSMApp *pApp) : IGameState(pApp)
{
	m_background = new aie::Texture("./textures/underwater.png");
	// Constructor - load assets here
}

PlayState::~PlayState()
{
	delete m_background;
	//destructor - unload assets here
}

bool PlayState::startup() {
	
	m_2dRenderer = new aie::Renderer2D();
	
	
	time_t srand(time(NULL));
	
	m_factory = std::unique_ptr<Factory>(new Factory());
	
		// create some entities to store in the factory
	std::shared_ptr<Entity> fish(new Entity("fish", "./textures/fish.png"));
	fish->setPosition(float(rand() % 1280), float(rand () % 720));

	std::shared_ptr<Entity> fish2(new Entity("fish2", "./textures/fish2.png"));
	fish2->setPosition(float(rand() % 1280), float(rand() % 720));
	
	std::shared_ptr<Entity> jelly(new Entity("jelly", "./textures/jelly.png"));
	jelly->setPosition(float(rand() % 1280), float(rand() % 720));

	std::shared_ptr<Entity> starfish(new Entity("starfish", "./textures/starfish.png"));
	starfish->setPosition(float(rand() % 1280), float(rand () % 720));
	
	m_factory->addPrototype(fish);
	m_factory->addPrototype(fish2);
	m_factory->addPrototype(jelly);
	m_factory->addPrototype(starfish);

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


			static float timer = 0;
		
			if (timer <= 0) {
			timer = 0.5f;
			
				std::shared_ptr<IPrototype> entityClone;
			if (rand() % 4 == 0)
				 entityClone = m_factory->create("fish");
			else if (rand() % 3 == 0)
				 entityClone = m_factory->create("jelly");
			else if (rand() % 2 == 0)
				entityClone = m_factory->create("fish2");
			else if (rand() % 1 == 0)
				entityClone = m_factory->create("starfish");
			
			// dynamically cast the shared pointer from IPrototype to entity
			std::shared_ptr<Entity> entity = std::dynamic_pointer_cast<Entity>(entityClone);
			entity->setVelocity(float(50 - rand() % 100), float(50 - rand() % 100));
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

	std::cout << "Play - Draw" << std::endl;

	m_2dRenderer->begin();
			
	m_2dRenderer->drawSprite(m_background, 640, 360);


	for (std::shared_ptr<Entity> entity : m_entities) {
	entity->draw(m_2dRenderer);
				
		}
	
			
				
	m_2dRenderer->end();
			
}
