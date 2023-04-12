/*
    *File: Bai2.cpp
    *Author: Tran Ngoc Duc
    *Date: 1/4/2023
    *Description: Chương trình tính chu vi, diện tích, đường chéo của hình chữ nhật và kiểm tra nó có phải hình vuông không
*/



#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>



/*
    *Function : Class Rectangle
    *Description: Chứa các Property và Method của Class Rectangle

*/
class Rectangle{
    private:
        uint8_t lengthOfRectangle;
        uint8_t widthOFRectangle;
    public:
        void setInfor(uint8_t length, uint8_t width);
        Rectangle(uint8_t length, uint8_t width);
        uint8_t  getLength();
        uint8_t  getWidth();
        uint8_t  getPerimeter();
        uint8_t  getArea();
        float    getDiagonal();
        bool     checkSquare();
        void     displayInfor();
};



/*
    *Function: Constructor của Class Rectangle
    *Description: Hàm khới tạo giá trị cho các property
    *Input:
        * length :  biến có kiểu uint8_t
        * width  :  biến có kiểu uint8_t
    *Output: None
*/  
Rectangle::Rectangle(uint8_t length, uint8_t width)
{
    lengthOfRectangle=length;
    widthOFRectangle=width;
}



/*
    *Function: Method getLength()
    *Description: Hàm lấy giá trị thuộc tính chiều dài của Class Reactangle
    *Input: None
    *Output: 
        return chiều dài của class Rectangle   
*/ 
uint8_t Rectangle::getLength()
{
    return lengthOfRectangle;
}



/*
    *Function: Method getWidth()
    *Description: Hàm lấy giá trị thuộc tính chiều rộng của Class Rectangle
    *Input: None
    *Output:
        return chiều dài của class Rectangle  
*/ 
uint8_t Rectangle::getWidth()
{
    return widthOFRectangle;
}



/*
    *Function: Method getPerimeter()
    *Description: Hàm tính chu vi của hình chữ nhật
    *Input: None
    *Output:
       return chu vi của hình chữ nhật
*/
uint8_t Rectangle::getPerimeter()
{
    return (lengthOfRectangle + widthOFRectangle)*2;
}



/*
    *Function: Method getArea()
    *Description: Hàm tính diện tích của hình chữ nhật
    *Input: None
    *Output:
        return diện tích của hình chữ nhật
*/
uint8_t Rectangle::getArea()
{
    return (lengthOfRectangle * widthOFRectangle);
}



/*
    *Function: Method getDiagonal()
    *Description: Hàm tính đường chéo của hình chữ nhật
    *Input: None
    *Output:
        return đường chéo của hình chữ nhật
*/
float Rectangle::getDiagonal()
{
    return sqrt(lengthOfRectangle*lengthOfRectangle + widthOFRectangle*widthOFRectangle);
}



/*
    *Function: Method checkSquare()
    *Description: Hàm kiểm tra xem HCN có phải hình vuông hay không?
    *Input: None
    *Output:
       return giá trị kiểu bool Đúng:1  Sai:0
*/
bool Rectangle::checkSquare()
{
    return ((lengthOfRectangle == widthOFRectangle) ? 1 : 0);
}



/*
    *Function: Method displayInfor()
    *Description: Hiện thị các method lấy chiều dài, chiều rộng, tính chu vi, diện tích, đường chéo và kiểm tra của class hình chữ nhật
    *Input: None
    *Output: None     
*/
void Rectangle::displayInfor()
{
    printf("Chieu dai hinh chu nhat la: %hhu\n",lengthOfRectangle);
    printf("Chieu rong cua hinh chu nhat la: %hhu\n",widthOFRectangle);
    printf("Chu vi cua hinh chu nhat la: %hhu\n",getPerimeter());
    printf("Dien tich cua hinh chu nhat la: %hhu\n",getArea());
    printf("Duong cheo cua hinh chu nhat la: %.2f\n",getDiagonal());
    printf(Rectangle::checkSquare() ? "La hinh vuong\n" : "Khong phai la hinh vuong\n");
}


int main()
{
   Rectangle rec(5,5);
   rec.displayInfor();
   return 0;
}