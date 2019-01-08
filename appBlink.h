//Autor : Erik Churo y Edison Aushay
//ACCION EFECTOS DE PARPADEO PARA UNA SECUENCIA GANADORA. ESTADOS POSIBLES
// o ESTADO INIT : ESTADO DE INICIO, FIJA EL NUMERO DE VECES QUE SE REPITE LA ANIMACION
// o ESTADO ANIMATION : ENCIENCE <-> APAGA LOS DISPLAYS   
// o ESTADO WAIT : ESPERA ANTES DE VOLVER A REALIZAR LA ANIMACION
// o ESTADO END : FIN DE LA ANIMACION 
// o ESTADO DISABLE : ESTADO INACTIVO
#ifndef _APP_BLINK_
#define _APP_BLINK_
#include "appConfiguration.h"
#include "appRM.h"
#include "appModel.h"
#include "appRefresh.h"
//modelo de datos de la accion
struct APP_BLINK_MODEL{
  unsigned char timerCount;//contador de 500ms
  unsigned char animation;//animacion es el doble del tipo de premio
  unsigned char pointer;//hasta el valor de la animacion
  unsigned char state; //estados
};
//instancia del modelo de datos (acceso global)
struct APP_BLINK_MODEL appBlink;
//funcion de inicializacion del modelo
void APP_BLINK_Initialize();
//enciendo o pagada los digitos segun el tipo de premio
void APP_Blink_Toggle();
//máquina de estados
void APP_BLINK_Task();
#endif
