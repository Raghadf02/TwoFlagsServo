#include <Servo.h>
int flag = 0;
int pos = 0;
Servo myservo;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(2, INPUT_PULLUP);
  myservo.attach(9);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {

  int sensorVal = digitalRead(2);

  if (sensorVal==0){
    if(flag==0){
      Serial.println(flag);
      for (pos=0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(10);  
      }
      flag=1; 
    }
    else if(flag==1)
    {
      Serial.println(flag);
      for (pos=180; pos >= 0; pos -= 1) { // goes from 0 degrees to 180 degrees
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(10);                           
      }
      for (pos=0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(10);                           
      }
      flag=0;  
    }
    /*
    else if(flag==2)
    {
   
    }
    else if(flag==3)
    {
      
    }
    */
  }
}