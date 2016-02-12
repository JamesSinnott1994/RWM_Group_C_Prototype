#include "DemoInputComponent.h"
#include "GameObject.h"

void DemoInputComponent::update(GameObject& gameObject){
	int x = rand() % 40;
	//switch (x)
	//{
	//case(0):
	if (x < 10)
		gameObject.velocityY -= WALK_ACCELERATION*10;
	//case(1) :
	else if (x < 20)
		gameObject.velocityY += WALK_ACCELERATION*10;
	//case(2) :
	else if (x < 30)
		gameObject.velocityX -= WALK_ACCELERATION*10;
	//case(3) :
	else
		gameObject.velocityX += WALK_ACCELERATION*10;
	//default:
	//	break;
	//}
}