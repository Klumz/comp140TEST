#include <PS2Mouse.h>

#define MOUSE_DATA 5
#define MOUSE_CLOCK 6

PS2Mouse mouse(MOUSE_CLOCK, MOUSE_DATA, STREAM);

int motorsPinEnable = 2;
int mx = 0;
int my = 0;

void setup()
{
  mouse.initialize();
  mouse.set_resolution(02);
  Serial.begin(9600);          //  setup serial

}



void loop()
{
   int data[2];
  mouse.report(data);
  Serial.print(data[0]); // Status Byte
  Serial.print(",");
  Serial.print(data[1]); // X Movement Data
  Serial.print(",");
  Serial.print(data[2]); // Y Movement Data
  Serial.println();

}
