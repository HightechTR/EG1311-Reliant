int trig_pin = 12;
int echo_pin = 11;
float speed_of_sound = 0.0345;

void setup() {
  pinMode(trig_pin,OUTPUT);
  pinMode(echo_pin,INPUT);
  digitalWrite(trig_pin,LOW);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig_pin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin,LOW);
  int microsecs = pulseIn(echo_pin,HIGH);
  float cms = microsecs*speed_of_sound/2;
  Serial.println(cms);
}

