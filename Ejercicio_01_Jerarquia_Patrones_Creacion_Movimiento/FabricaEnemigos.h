#pragma once

#include <memory>

class SimulacionGameManager;
class GestorEjercitoEnemigo;
class EnemigoNaveNova;
class EnemigoNaveEstrella;

class FabricaEnemigos
{
public:
	std::unique_ptr<EnemigoNaveNova> crearNova(
		GestorEjercitoEnemigo* gestor,
		SimulacionGameManager* gameManager,
		int id,
		float x,
		float y);

	std::unique_ptr<EnemigoNaveEstrella> crearEstrella(
		GestorEjercitoEnemigo* gestor,
		SimulacionGameManager* gameManager,
		int id,
		float x,
		float y);
};



