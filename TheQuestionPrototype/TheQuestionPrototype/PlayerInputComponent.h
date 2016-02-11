#ifndef PLAYERINPUTCOMPONENT_H
#define PLAYERINPUTCOMPONENT_H

#include "InputComponent.h"

class PlayerInputComponent : public InputComponent {
public:
	virtual void update(GameObject& gameObject){	//GameObject Class not yet created
		if (KeyBoardInput::GetInstance()->isKeyPressed(SDLK_w)){
			//these methods are tested and work, putting the right calls in is all that remains to do
			//gameObject.jump();
			std::cout << "Pressing S" << std::endl;
		}
		else if (KeyBoardInput::GetInstance()->isKeyPressed(SDLK_s)){
			//gameObject.crouch();
			std::cout << "Pressing S" << std::endl;
		}
		if (KeyBoardInput::GetInstance()->isKeyPressed(SDLK_a)){
			gameObject.velocity -= WALK_ACCELERATION;
		}
		else if (KeyBoardInput::GetInstance()->isKeyPressed(SDLK_d)){
			gameObject.velocity += WALK_ACCELERATION;
		}
	}
private:
	const float WALK_ACCELERATION = 1;
};

#endif