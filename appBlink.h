#ifndef APP_BLINK
#def APP_BLINK
enum APP_BLINK_STATE{//estados
  APP_BLINK_STATE_INIT = 1,//estado de inicio
  APP_BLINK_STATE_WAIT = 2,//estado de espera
  APP_BLINK_STATE_ANIMATION = 3,//estado de animacion
  APP_BLINK_STATA_STOP =4,//esta de fin de animacion
  APP_BLINK_STATE_DISABLE = 5//estado desactivado
};

struct APP_BLINK_MODEL{
  char timerCount;//contador de 20ms
  char animation;//animacion es el doble del tipo de premio
  char pointer;//hasta el valor de la animacion
  enum APP_BLINK_STATE state; //estados
};

//modelo de datos (acceso global)
struct APP_BLINK_MODEL appBlink;

//funcion de inicializacion del modelo
void APP_BLINK_Initialize();
//máquina de estados
void APP_BLINK_Task();
#endif
