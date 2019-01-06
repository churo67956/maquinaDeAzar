//Autor : Erik Churo y Edison Aushay
//ACCION PROPIA DE LA MAQUINA DE AZAR ES DECIR 
// o ESTADO INIT : LA GENERACION DE NUMEROS ALEATORIOS
// o ESTADO ANIMATION : CAMBIO DE LOS DIGITOS CADA 50MS
// o ESTADO FIX_DISPLAY : FIJAR LOS DIGITOS EN INTERVALOS DE 1 SEGUNDO Y EFECTOS SONOROS DE PARADA
// o ESTADO WAIT_UNTIL_PLAY_END : ES NECESARIO ESPERAR A QUE LA ULTIMA NOTA FINALIZE PARA IR AL ESTADO END 
// o ESTADO END : ANALIZAR SI LA SECUENCIA FINAL ES LA PREMIADA INICIAR LOS EFECTOS DE PARPADEO 
//                Y SONOROS EN CASO DE SER UNA SECUENCIA PREMIADA.SI LA SECUENCIA NO ES PREMIADA ACTIVA
//                EL PULSADOR
#ifndef APP_RM
#define APP_RM
#include "appConfiguration.h"
#include "appModel.h"
#include "appPIC.h"
#include "appSound.h"
#include "appS2.h"
#include "appBlink.h"
#include "appOrchestrate.h"
//modelo de datos de la accion
struct APP_RM_MODEL{
  unsigned char timerCount;//contador de 50ms
  unsigned char updateTimerCount;//contador de 1seg
  unsigned char pointer;//siguiente digito a parar
  unsigned char prize;//premio
  unsigned char state; //estados
};
//instancia del modelo de datos (acceso global)
struct APP_RM_MODEL appRM;
//funcion de inicializacion del modelo
void APP_RM_Initialize();
//funcion de actualizacion de los digitos
void APP_RM_Update(char);
//funcion que determina el tipo de premio
void APP_RM_AwardedSeq();
//funcion que simula un generador de numeros aleatorios
unsigned char APP_RM_Random();
//máquina de estados
void APP_RM_Task();
#endif
