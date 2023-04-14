/*
    *File: Bai7.cpp
    *Author: Tran Ngoc Duc
    *Date: 1/4/2023
    *Description: Chương trình tạo 1 lớp ngày tháng năm, tính tuổi của người và kiểm tra 1 ngày nhất định có phải ngày lễ hay không?
*/


#include <stdio.h>
#include <stdint.h>
#include <string.h>


/*
    *Function : Class dayMonthYear
    *Description: Chứa các Property và Method của Class dayMonthYear
*/
class dayMonthYear{
    private:
        uint8_t  _day;
        uint8_t _month;
        uint16_t _year;
    public:
        dayMonthYear(uint8_t day=0, uint8_t month=0, uint16_t year=0);
        uint8_t getDay();
        uint8_t getMonth();
        uint16_t getYear();
        void checkHoiliday();
};


/*
    *Function: Constructor của class dayMonthYear 
    *Description: Hàm khởi tạo giá trị cho các thuộc tính khi tạo obj
    *Input
        *day: ngày
        *month: tháng
        *year: năm
    *Output:None
*/
dayMonthYear::dayMonthYear(uint8_t day, uint8_t month, uint16_t year)
{
    _day=day;
    _month=month;
    _year=year;
}


/*
    *Function: getDay()
    *Description: Hàm lấy giá trị thuộc tính ngày của class
    *Input;None
    *Output:
        return: giá trị thuộc tính _day của class
*/
uint8_t dayMonthYear::getDay()
{
    return _day;
}


/*
    *Function: getMonth()
    *Description: Hàm lấy giá trị thuộc tính tháng của class
    *Input;None
    *Output:
        return: giá trị thuộc tính _month của class
*/
uint8_t dayMonthYear::getMonth()
{
    return _month;
}


/*
    *Function: getYear()
    *Description: Hàm lấy giá trị thuộc tính năm của class
    *Input;None
    *Output:
        return: giá trị thuộc tính _year của class
*/
uint16_t dayMonthYear::getYear()
{
    return _year;
}


typedef enum{
    JANUARY=1,FEBUARY,MARCH,APRIL,MAY,JUNE,
    JULY,AUGUST,SEPTEMBER,OCTOBER,NOVEMBER,DECEMBER
}MONTH;


/*
    *Function: checkHoiliday()()
    *Description: Hàm kiểm tra xem 1 ngày nhất định có phải ngày lễ hay không? 
    *Input;None
    *Output:None
*/
void dayMonthYear::checkHoiliday()
{
    MONTH month;
    switch(_month)
    {
    case(JANUARY):
        if(_day == 1) printf("Tet Duong Lich.\n");
        break;
    case(APRIL):
        if(_day == 30) printf("Ngay giai phong Mien Nam thong nhat dat nuoc\n");
        break;
    case(MAY):
        if(_day == 1) printf("Ngay Quoc te lao dong.\n");
        break;
    case(SEPTEMBER):
        if(_day == 2) printf("Ngay Quoc Khanh.\n");
        break;
    default:
        printf("Ngay binh thuong.");
        break;
    }
}


/*
    *Function : Class Person
    *Description: Chứa các Property và Method của Class Person
*/
class Person{
    private:
        char _name[20];
        char _gender[20];
        dayMonthYear _daymonthyear;
    public:
        Person(const char name[],const char gender[],dayMonthYear daymonthyear);
        uint8_t calculateAge();
        dayMonthYear getDayMonthYear();
        void showInfor();
        char* getName();
        char* getGender();      
};


/*
    *Function: Constructor của class Person
    *Description: Hàm khởi tạo giá trị cho các thuộc tính khi tạo obj
    *Input
        *name: tên
        *gender: giới tính
        *daymonthyear: ngày tháng năm sinh của người
    *Output:None
*/
Person::Person(const char name[],const char gender[],dayMonthYear daymonthyear)
{
    strcpy(_name,name);
    strcpy(_gender,gender);
    _daymonthyear=daymonthyear;
}


/*
    *Function: getName()
    *Description: Hàm lấy giá thuộc tính tên người của class Person
    *Input: None
    *Output: 
        return: Giá trị thuộc tính tên của class
*/
char* Person::getName()
{
    return _name;
}


/*
    *Function: getGender()
    *Description: Hàm lấy giá thuộc tính giới tính người của class Person
    *Input: None
    *Output: 
        return: Giá trị thuộc tính giới tính của class
*/
char* Person::getGender()
{
    return _gender;
}


/*
    *Function: calculateAge()
    *Description: Hàm tính và trả về giá trị tuổi của người 
    *Input: None
    *Output: 
        return: Giá trị tuổi của người đó
*/
uint8_t Person::calculateAge()
{
    return (2023-(_daymonthyear.getYear()));
}


/*
    *Function: showInfor()
    *Description: Hàm in ra thông tin tên, giới tính, tuổi của người
    *Input: None
    *Output:None
*/
void Person::showInfor()
{
    printf("Ten: %s\n",getName());
    printf("Gioi tinh: %s\n",getGender());
    printf("Tuoi cua ban la: %hhu\n", calculateAge());
}



int main()
{
    dayMonthYear daymonthyear(2,9,1980);
    daymonthyear.checkHoiliday();
    Person person("Duc","Nam",daymonthyear);
    person.showInfor();
    return 0;
}