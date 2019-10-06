#include <PS3BT.h>
#include <usbhub.h>
#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>


// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif   //41/45..........43/8
#include <SPI.h>


#include <NewPing.h>

#define TRIGGER_PIN1  33  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN1     31// Arduino pin tied to echo pin on the ultrasonic sensor.


#define TRIGGER_PIN2  37  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN2     39 

#define TRIGGER_PIN3  28  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN3     26 

#define TRIGGER_PIN4  47  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN4     49 


#define TRIGGER_PIN5  22  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN5     24 


#define MAX_DISTANCE 200 // Maximum sensor distance is rated at 400-500cm.


USB Usb;
//USBHub Hub1(&Usb); // Some dongles have a hub inside

BTD Btd(&Usb); // You have to create the Bluetooth Dongle instance like so
/* You can create the instance of the class in two ways */
PS3BT PS3(&Btd); // This will just create the instance
//PS3BT PS3(&Btd, 0x00, 0x15, 0x83, 0x3D, 0x0A, 0x57); // This will also store the bluetooth address - this can be obtained from the dongle when running the sketch

LiquidCrystal_PCF8574 lcd(0x27); 


NewPing sonar1(TRIGGER_PIN1, ECHO_PIN1, MAX_DISTANCE);

NewPing sonar2(TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE);

NewPing sonar3(TRIGGER_PIN3, ECHO_PIN3, MAX_DISTANCE);

NewPing sonar4(TRIGGER_PIN4, ECHO_PIN4, MAX_DISTANCE);

NewPing sonar5(TRIGGER_PIN5, ECHO_PIN5, MAX_DISTANCE);



bool printTemperature, printAngle;

int sht=A14;    //shoot
int dirac=43;     //direction of actuator-----41
int anaac=8;      // analog of actuator----45
int dirgrb=41; //direction of grab shagai---43
int anagrb=45;  //analog of grab shagai-----8
int sn1=A8;     //shagai nematic 1
int sn2=A9;    //shagai nmeatic 2

int gerg=A10;//gerg pass A13

int solenoidstop=A15; // free up all solenoids  A15 

//motors pins
int dirm1=25; 
int dirm2=23;
int dirm3=27;
int dirm4=29;
int pwmm1=5;
int pwmm2=4;
int pwmm3=7;
int pwmm4=6;

int en1a=3;      //3
int en1b=2;      // 2

int en2a=18;   //18
int en2b=19;   //19

//int a=2;
//int b=3;
/*
const int trig1 =33 ;    //33
const int echo1 = 31;    //31

const int trig2 = 37;
const int echo2 = 39;


const int trig3 =28 ;    //33
const int echo3 = 26;    //31

const int trig4 = 47;
const int echo4 = 49;

*/


volatile int lastEncoded = 0;
volatile long encoderValue = 0;
 
long lastencoderValue = 0;
 
int lastMSB = 0;
int lastLSB = 0;

volatile int lastEncoded2 = 0;
volatile long encoderValue2 = 0;
 
long lastencoderValue2 = 0;
 
int lastMSB2 = 0;
int lastLSB2 = 0;

volatile int valpre=0;
volatile int valpre2=0;
volatile int valnow=0;
volatile int valnow2=0;
volatile int valprepid=0;
volatile int valpre2pid=0;
volatile int valnowpid=0;
volatile int valnow2pid=0;
volatile int cpid=0;
volatile int cnorm=0;
volatile int c2norm=0;
volatile int c2pid=0;
int x=0; 
int y=0;
int z=0;
int flag=0;
int flag1=0;

int flagsolenoid=0;

int i;
int maxnor=220;
//************************************************************************************************************************************************************************************************
float kpf=0.54;           // 1.5              10.5                               0.9 ////0.63
float kdf=1.41;            //0.083             0.83                           1.11
float kif=0.078;                          //1.2      82                      0.04
float outpwmf=0;


float kplr=0.73;           //                                                    1.5              10.5
float kdlr=1.03;            //                                                   0.083             0.83      
float kilr=0.091;                          //1.2      82
float outpwmlr=0;

float kpult=6.63;           //            3.63                                    1.5              10.5                               0.9 ////0.63
float kdult=2.21;            //0.083             0.83                           1.11
float kiult=1.48;                          //1.2      82                      0.04


float kpultgerg=14.43;           //            3.63                                    1.5              10.5                               0.9 ////0.63
float kdultgerg=4.71;            //0.083             0.83                           1.11
float kiultgerg=6.98;                          //1.2      82                      0.04


float kpultfrwrdgerg=6.83;           //            3.63                                    1.5              10.5                               0.9 ////0.63
float kdultfrwrdgerg=2.71;            //0.083             0.83                           1.11
float kiultfrwrdgerg=3.74;   


float kpultrightgerg=8.93;
float kdultrightgerg=3.41;
float kiultrightgerg=4.48;



//*************************************************************************************************************************************************************************************************************
float outpwmult12=0;
float outpwmult34=0;
float outpwmult5=0;
float outpwmult12gerg=0;
float outpwm12right=0;                         




float pwmf12ult=200;
float pwmf34ult=200;
float maxmult=255;

float paf12ult=0;
float pbf12ult=0;

float paf34ult=0;
float pbf34ult=0;

float errang12=0;
float errang12gerg=0;
float errfrwrdgerg=0;
float errrightgerg=0;

float lasterrang12=0;
float lasterrang12gerg=0;
float lasterrfrwrdgerg=0;
float lasterrrightgerg=0;

float errang34=0;
float lasterrang34=0;

long dur1;
float dis1;

long dur2;
float dis2;

long dur3;
float dis3;

long dur4;
float dis4;

long dur5;
float dis5;

int setvalue=0;
//int outpwmf=0;
//int outpwmlr=0;
int paf=0;
int pbf=0;
int palr=0;
int pblr=0;
int maxm=255;
int pwmlr=180;
int pwmf=180;

int lasterrlr=0;
int lasterrf=0;

int leftX;
int leftY;
int axisX;
int axisY;
int pwmX;
int pwmY;

int startc=-1100;

float setdisgerg=13;
float setdisrightgerge=15;



void setup() {
  // put your setup code here, to run once:
Serial.begin(2000000);
#if !defined(__MIPSEL__)
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); //halt
  }
  Serial.print(F("\r\nPS3 Bluetooth Library Started"));

  Wire.begin();
  Wire.beginTransmission(0x27);
lcd.begin(16, 2);
  
/*
pinMode(trig1, OUTPUT); // Sets the trigPin as an Output
pinMode(echo1, INPUT); // Sets the echoPin as an Input

pinMode(trig2, OUTPUT); // Sets the trigPin as an Output
pinMode(echo2, INPUT); // Sets the echoPin as an Input
*/

  
  pinMode(dirgrb,OUTPUT);
  pinMode(anagrb,OUTPUT);
  pinMode(dirac,OUTPUT);
  pinMode(anaac,OUTPUT);
    pinMode(sht,OUTPUT);
       pinMode(sn1,OUTPUT);
      pinMode(sn2,OUTPUT);
      pinMode(gerg,OUTPUT);


      pinMode(en1a, INPUT); 
  pinMode(en1b, INPUT);
  pinMode(en2a, INPUT); 
  pinMode(en2b, INPUT);

pinMode(dirm1,OUTPUT);
pinMode(dirm2,OUTPUT);
pinMode(dirm3,OUTPUT);
pinMode(dirm4,OUTPUT);


pinMode(pwmm1,OUTPUT);
pinMode(pwmm2,OUTPUT);                                                                                                                              //c=======encoder1 lr            c2===========encoder2    f 
pinMode(pwmm3,OUTPUT);
pinMode(pwmm4,OUTPUT);


