/*
    *File: Bai2.cpp
    *Author: Tran Ngoc Duc
    *Date: 1/4/2023
    *Description: Chương trình tính chu vi, diện tích, đường chéo của hình chữ nhật và kiểm tra nó có phải hình vuông không
*/


#include <stdio.h>
#include <stdint.h>
#include <math.h>

//Khai báo hằng số pi
const float pi=3.14;


/*
    *Function : Class Circle
    *Description: Chứa các Property và Method của Class Circle
*/
class Circle{
    private:
        uint8_t radiusOfCircle;
    public:
        Circle(float circle);
        uint8_t getRadius();
        float   getPerimeter();
        float   getArea();
        void    displayInfor();
};


/*
    *Function: Constructor của Class Circle
    *Description: Hàm khới tạo giá trị cho các property của class
    *Input:  
       radius: biến có kiểu dữ liễu uint8_t
    *Output: None
*/  
Circle::Circle(float radius)
{
    radiusOfCircle=radius;
}


/*
    *Function: getRadius
    *Description: Hàm lấy giá trị thuộc tính bán kính của class Circle
    *Input:  None
    *Output:
        return bán kính của class Circle
*/  
uint8_t Circle::getRadius()
{
    return radiusOfCircle;
}


/*
    *Function: getPerimeter
    *Description: Hàm tính và trả về giá trị chu vi của hình tròn
    *Input:  None
    *Output:
        return chu vi của hình tròn
*/  
float Circle::getPerimeter()
{
    return (2*pi*radiusOfCircle);
}


/*
    *Function: getArea
    *Description: Hàm tính và trả về giá trị diện tích của hình tròn
    *Input: None
    *Output:
        return diện tích của hình tròn
*/  
float Circle::getArea()
{
    return pi*pow(radiusOfCircle,2);
}


/*
    *Function: displayInfor
    *Description: Hàm hiển thị bán kính, chu vi, diện tích của hình tròn
    *Input: None
    *Output: None
*/  
void Circle::displayInfor()
{
    printf("Ban kinh cua hinh tron R= %hhu\n",getRadius());
    printf("Chu vi hinh tron la: %.3lf\n",getPerimeter());
    printf("Dien tich hinh tron la: %.3lf\n",getArea());
}


int main()
{
    //Khai báo class
     Circle cir(5);
     cir.displayInfor();
    return 0;
}