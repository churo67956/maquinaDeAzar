#include "appS2.h"
//funcion de inicializacion del modelo
void APP_S2_Initialize(){
  appS2.timerCount = 0;//inicializacion del contador
  appS2.state = APP_STATE_DISABLE;//inicializacion del estado
}
//maquina de estados
void APP_S2_Task(){
  switch (appS2.state){//segun el tipo de dato
  case APP_STATE_INIT://estado de inicio
    appS2.state = APP_STATE_HIGH;//estado HIGH, pulsador no presionado 
    break;
  case APP_STATE_LOW://estado de presionado
    if (!APP_PIC_BtnPressed()){// no continua presionado
      appS2.state = APP_STATE_DEBOUNCE;//estado de transicion
    }
    break;
  case APP_STATE_DEBOUNCE://estado de transicion
      if (appS2.timerCount >= appConfig._20_MS_){//eliminamos los rebotes
	    if(APP_PIC_BtnPressed()){//si S2 presionado
	      appS2.state = APP_STATE_LOW;//estado bajo
	    }
	    else{//s2 no esta presionado
	      appS2.state = APP_STATE_HIGH;//estado alto
 ji = ji + 1;
	      appRM.state = APP_STATE_INIT;//arrancar la partida
	    }
	    appS2.timerCount = 0;//reiniciamos el contador
      }
    break;
  case APP_STATE_HIGH://estado de no presionado
    if (APP_PIC_BtnPressed()){// no continua presionado
      appS2.state = APP_STATE_DEBOUNCE;//estado de transicion
    } 
    break;
  case APP_STATE_DISABLE://STATE_S2_STATE_DISABLE
    //no hacer nada
    break;
  default:
	break;
  }
}
		     
