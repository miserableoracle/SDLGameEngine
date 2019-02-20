#include "Scene1.h"
#include "PlayerControls.h"
#include "Bullet.h"
#include "GameObject.h"
#include "SteeringAgent.h"
#include "Seek.h"
#include "Flee.h"
#include "Arrive.h"
#include "Align.h"
#include "Pursue.h"
#include "UpdateVectorTarget.h"
#include "MoveInCircle.h"
#include "Time.h"
#include "PathFollowing.h"
#include "Shoot.h"
#include "CameraFollow.h"
#include "SpriteRenderer.h"
#include "Renderer.h"
#include "Camera.h"
#include "Game.h"
#include "Rigidbody.h"


Scene1::Scene1()
{
}


Scene1::~Scene1()
{
}

void Scene1::Setup()
{
	Scene::Setup();


	GameObject* bg = Instantiate("bg", 300, 200, 0);
	Sprite* bgSprite = new Sprite("Assets/bg.png");
	SpriteRenderer* bgRenderer = new SpriteRenderer(bgSprite);
	bg->AddComponent(bgRenderer);



	GameObject* go = Instantiate("Tank", 300, 200, 0);
	go->AddComponent(new SpriteRenderer("Assets/Target.png"));
	go->transform->SetRelativeScale(Vector2(0.1f, 0.1f));

	GameObject* graphic = Instantiate("TankGraphic", 0, 0, 90);
	Sprite* tankSprite = new Sprite("Assets/Tank.png");
	SpriteRenderer* tankRenderer = new SpriteRenderer();
	tankRenderer->SetSprite(tankSprite);
	//tankRenderer->flipY = true;

	graphic->AddComponent(tankRenderer);
	/*graphic->transform->scale.x = 0.1f;
	graphic->transform->scale.y = 0.1f;*/



	graphic->transform->SetParentRelative(go->transform);


	go->AddComponent(new PlayerControls());
	go->AddComponent(new CameraFollow());

	graphic->AddComponent(new Shoot());
	
	for (int i = 0; i < 10; i++)
	{
		GameObject* enemy = Instantiate(game->Prefab("Enemy"), Camera::x + rand() % Camera::width, Camera::y + rand() % Camera::height, 0);
		enemy->GetComponent<Rigidbody>()->AddForce(500 * Vector2(rand() % 100 - 50 , rand() % 100 - 50));
	}



}
