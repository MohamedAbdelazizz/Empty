/***********  LET 2/3 PINS AS RX / TX **********/
#include <SoftwareSerial.h>

SoftwareSerial my_serial(2, 3); // RX, TX
/******** Variables DEF  ***************/
int val =0 ;
int LED_STATE = 0 ;
const int LED_PIN = 12 ;
const int POTPIN =A0 ;

void setup() {
  // put your setup code here, to run once:
  my_serial.begin(9600) ;
  pinMode ( LED_PIN , OUTPUT ) ;
  pinMode (POTPIN , INPUT ) ;

}

void loop()
{
  // put your main code here, to run repeatedly:
  val = analogRead(POTPIN);
  int mappedValue = map(val, 0, 1023, 0, 180) ;
   my_serial.write(mappedValue );
  if(my_serial.available())
  {
     LED_STATE =  my_serial.read() ;
     if(LED_STATE == 1 )
  {
    digitalWrite(LED_PIN , HIGH ) ;
  }
   else if(LED_STATE == 0 )
  {
    digitalWrite(LED_PIN , LOW ) ;
  }
  }
  delay(100);
}
