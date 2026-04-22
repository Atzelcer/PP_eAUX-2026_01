#include "GestorEjercitoEnemigo.h"
#include "Actor.h"

GestorEjercitoEnemigo::GestorEjercitoEnemigo()
	: tiempo_(0.f)
	, fase_(FaseEjercito::Reposo)
	, hogarLider0_{ 260.f, 68.f }
	, hogarLider1_{ 540.f, 68.f }
{
}

void GestorEjercitoEnemigo::agregarUnidad(UnidadEjercito unidad)
{
	int claveId = unidad.id;
	idAIndice_[claveId] = unidades_.size();
	unidades_.push_back(std::move(unidad));
}

Punto GestorEjercitoEnemigo::mezclar(const Punto& a, const Punto& b, float t)
{
	return Punto{ a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t };
}

void GestorEjercitoEnemigo::desplegarFormacionInicial()
{
	unidades_.clear();
	idAIndice_.clear();
	rutasLideres_[0].clear();
	rutasLideres_[1].clear();
	tiempo_ = 0.f;
	fase_ = FaseEjercito::Reposo;

	int id = 0;
	{
		UnidadEjercito u;
		u.id = id++;
		u.actor = fabrica_.crearNova(this, &gameManager_, u.id, hogarLider0_.x, hogarLider0_.y);
		u.lider = true;
		u.indiceLider = 0;
		u.hogar = hogarLider0_;
		u.offset = Punto{ 0.f, 0.f };
		u.retrasoPasos = 0;
		u.centroOrbita = hogarLider0_;
		u.radioOrbitaIn = 28.f;
		u.radioOrbitaOut = 62.f;
		agregarUnidad(std::move(u));
	}
	{
		UnidadEjercito u;
		u.id = id++;
		u.actor = fabrica_.crearNova(this, &gameManager_, u.id, hogarLider1_.x, hogarLider1_.y);
		u.lider = true;
		u.indiceLider = 1;
		u.hogar = hogarLider1_;
		u.offset = Punto{ 0.f, 0.f };
		u.retrasoPasos = 0;
		u.centroOrbita = hogarLider1_;
		u.radioOrbitaIn = 28.f;
		u.radioOrbitaOut = 62.f;
		agregarUnidad(std::move(u));
	}

	Punto aA{ 155.f, 138.f };
	Punto bA{ 355.f, 138.f };
	Punto aB{ 445.f, 138.f };
	Punto bB{ 645.f, 138.f };
	float ts[4] = { 0.2f, 0.4f, 0.6f, 0.8f };

	for (int i = 0; i < 4; ++i)
	{
		Punto h = mezclar(aA, bA, ts[i]);
		Punto off{ h.x - hogarLider0_.x, h.y - hogarLider0_.y };
		Punto centro{ h.x, h.y - 18.f };
		UnidadEjercito u;
		u.id = id++;
		u.lider = false;
		u.indiceLider = 0;
		u.hogar = h;
		u.offset = off;
		u.retrasoPasos = static_cast<size_t>(9 + i * 3);
		u.radioOrbitaIn = 34.f;
		u.radioOrbitaOut = 74.f;
		u.centroOrbita = centro;
		if (i % 2 == 0)
		{
			u.actor = fabrica_.crearNova(this, &gameManager_, u.id, h.x, h.y);
			u.radioOrbitaIn = 26.f;
			u.radioOrbitaOut = 58.f;
			u.centroOrbita = h;
		}
		else
			u.actor = fabrica_.crearEstrella(this, &gameManager_, u.id, h.x, h.y);
		agregarUnidad(std::move(u));
	}

	for (int i = 0; i < 4; ++i)
	{
		Punto h = mezclar(aB, bB, ts[i]);
		Punto off{ h.x - hogarLider1_.x, h.y - hogarLider1_.y };
		Punto centro{ h.x, h.y - 18.f };
		UnidadEjercito u;
		u.id = id++;
		u.lider = false;
		u.indiceLider = 1;
		u.hogar = h;
		u.offset = off;
		u.retrasoPasos = static_cast<size_t>(9 + i * 3);
		u.radioOrbitaIn = 34.f;
		u.radioOrbitaOut = 74.f;
		u.centroOrbita = centro;
		if (i % 2 == 0)
		{
			u.actor = fabrica_.crearNova(this, &gameManager_, u.id, h.x, h.y);
			u.radioOrbitaIn = 26.f;
			u.radioOrbitaOut = 58.f;
			u.centroOrbita = h;
		}
		else
			u.actor = fabrica_.crearEstrella(this, &gameManager_, u.id, h.x, h.y);
		agregarUnidad(std::move(u));
	}
}

void GestorEjercitoEnemigo::actualizarFase()
{
	FaseEjercito anterior = fase_;
	if (tiempo_ < kFinReposo)
		fase_ = FaseEjercito::Reposo;
	else if (tiempo_ < kFinOfensiva)
		fase_ = FaseEjercito::Ofensiva;
	else
		fase_ = FaseEjercito::Retorno;
	if (anterior != fase_)
	{
		rutasLideres_[0].clear();
		rutasLideres_[1].clear();
	}
}

ContextoMovimiento GestorEjercitoEnemigo::construirContexto(int idClave)
{
	size_t ind = idAIndice_.at(idClave);
	const UnidadEjercito& u = unidades_[ind];
	ContextoMovimiento ctx;
	ctx.fase = fase_;
	ctx.tiempoSimulacion = tiempo_;
	ctx.centroRegion = u.centroOrbita;
	ctx.radioInterior = u.radioOrbitaIn;
	ctx.radioExterior = u.radioOrbitaOut;
	ctx.posicionHogar = u.hogar;
	ctx.esLider = u.lider;
	ctx.indiceLider = u.indiceLider;
	ctx.trayectoriaLider = u.lider ? nullptr : &rutasLideres_[static_cast<size_t>(u.indiceLider)];
	ctx.retrasoPasos = u.retrasoPasos;
	ctx.offsetFormacion = u.offset;
	ctx.rapidezMaxima = 165.f;
	return ctx;
}

MovimientoSeguidor& GestorEjercitoEnemigo::movimientoSeguidor()
{
	return movimientoSeguidor_;
}

MovimientoRetornoAlHogar& GestorEjercitoEnemigo::movimientoRetorno()
{
	return movimientoRetorno_;
}

MovimientoOfensivaLider& GestorEjercitoEnemigo::movimientoOfensivaLider()
{
	return movimientoOfensivaLider_;
}

void GestorEjercitoEnemigo::registrarMuestrasLideres()
{
	for (const UnidadEjercito& u : unidades_)
	{
		if (!u.lider)
			continue;
		Punto m{ u.actor->getX(), u.actor->getY() };
		rutasLideres_[static_cast<size_t>(u.indiceLider)].push_back(m);
		if (rutasLideres_[static_cast<size_t>(u.indiceLider)].size() > 2600u)
			rutasLideres_[static_cast<size_t>(u.indiceLider)].pop_front();
	}
}

void GestorEjercitoEnemigo::pasoIntegracion(float dt)
{
	actualizarFase();
	for (UnidadEjercito& u : unidades_)
	{
		if (u.lider)
			continue;
		u.actor->actualizar(dt);
	}
	for (UnidadEjercito& u : unidades_)
	{
		if (!u.lider)
			continue;
		u.actor->actualizar(dt);
	}
	registrarMuestrasLideres();
	tiempo_ += dt;
}
