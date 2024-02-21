#include <Arduino.h>
#include <HTTPClient.h>
#include <WiFi.h>

const String ID = "Pistore";
const String PW = "circedeaba";

const String server = "https://vsh.pp.ua/TinyGSM/logo.txt";
const int port = 80;

const int timeDelay = 6000; // 10 minutos por chamada na API
int lastTime = 0;

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
  if (millis() - lastTime > timeDelay)
  {
    if (WiFi.status() == WL_CONNECTED)
    {
      HTTPClient http;
      http.begin(server);

      int response = http.GET();

      if (response > 0)
      {
        Serial.print("Resposta do servidor: ");
        Serial.println(response);

        String payload = http.getString();
        Serial.println("Leitura: ");
        Serial.println(payload);
      } else {
        Serial.print("Erro: ");
        Serial.println(response);
      }
      http.end();
    } else {
      Serial.println("WiFi disconectado!");
    }
    lastTime = millis();
  }
}
