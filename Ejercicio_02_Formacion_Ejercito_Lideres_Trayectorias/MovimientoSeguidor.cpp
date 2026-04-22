#include "MovimientoSeguidor.h"
#include "Actor.h"
#include <cmath>

void MovimientoSeguidor::aplicar(Actor& actor, const ContextoMovimiento& contexto, float dt)
{
	if (contexto.esLider || contexto.fase != FaseEjercito::Ofensiva)
		return;
	if (!contexto.trayectoriaLider || contexto.trayectoriaLider->size() <= contexto.retrasoPasos)
		return;
	size_t idx = contexto.trayectoriaLider->size() - 1u - contexto.retrasoPasos;
	const Punto& objetivoBase = (*contexto.trayectoriaLider)[idx];
	Punto objetivo{ objetivoBase.x + contexto.offsetFormacion.x, objetivoBase.y + contexto.offsetFormacion.y };
	float px = actor.getX();
	float py = actor.getY();
	float vx = (objetivo.x - px) / std::max(dt, 1e-4f);
	float vy = (objetivo.y - py) / std::max(dt, 1e-4f);
	float lim = std::max(45.f, contexto.rapidezMaxima * 1.1f);
	float mag = std::sqrt(vx * vx + vy * vy);
	if (mag > lim && mag > 1e-4f)
	{
		vx *= lim / mag;
		vy *= lim / mag;
	}
	actor.setXVelocidad(vx);
	actor.setYVelocidad(vy);
}
