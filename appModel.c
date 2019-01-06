#include "appModel.h"
//funcion de inicializacion del modelo
void APP_MODEL_Initialize(){
  appModel.digit[0].refresh = 1;//refrescar el primer digito
  appModel.digit[1].refresh = 1;//refrescar el segundo digito
  appModel.digit[2].refresh = 1;//refrescar el tercer digito
  appModel.digit[0].value = 0;//el primer digito a cero
  appModel.digit[1].value = 0;//el segundo digito a cero
  appModel.digit[2].value = 0;//el tercer digito a cero
}
