#ifndef APP_REFRESH
#def APP_REFRESH
enum APP_REFRESH_STATE{//estados
  APP_REFRESH_STATE_INIT = 1,//estado de inicio
  APP_REFRESH_STATE_WAIT = 2,//estado de espera
  APP_REFRESH_STATE_REFRESH = 3//estado de refresco
};

struct APP_REFRESH_MODEL{
  char timerCount;//contador de 5ms
  char pointer;//apuntador del display a refrescar
  enum APP_REFRESH_STATE state; //estados
};

//modelo de datos (acceso global)
struct APP_REFRESH_MODEL appRefresh;

//funcion de inicializacion del modelo
void APP_REFRESH_Initialize();

//máquina de estados
void APP_REFRESH_Task();
#endif
