#ifndef APP_RM
#define APP_RM
typedef enum {//estados
  APP_RM_STATE_INIT = 0,//estado de inicio
  APP_RM_STATE_WAIT = 1,//estado no pulsador
  APP_RM_STATE_UPDATE = 2,//estado de espera
  APP_RM_STATE_FIX_DISPLAY_1 = 3,//estado 
  APP_S2_STATE_FIX_DISPLAY_2 = 4,//estado desactivado
  APP_RM_STATE_FIX_DISPLAY_3 = 5,//estado
  APP_RM_STATE_DISABLE = 6//estado inactivo
}APP_RM_STATE;

typedef struct APP_RM_MODEL{
  char timerCount;//contador de 50ms
  char updateTImerCounter;//contador de 1seg
  char pointer;//siguiente digito a pasar
  APP_RM_STATE state; //estados
}APP_RM_MODEL;

//modelo de datos (acceso global)
APP_RM_MODEL appRM;

//funcion de inicializacion del modelo
void APP_RM_Initialize();

//máquina de estados
void APP_RM_Task();
#endif
