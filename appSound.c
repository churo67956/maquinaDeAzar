#include "appSound.h"
//funcion de inicializacion del modelo
void APP_SOUND_Initialize(){
  appSound.timerCount = 0;//contador
  appSound.duration = 0;//duracion de la pista
  appSound.track = 0;//cadena de frecuencias
  appSound.length = 0;//longitud de la cadena pista
  appSound.state = APP_STATE_DISABLE;//estado inicial 
  appSound.noteDuration = 0;//duracion de cada nota
  appSound.nextTimerCount = 0;//temporizador de la duracion de la nota
}
//funcion para fijar la pista a sonar
void APP_SOUND_SetTrack(struct APP_TRACK *track,unsigned char length,unsigned char duration,unsigned char noteDuration/*,void (*callback)()*/){
  appSound.duration = duration;//duracion
  appSound.noteDuration = noteDuration;//duracion de cada nota
  appSound.track = track;//fijamos la pista
  appSound.length = length;//longitud de la cadena track
  //APP_SOUND_Callback = callback;
}

//máquina de estados
void APP_SOUND_Task(){
  switch (appSound.state){//segun el tipo de estado
  case APP_STATE_INIT:
    APP_PIC_RC2CPPInitialize();//inicializacion del modulo CPP
    appSound.state = APP_STATE_ANIMATION;//actualiza el estado
    appSound.nextTimerCount = appSound.noteDuration;//simulacion para que inicie a sonar YA,como consecuencia
						    //de la programacion del estado ANIMATION
    break;
  case APP_STATE_ANIMATION:
    //la detectar la duracion de la pista tiene mayor prioridad que la duracion de una nota
    if (appSound.timerCount >= appSound.duration){//ha pasado la duracion de la pista
      appSound.timerCount = 0;//reiniciar el contador
      appSound.state = APP_STATE_END;//estado de desactivado
    }
    else{//siguiente nota
      if(appSound.nextTimerCount >= appSound.noteDuration){
	APP_PIC_CPPStop();//paramos de sonar
	if (appSound.pointer > appSound.length){//existen notas
	  appSound.pointer = 0;//reiniciar el apuntador
	}
	APP_PIC_CPPWM(appSound.track[appSound.pointer].PR2,appSound.track[appSound.pointer].CCPRL);//tocar la siguiente nota
	appSound.pointer = appSound.pointer + 1;//actualizar apuntado
	appSound.nextTimerCount = 0;//reiniciamos el contador de la duracion de la nota actual
      }
    }
    break;   
  case APP_STATE_END://estado parar de sonar
    /*if (APP_SOUND_Callback){//ejecutar el callback
      APP_SOUND_Callback();
      }*/
    APP_PIC_CPPStop();//paramos de sonar
    appSound.state = APP_STATE_DISABLE;//tarea inactiva
  default://APP_SOUND_STATE_DISABLE
    //NO HACER NADA
    break;
  }
}

