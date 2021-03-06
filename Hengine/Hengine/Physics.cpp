#include "Physics.h"
//Creates collision object with a vector of all GameObjects
Collision::Collision(std::vector<GameObject*>& gameObjects) : objects(gameObjects) {
	 
}

Collision::~Collision() {

}

void Collision::update() {
	for (unsigned int i = 0; i < objects.size(); i++) {

		for (unsigned int j = i + 1; j < objects.size(); j++) {

			if (std::abs(objects[i]->xpos - objects[j]->xpos) < 50) { // minimam difference in distance to check for collision
				int hwi = (objects[i]->destRect.w / 2);
				int hwj = (objects[j]->destRect.w / 2);
				int hhi = (objects[i]->destRect.h / 2);
				int hhj = (objects[j]->destRect.h / 2);
				int absoluteDifx = abs((objects[i]->xpos + hwi) - (objects[j]->xpos + hwj));
				int abosluteDify = abs((objects[i]->ypos + hhi) - (objects[j]->ypos + hhj));
				if (absoluteDifx < hwi + hwj) {
					if (abosluteDify < hhi + hhj) {
						//starts a onCollision function on gameObject, with data from collided GameObject
						objects[i]->onCollision(objects[j]->GetTag(), objects[j]);
						objects[j]->onCollision(objects[i]->GetTag(), objects[i]);
					}
				}
			}
		}
	}
}

