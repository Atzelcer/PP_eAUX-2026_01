# Ejercicio 3 — Contenedores de extremos, tiempo de simulacion e informes

## De que va este bloque

Este es el cierre “del examen de auxiliatura”: aqui cumplimos lo de **contenedores avanzados** para llevar la cuenta de **hasta donde llego cada nave** respecto a su sitio inicial, correr **20 segundos** de simulacion, **soltar un informe a los 10 y a los 20** con los extremos que se fueron viendo, y terminar con un **resumen** que puedas leer de un vistazo.

## El mapa de extremos, en lenguaje llano

Usamos un **unordered_map** que va de **id de unidad** a un **RegistroExtremos** (definido en `SimulacionTypes.h` del ejercicio 1). Piensa en una libreta por nave: en cada paso anotas si rompio record de minimo o maximo en x e y, y cuanto se alejo como mucho de su “casa”. Consultar por id es rapido; no tienes que buscar en listas largas cada vez que imprimes.

**MotorSimulacionYReportes** es quien pone el cronometro: avanza el gestor con `pasoIntegracion`, actualiza esa libreta, y cuando el reloj pasa de 10 y de 20 segundos escupe el estado de los extremos. Al final cierra con un resumen en texto.

## Si un dia esto fuera un juego serio

- El informe por consola podria ser un log, un CSV o un panel de debug en pantalla.
- El mismo mapa de extremos te sirve para ver que tan agresiva fue una oleada o para balancear dificultad.
- Podrias parametrizar duracion e intervalos sin tocar el corazon del gestor, solo este motor de reporte.

## Que archivos encontraras aqui

- `MotorSimulacionYReportes.h` y `.cpp`
- `main_simulacion_enemigos.cpp` (punto de entrada del programa)

## Como encaja todo el arbol de carpetas

- **Compartido_Actor**: el Actor base y las cabeceras minimas del proyecto.
- **Ejercicio_01_Jerarquia_Patrones_Creacion_Movimiento**
- **Ejercicio_02_Formacion_Ejercito_Lideres_Trayectorias**
- **Ejercicio_03_Contenedores_Tiempo_Reportes** (donde estas leyendo esto)

Para compilar el binario final: en la raiz `PP_eAUX-2026_01`, ejecuta `Compilar_Galaga_Tres_Ejercicios.sh`. El ejecutable queda en esta carpeta con nombre `simulacion_enemigos`.
