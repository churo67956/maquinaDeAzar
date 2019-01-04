#include "appBlink.h"

//funcion de inicializacion
void APP_BLINK_Initialize(){
  appBlink.timerCount = 0;//contador de 20ms
  appBlink.animation = 0;//animacion es el doble del tipo de premio
  appBlink.pointer = 0;//hasta el valor de la animacion
  appBlink.state = APP_BLINK_STATE_DISABLE; //estado de partida
 }

//maquina de estados
void APP_BLINK_Task(){
  switch (appBlink.state){
  case APP_BLINK_STATE_INIT://estao de inicio
    appBlink.animation = appRM.prize<<1;//fijamos en numero de veces del parpadeo
    if (appBlink.animation == 0){//no es necesario la animacion
      appBlink.state = APP_BLINK_STATE_DISABLE;//estado fin animacion
    }
    else{
      appBlink.state = APP_BLINK_STATE_ANIMATION;//estado de animacion
    }
    break;
  case APP_BLINK_STATE_WAIT://estado de espera
    if (appBlink.timerCount >= 100){//han  pasado 500ms
      appBlink.timerCount = 0;//reiniciamos contador
      appBlink.state = APP_BLINK_STATE_ANIMATION;//estado de animacion
    }
    break;
  case APP_BLINK_STATE_ANIMATION://animacion del parpadeo
    if (appBlink.pointer < appBlink.animation){//es necesario siguir animando
      if (appRM.prize == 1){//digitos no consecutivos 
	appModel.digit[0].refresh = !appModel.digit[0].refresh;//negacion
	appModel.digit[2].refresh = !appModel.digit[0].refresh;//negacion
      }
      else if (appRM.prize == 2){//digitos consecutivos
	if (appModel.digit[0].value == appModel.digit[1].value){//el primero y segundo consecutivos
	  appModel.digit[0].refresh = !appModel.digit[0].refresh;//negacion
	  appModel.digit[1].refresh = !appModel.digit[0].refresh;//negacion
	}
	else if (appModel.digit[1].value == appModel.digit[2].value){//el segundo y tercero consecutivos
	  appModel.digit[1].refresh = !appModel.digit[0].refresh;//negacion
	  appModel.digit[2].refresh = !appModel.digit[0].refresh;//negacion
	}
      }
      else {//todos los digitos
	appModel.digit[0].refresh = !appModel.digit[0].refresh;//negacion
	appModel.digit[1].refresh = !appModel.digit[0].refresh;//negacion
	appModel.digit[2].refresh = !appModel.digit[0].refresh;//negacion
      }
      appBlink.pointer = appBlink.pointer + 1;//incrementamos puntero 
      appBlink.state = APP_BLINK_STATE_WAIT;//estado de espera
    }
    else{//fin animacion
      appBlink.state = APP_BLINK_STATE_DISABLE;//estado fin de animacion
    }
    break;
  default:
    break;
  }
}
