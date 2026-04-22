#pragma once

#include "IMovimientoEnemigo.h"
#include <random>

class MovimientoNova : public IMovimientoEnemigo
{
	std::mt19937 generador_;
	std::uniform_real_distribution<float> angulo_;
	std::uniform_real_distribution<float> rapidez_;
	std::uniform_real_distribution<float> intervalo_;
	float acumulado_;
	float hastaCambio_;

public:
	MovimientoNova();
	void aplicar(Actor& actor, const ContextoMovimiento& contexto, float dt) override;
};
