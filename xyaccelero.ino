#define REMOTEXY_MODE__ESP8266WIFI_LIB_POINT
#include <ESP8266WiFi.h>

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_WIFI_SSID "esp"
#define REMOTEXY_WIFI_PASSWORD "12345678"
#define REMOTEXY_SERVER_PORT 6377


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 17 bytes
  { 255,12,0,0,0,10,0,16,31,1,9,0,8,26,46,46,24 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  float accelerometer_1_x;
  float accelerometer_1_y;
  float accelerometer_1_z;

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

int pin1=D0;
int pin2=D1;
int pin3=D2;
int pin4=D3;


void setup() 
{
  RemoteXY_Init (); 
  Serial.begin(115200);
  pinMode(pin1,OUTPUT);
  pinMode(pin2,OUTPUT);
  pinMode(pin3,OUTPUT);
  
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  float x,y,z;
  x=RemoteXY.accelerometer_1_x;
  y=RemoteXY.accelerometer_1_y;
  z=RemoteXY.accelerometer_1_z;
  Serial.print(x);
  Serial.print("\t");
  Serial.print(y);
  Serial.print("\t");
  Serial.print(z);
  Serial.println("");
  RemoteXY_delay(20);

  int a,b,c,d;

  

  a=x*40;b=y*35;
  if(x<0)
  {
    c=x*-1;
    c=c*40;
  }
  else
  {
    c=0;
  }
  if(y<0)
  {
    d=x*-1;
    d=d*55;
  }
  else
  {
    d=0;
  }

  analogWrite(pin1,a);
  analogWrite(pin2,b);
  analogWrite(pin3,c);
  analogWrite(pin4,d);
  
  
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay(), use instead RemoteXY_delay() 


}
