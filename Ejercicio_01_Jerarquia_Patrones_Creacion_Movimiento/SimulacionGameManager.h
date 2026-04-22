#pragma once

#include "GameManager.h"

class SimulacionGameManager : public GameManager
{
public:
	void moverActorA(Actor* actor, float nuevaX, float nuevaY) override;
};