analogWrite(pwmm1,0);
analogWrite(pwmm2,0);
analogWrite(pwmm3,0);
analogWrite(pwmm4,0);
analogWrite(anagrb,0);
analogWrite(anaac,0);
digitalWrite(sht,LOW);
digitalWrite(sn1,LOW);
digitalWrite(sn2,LOW);
digitalWrite(solenoidstop,LOW);

//valpre=digitalRead(en1a);
//valpre2=digitalRead(en2a);
         /*  attachInterrupt(digitalPinToInterrupt(en2a),encoder2,CHANGE);
          // attachInterrupt(digitalPinToInterrupt(en2a),encoder2pid,CHANGE);
             attachInterrupt(digitalPinToInterrupt(en1a),encoder1pid,CHANGE);
             //attachInterrupt(digitalPinToInterrupt(en1a),encoder1,CHANGE);

*/

lcd.setBacklight(255);
//delay(1000); 
}

void loop()
{
  // put your main code here, to run repeatedly:
  Usb.Task();

  if (PS3.PS3Connected || PS3.PS3NavigationConnected) {


     leftX=PS3.getAnalogHat(LeftHatX);
      leftY=(PS3.getAnalogHat(LeftHatY));
      axisX=map(leftX,0,255,-127,128);
      axisY=map(leftY,0,255,127,-128);

       pwmX=map(axisX,-127,128,-255,258);
      pwmY=map(axisY,-128,127,-256,255);
     // pwmX=map(axisX,0,-127.0,0,-255.0);
     // pwmY=map(axisY,0,-128.0,0,-255.0);

 if( PS3.getAnalogHat(LeftHatY) ==127&&PS3.getAnalogHat(LeftHatX)==127&&PS3.getAnalogHat(RightHatY)==127&&PS3.getAnalogHat(RightHatX)==127)

    { /* attachInterrupt(digitalPinToInterrupt(en2a),encoder2,CHANGE);
        //   attachInterrupt(digitalPinToInterrupt(en2a),encoder2pid,CHANGE);
          //   attachInterrupt(digitalPinToInterrupt(en1a),encoder1pid,CHANGE);

           attachInterrupt(digitalPinToInterrupt(en2b),encoder2,CHANGE);
             attachInterrupt(digitalPinToInterrupt(en1a),encoder1,CHANGE);

attachInterrupt(digitalPinToInterrupt(en1b),encoder1,CHANGE);

       lcd.clear();
lcd.setCursor(0, 0);

    lcd.print(cnorm);
    lcd.setCursor(0, 1);

    lcd.print(c2norm);*/
     
      stop1();
   //   Serial.println("stop");
      analogWrite(anaac,0);
      
      
      } 
      
 if (PS3.getAnalogButton(L2) ) 
     {
     clockwise();
   //  Serial.println("clockwise");
     
     }  
 if (PS3.getAnalogButton(R2))
     {
     anticlockwise();
     // Serial.println("anticlockwise");
     }
     
 
 if (PS3.getButtonClick(TRIANGLE)) 
      {
        digitalWrite(sht,HIGH);
         Serial.println("shoooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooot");
         delay(500);
         digitalWrite(sht,LOW);
         
      //  Serial.println("shooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooot off");
      }

   /*
 else if (PS3.getButtonClick(CIRCLE))
      {
        digitalWrite(gerg,HIGH);
        Serial.println("gerg pass");
        delay(500);
        digitalWrite(gerg,LOW);
     // Serial.println("gerg passed");
      }
*/

  
      else if (PS3.getButtonClick(R1)) {
         digitalWrite(sn1,LOW);
        digitalWrite(sn2,LOW);
        delay(1000);
        digitalWrite(sn1,HIGH);
        digitalWrite(sn2,LOW);
        // Serial.println(" ready to grab ");
         //delay(200);
     }

else if (PS3.getButtonClick(L1)) { 
        digitalWrite(sn1,LOW);
        digitalWrite(sn2,HIGH);
        
        // Serial.println("SHAGAI RELEASED");
         //delay(200);
     }

else if(PS3.getButtonClick(LEFT))
    {
        digitalWrite(solenoidstop,HIGH);

    }

 if (PS3.getAnalogButton(CIRCLE)>10)
      {
        digitalWrite(gerg,HIGH);
       // Serial.println("gerg pass");
        //delay(500);
       // digitalWrite(gerg,LOW);
     // Serial.println("gerg passed");
      flagsolenoid=1;
      }
  else
  {
        if(flagsolenoid==1)
        {
          digitalWrite(solenoidstop,LOW);
          delay(1000);
        }
        digitalWrite(solenoidstop,HIGH);
        digitalWrite(gerg,LOW);
        flagsolenoid=0;
  }


    


    if (PS3.getAnalogButton(UP))
      {
        digitalWrite(dirac,HIGH);
        analogWrite(anaac,150);
       // Serial.println("accuator up");
      
      }
    else if (PS3.getAnalogButton(DOWN))
      {
        digitalWrite(dirac,LOW);
        analogWrite(anaac,150);
       // Serial.println("accuator DOWN");
      }

    else
    {
          analogWrite(anaac,0);
         // Serial.println("accuator stop");
          
      
     }

     
     if (PS3.getAnalogButton(CROSS))
     {
      digitalWrite(dirgrb,HIGH);
      analogWrite(anagrb,70);
        //Serial.println("clock wiseeeeee grabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb");
        }
      
 else if (PS3.getAnalogButton(SQUARE))
        {
        digitalWrite(dirgrb,LOW);
        analogWrite(anagrb,120);
       // Serial.println("ANTIIIIclock wiseeeeee grabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb");
        
        }
     else
     {
      analogWrite(anagrb,0);
    //  Serial.println("stop shagai motor"); 
      }



    /*   if( pwmY >0&&pwmX==0&&PS3.getAnalogHat(RightHatY)==127&&PS3.getAnalogHat(RightHatX)==127)

      {   forwardjoy();
      //Serial.println("forwardjoy");
      
      
        }
*/

if(PS3.getAnalogHat(LeftHatY) ==0&&PS3.getAnalogHat(LeftHatX)==127&&PS3.getAnalogHat(RightHatY)==127&&PS3.getAnalogHat(RightHatX)==127)

      {    forwardjoy();
      //  Serial.println("backward");
        
        }
      if(PS3.getAnalogHat(LeftHatY) ==255&&PS3.getAnalogHat(LeftHatX)==127&&PS3.getAnalogHat(RightHatY)==127&&PS3.getAnalogHat(RightHatX)==127)

      {    backwardjoy();
      //  Serial.println("backward");
        
        }
        if( PS3.getAnalogHat(LeftHatY) ==127&&PS3.getAnalogHat(LeftHatX)==255&&PS3.getAnalogHat(RightHatY)==127&&PS3.getAnalogHat(RightHatX)==127)

      {        rightjoy();
    //    Serial.println("right");
        
        }
        if( PS3.getAnalogHat(LeftHatY) ==127&&PS3.getAnalogHat(LeftHatX)==0&&PS3.getAnalogHat(RightHatY)==127&&PS3.getAnalogHat(RightHatX)==127)

      {          leftjoy();
    //    Serial.println("left");
        
        }

        if( PS3.getAnalogHat(LeftHatY) ==0&&PS3.getAnalogHat(LeftHatX)==0&&PS3.getAnalogHat(RightHatY)==127&&PS3.getAnalogHat(RightHatX)==127)
{
         northwest();
  //      Serial.println("northwest");
  
  
  }

  if(PS3.getAnalogHat(LeftHatY) ==0&&PS3.getAnalogHat(LeftHatX)==255&&PS3.getAnalogHat(RightHatY)==127&&PS3.getAnalogHat(RightHatX)==127){
      northeast();
   // Serial.println("northeast");
    
    }
     if(PS3.getAnalogHat(LeftHatY) ==255&&PS3.getAnalogHat(LeftHatX)==0&&PS3.getAnalogHat(RightHatX)==127&&PS3.getAnalogHat(RightHatX)==127){
           southwest();
  //  Serial.println("southwest");
    
    } if(PS3.getAnalogHat(LeftHatY) ==255&&PS3.getAnalogHat(LeftHatX)==255&&PS3.getAnalogHat(RightHatY)==127&&PS3.getAnalogHat(RightHatX)==127){
           southeast();
//    Serial.println("southeast");
    
    }





     if(PS3.getAnalogHat(LeftHatY) ==127&&PS3.getAnalogHat(LeftHatX)==127&&PS3.getAnalogHat(RightHatY)==127&&PS3.getAnalogHat(RightHatX)==255)
          {

                                alignbutton();

                  
          }

 if(PS3.getAnalogHat(RightHatY) ==255&&PS3.getAnalogHat(RightHatX)==127&&PS3.getAnalogHat(LeftHatY)==127&&PS3.getAnalogHat(LeftHatX)==127)

      {   
     
                          ultra5frwrdgerge();                 
        }






  //************************************encoder*************************************//

          if(PS3.getAnalogHat(LeftHatY) ==127&&PS3.getAnalogHat(LeftHatX)==127&&PS3.getAnalogHat(RightHatY)==0&&PS3.getAnalogHat(RightHatX)==127)
          {
                          
                            
       lcd.clear();
lcd.setCursor(0, 0);

    lcd.print(cnorm);
    lcd.setCursor(0, 1);

    lcd.print(c2norm);
    

            
       
  if(c2norm>=0 && c2norm<=2800 && flag==0)
             {          
             attachInterrupt(digitalPinToInterrupt(en2a),encoder2,CHANGE);
                        attachInterrupt(digitalPinToInterrupt(en2b),encoder2,CHANGE);
                        attachInterrupt(digitalPinToInterrupt(en1a),encoder1pid,CHANGE);
            attachInterrupt(digitalPinToInterrupt(en1b),encoder1pid,CHANGE);
             
              
                  
                  pidforforwardmoving();
                  ultra12pidfrwrd();
                  if(c2norm>=2700 && c2norm<=2800)
                  {
                    stopped();
                    detachInterrupt(digitalPinToInterrupt(en2a));
                    detachInterrupt(digitalPinToInterrupt(en1a));
                    detachInterrupt(digitalPinToInterrupt(en2b));
                    detachInterrupt(digitalPinToInterrupt(en1b));
                    flag=1;
                    c2pid=startc;
                   
         
                   
                  }
             }
             
  else if(cnorm<=50 && cnorm>=-5400 && flag==1)
             {

                      
           attachInterrupt(digitalPinToInterrupt(en2a),encoder2pid,CHANGE);
             attachInterrupt(digitalPinToInterrupt(en1a),encoder1,CHANGE);

           attachInterrupt(digitalPinToInterrupt(en2b),encoder2pid,CHANGE);
             attachInterrupt(digitalPinToInterrupt(en1b),encoder1,CHANGE);
            
            
                    pidforleftmoving();
                    if(cnorm<=-5200 && cnorm>=-5400)
                    {
                       stopped();
                       detachInterrupt(digitalPinToInterrupt(en2a));
                    detachInterrupt(digitalPinToInterrupt(en1a));
                    detachInterrupt(digitalPinToInterrupt(en2b));
                    detachInterrupt(digitalPinToInterrupt(en1b));
                    flag=2;
               
                  
                    }
             }
             
  else if(c2norm>=2700 && c2norm<=10000 && flag==2)
             {
             attachInterrupt(digitalPinToInterrupt(en2a),encoder2,CHANGE);
             attachInterrupt(digitalPinToInterrupt(en1a),encoder1pid,CHANGE);

               attachInterrupt(digitalPinToInterrupt(en2b),encoder2,CHANGE);
             attachInterrupt(digitalPinToInterrupt(en1b),encoder1pid,CHANGE);

                    pidforforwardmoving(); 
                    ultra34pidfrwrd();
                          
                    if(c2norm>9800 && c2norm<10000)
                    {
                          stopped();
                      detachInterrupt(digitalPinToInterrupt(en2a));
                    detachInterrupt(digitalPinToInterrupt(en1a));
                    detachInterrupt(digitalPinToInterrupt(en2b));
                    detachInterrupt(digitalPinToInterrupt(en1b));
                    c2pid=startc;
                      flag=3;
                    }
             }

 else if(cnorm<=200 && cnorm>=-5500 && flag==3)
             {

           attachInterrupt(digitalPinToInterrupt(en2a),encoder2pid,CHANGE);
             attachInterrupt(digitalPinToInterrupt(en1a),encoder1,CHANGE);

           attachInterrupt(digitalPinToInterrupt(en2b),encoder2pid,CHANGE);
             attachInterrupt(digitalPinToInterrupt(en1b),encoder1,CHANGE);
                    pidforrightmoving();
                    if(cnorm<=200 && cnorm>=50)
                    {
                    
                      stopped();
                       detachInterrupt(digitalPinToInterrupt(en2a));
                    detachInterrupt(digitalPinToInterrupt(en1a));
                    detachInterrupt(digitalPinToInterrupt(en2b));
                    detachInterrupt(digitalPinToInterrupt(en1b));
                   // cpid=-600;
                    flag=4;
                  
                    }
             }
             
  else if(c2norm>=9700 && c2norm<=16100 && flag==4)
             {
                          attachInterrupt(digitalPinToInterrupt(en2a),encoder2,CHANGE);
             attachInterrupt(digitalPinToInterrupt(en1a),encoder1pid,CHANGE);
               attachInterrupt(digitalPinToInterrupt(en2b),encoder2,CHANGE);
             attachInterrupt(digitalPinToInterrupt(en1b),encoder1pid,CHANGE);
          
                    pidforforwardmoving();  
                    ultra12pidfrwrd();
                   // ultra12encofrwrdpid();
                         
                    if(c2norm>15900 && c2norm<16100)
                    {
                      stopped();
                      detachInterrupt(digitalPinToInterrupt(en2a));
                    detachInterrupt(digitalPinToInterrupt(en1a));
                    detachInterrupt(digitalPinToInterrupt(en2b));
                    detachInterrupt(digitalPinToInterrupt(en1b));
                      flag=5;
                      c2pid=startc;
                    }
             }


   else if(cnorm<=200 && cnorm>=-5000 && flag==5)
             {

           attachInterrupt(digitalPinToInterrupt(en2a),encoder2pid,CHANGE);
             attachInterrupt(digitalPinToInterrupt(en1a),encoder1,CHANGE);

           attachInterrupt(digitalPinToInterrupt(en2b),encoder2pid,CHANGE);
             attachInterrupt(digitalPinToInterrupt(en1b),encoder1,CHANGE);
                    pidforleftmoving();
                    if(cnorm<=-4700 && cnorm>=-5000)
                    {
                        stopped();
                       detachInterrupt(digitalPinToInterrupt(en2a));
                    detachInterrupt(digitalPinToInterrupt(en1a));
                    detachInterrupt(digitalPinToInterrupt(en2b));
                    detachInterrupt(digitalPinToInterrupt(en1b));
                    
                    flag=6;
                 
                    }
             }

    else if(c2norm>=15800 && c2norm<=22400 && flag==6)
             {
                          attachInterrupt(digitalPinToInterrupt(en2a),encoder2,CHANGE);
             attachInterrupt(digitalPinToInterrupt(en1a),encoder1pid,CHANGE);

              attachInterrupt(digitalPinToInterrupt(en2b),encoder2,CHANGE);
             attachInterrupt(digitalPinToInterrupt(en1b),encoder1pid,CHANGE);

                    pidforforwardmoving(); 
                    ultra34pidfrwrd();
                          
                    if(c2norm>22200 && c2norm<22400)
                    {
                      stopped();
                      detachInterrupt(digitalPinToInterrupt(en2a));
                    detachInterrupt(digitalPinToInterrupt(en1a));
                    detachInterrupt(digitalPinToInterrupt(en2b));
                    detachInterrupt(digitalPinToInterrupt(en1b));
                      flag=7;
                      c2pid=startc;
                    }
             }

    else if(cnorm>=-5100 && cnorm<=-1500 && flag==7)
             {

           attachInterrupt(digitalPinToInterrupt(en2a),encoder2pid,CHANGE);
             attachInterrupt(digitalPinToInterrupt(en1a),encoder1,CHANGE);

           attachInterrupt(digitalPinToInterrupt(en2b),encoder2pid,CHANGE);
             attachInterrupt(digitalPinToInterrupt(en1b),encoder1,CHANGE);
                    pidforrightmoving();
                    if(cnorm<=-1500 && cnorm>=-1600)
                    {
                        stopped();
                       detachInterrupt(digitalPinToInterrupt(en2a));
                    detachInterrupt(digitalPinToInterrupt(en1a));
                    detachInterrupt(digitalPinToInterrupt(en2b));
                    detachInterrupt(digitalPinToInterrupt(en1b));

                    
                    flag=8;
                

                    }


             }



         else if(c2norm>=22100 && c2norm<=30800 && flag==8)
             {
                          attachInterrupt(digitalPinToInterrupt(en2a),encoder2,CHANGE);
             attachInterrupt(digitalPinToInterrupt(en1a),encoder1pid,CHANGE);

              attachInterrupt(digitalPinToInterrupt(en2b),encoder2,CHANGE);
             attachInterrupt(digitalPinToInterrupt(en1b),encoder1pid,CHANGE);

                    pidforforwardmoving();       
                    if(c2norm>30700 && c2norm<30800)
                    {
                      
                      detachInterrupt(digitalPinToInterrupt(en2a));
                    detachInterrupt(digitalPinToInterrupt(en1a));
                    detachInterrupt(digitalPinToInterrupt(en2b));
                    detachInterrupt(digitalPinToInterrupt(en1b));

                    
                      flag=9;
                    }
            
      if(flag==9)
              {
                      
                    }
                    
             }



      /*  if(c2norm>=0 && c2norm<=14000 && flag==0)
             {
                          attachInterrupt(digitalPinToInterrupt(en2a),encoder2,CHANGE);
             attachInterrupt(digitalPinToInterrupt(en1a),encoder1pid,CHANGE);

              attachInterrupt(digitalPinToInterrupt(en2b),encoder2,CHANGE);
             attachInterrupt(digitalPinToInterrupt(en1b),encoder1pid,CHANGE);

                    pidforforwardmoving();       
                    if(c2norm>13900&& c2norm<14000)
                    {
                      stopped();
                      detachInterrupt(digitalPinToInterrupt(en2a));
                    detachInterrupt(digitalPinToInterrupt(en1a));
                      flag=1;
                    }
             }

         else if(c2norm>=13900 && c2norm<=17700 && flag==1)
         {

             attachInterrupt(digitalPinToInterrupt(en2a),encoder2,CHANGE);
             attachInterrupt(digitalPinToInterrupt(en1a),encoder1pid,CHANGE);

              attachInterrupt(digitalPinToInterrupt(en2b),encoder2,CHANGE);
             attachInterrupt(digitalPinToInterrupt(en1b),encoder1pid,CHANGE);



              encoclockwise();
              if(c2norm<17700 && c2norm>17600)
              {
                stopped();
                 detachInterrupt(digitalPinToInterrupt(en2a));
                    detachInterrupt(digitalPinToInterrupt(en1a));
                    flag=2;
              }
         }
         
         else if(cnorm>=-2000 && cnorm<=17100 && flag==2)
             {

           attachInterrupt(digitalPinToInterrupt(en2a),encoder2pid,CHANGE);
             attachInterrupt(digitalPinToInterrupt(en1a),encoder1,CHANGE);

           attachInterrupt(digitalPinToInterrupt(en2b),encoder2pid,CHANGE);
             attachInterrupt(digitalPinToInterrupt(en1b),encoder1,CHANGE);
                    pidforrightmoving();
                    if(cnorm<=17100 && cnorm>=17000)
                    {
                        stopped();
                       detachInterrupt(digitalPinToInterrupt(en2a));
                    detachInterrupt(digitalPinToInterrupt(en1a));
                    flag=3;
                    }
             
          if(flag==3)
          {
            
          }


             }             
             */

              /*  else if(flag==8)
                {
                  stopped();
                }
            */
            
            
            }


       if(PS3.getAnalogHat(RightHatY)==127&&PS3.getAnalogHat(RightHatX)==127)
            {
               detachInterrupt(digitalPinToInterrupt(en2a));
                    detachInterrupt(digitalPinToInterrupt(en1a));
              
            }
    
      
     
     
      if (PS3.getButtonClick(LEFT)) {
       // Serial.print(F("\r\nLeft"));
        if (PS3.PS3Connected) {
          PS3.setLedOff();
          PS3.setLedOn(LED3);
        }
      }

      if (PS3.getButtonClick(L1))
       // Serial.print(F("\r\nL1"));
      if (PS3.getButtonClick(L3))
       // Serial.print(F("\r\nL3"));
      if (PS3.getButtonClick(R1))
       // Serial.print(F("\r\nR1"));
      if (PS3.getButtonClick(R3))
      //  Serial.print(F("\r\nR3"));

if (PS3.getButtonClick(PS)) {
     // Serial.print(F("\r\nPS"));
      PS3.disconnect();
    }
  
    
  }

    
}


