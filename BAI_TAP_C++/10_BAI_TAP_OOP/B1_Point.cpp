
/*
    *File: Bai2.cpp
    *Author: Tran Ngoc Duc
    *Date: 1/4/2023
    *Description: Chương trình tính khoảng cách giữa 2 điểm và diện tích tam giác được tạo bởi 3 điểm trong không gian            
*/


#include <stdio.h>
#include <stdint.h>
#include <math.h>


/*
    *Function : Class Point
    *Description: Chứa các Property và Method của Class Rectangle
*/
class Point{
    private:
        float _ordinate;   // Hoanh do
        float _abscissa;    // Tung do
    public:
        Point(float ordinate = 0,float abscissa = 0);
        float getOrdinate();
        float getAbscissa();
};


/*
    *Function: Constructor của Class Point
    *Description: Hàm khới tạo giá trị cho các property
    *Input:
        * ordinate : hoành độ
        * abscissa : tung độ
    *Output: None
*/
Point::Point(float ordinate, float abscissa)
{
    _ordinate=ordinate;
    _abscissa=abscissa;
}


/*
    *Function:getOrdinate()
    *Description: Hàm lấy giá trị của hoành độ
    *Input:None
    *Output: 
        return: Giá trị của thuộc tính hoành độ 
*/
float Point::getAbscissa()
{ 
    return _ordinate;
}


/*
    *Function:getAbscissa()
    *Description: Hàm lấy giá trị của tung độ
    *Output: 
        return: Giá trị của thuộc tính tung độ
*/
float Point::getAbscissa()
{
    return _abscissa;
}


/*
    *Function : Class SpaceMath
    *Description: Chứa các Property và Method của Class SpaceMath
*/
class SpaceMath{
    private:
        Point firstCoordinate;
        Point secondCoordinate;
        Point thirdCoordinate;
        typedef enum{
            DISTANCE,
            AREA_OF_TRIANGLE
        }Math;
        Math math;
    public:
        SpaceMath(Point firstcoordinate, Point secondcoordinate);
        SpaceMath(Point firstcoordinate, Point secondcoordinate, Point thirdcoordinate);
        float calculateDistance();
        float calculateAreaOfTriangle();
        Point getFirstPoint();
        Point getSecondPoint();
        Point getThirdPoint();
};


/*
    *Function: Constructor của Class SpaceMath với 2 input parameter
    *Description: Hàm khới tạo giá trị cho các property
    *Input:
        * firstcoordinate  :  tọa độ điểm đầu trong hệ tọa độ 2D
        * secondcoordinate  : tọa độ điểm thứ 2 trong hệ tọa độ 2D
    *Output: None
*/
SpaceMath::SpaceMath(Point firstcoordinate, Point secondcoordinate)
{
    math=DISTANCE;  //Gán giá trị cho math= DISTANCE khi hàm khởi tạo có 2 giá đầu vào
    SpaceMath::firstCoordinate=firstcoordinate;
    SpaceMath::secondCoordinate=secondcoordinate;
}



/*
    *Function: Constructor của Class SpaceMath với 3 input parameter
    *Description: Hàm khới tạo giá trị cho các property
    *Input:
        * firstcoordinate  : tọa độ điểm đầu trong hệ tọa độ 2D
        * secondcoordinate : tọa độ điểm thứ 2 trong hệ tọa độ 2D
        * thirdcoordinate  : tọa độ điểm thứ 3 trong hệ tọa độ 2D
    *Output: None
*/
SpaceMath::SpaceMath(Point firstcoordinate, Point secondcoordinate,Point thirdcoordinate)
{
    math=AREA_OF_TRIANGLE;    //Gán giá trị cho math=AREA_OF_TRIANGLE khi hàm khởi tạo có 3 giá đầu vào
    SpaceMath::firstCoordinate=firstcoordinate;
    SpaceMath::secondCoordinate=secondcoordinate;
    SpaceMath::thirdCoordinate=thirdcoordinate;
}



/*
    *Function: calculateDistance()
    *Description: Hàm tính khoảng cách giữa 2 điểm trong hệ tọa độ 2D
    *Input: None
    *Output: 
        return: khoảng cách giữa 2 điểm 
*/
float SpaceMath::calculateDistance()
{
    if(math == DISTANCE)
    {
        return sqrt(pow(secondCoordinate.getOrdinate()-firstCoordinate.getOrdinate(),2) + pow(secondCoordinate.getAbscissa()-firstCoordinate.getAbscissa(),2));
    }
    else
    {
        printf("Khong the thuc hien tinh toan chuc nang nay!");
        return 0;
    }
}



/*
    *Function: calculateAreaOfTriangle()
    *Description: Hàm tính diện tích tam giác tạo bởi 3 điểm trong hệ tọa độ 2D
    *Input: None
    *Output: 
        return: diện tích tam giác tạo bởi 3 điểm
*/
float SpaceMath::calculateAreaOfTriangle()
{
    if(math == AREA_OF_TRIANGLE)
    {
        float firstLength=sqrt(pow(secondCoordinate.getOrdinate()-firstCoordinate.getOrdinate(),2) + pow(secondCoordinate.getAbscissa()-firstCoordinate.getAbscissa(),2));
        float secondLength=sqrt(pow(thirdCoordinate.getOrdinate()-secondCoordinate.getOrdinate(),2) + pow(thirdCoordinate.getAbscissa()-secondCoordinate.getAbscissa(),2));
        float thirdLength=sqrt(pow(thirdCoordinate.getOrdinate()-firstCoordinate.getOrdinate(),2) + pow(thirdCoordinate.getAbscissa()-firstCoordinate.getAbscissa(),2));
        float halfPerimeterOfTriangle = (firstLength + secondLength + thirdLength)/3;  //Nửa chu vi
        return sqrt(halfPerimeterOfTriangle*(halfPerimeterOfTriangle-firstLength)*(halfPerimeterOfTriangle-secondLength)*(halfPerimeterOfTriangle-thirdLength));
    }
    else
    {
        printf("Khong the thuc hien tinh toan chuc nang nay!");
        return 0;
    }
}


int main(void)
{
    Point point1(1,3.5);
    Point point2(3.5,4);
    Point point3(4.5,5);
    SpaceMath spacemath(point1,point2);
    SpaceMath spacemath1(point1,point2,point3);
    printf("%f\n",spacemath.calculateDistance());
    printf("%f",spacemath1.calculateAreaOfTriangle());
}