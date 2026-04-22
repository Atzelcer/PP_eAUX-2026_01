#pragma once

#include "IMovimientoEnemigo.h"

class MovimientoRetornoAlHogar : public IMovimientoEnemigo
{
public:
	void aplicar(Actor& actor, const ContextoMovimiento& contexto, float dt) override;
};
