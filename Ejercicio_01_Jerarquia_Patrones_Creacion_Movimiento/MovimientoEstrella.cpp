#include "MovimientoEstrella.h"
#include "Actor.h"
#include <cmath>

MovimientoEstrella::MovimientoEstrella()
	: generador_(std::random_device{}())
	, perturbacion_(-0.35f, 0.35f)
	, angulo_(0.f)
	, velocidadAngularBase_(1.1f)
	, radioActual_(55.f)
	, tiempoRadio_(0.f)
{
}

void MovimientoEstrella::aplicar(Actor& actor, const ContextoMovimiento& contexto, float dt)
{
	if (contexto.fase != FaseEjercito::Reposo)
		return;
	tiempoRadio_ += dt;
	if (tiempoRadio_ > 1.8f)
	{
		tiempoRadio_ = 0.f;
		float rMedio = (contexto.radioInterior + contexto.radioExterior) * 0.5f;
		float variacion = perturbacion_(generador_) * (contexto.radioExterior - contexto.radioInterior) * 0.35f;
		radioActual_ = rMedio + variacion;
		radioActual_ = std::max(contexto.radioInterior, std::min(contexto.radioExterior, radioActual_));
		velocidadAngularBase_ = 0.75f + std::abs(perturbacion_(generador_)) * 1.6f;
	}
	float w = velocidadAngularBase_ + perturbacion_(generador_) * 0.25f;
	angulo_ += w * dt;
	float ox = contexto.centroRegion.x + std::cos(angulo_) * radioActual_;
	float oy = contexto.centroRegion.y + std::sin(angulo_) * radioActual_;
	float curvx = actor.getX();
	float curvy = actor.getY();
	float vx = (ox - curvx) / std::max(dt, 1e-4f);
	float vy = (oy - curvy) / std::max(dt, 1e-4f);
	float mag = std::sqrt(vx * vx + vy * vy);
	float lim = std::max(30.f, contexto.rapidezMaxima);
	if (mag > lim && mag > 1e-4f)
	{
		vx *= lim / mag;
		vy *= lim / mag;
	}
	actor.setXVelocidad(vx);
	actor.setYVelocidad(vy);
}
