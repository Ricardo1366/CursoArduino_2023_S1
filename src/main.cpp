#include <Arduino.h>
#define EJEMPLO4

#define PINPULSADOR DD4
#define PINLED DD2

void cambiaEstado();

bool pulsado;
bool activo;
bool encendido;

void setup()
{
  // Configuración hardaware.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  pinMode(PINPULSADOR, INPUT);
  pinMode(PINLED, OUTPUT);
}

void loop()
{
#if defined(EJEMPLO1)
  // Tiempo encendido = Tiempo apagado
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  Serial.println(F("Cambiando estado led"));
  delay(250);
#endif

#if defined(EJEMPLO2)
  // Tiempo encendido != Tiempo apagado
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println(F("Led encendido"));
  delay(250);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println(F("Led apagado"));
  delay(750);
#endif

#if defined(EJEMPLO3)
  pulsado = digitalRead(PINPULSADOR);
  if (pulsado)
  {
    digitalWrite(PINLED, HIGH);
  }
  else
  {
    digitalWrite(PINLED, LOW);
  }
#endif

#if defined(EJEMPLO4)
  // Leemos el estado del pulsador.
  pulsado = digitalRead(PINPULSADOR);

  // El pulsador está en reposo comprobamos si lo han pulsado.
  if (!activo)
  {
    if (pulsado)
    {
      activo = true;
      cambiaEstado();
    }
  }

  // El pulsador está pulsado. Comprobamos si lo han soltado.
  if (activo)
  {
    if (!pulsado)
    {
      activo = false;
    }
  }

#endif
}

void cambiaEstado()
{
  encendido != encendido;
  digitalWrite(PINLED, encendido);
}
