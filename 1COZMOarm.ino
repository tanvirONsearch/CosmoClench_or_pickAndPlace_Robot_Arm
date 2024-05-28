#define armServoSigl 8
#define armServoSigr 9
#define gripServoSigr 10
#define gripServoSigl 11

#include<Servo.h>
Servo arml;
Servo armr;
Servo gripr;
Servo gripl;


int i=90;
int j=0;
int Yarm=A1;
int Xgrip=A0;

void setup() {
  
  pinMode(Xgrip,INPUT);
  pinMode(Yarm,INPUT);
  pinMode(gripServoSigr,OUTPUT);
  pinMode(gripServoSigl,OUTPUT);
  pinMode(armServoSigl,OUTPUT);
  pinMode(armServoSigr,OUTPUT);
 
  arml.attach(armServoSigl);
  armr.attach(armServoSigr);
  
  gripr.attach(gripServoSigr);
  gripl.attach(gripServoSigl);
  
  gripr.write(0);
  gripl.write(0);
  arml.write(80);
  armr.write(80);
  delay(1000);
  
  Serial.begin(115200);
  

}

void loop() {
   Serial.println(analogRead(Xgrip));

 
 if(analogRead(Xgrip)>700){
    j=j+6;
    gripr.write(j);
    gripl.write(140-j);
    
    if(j>140)j=140; 
    
  }
  if(analogRead(Xgrip)<300){
    j=j-6;
    gripr.write(j);
    gripl.write(140-j);
    if(j<0)j=0;
     
    }
  
  if(analogRead(Yarm)>700){
    i=i+3;
    arml.write(i);
    armr.write(187-i);
    if(i>173)i=173; 
    
  }
  if(analogRead(Yarm)<300){
    i=i-3;
    arml.write(i);
    armr.write(180-i);
    if(i<0)i=0;
     
    }
    
   
   delay(15);

 }
