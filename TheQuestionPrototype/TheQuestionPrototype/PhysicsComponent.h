#ifndef PHYSICSCOMPONENT_H
#define PHYSICSCOMPONENT_H

class GameObject;

class PhysicsComponent {
public:
	void update(GameObject& gameObject, float time);
private:
};

#endif
