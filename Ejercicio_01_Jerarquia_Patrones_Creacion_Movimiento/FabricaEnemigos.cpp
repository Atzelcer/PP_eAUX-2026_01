#include "FabricaEnemigos.h"
#include "EnemigoNaveNova.h"
#include "EnemigoNaveEstrella.h"
#include "SimulacionGameManager.h"

std::unique_ptr<EnemigoNaveNova> FabricaEnemigos::crearNova(
	GestorEjercitoEnemigo* gestor,
	SimulacionGameManager* gameManager,
	int id,
	float x,
	float y)
{
	return std::make_unique<EnemigoNaveNova>(gestor, gameManager, id, x, y);
}

std::unique_ptr<EnemigoNaveEstrella> FabricaEnemigos::crearEstrella(
	GestorEjercitoEnemigo* gestor,
	SimulacionGameManager* gameManager,
	int id,
	float x,
	float y)
{
	return std::make_unique<EnemigoNaveEstrella>(gestor, gameManager, id, x, y);
}
