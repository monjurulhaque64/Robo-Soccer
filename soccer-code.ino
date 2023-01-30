//define motor output pins
int motorLeftA = 8;
int motorLeftB = 9;
int motorRightA = 10;
int motorRightB = 12;
int motorLeftENA = 4;                                    // use any two pwm pin of arduino
int motorRightENB = 5;
char miu;
int goti = 255; 

void setup() 
{  
pinMode(motorLeftA, OUTPUT);  // Digital Pin 8 as output
pinMode(motorLeftB, OUTPUT);  // Digital Pin 9 as output
pinMode(motorRightA, OUTPUT);  // Digital Pin 10 as output
pinMode(motorRightB, OUTPUT);  // Digital Pin 12 as output
Serial.begin(9600);
}

void forward(){
      digitalWrite(motorLeftA, HIGH);
      digitalWrite(motorLeftB, LOW);
      digitalWrite(motorRightA, HIGH);
      digitalWrite(motorRightB, LOW);
  }

 void backward(){
      digitalWrite(motorLeftA, LOW);
      digitalWrite(motorLeftB, HIGH);
      digitalWrite(motorRightA, LOW);
      digitalWrite(motorRightB, HIGH); 
      }

 void leftturn(){
    digitalWrite(motorLeftA, LOW);
    digitalWrite(motorLeftB, HIGH);//low (if you want to of left motor)
    digitalWrite(motorRightA, HIGH);
    digitalWrite(motorRightB, LOW);
  }

  void rightturn(){
    digitalWrite(motorLeftA, HIGH);
    digitalWrite(motorLeftB, LOW);
    digitalWrite(motorRightA, LOW);
    digitalWrite(motorRightB, HIGH); //LOW (if you want to of right motor)
    }
  void stopping(){
    digitalWrite(motorLeftA, LOW);
    digitalWrite(motorLeftB, LOW);
    digitalWrite(motorRightA, LOW);
    digitalWrite(motorRightB, LOW); 
    }
void loop()
{
  while (Serial.available() > 0)
  {
  miu = Serial.read();
  Serial.println(miu);
  }
  analogWrite(motorLeftENA , goti);
  analogWrite(motorRightENB, goti);
   
  if( miu == 'F') // Forward Movement
    {
      forward();  
    }
  else if(miu == 'B') // Backward Movement
    {
      backward();
    }
  
    else if(miu == 'L') //Left Turn
    {
    leftturn();
    }
    else if(miu == 'R') //Right Turn
    {
    rightturn();
    }
    
  else if(miu == 'S') //Stop Bot
    {
    stopping();
    }

  if (miu == '0')
  {
    goti = 0;
    stopping();
  }
  if (miu == '1')
  {
    goti = 30;
  }
  if (miu == '2')
  {
    goti = 60;
  }
  if (miu == '3')
  {
    goti = 90;
  }
  if (miu == '4')
  {
    goti = 120;
  }
  if (miu == '5')
  {
    goti = 150;
  }
  if (miu == '6')
  {
    goti = 180;
  }
  if (miu == '7')
  {
    goti = 210;
  }
  if (miu == '8')
  {
    goti = 240;
  }
  if (miu == '9')
  {
    goti = 255;
  }

  /* Comment out of modification   
  else if(miu == 'I') // FR
    {
    digitalWrite(motorLeftA, HIGH);
    digitalWrite(motorLeftB, LOW);
    digitalWrite(motorRightA, LOW);
    digitalWrite(motorRightB, LOW);
    }
  else if(miu == 'J') //BR
    {
    digitalWrite(motorLeftA, LOW);
    digitalWrite(motorLeftB, HIGH);
    digitalWrite(motorRightA, LOW);
    digitalWrite(motorRightB, LOW);
    }
   else if(miu == 'G') //FL
    {
    digitalWrite(motorLeftA, LOW);
    digitalWrite(motorLeftB, LOW);
    digitalWrite(motorRightA, HIGH);     
    digitalWrite(motorRightB, LOW);
    }
  else if(miu == 'H') //BL
    {
    digitalWrite(motorLeftA, LOW);
    digitalWrite(motorLeftB, LOW);
    digitalWrite(motorRightA, LOW);
    digitalWrite(motorRightB, HIGH); 
    } */
}