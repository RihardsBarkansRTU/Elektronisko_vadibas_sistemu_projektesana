enum pinConfig  {
  button1 = 16,
  button2 = 17,
  a7 = 26,
  b7 = 15,
  c7 = 21,
  d7 = 22,
  e7 = 23,
  f7 = 27,
  g7 = 19,
  dig4 = 18,
  dig3 = 13,
  dig2 = 14,
  dig1 = 25,
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

void clear()
  {
    setDisplay(1,1,1,1,1,1,1);
  }

void display2(int number, int which_position) {
  clear();
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
}

void loop() {
  static int num0 = 0;
  static int num1 = 0;
  static int num2 = 0;
  static int num3 = 0;
  unsigned long wait_interval = 1000;
  unsigned long start_millis = millis();
  while(millis()<(start_millis + wait_interval))
  {
    display2(num0,0);
    display2(num1,1);
    display2(num2,2);
    display2(num3,3);
  }
  num0++;
  if(num0>9)
  {
    num0 = 0;
    num1++;
  }
  if(num1>5)
  {
    num1 = 0;
    num2++;
  }
  if (num2>9)
  {
    num2 = 0;
    num3++;
  }
  if(num3>5);
  {
    num3 = 0;
  }
}
