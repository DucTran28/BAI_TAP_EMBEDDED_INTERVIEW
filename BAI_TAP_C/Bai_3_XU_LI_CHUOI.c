// Khai báo thư viện
#include <stdio.h>
#include <stdint.h>

// Hàm đảo ngược lại chuỗi 
void reverse_str(char arr[],int size)
{
    int count=1;      
    int temp=0;
    int temp1=0;
    int temp2=0;
    int temp3=1;
    for(int i=0;i<size;i++)
    {
        if(arr[i] == 32)            // 32 là mã ASCII của khoảng trắng
        {
           count++;
        }
    }
    uint8_t vitri[count];      // Tạo 1 mảng để lưu vị trí các khoảng trắng
    vitri[0]=0;                // Khai báo vị trí đầu tiên của mảng là kí tự đầu tiên của chuỗi 
    uint8_t j=1;               // Khai báo biến j bắt đầu để lưu vị trí khoảng trắng từ vị trí thứ 2 của mảng 
    for(int i=0;i<size;i++)
    {
        if(arr[i] == 32 )
        {
           temp=i;
           vitri[j]=temp;
           j++;
        }
    }
    temp1=(size-2)-vitri[count-1];    // temp1 = Vị trí kí tự cuối cùng của mảng - Vị trí cuối cùng của khoảng trắng trong chuỗi = Số kí tự in ra
    temp2=vitri[count-1];             // temp2 = Vị trí cuối cùng của khoảng trắng trong chuỗi
    for(int i=0;i<count;i++)          // Vòng lặp for duyệt từ cuối chuỗi về đầu chuỗi
    {
        for(int k=temp2; k<=temp2+temp1;k++)   
        {
            printf("%c",arr[k]);
        }
        *(&temp1)=vitri[count-1-i]-vitri[count-1-temp3];    // Gán temp1 = Số kí tự giữa 2 vị trí khoảng trắng được lưu trong mảng
        *(&temp2)=vitri[count-1-temp3];                    
        temp3++;
    }
    printf("\n");
}

// Hàm viết hoa chữ cái đầu tiên sau dấu chấm trong chuỗi 
void Capital_letter_after_dot(char arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i] == 46)                       // 46 là mã ASCII của dấu chấm
        {
           if(arr[i+2]>64 && arr[i+2]<90)      // Từ 64->90 là mã ASCII của các chữ cái in hoa
           {  
               arr[i+2]= arr[i+2];             // Kí tự đầu tiên sau dấu chấm 
           }
           else
           {
              arr[i+2]=arr[i+2]-32 ;           // Chữ hoa = Chữ thường -32
           } 
        }
    }
    for(int i=0;i<size;i++)
    {
        printf("%c",arr[i]);
    }
    printf("\n");
}

// Hàm in hoa cả đoạn văn bản
void Capital_letter_all(char arr[],int size)
{
    for(int i=0;i<size;i++)
    {
           if(arr[i]>96 && arr[i+2]<122)      // Từ 96->122 là mã ASCII của tất cả các chữ cái in thường
           {  
               arr[i]= arr[i]-32;
           }
           else
           {
              arr[i]=arr[i];
           } 
        
    }
    for(int i=0;i<size;i++)
    {
        printf("%c",arr[i]);
    }
    printf("\n");
}

// Hàm in thường cả  đoạn văn bản
void Lower_letter_all(char arr[],int size)
{
    for(int i=0;i<size;i++)
    {
           if(arr[i]>64 && arr[i]<90)
           {  
               arr[i]= arr[i]+32;               
           }
           else
           {
              arr[i]=arr[i];
           } 
    }
    for(int i=0;i<size;i++)
    {
        printf("%c",arr[i]);
    }
    printf("\n");
}
int main(int argc, char const *argv[])
{
    // Khai báo chuỗi
    char chuoi[]="The US government plans to protect. American technologies by restricting investment. in China in specific. sectors in which the US competes with China.";

    // Lấy kích thước của chuỗi(số lượng phần tử)
    int temp4=sizeof(chuoi);

    //Gọi hàm đảo chuỗi
    reverse_str(chuoi,temp4);

    //Gọi hàm in chữ cái đầu tiên sau dấu chấm
    Capital_letter_after_dot(chuoi,temp4);

    // Gọi hàm in hoa toàn bộ chuỗi
    Capital_letter_all(chuoi,temp4);

    //Gọi hàm in thường toàn bộ chuỗi 
    Lower_letter_all(chuoi,temp4);
    return 0;
}

