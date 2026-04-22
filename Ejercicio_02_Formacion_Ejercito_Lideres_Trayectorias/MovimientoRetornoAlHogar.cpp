#include "MovimientoRetornoAlHogar.h"
#include "Actor.h"
#include <cmath>

void MovimientoRetornoAlHogar::aplicar(Actor& actor, const ContextoMovimiento& contexto, float dt)
{
	if (contexto.fase != FaseEjercito::Retorno)
		return;
	float px = actor.getX();
	float py = actor.getY();
	float vx = (contexto.posicionHogar.x - px) / std::max(dt, 1e-4f);
	float vy = (contexto.posicionHogar.y - py) / std::max(dt, 1e-4f);
	float lim = std::max(40.f, contexto.rapidezMaxima);
	float mag = std::sqrt(vx * vx + vy * vy);
	if (mag > lim && mag > 1e-4f)
	{
		vx *= lim / mag;
		vy *= lim / mag;
	}
	actor.setXVelocidad(vx);
	actor.setYVelocidad(vy);
}
