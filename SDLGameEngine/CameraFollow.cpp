#include "CameraFollow.h"
#include "Camera.h"
#include "GameObject.h"
#include "Transform.h"


CameraFollow::CameraFollow()
{
}


CameraFollow::~CameraFollow()
{
}

void CameraFollow::Update()
{
	Camera::x = ceil(gameObject->transform->GetAbsolutePosition().x) - floor(Camera::width * 0.5f);
	Camera::y = ceil(gameObject->transform->GetAbsolutePosition().y) - floor(Camera::height * 0.5f);

}