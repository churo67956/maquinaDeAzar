//Autor : Erik Churo y Edison Aushay
//ACCION DE REFRESCO DE LOS DISPLAYS CADA 5MS
//LOS DIFERENTES ESTADOS POR LOS QUE PASA LA TAREA
//SON : 
//	INIT : estado de inicio
//      REFRESH : estado de refresco del i-esimo digito
//      WAIT : estado de espera de 5ms
//      DISABLE : estado desactivado 
#ifndef APP_REFRESH
#define APP_REFRESH
#include "appConfiguration.h"
#include "appModel.h"
#include "appPIC.h"
//modelo de datos de la accion REFRESH
struct APP_REFRESH_MODEL{
  unsigned char timerCount;//contador de 5ms
  unsigned char pointer;//apuntador del display a refrescar
  unsigned char state; //estados
};
//instancia del modelo de datos (acceso global)
struct APP_REFRESH_MODEL appRefresh;
//funcion de inicializacion del modelo
void APP_REFRESH_Initialize();
//máquina de estados
void APP_REFRESH_Task();
#endif
