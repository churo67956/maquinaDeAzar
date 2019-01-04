#ifndef APP_ORCHESTRATE
#define APP_ORCHESTRATE
//estados
enum APP_ORCHESTRATE_STATES{
  APP_ORCHESTRATE_STATE_INIT = 1,//estado de partida
  APP_ORCHESTRATE_STATE_WAIT = 2,//estado de espera
  APP_ORCHESTRATE_STATE_PLAY = 3,//estado de sonar
  APP_ORCHESTRATE_STATE_STOP = 4,//estado fin sonar
  APP_ORCHESTRATE_STATE_DISABLE = 5//estado inactivo
};
//modelo de datos
struct APP_ORCHESTRATE_MODEL{
  unsigned char animation;//animacion es el doble del tipo de premio
  unsigned char pointer;//hasta el valor de la animacion
  enum APP_ORCHESTRATE_STATES state;
};
//instancia del modelo de datos 
struct APP_ORCHESTRATE_MODEL appOrchestrate;

//funcion de inicializacion
void APP_ORCHESTRATE_Initialize();
//maquina de estados
void APP_ORCHESTRATE_Task();
 
#endif
