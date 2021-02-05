#include <classes.h>

Train my_train;

void setup() {
  Serial.begin(9600);
  Serial.print("");
  Serial.print("Starting Setup      ");

  pinMode(ON_BOARD_LED,OUTPUT);
  pinMode(MOTOR_DIR_1_PIN,OUTPUT);
  pinMode(MOTOR_DIR_2_PIN,OUTPUT);


  digitalWrite(ON_BOARD_LED,LOW); // set led ON

  // setting PWM
  // configure LED PWM functionalitites
  ledcSetup(PWM_Channel, PWM_freq, PWM_resolution);
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(MOTOR_PWM_PIN, PWM_Channel);

  my_train.init();

}

bool cycle = false;

void loop() {

 
  my_train.demo();

  if (!cycle) {
    digitalWrite(ON_BOARD_LED,HIGH);
    cycle = true;
  }
  else {
    digitalWrite(ON_BOARD_LED,LOW);
    cycle = false;
  }
  // my_train.wait(1000);
} // of LOOP()