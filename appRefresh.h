#ifndef APP_REFRESH
#def APP_REFRESH
typedef enum {//estados
  APP_REFRESH_STATE_INIT = 0,//estado de inicio
  APP_REFRESH_STATE_WAIT = 1,//estado de espera
  APP_REFRESH_STATE_REFRESH = 2//estado de refresco
}APP_REFRESH_STATE;

typedef struct APP_REFRESH_MODEL{
  char timerCount;//contador de 5ms
  char pointer;//apuntador del display a refrescar
  APP_REFRESH_STATE state; //estados
}APP_REFRESH_MODEL;

//modelo de datos (acceso global)
APP_REFRESH_MODEL appRefresh;

//funcion de inicializacion del modelo
void APP_REFRESH_Initialize();

//máquina de estados
void APP_REFRESH_Task();
#endif
