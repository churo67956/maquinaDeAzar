#include "appS2.h"

//funcion de inicializacion del modelo
void APP_S2_Initialize(){
  appS2.timerCount = 0;//inicializacion del contador
  appS2.state = APP_S2_STATE_INIT;//inicializacion del estado
}
//transicion del estado encendido - apagado o viceversa
void APP_S2_Transition(){
  if(APP_PIC_S2pressed()){//si S2 presionado
    appS2.state = APP_S2_STATE_LOW;//estado bajo
    }
  else{//s2 no esta presionado
    appS2.state = APP_S2_STATE_HIGH;//estado alto
  }
}

//maquina de estados
void APP_S2_Task(){
  switch (appRefresh.state){
  case APP_REFRESH_STATE_INIT://estado de inicio, por protocolo
    APP_S2_Transition();
    break;
  case APP_REFRESH_STATE_LOW://estado de presionado
    if (!APP_PIC_S2pressed()){// no continua presionado
      appS2.state = APP_REFRESH_STATE_DEBOUNCE;//estado de transicion
    }
    break;
  case APP_REFRESH_STATE_DEBOUNCE://estado de transicion
    if (appS2.timerCounter >= 5){//eliminamos los rebotes
      APP_S2_Transition();//transicion de alto-bajo o viceversa
      appS2.timerCounter = 0;//reiniciamos el contador
    }
    break;
  case APP_REFRESH_STATE_HIGH://estado de no presionado
    if (APP_PIC_S2pressed()){// no continua presionado
      appS2.state = APP_REFRESH_STATE_DEBOUNCE;//estado de transicion
    } 
    break;
  default:
    break;
}
		     
