#include "PhysicsComponent.h"
#include "GameObject.h"

void PhysicsComponent::update(GameObject& gameObject, float time){
	gameObject.x += gameObject.velocityX;
	gameObject.y += gameObject.velocityY;
}