#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>   
double data[3] = {0};
double x,y,p;
void setup()
{
  Serial.begin(9600); 
  Mirf.spi = &MirfHardwareSpi;
  Mirf.init();
  Mirf.setRADDR((byte *)"67890");    //设置接收端地址（使用5个字符）
  Mirf.setTADDR((byte *)"12345");    //设置发送端地址（使用5个字符）
  Mirf.payload = sizeof(data);
  Mirf.channel = 3;                  //设置通讯信道
  Mirf.config();
  }
  void loop()
  {
    if (Mirf.dataReady()) 
    {
    Mirf.getData((byte *)&data);                //接收指令
    Mirf.rxFifoEmpty();
    x = data[0];
    y = data[1];
    p = data[2];
   Serial.print("X:");
   Serial.print(x);
   Serial.print("Y:");
   Serial.print(y);
   Serial.print("P:");
   Serial.println(p);
    }
}


