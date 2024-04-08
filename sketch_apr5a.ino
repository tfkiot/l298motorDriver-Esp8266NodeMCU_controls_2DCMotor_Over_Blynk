// #define BLYNK_TEMPLATE_ID "TMPL3THMhadhs"
// #define BLYNK_TEMPLATE_NAME "MotorDriver"
// #define BLYNK_AUTH_TOKEN "-0qm3TeJvd9ihqnAc1tPsGPicKAuMiwk"

#define BLYNK_PRINT Serial

#include <BlynkSimpleEsp8266.h>
#include <ESP8266WiFi.h>

char ssid[] = "YourSSID";          // Your WiFi SSID
char pass[] = "PassworD";        // Your WiFi password

#define ENA D7  // PWM pin for motor A
#define ENB D8  // PWM pin for motor B
#define IN1 D1  // Motor A control pin 1
#define IN2 D2  // Motor A control pin 2
#define IN3 D5  // Motor B control pin 1
#define IN4 D6  // Motor B control pin 2

int speed1;
int speed2;
int direction1;
int direction2;

void setup() {
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  //timer.setInterval(1000L, sendSensor);
}

void loop() {
  Blynk.run();
}


BLYNK_WRITE(V0) {
  speed1 = param.asInt();
}

BLYNK_WRITE(V1) {
  speed2 = param.asInt();
}

BLYNK_WRITE(V2) {

  direction1 = param.asInt();

  if (direction1 == 0)  // Motor 1 Forward
  {
    analogWrite(ENA, speed1);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  } else if (direction1 == 1)  // Motor 1 Reverse
  {
    analogWrite(ENA, speed1);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
  }
}

BLYNK_WRITE(V3) {

  direction2 = param.asInt();

  if (direction2 == 0)  // Motor 2 Forward
  {
    analogWrite(ENB, speed2);
    // analogWrite(ENB, speed1);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } else if (direction2 == 1)  // Motor 2 Reverse
  {
    analogWrite(ENB, speed2);
    //analogWrite(ENB, speed1);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }
}