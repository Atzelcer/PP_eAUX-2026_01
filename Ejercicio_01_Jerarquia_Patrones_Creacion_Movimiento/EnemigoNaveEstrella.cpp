#include "EnemigoNaveEstrella.h"
#include "GestorEjercitoEnemigo.h"
#include "MovimientoEstrella.h"
#include "SimulacionGameManager.h"

EnemigoNaveEstrella::EnemigoNaveEstrella(
	GestorEjercitoEnemigo* gestor,
	SimulacionGameManager* gameManager,
	int id,
	float x,
	float y)
	: Actor(
		  gameManager,
		  TipoActor_EnemigoNaveEstrella,
		  x,
		  y,
		  0.f,
		  0.f,
		  30,
		  24,
		  120,
		  true,
		  false,
		  true,
		  Direccion_Abajo)
	, gestor_(gestor)
	, id_(id)
	, reposo_(std::make_unique<MovimientoEstrella>())
{
}

void EnemigoNaveEstrella::actualizar(float dt)
{
	ContextoMovimiento ctx = gestor_->construirContexto(id_);
	if (ctx.fase == FaseEjercito::Reposo)
		reposo_->aplicar(*this, ctx, dt);
	else if (ctx.fase == FaseEjercito::Retorno)
		gestor_->movimientoRetorno().aplicar(*this, ctx, dt);
	else if (ctx.esLider)
		gestor_->movimientoOfensivaLider().aplicar(*this, ctx, dt);
	else
		gestor_->movimientoSeguidor().aplicar(*this, ctx, dt);
	Actor::actualizar(dt);
}
