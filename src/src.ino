#include "extra.h"

/* This is a very short "toy" example of a design exercise. Your submissions will undoubtedly be longer.
I split my work across a second file ("extra.h") located next to src.ino in this folder and included it above.
I added comments as needed. You should too.  
*/

const int PIN_A = 40;
const int GREEN_LED = 35;

int toggle_time;//used to remember last time LED switched value
int led_state;
const int FLASH_PERIOD = 200;

void setup() {
  Serial.begin(115200); //start serial at 115200 baud
  while(!Serial);//wait for serial to start
  pinMode(PIN_A,INPUT_PULLUP); //set with pullup since that makes default 1 (important in pulldown switch)
  pinMode(GREEN_LED,OUTPUT); //set pin to output; important since we are controlling LED
  led_state = 0;
  toggle_time = millis(); //initialize toggle_time with current value!
}

void loop() {
  int measurement = digitalRead(PIN_A);//get pin measurement
  if (measurement==0){ //check if pushed
    if (millis()-toggle_time> FLASH_PERIOD/2){ //if half of the period has expired note it
      led_state = !led_state; //toggle LED STATE
      digitalWrite(GREEN_LED,led_state); //change LED value
      toggle_time = millis(); //remember new toggle time
      Serial.printf("Changing at %d. Also 3 times %d is %d.\n",toggle_time,toggle_time, triple_number(toggle_time));
    }
  }else{ //it is not pushed (switches are active low!)
    led_state = 0; //turn off LED immediately
    digitalWrite(GREEN_LED,led_state);
  }
}


