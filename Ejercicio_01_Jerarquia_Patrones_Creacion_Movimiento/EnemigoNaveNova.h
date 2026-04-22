#pragma once

#include "Actor.h"
#include "IMovimientoEnemigo.h"
#include <memory>

class GestorEjercitoEnemigo;
class SimulacionGameManager;

class EnemigoNaveNova : public Actor
{
	GestorEjercitoEnemigo* gestor_;
	int id_;
	std::unique_ptr<IMovimientoEnemigo> reposo_;

public:
	EnemigoNaveNova(
		GestorEjercitoEnemigo* gestor,
		SimulacionGameManager* gameManager,
		int id,
		float x,
		float y);

	int obtenerId() const { return id_; }

	void actualizar(float dt) override;
};
