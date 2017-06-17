
void backward(int pause = 0){
    Serial.println("backward");
    digitalWrite (IN1,  HIGH);
    digitalWrite (IN2, LOW);
    digitalWrite (IN3,LOW);
    digitalWrite (IN4,  HIGH);
    analogWrite(EN1, 250);
    analogWrite(EN2, 250);
    delay(pause);
}


void stopp(){
    Serial.println("stop");
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    analogWrite(EN1, 0);
    analogWrite(EN2, 0);
}

void forward(int cm){
    float acd, analog;
    Serial.println("forward");
    digitalWrite (IN1, LOW);
    digitalWrite (IN2, HIGH);
    digitalWrite (IN3, HIGH);
    digitalWrite (IN4, LOW);
    if (cm < 150 && cm > 10) {
        acd = 150 - cm; 
        analog = 255 - (255 * (acd / 150));
        acd = (int) analog;
        if (acd < 130) acd = 130;
        Serial.println(acd);
        analogWrite(EN1,acd);
        analogWrite(EN2,acd);
    } else {
        analogWrite(EN1,200);
        analogWrite(EN2,200);  
    }
}


void left(){
    Serial.println("left");
    /* встановлюємо напрям обертання двигунів*/
    digitalWrite (IN1,  HIGH);
    digitalWrite (IN2, LOW);
    digitalWrite (IN3, HIGH);
    digitalWrite (IN4, LOW);
    /* встановлюємо швидкість */
    analogWrite(EN1, 250);
    analogWrite(EN2, 250);
}



void right(){
    Serial.println("right");
    digitalWrite (IN1, LOW);
    digitalWrite (IN2, HIGH);
    digitalWrite (IN3,LOW);
    digitalWrite (IN4,  HIGH);
    analogWrite(EN1, 250);
    analogWrite(EN2, 250);
}



int getDistance() {
    int cm = sensor.distance();
    return cm;
}


void detectWall() {
    
    detectWallVar = true;
    if (firstLoop) {
        backward(300);
        stopp(); 
               
        for (pos = 0; pos < 180; pos += 1){  //goes from 0 degrees to 180 degrees 
            myservo.write(pos);             //tell servo to go to position in variable 'pos' 
            delay(7);                      //waits 10ms for the servo to reach the position 
        } 
                    
        checkLeft = getDistance();  //Take distance from the left side
        delay(40);      
        for (pos = 180; pos>=0; pos-=1){     //goes from 180 degrees to 0 degrees                           
            myservo.write(pos);             //tell servo to go to position in variable 'pos' 
            delay(7);                      //waits 10ms for the servo to reach the position   
        }
                    
        checkRight=getDistance();
        delay(40);    
        
        Serial.print(checkLeft); Serial.print("\t");Serial.print(checkRight); Serial.print("\t");

        myservo.write(position);  // Sensor "look" forward again
        
        if (checkLeft <=20 && checkRight <=20) {
            backward(); //The road is closed... go back and then left ;)
        } else {
            //Finally, take the right decision, turn left or right?
            if (checkLeft < checkRight){
                right();
                delay(450);
                stopp();            
            }
            else if (checkLeft > checkRight){
                left();
                delay(450);
                stopp();  
            }
        }
    }
    firstLoop = true;  
}


