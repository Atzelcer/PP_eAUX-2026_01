#include "Actor.h"

Actor::Actor()
{
	//gameManager = nullptr;
	gameManager = 0;
	tipoActor = TipoActor_None;

	x = 0.0;
	y = 0.0;
	xVelocidad = 0.0;
	yVelocidad = 0.0;
	ancho = 1;
	alto = 1;
	energia = 1;
	destruirDespuesMuerte = true;
	invulnerable = false;
	fisico = true;

	direccion = Direccion_Arriba;
}

//Actor::Actor(float _x = 0.0, float _y = 0.0, float _xVelocidad = 0.0, float _yVelocidad = 0.0, int _ancho = 1, int _alto = 1, int _energia = 1)
Actor::Actor(float _x , float _y, float _xVelocidad, float _yVelocidad, int _ancho, int _alto, int _energia)
{
	gameManager = nullptr;
	tipoActor = TipoActor_None;

	x = _x;
	y = _y;
	xVelocidad = _xVelocidad;
	yVelocidad = _yVelocidad;
	ancho = _ancho;
	alto = _alto;
	energia = _energia;
	destruirDespuesMuerte = true;
	invulnerable = false;
	fisico = true;

	direccion = Direccion_Arriba;
}

Actor::Actor(GameManager* _gameManager, TipoActor _tipoActor, float _x, float _y, float _xVelocidad, float _yVelocidad, int _ancho, int _alto, 
	int _energia, bool _destrirDespuesMuerte, bool _invulnerable, bool _fisico, Direccion _direccion)
{
	gameManager = _gameManager;
	tipoActor = _tipoActor;

	x = _x;
	y = _y;
	xVelocidad = _xVelocidad;
	yVelocidad = _yVelocidad;
	ancho = _ancho;
	alto = _alto;
	energia = _energia;
	destruirDespuesMuerte = _destrirDespuesMuerte;
	invulnerable = _invulnerable;
	fisico = _fisico;

	direccion = _direccion;
}

void Actor::renderizar(SistemaRenderizacion* _sistemaRenderizacion)
{
}

void Actor::actualizar(float _dt)
{
	int filaAnterior = int(y);
	int columnaAnterior = int(x);

	float yNueva = y + yVelocidad * _dt;
	float xNueva = x + xVelocidad * _dt;

	int filaNueva = int(yNueva);
	int columnaNueva = int(xNueva);


	if (columnaAnterior != columnaNueva)
		gameManager->moverActorA(this, xNueva, y);
	else
		x = xNueva;

	if (filaAnterior != filaNueva)
		gameManager->moverActorA(this, x, yNueva);
	else
		y = yNueva;
}


void Actor::intersectar(Actor* _actor)
{

}

void Actor::hacerDano(int _dano)
{
	if (getInvulnerable())
		return;

	if (energia > _dano)
		energia -= _dano;
	else
		energia = 0;
}