void encoder1()
{
  Serial.println("encoder");


 int MSB = digitalRead(en1a); 
  int LSB = digitalRead(en1b); 
 
  int encoded = (MSB << 1) |LSB; 
  int sum  = (lastEncoded << 2) | encoded;
 
  if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) cnorm ++;
  if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) cnorm --;
 
  lastEncoded = encoded; 

   
}

void encoder2()
//{
{

 int MSB2 = digitalRead(en2a); 
  int LSB2 = digitalRead(en2b); 
 
  int encoded2 = (MSB2 << 1) |LSB2; 
  int sum2  = (lastEncoded2 << 2) | encoded2;
 
  if(sum2 == 0b1101 || sum2 == 0b0100 || sum2 == 0b0010 || sum2 == 0b1011) c2norm ++;
  if(sum2 == 0b1110 || sum2 == 0b0111 || sum2 == 0b0001 || sum2 == 0b1000) c2norm --;
 
  lastEncoded2 = encoded2; 

   
}

void encoder1pid()
                                                     //while moving forward
  {

  //  Serial.println("encoder1pid");

  int MSB = digitalRead(en1a); 
  int LSB = digitalRead(en1b); 
 
  int encoded = (MSB << 1) |LSB; 
  int sum  = (lastEncoded << 2) | encoded;
 
  if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) cpid ++;
  if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) cpid --;
 
  lastEncoded = encoded; 

  }




