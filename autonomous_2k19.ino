//#include <NewPing.h>

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);



#define trig1 40
#define echo1  38
#define trig2 44
#define echo2 42 
int dir5 = 11; // left piche
int an5 = 13;

int dir6 = 15; //right aage
int an6 = 2;

int dir1 = 9; //left age
int an1 = 12;

int dir2 = 14; //right piche//15
int an2 = 3;//2

int dir4 = 5; //niche wali
int an4 = 6;

int dir3 = 7;
int an3 = 8;

int flagr = 0;
int flag1 = 1;

int flag2 = 1;
int flag3 = 1;
int flag4 = 1;
int flag5 = 1;
int flag6 = 1;


int flags=0;
int flag1s=1;
int flag2s=1;
int flag3s=1;
int flag4s=1;
int flag5s=1;
int flag6s=1;
int pwm1 = 90;
int pwm = 160;
volatile int c1;
volatile int c2;
volatile int c3;
volatile int c4;
volatile int c5;
volatile int c6;


volatile int valpre;
volatile int valpre2;
volatile int valpre3;
volatile int valpre4;
volatile int valpre5;
volatile int valpre6;



volatile int valnow;
volatile int valnow2;
volatile int valnow3;
volatile int valnow4;
volatile int valnow5;
volatile int valnow6;


int en3b =34;
int en3a = 36;
int en1a = 37;
int en1b = 35;
int en4b = 32;
int en4a = 30;
int en2a = 26;
int en2b = 28;

int en5a = 27;
int en5b = 29;

int en6a = 33;
int en6b = 31;

volatile int lastEncoded1 = 0;
volatile long encoderValue1 = 0;

long lastencoderValue1 = 0;


volatile int lastEncoded2 = 0;
volatile long encoderValue2 = 0;

long lastencoderValue2 = 0;


volatile int lastEncoded3 = 0;
volatile long encoderValue3 = 0;

long lastencoderValue3 = 0;

volatile int lastEncoded4 = 0;
volatile long encoderValue4 = 0;

long lastencoderValue4 = 0;

volatile int lastEncoded5 = 0;
volatile long encoderValue5 = 0;

long lastencoderValue5 = 0;



volatile int lastEncoded6 = 0;
volatile long encoderValue6 = 0;

long lastencoderValue6 = 0;

