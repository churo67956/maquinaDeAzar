#include "appBlink.h"

void APP_ORCHESTRATE_Initialize(){
  appBlink.animation = 0;//animacion es el doble del tipo de premio
  appBlink.pointer = 0;//hasta el valor de la animacion
  appBlink.state = APP_ORCHESTRATE_STATE_DISABLE; //estado de partida
}

 
//máquina de estados
void APP_ORCHESTRATE_Task(){
  switch (appBlink.state){
  case APP_ORCHESTRATE_STATE_INIT://estao de inicion
    appOrchestrate.animation = appRM.prize;//fijamos en numero de veces de la animacion
    if (appOrchestrate.animation == 0){//no es necesario la animacion
      appOrchestrate.state = APP_ORCHESTRATE_STATE_DISABLE;//estado fin animacion
    }
    else{
      appOrchestrate.state = APP_ORCHESTRATE_STATE_PLAY;//estado de animacion
    }
    break;
  case APP_ORCHESTRATE_STATE_WAIT://estado de espera
    if (appSound.state == APP_SOUND_STATE_STOP){//han pasado 1s
      appOrchestrate.state = APP_ORCHESTRATE_STATE_PLAY;//estado de animacion
    }
    break;
  case APP_ORCHESTRATE_STATE_PLAY://animacion
    if (appOrchestrate.pointer < appOrchestrate.animation){//es necesario siguir animando
      if (appRM.prize == 1){//digitos no consecutivos 
	APP_SOUND_SetTrack(appConfig.SCALE_NOTES_ASC,appConfig._1_SEG);
      }
      else if (appRM.prize == 2){//digitos consecutivos
	if (appOrchestate.pointer == 0){//el primero y segundo consecutivos
	  APP_SOUND_SetTrack(appConfig.SCALE_NOTES_ASC,appConfig._1_SEG);
	}
	else if (appOrchestra.pointer == 1){//el segundo y tercero consecutivos
	  APP_SOUND_SetTrack(appConfig.SCALE_NOTES_DESC,appConfig._1_SEG);
	}
      }
      else {//todos los digitos
	if (appOrchestrate.pointer == 0 || appOrchestrate.pointer == 2){//el primero y segundo consecutivos
	  APP_SOUND_SetTrack(appConfig.SCALE_NOTES_ASC,appConfig._1_SEG);
	}
	else if (appOrchestra.pointer == 1){//el segundo y tercero consecutivos
	  APP_SOUND_SetTrack(appConfig.SCALE_NOTES_DESC,appConfig._1_SEG);
	}
      }
      appSound.state = APP_SOUND_STATE_INIT;//estado de inicio del sonido
      appOrchestrate.pointer = appOrchestrate.pointer + 1;//incrementamos puntero
      appOrchestrate.state = APP_ORCHESTRATE_STATE_WAIT;//estado de espera
    }
    else{//fin animacion
      appOrchestrate.state = APP_ORCHESTRATE_STATE_DISABLE;//estado fin de animacion
    }
    break;
  default://APP_ORCHESTRA_STATA_DISABLE
    break;
  }
}