void encoder2pid()
                                                  //while moving left right
 {


 int MSB2 = digitalRead(en2a); 
  int LSB2 = digitalRead(en2b); 
 
  int encoded2 = (MSB2 << 1) |LSB2; 
  int sum2  = (lastEncoded2 << 2) | encoded2;
 
  if(sum2 == 0b1101 || sum2 == 0b0100 || sum2 == 0b0010 || sum2 == 0b1011) c2pid ++;
  if(sum2 == 0b1110 || sum2 == 0b0111 || sum2 == 0b0001 || sum2 == 0b1000) c2pid --;
 
  lastEncoded2 = encoded2; 
  
  }



void pidforforwardmoving()
{
  float errlr=cpid-setvalue;
  outpwmlr=(kplr*errlr)+(kdlr*(errlr-lasterrlr))+(kilr*(lasterrlr+errlr));
     palr=pwmlr-outpwmlr;
     pblr=pwmlr+outpwmlr;

      if(palr>maxm)
      {
          palr=maxm;
      }

      if(pblr>maxm)
      {
          pblr=maxm;
      }
     
        if(palr<0)
      {
          palr=0;
      }
      if(pblr<0)
      {
          pblr=0;
      }

   
      
      
      
      if(cpid>=-8 && cpid<=8)
      {
forward();
      }

      else
      {
             digitalWrite(dirm1,LOW);
digitalWrite(dirm2,HIGH);    
digitalWrite(dirm3,HIGH);    //HIGH   C
digitalWrite(dirm4,LOW);            //C

  analogWrite(pwmm1,palr);
analogWrite(pwmm2,pblr);
analogWrite(pwmm3,palr);
analogWrite(pwmm4,pblr);
//Serial.println("forward");
      }
       lasterrlr=errlr;
}


