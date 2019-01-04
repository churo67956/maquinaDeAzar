#ifndef APP_MODEL
#define APP_MODEL
struct APP_MODEL{
  char value;
  char refresh;
};

struct APP_MODELS{
  struct APP_MODEL digit[3];
};

struct APP_MODELS appModel;

void APP_MODEL_Initialize();
#endif
