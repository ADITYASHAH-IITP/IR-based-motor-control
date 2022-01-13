#include<IRremote.h>
const int recvpin=6;
int val;
int n;
int m;
int a;
const int motor1 = 9; 
const int motor2 = 10; 
IRrecv irrecv(recvpin);
decode_results results;
void setup()
{
 Serial.begin(9600);
 Serial.println("Enabling IRin:");
 irrecv.enableIRIn();
 Serial.println("Enabled IRin:");
 pinMode(motor1, OUTPUT);
 pinMode(motor2, OUTPUT);
 val=175;
 a=0;
 m=0;
 n=0;

}
void loop()
{

  
 if(irrecv.decode(&results))
 {
  Serial.println(results.value,DEC);
 
    
   // play
 
   if(results.value==16621663 && m==0)
  {
     // n= digitalRead(motor1); 
     
     // analogWrite(motor1, 0);
     m=1;
     a=1;
     
    }
   else if ( results.value==16621663 && m==1)
  {
     // n= digitalRead(motor1); 
     
     // analogWrite(motor1, 0);
     m=0;
     a=0;
     analogWrite(motor1, 0);
     analogWrite(motor2, 0); 
     
    }
   if(results.value==16601263)
  {
     val=val+10;  
  
    }
   if(results.value==16584943)
  {
     val=val-10;  
  
    }
   if(results.value==16589023)
  {
     n=1;  
  
    }
   if(results.value==16605343)
  {
     n=0;  
  
    }
   
   if(a==1 && n==0)
  {
     analogWrite(motor1, val);
     analogWrite(motor2, 0);   
  
    }
   if(a==1 && n==1)
  {
     analogWrite(motor2, val);
     analogWrite(motor1, 0);   
  
    }
   Serial.println(m);
	Serial.println(n);
	Serial.println(a);
   Serial.println(val);
  irrecv.resume();
 }
  
}