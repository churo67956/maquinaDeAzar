//Autor : Erik Churo y Edison Aushay
//ACCION EFECTOS SONOROS COMBINACION GANADORA 
// o ESTADO INIT : ESTADO INCIAL, FIJA LAS ITERACIONES DE LA ANIMACION
// o ESTADO ANIMATION : EFECTOS SONORAS SEGUN EL TIPO DE PREMIO
// o ESTADO WAIT : ESTADO DE ESPERA, ESPERA A QUE FINALICE UNA ITERACION DE LA MELONIA PARA CONTINUAR CON LA ANIMACION
// o ESTADO END : SI LA SECUENCIA ES PREMIADA ACTIVAR EL PULSADOR
#ifndef _APP_ORCHESTRATE_
#define _APP_ORCHESTRATE_
#include "appConfiguration.h"
#include "appSound.h"
#include "appRM.h"
//modelo de datos de la accion
struct APP_ORCHESTRATE_MODEL{
  unsigned char animation;//animacion es el doble del tipo de premio
  unsigned char pointer;//hasta el valor de la animacion
  unsigned char state;//estados
};
//instancia del modelo de datos 
struct APP_ORCHESTRATE_MODEL appOrchestrate;
//funcion de inicializacion
void APP_ORCHESTRATE_Initialize();
//fija la melodia a sonar segun el premio e instante de la animacion
void APP_ORCHESTRATE.SetSound();
//maquina de estados
void APP_ORCHESTRATE_Task();
#endif
