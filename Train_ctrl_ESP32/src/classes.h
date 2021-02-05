#include<headers.h>
#include <Arduino.h>

class Train {
  public:
  int speed = 0; // in work, to use as the speed of the train instead of global variable
  //int direction = LEFT;
  int distance = 0;
  int left_distance  = 777;
  int right_distance = 777;
  int bad_reads_cnt = 0;
  int bad_reads_in_a_row = 0;
  int good_reads_cnt = 0;
  //int dist_buffer[DIST_BUFF_SIZE];

  void init() {
    stop();
  } // of init()

  
  void stop() {
    digitalWrite(MOTOR_DIR_1_PIN,LOW);
    digitalWrite(MOTOR_DIR_2_PIN,LOW);
    } // of set_stop()

  void set_forward() {
    digitalWrite(MOTOR_DIR_1_PIN,HIGH);
    digitalWrite(MOTOR_DIR_2_PIN,LOW);
  }; // of set_forward()
  
  void set_backward() {
    digitalWrite(MOTOR_DIR_1_PIN,LOW);
    digitalWrite(MOTOR_DIR_2_PIN,HIGH);
  }; // of set_backward

  void go(int _speed) {
    ledcWrite(PWM_Channel, _speed);
    delay(15);
  } // of GO()

  void demo() {
      Serial.print("Going Forward");
      for (int i =1;i<256;i+=10) {
          set_forward();
          go(i);
          delay(500);
      } // end of for loop

  } // end of demo()

}; // end of Train class
