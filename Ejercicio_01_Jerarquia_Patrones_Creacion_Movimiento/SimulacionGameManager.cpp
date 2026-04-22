#include "SimulacionGameManager.h"
#include "Actor.h"

void SimulacionGameManager::moverActorA(Actor* actor, float nuevaX, float nuevaY)
{
	if (!actor)
		return;
	actor->setX(nuevaX);
	actor->setY(nuevaY);
}
