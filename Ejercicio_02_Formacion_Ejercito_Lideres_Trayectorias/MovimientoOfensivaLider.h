#pragma once

#include "IMovimientoEnemigo.h"

class MovimientoOfensivaLider : public IMovimientoEnemigo
{
public:
	void aplicar(Actor& actor, const ContextoMovimiento& contexto, float dt) override;
};
