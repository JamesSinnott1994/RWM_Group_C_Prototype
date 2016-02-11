#ifndef GRAPHICSCOMPONENT_H
#define GRAPHICSCOMPONENT_H

class GameObject;
#include "Renderer.h"

class GraphicsComponent {
public:
	void update(GameObject& gameObject) {
		/***  SAMPLE CODE IN UPCOMING COMMENTS HERE  ***/
		/*
		gameObject.sprite = standingSprite

		if (gameObject.velocity.x > 0){
			gameObject.sprite = run_Right_Sprite;
		}
		else if (gameObject.velocity.x < 0){
			gameObject.sprite = run_Left_Sprite;
		}

		if (gameObject.velocity.y != 0){
			gameObject.sprite = jumpingSprite;
		}
		*/

		//Renderer::GetInstance()->DrawImage(gameObject.src, gameObject.dest, gameObject.texture);
		std::cout << "Drawing Game Object" << std::endl;
	}
private:
	//Hold all the different sprites here, eg.
	//Sprite standingSprite;
	//Sprite run_Right_Sprite;
	//Sprite run_Left_Sprite;
	//Sprite jumpingSprite;
};

#endif