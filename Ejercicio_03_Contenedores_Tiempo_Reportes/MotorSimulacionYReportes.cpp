#include "MotorSimulacionYReportes.h"
#include "Actor.h"
#include <algorithm>
#include <iostream>
#include <vector>

void MotorSimulacionYReportes::inicializarClavesExtremos()
{
	extremosPorId_.clear();
	for (const UnidadEjercito& u : gestor_.obtenerUnidades())
		extremosPorId_.try_emplace(u.id, RegistroExtremos());
}

void MotorSimulacionYReportes::desplegarYPrepararRegistro()
{
	gestor_.desplegarFormacionInicial();
	inicializarClavesExtremos();
}

void MotorSimulacionYReportes::registrarExtremosTrasPaso()
{
	for (const UnidadEjercito& u : gestor_.obtenerUnidades())
	{
		Punto actual{ u.actor->getX(), u.actor->getY() };
		extremosPorId_.at(u.id).registrarMuestra(actual, u.hogar);
	}
}

void MotorSimulacionYReportes::informeIntermedioExtremos(const std::string& marcaTemporal)
{
	std::cout << "\n--- Posiciones extremas al cumplirse " << marcaTemporal << " ---\n";
	std::vector<int> claves;
	claves.reserve(extremosPorId_.size());
	for (const auto& par : extremosPorId_)
		claves.push_back(par.first);
	std::sort(claves.begin(), claves.end());
	for (int k : claves)
		std::cout << "Unidad " << k << ": " << extremosPorId_.at(k).formatear() << "\n";
}

void MotorSimulacionYReportes::resumenFinal() const
{
	std::cout << "\n========== Resumen final de la simulacion (20 s) ==========\n";
	std::vector<int> claves;
	for (const auto& par : extremosPorId_)
		claves.push_back(par.first);
	std::sort(claves.begin(), claves.end());
	for (int k : claves)
	{
		const RegistroExtremos& r = extremosPorId_.at(k);
		std::cout << "ID " << k << " | " << r.formatear() << "\n";
	}
	std::cout << "Formacion: 2 lideres superiores, 8 escoltas en dos alas equidistantes.\n";
	std::cout << "Fases: reposo orbital o erratico, ofensiva coordinada, retorno al hogar.\n";
}

void MotorSimulacionYReportes::ejecutarSimulacion20Segundos()
{
	const float dt = 1.f / 120.f;
	const float total = GestorEjercitoEnemigo::kDuracionTotalSimulacion;
	bool reporte10 = false;
	bool reporte20 = false;
	while (gestor_.obtenerTiempoSimulacion() + 1e-6f < total)
	{
		float t = gestor_.obtenerTiempoSimulacion();
		float paso = dt;
		if (t + paso > total + 1e-6f)
			paso = total - t;
		gestor_.pasoIntegracion(paso);
		registrarExtremosTrasPaso();
		if (!reporte10 && gestor_.obtenerTiempoSimulacion() >= 10.f - 1e-5f)
		{
			informeIntermedioExtremos("10 segundos de simulacion");
			reporte10 = true;
		}
		if (!reporte20 && gestor_.obtenerTiempoSimulacion() >= 20.f - 1e-5f)
		{
			informeIntermedioExtremos("20 segundos de simulacion");
			reporte20 = true;
		}
	}
	resumenFinal();
}
