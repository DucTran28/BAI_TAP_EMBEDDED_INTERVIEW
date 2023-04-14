/*
    *File: Bai2.c
    *Author: Tran Ngoc Duc
    *Date: 27/2/2023
    *Description: Chương trình đọc số nhập từ bàn phím vào và đọc thành chữ
*/


// Nhap tu ban phim vao MOT so
// Vi Du:  1.000.000  --> 1Tr
//         1.000.100  --> 1 Trieu 1 Tram


#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>



/*
    *Function: readNumber()
    *Description: Đọc số 
    *Input: 
        *avalue: Giá trị 1-9
    *Output: 
        return: None
*/
void readNumber(int value){
    if(value == 0) printf("KHONG ");
    if(value == 1) printf("MOT ");
    if(value == 2) printf("HAI ");
    if(value == 3) printf("BA ");
    if(value == 4) printf("BON ");
    if(value == 5) printf("NAM ");
    if(value == 6) printf("SAU ");
    if(value == 7) printf("BAY ");
    if(value == 8) printf("TAM ");
    if(value == 9) printf("CHIN ");
}


/*
    *Function: printNumber()
    *Description: In số nhập vào thành chữ
    *Input: 
        *value: Giá trị từ 1-9
        *index: Chỉ số dùng để so sáng để in ra giá trị hàng triệu, trăm ngàn, chục ngàn, hàng, trăm , chục, đơn vị
    *Output: 
        return: None
*/
void printNumber(int index, int value)
{
    switch (index)
    {
    case 7:
        readNumber(value);
        printf("TRIEU ");
        break;
    case 6:
        readNumber(value);
        printf("TRAM ");
        break;
    case 5:
        if(value == 0)
        {
            printf("LE ");
        }
        else if(value == 1)
        {
            printf("MUOI ");
        } 
        else
        {
            readNumber(value);
            printf("MUOI ");
        }
        break;
    case 4: 
        if(value > 0)
        {
            readNumber(value);
            printf("NGAN ");
        }
        else
        {
            printf("NGAN ");
        } 
        break;
    case 3:
        readNumber(value);
        printf("TRAM ");
        break;
    case 2:
        if(value == 0)
        {
            printf("LE ");
        }
        else if(value == 1)
        {
            printf("MUOI ");
        }
        else 
        {
            readNumber(value);
            printf("MUOI ");
        }
        break;
    case 1: 
        if(value>0)
        {
            readNumber(value);
        }
        break;
    default:
        break;
    }
}



/*
    *Function: countDigitsInNumber()
    *Description: Hàm đếm số chữ số có trong số nhập vào
    *Input: 
        *number: giá trị của số nhập vào
    *Output: 
        return: số chữ số có trong số nhập vào
*/
uint8_t countDigitsInNumber(uint32_t number)
{
    uint8_t amountNumber = 0;   //Khởi tạo biến để lưu số chữ số của số nhập vào(Ví dụ 1234 -> có 4 chữ số)
    uint32_t temp1 = 1;         //Khởi tạo  biến tạm temp1
    uint32_t temp2 = number;    //Khởi tạo biến tạm temp2 gán bằng số nhập vào

    if(temp2 == 0)              // Nếu số nhập vào bằng 0 --> Số chữ số = 1
    {
        amountNumber = 1;
    }

    //Tính số chữ số có trong số nhập vào
    while(1){ 
        temp2 = number/temp1; 
        if(temp2 == 0)
        {
            break;     
        } 
        temp1 = temp1*10;
        amountNumber++;
    }
    return amountNumber;
}



int main(){
    
    //Nhập số
    uint32_t _number;
    printf("Moi ban nhap so: ");
    scanf("%d",&_number);

    uint8_t amountNumber=countDigitsInNumber(_number);

    uint32_t *arrNumber;  //Khai báo mảng dưới dạng con trỏ
    
    arrNumber = (uint8_t *)malloc(amountNumber*sizeof(int8_t)); //Cấp phát động cho mảng chứa amountNumber phần tử đã tìm ở hàm countDigitsInNumber()
    
    uint32_t temp3 = 1;   //Khai báo 1 biến tạm temp3

    for(int i = 0; i < amountNumber;i++) //Vòng for dùng để từng chữ số vào mảng --> index
    {                                       
        arrNumber[i] =_number/temp3%10;   //Ví dụ vòng lặp đầu 1234/1%10 = 4 lưu 4 vào vị trí đầu tiên của mảng, tiếp theo là 3->2->1.
        temp3 *= 10;                     
    }                                     

    for(int i = amountNumber-1; i > -1; i--)//Vòng for để in số ra chữ
    {
        printNumber(i+1,*(arrNumber+i));
    }
    printf("\n");
    return 0;
}