enum custom_variables {
  led_pin_red = 27,
  led_pin_yellow = 26,
  led_pin_green = 25,
  button_pin = 34,
};

void set_red(bool on_off)
{
  digitalWrite(led_pin_red, on_off);
}

void set_yellow(bool on_off)
{
  digitalWrite(led_pin_yellow, on_off);
}

void set_green(bool on_off)
{
  digitalWrite(led_pin_green, on_off);
}

void set_ryg(bool red_on_off, bool yellow_on_off, bool green_on_off)
{
  set_red(red_on_off);
  set_yellow(yellow_on_off);
  set_green(green_on_off);
}

bool read_button()
{
  unsigned long i = 0;
  while(i<1000)
  {
    if(digitalRead(button_pin))
    {
      i=1000;
      return true;
    }
    else
    {
      i++;
      delay(1);
    }
  }
  return false;
}

void setup() {
  pinMode(led_pin_red, OUTPUT);
  pinMode(led_pin_yellow, OUTPUT);
  pinMode(led_pin_green, OUTPUT);
}

void loop() {
  static int sequence = 0;
  switch(sequence) {
    case 0:
    {
      set_ryg(1,0,0);
      break;
    }
    case 1:
    {
      set_ryg(1,1,0);
      break;
    }
    case 2:
    {
      set_ryg(0,0,1);
      break;
    }
    case 3:
    {
      set_ryg(0,1,0);
      break;
    }
  }
  sequence++;

  if(read_button())
  {
    sequence = 2;
  }

  if (sequence>3) sequence = 0;
}
