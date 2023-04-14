
/*
    *File: Bai1.c
    *Author: Tran Ngoc Duc
    *Date: 25/2/2023
    *Description: Chương trình xử lí mảng số với các thuật toán sắp xếp, đếm số lần xuất hiện của phần tử...
*/


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>


//mang bat ky vd arr[] = {1, 7, 8, 2, 3, 8, 3, 7, 6, 7, 8, 8, 2}
// sap xep mang theo thu tu tang dan
// liet ke cac phan tu co so lan xuat hien trong mảng sắp xếp và chưa sắp xếp  vd: 1 xuat hien 1 lan
//                                                                                 7 xuat hien 2 lan
//                                                                                 8 xuat hien 3 lan



uint8_t count=0;  //Khai báo  biến  toàn cục count


typedef struct{
    uint8_t size;
    uint8_t *firstAdd;
}typeArray;



/*
    *Function: randomA()
    *Description: Hàm trả về 1 giá trị random ngẫu nhiên
    *Input: 
        *minN: Cận dưới của số được random
        *maxN: Cận trên của số được random
    *Output: 
        return: giá trị được random trong khoảng (minN, maxN)
*/
int randomA(int minN, int maxN){
 return minN + rand() % (maxN + 1 - minN);
}



/*
    *Function: randomA()
    *Description: Hàm tạo mảng để lưu các giá trị được random ngẫu nhiên
    *Input: 
        *value:  con trỏ kiểu struct.
        *length: chiều dài của mảng.
    *Output: None
*/
void randomArray(typeArray *value, uint8_t length){
    srand((int)time(0));
    value->size = length;
    value->firstAdd = (uint8_t *)malloc(sizeof(uint8_t)*value->size); //cấp phát động tạo mảng có chiều dài length
    int r;
    for(int i = 0; i < value->size; ++i)
    {
        value->firstAdd[i] = randomA(0,10);
    }    
}


/*
    *Function: sortArr()
    *Description: Hàm sắp xếp mảng theo thứ tự tăng dần
    *Input: 
        * *arr:  con trỏ kiểu struct.
    *Output: None
*/
void sortArr(typeArray *arr)
{
    for(int i=0;i<(arr->size)-1;i++)      
    {
        for(int j=i+1;j<(arr->size);j++)  
        {
            uint8_t temp=0;                           // Khai báo 1 biến tạm để lưu trữ giá trị 
            if(arr->firstAdd[i] > arr->firstAdd[j])   // Nếu giá trị của phần tử ở vị trí thứ i > giá trị ở phần tử thứ j (j=i+1)
            {
                temp=arr->firstAdd[i];                // Gán giá trị ở phần tử thứ i vào biến temp
                arr->firstAdd[i]=arr->firstAdd[j];    // Gán giá trị phần tử thứ i = giá trị tại phần tử j
                arr->firstAdd[j]=temp;                // Gán giá trị phần tử thứ j = biến temp
            }
        }
    }
}


/*
    *Function: countItemAppearWithArrayNotArranged()
    *Description: Hàm đếm số lần 1 phần tử xuất hiện trong mảng khi chưa được sắp xếp
    *Input: 
        * *arr: con trỏ kiểu struct.
    *Output: None
*/
void countItemAppearWithArrayNotArranged(typeArray *arr)
{
    for(int i=0; i < (arr->size) ;i++)        // Vòng lặp tìm số lần phần tử 0 xuất hiện trong mảng
    {
       if(arr->firstAdd[i] == 0)        
       {
            count++;
       }
    }
    printf("0 xuat hien: %d lan\n",count); 
    count=1;
    for(int i=0; i < (arr->size);i++)      
    {
       for(int j=i+1; j < (arr->size) ;j++)
       {
            if(arr->firstAdd[i] == arr->firstAdd[j] & arr->firstAdd[i] != 0) //So sánh phần tử i với phần tử i+1 với điều kiện phần tử thứ i khác 0
            {
                count++;               
                arr->firstAdd[j]=0;    // Gán giá trị phần tử thứ j bằng 0 khi phần tử thứ i bằng phần tử thứ j
            }
       }
       if( arr->firstAdd[i] != 0)
       {
          printf("%d xuat hien trong mang so lan la:%d\n",arr->firstAdd[i],count);
       }
       count=1;
    }
    
}

/*
    *Function: countItemAppearWithArrayArranged()
    *Description: Hàm đếm số lần 1 phần tử xuất hiện trong mảng đã được sắp xếp
    *Input: 
        * *arr: con trỏ kiểu struct.
    *Output: None
*/
void countItemAppearWithArrayArranged(typeArray *arr)
{
    uint8_t count=1;               // Khai báo 1 biến đếm =1
    for(int i=0; i < arr->size ;i++)
    {
      if(arr->firstAdd[i] == arr->firstAdd[i+1])   // So sánh phần tử thứ i và phần tử thứ i+1
      {
        count++;
      }
      else
      {
        printf("%d xuat hien so lan la:%d\n",arr->firstAdd[i],count);
        count=1;   
      } 
    } 
}
int main(int argc, char const *argv[])
{
    // Khai báo 1 struct với tên arr
    typeArray arr;

    // Gọi hàm tạo mảng với 10 giá trị ngẫu nhiên từ 0-10
    randomArray(&arr,10);

    //In giá trị của mảng trước khi sắp xếp
    printf("Mang truoc khi sap xep la:\n");
    for (int i = 0; i < arr.size; i++)
    {
        printf("arr[%d] = %d\n",i, arr.firstAdd[i]);
    }

    //countItemAppearWithArrayNotArranged(&arr);

    
    sortArr(&arr); //Gọi hàm sắp xếp mảng theo tứ tự tăng dần
    
    
    //In giá trị của mảng sau khi sắp xếp
    printf("Mang sau khi sap xep la:\n");
    for (int i = 0; i < arr.size; i++)
    {
        printf("arr[%d] = %d\n",i, arr.firstAdd[i]);
    }

    countItemAppearWithArrayArranged(&arr); //Gọi hàm đếm số lần xuất hiện của từng phần tử trong mảng đã sắp xếp
   
    return 0;
}
