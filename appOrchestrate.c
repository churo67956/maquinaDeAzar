#include "appOrchestrate.h"
//funcion de inicializacion
void APP_ORCHESTRATE_Initialize(){
  appOrchestrate.animation = 0;//animacion es el doble del tipo de premio
  appOrchestrate.pointer = 0;//hasta el valor de la animacion
  appOrchestrate.state = APP_STATE_DISABLE; //estado de partida
}
//fija la melodia a sonar segun el tipo de premio e instante de la animacion
void APP_ORCHESTRATE.SetSound(){
  if (appRM.prize == 1 //premio 1
    || (appRM.prize == 2 && appOrchestrate.pointer == 0) //premio 2 y primera iteracion de la animacion
    || (appRM.prize == 3 && (appOrchestrate.pointer == 0 || appOrchestrate.pointer == 2))){//premio 3 y primera o tercera iteracion de la animacion
    APP_SOUND_SetTrack(&appConfig.SCALE_NOTES_ASC[0],appConfig._8_,appConfig._1_SEG_,appConfig._125_MS_);//escala ascendente
  }
  else if ((appRM.prize == 3 && appOrchestrate.pointer == 1) //premio 3 y segunda iteracion de la animacion
    || (appRM.prize == 2 && appOrchestrate.pointer == 1)){//premio 2 y segunda iteracion de la animacion
    APP_SOUND_SetTrack(&appConfig.SCALE_NOTES_DESC[0],appConfig._8_,appConfig._1_SEG_,appConfig._125_MS_);//escala descendente
  }
}
//máquina de estados
void APP_ORCHESTRATE_Task(){
  switch (appOrchestrate.state){
  case APP_STATE_INIT://estao de inicion
    appOrchestrate.animation = appRM.prize;//fijamos en numero de veces de la animacion
    if (appOrchestrate.animation == 0){//no es necesario la animacion
      appOrchestrate.state = APP_STATE_END;//estado fin animacion
    }
    else{
      appOrchestrate.state = APP_STATE_ANIMATION;//estado de animacion
      appSound.state == APP_STATE_DISABLE;//la animacion empieza YA,por motivos de la programacion
    }
    break;
  case APP_STATE_ANIMATION://estado de espera
    if (appSound.state == APP_STATE_END
	|| appSound.state == APP_STATE_DISABLE){//han pasado 1s
      if (appOrchestrate.pointer < appOrchestrate.animation){//es necesario siguir animando
        APP_ORCHESTRATE.SetSound();//fija la melodia a sonar
        appSound.state = APP_STATE_INIT;//estado de inicio del sonido
        appOrchestrate.pointer = appOrchestrate.pointer + 1;//incrementamos puntero
      }
      else{//fin animacion
        appOrchestrate.state = APP_STATE_END;//estado fin de animacion
      }
    }
    break;
  case APP_STATE_END://estado fin de la animacion
    if (appRM.prize > 0){//combinacion premiada
      appS2.state = APP_STATE_INIT;//volver activar el boton
    }
    appOrchestrate.state = APP_STATE_DISABLE;//inactivamos la tarea
    break;
  default://APP_ORCHESTRA_STATA_DISABLE
    break;
  }
}

