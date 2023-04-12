#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>


//mang bat ky vd arr[] = {1, 7, 8, 2, 3, 8, 3, 7, 6, 7, 8, 8, 2}
// sap xep mang theo thu tu tang dan
// liet ke cac phan tu co so lan xuat hien trong mảng sắp xếp và chưa sắp xếp  vd: 1 xuat hien 1 lan
//                                                                                 7 xuat hien 2 lan
//                                                                                 8 xuat hien 3 lan
                                             
uint8_t dem=0;

typedef struct{
    uint8_t size;
    uint8_t *firstAdd;
}typeArray;

int randomA(int minN, int maxN){
 return minN + rand() % (maxN + 1 - minN);
}

// Hàm tạo mảng với các giá trị ngẫu nhiên
void randomArray(typeArray *value, uint8_t length){
    srand((int)time(0));
    value->size = length;
    value->firstAdd = (uint8_t *)malloc(sizeof(uint8_t)*value->size);
    int r;
    for(int i = 0; i < value->size; ++i)
    {
        value->firstAdd[i] = randomA(0,10);
    }    
}


// Hàm sắp xếp mảng theo thứ tự tăng dần
void sortArr(typeArray *arr)
{
    for(int i=0;i<(arr->size)-1;i++)      
    {
        for(int j=i+1;j<(arr->size);j++)  
        {
            uint8_t temp=0;                          // Khai báo 1 biến tạm để lưu trữ giá trị 
            if(arr->firstAdd[i] > arr->firstAdd[j])  // So sánh giá trị thứ i với giá trị thứ i+1
            {
                temp=arr->firstAdd[i];
                arr->firstAdd[i]=arr->firstAdd[j];
                arr->firstAdd[j]=temp;
            }
        }
    }
}

// Hàm đếm số lần phần tử xuất hiện trong mảng chưa được sắp xếp
void count_item_no_arrange(typeArray *arr)
{
    for(int i=0; i < (arr->size) ;i++)     // Vòng lặp tìm số lần phần tử 0 xuất hiện trong mảng
    {
       if(arr->firstAdd[i] == 0)        
       {
            dem++;
       }
    }
    printf("0 xuat hien: %d lan\n",dem); 
    dem=1;
    for(int i=0; i < (arr->size);i++)      
    {
       for(int j=i+1; j < (arr->size) ;j++)
       {
            if(arr->firstAdd[i] == arr->firstAdd[j] & arr->firstAdd[i] != 0)    //So sánh phần tử i với phần tử i+1 với điều kiện phần tử thứ i khác 0
            {
                dem++;
                arr->firstAdd[j]=0;    // Gán giá trị thứ j bằng 0 khi phần tử thứ i bằng phần tử thứ j
            }
       }
       if( arr->firstAdd[i] != 0)
       {
          printf("%d xuat hien trong mang so lan la:%d\n",arr->firstAdd[i],dem);
       }
       dem=1;
    }
    
}

// Hàm đếm các phần tử xuất hiện trong mảng đã được sắp xếp
void count_item_arranged(typeArray *arr)
{
    uint8_t dem=1;                                 // Khai báo 1 biến đếm =1
    for(int i=0; i < arr->size ;i++)
    {
      if(arr->firstAdd[i] == arr->firstAdd[i+1])   // So sánh phần tử thứ i và phần tử thứ i cộng 1
      {
        dem++;
      }
      else
      {
        printf("%d xuat hien so lan la:%d\n",arr->firstAdd[i],dem);
        dem=1;   
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

    //count_item_no_arrange(&arr);

    //Gọi hàm sắp xếp mảng theo tứ tự tăng dần
    sortArr(&arr);
    
    //In giá trị của mảng sau khi sắp xếp
    printf("Mang sau khi sap xep la:\n");
    for (int i = 0; i < arr.size; i++)
    {
        printf("arr[%d] = %d\n",i, arr.firstAdd[i]);
    }

    //Gọi hàm đếm số lần xuất hiện của từng phần tử trong mảng
    count_item_arranged(&arr);
   
    return 0;
}
