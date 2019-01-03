#include "appSound.h"

//funcion de inicializacion del modelo
void APP_SOUND_Initialize(){
  appSound.timerCount = 0;//contador de 20ms
  appSound.animation = ;//animacion es el doble del tipo de premio
  appSound.pointer = 0;//hasta el valor de la animacion
  appSound.hz =0;//frecuencia
  appSound.state = APP_SOUND_STATE_INIT;//estado inicial 
}

void APP_SOUND_SetHz(char hz){
  appSound.hz =hz;//frecuencia
}

//máquina de estados
void APP_SOUND_Task(){
  switch (appSound.state){
  case APP_SOUND_STATE_INIT:
    APP_PIC_CPPInitialize();
    appSound.state = APP_SOUND_STATE_ANINATION;
    break;
  case APP_SOUND_STATE_PLAY:
    APP_PIC_CPPlay(appSound.hz);
    app
    break;
  case APP_SOUND_STATE_WAIT:
    break;
  case APP_SOUND_STATE_ANIMATION:
    if (pointer){
      
    }
    break;
  case APP_SOUND_STATE_DISABLE:
    break;
  default:
    break;
  }
}