void pidforleftmoving()
{
  
      float errf=c2pid-setvalue;
      outpwmf=(kpf*errf)+(kdf*(errf-lasterrf))+(kif*(lasterrf+errf));
              paf=pwmf+outpwmf;
               pbf=pwmf-outpwmf;

      if(paf>maxm)
      {
          paf=maxm;
      }

      if(pbf>maxm)
      {
          pbf=maxm;
      }
     
        if(paf<0)
      {
          paf=0;
      }
      if(pbf<0)
      {
          pbf=0;
      }

  //  Serial.print("pbf///////////////////");
    //  Serial.println(pbf);
      
      
      if(c2pid>=-20 && c2pid<=20)
      {
left();
      }


      else
      {
             digitalWrite(dirm1,HIGH);
digitalWrite(dirm2,HIGH);    
digitalWrite(dirm3,LOW);    //HIGH   C
digitalWrite(dirm4,LOW);            //C

  analogWrite(pwmm1,paf);
analogWrite(pwmm2,pbf);
analogWrite(pwmm3,paf);
analogWrite(pwmm4,pbf);
//Serial.println("left");
      }
       lasterrf=errf;
}




void pidforrightmoving()
{
   float errf=c2pid-setvalue;
  outpwmf=(kpf*errf)+(kdf*(errf-lasterrf))+(kif*(lasterrf+errf));
     paf=pwmf-outpwmf;
     pbf=pwmf+outpwmf;

      if(paf>maxm)
      {
          paf=maxm;
      }

      if(pbf>maxm)
      {
          pbf=maxm;
      }
     
        if(paf<0)
      {
          paf=0;
      }
      if(pbf<0)
      {
          pbf=0;
      }

 //   Serial.print("pbf///////////////////");
   //   Serial.println(pbf);
      
      
      if(c2pid>=-20 && c2pid<=20)
      {
right();
      }


      else
      {
             digitalWrite(dirm1,LOW);
digitalWrite(dirm2,LOW);    
digitalWrite(dirm3,HIGH);    //HIGH   C
digitalWrite(dirm4,HIGH);            //C

  analogWrite(pwmm1,paf);
analogWrite(pwmm2,pbf);
analogWrite(pwmm3,paf);
analogWrite(pwmm4,pbf);
//Serial.println("right");
      }
       lasterrf=errf;
}
/*

void ultra1()
{

digitalWrite(trig1,LOW);
delayMicroseconds(2);
digitalWrite(trig1,HIGH);
delayMicroseconds(10);
digitalWrite(trig1,LOW);
                 dur1=pulseIn(echo1,255);
                 dis1=(0.034*dur1)/2;
//Serial.println("distance1");
//Serial.println(dis1);
  
}


void ultra2()
{
digitalWrite(trig2,LOW);
delayMicroseconds(2);
digitalWrite(trig2,HIGH);
delayMicroseconds(10);
digitalWrite(trig2,LOW);
                 dur2=pulseIn(echo2,255);
                 dis2=(0.034*dur2)/2;
//Serial.println("distance2");
//Serial.println(dis2);

}


void ultra3()
{

digitalWrite(trig3,LOW);
delayMicroseconds(2);
digitalWrite(trig3,HIGH);
delayMicroseconds(10);
digitalWrite(trig3,LOW);
                 dur3=pulseIn(echo3,255);
                 dis3=(0.034*dur3)/2;
//Serial.println("distance3");
//Serial.println(dis3);
  
}


void ultra4()
{
digitalWrite(trig4,LOW);
delayMicroseconds(2);
digitalWrite(trig4,HIGH);
delayMicroseconds(10);
digitalWrite(trig4,LOW);
                 dur4=pulseIn(echo4,255);
                 dis4=(0.034*dur4)/2;
//Serial.println("distance4");
//Serial.println(dis4);
}
*/

void ultra12pidfrwrd()
{
 // ultra1();
//ultra2();

dis1=sonar1.ping_cm();
dis2=sonar2.ping_cm();

 errang12=dis1-dis2;
 outpwmult12=(kpult*errang12)+(kdult*(errang12-lasterrang12))+kiult*(lasterrang12+errang12);
 paf12ult=pwmf12ult-outpwmult12;
 pbf12ult=pwmf12ult+outpwmult12;
// Serial.println(errang12);
 if(paf12ult>maxmult)
 {
  paf12ult=maxmult;
 
 }
 if(pbf12ult>maxmult)
 {
  pbf12ult=maxmult;
 
 }
 if(paf12ult<0)
 {
  paf12ult=0;
 }
 if(pbf12ult<0)
 {
  pbf12ult=0;
 }

        if(errang12==0)
          {
                forward();
           }

       else
       {
          digitalWrite(dirm1,LOW);
digitalWrite(dirm2,HIGH);    
digitalWrite(dirm3,HIGH);    //HIGH   C
digitalWrite(dirm4,LOW);         //C
analogWrite(pwmm1,paf12ult);
analogWrite(pwmm2,pbf12ult);
analogWrite(pwmm3,pbf12ult);
analogWrite(pwmm4,paf12ult);
/*Serial.print("----------------pa");
Serial.println(paf12ult);
Serial.print("--------------===================--pb");
Serial.println(pbf12ult);
*/
//Serial.println("forward");
      }
       lasterrang12=errang12;
      
       
   }



void ultra34pidfrwrd()
{
  //ultra3();
//ultra4();

dis3=sonar3.ping_cm();
dis4=sonar4.ping_cm();


 errang34=dis3-dis4;
 outpwmult34=(kpult*errang34)+(kdult*(errang34-lasterrang34))+kiult*(lasterrang34+errang34);
 paf34ult=pwmf34ult-outpwmult34;
 pbf34ult=pwmf34ult+outpwmult34;
 //Serial.println(errang34);
 if(paf34ult>maxmult)
 {
  paf34ult=maxmult;
 
 }
 if(pbf34ult>maxmult)
 {
  pbf34ult=maxmult;
 
 }
 if(paf34ult<0)
 {
  paf34ult=0;
 }
 if(pbf34ult<0)
 {
  pbf34ult=0;
 }

        if(errang34==0)
          {
                forward();
           }

       else
       {
          digitalWrite(dirm1,LOW);
digitalWrite(dirm2,HIGH);    
digitalWrite(dirm3,HIGH);    //HIGH   C
digitalWrite(dirm4,LOW);         //C
analogWrite(pwmm1,paf34ult);
analogWrite(pwmm2,pbf34ult);
analogWrite(pwmm3,pbf34ult);
analogWrite(pwmm4,paf34ult);
//Serial.print("----------------pa");
//Serial.println(paf12ult);
//Serial.print("--------------===================--pb");
//Serial.println(pbf12ult);

//Serial.println("forward");
      }
       lasterrang34=errang34;
      
       
   }



