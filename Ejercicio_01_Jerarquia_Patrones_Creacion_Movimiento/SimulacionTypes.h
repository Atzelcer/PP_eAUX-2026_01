#pragma once

#include <algorithm>
#include <cmath>
#include <deque>
#include <limits>
#include <string>

struct Punto
{
	float x;
	float y;
};

inline float distancia(const Punto& a, const Punto& b)
{
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	return std::sqrt(dx * dx + dy * dy);
}

using TrayectoriaMuestras = std::deque<Punto>;

enum class FaseEjercito
{
	Reposo,
	Ofensiva,
	Retorno
};

struct ContextoMovimiento
{
	FaseEjercito fase;
	float tiempoSimulacion;
	Punto centroRegion;
	float radioInterior;
	float radioExterior;
	Punto posicionHogar;
	bool esLider;
	int indiceLider;
	const TrayectoriaMuestras* trayectoriaLider;
	size_t retrasoPasos;
	Punto offsetFormacion;
	float rapidezMaxima;
};

struct RegistroExtremos
{
	float minX;
	float maxX;
	float minY;
	float maxY;
	float maxDistanciaDesdeInicio;

	RegistroExtremos()
		: minX(std::numeric_limits<float>::max())
		, maxX(std::numeric_limits<float>::lowest())
		, minY(std::numeric_limits<float>::max())
		, maxY(std::numeric_limits<float>::lowest())
		, maxDistanciaDesdeInicio(0.f)
	{
	}

	void registrarMuestra(const Punto& actual, const Punto& inicio)
	{
		minX = std::min(minX, actual.x);
		maxX = std::max(maxX, actual.x);
		minY = std::min(minY, actual.y);
		maxY = std::max(maxY, actual.y);
		maxDistanciaDesdeInicio = std::max(maxDistanciaDesdeInicio, distancia(actual, inicio));
	}

	std::string formatear() const
	{
		return "minX=" + std::to_string(minX) + " maxX=" + std::to_string(maxX)
			+ " minY=" + std::to_string(minY) + " maxY=" + std::to_string(maxY)
			+ " maxDistOrigen=" + std::to_string(maxDistanciaDesdeInicio);
	}
};
