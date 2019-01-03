#include "appRefresh.h"

//funcion de inicializacion del modelo
void APP_REFRESH_Initialize(){
  appRefresh.timerCount = 0;//inicializacion del contador
  appRefresh.pointer = 0;//inicializacion del puntero
  appRefresh.state = APP_REFRESH_STATE_INIT;//inicializacion del estado
}

//maquina de estados
void APP_REFRESH_Task(){
  switch (appRefresh.state){
  case APP_REFRESH_STATE_INIT://estado de inicio, por protocolo
    appRefresh.state = APP_REFRESH_STATE_WAIT;
    break;
  case APP_REFRESH_STATE_WAIT://estado de espera
    if (appRefresh.timerCount >= 1){//han pasado los 5 ms
      appRefresh.timerCount = 0;//reiniciamos el timer
      appRefresh.state = APP_REFRESH_STATE_REFRESH;//vamos al estado de refresco
    }
    break;
  case APP_REFRESH_STATE_REFRESH://estado de refresco de lo que apunta apuntador
    if (appModel.digit[appRefresh.pointer].refresh == 1){//solo si es necesario refrescar
      APP_PIC_Refresh(appRefresh.pointer);//refresco depende del pic
    }
    if (appRefresh.pointer == 2){//solo temenos 3 digitos
      appRefresh.pointer = 0;//reiniciamos el apuntador
    }
    else{
      appRefresh.pointer = appRefresh.pointer + 1;//incrementamos el apuntador
    }
    appRefresh.state = APP_REFRESH_STATE_WAIT;//estado de espera
    break;
  default:
    break;
}
		     