void ultra12encofrwrdpid()
{
            dis1=sonar1.ping_cm();
          dis2=sonar2.ping_cm();
          
           errang12=dis1-dis2;
           outpwmult12=(kpult*errang12)+(kdult*(errang12-lasterrang12))+kiult*(lasterrang12+errang12);
           paf12ult=pwmf12ult-outpwmult12;
           pbf12ult=pwmf12ult+outpwmult12;
         //  Serial.println(errang12);
           if(paf12ult>maxmult)
           {
            paf12ult=maxmult;
           
           }
           if(pbf12ult>maxmult)
           {
            pbf12ult=maxmult;
           
           }
           if(paf12ult<0)
           {
            paf12ult=0;
           }
           if(pbf12ult<0)
           {
            pbf12ult=0;
           }



           
                                                float errlr=cpid-setvalue;
                                                  outpwmlr=(kplr*errlr)+(kdlr*(errlr-lasterrlr))+(kilr*(lasterrlr+errlr));
                                                     palr=pwmlr-outpwmlr;
                                                     pblr=pwmlr+outpwmlr;
                                                
                                                      if(palr>maxm)
                                                      {
                                                          palr=maxm;
                                                      }
                                                
                                                      if(pblr>maxm)
                                                      {
                                                          pblr=maxm;
                                                      }
                                                     
                                                        if(palr<0)
                                                      {
                                                          palr=0;
                                                      }
                                                      if(pblr<0)
                                                      {
                                                          pblr=0;
                                                      }
                                                
                                                   
                                                      
                                                      
                                                      
                                          if(cpid>=-8 && cpid<=8)
                                              {
                                                       forward();
                                              }
                                        
                                           /*   else
                                              {
                                                        digitalWrite(dirm1,LOW);
                                                        digitalWrite(dirm2,HIGH);    
                                                        digitalWrite(dirm3,HIGH);    //HIGH   C
                                                        digitalWrite(dirm4,LOW);            //C
                                                        
                                                          analogWrite(pwmm1,palr);
                                                        analogWrite(pwmm2,pblr);
                                                        analogWrite(pwmm3,palr);
                                                        analogWrite(pwmm4,pblr);
                                                          //Serial.println("forward");
                                              }
                                              
                                              */
        
        
        
        
       if(errang12==0)
          {
                forward();
           }

    /*   else
       {
            digitalWrite(dirm1,LOW);
            digitalWrite(dirm2,HIGH);    
            digitalWrite(dirm3,HIGH);    //HIGH   C
            digitalWrite(dirm4,LOW);         //C
            analogWrite(pwmm1,paf12ult);
            analogWrite(pwmm2,pbf12ult);
            analogWrite(pwmm3,pbf12ult);
            analogWrite(pwmm4,paf12ult);
            

      }

      */              if((errang12!=0) &&(cpid<-8 && cpid>8))
                    {
                               int mean1=(palr+paf12ult)/2;
                               int mean2=(pblr+pbf12ult)/2;
                               int mean3=(palr+pbf12ult)/2;
                               int mean4=(pblr+paf12ult)/2;   
                

                             
                              digitalWrite(dirm1,LOW);
                              digitalWrite(dirm2,HIGH);    
                              digitalWrite(dirm3,HIGH);    //HIGH   C
                              digitalWrite(dirm4,LOW);         //C
                              analogWrite(pwmm1,mean1);
                              analogWrite(pwmm2,mean2);
                              analogWrite(pwmm3,mean3);
                              analogWrite(pwmm4,mean4);



                      
                    }

       lasterrlr=errlr;
       lasterrang12=errang12;

}
/*

void ultra12right()
{
      dis1=sonar1.ping_cm();
      dis2=sonar2.ping_cm();
       int meandis=(dis1+dis2)/2;
            if(meandis<20)
            {
              left();
            }
            else if(meandis>21)
            {
                                       errang12=dis1-dis2;
                         outpwmult12=(kpult*errang12)+(kdult*(errang12-lasterrang12))+kiult*(lasterrang12+errang12);
                         paf12ult=pwmf12ult-outpwmult12;
                         pbf12ult=pwmf12ult+outpwmult12;
                         Serial.println(errang12);
                         if(paf12ult>maxmult)
                         {
                          paf12ult=maxmult;
                         
                         }
                         if(pbf12ult>maxmult)
                         {
                          pbf12ult=maxmult;
                         
                         }
                         if(paf12ult<0)
                         {
                          paf12ult=0;
                         }
                         if(pbf12ult<0)
                         {
                          pbf12ult=0;
                         }
                        
                                if(errang12==0)
                                  {
                                        right();
                                   }
                        
                               else
                               {
                                 
                                              digitalWrite(dirm1,LOW);  
                                    digitalWrite(dirm2,LOW);
                                    digitalWrite(dirm3,HIGH);        //HIGH  C
                                    digitalWrite(dirm4,HIGH);  
                                    analogWrite(pwmm1,paf12ult);
                                    analogWrite(pwmm2,pbf12ult);
                                    analogWrite(pwmm3,pbf12ult);
                                    analogWrite(pwmm4,paf12ult);
                        
                              }
                               lasterrang12=errang12;
            }
            else{
              stop1();
            }

}*/



void ultra12rightgerge()
{

   dis1=sonar1.ping_cm();
      dis2=sonar2.ping_cm();
       float meandis=(dis1+dis2)/2;


        if(int(dis1)==int(dis2))
        {
          if(meandis<15)
          {
            left();
          }
          else if(meandis>=16)
          {
                             digitalWrite(dirm1,LOW);
                  analogWrite(pwmm1,165);
                  digitalWrite(dirm2,LOW);
                  analogWrite(pwmm2,165);
                  digitalWrite(dirm3,HIGH);
                  analogWrite(pwmm3,165);
                  digitalWrite(dirm4,HIGH);
                  analogWrite(pwmm4,165);
          }
          else
          {
            stop1();
          }
        }
        else
        {
              
               /*if(meandis<15)          
                   {
                          left();
                   }
*/
                if(meandis>10)
                {
                           
                
                         
                         errang12gerg=dis1-dis2;
                         outpwmult12gerg=(kpultgerg*errang12gerg)+(kdultgerg*(errang12gerg-lasterrang12gerg))+kiultgerg*(lasterrang12gerg+errang12gerg);
                         /*paf12ult=pwmf12ult-outpwmult12;
                         pbf12ult=pwmf12ult+outpwmult12;
                         Serial.println(errang12);
                         if(paf12ult>maxmult)
                         {
                          paf12ult=maxmult;
                         
                         }
                         if(pbf12ult>maxmult)
                         {
                          pbf12ult=maxmult;
                         
                         }
                         if(paf12ult<0)
                         {
                          paf12ult=0;
                         }
                         if(pbf12ult<0)
                         {
                          pbf12ult=0;
                         }
*/
                         if(outpwmult12gerg<0)
                         {
                          outpwmult12gerg=-outpwmult12gerg;
                         }


                        
                         if(outpwmult12gerg>maxmult)
                         {
                          outpwmult12gerg=maxmult;
                         
                         }
                         
       Serial.print(dis1);
       Serial.print("......");
       Serial.println(dis2);
      Serial.print("=============="); 
      Serial.println(outpwmult12gerg);

                         if(errang12gerg>0)
                         {
                            
                                digitalWrite(dirm1,HIGH);
                                analogWrite(pwmm1, outpwmult12gerg);
                                digitalWrite(dirm2,HIGH);//CHANGE
                                analogWrite(pwmm2, outpwmult12gerg);
                                digitalWrite(dirm3,HIGH);
                                analogWrite(pwmm3,outpwmult12gerg);
                                digitalWrite(dirm4,HIGH);
                                analogWrite(pwmm4,outpwmult12gerg );

                         }
                         if(errang12gerg<0)
                         {
  
                            digitalWrite(dirm1,LOW);
                            analogWrite(pwmm1,outpwmult12gerg);
                            digitalWrite(dirm2,LOW);//CHANGE
                            analogWrite(pwmm2,outpwmult12gerg);
                            digitalWrite(dirm3,LOW);
                            analogWrite(pwmm3,outpwmult12gerg);
                            digitalWrite(dirm4,LOW);
                            analogWrite(pwmm4,outpwmult12gerg);
                                }
                                    
                           if(errang12gerg==0)
                           {
                                stop1(); 
                           }
                                
                        lasterrang12gerg=errang12gerg;
                                
                  }

                         else
                         {
                          left();
                          
                         }

        }
                                 /*   digitalWrite(dirm1,LOW);  
                                    digitalWrite(dirm2,LOW);
                                    digitalWrite(dirm3,HIGH);        //HIGH  C
                                    digitalWrite(dirm4,HIGH);  
                                    analogWrite(pwmm1,paf12ult);
                                    analogWrite(pwmm2,pbf12ult);
                                    analogWrite(pwmm3,pbf12ult);
                                    analogWrite(pwmm4,paf12ult);*/



                         
        }

       



