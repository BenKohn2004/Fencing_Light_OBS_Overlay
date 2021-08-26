// NodeMCU 1.0 ESP-12E
// Receives Low Signal from Scoring Machine and Transfers data as JSON
// to a NodeMCU ESP8266 acting as a Server.

#include <ESP8266WiFi.h>

// NodeMCU has internal Pull-Up resistors
#define btn0 2  //D4
#define btn1 5  //D1
#define btn2 4  //D2
#define btn3 0  //D3


const char *ssid = "FencingBox1";
const char *password = "ilovetofence";


int sensorValue0 = 0;       //sensor value, I'm usingg 0/1 button state
int sensorValue1 = 0;
int sensorValue2 = 0;
int sensorValue3 = 0;

void setup() {
  Serial.begin(115200);
  delay(10);

  pinMode(btn0, INPUT_PULLUP);
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  pinMode(btn3, INPUT_PULLUP);


  // set the ESP8266 to be a WiFi-client
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.printf(".");
  }

  Serial.printf("Connected to Wifi.");

}

void loop() {

  // Detects Touches on Signal Low
  if (digitalRead(btn0) == LOW) sensorValue0 = 1;
  if (digitalRead(btn1) == LOW) sensorValue1 = 1;
  if (digitalRead(btn2) == LOW) sensorValue2 = 1;
  if (digitalRead(btn3) == LOW) sensorValue3 = 1;

  if (digitalRead(btn0) == HIGH) sensorValue0 = 0;
  if (digitalRead(btn1) == HIGH) sensorValue1 = 0;
  if (digitalRead(btn2) == HIGH) sensorValue2 = 0;
  if (digitalRead(btn3) == HIGH) sensorValue3 = 0;


  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const char * host = "192.168.4.1";            //default IP address
  const int httpPort = 80;

  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }

  // Format is Green/Red/White Green/White Red
  String url = "/data/";
  url += "?sensor_reading=";
  url += "{" + String(sensorValue0) + String(sensorValue1) + String(sensorValue2) + String(sensorValue3) + "}";

  // The JSON Request Sent to the Server
  Serial.println("Sending...");
  Serial.println(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" +
                 "Connection: close\r\n\r\n");

  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");
  unsigned long timeout = millis();

  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }
}
