#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "xxx";                               //Replace with the name of the network your computer is connected to
const char* password = "xxx";                           //Replace with the password of the network

const String REQUEST_URL = "http://xxx:7999/door/OPEN"; //Replace the 'xxx' with the local IP on your local server
int requestCounter = 0;

const int TRIG_PIN = 5;                                 //Setting the pins on the ESP8266
const int ECHO_PIN = 4;

float distance;
float previousDistance;
float THRESHOLD = 10;                                   //This threshold is measured in centimeters

long duration;

void setup() {
  Serial.begin(9600);                                   //Turns on serial for debugging
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }
  
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  digitalWrite(LED_BUILTIN, LOW);                       //If you dont like the light turning on when its connected, set to HIGH
}

void makeRequest() {                                    //This is the function that actually makes the request to your local server
  HTTPClient http;

  http.begin(REQUEST_URL);
  int httpResponseCode = http.GET();

  http.end();
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);

  previousDistance = distance;                          //When your door has moved it will send a request
  distance = duration / 58.0;
  Serial.print(" Distance is: ");
      Serial.print(distance);
      Serial.print(" Previous Distance is: ");
      Serial.println(previousDistance);

  if (abs(distance - previousDistance) > THRESHOLD) {
    requestCounter++;

    if (requestCounter % 2) {
      Serial.print("Request Counter is at: ");
      Serial.println(requestCounter);
      
      makeRequest();
      delay(10000);                                     //This delay is added so it doesnt get triggered from the door opening
                                                        //and closing. May need to be increased for your usage
    }
  }
  
  delay(200);
}