void autoControl(int cm) {
    distance = cm; 
    if (myservo.read() > 115) {
        for (pos = 120; pos >= 60; pos -= 1){  
            myservo.write(pos);             
            delay(4);                     
            switch(pos){
                case 60: 
                    matrix[0][0] = getDistance();
                    if (matrix[0][0]  < 30) {detectWall(); break;}
                    break;
                case 90: 
                    matrix[0][1] = getDistance();
                    if (matrix[0][1]  < 30) {detectWall(); break;}
                    break;
                case 120: 
                    matrix[0][2] = getDistance();
                    if (matrix[0][2]  < 30) {detectWall(); break;}
                    break;
               }       
        } 
      } else {
             for (pos = 60; pos <=120; pos += 1){ 
                myservo.write(pos);            
                delay(4); 
                switch(pos){
                    case 60: 
                      matrix[0][0] = getDistance();
                      if (matrix[0][0]  < 30) {detectWall(); break;}
                      break;
                    case 90: 
                      matrix[0][1] = getDistance();
                      if (matrix[0][1]  < 30) {detectWall(); break;}
                      break;
                    break;
                    case 120: 
                       matrix[0][2] = getDistance();
                       if (matrix[0][2]  < 30) {detectWall(); break;}
                       break;
                    break;   
        } 
      }
      if (!detectWallVar) {
          forward(matrix[0][1]);  
     }
}


void manualControl(int cm) {
        
    Serial.println(cm);
    //  DEBUG //        
    Serial.print("b1 - "); Serial.print(buttonD2); Serial.print("\t");
    Serial.print("b2 - "); Serial.print(buttonD3);Serial.print("\t");
    Serial.print("b5 - "); Serial.print(buttonD5);Serial.print("\t");
    Serial.print("b6 - "); Serial.print(buttonD6);Serial.print("\t");
    Serial.print("cm "); Serial.print(cm);Serial.print("\t");
    Serial.print("was-stop  -  "); Serial.print(wasStop);Serial.print("\t"); 
    Serial.print("\n");
    // DEBUG _______//
                  
    if (cm < 30) {
        if (!wasStop) { 
            Serial.print("STOP ");
            digitalWrite (IN1, HIGH);
            digitalWrite (IN2, LOW);        
            digitalWrite (IN3, LOW);
            digitalWrite (IN4,  HIGH);  
            analogWrite(EN2,200);
            analogWrite(EN1,200);
            for (int i = 255; i > 100; i--) {
                analogWrite(EN1,i);
                analogWrite(EN2,i);
                delay(5);
            }
            analogWrite(EN1,0);
            analogWrite(EN2,0);
            wasStop = true;
            return;
         } 
    }
    if (cm >25) {
        wasStop = false;
    }
                         
     // right forward
     if (buttonD2 == 0) {
          digitalWrite (IN3, HIGH);
          digitalWrite (IN4, LOW);
          if (cm < 100 && cm > 10) {
              acd = 100 - cm; 
              analog = 255 - (255 * (acd / 100));
              acd = (int) analog;
              analogWrite(EN2,acd);// 2
          } else {
              analogWrite(EN2,250);// 2   
          }
     }  
       
     // right back
     if (buttonD3 == 0) {
         digitalWrite (IN3,LOW);
         digitalWrite (IN4,  HIGH);
         analogWrite(EN2,250); // 1
     }
                    
     // left forward
     if (buttonD6 == 0) {
          digitalWrite (IN1,   LOW);//
          digitalWrite (IN2, HIGH);
          if (cm < 100 && cm > 10) {
               acd = 100 - cm; 
               analog = 255 - (255 * (acd / 100));
               acd = (int) analog;
               analogWrite(EN1,acd);
          } else {
               analogWrite(EN1,250);
          }
       }
                            
       // left back
       if (buttonD5 == 0) {
            digitalWrite (IN1,  HIGH);
            digitalWrite (IN2, LOW);
            analogWrite(EN1,250);
       }
                    
       // стоп
       if (buttonD3 == 1 && buttonD5 == 1 && buttonD2 == 1 && buttonD6 == 1) {
            analogWrite(EN1,0);
            analogWrite(EN2,0);
       }    
}


/* OLD
long microsecondsToCentimeters(long microseconds)
{
  //скорость звука 340 м/с или 29,412 микросекунд/см, а поскольку звук летит до помехи и обратно, делим результат на двое
  return microseconds / 29.412 / 2;
}/*
int getDistance() {
       long duration, cm,tmp1;//объявляем переменные
      digitalWrite(pingPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(pingPin, LOW);
      //делаем паузу чтобы датчик успел среагировать
      delayMicroseconds(500);
      //засекаем время в микросекундах
      tmp1=micros();
     //ждем пока сигнал на выходе echo не станет низкий
      while(digitalRead(inPin)==HIGH){
        //если долго нет ответа от датчика, значит препятствий в зоне видимости нет, выходим по таймауту
        if(micros()-tmp1 > 15000)
          break;
      }
      //вычисляем время "полета" ультразвукового сигнала
      duration=micros()-tmp1;
      Serial.println("duration - "); Serial.print(duration); Serial.print("\n"); 
      cm = microsecondsToCentimeters(duration);//переводим время в сантиметры
      if (cm == 0) cm = 255;
      return cm;
 }
*/



