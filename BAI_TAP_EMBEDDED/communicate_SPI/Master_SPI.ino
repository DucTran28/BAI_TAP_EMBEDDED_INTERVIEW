#include <stdio.h>
#include <stdint.h>

/*
 *Author: Tran Ngoc Duc
 *Date: 5/4/2023
 *Description: Viết hàm truyền data cho Master trong chuẩn giao tiếp SPI
*/


//Định nghĩa các chân SCK,SS,MOSI,MISO của Master
#define SCK_PIN    4
#define MOSI_PIN   5
#define MISO_PIN   6
#define SS_PIN     7


//Khai báo các hàm con
void SPI_Soft_Init(void);
void SPI_Soft_Transmit(uint8_t mData);


//Hàm khởi tạo 
void setup() {
  SPI_Soft_Init();
}



//Hàm lặp tuần hoàn
void loop() {
  digitalWrite(SS_PIN,LOW);
  SPI_Soft_Transmit('A');
  digitalWrite(SS_PIN,HIGH);
  delay(2000);
}


/*
 *Function: SPI_Soft_Init
 *Input: None
 *Output:None
 *Description: Khởi tạo chế độ input,output cho các chân. Khởi tạo giá trị ban đầu cho chân SS=HIGH và SCK=LOW
*/
void SPI_Soft_Init()
{
  pinMode(SCK_PIN,OUTPUT);
  pinMode(MOSI_PIN,OUTPUT);
  pinMode(MISO_PIN,INPUT);
  pinMode(SS_PIN , OUTPUT);
  digitalWrite(SCK_PIN,LOW);
  digitalWrite(SS_PIN,HIGH);
}



/*
 *Function: SPI_Soft_Transmit
 *Input: mData: biến đầu vào có kiểu dữ liệu uint8_t
 *Output:None
 *Description: Hàm dùng để truyền 1 byte dữ liệu từ Master đến Slave
*/
void SPI_Soft_Transmit(uint8_t mData)
{
  uint8_t i=0,temp=0;
  for(i=0;i<8;i++)
  {
     x= mData & 0x80 ;
     if(temp)
     {
        digitalWrite(MOSI_PIN,HIGH);
     }
     else
     {
        digitalWrite(MOSI_PIN,LOW);
     }
     delayMicroseconds(25);
     digitalWrite(SCK_PIN,HIGH);
     delayMicroseconds(25);
     digitalWrite(SCK_PIN,LOW);
     mData=mData<<1;
  }
}
