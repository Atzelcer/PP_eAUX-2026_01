#include "EnemigoNaveNova.h"
#include "GestorEjercitoEnemigo.h"
#include "MovimientoNova.h"
#include "SimulacionGameManager.h"

EnemigoNaveNova::EnemigoNaveNova(
	GestorEjercitoEnemigo* gestor,
	SimulacionGameManager* gameManager,
	int id,
	float x,
	float y)
	: Actor(
		  gameManager,
		  TipoActor_EnemigoNaveNova,
		  x,
		  y,
		  0.f,
		  0.f,
		  28,
		  22,
		  100,
		  true,
		  false,
		  true,
		  Direccion_Abajo)
	, gestor_(gestor)
	, id_(id)
	, reposo_(std::make_unique<MovimientoNova>())
{
}

void EnemigoNaveNova::actualizar(float dt)
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
