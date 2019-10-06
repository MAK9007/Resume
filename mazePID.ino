#include <Ultrasonic.h>
Ultrasonic ultrasonic(9,8);
int setvalue = 5.5;
int error = 0;
int lasterror = 0;
int ERRORCHANGE;
int speedchange;
int errorsum;

int dir_1 = 11;
int dir_2 = 10;
int rmotor_1 = 9;
int lmotor_2 = 12;
float kp = 2.2;
float kd = 0.3;
float ki = 2.2;
int currentspeed = 75;
int maxspeed = 150;
int count = 0;
int pos;
int readvalue;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(dir_1,OUTPUT);
  pinMode(dir_2,OUTPUT);
  delay(1000);
  pinMode(rmotor_1,OUTPUT);
  pinMode(lmotor_2,OUTPUT);
 
  
}

void loop() {
  
{
  pos = ultrasonic.Ranging(CM);
  Serial.println(pos);
  if( pos>=3&&pos<=10);
}

    error = pos-setvalue;
    ERRORCHANGE = error-lasterror;
    errorsum = error+lasterror;
    speedchange = ((kp*error)+(kd*ERRORCHANGE)+(ki*(errorsum));
    int x = currentspeed-speedchange;
    int y = currentspeed+speedchange;
    if(x>maxspeed)
    x = maxspeed;
    if (y>maxspeed)
    y = maxspeed;
    if (x<0)
    {
      x=0;
    }
    if(y<0)
    {
      y=0;
    }
    if(pos>=0&&pos<=4)
    {
      analogWrite(dir_1,x);
      analogWrite(dir_2,y);
    }
    lasterror = error;
    
    }
    else
    {
      analogWrite(dir_1,76);
      analogWrite(dir_2,76);
  }
}

