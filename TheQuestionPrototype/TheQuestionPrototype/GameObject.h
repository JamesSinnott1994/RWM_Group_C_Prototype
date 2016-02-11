#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "PhysicsComponent.h"
#include "GraphicsComponent.h"
#include "PlayerInputComponent.h"
#include "DemoInputComponent.h"

class GameObject {
public:
	int velocity;
	int x, y;

	GameObject(InputComponent* input): input_(input) {}
	//Instancize GameObject like so
	//GameObject player = new GameObject(new PlayerInputComponent());	or
	//GameObject aiPlayer = new GameObject(new DemoInputComponent())

	void update(float time){
		input_->update(*this);
		physics_.update(*this);
		graphics_.update(*this);
	}
private:
	PhysicsComponent physics_;
	GraphicsComponent graphics_;
	InputComponent* input_;
};

#endif