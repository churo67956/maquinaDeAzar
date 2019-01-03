#ifndef APP_BLINK
#def APP_BLINK
typedef enum {//estados
  APP_S2_STATE_INIT = 0,//estado de inicio
  APP_S2_STATE_WAIT = 1,//estado de espera
  APP_S2_STATE_BLINK = 2,//estado de parpadeo
  APP_S2_STATE_DISABLE = 3//estado desactivado
}APP_BLINK_STATE;

typedef struct APP_BLINK_MODEL{
  char timerCount;//contador de 20ms
  char animation;//animacion es el doble del tipo de premio
  char pointer;//hasta el valor de la animacion
  APP_BLINK_STATE state; //estados
}APP_S2_MODEL;

//modelo de datos (acceso global)
APP_BLINK_MODEL appBlink;

//funcion de inicializacion del modelo
void APP_BLINK_Initialize();

//máquina de estados
void APP_BLINK_Task();
#endif
