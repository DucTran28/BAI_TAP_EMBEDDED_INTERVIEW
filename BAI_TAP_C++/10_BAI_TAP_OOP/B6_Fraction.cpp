/*
    *File: Bai6.cpp
    *Author: Tran Ngoc Duc
    *Date: 1/4/2023
    *Description: Chương trình thực hiện các phép toán giữa tử số và mẫu số
*/


#include <stdio.h>
#include <string>
#include <stdint.h>


/*
    *Function : Class Fraction
    *Description: Chứa các Property và Method của Class Fraction
*/
class Fraction{
    private:
        int16_t _numerator;     //Tu so
        int16_t _denominator;   //Mau so
    public:
        int16_t getNumerator();
        int16_t getDenominator();
        Fraction(int16_t numerator=0,int16_t denominator=0);
};


/*
    *Function: Constructor của Class Fraction
    *Description: Hàm khởi tạo giá trị cho các property của class Fraction
    *Input:  
       numerator:     Tử số 
       denominator:   Mẫu số
    *Output: None
*/ 
Fraction::Fraction(int16_t numerator,int16_t denominator)
{
    _numerator=numerator;
    _denominator=denominator;
}


/*
    *Function: getNumerator()
    *Description: Hàm lấy giá trị thuộc tính tử số của class
    *Input:  None
    *Output: 
        return: giá trị thuộc tính tử số của class
*/ 
int16_t Fraction::getNumerator()
{
    return _numerator;
}


/*
    *Function: getDenominator()
    *Description: Hàm lấy giá trị thuộc tính mẫu số của class
    *Input:  None
    *Output: 
        return: giá trị thuộc tính mẫu số của class
*/ 
int16_t Fraction::getDenominator()
{
    return _denominator;
}


/*
    *Function : Class Calculation
    *Description: Chứa các Property và Method của Class Class Calculation.
*/
class Calculation{
    private:
        int16_t resultMathAdd;
        int16_t resultMathSub;
        int16_t resultMathMul;
        float   resultMathDiv;
        Fraction fraction;
    public:
        void    mathAdd(Fraction fraction);
        void    mathSub(Fraction fraction);
        void    mathMul(Fraction fraction);
        void   mathDiv(Fraction fraction); 
        int16_t getResultMathAdd();
        int16_t getResultMathSub();
        int16_t getResultMathMul();
        float   getResultMathDiv();
};


/*
    *Function : mathAdd()
    *Description: Hàm tính phép cộng giữa tử số và mẫu số
    *Input: 
        *fraction: object thuộc class Fraction
    *Output: None
*/
void Calculation::mathAdd(Fraction fraction){
    resultMathAdd=fraction.getDenominator() + fraction.getNumerator();
}


/*
    *Function : mathSub()
    *Description: Hàm tính phép trừ giữa tử số và mẫu số
    *Input: 
        *fraction: object thuộc class Fraction
    *Output: None
*/
void Calculation::mathSub(Fraction fraction){
    resultMathSub=fraction.getDenominator() - fraction.getNumerator();
}


/*
    *Function : mathMul()
    *Description: Hàm tính phép nhân giữa tử số và mẫu số
    *Input: 
        *fraction: object thuộc class Fraction
    *Output: None
*/
void Calculation::mathMul(Fraction fraction){
    resultMathAdd=fraction.getDenominator() * fraction.getNumerator();
}


/*
    *Function : mathDiv()
    *Description: Hàm tính phép chia giữa tử số và mẫu số
    *Input: 
        *fraction: object thuộc class Fraction
    *Output: None
*/
void Calculation::mathDiv(Fraction fraction){
    if(fraction.getDenominator()== 0)
    {
        printf("Mau so bang 0.Ket qua khong xac dinh.");
    }
    else
    {
        resultMathAdd=fraction.getDenominator() / fraction.getNumerator();
    }
}



/*
    *Function: getResultMathAdd()
    *Description: hàm lấy giá trị phép cộng giữa tử và mẫu số
    *Input: None
    *Output: 
        return: giá trị phép cộng tử và mẫu số
*/
int16_t Calculation::getResultMathAdd()
{
    return resultMathAdd;
}


/*
    *Function:getResultMathSub()
    *Description: hàm lấy giá trị phép trừ giữa tử và mẫu số
    *Input: None
    *Output: 
        return: giá trị phép trừ tử và mẫu số
*/
int16_t Calculation::getResultMathSub()
{
    return resultMathSub;
}


/*
    *Function:getResultMathMul()
    *Description: hàm lấy giá trị phép nhân giữa tử và mẫu số
    *Input: None
    *Output: 
        return: giá trị phép nhân giữa tử và mẫu số
*/
int16_t Calculation::getResultMathMul()
{
    return resultMathMul;
}


/*
    *Function:getResultMathDiv()
    *Description: hàm lấy giá trị phép chia giữa tử và mẫu số
    *Input: None
    *Output: 
        return: giá trị phép chia giữa tử và mẫu số
*/
float Calculation::getResultMathDiv()
{
    return resultMathDiv;
}


int main(void)
{
    Fraction fraction(4,0);
    Calculation calculate;
    calculate.mathDiv(fraction);
    printf("%d",calculate.getResultMathDiv());
    return 0;
}