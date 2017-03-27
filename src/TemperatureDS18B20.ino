// See: http://diotlabs.daraghbyrne.me/3-working-with-sensors/DS18B20/
//      https://docs.particle.io/reference/firmware/photon/

#include "OneWire.h"
#include "spark-dallas-temperature.h"
#include "SparkFunMAX17043.h"

OneWire oneWire(D7 );
DallasTemperature dallas(&oneWire);
double temperature = 0.0;
double temperatureF = 0.0;

double voltage = 0;
double soc = 0;
int alert;

void setup()
{
  Particle.variable("temperature", &temperature, DOUBLE);
  Particle.variable("temperatureF", &temperatureF, DOUBLE);
  dallas.begin();
  dallas.setResolution(12);
  Particle.variable("voltage", &voltage, DOUBLE);
  Particle.variable("soc", &soc, DOUBLE);
  Particle.variable("alert", &alert, INT);
  lipo.begin();
  lipo.quickStart();
  lipo.setThreshold(20);
  Serial.begin(9600);
}

void loop()
{
  dallas.requestTemperatures();
  float tempC = dallas.getTempCByIndex(0);
  temperature = (double)tempC;
  float tempF = DallasTemperature::toFahrenheit( tempC );
  if (tempF < 20) {
    delay(10000);
    return;
  }
  temperatureF = (double)tempF;
  voltage = lipo.getVoltage();
  soc = lipo.getSOC();
  alert = lipo.getAlert();
  String data = \
    String::format("{ \"timestamp\": %d, \"temperature\": %f, \"voltage\": %f, \"soc\": %f, \"power_alert\": %d }",
                   Time.now(), temperatureF, voltage, soc, alert);
  Particle.publish("temperature", data, PRIVATE);
  delay(60000);
}
