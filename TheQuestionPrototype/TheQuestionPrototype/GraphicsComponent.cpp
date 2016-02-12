#include "GraphicsComponent.h"
#include "GameObject.h"

void GraphicsComponent::update(GameObject& gameObject){
	Renderer::GetInstance()->DrawRect(gameObject.x, gameObject.y);
}