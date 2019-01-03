#ifndef APP_S2
#def APP_S2
typedef enum {//estados
  APP_S2_STATE_INIT = 0,//estado de inicio
  APP_S2_STATE_HIGH = 1,//estado no pulsador
  APP_S2_STATE_DEBOUNCE = 2,//estado de espera
  APP_S2_STATE_LOW = 3,//estado pulsador
  APP_S2_STATE_DISABLE = 4//estado desactivado
}APP_S2_STATE;

typedef struct APP_S2_MODEL{
  char timerCount;//contador de 20ms
  APP_S2_STATE state; //estados
}APP_S2_MODEL;

//modelo de datos (acceso global)
APP_S2_MODEL appS2;

//funcion de inicializacion del modelo
void APP_S2_Initialize();

//funcion de transicion de alto a bajo
void APP_S2_Transition();

//máquina de estados
void APP_S2_Task();
#endif
