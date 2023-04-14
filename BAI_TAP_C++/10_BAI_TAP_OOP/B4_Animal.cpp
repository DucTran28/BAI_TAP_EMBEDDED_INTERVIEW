/*
    *File: Bai4.cpp
    *Author: Tran Ngoc Duc
    *Date: 1/4/2023
    *Description: Chương trình tính chỉ số BMI, in các thông tin của động vật và so sánh trọng lượng giữa các loài động vật
*/

#include <stdio.h>
#include <stdint.h>
#include <string>
#include <string.h>
#include <vector>
using namespace std;


/*
    *Function : Class Animals
    *Description: Chứa các Property và Method của Class Animals
*/
class Animals{
    private:
        char    nameOfAnimals[10];
        uint8_t ageOfAnimals;
        float   weightOfAnimals;
        float   heightOfAnimals;
    public:
        Animals(const char name[],uint8_t tuoi,float weight);
        Animals();
        char   *getName();
        uint8_t getAge();
        float   getWeight();
        float   getHeight();
        float   calculateBMI();
};


/*
    *Function: Constructor của Class Animals
    *Description: Hàm khới tạo giá trị cho các property của class
    *Input:
       *name:   tên động vật
       *age :   tuổi 
       *weight: trọng lượng 
    *Output: None
*/  
Animals::Animals(const char name[20],uint8_t age,float weight)
{
    strcpy(nameOfAnimals,name);
    ageOfAnimals=age;
    weightOfAnimals=weight;
}


/*
    *Function: getName()
    *Description: Hàm lấy tên của động vật
    *Input: None
    *Output: 
        return: giá trị thuộc tính tên của động vật

*/
char* Animals::getName()
{
    return nameOfAnimals;
}


/*
    *Function: getAge()
    *Description: Hàm lấy tuổi của động vật
    *Input: None
    *Output: 
        return: giá trị thuộc tính tuổi của động vật
*/
uint8_t Animals::getAge()
{
    return ageOfAnimals;
}


/*
    *Function: getWeight()
    *Description: Hàm lấy trọng lượng của động vật
    *Input: None
    *Output: 
        return: giá trị thuộc tính trọng lượng của động vật
*/
float Animals::getWeight()
{
    return weightOfAnimals;
}


/*
    *Function:getHeight()
    *Description: Hàm lấychiều cao của động vật
    *Input: None
    *Output: 
        return: giá trị thuộc tính chiều cao của động vật
*/
float Animals::getHeight()
{
    return heightOfAnimals;
}


/*
    *Function:calculateBMI()
    *Description: Hàm tính và trả về chỉ số BMI  của động vật
    *Input: None
    *Output: 
        return: giá trị chỉ số BMI
*/
float Animals::calculateBMI()
{
    return float(weightOfAnimals)/(heightOfAnimals*heightOfAnimals);
}


/*
    *Function : Class Compare
    *Description: Chứa các Property và Method của Class Compare
*/
class Compare{
    private:
        vector <Animals> listAnimals;
    public:
        void  addAnimal(Animals animal);
        void  compareAge();
        void  compareWeight();
};


/*
    *Function: addAnimal()
    *Description: hàm thêm động vật vào list danh sách 
    *Input: 
        animal: obj thuộc class Animals
    *Output: None
*/
void Compare::addAnimal(Animals animal)
{
    listAnimals.push_back(animal);
}


/*
    *Function: compareAge()
    *Description: hàm so sánh tuổi các động vật và in ra động vật lớn tuổi nhất
    *Input: None
    *Output: None
*/
void Compare::compareAge()
{
    uint8_t maxAge=0;
    char nameAnimal[20];
    for(Animals animal : listAnimals)
    {
        if(animal.getAge() > maxAge)
        {
            maxAge=animal.getAge();
            strcpy(nameAnimal,animal.getName());
        }
    }
    printf("Dong vat co tuoi lon nhat la: %s",nameAnimal);
    printf("%d\n",maxAge);
}


/*
    *Function: compareWeight()
    *Description: hàm so sánh trọng lượng các động vật và in ra động vật nặng nhất
    *Input: None
    *Output: None
*/
void Compare::compareWeight()
{
    uint8_t maxWeight=0;
    char nameAnimal[20];
    for(Animals animal : listAnimals)
    {
        if(animal.getWeight() > maxWeight)
        {
            maxWeight=animal.getWeight();
            strcpy(nameAnimal,animal.getName());
        }
    }
    printf("Dong vat co khoi luong lon nhat la: %s",nameAnimal);
    printf("%d",maxWeight);
}


int main(void)
{

   Animals animal1("Cho",10,20.1);
   Animals animal2("Meo",5,6.5);
   Animals animal3("Heo",3,36.1);
   Compare cmp;
   cmp.addAnimal(animal1);
   cmp.addAnimal(animal2);
   cmp.addAnimal(animal3);
   cmp.compareAge();
   cmp.compareWeight();
   return 0;
}