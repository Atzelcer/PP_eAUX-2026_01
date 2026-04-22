# Ejercicio 2 — Formacion del ejercito, lideres, ofensiva y seguimiento de trayectoria

## De que va este bloque

Aqui ya no hablamos solo de una nave suelta, sino de **la formacion**: al menos diez enemigos, colocados con criterio (equidistantes en cada ala), **dos lideres arriba** que son los primeros en tirar la ofensiva, y el resto **enganchado a un jefe** siguiendo su estela con un poco de retraso y un desfase de formacion. Cuando pasa la embestida, todo el mundo intenta **volver al hueco donde empezo**; eso va ligado a las estrategias de movimiento que ves en esta carpeta (ofensiva del lider, seguidor, retorno al hogar).

## Contenedores que veras por aqui (y el enlace con el ejercicio 3)

No hace falta memorizar nombres raros; la idea es practica:

- Un **vector** de unidades con **unique_ptr** a **Actor**: orden claro, y cuando sueltas el vector las naves se destruyen bien, sin fugas raras de punteros.
- Un **unordered_map** de id a indice: cuando necesitas “la unidad 7”, no recorres todo el ejercito a lo bruto.
- Un **array** de dos **deque** de puntos (uno por lider): es la “cinta” de la trayectoria del jefe. El seguidor mira atras en esa cinta; el **deque** ayuda porque quitar muestras viejas por delante no te deja el programa patinando como con otros contenedores.

El **mapa de posiciones extremas** y el **reloj de 20 segundos con informes** estan en el ejercicio 3, en **MotorSimulacionYReportes**. El gestor de este ejercicio se limita a mover el mundo frame a frame y a dejar datos accesibles (tiempo, unidades, `pasoIntegracion`) para que el otro modulo imprima y acumule estadisticas.

## Que archivos encontraras aqui

- `MovimientoOfensivaLider`, `MovimientoSeguidor`, `MovimientoRetornoAlHogar`
- `GestorEjercitoEnemigo`: despliega la formacion, cambia fases globales, integra cada frame y va rellenando las estelas de los lideres

## Como compila esto

Se apoya en el ejercicio 1 (tipos, fabrica, naves, game manager de simulacion) y en **Compartido_Actor**. Otra vez: desde la raiz, `Compilar_Galaga_Tres_Ejercicios.sh` y listo.
