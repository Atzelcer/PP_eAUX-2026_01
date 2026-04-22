#include "MotorSimulacionYReportes.h"
#include <iostream>

int main()
{
	MotorSimulacionYReportes motor;
	motor.desplegarYPrepararRegistro();
	std::cout << "Simulacion de enemigos tipo Galaga (20 s, informes a 10 s y 20 s).\n";
	motor.ejecutarSimulacion20Segundos();
	return 0;
}
