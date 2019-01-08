#include "appRefresh.h"
//funcion de inicializacion del modelo
void APP_REFRESH_Initialize(){
  appRefresh.timerCount = 0;//inicializacion del contador
  appRefresh.pointer = 0;//inicializacion del puntero
  appRefresh.state = APP_STATE_DISABLE;//inicializacion del estado
}
//maquina de estados
void APP_REFRESH_Task(){
  switch (appRefresh.state){
  case APP_STATE_INIT://estado de inicio, por protocolo
    appRefresh.state = APP_STATE_ANIMATION;//estado de animacion
    appRefresh.timerCount = appConfig._5_MS_;//la animacion debe empezar YA
    break;
  case APP_STATE_ANIMATION://estado de espera
    if (appRefresh.timerCount >= appConfig._5_MS_){//han pasado los 5 ms
      appRefresh.timerCount = 0;//reiniciamos el timer
      if (appModel.digit[appRefresh.pointer].refresh == 1){//solo si es necesario refrescar
        APP_PIC_Refresh(appModel.digit[appRefresh.pointer].value,appRefresh.pointer);//refresco depende del pic
      }
	  else{//apagar
        APP_PIC_TurnOff(appRefresh.pointer);//refresco depende del pic
      }
      if (appRefresh.pointer == 2){//solo temenos 3 digitos
        appRefresh.pointer = 0;//reiniciamos el apuntador
      }
      else{
        appRefresh.pointer = appRefresh.pointer + 1;//incrementamos el apuntador
      }
    }
    break;
  case APP_STATE_DISABLE://STATE_DISABLE
    //NO HACER NADA
    break;
  default://
    //NO HACER NADA
    break;
  }
}
		     
