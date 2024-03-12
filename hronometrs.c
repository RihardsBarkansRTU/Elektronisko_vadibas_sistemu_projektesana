
enum pinConfig  {
  button1 = 34,
  button2 = 35,
  a7 = 0,
  b7 = 4,
  c7 = 16,
  d7 = 17,
  e7 = 5,
  f7 = 18,
  g7 = 19,
  dig1 = 12,
  dig2 = 14,
  dig3 = 27,
  dig4 = 26,
  clean = 2,
};

bool isPressed(int button)
{
  if(digitalRead(button))
  return true;
  else return false;
}

void setDisplay(bool a, bool b, bool c, bool d, bool e, bool f, bool g)
{
  digitalWrite(a7,a);
  digitalWrite(b7,b);
  digitalWrite(c7,c);
  digitalWrite(d7,d);
  digitalWrite(e7,e);
  digitalWrite(f7,f);
  digitalWrite(g7,g);
}

void display(int number)
{
  switch (number) {

    case 0: setDisplay(0,0,0,0,0,0,1);
    break;

    case 1: setDisplay(1,0,0,1,1,1,1);
    break;
    
    case 2: setDisplay(0,0,1,0,0,1,0);
    break;

    case 3: setDisplay(0,0,0,0,1,1,0);
    break;

    case 4: setDisplay(1,0,0,1,1,0,0);
    break;

    case 5: setDisplay(0,1,0,0,1,0,0);
    break;

    case 6: setDisplay(0,1,0,0,0,0,0);
    break;

    case 7: setDisplay(0,0,0,1,1,1,1);
    break;

    case 8: setDisplay(0,0,0,0,0,0,0);
    break;

    case 9: setDisplay(0,0,0,0,1,0,0);
    break;
  }
}

void setPositions(bool a, bool b, bool c, bool d) {
  digitalWrite(dig1,a);
  digitalWrite(dig2,b);
  digitalWrite(dig3,c);
  digitalWrite(dig4,d);
}

void position(int which_position) {
  switch(which_position) {
    case 0: setPositions(1,0,0,0);
    break;
    case 1: setPositions(0,1,0,0);
    break;
    case 2: setPositions(0,0,1,0);
    break;
    case 3: setPositions(0,0,0,1);
    break;
  }
}

void display2(int number, int which_position) {
  position(which_position);
  display(number);
}

void setup() {
  Serial.begin(9600);
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
  pinMode(a7,OUTPUT);
  pinMode(b7,OUTPUT);
  pinMode(c7,OUTPUT);
  pinMode(d7,OUTPUT);
  pinMode(e7,OUTPUT);
  pinMode(f7,OUTPUT);
  pinMode(g7,OUTPUT);
  pinMode(dig1,OUTPUT);
  pinMode(dig2,OUTPUT);
  pinMode(dig3,OUTPUT);
  pinMode(dig4,OUTPUT);
  pinMode(clean,OUTPUT);
}

void loop() {
  static int i = 0;
  
  if (isPressed(button1))
  {
    //start timer and display
  }
  if (isPressed(button2))
  {
    //only display
  }

  

  display2(5,i);
  i++;
  if (i>3) i=0;
  delay(150);


  //Serial.print(digitalRead(d7));
  delay(1);
}
