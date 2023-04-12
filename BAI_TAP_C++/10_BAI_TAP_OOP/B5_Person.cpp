/*
    *File: Bai5.cpp
    *Author: Tran Ngoc Duc
    *Date: 1/4/2023
    *Description: Chương trình tính tuổi và hiển thị thông tin tên, tuổi, địa chỉ của người đó
*/


#include <stdio.h>
#include <stdint.h>
#include <string.h>


/*
    *Function : Class Person
    *Description: Chứa các Property và Method của Class Person
*/
class Person{
    private: 
        char nameOfPerson[20];
        uint16_t yearOfBirth;
        uint8_t ageOfPerson;
        char addressOfPerson[30];
    public:
        Person(const char name[20],uint16_t year,const char address[]);
        void showInfor();
        char *getName();
        uint16_t getYearOfBirth();
        char *getAddress();
        uint8_t calculateAge(); 
};


/*
    *Function: Constructor của Class Person
    *Description: Hàm khởi tạo giá trị cho các property của class Person
    *Input:  
       name:    mảng kí tự có kiểu char
       year:    biến có kiểu dữ liệu uint16_t 
       address: mảng kí tự có kiểu char
    *Output: None
*/  
Person::Person(const char name[],uint16_t year,const char address[])
{
    strcpy(nameOfPerson,name);
    strcpy(addressOfPerson,address);
    yearOfBirth=year;
}



/*
    *Function: getName()
    *Description: Hàm lấy giá trị thuộc tính tên của người
    *Input: None
    * Output
         return: Giá trị thuộc tính nameOfPerson trong class
*/
char* Person::getName()
{
    return nameOfPerson;
}


/*
    *Function: getYearOfBirth()
    *Description: Hàm lấy giá trị thuộc tính năm sinh của người
    *Input: None
    * Output
         return: Giá trị thuộc tính yearOfBirth trong class
*/
uint16_t Person::getYearOfBirth()
{
    return yearOfBirth;
}



/*
    *Function: getAddress()
    *Description: Hàm lấy giá trị thuộc tính địa chỉ của người
    *Input: None
    * Output
         return: Giá trị của thuộc tính addressOfPerson trong class
*/
char* Person::getAddress()
{
    return addressOfPerson;
}


/*
    *Function: calculateAge()
    *Description: Hàm tính tuổi của người
    *Input: None
    * Output
         return: Giá trị tuổi của người đó
*/
uint8_t Person::calculateAge()
{
    ageOfPerson= 2023-yearOfBirth;
    return ageOfPerson;
}


/*
    *Function: showInfor
    *Description: Hàm hiển thị thông tin tên, tuổi, năm sinh, địa chỉ của người
    *Input: None
    * Output : None
        
*/
void Person::showInfor()
{
    printf("Ho va ten: %s\n",nameOfPerson);
    printf("Nam sinh: %u\n",yearOfBirth);
    printf("Tuoi: %hhu\n",calculateAge());
    printf("Dia chi: %s\n",addressOfPerson);
}


int main()
{
    //Khởi tạo obj thuộc class Person với các input parameter
    Person person("Tran Ngoc Duc",2001,"Thon 1 Hoa Bac Di Linh Lam Dong");
    person.showInfor();
    return 0;
}