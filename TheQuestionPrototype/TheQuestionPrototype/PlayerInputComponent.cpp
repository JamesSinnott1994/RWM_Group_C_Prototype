#include "PlayerInputComponent.h"
#include "GameObject.h"

void PlayerInputComponent::update(GameObject& gameObject){
	if (KeyBoardInput::GetInstance()->isKeyPressed(SDLK_w)){
		gameObject.velocityY -= WALK_ACCELERATION;
	}
	else if (KeyBoardInput::GetInstance()->isKeyPressed(SDLK_s)){
		gameObject.velocityY += WALK_ACCELERATION;
	}
	if (KeyBoardInput::GetInstance()->isKeyPressed(SDLK_a)){
		gameObject.velocityX -= WALK_ACCELERATION;
	}
	else if (KeyBoardInput::GetInstance()->isKeyPressed(SDLK_d)){
		gameObject.velocityX += WALK_ACCELERATION;
	}
}