#include "appBlink.h"
//funcion de inicializacion
void APP_BLINK_Initialize(){
  appBlink.timerCount = 0;//contador de 500ms
  appBlink.animation = 0;//animacion es el doble del tipo de premio
  appBlink.pointer = 0;//hasta el valor de la animacion
  appBlink.state = APP_STATE_DISABLE; //estado de partida
 }
//enciendo o pagada los digitos segun el tipo de premio
void APP_Blink_Toggle(){
      if (appRM.prize == 1){//digitos no consecutivos 
	appModel.digit[0].refresh = !appModel.digit[0].refresh;//negacion
	appModel.digit[2].refresh = !appModel.digit[2].refresh;//negacion
      }
      else if (appRM.prize == 2){//digitos consecutivos
	if (appModel.digit[0].value == appModel.digit[1].value){//el primero y segundo consecutivos
	  appModel.digit[0].refresh = !appModel.digit[0].refresh;//negacion
	  appModel.digit[1].refresh = !appModel.digit[1].refresh;//negacion
	}
	else if (appModel.digit[1].value == appModel.digit[2].value){//el segundo y tercero consecutivos
	  appModel.digit[1].refresh = !appModel.digit[1].refresh;//negacion
	  appModel.digit[2].refresh = !appModel.digit[2].refresh;//negacion
	}
      }
      else {//todos los digitos
	appModel.digit[0].refresh = !appModel.digit[0].refresh;//negacion
	appModel.digit[1].refresh = !appModel.digit[1].refresh;//negacion
	appModel.digit[2].refresh = !appModel.digit[2].refresh;//negacion
      }
}
//maquina de estados
void APP_BLINK_Task(){
  switch (appBlink.state){//segun el estado hacer
  case APP_STATE_INIT://estado de inicio
    appBlink.animation = (appRM.prize << 1) -1;//fijamos en numero de veces del parpadeo
    if (appBlink.animation == 0){//no es necesario la animacion
      appBlink.state = APP_STATE_END;//estado fin animacion
    }
    else{
      appBlink.state = APP_STATE_ANIMATION;//estado de animacion
      appBlink.timerCount = appConfig._500_MS_;//empezar la animacion YA,por motivos de la programacion del estado ANIMATION
    }
    break;
  case APP_STATE_ANIMATION://animacion
    if (appBlink.timerCount >= appConfig._500_MS_){//han  pasado 500ms
      appBlink.timerCount = 0;//reiniciamos contador
      if (appBlink.pointer < appBlink.animation){//es necesario siguir animando
       APP_BLINK_Toggle();//enciendo o pagada los digitos
       appBlink.pointer = appBlink.pointer + 1;//incrementamos puntero
      }
      else{
      	APP_BLINK_Toggle();//enciendo o pagada los digitos
        appBlink.state = APP_STATE_END;//fin de la animacion
      }
    }
    break;
  case APP_STATE_END://fin de la tarea
    appBlink.state = APP_STATE_DISABLE;//estano inactivo
    break;
  default://STATE_DISABLE
    //NO HACER NADA A LA ESPERA
    break;
  }
}
