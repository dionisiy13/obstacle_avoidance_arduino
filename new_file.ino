      #include <Wire.h>
      #include <Servo.h> 
      #include <iarduino_HC_SR04_int.h>
      
      // for distance sensor
      int pingPin = 3; // trig
      int inPin = 2; // echo
         
      // for motors
      int IN1 = 8; 
      int IN2 = 11;
      int IN3 = 12;
      int IN4 = 13;
      int EN1 = 6;
      int EN2 = 5;
      
      // for manual control
      int control1 = 7;
      int control2 = 9;
      int control3 = 10;
      int control4 = 4;
      
      iarduino_HC_SR04_int sensor(pingPin,inPin);   
      
      // some valiebles
      int buttonD2, buttonD3, buttonD5, buttonD6, i;
      int distance, checkRight, checkLeft, function=1;  
      int buttonState=0;            
      int pos = 0;
      int position=97;           
      int flag=1;    
      int matrix[2][2]; 
      
      float acd, analog;
      
      bool wasStop = false;
      bool autoControlVar = true;
      bool detectWallVar = false;
      bool firstLoop = false;
      
      Servo myservo; 
      
      
      #include "functions.h"
      void setup() {
          Serial.begin(9600);
          pinMode(inPin, INPUT);
          pinMode(pingPin, OUTPUT);
          digitalWrite(pingPin, LOW);
          pinMode (EN1, OUTPUT);
          pinMode (IN1, OUTPUT);
          pinMode (IN2, OUTPUT);
          pinMode (EN2, OUTPUT);
          pinMode (IN4, OUTPUT);
          pinMode (IN3, OUTPUT);
        
          myservo.attach(14);     
          myservo.write(position);   

          // pull up buttons  
          pinMode(control1, INPUT);
          digitalWrite(control1, HIGH);  
          pinMode(control2, INPUT);
          digitalWrite(control2, HIGH);  
          pinMode(control3, INPUT);
          digitalWrite(control3, HIGH);  
          pinMode(control4, INPUT);
          digitalWrite(control4, HIGH);  
      
      }
      
      void loop() {
        
         long duration, cm,tmp1;
         double acd, analog; 
         detectWallVar = false;
         cm = getDistance();
         /////////////AUTO///CONTROL////////////
         if (autoControlVar) {
             autoControl(cm);
         }
          ////////////MANUAL//CONTROL///////////
          if (!autoControlVar) manualControl(cm);
             buttonD2 = digitalRead(control1); 
             buttonD3 = digitalRead(control2);
             buttonD5 = digitalRead(control3);
             buttonD6 = digitalRead(control4);
        
            if (buttonD3 == 0 || buttonD5 == 0 || buttonD2 == 0 || buttonD6 == 0) {
                 autoControlVar = false; 
            }

      }
      
    

