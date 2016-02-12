#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "PlayerInputComponent.h"
#include "DemoInputComponent.h"
#include "GraphicsComponent.h"
#include "PhysicsComponent.h"

class GameObject {
public:
	int velocityX, velocityY;
	int x = 200, y = 200;

	GameObject(InputComponent* input): input_(input) {}
	//Instancize GameObject like so
	//GameObject player = new GameObject(new PlayerInputComponent());	or
	//GameObject aiPlayer = new GameObject(new DemoInputComponent())

	void update(float time){
		input_->update(*this);
		physics_.update(*this, time);
		graphics_.update(*this);
	}
private:
	PhysicsComponent physics_;
	GraphicsComponent graphics_;
	InputComponent* input_;
};

#endif