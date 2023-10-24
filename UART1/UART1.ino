#include <Servo.h> 
#include <SoftwareSerial.h>

Servo myservo; 
SoftwareSerial my_serial(2, 3); // RX, TX

const int servopin = 9 ;
const int ledpin = 5 ;
int VAL = 0 ;
int position =0 ;
void setup()
{
  my_serial.begin(9600); // SoftwareSerial
  // put your setup code here, to run once:
  myservo.attach(servopin); 
  pinMode ( ledpin ,  INPUT_PULLUP ) ;
}

void loop() 
{
  // put your main code here, to run repeatedly:
  if(my_serial.available() > 0 )
  { 
     position = my_serial.read() ; 
      myservo.write(position);
  }
  VAL = digitalRead(ledpin) ;
  delay(3);
  if ( VAL == LOW  )
    {
      my_serial.write(1) ;
    }
    else 
    {
      my_serial.write((byte) 0x00); 
    }
    delay(100) ;
}
