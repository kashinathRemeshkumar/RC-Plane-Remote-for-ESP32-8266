#define REMOTEXY_MODE__ESP8266WIFI_LIB_POINT
#include <ESP8266WiFi.h>

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_WIFI_SSID "esp"
#define REMOTEXY_WIFI_PASSWORD "12345678"
#define REMOTEXY_SERVER_PORT 6377


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 59 bytes
  { 255,3,0,4,0,52,0,16,209,0,5,3,63,16,36,36,2,26,31,4,
  0,6,13,8,39,2,26,71,56,30,23,19,19,0,2,24,135,0,0,0,
  0,0,0,200,66,0,0,160,65,0,0,32,65,0,0,0,64,24,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  int8_t joystick_x; // from -100 to 100  
  int8_t joystick_y; // from -100 to 100  
  
  int8_t trottle; // =0..100 slider position 

    // output variables
  float trottle_meter;  // from 0 to 100 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

int trot=D0;
int joy_x=D1;
int joy_y=D2;
int joy_nx=D3;
int joy_ny=D4;
void setup() 
{
  RemoteXY_Init (); 
  Serial.begin(115200);
  pinMode(trot,OUTPUT);
  pinMode(joy_x,OUTPUT);
  pinMode(joy_y,OUTPUT);
  pinMode(joy_nx,OUTPUT);
  pinMode(joy_ny,OUTPUT);
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  analogWriteFreq(200);
  
  int tro,pitch,yaw;
  tro=RemoteXY.trottle;
  RemoteXY.trottle_meter=tro;
  int con=RemoteXY.connect_flag;
  yaw=RemoteXY.joystick_x;
  pitch=RemoteXY.joystick_y;
  
  if(con==0)
  {
    while(tro>0)
    {
      analogWrite(trot,tro);
      tro=tro-1;
    }
    analogWrite(joy_ny,0);   //pitch
    analogWrite(joy_y,50);
    
    analogWrite(joy_nx,0);   //yaw
    analogWrite(joy_x,0);
    delay(3000);
    
    
  }




  
  tro=(tro*2.56);
  analogWrite(trot,tro);
  
  yaw=RemoteXY.joystick_x;
  pitch=RemoteXY.joystick_y;

  
  
/////////////yaw////////////////// 
  if(yaw<0)
  {
    yaw=yaw*-1;
    yaw=yaw*2.56;
    analogWrite(joy_nx,yaw);
    analogWrite(joy_x,0);
  }
  else
  {
   yaw=yaw*2.56;
    analogWrite(joy_x,yaw);
    analogWrite(joy_nx,0);
  }

//////////////////pitch////////////////

  if(pitch<0)
  {
    pitch=pitch*-1;
    pitch=pitch*2.56;
    analogWrite(joy_ny,pitch);
    analogWrite(joy_y,0);
  }
  else
  {
   
   pitch=pitch*2.56;
   analogWrite(joy_y,pitch);
   analogWrite(joy_ny,0);
  }
  
  

  
  //pitch=RemoteXY.joystick_y;
  //yaw=RemoteXY.joystick_x;
  
  Serial.print(tro);
  Serial.print("\t");
  Serial.print(pitch);
  Serial.print("\t");
  Serial.print(yaw);
  Serial.println("");

  RemoteXY_delay(10);   
  
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay(), use instead RemoteXY_delay() 


}
