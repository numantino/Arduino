#include "Server.hpp"

void setup()
{
    Serial.begin(115200);
    delay(10);
    //Inicializacion del componente, dependiendo de la clase incluida con anterioridad
    inicializacion();
}
void loop()
{
  server.handleClient();
}
