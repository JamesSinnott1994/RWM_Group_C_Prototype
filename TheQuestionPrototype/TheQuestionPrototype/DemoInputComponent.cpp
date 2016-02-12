#include "DemoInputComponent.h"
#include "GameObject.h"

void DemoInputComponent::update(GameObject& gameObject){
	int x = rand() % 4;
	switch (x)
	{
	case(0):
		gameObject.velocityY -= WALK_ACCELERATION;
	case(1) :
		gameObject.velocityY += WALK_ACCELERATION;
	case(2) :
		gameObject.velocityX -= WALK_ACCELERATION;
	case(3) :
		gameObject.velocityX += WALK_ACCELERATION;
	default:
		break;
	}
}