// NodeMCU 1.0 ESP-12E
// Acts as a Wifi Server
// Receives a JSON encoding and then outputs a Low or High Voltage.
// LEDs are replaced with the input for a HID, Arduino Pro Micro.

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ArduinoJson.h>

// Green Light
#define led0 16               //D0
// Red Light
#define led1 5                //D1
// Green White Light
#define led2 4                //D2
// Red White Light
#define led3 0                //D3


DynamicJsonBuffer jsonBuffer;

const char *ssid      = "FencingBox1";
const char *password  = "fenceforfun";

int sensorValue0 = 0;
int sensorValue1 = 0;
int sensorValue2 = 0;
int sensorValue3 = 0;
String sensor_values;

ESP8266WebServer server(80);

void handleSentVar() {

  if (server.hasArg("sensor_reading"))
  {
    sensor_values = server.arg("sensor_reading");
    Serial.println(sensor_values);
  }

  Serial.println("The sensor values are:");
  Serial.println(sensor_values);

  // Converting the sensor_values from ascii to unicode
  if (sensor_values.charAt(1) == 48) {
    sensorValue0 = 0;
  } else if (sensor_values.charAt(1) == 49) {
    sensorValue0 = 1;
  } else {
    sensorValue0 = 2;
  }

  if (sensor_values.charAt(2) == 48) {
    sensorValue1 = 0;
  } else if (sensor_values.charAt(2) == 49) {
    sensorValue1 = 1;
  } else {
    sensorValue1 = 2;
  }

  if (sensor_values.charAt(3) == 48) {
    sensorValue2 = 0;
  } else if (sensor_values.charAt(3) == 49) {
    sensorValue2 = 1;
  } else {
    sensorValue2 = 2;
  }

  if (sensor_values.charAt(4) == 48) {
    sensorValue3 = 0;
  } else if (sensor_values.charAt(4) == 49) {
    sensorValue3 = 1;
  } else {
    sensorValue3 = 2;
  }

  Serial.println(sensorValue0);
  Serial.println(sensorValue1);
  Serial.println(sensorValue2);
  Serial.println(sensorValue3);

  // Used to Toggle Output Pins which are input pins for the Micro Pro
  toggle_leds();

  server.send(200, "text/html", "Data received");
}

void setup() {
  Serial.begin(115200);
  Serial.println("\nStarting up...");
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();

  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  toggle_leds();                 //turn off all leds as all the sensor values are zero

  server.on("/data/", HTTP_GET, handleSentVar); // when the server receives a request with /data/ in the string then run the handleSentVar function
  server.begin();
}

void loop() {
  server.handleClient();
}

void toggle_leds()
{
  // Receiving a 0 outputs Low
  if (sensorValue0 == 0)  digitalWrite(led0, LOW);
  if (sensorValue1 == 0)  digitalWrite(led1, LOW);
  if (sensorValue2 == 0)  digitalWrite(led2, LOW);
  if (sensorValue3 == 0)  digitalWrite(led3, LOW);

  // Receiving a 1 outputs High
  if (sensorValue0 == 1)  digitalWrite(led0, HIGH);
  if (sensorValue1 == 1)  digitalWrite(led1, HIGH);
  if (sensorValue2 == 1)  digitalWrite(led2, HIGH);
  if (sensorValue3 == 1)  digitalWrite(led3, HIGH);
}
