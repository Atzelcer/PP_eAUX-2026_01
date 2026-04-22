#pragma once

#include "SimulacionTypes.h"

class Actor;

class IMovimientoEnemigo
{
public:
	virtual ~IMovimientoEnemigo() = default;
	virtual void aplicar(Actor& actor, const ContextoMovimiento& contexto, float dt) = 0;
};
