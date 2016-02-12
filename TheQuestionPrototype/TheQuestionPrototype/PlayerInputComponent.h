#ifndef PLAYERINPUTCOMPONENT_H
#define PLAYERINPUTCOMPONENT_H

#include "InputComponent.h"

class PlayerInputComponent : public InputComponent {
public:
	virtual void update(GameObject& gameObject);
private:
	const float WALK_ACCELERATION = 1;
};

#endif