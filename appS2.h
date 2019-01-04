#ifndef APP_S2
#def APP_S2
enum APP_S2_STATE{//estados
  APP_S2_STATE_INIT = 1,//estado de inicio
  APP_S2_STATE_HIGH = 2,//estado no pulsador
  APP_S2_STATE_DEBOUNCE = 3,//estado de espera
  APP_S2_STATE_LOW = 4,//estado pulsador
  APP_S2_STATE_DISABLE = 5//estado desactivado
};

struct APP_S2_MODEL{
  char timerCount;//contador de 20ms
  enum APP_S2_STATE state; //estados
};

//modelo de datos (acceso global)
struct APP_S2_MODEL appS2;

//funcion de inicializacion del modelo
void APP_S2_Initialize();

//máquina de estados
void APP_S2_Task();
#endif
