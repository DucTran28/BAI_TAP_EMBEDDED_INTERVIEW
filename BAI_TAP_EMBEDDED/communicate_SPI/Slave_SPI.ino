#include <stdio.h>
#include <stdint.h>

/*
 *Author: Tran Ngoc Duc
 *Date: 5/4/2023
 *Description: Viết hàm nhận data cho Slave trong chuẩn giao tiếp SPI
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
  uint8_t rev;
  rev=SPI_Receive();
  delay(2000);

}


/*
 *Function: SPI_Soft_Init
 *Input: None
 *Output:None
 *Description: Khởi tạo chế độ input,output cho các chân.
*/
void SPI_Soft_Init()
{
  pinMode(SCK_PIN,INPUT);
  pinMode(MOSI_PIN,INPUT);
  pinMode(MISO_PIN,OUTPUT);
  pinMode(SS_PIN ,INPUT);
}


/*
 *Function: SPI_Soft_Init
 *Input: None
 *Output: result: biến có kiểu dữ liệu uint8_t
 *Description: Hàm trả về 1 byte dữ liệu là data được truyền từ master.
*/
uint8_t SPI_Receive()
{
  uint8_t x,result=0;

  while(digitalRead(SS_PIN) == HIGH);          //waiting until SS=0. Start condition

  for(x=0;x<8;x++)
  {
    while(digitalRead(SCK_PIN)==LOW);          // waiting until SCK == 1 --> receive data
      result = result | digitalRead(MOSI);
      result = result<<1;
    while(digitalRead(SCK_PIN)==HIGH);        //  waiting until SCK == 0 --> received 1 bit and prepare for process receive continue bit
   -->  }
  return result;
}
