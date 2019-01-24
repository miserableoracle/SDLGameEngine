#include "TestDemo.h"
#include "MoveInCircle.h"


TestDemo::TestDemo()
{
}


TestDemo::~TestDemo() 
{
}

void TestDemo::Setup()
{
	GameObject* go = CreateGameObject("Test", 640, 360, 45);
	go->AddComponent(new Renderer(go, "Assets/Tank.png"));	
	go->transform->scale.x = 0.1f;
	go->transform->scale.y = 0.1f;
	go->AddComponent(new MoveInCircle(go));
	go->GetComponent<MoveInCircle>()->radius = 100;
}