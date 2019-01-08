//Autor : Erik Churo y Edison Aushay
//ACCION PULSAR BOTON MARCA EL INICIO DE LA PARTIDA
//LOS DIFERENTES ESTADOS POR LOS QUE PASA LA TAREA
//SON : 
//	INIT : estado de inicio
//      HIGH : estado no presionado
//      DEBOUNCE : estado de transicion entre LOW - HIGH o viceversa, tambien evita los rebotes
//      LOW : estado presionado
//      DISABLE : estado desactivado 
#ifndef APP_S2
#define APP_S2
#include "appConfiguration.h"
#include "appRM.h"

unsigned char ji = 0;

//modelo de datos de la accion pulsar
struct APP_S2_MODEL{
  unsigned char timerCount;//contador de 20ms
  unsigned char state; //estados
};
//instancia del modelo de datos (acceso global)
struct APP_S2_MODEL appS2;
//funcion de inicializacion del modelo
void APP_S2_Initialize();
//máquina de estados
void APP_S2_Task();
#endif
