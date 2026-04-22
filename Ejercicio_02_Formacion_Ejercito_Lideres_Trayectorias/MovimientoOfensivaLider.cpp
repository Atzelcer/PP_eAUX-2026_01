#include "MovimientoOfensivaLider.h"
#include "Actor.h"
#include <cmath>

void MovimientoOfensivaLider::aplicar(Actor& actor, const ContextoMovimiento& contexto, float dt)
{
	(void)dt;
	if (!contexto.esLider || contexto.fase != FaseEjercito::Ofensiva)
		return;
	float faseTemporal = contexto.tiempoSimulacion;
	float signo = contexto.indiceLider == 0 ? 1.f : -1.f;
	float vx = signo * 95.f * std::sin(faseTemporal * 1.05f);
	float vy = 70.f + 40.f * std::sin(faseTemporal * 0.9f);
	float lim = std::max(50.f, contexto.rapidezMaxima * 1.2f);
	float mag = std::sqrt(vx * vx + vy * vy);
	if (mag > lim && mag > 1e-4f)
	{
		vx *= lim / mag;
		vy *= lim / mag;
	}
	actor.setXVelocidad(vx);
	actor.setYVelocidad(vy);
}
