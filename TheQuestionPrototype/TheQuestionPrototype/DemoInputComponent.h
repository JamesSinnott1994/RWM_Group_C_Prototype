#ifndef DEMOINPUTCOMPONENT_H
#define DEMOINPUTCOMPONENT_H

#include "InputComponent.h"

class DemoInputComponent : public InputComponent{
public:
	virtual void update(GameObject& gameObject);
private:
	const float WALK_ACCELERATION = 1;
};

#endif