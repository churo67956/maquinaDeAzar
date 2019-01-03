#include "appBlink.h"

void APP_BLINK_Initialize(){
  appBlink.timerCount = 0;//contador de 20ms
  appBlink.animation = 0;//animacion es el doble del tipo de premio
  appBlink.pointer = 0;//hasta el valor de la animacion
  appBlink.state = APP_BLINK_STATE_INIT; //estado de partida
 }

//máquina de estados
void APP_BLINK_Task(){
  switch (appBlink.state){
  case APP_BLINK_STATE_INIT:
    break;
  case APP_BLINK_STATE_WAIT:
    break;
  case APP_BLINK_STATE_BLINK:
    break;
  }
}
#endif