int long distance=0;
int long duration=0;
void setup() {
  // initialize the LCD
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
 // lcd.print("Hello, world!");
  
  /*
    #ifdef _SAM3X8E_
    SerialUSB.begin(250000);
    while(!SerialUSB);
    #endif*/
Serial.begin(115200);
  //while(!Serial);
  // put your setup code here, to run once:

pinMode(trig1,OUTPUT);
pinMode(echo1,INPUT);
pinMode(trig2,OUTPUT);
pinMode(echo2,INPUT);
  pinMode(dir1, OUTPUT);
  pinMode(an1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(an2, OUTPUT);
  pinMode(dir3, OUTPUT);
  pinMode(an3, OUTPUT);
  pinMode(dir4, OUTPUT);
  pinMode(an4, OUTPUT);
  pinMode(dir5, OUTPUT);
  pinMode(dir6, OUTPUT);
  pinMode(an5, OUTPUT);
  pinMode(an6, OUTPUT);
    digitalWrite(dir4,LOW);
  digitalWrite(dir3,LOW);
  analogWrite(an5, 0);
  analogWrite(an6, 0);

  analogWrite(an1, 0);
  analogWrite(an2, 0);
  analogWrite(an3, 0);
  analogWrite(an4, 0);
  digitalWrite(trig1,LOW);
  digitalWrite(echo1,LOW);
  digitalWrite(trig2,LOW);
  digitalWrite(echo2,LOW);
  pinMode(en1a, INPUT);
  pinMode(en2a, INPUT);
  pinMode(en3a, INPUT);
  pinMode(en4a, INPUT);
  pinMode(en5a, INPUT);
  pinMode(en6a, INPUT);
  pinMode(en1b, INPUT);
  pinMode(en2b, INPUT);
  pinMode(en3b, INPUT);
  pinMode(en4b, INPUT);
  pinMode(en5b, INPUT);
  pinMode(en6b, INPUT);

  attachInterrupt(digitalPinToInterrupt(en2a), encoder2 , CHANGE);
  attachInterrupt(digitalPinToInterrupt(en1a), encoder1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(en3a), encoder3, CHANGE);
  attachInterrupt(digitalPinToInterrupt(en4a), encoder4, CHANGE);
  attachInterrupt(digitalPinToInterrupt(en5a), encoder5, CHANGE);
  attachInterrupt(digitalPinToInterrupt(en6a), encoder6, CHANGE);
  
//c3=-550;
//c2=-1900;

  delay(2000);





initi1();
  // delay(1000);
}
void loop() {
 /* digitalWrite(trig1,LOW);
  delayMicroseconds(2);
  digitalWrite(trig1,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1,LOW);
  duration=pulseIn(echo1,HIGH);*/
/*int  pos=analogRead(A5);
 Serial.println(analogRead(A5));
 lcd.setCursor(0,0);
 lcd.print(pos);*/
 //lcd.clear();
  
 
//motion2();
//motion1();
/*if(c4<1000){
digitalWrite(dir4,0);
  analogWrite(an4,160);
}
if(c3>-1000&&c3<1000){
  digitalWrite(dir3,0);
  analogWrite(an3,160);
}
else{
analogWrite(an4,0);
analogWrite(an3,0);
}*/

  //SerialUSB.println("c2");
 // SerialUSB.println(c6);
  //SerialUSB.println("c5");

 //SerialUSB.println(c3);
 //SerialUSB.println(c4);
 // SerialUSB.println("c6");
//SerialUSB.println(c6);

 //
// motion1();
//sanddune();
 //delay(200000);

}
void encoder1()
{

  valnow = digitalRead(en1a);

  if (digitalRead(en1b) != valnow)
  {
    c1++;

  }
  else
  {
    c1--;
  }

}
void encoder2()

{

  valnow2 = digitalRead(en2a);

  if (digitalRead(en2b) != valnow2)
  {
    c2++;

  }
  else
  {
    c2--;
  }

}
void encoder3()

{
  valnow3 = digitalRead(en3a);


  if (digitalRead(en3b) != valnow3)
  {
    c3++;

  }
  else
  {
    c3--;
  }

}

void encoder4()
{

  valnow4 = digitalRead(en4a);


  if (digitalRead(en4b) != valnow4)
  {
    c4++;

  }
  else
  {
    c4--;
  }

}
void encoder5()
{

  valnow5 = digitalRead(en5a);

  if (digitalRead(en5b) != valnow5)
  {
    c5++;

  }
  else
  {
    c5--;
  }
}
void encoder6()
{
  valnow6 = digitalRead(en6a);
  if (digitalRead(en6b) != valnow6)
  {
    c6++;

  }
  else
  {
    c6--;
  }
}


void motion1()
{
  
//first and second number motor vertical upward motion 
                           if (flagr == 0) {
                                     if (c5 < 0)
                                           {
                                        digitalWrite(dir5, LOW);
                                       analogWrite(an5, pwm1-40);

                                             }
                                    if (c5 >= 0)
                                           {
      
                                     digitalWrite(dir5, HIGH);
                                     analogWrite(an5, 30);
   
                                            }
                                   if (c6 < 0)
                                         {
                                    digitalWrite(dir6, LOW);
                                    analogWrite(an6, pwm1-30);

                                          }
                                   if (c6 >= 0)
                                       {
                                  digitalWrite(dir6, HIGH);
                                  analogWrite(an6, pwm1-30);
                                       }
                                   if (flag1 == 1 && c1 <= 10 && c1 >= -2500)
                                     {
                                 digitalWrite(dir1, HIGH);
                                 analogWrite(an1, pwm);
  

                               if (c1 < -2450 && c1 >= -2500)
                                      {
                                     flag1 = 2;
                                     analogWrite(an1, 0);
                                       }

                                    }
                               if (flag2 == 1 && c2 <= 10 && c2 >= -2900)
                                  {
                                  digitalWrite(dir2, LOW);
                                 analogWrite(an2, pwm-30);
  
                                 if (c2 <= -2850 && c2 >= -2900)
                                {
                               flag2 = 2;
                                      }
                                    }


                             if (flag1 == 2 && flag2 == 2)
                                  {

                                 flagr = 1;
                           analogWrite(an1, 0);
                           analogWrite(an2, 0);
                                    }
                                   }



///**********************diagonal movement of motor number 3 and 4*****************************//////////
                              
if (flagr == 1)
  {
  if (c5 < 0)
    {
      digitalWrite(dir5, LOW);
      analogWrite(an5, pwm1-10);

    }
    if (c5 >= 0)
    {
      analogWrite(an5, 0);
      c5 = 0;
    }
    if (c6 < 0)
    {
      digitalWrite(dir6, LOW);
      analogWrite(an6, pwm1-30);

    }
    if (c6 >= 0)
    {
      analogWrite(an6, 0);
      c6 = 0;
    }

    if (flag3 == 1 && c3 <= 20 && c3 >= -1900) //1700 800
    {
      digitalWrite(dir3, LOW);
      analogWrite(an3, 255);

      if (c3 >= -1900 && c3 <= -1850)
      {
        flag3 = 2;
      }
    }
    if (flag4 == 1 && c4 <= 20 && c4 >= -1900)
    {
      digitalWrite(dir4, LOW);
      analogWrite(an4, 255);

      if (c4 >= -1900 && c4 <= -1850)
      {
        flag4 = 2;
      }
    }
    if (flag4 == 2 && flag3 == 2)
    {
      c2=-2900;
      c1=-2500;
      flagr = 2;
      
      analogWrite(an3, 0);
      analogWrite(an4, 0);

    }
  }


/////***************************************downward motion of leg with motor number 1 and 2 **************************************/////////////////////////////////////


  
if (flagr == 2)
  {
    if (c5 < 0)
    {
      digitalWrite(dir5, LOW);
      analogWrite(an5, pwm1-30);

    }
    if (c5 >= 0)
    {
      analogWrite(an5, 0);
      c5 = 0;
    }
    if (c6 < 0)
    {
      digitalWrite(dir6, LOW);
      analogWrite(an6, pwm1-30);

    }
    if (c6 >= 0)
    {
      analogWrite(an6, 0);
      c6 = 0;
    }
  if (flag1 == 2 && c1 <= 10 && c1 >= -2600) //-1000
    {
      digitalWrite(dir1, LOW);
      analogWrite(an1, pwm+20);

      if (c1 >= -50 && c1 <= 0)
      {
        flag1 = 3;
         analogWrite(an1, 0);
      }

    }
     if (flag1 == 3 /*&& flag2 == 3*/)
    {

      flagr = 3;
      analogWrite(an1, 0);
      analogWrite(an2, 0);
      
    }}
 /*   if (flag2 == 2 && c2 <= 0 && c2 >= -2500) //-1000
    {
      digitalWrite(dir2, HIGH);
      analogWrite(an2, pwm -20);
       digitalWrite(dir1, LOW);
      analogWrite(an1, pwm);


      if (c2 >= -100 && c2 <= 20)
      {
        flag2 = 3;
      }
    }


    if (/*flag1 == 3 && flag2 == 3)
    {

      flagr = 3;
      analogWrite(an1, 0);
      analogWrite(an2, 0);
    }

  }*/

  /////////***************************************vertical motion of leg with motor number 5 and 6*********************///////////////////////////////////////
  

 
  while(flagr == 3)
  {
    if (c1 < 0)
    {
      digitalWrite(dir1, LOW);
      analogWrite(an1, pwm1-30);

    }
    if (c1 >= 0)
    {
      analogWrite(an1, 0);
      c1 = 0;
    }
    if (c2 < 0)
    {
      digitalWrite(dir2, HIGH);
      analogWrite(an2, pwm1-30);

    }
    if (c2 >= 0)
    {
      analogWrite(an2, 0);
      c2 = 0;
    }
    if (flag5 == 1 && c5 <= 120 && c5 >= -3100)
    {
      digitalWrite(dir5, HIGH);
      analogWrite(an5, pwm);
      

      if (c5 <= -3040 && c5 >= -3100)
      {
        flag5 = 2;
      }
    }
   if (flag6 == 1 && c6 <= 20 && c6 >= -3000)
    {
      digitalWrite(dir6, HIGH);
      analogWrite(an6, pwm+10);

      if (c6 <= -2900 && c6 >= -3000)
      {
        flag6 = 2;
          analogWrite(an6, 0);
      }
    }
    if (flag5 == 2 && flag6 == 2)
    {

      c3 = -1950;
      c4 = -1950;
      // c3=-1650;
      flagr = 4;
      analogWrite(an5, 0);
      analogWrite(an6, 0);


    }
  }

  
  ///////////////////////////////////****************************diagonal motion of base with the help of motor number 4 and 3******************************///////////////

  
 while (flagr == 4)
  {
    if (c1 < 0)
    {
      digitalWrite(dir1, LOW);
      analogWrite(an1, pwm1-30);

    }
    if (c1 >= 0)
    {
      analogWrite(an1, 0);
      c1 = 0;
    }
    if (c2 < 0)
    {
      digitalWrite(dir2, HIGH);
      analogWrite(an2, pwm1-30);

    }
    if (c2 >= 0)
    {
      analogWrite(an2, 0);
      c2 = 0;
    }
    if (flag3 == 2 && c3 <= 20 && c3 >= -2400) //-1700  1750  *800
    {
      digitalWrite(dir3, HIGH);
      analogWrite(an3, 255);

      if (c3 >= 0 && c3 <= 20)
      {
        flag3 = 3;
      }
    }
    if (flag4 == 2 && c4 <= 20 && c4 >= -2100) //-1700  800
    {
      digitalWrite(dir4, HIGH);
      analogWrite(an4, 255);

      if (c4 >= 0 && c4 <= 20)
      {
        flag4 = 3;
      }
    }
    if (flag4 == 3 && flag3 == 3)
    {
c2=0;
      c5 = 0;
      c6 = -3000;
      flagr = 5;
      analogWrite(an3, 0);
      analogWrite(an4, 0);

    }
  }
  while (flagr == 5)
  {
    if (c1 < 0)
    {
      digitalWrite(dir1, LOW);
      analogWrite(an1, pwm1-30);

    }
    if (c1 >= 0)
    {
      analogWrite(an1, 0);
      c1 = 0;
    }
    if (c2 < 0)
    {
      digitalWrite(dir2, HIGH);
      analogWrite(an2, pwm1-30);

    }
    if (c2 >= 0)
    {digitalWrite(dir2, LOW);
      analogWrite(an2, 30);
     
    }
    if (flag6 == 2 && c6<= 0 && c6 >= -3100)
    {
      
      
      digitalWrite(dir6, LOW);
      analogWrite(an6, pwm);

      if (c6 >= -50 && c6 <= 0)
      {
        flag6 = 3;
      }
    }
     if (flag6 == 3/* && flag6 == 3*/)
    {
      c2=0;
      c5=0;
 int i=0;
       while (i == 0) {
    if (c5 > -100 && c5 <901) {

      digitalWrite(dir5, LOW);
      analogWrite(an5, 130);
    }
    if (c2 > -150&& c2 < 905) {
 
      digitalWrite(dir2, HIGH);
      analogWrite(an2, 130);
    }
   
     else
    {
      digitalWrite(dir2, HIGH);
      analogWrite(an2, 0);
      digitalWrite(dir5, HIGH);
      analogWrite(an5, 0);
      digitalWrite(dir6, HIGH);
      analogWrite(an6, 0);
      digitalWrite(dir1, HIGH);
      analogWrite(an1, 0);
 
      i = 2;
      c1 = 0;
      c2 = 0;
      c3 = 0;
      c4 = 0;
      c5 = 0;
      c6 = 0;
   
    }}

      flagr = 6;
      analogWrite(an5, 0);
      analogWrite(an6, 0);


    }
  }

  while(flagr==6)
  {
      if (c5 < 0)
    {
      digitalWrite(dir5, LOW);
      analogWrite(an5, pwm1-20);

    }
    if (c5 >= 0)
    {
      
      digitalWrite(dir5, HIGH);
      analogWrite(an5, 0);
   
    }
    if (c6 < 0)
    {
      digitalWrite(dir6, LOW);
      analogWrite(an6, pwm1-40);

    }
    if (c6 >= 0)
    {
      digitalWrite(dir6, HIGH);
      analogWrite(an6, 0);
    }

    //c1 c2 be the leg motor of one diagonal
  if (flag1 == 3 && c1 <= 10 && c1 >= -3600)
    {
      digitalWrite(dir1, HIGH);
      analogWrite(an1, pwm);
  

      if (c1 < -3250 && c1 >= -3600)
      {
        flag1 = 4;
        analogWrite(an1, 0);
      }

    }
    if (flag2 == 2 && c2 <= 10 && c2 >= -400) 
    {
      digitalWrite(dir2, LOW);
      analogWrite(an2, pwm-20);
  
      if (c2 <= -350 && c2 >= -400)
      {
        flag2 = 3;
      }
    }


    if (flag1 == 4&& flag2 == 3)
    {
c3=0;
c4=0;
      flagr = 7;
      analogWrite(an1, 0);
      analogWrite(an2, 0);
    }
  }
  if(flagr==7){
      if (c5 < 0)
    {
      digitalWrite(dir5, LOW);
      analogWrite(an5, pwm1-10);

    }
    if (c5 >= 0)
    {
      analogWrite(an5, 0);
      c5 = 0;
    }
    if (c6 < 0)
    {
      digitalWrite(dir6, LOW);
      analogWrite(an6, pwm1-30);

    }
    if (c6 >= 0)
    {
      analogWrite(an6, 0);
      c6 = 0;
    }

    if (flag3 == 3 && c3 <= 20 && c3 >= -1000) //1700 800
    {
      digitalWrite(dir3, LOW);
      analogWrite(an3, 255);

      if (c3 >= -1000 && c3 <= -950)
      {
        flag3 = 4;
      }
    }
    if (flag4 == 3&& c4 <= 20 && c4 >= -2340)
    {
      digitalWrite(dir4, LOW);
      analogWrite(an4, 255);

      if (c4 >= -2340 && c4 <= -2250)
      {
        flag4 = 4;
      }
    }
    if (flag4 == 4 && flag3 == 4)
    {
     
      flagr = 8;
      c1=-3200;
      c2=-3200;
      analogWrite(an3, 0);
      analogWrite(an4, 0);

    }
  }
    if(flagr==8){
          if (c5 < 0)
    {
      digitalWrite(dir5, LOW);
      analogWrite(an5, pwm1-30);

    }
    if (c5 >= 0)
    {
      analogWrite(an5, 0);
      c5 = 0;
    }
    if (c6 < 0)
    {
      digitalWrite(dir6, LOW);
      analogWrite(an6, pwm1-30);

    }
    if (c6 >= 0)
    {
      analogWrite(an6, 0);
      c6 = 0;
    }
  if (flag1 == 4 && c1 <= 10 && c1 >= -3300) //-1000
    {
      
      digitalWrite(dir1, LOW);
      analogWrite(an1, pwm+20);

      if (c1 >= -50 && c1 <= 0)
      {
        flag1 = 5;
         analogWrite(an1, 0);
      }

    }
    if(flag2==3&&c2<=10&&c2>=-3500){
      digitalWrite(dir2,HIGH);
      analogWrite(an2,pwm+20);
      if(c2>=-50&&c2<=0){
        flag2=4;
      }
    }
     if (flag1 == 5&& flag2 == 4)
    {
c5=0;
c6=0;
      flagr = 9;
      analogWrite(an1, 0);
      analogWrite(an2, 0);
      
    } 
      
    }
  /*
    if(flagr==9){
      if (c1 < 0)
    {
      digitalWrite(dir1, LOW);
      analogWrite(an1, pwm1-30);

    }
    if (c1 >= 0)
    {
      analogWrite(an1, 0);
      c1 = 0;
    }
    if (c2 < 0)
    {
      digitalWrite(dir2, HIGH);
      analogWrite(an2, pwm1-30);

    }
    if (c2 >= 0)
    {
      analogWrite(an2, 0);
      c2 = 0;
    }
    if (flag5 == 2 && c5 <= 120 && c5 >= -350)
    {
      digitalWrite(dir5, HIGH);
      analogWrite(an5, pwm);
      

      if (c5 <= -300 && c5 >= -350)
      {
        flag5 = 4;
      }
    }
   if (flag6 == 3 && c6 <= 20 && c6 >= -3000)
    {
      digitalWrite(dir6, HIGH);
      analogWrite(an6, pwm);

      if (c6 <= -2900 && c6 >= -3000)
      {
        flag6 = 4;
          
      }
    }
    if (flag5 == 4 && flag6 == 4)
    {

      c3 = -750;
      c4 = -1820;
      // c3=-1650;
      flagr = 10;
      analogWrite(an5, 0);
      analogWrite(an6, 0);
      


    }
    }
    if(flagr==10){
       if (c1 < 0)
    {
      digitalWrite(dir1, LOW);
      analogWrite(an1, pwm1-30);

    }
    if (c1 >= 0)
    {
     digitalWrite(dir1, HIGH);
    analogWrite(an1,0);
    
    
    }
    if (c2 < 0)
    {
      digitalWrite(dir2, HIGH);
      analogWrite(an2, pwm1-30);

    }
    if (c2 >= 0)
    {digitalWrite(dir2, LOW);
      analogWrite(an2, 0);
      c2=0;
   
    }
    
    if (flag3 == 4 && c3 <= 120 && c3 >= -790) //-1700  1750  *800
    {
      digitalWrite(dir3, HIGH);
      analogWrite(an3, pwm + 90);

      if (c3 >= 0 && c3 <= 120)
      {   analogWrite(an3, 0);
    
        flag3 = 5;
      }
    }
    if (flag4 == 4 && c4 <= 120 && c4 >= -1900) //-1700  800
    {
      digitalWrite(dir4, HIGH);
      analogWrite(an4, pwm + 90);

      if (c4 >= 0 && c4 <= 120)
      {   
      analogWrite(an4, 0);
        flag4 = 5;
      }
    }
    if (flag4 == 5 && flag3 == 5)
    {
     // c2=0;
    c5 = -450;
     c6 = -2300;
      flagr = 11;
      analogWrite(an3, 0);
      analogWrite(an4, 0);

    }
      
    }
 if(flagr==11){
   if (c1 < 0)
    {
      digitalWrite(dir1, LOW);
      analogWrite(an1, pwm1-30);

    }
    if (c1 >= 0)
    {
      analogWrite(an1, HIGH);
      analogWrite(an1,0);
     

    }
    if (c2 < 0)
    {
      digitalWrite(dir2, HIGH);
      analogWrite(an2, pwm1-30);

    }
    if (c2 >= 0)
    {digitalWrite(dir2, LOW);
      analogWrite(an2, 0);
     
    }
    if (flag6 == 4 && c6<= 0 && c6 >= -2400)
    {
      
      
      digitalWrite(dir6, LOW);
      analogWrite(an6, pwm-30);

      if (c6 >= -50 && c6 <= 0)
      {
        flag6 = 5;
      }
    }
      if(flag5==4&&c5<=0&&c5>=-500){
        digitalWrite(dir5,LOW);
        analogWrite(an5,33);
        if(c5>=-50&&c5<=0){
          flag5=5;
        }
      }
      if(flag5==5&&flag6==5){
        c1=0;
        c2=0;
        flagr=12;
        analogWrite(an5,0);
        analogWrite(an6,0);
    }
  
 }
 if (flagr ==12) {
    if (c5 < 0)
    {
      digitalWrite(dir5, LOW);
      analogWrite(an5, pwm1-40);

    }
    if (c5 >= 0)
    {
      
      digitalWrite(dir5, HIGH);
      analogWrite(an5, 30);
   
    }
    if (c6 < 0)
    {
      digitalWrite(dir6, LOW);
      analogWrite(an6, pwm1-30);

    }
    if (c6 >= 0)
    {
      digitalWrite(dir6, HIGH);
      analogWrite(an6, pwm1-30);
    }
  if (flag1 == 5 && c1 <= 10 && c1 >= -2900)
    {
      digitalWrite(dir1, HIGH);
      analogWrite(an1, pwm);
  

      if (c1 < -2800 && c1 >= -2900)
      {
        flag1 = 6;
        analogWrite(an1, 0);
      }

    }
    if (flag2 == 4 && c2 <= 10 && c2 >= -2800)
    {
      digitalWrite(dir2, LOW);
      analogWrite(an2, pwm-30);
  
      if (c2 <= -2700 && c2 >= -2800)
      {
        flag2 = 6;
      }
    }


    if (flag1 ==6 && flag2 == 6)
    {

      flagr =13;
      c3=0;
      c4=0;
      analogWrite(an1, 0);
      analogWrite(an2, 0);
    }
  }
 if(flagr==13){
  if (c5 < 0)
    {
      digitalWrite(dir5, LOW);
      analogWrite(an5, pwm1-10);

    }
    if (c5 >= 0)
    {
      analogWrite(an5, 0);
      c5 = 0;
    }
    if (c6 < 0)
    {
      digitalWrite(dir6, LOW);
      analogWrite(an6, pwm1-30);

    }
    if (c6 >= 0)
    {
      analogWrite(an6, 0);
      c6 = 0;
    }

    if (flag3 == 5 && c3 <= 20 && c3 >= -400) //1700 800
    {
      digitalWrite(dir3, LOW);
      analogWrite(an3, pwm + 90);

      if (c3 >= -400&& c3 <= -350)
      {
        flag3 = 6;
      }
    }
    if (flag4 == 5 && c4 <= 20 && c4 >= -1900)
    {
      digitalWrite(dir4, LOW);
      analogWrite(an4, pwm + 80);

      if (c4 >= -1900 && c4 <= -1850)
      {
        flag4 =6;
      }
    }
    if (flag4 == 6 && flag3 == 6)
    {
     // c2=0;
      flagr = 14;
      
      analogWrite(an3, 0);
      analogWrite(an4, 0);

    }
 }
  if(flagr==14){

           if (c5 < 0)
    {
      digitalWrite(dir5, LOW);
      analogWrite(an5, pwm1-30);

    }
    if (c5 >= 0)
    {
      analogWrite(an5, 0);
      c5 = 0;
    }
    if (c6 < 0)
    {
      digitalWrite(dir6, LOW);
      analogWrite(an6, pwm1-30);

    }
    if (c6 >= 0)
    {
      analogWrite(an6, 0);
      c6 = 0;
    }
  if (flag1 == 6 && c1 <= 10 && c1 >= -3000) //-1000
    {
      
      digitalWrite(dir1, LOW);
      analogWrite(an1, pwm+20);

      if (c1 >= -50 && c1 <= 0)
      {
        flag1 = 7;
         analogWrite(an1, 0);
      }

    }
    if(flag2==6&&c2<=10&&c2>=-2900){
      digitalWrite(dir2,HIGH);
      analogWrite(an2,pwm+20);
      if(c2>=-50&&c2<=0){
        flag2=7;
      }
    }
     if (flag1 == 7&& flag2 ==7)
    {
      
c5=0;
c6=0;
      flagr =15;
      analogWrite(an1, 0);
      analogWrite(an2, 0);
      
    } 
  }
  if(flagr==15){
    if (c1 < 0)
    {
      digitalWrite(dir1, LOW);
      analogWrite(an1, pwm1-30);

    }
    if (c1 >= 0)
    {
      analogWrite(an1, 0);
      c1 = 0;
    }
    if (c2 < 0)
    {
      digitalWrite(dir2, HIGH);
      analogWrite(an2, pwm1-30);

    }
    if (c2 >= 0)
    {
      analogWrite(an2, 0);
      c2 = 0;
    }
    if (flag5 == 5 && c5 <= 120 && c5 >= -250)
    {
      digitalWrite(dir5, HIGH);
      analogWrite(an5, pwm);
      

      if (c5 <= -200 && c5 >= -250)
      {
        flag5 = 6;
      }
    }
   if (flag6 ==5&& c6 <= 20 && c6 >= -3500)
    {
      digitalWrite(dir6, HIGH);
      analogWrite(an6, pwm);

      if (c6 <= -3400 && c6 >= -3500)
      {
        flag6 = 6;
          
      }
    }
    if (flag5 == 6 && flag6 == 6)
    {

      c3 = -2600;
      c4 = -2200;
      // c3=-1650;
      flagr = 16;
      analogWrite(an5, 0);
      analogWrite(an6, 0);
      


    }
  }
  if(flagr==16){
         if (c1 < 0)
    {
      digitalWrite(dir1, LOW);
      analogWrite(an1, pwm1-30);

    }
    if (c1 >= 0)
    {
     digitalWrite(dir1, HIGH);
    analogWrite(an1,0);
    
    
    }
    if (c2 < 0)
    {
      digitalWrite(dir2, HIGH);
      analogWrite(an2, pwm1-30);

    }
    if (c2 >= 0)
    {digitalWrite(dir2, LOW);
      analogWrite(an2, 0);
      c2=0;
   
    }
    
    if (flag3 == 6&& c3 <= 120 && c3 >= -2650) //-1700  1750  *800
    {
      digitalWrite(dir3, HIGH);
      analogWrite(an3, pwm + 90);

      if (c3 >= 0 && c3 <= 120)
      {   analogWrite(an3, 0);
    
        flag3 =7;
      }
    }
    if (flag4 ==6 && c4 <= 120 && c4 >= -2250) //-1700  800
    {
      digitalWrite(dir4, HIGH);
      analogWrite(an4, pwm + 90);

      if (c4 >= 0 && c4 <= 120)
      {   
      analogWrite(an4, 0);
        flag4 = 7;
      }
    }
    if (flag4 == 7 && flag3 == 7)
    {
     // c2=0;
    c5 = -3000;
     c6 = -400;
      flagr = 17;
      analogWrite(an3, 0);
      analogWrite(an4, 0);

    }
      
  }
  if(flagr==17){
      if (c1 < 0)
    {
      digitalWrite(dir1, LOW);
      analogWrite(an1, pwm1-30);

    }
    if (c1 >= 0)
    {
      analogWrite(an1, HIGH);
      analogWrite(an1,0);
     

    }
    if (c2 < 0)
    {
      digitalWrite(dir2, HIGH);
      analogWrite(an2, pwm1-30);

    }
    if (c2 >= 0)
    {digitalWrite(dir2, LOW);
      analogWrite(an2, 0);
     
    }
    if (flag6 == 6 && c6<= 0 && c6 >= -500)
    {
      
      
      digitalWrite(dir6, LOW);
      analogWrite(an6, pwm-30);

      if (c6 >= -50 && c6 <= 0)
      {
        flag6 = 7;
      }
    }
      if(flag5==6&&c5<=0&&c5>=-3200){
        digitalWrite(dir5,LOW);
        analogWrite(an5,pwm+20);
        if(c5>=-50&&c5<=0){
          flag5=7;
        }
      }
      if(flag5==7&&flag6==7){
        c1=0;
        c2=0;
        flagr=18;
        analogWrite(an5,0);
        analogWrite(an6,0);
    }
  
    
  }
  if(flagr==18){
     if (c5 < 0)
    {
      digitalWrite(dir5, LOW);
      analogWrite(an5, pwm1-40);

    }
    if (c5 >= 0)
    {
      
      digitalWrite(dir5, HIGH);
      analogWrite(an5, 30);
   
    }
    if (c6 < 0)
    {
      digitalWrite(dir6, LOW);
      analogWrite(an6, pwm1-30);

    }
    if (c6 >= 0)
    {
      digitalWrite(dir6, HIGH);
      analogWrite(an6, pwm1-30);
    }
  if (flag1 == 7 && c1 <= 10 && c1 >= -3800)
    {
      digitalWrite(dir1, HIGH);
      analogWrite(an1, pwm);
  

      if (c1 < -3750 && c1 >= -3800)
      {
        flag1 = 8;
        analogWrite(an1, 0);
      }

    }
    if (flag2 == 7 && c2 <= 10 && c2 >= -1900)
    {
      digitalWrite(dir2, LOW);
      analogWrite(an2, pwm-30);
  
      if (c2 <= -1850 && c2 >= -1900)
      {
        flag2 = 8;
      }
    }


    if (flag1 == 8 && flag2 == 8)
    {
c3=0;
c4=0;
      flagr = 19;
      analogWrite(an1, 0);
      analogWrite(an2, 0);
    }
    
  }
  if(flagr==19){
    if (c5 < 0)
    {
      digitalWrite(dir5, LOW);
      analogWrite(an5, pwm1-10);

    }
    if (c5 >= 0)
    {
      analogWrite(an5, 0);
      c5 = 0;
    }
    if (c6 < 0)
    {
      digitalWrite(dir6, LOW);
      analogWrite(an6, pwm1);

    }
    if (c6 >= 0)
    {
      analogWrite(an6, 0);
      c6 = 0;
    }

    if (flag3 == 7 && c3 <= 20 && c3 >= -1600) //1700 800
    {
      digitalWrite(dir3, LOW);
      analogWrite(an3, pwm + 90);

      if (c3 >= -1600 && c3 <= -1550)
      {
        flag3 = 8;
      }
    }
    if (flag4 == 7 && c4 <= 20 && c4 >= -2000)
    {
      digitalWrite(dir4, LOW);
      analogWrite(an4, pwm + 80);

      if (c4 >= -2000 && c4 <= -1950)
      {
        flag4 = 8;
      }
    }
    if (flag4 == 8 && flag3 == 8)
    {
      c1=-350;
      flagr = 20;
      c2=-1000;
      analogWrite(an3, 0);
      analogWrite(an4, 0);

    }
  }
  while(flagr==20){
 

           if (c5 < 0)
    {
      digitalWrite(dir5, LOW);
      analogWrite(an5, pwm1-30);

    }
    if (c5 >= 0)
    {
      analogWrite(an5, 0);
      c5 = 0;
    }
    if (c6 < 0)
    {
      digitalWrite(dir6, LOW);
      analogWrite(an6, pwm1-30);

    }
    if (c6 >= 0)
    {
      analogWrite(an6, 0);
      c6 = 0;
    }
  if (flag1 == 8 && c1 <= 10 && c1 >= -400) //-1000
    {
      
      digitalWrite(dir1, LOW);
      analogWrite(an1, pwm+20);

      if (c1 >= -50 && c1 <= 0)
      {
        flag1 = 9;
         analogWrite(an1, 0);
      }

    }
    if(flag2==8&&c2<=10&&c2>=-1000){
      digitalWrite(dir2,HIGH);
      analogWrite(an2,pwm+20);
      if(c2>=-150&&c2<=0){
          analogWrite(an2, 0);
        flag2=9;
      }
    }
     if (flag1 == 9&& flag2 == 9)
    {

c5=0;
c6=0;
c1=0;
c2=0;
 int i=0;
       while (i == 0) {
    if (c6 > -100 && c6 <501) {

      digitalWrite(dir6, LOW);
      analogWrite(an6, 130);
    }
    if (c1 > -150&& c1< 805) {
 
      digitalWrite(dir1, LOW);
      analogWrite(an1, 130);
    }
   
     else
    {
      digitalWrite(dir2, HIGH);
      analogWrite(an2, 0);
      digitalWrite(dir5, HIGH);
      analogWrite(an5, 0);
      digitalWrite(dir6, HIGH);
      analogWrite(an6, 0);
      digitalWrite(dir1, HIGH);
      analogWrite(an1, 0);
 
      i = 2;
      c1 = 0;
      c2 = 0;
      c3 = 0;
      c4 = 0;
      c5 = 0;
      c6 = 0;
   
    }}
      flagr = 21;
      analogWrite(an1, 0);
      analogWrite(an2, 0);
      
    } 
      
  }

  if(flagr==21){
 
     if (c1 < 0)
    {
      digitalWrite(dir1, LOW);
      analogWrite(an1, pwm1-50);

    }
    if (c1 >= 0)
    {digitalWrite(dir1, HIGH);
      analogWrite(an1, 20);
   
    }
    
    if (c2 < 0)
    {
      digitalWrite(dir2, HIGH);
      analogWrite(an2, pwm1-30);

    }
    if (c2 >= 0)
    {
      analogWrite(an2, 0);
      c2 = 0;
    }
 
     
    
    
 if (flag5 == 7&& c5 <= 120 && c5 >= -2300)
    {
      digitalWrite(dir5, HIGH);
      analogWrite(an5, pwm+10);

      if (c5 <= -2240 && c5 >= -2300)
      {
        flag5 = 8;
        analogWrite(an5,0);
      }
    }
 if(flag6 == 7 && c6 <= 20 && c6 >= -1500)
    {
      digitalWrite(dir6, HIGH);
      analogWrite(an6, pwm-20);
    

      if (c6 <= -1450 && c6 >= -1500)
      {
        flag6 = 8;
          analogWrite(an6, 0);
      }
    }
    if (flag5 == 8 && flag6 ==8)
    {

      c3 = -1950;
      c4 = -400;
      // c3=-1650;
      flagr =22;
      analogWrite(an5, 0);
      analogWrite(an6, 0);


    }
}
/*while(flagr==22){
  c1=0;
  c2=0;
  c5=0;
  c6=0;

  int j=0;
  while(j==0){
    if(c1<=500&&c1>=-10){
 digitalWrite(dir1, LOW);
      analogWrite(an1, 130);
      
    }
    if(c2<=1000&&c2>=-10){
       digitalWrite(dir2, HIGH);
      analogWrite(an2, 130);
      
    }
    if(c5<=1000&&c5>=-10){
       digitalWrite(dir5, LOW);
      analogWrite(an5, 130);
    }
    if(c6<=500&&c6>=-10){
             digitalWrite(dir6, LOW);
      analogWrite(an6, 130);
    }
    else{
      digitalWrite(dir2, HIGH);
      analogWrite(an2, 0);
      digitalWrite(dir5, HIGH);
      analogWrite(an5, 0);
      digitalWrite(dir6, HIGH);
      analogWrite(an6, 0);
      digitalWrite(dir1, HIGH);
      analogWrite(an1, 0);
     j = 2;
     flagr=23;
      c1 = 0;
      c2 = 0;
      c3 = 0;
      c4 = 0;
      c5 = 0;
      c6 = 0;
    }
  }
  flagr=23;
}


/*
if(flagr==22){
    if (c1 < 0)
    {
      digitalWrite(dir1, LOW);
      analogWrite(an1, pwm1-30);

    }
    if (c1 >= 0)
    {
      analogWrite(an1, 0);
      c1 = 0;
    }
    if (c2 < 0)
    {
      digitalWrite(dir2, HIGH);
      analogWrite(an2, pwm1-30);

    }
    if (c2 >= 0)
    {
      analogWrite(an2, 0);
      c2 = 0;
    }
    if (flag3 == 8 && c3 <= 20 && c3 >= -2000) //-1700  1750  *800
    {
      digitalWrite(dir3, HIGH);
      analogWrite(an3, pwm + 90);

      if (c3 >= 0 && c3 <= 20)
      {
        flag3 = 9;
        analogWrite(an3,0);
      }
    }
    if (flag4 == 8 && c4 <= 20 && c4 >= -400) //-1700  800
    {
      digitalWrite(dir4, HIGH);
      analogWrite(an4, pwm + 80);

      if (c4 >= 0 && c4 <= 20)
      {
        flag4 = 9;
        analogWrite(an4,0);
      }
    }
    if (flag4 == 9 && flag3 == 9)
    {
      c1=0;
c2=0;
   c5 = -2500;
     c6 =-950;
      flagr = 23;
      analogWrite(an3, 0);
      analogWrite(an4, 0);

    }
}
if(flagr==23){
   if (c1 < 0)
    {
      digitalWrite(dir1, LOW);
      analogWrite(an1, pwm1-30);

    }
    if (c1 >= 0)
    {
      analogWrite(an1, HIGH);
      analogWrite(an1,10);
     

    }
    if (c2 < 0)
    {
      digitalWrite(dir2, HIGH);
      analogWrite(an2, pwm1-30);

    }
    if (c2 >= 0)
    {digitalWrite(dir2, LOW);
      analogWrite(an2, 0);
     
    }
    if (flag6 == 8 && c6<= 0 && c6 >= -1000)
    {
      
      
      digitalWrite(dir6, LOW);
      analogWrite(an6, pwm-30);

      if (c6 >= -50 && c6 <= 0)
      {
        flag6 = 9;
        analogWrite(an6,0);
 
        }     }
    
      if(flag5==8&&c5<=0&&c5>=-2600){
        digitalWrite(dir5,LOW);
        analogWrite(an5,100);
        if(c5>=-50&&c5<=0){
          flag5=9;
          analogWrite(an5,0);
      }}
      if(flag5==9&&flag6==9){
       c5=0;
c6=0;
c1=0;
c2=0;
 int i=0;
       while (i == 0) {
        if(c2>=0&&c2<=900){
           digitalWrite(dir2, HIGH);
      analogWrite(an2,100);
        }
        if(c5>=0&&c5<=400){
                digitalWrite(dir5, LOW);
      analogWrite(an5, 130);
        }
    if (c6<=0 && c6>-300) {

      digitalWrite(dir6, HIGH);
      analogWrite(an6, 130);
    }
    if (c1<=0&& c1>=-600) {
 
      digitalWrite(dir1, HIGH);
      analogWrite(an1, 130);
    }
   
     else
    {
      digitalWrite(dir2, HIGH);
      analogWrite(an2, 0);
      digitalWrite(dir5, HIGH);
      analogWrite(an5, 0);
      digitalWrite(dir6, HIGH);
      analogWrite(an6, 0);
      digitalWrite(dir1, HIGH);
      analogWrite(an1, 0);
 flagr=24;
      i = 2;
      c1 = 0;
      c2 = 0;
      c3 = 0;
      c4 = 0;
      c5 = 0;
      c6 = 0;
   
    }}
    c1=0;
    c2=0;
        flagr=24;
        analogWrite(an5,0);
        analogWrite(an6,0);
    }
  
}
if(flagr==24){
       if (c5 < 0)
                                           {
                                        digitalWrite(dir5, LOW);
                                       analogWrite(an5, 19);

                                             }
                                    if (c5 >= 0)
                                           {
      
                                     digitalWrite(dir5, HIGH);
                                     analogWrite(an5,19);
   
                                            }
                                   if (c6 < 0)
                                         {
                                    digitalWrite(dir6, LOW);
                                    analogWrite(an6, pwm1-30);

                                          }
                                   if (c6 >= 0)
                                       {
                                  digitalWrite(dir6, HIGH);
                                  analogWrite(an6, pwm1-30);
                                       }
                                   if (flag1 == 9 && c1 <= 10 && c1 >= -1000)
                                     {
                                 digitalWrite(dir1, HIGH);
                                 analogWrite(an1, pwm);
  

                               if (c1 < -950 && c1 >= -1000)
                                      {
                                     flag1 = 10;
               
                                     analogWrite(an1, 0);
                                       }

                                    }
                               if (flag2 == 9 && c2 <= 10 && c2 >= -1900)
                 
                                  {
                                  digitalWrite(dir2, LOW);
                                 analogWrite(an2, pwm-30);
  
                                 if (c2 <= -1850 && c2 >= -1900)
                                {
                               flag2 = 10;
                               analogWrite(an2,0);
                                      }
                                    }


                             if (flag1 == 10 && flag2 == 10)
                                  {

                                 flagr = 25;
                                 c3=0;
                                 c4=0;
                           analogWrite(an1, 0);
                           analogWrite(an2, 0);
                                    }
  
  
  
}
if(flagr==25){
   if (c5 < 0)
    {
      digitalWrite(dir5, LOW);
      analogWrite(an5, 20);

    }
    if (c5 >= 0)
    {
      analogWrite(an5, 0);
      c5 = 0;
    }
    if (c6 < 0)
    {
      digitalWrite(dir6, LOW);
      analogWrite(an6, 20);

    }
    if (c6 >= 0)
    {
      analogWrite(an6, 0);
      c6 = 0;
    }

    if (flag3 == 9 && c3 <= 20 && c3 >= -400) //1700 800
    {
      digitalWrite(dir3, LOW);
      analogWrite(an3, pwm + 90);

      if (c3 >= -400 && c3 <= -350)
      {
        flag3 = 10;
        analogWrite(an3,0);
      }
    }
    if (flag4 == 9 && c4 <= 20 && c4 >= -700)
    {
      digitalWrite(dir4, LOW);
      analogWrite(an4, pwm +45);

      if (c4 >= -700 && c4 <= -650)
      {
        flag4 = 10;
        analogWrite(an4,0);
      }
    }
    if (flag4 == 10 && flag3 == 10)
    {
      c2=-700;
      c1=-140;
      flagr = 26;
      
      analogWrite(an3, 0);
      analogWrite(an4, 0);

    }
  
}
///////////////////////////////////****************************************checked*****************************************//////////////////////////////////////////////////////////////////////
/*while(flagr==26){
         if (c5 < 0)
    {
      digitalWrite(dir5, LOW);
      analogWrite(an5, pwm1-30);

    }
    if (c5 >= 0)
    {
      analogWrite(an5, 0);
      c5 = 0;
    }
    if (c6 < 0)
    {
      digitalWrite(dir6, LOW);
      analogWrite(an6, pwm1-30);

    }
    if (c6 >= 0)
    {
      analogWrite(an6, 0);
      c6 = 0;
    }
  if (flag1 ==10 && c1 <= 10 && c1 >= -500) //-1000
    {
      
      digitalWrite(dir1, LOW);
      analogWrite(an1, pwm+20);

      if (c1 >= -50 && c1 <= 0)
      {
        flag1 = 11;
         analogWrite(an1, 0);
      }
  }
    if(flag2==10&&c2<=10&&c2>=-900){
      digitalWrite(dir2,HIGH);
      analogWrite(an2,pwm+20);
      if(c2>=-50&&c2<=0){
        flag2=11;
        analogWrite(an2,0);
      }
    }
     if (flag1 == 11&& flag2 ==11)
    {
      analogWrite(an2,0);
      analogWrite(an1,0);
c5=0;
c6=0;
       c5=0;
c6=0;
c1=0;
c2=0;
 int i=0;
       while (i == 0) {
  /*  if (c6>=-10 && c6<=600) {

      digitalWrite(dir6, LOW);
      analogWrite(an6, 130);
    }
    if (c5>=0&& c5<=900) {
 
      digitalWrite(dir5, HIGH);
      analogWrite(an5, 130);
    }
   if(c2>=0&&c2<=900){
    digitalWrite(dir2,HIGH);
    analogWrite(an2,100);
   }
     else
    {
      digitalWrite(dir2, HIGH);
      analogWrite(an2, 0);
      digitalWrite(dir5, HIGH);
      analogWrite(an5, 0);
      digitalWrite(dir6, HIGH);
      analogWrite(an6, 0);
      digitalWrite(dir1, HIGH);
      analogWrite(an1, 0);
 
      i = 2;
      c1 = 0;
      c2 = 0;
      c3 = 0;
      c4 = 0;
      c5 = 0;
      c6 = 0;
      flagr=27;
   
    }}
    c5=0;
    c6=0;
    flagr =27;
      analogWrite(an1, 0);
      analogWrite(an2, 0);
      
    } 
  
}

  
  while(flagr == 27)
  {
    if (c1 < 0)
    {
      digitalWrite(dir1, LOW);
      analogWrite(an1, pwm1-30);

    }
    if (c1 >= 0)
    {
      analogWrite(an1, 0);
      c1 = 0;
    }
    if (c2 < 0)
    {
      digitalWrite(dir2, HIGH);
      analogWrite(an2, pwm1-30);

    }
    if (c2 >= 0)
    {
      digitalWrite(dir2,HIGH);
      analogWrite(an2, 20);
     
    }
    if (flag5 == 9&& c5 <= 120 && c5 >= -2000)
    {
      digitalWrite(dir5, HIGH);
      analogWrite(an5, pwm);
      

      if (c5 <= -1960 && c5 >= -2000)
      {
        flag5 =10;
        analogWrite(an5,0);
      }
    }
   if (flag6 ==9 && c6 <= 20 && c6 >= -1100)
    {
      digitalWrite(dir6, HIGH);
      analogWrite(an6, pwm+10);

      if (c6 <= -1050 && c6 >= -1100)
      {
        flag6 = 10;
          analogWrite(an6, 0);
      }
    }
    if (flag5 == 10 && flag6 == 10)
    {

      c3 = -1000;
      c4 = -2300;
      // c3=-1650;
      flagr =28;
      analogWrite(an5, 0);
      analogWrite(an6, 0);


    }
  }
///////////////////////////////////////////////////**********************************checked****************************************////////////////////////////////////////////
 /*
   if(flagr==28){
     if (c1 < 0)
    {
      digitalWrite(dir1, LOW);
      analogWrite(an1, pwm1-30);

    }
    if (c1 >= 0)
    {
      analogWrite(an1, 0);
      c1 = 0;
    }
    if (c2 < 0)
    {
      digitalWrite(dir2, HIGH);
      analogWrite(an2, pwm1-30);

    }
    if (c2 >= 0)
    {
      analogWrite(an2, 0);
      c2 = 0;
    }
    if (flag3 == 10 && c3 <= 20 && c3 >= -2400) //-1700  1750  *800
    {
      digitalWrite(dir3, HIGH);
      analogWrite(an3, pwm + 90);

      if (c3 >= 0 && c3 <= 20)
      {
        flag3 = 11;
      }
    }
    if (flag4 == 10 && c4 <= 20 && c4 >= -2300) //-1700  800
    {
      digitalWrite(dir4, HIGH);
      analogWrite(an4, pwm + 80);

      if (c4 >= 0 && c4 <= 20)
      {
        flag4 = 11;
      }
    }
    if (flag4 == 11 && flag3 == 11)
    {
c2=0;
      c5 = -2000;
      c6 = -2100;
      flagr = 29;
      analogWrite(an3, 0);
      analogWrite(an4, 0);

    }
   }
  
  ////////////////////////*************************checked********************************//////////////////////////////////
/*  if(flagr==29){
      if (c1 < 0)
    {
      digitalWrite(dir1, LOW);
      analogWrite(an1, pwm1-30);

    }
    if (c1 >= 0)
    {
      analogWrite(an1, HIGH);
      analogWrite(an1,0);
     

    }
    if (c2 < 0)
    {
      digitalWrite(dir2, HIGH);
      analogWrite(an2, pwm1-30);

    }
    if (c2 >= 0)
    {digitalWrite(dir2, LOW);
      analogWrite(an2, 0);
     
    }
    if (flag6 == 10 && c6<= 0 && c6 >= -2400)
    {
      
      
      digitalWrite(dir6, LOW);
      analogWrite(an6, pwm-30);

      if (c6 >= -50 && c6 <= 0)
      {
        flag6 =11;
      }
    }
      if(flag5==10&&c5<=0&&c5>=-2000){
        digitalWrite(dir5,LOW);
        analogWrite(an5,100);
        if(c5>=-50&&c5<=0){
          flag5=11;
        }
      }
      if(flag5==11&&flag6==11){
        c1=0;
        c2=0;
        flagr=30;
        analogWrite(an5,0);
        analogWrite(an6,0);
    }
  
  }
  if(flagr==30){
         if (c5 < 0)
                                           {
                                        digitalWrite(dir5, LOW);
                                       analogWrite(an5, pwm1-40);

                                             }
                                    if (c5 >= 0)
                                           {
      
                                     digitalWrite(dir5, HIGH);
                                     analogWrite(an5, 30);
   
                                            }
                                   if (c6 < 0)
                                         {
                                    digitalWrite(dir6, LOW);
                                    analogWrite(an6, pwm1-30);

                                          }
                                   if (c6 >= 0)
                                       {
                                  digitalWrite(dir6, HIGH);
                                  analogWrite(an6, pwm1-30);
                                       }
                                   if (flag1 == 11 && c1 <= 100 && c1 >= -1000)
                                     {
                                 digitalWrite(dir1, HIGH);
                                 analogWrite(an1, pwm-20);
  

                               if (c1 < -950 && c1 >= -1000)
                                      {
                                     flag1 = 12;
                                     analogWrite(an1, 0);
                                       }

                                    }
                               if (flag2 == 11&& c2 <= 100 && c2 >= -1900)
                                  {
                                  digitalWrite(dir2, LOW);
                                 analogWrite(an2, pwm-30);
  
                                 if (c2 <= -1850 && c2 >= -1900)
                                {
                               flag2 = 12;
                                      }
                                    }


                             if (flag1 == 12 && flag2 == 12)
                                  {
c3=0;
c4=0;
                                 flagr = 31;
                           analogWrite(an1, 0);
                           analogWrite(an2, 0);
                                    }
    
  }
  if(flagr==31){
    if (c5 < 0)
    {
      digitalWrite(dir5, LOW);
      analogWrite(an5, pwm1-10);

    }
    if (c5 >= 0)
    {
      analogWrite(an5, 0);
      c5 = 0;
    }
    if (c6 < 0)
    {
      digitalWrite(dir6, LOW);
      analogWrite(an6, pwm1-30);

    }
    if (c6 >= 0)
    {
      analogWrite(an6, 0);
      c6 = 0;
    }

    if (flag3 == 11&& c3 <= 20 && c3 >= -1900) //1700 800
    {
      digitalWrite(dir3, LOW);
      analogWrite(an3, pwm+60);

      if (c3 >= -1900 && c3 <= -1850)
      {
        flag3 =12;
      }
    }
    if (flag4 == 11 && c4 <= 20 && c4 >= -2400)
    {
      digitalWrite(dir4, LOW);
      analogWrite(an4, pwm+60 );

      if (c4 >= -2300 && c4 <= -2250)
      {
        flag4 = 12;
      }
    }
    if (flag4 == 12 && flag3 == 12)
    {
      c2=-2100;
      c1=-3000;
      flagr = 32;
      
      analogWrite(an3, 0);
      analogWrite(an4, 0);

    }
  }
  if(flagr==32){
      if (c5 < 0)
    {
      digitalWrite(dir5, LOW);
      analogWrite(an5, pwm1-30);

    }
    if (c5 >= 0)
    {
      analogWrite(an5, 0);
      c5 = 0;
    }
    if (c6 < 0)
    {
      digitalWrite(dir6, LOW);
      analogWrite(an6, pwm1-30);

    }
    if (c6 >= 0)
    {
      analogWrite(an6, 0);
      c6 = 0;
    }
  if (flag1 == 12 && c1 <= 10 && c1 >= -3300) //-1000
    {
     
      digitalWrite(dir1, LOW);
      analogWrite(an1, pwm-20);

      if (c1 >= -50 && c1 <= 0)
      {
        flag1 = 13;
         analogWrite(an1, 0);
      }

    }
    if(flag2==12&&c2<=10&&c2>=-2200){
      digitalWrite(dir2,HIGH);
      analogWrite(an2,pwm-20);
      if(c2>=-50&&c2<=0){
        flag2=13;
      }
    }
     if (flag1 == 13&& flag2 == 13)
    {
c5=0;
c6=0;
      flagr =   33;
      analogWrite(an1, 0);
      analogWrite(an2, 0);
      
    } 
      
  }
  /*
  if(flagr==20){
     if (c1 < 0)
    {
      digitalWrite(dir1, LOW);
      analogWrite(an1, pwm1-30);

    }
    if (c1 >= 0)
    {
      analogWrite(an1, 0);
      c1 = 0;
    }
    if (c2 < 0)
    {
      digitalWrite(dir2, HIGH);
      analogWrite(an2, pwm1-30);

    }
    if (c2 >= 0)
    {      digitalWrite(dir2, LOW);
      analogWrite(an2,30);
      
    }
    if (flag5 == 7 && c5 <= 120 && c5 >= -1900)
    {
      digitalWrite(dir5, HIGH);
      analogWrite(an5, pwm);
      

      if (c5 <= -1850 && c5 >= -1900)
      {
        flag5 = 8;
      }
    }
   if (flag6 ==7&& c6 <= 20 && c6 >= -400)
    {
      digitalWrite(dir6, HIGH);
      analogWrite(an6, pwm);

      if (c6 <= -340&& c6 >= -400)
      {
        flag6 = 8;
          
      }
    }
    if (flag5 ==8 && flag6 ==8)
    {

      c3 = -2600;
      c4 = -2200;
      // c3=-1650;
      flagr = 21;
      analogWrite(an5, 0);
      analogWrite(an6, 0);
      


    }
    
    
  }
    /*if (flag6 == 2 && c6 <= 0 && c6 >= -1200)
    {
      digitalWrite(dir6, LOW);
      analogWrite(an6, pwm+10);

      if (c6 >= -50 && c6 <= 0)
      {
        flag6 = 3;
      }
    }
    if (flag5 == 3/* && flag6 == 3)
    {


      flagr = 6;
      analogWrite(an5, 0);
      analogWrite(an6, 0);


    }
  }
  if (flagr == 6)
  {
    c1 = 0;
    c2 = 0;
    c3 = 0;
    c4 = 0;
    c5 = 0;
    c6 = 0;


    flag1 = 1;
    flag2 = 1;
    flag3 = 1;
    flag4 = 1;
    flag5 = 1;
    flag6 = 1;
    flagr = 0;
  }*/
}

void initi1() {
  int i = 0;

  digitalWrite(dir2, LOW);
  digitalWrite(dir1, HIGH);
  digitalWrite(dir5, HIGH);
  digitalWrite(dir6, HIGH);
  digitalWrite(dir3, HIGH);
  digitalWrite(dir4, HIGH);
  analogWrite(an2, 140);
  analogWrite(an1, 140);
  analogWrite(an5, 140);
  analogWrite(an6, 140);
  //  analogWrite(an3,100);
  // analogWrite(an4,100);
  delay(2000);
  analogWrite(an4, 0);
  analogWrite(an3, 0);
  analogWrite(an5, 0);
  analogWrite(an6, 0);
  analogWrite(an1, 0);
  analogWrite(an2, 0);
  c1 = 0;
  c2 = 0;
  c3 = 0;
  c4 = 0;
  c5 = 0;
  c6 = 0;
  delay(500);
 c1 = 0;
  c2 = 0;
  c3 = 0;
  c4 = 0;
  c5 = 0;
  c6 = 0;
  i=0;
  while ( i == 0) {
    if (c6 >= -100 && c6 < 3700) {
      digitalWrite(dir6, LOW);
      analogWrite(an6, 230);
      if(c6>3600){
           digitalWrite(dir6, 1);
      analogWrite(an6, 0);
      }
    }

    if (c5 > -100 && c5 < 3700) {
      digitalWrite(dir5, 1);
      analogWrite(an5, 230);
      if(c5>3500){
        
        analogWrite(an5, 0);
      }
    }
  /* 
    }*/

     if(c5>3000&&c6>3000)
    {
      digitalWrite(dir2, HIGH);
      analogWrite(an2, 0);
      digitalWrite(dir5, HIGH);
      analogWrite(an5, 0);
      digitalWrite(dir6, HIGH);
      analogWrite(an6, 0);
      digitalWrite(dir1, HIGH);
      analogWrite(an1, 0);
      i = 2;
      c1 = 0;
      c2 = 0;
      c3 = 0;
      c4 = 0;
      c5 = 0;
      c6 = 0;
    }
  }
      digitalWrite(dir3, HIGH);
    analogWrite(an3, 109);
    digitalWrite(dir4, HIGH);
    analogWrite(an4, 100);
    delay(2000);

    digitalWrite(dir3, HIGH);
    analogWrite(an3, 0);
    digitalWrite(dir4, HIGH);
    analogWrite(an4, 0);

  int j = 1;
  c1 = 0;
  c2 = 0;
  c3=0;
  c4=0;
 /* while (j == 0) {
    if (c5 < 10 && c5> -3509) {

      digitalWrite(dir1, LOW);
      analogWrite(an1, 110);
    }
    if (c6< 10 && c6 > -3509) {


      digitalWrite(dir2, HIGH);
      analogWrite(an2, 110);
    }
    else
    { j = 1;
      c1 = 0; c2 = 0;
      analogWrite(an2, 0);
      analogWrite(an1, 0);
      delay(1000);
    }
  }
*/

  while (j == 1) {
     if(c5<0)
    {
      digitalWrite(dir5,LOW);
      analogWrite(an5,pwm1+10);
      c5=0;
      
    }
    if(c5>=0)
    {digitalWrite(dir5,HIGH);
      analogWrite(an5,20);
      
 c5=0;
    }
    if(c6<0)
    {
      digitalWrite(dir6,LOW);
      analogWrite(an6,pwm1-30);
      
    }
    if(c6>=0)
    {digitalWrite(dir6,HIGH);
      analogWrite(an6,40);
      c6=0;
    }


    

     if (c2 > -100 && c2 < 3005) {
      digitalWrite(dir2, HIGH);
      analogWrite(an2, 200);
      if(c2>3000){
           digitalWrite(dir2, LOW);
      analogWrite(an2, 0);
      }
    }
   if (c1 > -100&& c1 < 3005) {
      digitalWrite(dir1, LOW);
      analogWrite(an1, 200);
      if(c1>2900){
         digitalWrite(dir1, LOW);
      analogWrite(an1, 0);
      }}
    if(c1>2900&&c2>3000){//&&c3<-400&&c4<-400
      j=2;
      c1=0;
      c2=0;
      c3=0;
   c4=0;
      
    }

  }
/*  int x = 1;
  while (x == 1) {
    if (c5 > -3500 && c1 < 10) {
      digitalWrite(dir5, LOW);
      analogWrite(an5, 90);
    }
    else if (c6 > -3500 && c2 < 10) {


      digitalWrite(dir6, HIGH);
      analogWrite(an6, 90);
    }
    else
    { x = 2;
      digitalWrite(dir6, LOW);
      analogWrite(an6, 90);
      digitalWrite(dir5, LOW);
      analogWrite(an5, 90);
      delay(200);
      c1 = 0;+
      c2 = 0;
      c3 = 0;
      c4 = 0;
      c5 = 0;
      c6 = 0; 
      analogWrite(an2, 0);
      analogWrite(an1, 0);
      analogWrite(an6, 0);
      digitalWrite(dir5, LOW);
      analogWrite(an5, 0);
      //delay(2000);
    }
  }*/
  
  c1 = 0;
  c2 = 0;
  c3 = 0;
  c4 = 0;
  c5 = 0;
  c6 = 0;

}

void motion2(){
  
  if(flagr==0){
    if(c5<0)
    {
      digitalWrite(dir5,LOW);
      analogWrite(an5,pwm1+10);
      c5=0;
      
    }
    if(c5>=0)
    {digitalWrite(dir5,HIGH);
      analogWrite(an5,20);
      
 c5=0;
    }
    if(c6<0)
    {
      digitalWrite(dir6,LOW);
      analogWrite(an6,pwm1-30);
      
    }
    if(c6>=0)
    {digitalWrite(dir6,HIGH);
      analogWrite(an6,40);
      c6=0;
    }
    
 //c1 c2 be the leg motor of one diagonal
if(flag1s==1&&c1<=50&&c1>=-2100)
 {
  digitalWrite(dir1,HIGH);
  analogWrite(an1,180);
 if(c1<-2000&&c1>=-2100)
 {
  flag1s=2;
    analogWrite(an1,0);
 }
 
 }
 if(flag2s==1&&c2<=50&&c2>=-2100)
 {
  digitalWrite(dir2,LOW);
  analogWrite(an2,180);
 
  if(c2<=-2000&&c2>=-2100)
 {
  flag2s=2;
    analogWrite(an2,0);
    
 }
 }
 
 
 if(flag1s==2&&flag2s==2)
 {
  c3=0;
  c4=0;
  flagr=1;
  analogWrite(an1,0);
  analogWrite(an2,0);
 }
}
/*
if(flagr==1)
{
   if(c5<0)
    {
      digitalWrite(dir5,LOW);
      analogWrite(an5,pwm1-30);
      
    }
    if(c5>=0)
    {
      digitalWrite(dir5,1);
      analogWrite(an5,0);
      
    //  c5=0;
    }
    if(c6<0)
    {
      digitalWrite(dir6,LOW);
      analogWrite(an6,pwm1-30);
      
    }
    if(c6>=0)
    {digitalWrite(dir6,1);
    
      analogWrite(an6,0);
      c6=0;
    }
    
  if(flag3s==1&&c3<=20&&c3>=-15000)  //1700 800    -1000
  {
    digitalWrite(dir3,LOW);
    analogWrite(an3,160);

    if(c3>=-15000&&c3<=-10900)
    {
      analogWrite(an3,0);
      flag3s=2;
    }
  }
  if(flag4s==1&&c4<=20&&c4>=-17000)
  {
    digitalWrite(dir4,LOW);
    analogWrite(an4,160);

    if(c4>=-17000&&c4<=-13900)
    {analogWrite(an4,0);
      flag4s=2;
    }
  }
  if(flag4s==2&&flag3s==2)
  {
    c2=-2100;
    c1=-2100;
    flagr=2;
    flag5s=1;
    flag6s=1;
    analogWrite(an3,0);
    analogWrite(an4,0);
    
  }
}

if(flagr==2)
{
    if(c5<0)
    {
      digitalWrite(dir5,LOW);
      analogWrite(an5,pwm1-30);
      
    }
    if(c5>=0)
    {
      digitalWrite(dir5,1);
      analogWrite(an5,40);
      
    }
    if(c6<0)
    {
      digitalWrite(dir6,LOW);
      analogWrite(an6,pwm1-30);
      
    }
    if(c6>=0)
    {
      analogWrite(an6,0);
      c6=0;
    }
   if(flag1s==2&&c1<=0&&c1>=-3200)  //-1000
 {
  digitalWrite(dir1,LOW);
  analogWrite(an1,180);


 if(c1>=-100&&c1<=100)
 {
  flag1s=3;
  analogWrite(an1,0);
 }
 
 }
  if(flag2s==2&&c2<=0&&c2>=-3200)  //-1000
 {
  digitalWrite(dir2,HIGH);
  analogWrite(an2,180);
    

  if(c2>=-100&&c2<=100)
 {
  flag2s=3;
  analogWrite(an2,0);
 }
 
 
 if(flag1s==3&&flag2s==3)
 {
    c5=0;
  c6=0;



  analogWrite(an1,0);
  analogWrite(an2,0);
 }
 
}
}
/*
if(flagr==3)
{
   if(c1<0)
    {
      digitalWrite(dir1,LOW);
      analogWrite(an1,pwm1+35);
      
    }
    if(c1>=0)
    {
      digitalWrite(dir1,HIGH);
      analogWrite(an1,45);
    
    }
    if(c2<0)
    {
      digitalWrite(dir2,HIGH);
      analogWrite(an2,pwm1-10);
      
    }
    if(c2>=0)
    {
      digitalWrite(dir2,0);
      analogWrite(an2,40);
     //   analogWrite(an2,0);
     // c2=0;
    }
  if(flag5s==1&&c5<=100&&c5>=-2100)
  {
    digitalWrite(dir5,HIGH);
    analogWrite(an5,180);

    if(c5<=-2000&&c5>=-2100)
    {
      flag5s=2;
      analogWrite(an5,0);
    }
  }
  if(flag6s==1&&c6<=2220&&c6>=-2100)
  {
    digitalWrite(dir6,HIGH);
    analogWrite(an6,180);
 
    if(c6<=-2000&&c6>=-2100)
    {
      
    analogWrite(an6,0);
      flag6s=2;
    }
  }
  if(flag5s==2&&flag6s==2)
  {
    
    c3=-1300;
    c4=-1700;
   // c3=-1650;
    flagr=4;
    analogWrite(an5,0);
    analogWrite(an6,0);
    
    
  }
}
if(flagr==4)
{ 
 if(c1<0)
    {
      digitalWrite(dir1,LOW);
      analogWrite(an1,pwm1);
      
    }
    if(c1>=0)
    {
      digitalWrite(dir1,1);
      analogWrite(an1,30);
      
    }
    if(c2<0)
    {
      digitalWrite(dir2,HIGH);
      analogWrite(an2,pwm1);
      
    }
    if(c2>=0)
    { digitalWrite(dir2,0);
      analogWrite(an2,50);
     // c2=0;
    }
   if(flag3s==2&&c3<=20&&c3>=-2000)  //-1700  1750  *800
  {
    digitalWrite(dir3,HIGH);
    analogWrite(an3,255);

    if(c3>=-50&&c3<=50)
    {
      analogWrite(an3,0);
      flag3s=3;
    }
  }
  if(flag4s==2&&c4<=20&&c4>=-2000)  //-1700  800
  {
    digitalWrite(dir4,HIGH);
    analogWrite(an4,255 );
  
    if(c4>=-50&&c4<=50)
    {
      analogWrite(an4,0);
      flag4s=3;
    }
  }
  if(flag4s==3&&flag3s==3)
  {
   
    c5=-2100;
    c6=-2100;
    flagr=5;
    analogWrite(an3,0);
    analogWrite(an4,0);
    
  }
}

if(flagr==5)
{
  if(c1<0)
    {
      digitalWrite(dir1,LOW);
      analogWrite(an1,pwm1-20);
      
    }
    if(c1>=0)
    {digitalWrite(dir1,1);
      analogWrite(an1,27);
   c1=0;
    }
    if(c2<0)
    {
      digitalWrite(dir2,HIGH);
      analogWrite(an2,pwm1+31);
    //  c2=0;
    }
    if(c2>=0)
    {
      digitalWrite(dir2,0);
      analogWrite(an2,30);
 c2=0;
    }
  if(flag5s==2&&c5<=0&&c5>=-3200)
  {
    digitalWrite(dir5,LOW);
    analogWrite(an5,180);

    if(c5>=-100&&c5<=100)
    {
      analogWrite(an5,0);
      flag5s=3;
    }
  }
  if(flag6s==2&&c6<=0&&c6>=-3200)
  {
    digitalWrite(dir6,LOW);
    analogWrite(an6,180);

    if(c6>=-100&&c6<=100)
    {
      analogWrite(an6,0);
      flag6s=3;
    }
  }
  if(flag5s==3&&flag6s==3)
  {

    
    flagr=6;
    c2=0;
    c1=0;
    c3=0;
  c4=0;
  c5=0;
  c6=0;
    analogWrite(an5,0);
    analogWrite(an6,0);
    
    
  }
}
if(flagr==6)
{
  c1=0;
  c2=0;
  c3=0;
  c4=0;
  c5=0;
  c6=0;
  

  flag1s=1;
  flag2s=1;
  flag3s=1;
  flag4s=1;
  flag5s=1;
  flag6s=1;
  flagr=0;
}
*/
}

