# Ejercicio 1 — Jerarquia sobre Actor, patrones de creacion y movimiento en reposo

## De que va este bloque

Este es el cimiento. Aqui montamos todo lo que el enunciado pide sobre arrancar desde la clase **Actor**, sacar **dos tipos de nave** distintos (**EnemigoNaveNova** y **EnemigoNaveEstrella**) y no mezclar en un mismo sitio la **fabricacion** de bichos con la **logica de movimiento**. En reposo, una nave va mas “nerviosa” y la otra gira en una orbita un poco caprichosa alrededor de un centro; eso es lo que diferencia a Nova y Estrella cuando no estan atacando.

## Jerarquia, contada sin tecnicismo forzado

**Actor** sigue siendo el personaje base del motor: posicion, velocidad, el `actualizar` de siempre. Las dos naves nuevas no reescriben el motor desde cero; solo aportan su toque en reposo (una estrategia u otra). Cuando la partida pasa a ofensiva o a volver al sitio inicial, eso ya lo coordina el gestor del ejercicio 2, pero el contrato es el mismo: “dame un contexto y yo aplico la tactica que toque”.

## Por que Factory y Strategy aqui

**FabricaEnemigos** evita que cada vez que quieras una nave copies y pegues el constructor enorme de **Actor**. Si manana anades otro enemigo, tocas un solo sitio y listo; el resto del codigo no se entera de los detalles feos de construccion.

**IMovimientoEnemigo** con **MovimientoNova** y **MovimientoEstrella** es la idea de “cambia el comportamiento sin reescribir la clase entera”. Quieres otro reposo distinto? Metes otra clase que cumpla la interfaz. Te viene bien si mas adelante quieres cargar cosas desde archivo o tunear la IA sin abrir diez herencias raras.

En pocas palabras: la fabrica responde a **quien crea y como**; la estrategia responde a **como se mueve hoy** sin liarla con el arbol de clases.

## Que archivos encontraras aqui

- Tipos y contrato: `SimulacionTypes.h`, `IMovimientoEnemigo.h`
- Movimiento en reposo: `MovimientoNova`, `MovimientoEstrella`
- Piezas de juego: `FabricaEnemigos`, `EnemigoNaveNova`, `EnemigoNaveEstrella`
- El `SimulacionGameManager` es el adaptador minimo para que **Actor** siga hablando con un **GameManager** en esta simulacion

## Como compila esto

Esta carpeta no es un programa suelto: necesita **Compartido_Actor** y los otros dos ejercicios. Desde la raiz del proyecto, lo mas comodo es lanzar `Compilar_Galaga_Tres_Ejercicios.sh` y olvidarte de los `-I` a mano.
