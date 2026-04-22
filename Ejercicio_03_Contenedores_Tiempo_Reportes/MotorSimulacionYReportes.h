#pragma once

#include "GestorEjercitoEnemigo.h"
#include "SimulacionTypes.h"
#include <string>
#include <unordered_map>

class MotorSimulacionYReportes
{
	GestorEjercitoEnemigo gestor_;
	std::unordered_map<int, RegistroExtremos> extremosPorId_;

public:
	void desplegarYPrepararRegistro();
	void ejecutarSimulacion20Segundos();

private:
	void inicializarClavesExtremos();
	void registrarExtremosTrasPaso();
	void informeIntermedioExtremos(const std::string& marcaTemporal);
	void resumenFinal() const;
};
