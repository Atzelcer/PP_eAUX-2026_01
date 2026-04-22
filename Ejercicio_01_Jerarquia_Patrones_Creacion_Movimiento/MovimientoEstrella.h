#pragma once

#include "IMovimientoEnemigo.h"
#include <random>

class MovimientoEstrella : public IMovimientoEnemigo
{
	std::mt19937 generador_;
	std::uniform_real_distribution<float> perturbacion_;
	float angulo_;
	float velocidadAngularBase_;
	float radioActual_;
	float tiempoRadio_;

public:
	MovimientoEstrella();
	void aplicar(Actor& actor, const ContextoMovimiento& contexto, float dt) override;
};
