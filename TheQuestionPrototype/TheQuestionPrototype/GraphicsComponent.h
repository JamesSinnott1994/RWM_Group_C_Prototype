#ifndef GRAPHICSCOMPONENT_H
#define GRAPHICSCOMPONENT_H

class GameObject;
#include "Renderer.h"

class GraphicsComponent {
public:
	void update(GameObject& gameObject);
private:
	//Hold all the different sprites here, eg.
	//Sprite standingSprite;
	//Sprite run_Right_Sprite;
	//Sprite run_Left_Sprite;
	//Sprite jumpingSprite;
};

#endif