void ultra5frwrdgerge()
{
  dis5=sonar5.ping_cm();

            errfrwrdgerg=setdisgerg-dis5;
            outpwmult5=(kpultfrwrdgerg*errfrwrdgerg)+(kdultfrwrdgerg*(errfrwrdgerg-lasterrfrwrdgerg))+kiultfrwrdgerg*(lasterrfrwrdgerg+errfrwrdgerg);    


                         
                         if(outpwmult5<0)
                         {
                          outpwmult5=-outpwmult5;
                         }

                         
                     if(outpwmult5>140)
                         {
                          outpwmult5=140;
                         
                         }
                       if(outpwmult5<34)
                         {
                          outpwmult5=34;
                         }
      


     /*                 
      Serial.println(dis5);
      Serial.print("=============="); 
      Serial.println(outpwmult5);
      */
  
  if(dis5>setdisgerg)
  {
    
                          digitalWrite(dirm1,LOW);
                digitalWrite(dirm2,HIGH);    
                digitalWrite(dirm3,HIGH);    //HIGH   C
                digitalWrite(dirm4,LOW);            //C
                
                  analogWrite(pwmm1,outpwmult5);           //-40
                analogWrite(pwmm2,outpwmult5);           //+30
                analogWrite(pwmm3,outpwmult5);               //30  
                analogWrite(pwmm4,outpwmult5);

  }
  if(dis5<setdisgerg)
  {
              digitalWrite(dirm1,HIGH);
                digitalWrite(dirm2,LOW);    
                digitalWrite(dirm3,LOW);    //HIGH   C
                digitalWrite(dirm4,HIGH);            //C
                
                  analogWrite(pwmm1,outpwmult5);           //-40
                analogWrite(pwmm2,outpwmult5);           //+30
                analogWrite(pwmm3,outpwmult5);               //30  
                analogWrite(pwmm4,outpwmult5);
  }

  if(dis5==setdisgerg)
  {
    stop1();
  }

    lasterrfrwrdgerg=errfrwrdgerg;

  
}


//**************************************align button**********************************************************

void alignbutton()
{

 
dis1=sonar1.ping_cm();
      dis2=sonar2.ping_cm();
       float meandis=(dis1+dis2)/2;

                         errang12gerg=dis1-dis2;
                         outpwmult12gerg=(kpultgerg*errang12gerg)+(kdultgerg*(errang12gerg-lasterrang12gerg))+kiultgerg*(lasterrang12gerg+errang12gerg);

                         if(outpwmult12gerg<0)
                         {
                          outpwmult12gerg=-outpwmult12gerg;
                         }


                        
                         if(outpwmult12gerg>maxmult)
                         {
                          outpwmult12gerg=maxmult;
                         
                         }


                          if(outpwmult12gerg<50)
                          {
                            outpwmult12gerg=50;
                          }
                         
                         
       Serial.print(dis1);
       Serial.print("......");
       Serial.println(dis2);
      Serial.print("=============="); 
      Serial.println(outpwmult12gerg);

                         if(errang12gerg>1)
                         {
                            
                                digitalWrite(dirm1,HIGH);
                                analogWrite(pwmm1, outpwmult12gerg);
                                digitalWrite(dirm2,HIGH);//CHANGE
                                analogWrite(pwmm2, outpwmult12gerg);
                                digitalWrite(dirm3,HIGH);
                                analogWrite(pwmm3,outpwmult12gerg);
                                digitalWrite(dirm4,HIGH);
                                analogWrite(pwmm4,outpwmult12gerg );

                         }
                         else if(errang12gerg<0)
                         {
  
                            digitalWrite(dirm1,LOW);
                            analogWrite(pwmm1,outpwmult12gerg);
                            digitalWrite(dirm2,LOW);//CHANGE
                            analogWrite(pwmm2,outpwmult12gerg);
                            digitalWrite(dirm3,LOW);
                            analogWrite(pwmm3,outpwmult12gerg);
                            digitalWrite(dirm4,LOW);
                            analogWrite(pwmm4,outpwmult12gerg);
                                }
                                    
                           else
                           {
                        
                                        errrightgerg=setdisrightgerge-meandis;
                                        outpwm12right=(kpultrightgerg*errrightgerg)+(kdultrightgerg*(errrightgerg-lasterrrightgerg))+kiultrightgerg*(lasterrrightgerg+errrightgerg);   
                                          if(outpwm12right<0)
                                           {
                                            outpwm12right=-outpwm12right;
                                           }
                  
                                           
                                       if(outpwm12right>140)
                                           {
                                            outpwm12right=140;
                                           
                                           }
                                         if(outpwm12right<45)
                                           {
                                            outpwm12right=45;
                                           }

                                            if(meandis<15)
                                              {
                                                 digitalWrite(dirm1,HIGH);
                                                      analogWrite(pwmm1,outpwm12right);
                                                      digitalWrite(dirm2,HIGH);
                                                      analogWrite(pwmm2,outpwm12right);
                                                      digitalWrite(dirm3,LOW);
                                                      analogWrite(pwmm3,outpwm12right);
                                                      digitalWrite(dirm4,LOW);
                                                      analogWrite(pwmm4,outpwm12right);
                                              }
                                              else if(meandis>16)
                                              {
                                                                 digitalWrite(dirm1,LOW);
                                                      analogWrite(pwmm1,outpwm12right);
                                                      digitalWrite(dirm2,LOW);
                                                      analogWrite(pwmm2,outpwm12right);
                                                      digitalWrite(dirm3,HIGH);
                                                      analogWrite(pwmm3,outpwm12right);
                                                      digitalWrite(dirm4,HIGH);
                                                      analogWrite(pwmm4,outpwm12right);
                                              }
                                              else
                                              {
                                              
                                                                                                              
                                                          dis5=sonar5.ping_cm();
                                                          
                                                                      errfrwrdgerg=setdisgerg-dis5;
                                                                      outpwmult5=(kpultfrwrdgerg*errfrwrdgerg)+(kdultfrwrdgerg*(errfrwrdgerg-lasterrfrwrdgerg))+kiultfrwrdgerg*(lasterrfrwrdgerg+errfrwrdgerg);   
                                                                      
                                                                                if(outpwmult5<0)
                                                                                   {
                                                                                    outpwmult5=-outpwmult5;
                                                                                   }
                                                          
                                                                                   
                                                                               if(outpwmult5>140)
                                                                                   {
                                                                                    outpwmult5=140;
                                                                                   
                                                                                   }
                                                                                 if(outpwmult5<40)
                                                                                   {
                                                                                    outpwmult5=40;
                                                                                   }
                                                          
                                                               /*                 
                                                                Serial.println(dis5);
                                                                Serial.print("=============="); 
                                                                Serial.println(outpwmult5);
                                                                */
                                                            
                                                            if(dis5>setdisgerg)
                                                            {
                                                                           digitalWrite(dirm1,LOW);
                                                                          digitalWrite(dirm2,HIGH);    
                                                                          digitalWrite(dirm3,HIGH);    //HIGH   C
                                                                          digitalWrite(dirm4,LOW);            //C
                                                                          
                                                                            analogWrite(pwmm1,outpwmult5);           //-40
                                                                          analogWrite(pwmm2,outpwmult5);           //+30
                                                                          analogWrite(pwmm3,outpwmult5);               //30  
                                                                          analogWrite(pwmm4,outpwmult5);
                                                          
                                                            }
                                                            if(dis5<setdisgerg)
                                                            {
                                                                        digitalWrite(dirm1,HIGH);
                                                                          digitalWrite(dirm2,LOW);    
                                                                          digitalWrite(dirm3,LOW);    //HIGH   C
                                                                          digitalWrite(dirm4,HIGH);            //C
                                                                          
                                                                            analogWrite(pwmm1,outpwmult5);           //-40
                                                                          analogWrite(pwmm2,outpwmult5);           //+30
                                                                          analogWrite(pwmm3,outpwmult5);               //30  
                                                                          analogWrite(pwmm4,outpwmult5);
                                                            }
                                                          
                                                            if(dis5==setdisgerg)
                                                            {
                                                              stop1();
                                                            }
                                                          
                                                              lasterrfrwrdgerg=errfrwrdgerg;

                                             
                                              
                                              
                                              
                                              }


                                
                           }
                                
                        lasterrang12gerg=errang12gerg;
                                


}










