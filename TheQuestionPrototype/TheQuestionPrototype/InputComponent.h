#ifndef INPUTCOMPONENT_H
#define INPUTCOMPONENT_H

class GameObject;
#include "KeyBoardInput.h"

class InputComponent {
public:
	virtual ~InputComponent() {}
	virtual void update(GameObject& gameObject) = 0;
};

#endif