#pragma once
#include <iostream>
#include <string>
#include "SistemaRenderizacion.h"
#include "GameManager.h"
#include "TipoActor.h"
#include "Direccion.h"
using namespace std;

class GameManager;

class Actor
{
protected:
	GameManager* gameManager;
	TipoActor tipoActor;
	float x;
	float y;
	float xVelocidad;
	float yVelocidad;
	string avatar;
	int ancho;
	int alto;
	int energia;

	bool destruirDespuesMuerte;
	bool invulnerable;
	bool fisico;
	Direccion direccion;

public:
	Actor();
	Actor(float _x, float _y, float _xVelocidad, float _yVelocidad, int _ancho, int _alto, int _energia);
	Actor(GameManager* _gameManager, TipoActor _tipoActor, float _x, float _y, float _xVelocidad, float _yVelocidad, int _ancho, int _alto, int _energia, bool _destrirDespuesMuerte, bool _invulnerable, bool _fisico, Direccion _direccion);
	TipoActor getTipoActor() { return tipoActor; }
	float getX() { return x; }
	float getY() { return y; }
	float getXVelocidad() { return xVelocidad; }
	float getYVelocidad() { return yVelocidad; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
	int getEnergia() { return energia; }
	bool getDestruirDespuesMuerte() { return destruirDespuesMuerte; }
	bool getInvulnerable() { return invulnerable; }
	bool getFisico() { return fisico; }
	Direccion getDireccion() { return direccion; }
	
	void setTipoActor(TipoActor _tipoActor) { tipoActor = _tipoActor; }
	void setX(float _x) { x = _x; }
	void setY(float _y) { y = _y; }
	void setXVelocidad(float _xVelocidad) { xVelocidad = _xVelocidad; }
	void setYVelocidad(float _yVelocidad) { yVelocidad = _yVelocidad; }
	void setAncho(int _ancho) { ancho = _ancho; }
	void setAlto(int _alto) { alto = _alto; }
	void setEnergia(int _energia) { energia = _energia; }
	void setDestruirDespuesMuerte(bool _destruirDespuesMuerte) { destruirDespuesMuerte = _destruirDespuesMuerte; }
	void setInvulnerable(bool _invulnerable) { invulnerable = _invulnerable; }
	void setFisico(bool _fisico) { fisico = _fisico; }
	void setDireccion(Direccion _direccion) { direccion = _direccion; }
	void setGameManager(GameManager* _gameManager) { gameManager = _gameManager; }

	virtual void renderizar(SistemaRenderizacion* _sistemaRenderizacion);
	virtual void actualizar(float _dt);
	virtual void intersectar(Actor* _actor);
	void hacerDano(int _dano);
};

