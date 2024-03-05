enum custom_variables {
  led_pin_red = 27,
  led_pin_green = 26,
  led_pin_blue = 25,
};

void set_red(bool on_off)
{
  digitalWrite(led_pin_red, on_off);
}

void set_green(bool on_off)
{
  digitalWrite(led_pin_green, on_off);
}

void set_blue(bool on_off)
{
  digitalWrite(led_pin_blue, on_off);
}

void set_rgb(bool red_on_off, bool green_on_off, bool blue_on_off)
{
  set_red(red_on_off);
  set_green(green_on_off);
  set_blue(blue_on_off);
}

void setup() {
  pinMode(led_pin_red, OUTPUT);
  pinMode(led_pin_green, OUTPUT);
  pinMode(led_pin_blue, OUTPUT);
}

void loop() {
  set_rgb(1,0,0);
  delay(1000);
  set_rgb(1,1,0);
  delay(1000);
  set_rgb(0,0,1);
  delay(1000);
  set_rgb(0,1,0);
  delay(1000);
}
