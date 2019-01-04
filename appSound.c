#include "appSound.h"

//funcion de inicializacion del modelo
void APP_SOUND_Initialize(){
  appSound.timerCount = 0;//contador
  appSound.duration = 0;//duracion de la pista
  appSound.track = 0;//cadena de frecuencias
  appSound.length = 0;//longitud de la cadena pista
  appSound.state = APP_SOUND_STATE_DISABLE;//estado inicial 
}

//funcion para fijar la pista a sonar
void APP_SOUND_SetTrack(unsigned char *track,unsigned char duration/*,void (*callback)()*/){
  appSound.track = track;
  appSound.duration = duration;
  //APP_SOUND_Callback = callback;
}

//máquina de estados
void APP_SOUND_Task(){
  switch (appSound.state){
  case APP_SOUND_STATE_INIT:
    APP_PIC_RC2CPPInitialize();//inicializacion del modulo CPP
    appSound.state = APP_SOUND_STATE_PLAY;
    break;
  case APP_SOUND_STATE_PLAY:
    if (appSound.timerCount >= appSound.duration){//ha pasado la duracion de la pista
      appSound.timerCount = 0;//reiniciar el contador
      appSound.state = APP_SOUND_STATE_STOP;//estado de desactivado
    }
    else{//siguiente nota
      if (appSound.pointer < appSound.length){//existen notas
	APP_PIC_CPPWM(appSound.track[appSound.pointer]);//tocar la siguiente nota
	appSound.pointer = appSound.pointer + 1;//actualizar apuntador
      }
      else{
	appSound.pointer = 0;//reiniciar el apuntador
      }
    }
    break;   
  case APP_SOUND_STATE_STOP://estado parar de sonar
    /*if (APP_SOUND_Callback){//ejecutar el callback
      APP_SOUND_Callback();
      }*/
    APP_PIC_CPPStop();//paramos de sonar
  default://APP_SOUND_STATE_DISABLE
    break;
  }
}

