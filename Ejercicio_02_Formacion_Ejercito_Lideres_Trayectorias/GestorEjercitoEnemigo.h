#pragma once

#include "FabricaEnemigos.h"
#include "MovimientoOfensivaLider.h"
#include "MovimientoRetornoAlHogar.h"
#include "MovimientoSeguidor.h"
#include "SimulacionGameManager.h"
#include "SimulacionTypes.h"
#include <array>
#include <memory>
#include <unordered_map>
#include <vector>

class Actor;

struct UnidadEjercito
{
	int id;
	std::unique_ptr<Actor> actor;
	bool lider;
	int indiceLider;
	Punto hogar;
	Punto offset;
	size_t retrasoPasos;
	Punto centroOrbita;
	float radioOrbitaIn;
	float radioOrbitaOut;
};

class GestorEjercitoEnemigo
{
	SimulacionGameManager gameManager_;
	FabricaEnemigos fabrica_;
	std::vector<UnidadEjercito> unidades_;
	std::unordered_map<int, size_t> idAIndice_;
	std::array<TrayectoriaMuestras, 2> rutasLideres_;
	MovimientoSeguidor movimientoSeguidor_;
	MovimientoRetornoAlHogar movimientoRetorno_;
	MovimientoOfensivaLider movimientoOfensivaLider_;
	float tiempo_;
	FaseEjercito fase_;
	Punto hogarLider0_;
	Punto hogarLider1_;

	static constexpr float kFinReposo = 4.f;
	static constexpr float kFinOfensiva = 13.f;

public:
	static constexpr float kDuracionTotalSimulacion = 20.f;

	GestorEjercitoEnemigo();

	void desplegarFormacionInicial();
	void pasoIntegracion(float dt);

	ContextoMovimiento construirContexto(int id);
	MovimientoSeguidor& movimientoSeguidor();
	MovimientoRetornoAlHogar& movimientoRetorno();
	MovimientoOfensivaLider& movimientoOfensivaLider();

	float obtenerTiempoSimulacion() const { return tiempo_; }
	const std::vector<UnidadEjercito>& obtenerUnidades() const { return unidades_; }

private:
	void agregarUnidad(UnidadEjercito unidad);
	void actualizarFase();
	void registrarMuestrasLideres();
	static Punto mezclar(const Punto& a, const Punto& b, float t);
};