void encoclockwise()
 {
   digitalWrite(dirm1,HIGH);
  analogWrite(pwmm1,180);
  digitalWrite(dirm2,HIGH);//CHANGE
  analogWrite(pwmm2,180);
  digitalWrite(dirm3,HIGH);
  analogWrite(pwmm3,180);
  digitalWrite(dirm4,HIGH);
  analogWrite(pwmm4,180);
 }



void forward()
{
digitalWrite(dirm1,LOW);
digitalWrite(dirm2,HIGH);    
digitalWrite(dirm3,HIGH);    //HIGH   C
digitalWrite(dirm4,LOW);            //C

//for (int j=35; j<=maxnor;j++)
//{

  analogWrite(pwmm1,maxnor);           //-40
analogWrite(pwmm2,maxnor);           //+30
analogWrite(pwmm3,maxnor);               //30  
analogWrite(pwmm4,maxnor);

//Serial.println("forward");

//delayMicroseconds(30);
//}
//i=maxnor;

}
void left()
{
  
digitalWrite(dirm1,HIGH);
digitalWrite(dirm2,HIGH);
digitalWrite(dirm3,LOW);      //LOW    C
digitalWrite(dirm4,LOW);             //C

  analogWrite(pwmm1,maxnor);
analogWrite(pwmm2,maxnor);
analogWrite(pwmm3,maxnor);
analogWrite(pwmm4,maxnor);
//Serial.println("left");
//i=maxnor;
}
void stopped()
{
  analogWrite(pwmm1,0);
analogWrite(pwmm2,0);
analogWrite(pwmm3,0);
analogWrite(pwmm4,0);
}
void right()
{

  digitalWrite(dirm1,LOW);
digitalWrite(dirm2,LOW);
digitalWrite(dirm3,HIGH);        //HIGH  C
digitalWrite(dirm4,HIGH);         //  C

  analogWrite(pwmm1,maxnor);
analogWrite(pwmm2,maxnor);
analogWrite(pwmm3,maxnor);
analogWrite(pwmm4,maxnor);
//Serial.println("right");
//i=maxnor;
}
void stopp()
{
  for(i;i>=0;i--)
  {
  digitalWrite(dirm1,HIGH);
digitalWrite(dirm2,LOW);
digitalWrite(dirm3,LOW);
digitalWrite(dirm4,HIGH);

  analogWrite(pwmm1,0);
analogWrite(pwmm2,0);
analogWrite(pwmm3,0);
analogWrite(pwmm4,0);
//Serial.println("stop");
delayMicroseconds(30);

  analogWrite(pwmm1,i);
analogWrite(pwmm2,i);
analogWrite(pwmm3,i);
analogWrite(pwmm4,i);
//Serial.println("stop");
 }

}


 void backwardjoy()
 {
  digitalWrite(dirm1,HIGH);
  analogWrite(pwmm1,255);  // 100 70 95 80 90 255 75 78 85 87 88 86 (90 95 87 92)
  digitalWrite(dirm2,LOW);//CHANGE
  analogWrite(pwmm2,255); //93 90
  digitalWrite(dirm3,LOW);
  analogWrite(pwmm3,255);  //100 70 95 80 255 75 78 85 87 90
  digitalWrite(dirm4,HIGH);
  analogWrite(pwmm4,255 );  //100
  
  
 }

void forwardjoy()
{
  /*  int r=pwmY+40;
    int j=pwmY-25;
  if(r>=255)
  {
    r=255;
  }

 if(j<=0)
 {
  j=0;
 }*/
  digitalWrite(dirm1,LOW);
  analogWrite(pwmm1,255);
  digitalWrite(dirm2,HIGH);
   analogWrite(pwmm2,255);  //CHNAGE
  digitalWrite(dirm3,HIGH);
  analogWrite(pwmm3,255);
  digitalWrite(dirm4,LOW);
  analogWrite(pwmm4,255);
  
}
void rightjoy(){
  digitalWrite(dirm1,LOW);
  analogWrite(pwmm1,255);
  digitalWrite(dirm2,LOW);
  analogWrite(pwmm2,255);
  digitalWrite(dirm3,HIGH);
  analogWrite(pwmm3,255);
  digitalWrite(dirm4,HIGH);
  analogWrite(pwmm4,255);
}
void leftjoy()
{
  digitalWrite(dirm1,HIGH);
  analogWrite(pwmm1,255);
  digitalWrite(dirm2,HIGH);
  analogWrite(pwmm2,255);
  digitalWrite(dirm3,LOW);
  analogWrite(pwmm3,255);
  digitalWrite(dirm4,LOW);
  analogWrite(pwmm4,255);
}

void stop1(){
 // Serial.println("stopped");
digitalWrite(dirm1,LOW);
  analogWrite(pwmm1,0);
  digitalWrite(dirm2,LOW);
  
  analogWrite(pwmm2,0);
  digitalWrite(dirm3,HIGH);
  analogWrite(pwmm3,0);
  digitalWrite(dirm4,LOW);
  analogWrite(pwmm4,0);
}
 
void southeast()
{
 
  digitalWrite(dirm2,LOW);//CHANGE
  analogWrite(pwmm2,255);
  digitalWrite(dirm4,HIGH);
  analogWrite(pwmm4,255);

}
void southwest()
{
  digitalWrite(dirm1,HIGH);
  analogWrite(pwmm1,255);
  digitalWrite(dirm3,LOW);
  analogWrite(pwmm3,255);
}
void northwest()
{
   
  digitalWrite(dirm2,HIGH);
  analogWrite(pwmm2,255);  
  digitalWrite(dirm4,LOW);
  analogWrite(pwmm4,255);

}
void northeast()
{
  digitalWrite(dirm1,LOW);
  analogWrite(pwmm1,255);
  digitalWrite(dirm3,HIGH);
  analogWrite(pwmm3,255);
  
}
void clockwise()
{
  digitalWrite(dirm1,HIGH);
  analogWrite(pwmm1,180);
  digitalWrite(dirm2,HIGH);//CHANGE
  analogWrite(pwmm2,180);
  digitalWrite(dirm3,HIGH);
  analogWrite(pwmm3,180);
  digitalWrite(dirm4,HIGH);
  analogWrite(pwmm4,180);
}
void anticlockwise()
{
  
  digitalWrite(dirm1,LOW);
  analogWrite(pwmm1,180);
  digitalWrite(dirm2,LOW);//CHANGE
  analogWrite(pwmm2,180);
  digitalWrite(dirm3,LOW);
  analogWrite(pwmm3,180);
  digitalWrite(dirm4,LOW);
  analogWrite(pwmm4,180);
}

