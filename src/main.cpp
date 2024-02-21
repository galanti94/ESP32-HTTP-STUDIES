#include <Arduino.h>
#include <WiFi.h>

const String ID = "Pistore";
const String PW = "circedeaba";

void setup()
{
  Serial.begin(115200);

  Serial.print("Conectando ao WiFi...");
  WiFi.begin(ID, PW);

  if (WiFi.status() != WL_CONNECTED)
  {
    while (WiFi.status() != WL_CONNECTED)
    {
      Serial.print(".");
      delay(100);
    }
    Serial.println("");
    Serial.println("Conectado!!");
    Serial.println("WiFi: " + ID);
    Serial.println("Password: " + PW);
  }
}

void loop()
{
}
