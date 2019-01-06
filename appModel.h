//Autor : Erik Churo y Edison Aushay
//FICHERO CON EL MODELO DE DATOS PRINCIPAL
//SON LOS 3 DIGITOS DE LA MAQUINA DE AZAR
#ifndef _APP_MODEL_
#define _APP_MODEL_
//modelo de datos principal
struct APP_MODEL{
  char value;//numero natural entre 0 y 7
  char refresh;//necesidad de refrescar
};
//son necesarios 3 digitos 
struct APP_MODELS{
  struct APP_MODEL digit[3];//3 digitos
};

//instancia del modelo de datos
struct APP_MODELS appModel;
//funcion de inicializacion del modelo
void APP_MODEL_Initialize();
#endif
