#include "MovimientoNova.h"
#include "Actor.h"
#include <cmath>

MovimientoNova::MovimientoNova()
	: generador_(std::random_device{}())
	, angulo_(0.f, 6.2831853f)
	, rapidez_(40.f, 140.f)
	, intervalo_(0.25f, 0.9f)
	, acumulado_(0.f)
	, hastaCambio_(0.4f)
{
}

void MovimientoNova::aplicar(Actor& actor, const ContextoMovimiento& contexto, float dt)
{
	if (contexto.fase != FaseEjercito::Reposo)
		return;
	acumulado_ += dt;
	if (acumulado_ >= hastaCambio_)
	{
		acumulado_ = 0.f;
		hastaCambio_ = intervalo_(generador_);
		float t = angulo_(generador_);
		float v = rapidez_(generador_);
		float lim = std::max(20.f, contexto.rapidezMaxima);
		if (v > lim)
			v = lim;
		actor.setXVelocidad(std::cos(t) * v);
		actor.setYVelocidad(std::sin(t) * v);
	}
}
