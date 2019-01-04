#include "appModel.h"

void APP_MODEL_Initialize(){
  appModel.digit[0].refresh = 1;
  appModel.digit[1].refresh = 1;
  appModel.digit[2].refresh = 1;
  appModel.digit[0].value = 0;
  appModel.digit[1].value = 0;
  appModel.digit[2].value = 0;
}
