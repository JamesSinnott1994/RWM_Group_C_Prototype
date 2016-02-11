#ifndef DEMOINPUTCOMPONENT_H
#define DEMOINPUTCOMPONENT_H

#include "InputComponent.h"
#include "GameObject.h"

class DemoInputComponent : public InputComponent{
public:
	virtual void update(GameObject& gameObject){
		//Ai code to automatically control a gameObject
		//create as GameObject* gameObject = new GameObject(new DemoInputComponent());
	}
};

#endif