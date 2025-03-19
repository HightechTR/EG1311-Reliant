#include <Servo.h>

Servo servo;
int TRIG_PIN = 13;
int ECHO_PIN = 12;
int MOTOR_PINLP = 3;
int MOTOR_PINRBP = 4;
int MOTOR_PINLN = 5;
int MOTOR_PINRBN = 6;
int SERVO_PIN = 2;
float SPEED_OF_SOUND = 0.0345;

void setup() {
  pinMode(MOTOR_PINLP, OUTPUT);
  pinMode(MOTOR_PINLN, OUTPUT);
  pinMode(MOTOR_PINRBP, OUTPUT);
  pinMode(MOTOR_PINRBN, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  digitalWrite(TRIG_PIN, LOW);
  pinMode(ECHO_PIN, INPUT);
  servo.attach(SERVO_PIN, 500, 2000);
  Serial.begin(9600);
}

void loop() {
  servo.write(0);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  int microsecs = pulseIn(ECHO_PIN, HIGH);
  float cms = microsecs*SPEED_OF_SOUND/2;
  Serial.println(cms);
  if (cms < 11) {
    digitalWrite(MOTOR_PINLP, LOW);
    digitalWrite(MOTOR_PINRBP, LOW);
    delay(2000);
    if (cms < 11) {
      servo.write(70);
      delay(500);
      servo.write(0);
      delay(2000);

    }
  } else {
    analogWrite(MOTOR_PINLP, 238);
    analogWrite(MOTOR_PINLN, 0);
    digitalWrite(MOTOR_PINRBP, HIGH);
    digitalWrite(MOTOR_PINRBN, LOW);
  }
  delay(10);
}
