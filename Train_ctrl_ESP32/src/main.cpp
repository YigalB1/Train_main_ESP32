
#include <classes.h>

Train my_train;

void setup() {
  Serial.begin(9600);
  Serial.print("");
  Serial.print("Starting Setup      ");

  // setting PWM
  // configure LED PWM functionalitites
  ledcSetup(PWM_Channel, PWM_freq, PWM_resolution);
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(MOTOR_PWM_PIN, PWM_Channel);

  my_train.init();

}

void loop() {
  // put your main code here, to run repeatedly:
}