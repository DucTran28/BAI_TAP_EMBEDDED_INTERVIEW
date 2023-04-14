/*
    *File: Bai9.cpp
    *Author: Tran Ngoc Duc
    *Date: 1/4/2023
    *Description: Chương trình tạo 1 lớp Car chứa các thuộc tính và các phương thức 
                  để kiểm số Km đã đi, chi phí bảo trì và in thông tin về xe.
*/


#include <stdio.h>
#include <string.h>



/*
    *Function : Class AccountBank
    *Description: Chứa các Property và Method của Class AccountBank
*/
class Car{
    private:
        char   carColor[10];
        char   engineType[20];
        float  odometerGone;
    public:
        Car(const char color[10],const char engine[20], float odometer);
        int    calculatePriceMaintance();
        void   showInfor();
        float  getOdometer();
        char*  getCarColor();
        char*  getEngineType();
};


/*
    *Function: Constructor của class Car
    *Description: Hàm khởi tạo giá trị cho các thuộc tính khi tạo obj
    *Input
        *color:  màu của xe
        *engine:  loại động cơ
        *odometer: số kilometer đã đi
    *Output:None
*/
Car::Car(const char color[10],const char engine[20], float odometer)
{
    strcpy(carColor,color);
    strcpy(engineType,engine);
    odometerGone=odometer;
}


/*
    *Function: getCarColor()
    *Description: Hàm lấy giá trị thuộc tính màu xe của class
    *Input: None
    *Output: 
        return: giá trị thuộc tính màu xe của class
*/
char* Car::getCarColor()
{
    return carColor;
}


/*
    *Function: getEngineType()
    *Description: Hàm lấy giá trị thuộc tính loại động cơ của class
    *Input: None
    *Output: 
        return: giá trị thuộc tính động cơ của class
*/
char* Car::getEngineType()
{
    return engineType;
}


/*
    *Function: getOdometer()
    *Description: Hàm lấy giá trị thuộc tính số km đã đi của class
    *Input: None
    *Output: 
        return: giá trị thuộc tính km đã đi của class
*/
float Car::getOdometer()
{
    return odometerGone;
}


/*
    *Function: calculatePriceMaintance()
    *Description: Hàm so sánh km xe đã đi và trả về chi phí bảo trì tương ứng
    *Input: None
    *Output: chi phí bảo trì cho xe
*/
int Car::calculatePriceMaintance()
{
    if(odometerGone > 5000  && odometerGone <  15000 )
    {
        return 1000000;
    }        
    else if (odometerGone > 15000 && odometerGone <  40000 )  
    {
        return 3000000;
    }
    else if (odometerGone > 40000 && odometerGone < 1000000 )
    {
        return 5000000;
    }       
    else if (odometerGone > 1000000) 
    {
        return 7000000;
    }                              
}


/*
    *Function: showInfor()()
    *Description: Hàm in các thông tin về màu, loại động cơ, số Km đã đi và chi phí bảo trì cho xe
    *Input: None
    *Output:None
*/
void Car::showInfor()
{
    printf("The car color: %s\n",getCarColor());
    printf("The type engine of car: %s\n",getEngineType());
    printf("Kilometers:%.2f\n",getOdometer());
    printf("The prices for maintenance: %d VND\n",calculatePriceMaintance());
}



int main(void)
{
    Car car("Red","Electrical Engine",55000.6);
    car.showInfor();
    return 0;
}
