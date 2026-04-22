#pragma once

class Actor;

class GameManager
{
public:
	virtual ~GameManager() = default;
	virtual void moverActorA(Actor* actor, float nuevaX, float nuevaY) = 0;
};
