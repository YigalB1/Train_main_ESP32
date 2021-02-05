#include<headers.h>
#include <Arduino.h>

void wait(int _num_of_ms) {
    // replacing delay()
    unsigned long time_now = millis();
    while(millis() < time_now + _num_of_ms) {
    } // of while()
  } // of wait



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
    wait(15);
  } // of GO()

  void demo() {
    Serial.print("in DEMO   ");
    Serial.print("toggle directions   ");
    bool cycle = false;
    Serial.print("Going Forward");
    set_forward();
    for (int i =1;i<256;i+=10) {        
        go(i);
        wait(1000);
    } // end of for loop

    Serial.print("Going Backward");
    set_backward();
    for (int i =1;i<256;i+=10) {          
        go(i);
        wait(1000);
    } // end of for loop

    stop();

  } // end of demo()


  void test_motor_pins() {
        // one time signals change
        // call within endless loop - to catch on scope
        digitalWrite(MOTOR_DIR_1_PIN,LOW);
        wait(50);
        digitalWrite(MOTOR_DIR_2_PIN,HIGH);
        wait(50);
        digitalWrite(MOTOR_DIR_1_PIN,HIGH);
        wait(50);
        digitalWrite(MOTOR_DIR_2_PIN,LOW);
        wait(50);
        Serial.print(" .");
    }


    void test_pwm_pin() {
        for (int i =1;i<256;i+=10) {        
          go(i);
          wait(500);
      } // end of for loop
    }

}; // end of Train class



