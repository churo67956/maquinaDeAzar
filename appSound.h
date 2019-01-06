//Autor : Erik Churo y Edison Aushay
//ACCION SONAR MELODIA 
// o ESTADO INIT : ESTADO DE PARTIDA
// o ESTADO ANIMATION : TOCA LA MELODIA, SE ENCARGA DE LLEVAR LA CUENTA DE LA DURACION DE TODA LA PISTA Y DE CADA NOTA DE LA PISTA 
// o ESTADO END : FIN DE LA ANIMACION
// o ESTADO DISABLE : ESTADO DESACTIVADO 
#ifndef APP_SOUND
#define APP_SOUND
#include "appConfiguration.h"
#include "appPIC.h"
//modelo de datos de la accion
struct APP_SOUND_MODEL{
  unsigned char timerCount;//temporizar la duracion de la pista
  unsigned char duration;//duracion de la pista
  struct APP_TRACK *track;//cadena de notas
  unsigned char length;//longitud de la cadena de notas
  unsigned char pointer;//posicion actual dentro de la cadena de notas
  unsigned char state; //estados
  unsigned char nextTimerCount;///temporizador de la duracion de cada nota
  unsigned char noteDuration;//duracion de cada nota
};
//TODO-EMPLEAR CALLBACK PARA AVISAR QUE LA MELODIA HA FINALIZADO
//EN LUGAR DE ESTAR CONTINUAMENTE PREGUNTANDO SI LA MELODIA HA FINALIZADO
//void (*APP_SOUND_Callback)();
//modelo de datos (acceso global)
struct APP_SOUND_MODEL appSound;
//fija la pista
//parametros : APP_TRACK{pista},LENGTH{longitud de la pista},DURATION{duracion de la pista},NOTEDURATION{duracion de la nota} 
void APP_SOUND_SetTrack(struct APP_TRACK *,unsigned char,unsigned char,unsigned char/*,void (*callback)()*/);
//funcion de inicializacion del modelo
void APP_SOUND_Initialize();
//máquina de estados
void APP_SOUND_Task();
#endif
