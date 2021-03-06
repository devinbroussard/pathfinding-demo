#include "MainScene.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Transform2D.h"
#include "Player.h"
#include "Agent.h"
#include "SeekComponent.h"
#include "WanderComponent.h"
#include "StateMachineComponent.h"

void MainScene::start()
{
	Player* player = new Player(200, 50, "Player", 100, 50);
	player->getTransform()->setScale({ 50,50 });

	Agent* agent = new Agent(0, 0, "Agent", 200, 500);
	
	WanderComponent* wanderComponent = new WanderComponent(1000, 100, 100);
	agent->addComponent(wanderComponent);

	SeekComponent* seekComponent = new SeekComponent();
	seekComponent->setSteeringForce(50);
	seekComponent->setTarget(player);
	agent->addComponent(seekComponent);
	agent->addComponent<StateMachineComponent>();

	addActor(player);
	addActor(agent);
}
