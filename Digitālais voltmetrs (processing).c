import meter.*;
import processing.serial.*;
Serial port;
String DataIn;
int val;
Meter m ;
void setup()
{
  size(500,400);
  background(0,0,0);
  port = new Serial(this, "COM7", 115200);
  port.clear();
  port.bufferUntil('\n');
  m = new Meter(this,25,50);
  m.setTitle("Digitālais voltmetrs [V]");
  String[] scaleLabels ={"0","0,4","0,8","1,2","1,6","2","2,4","2,8","3,2","3,6","4"};
  m.setScaleLabels(scaleLabels);
  m.setNeedleThickness(3);
}
 void serialEvent (Serial port)
{
DataIn = port.readString();
}
void draw()
{
println(DataIn);
int val = int(trim(DataIn));
m.updateMeter(int(val));
}
