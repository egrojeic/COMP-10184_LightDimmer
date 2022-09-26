/*
I, Jorge Isaza, student number 000811486, certify that all code submitted is my own work; 
that I have not copied it from any other source. 
I also certify that I have not allowed my work to be copied by others.

git@github.com:egrojeic/COMP-10184_LightDimmer.git

*/

#include <Arduino.h> 

// Variable to keep the state (ON/OFF)
bool turnedOn = false;

// Variable to keep track of what was the last digital input
int lastInput = 1;

void setup() { 
  // configure the USB serial monitor 
  Serial.begin(115200); 
 
  // configure pin D5 as digital input - this is the pushbutton 
  pinMode(D5, INPUT_PULLUP); 
 
  // configure pin D4 as a digital output - this is the LED 
  pinMode(D4, OUTPUT); 
 
} 

void loop() { 
  
  int iVal; 
  int iButton; 

  // Read the analog input comming from the variable resistance
  iVal = analogRead(A0); 

  // Gets when the user press the button
  iButton = digitalRead(D5);

  
  // Given that the signal from the button will be 1 when the button state is released, and 0 when it is prest
  // When iButton == 0 is because the button was prest. But also, we need to do the transition only
  // when the button turns to 0 from 1. That is why I need to keep the last state of the button.  
  if(iButton == 0 && lastInput==1){
      turnedOn = !turnedOn; 
      Serial.println("Digital IN: " + String(iButton) + " - Light State: " + String(turnedOn));
    
  
  }
  
  lastInput =iButton;

  Serial.println("Analog Input: " + String(iVal));

  if (turnedOn){
    analogWrite(D4, iVal); 
  }
  else{
    // The Led will be ON when Input D4 is HIGH, and OFF When LOW. So, to turn it off, the duty cycle needs 
    // to be set on 100%
    analogWrite(D4, 1023); 
  }
  

} 
