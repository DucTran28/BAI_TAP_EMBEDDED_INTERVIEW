/*
    *File: Quan_Ly_Sinh_Vien.cpp
    *Author: Tran Ngoc Duc
    *Date: 26/3/023
    *Description: Chương trình tạo 1 lớp sinh viên chứa các thuộc tính tên,tuổi,giới tính, điểm(toán,lí hóa),điểm trung bình 
                  và các phương thức để thêm sinh viên, xóa sinh viên,tìm kiếm,sắp theo(theo tên, theo GPA),cập nhật, hiển thị 
                  danh sách sinh viên.                 
*/


#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <vector>

using namespace std;

typedef enum{
        AddStudent=1,deleteById,SearchById,ArrangeByGpa,ArrangeByName,UpdateById,ShowInfor
}MENU_OPTIONS;


/*
    *Function : Class Student
    *Description: Chứa các Property và Method của Class Student
*/
class Student{
private:
    uint8_t Id;
    char    nameStudent[20];
    char    genderStudent[4];
    uint8_t ageStudent;
    float   scoreMath;
    float   scorePhysic;
    float   scoreChemistry;
    float   scoreMedium;
    char    rankStudent[11];

public:
    Student(const char name[],const char gender[],const uint8_t age,
                const float math,const float physic,const float chemistry);
    Student();
    void   setName(const char name[]);
    void   setGender(const char gender[]);
    void   setAge(const uint8_t age);
    void   setScoreMath(const float math);
    void   setScorePhysic(const float physic);
    void   setScoreChemistry(const float chemistry);

    uint32_t   getId();
    char*      getName();
    char*      getGender();
    uint8_t    getAge();
    float      getScoreMath();
    float      getScorePhysic();
    float      getScoreChemistry();
    float      getScoreMedium();
    char*      getRankStudent();
};


/*
    *Function: setName() 
    *Description: Hàm set giá trị cho thuộc tính tên của class sinh viên
    *Input: 
        *name: tên
    *Output: None
*/
void Student::setName(const char name[])
{
    strcpy(nameStudent,name);
}


/*
    *Function: setAge() 
    *Description: Hàm set giá trị cho thuộc tính tuổi của class sinh viên
    *Input: 
        *age: tuổi
    *Output: None
*/
void Student::setAge(uint8_t age)
{
    ageStudent=age;
}


/*
    *Function: setGender() 
    *Description: Hàm set giá trị cho thuộc tính giới tính của class sinh viên
    *Input: 
        *gender: giới tính
    *Output: None
*/
void Student::setGender(const char gender[])
{
    strcpy(genderStudent,gender);
}


/*
    *Function: setScoreChemistry() 
    *Description: Hàm set giá trị cho thuộc tính điểm hóa của class sinh viên
    *Input: 
        *chemistry: điểm hóa
    *Output: None
*/
void Student::setScoreChemistry(const float chemistry)
{
    scoreChemistry=chemistry;
}


/*
    *Function: setScoreMath() 
    *Description: Hàm set giá trị cho thuộc tính điểm toán của class sinh viên
    *Input: 
        *math: điểm toán
    *Output: None
*/
void Student::setScoreMath(const float math)
{
   scoreMath=math;
}


/*
    *Function: setScorePhysic() 
    *Description: Hàm set giá trị cho thuộc tính điểm lí của class sinh viên
    *Input: 
        *physic: điểm lý
    *Output: None
*/
void Student::setScorePhysic(const float physic)
{
    scorePhysic=physic;
}


/*
    *Function: getId()
    *Description: Hàm get giá trị thuộc tính Id của class sinh viên
    *Input: None
    *Output: 
        return: giá trị thuộc tính Id
*/
uint32_t Student::getId()
{
    return Id;
}


/*
    *Function: getName()
    *Description: Hàm get giá trị thuộc tính tên của class sinh viên
    *Input: None
    *Output: 
        return: giá trị thuộc tính tên
*/
char* Student::getName()
{
    return nameStudent;
}


/*
    *Function: getAge()
    *Description: Hàm get giá trị thuộc tính tuổi của class sinh viên
    *Input: None
    *Output: 
        return: giá trị thuộc tính tuổi
*/
uint8_t Student::getAge()
{
    return ageStudent;
}


/*
    *Function: getGender()
    *Description: Hàm get giá trị thuộc tính giới tính của class sinh viên
    *Input: None
    *Output: 
        return: giá trị thuộc tính giới tính
*/
char* Student::getGender()
{
    return genderStudent;
}


/*
    *Function: getScoreMath()
    *Description: Hàm get giá trị thuộc tính điểm toán của class sinh viên
    *Input: None
    *Output: 
        return: giá trị thuộc tính điểm toán
*/
float Student::getScoreMath()
{
    return scoreMath;
}


/*
    *Function: getScoreChemistry()
    *Description: Hàm get giá trị thuộc tính điểm hóa của class sinh viên
    *Input: None
    *Output: 
        return: giá trị thuộc tính điểm hóa
*/
float Student::getScoreChemistry()
{
    return scoreChemistry;
}


/*
    *Function: getScorePhysic()
    *Description: Hàm get giá trị thuộc tính điểm lí của class sinh viên
    *Input: None
    *Output: 
        return: giá trị thuộc tính điểm lí
*/
float Student::getScorePhysic()
{
    return scorePhysic;
}


/*
    *Function: getScoreMedium()
    *Description: Hàm get giá trị thuộc tính điểm trung bình của class sinh viên
    *Input: None
    *Output: 
        return: giá trị thuộc tính điểm trung bình
*/
float Student::getScoreMedium()
{
    scoreMedium=(scoreMath+scorePhysic+scoreChemistry) / 3;
    return scoreMedium;
}


/*
    *Function: getRankStudent()
    *Description: Hàm tính và trả về giá trị thuộc tính học lực của class sinh viên
    *Input: None
    *Output: 
        return: giá trị thuộc tính học lực
*/
char* Student::getRankStudent()
{
    
    if(getScoreMedium()>=8)
    {
        strcpy(rankStudent,"GIOI");
    }
    else if (getScoreMedium()>=6.5)
    {
        strcpy(rankStudent,"KHA");
    }
    else if (getScoreMedium()>=5)
    {
        strcpy(rankStudent,"TRUNG BINH");
    }
    else if (getScoreMedium()<5)
    {
        strcpy(rankStudent,"YEU");
    }
    return rankStudent;
}

Student::Student()
{
}

/*
    *Function: Constructor của class Student
    *Description: Hàm khởi tạo giá trị cho các thuộc tính khi tạo obj
    *Input
        *name:         tên sinh viên
        *gender:       giới tính
        *age:          tuổi
        *math:         điểm toán
        *physic:       điểm lí
        *chemistry:    điểm hóa
    *Output:None
*/
Student::Student(const char name[],const char gender[],const uint8_t age,const float math,const float physic,const float chemistry)
{
    static uint8_t id = 0;
    Id=id;
    id++;
    strcpy(nameStudent,name);
    strcpy(genderStudent,gender);
    ageStudent=age;
    scoreMath=math;
    scorePhysic=physic;
    scoreChemistry=chemistry;
}



/*
    *Function : Class Student
    *Description: Chứa các Property và Method của Class Student
*/
class Menu{
private:
    vector<Student> listStudent;
public: 
    void addStudent();
    void showListStudent();
    void updateInforById();
    void deleteStudentById();
    void searchStudentByName();
    void arrangeStudentByGpa();
    void arrangeStudentByName();
};



#define ENTER_INFORMATION(content1,typeData,variable,condition,content2)    \
    do                                                                      \
    {                                                                       \
        printf("%s",content1);                                              \
        scanf(typeData,variable);                                           \
        if(condition){                                                      \
            printf(content2);                                               \
        }                                                                   \   
    }while(condition);                                                      \




/*
    *Function: addStudent()
    *Description: Hàm dùng để nhập thông tin sinh viên và push vào list sinh viên
    *Input:  None 
    *Output: None
*/
void Menu::addStudent()
{
    uint8_t Continue_or_Exit;  //Biến cho người dùng nhập để xác định có tiếp tục nhập sinh viên nữa hay không?
    char name[20];
    uint8_t  age;
    char  gender[4];
    float math;
    float physic;
    float chemistry;
    do
    {
        printf("Nhap ten cua sinh vien: ");
        scanf("%s",&name);
        ENTER_INFORMATION("Nhap gioi tinh cua sinh vien: ","%s",&gender,strcmp(gender,"Nam") != 0 && strcmp(gender,"Nu") != 0,"Ban nhap sai! Hay nhap lai.");
        ENTER_INFORMATION("Nhap tuoi cua sinh vien: ","%hhu",&age,age<18 || age>100,"Ban nhap sai! Hay nhap lai.");
        ENTER_INFORMATION("Nhap diem toan cua sinh vien: ","%f",&math,math<0 || math>10,"Ban nhap sai! Hay nhap lai.");
        ENTER_INFORMATION("Nhap diem ly cua sinh vien: ","%f",&physic,physic<0 || physic>10,"Ban nhap sai! Hay nhap lai.");
        ENTER_INFORMATION("Nhap diem hoa cua sinh vien: ","%f",&chemistry,chemistry<0 || chemistry>10,"Ban nhap sai! Hay nhap lai.");
        Student sv(name,gender,age,math,physic,chemistry);
        listStudent.push_back(sv);    //Push sinh viên mới nhập vào list
        printf("%s","Ban co muon nhap them sinh vien nua khong? ");
        printf("%s","Nhan 1 (Yes) or 0 (No): ");
        scanf("%hhu",&Continue_or_Exit);
    }while(Continue_or_Exit == 1);
}


/*
    *Function: showListStudent()
    *Description: Hàm dùng hiển thị thông tin của tất cả các sinh viên có trong list sinh viên
    *Input:  None 
    *Output: None
*/
void Menu::showListStudent()
{
    printf("Id\tName\tGender\t\tAge\tScore Math\tScore Physic\tScore Chemistry\t   Score Medium\t\tRank\n");
    for(Student student : listStudent)
    {
        printf(" %hhu\t%s\t%s\t\t%hhu\t %0.2f\t\t %0.2f\t\t\t%0.2f\t\t%0.2f\t\t%s\n",
        student.getId(),student.getName(),student.getGender(),student.getAge(),student.getScoreMath(),student.getScorePhysic(),student.getScoreChemistry(),student.getScoreMedium(),student.getRankStudent());
    }
}

/*
    *Function: searchStudentByName()
    *Description: Hàm dùng tìm kiếm và hiển thị sinh viên theo tên
    *Input:  None 
    *Output: None
*/
void Menu::searchStudentByName()
{
   char typeName[20];
   printf("Nhap ten ban muon tim kiem: ");
   scanf("%s",&typeName);
   bool checkNameHaveInArray= false;
   for(Student student : listStudent)
   {
        if(strcmp(student.getName(),typeName) == 0)
        {
            checkNameHaveInArray= true;
            printf("Id\tName\t\tGender\tAge\tScore Math\tScore Physic\tScore Chemistry\tScore Medium\t\tRank\n");
            printf(" %hhu\t%s\t%s\t\t%hhu\t%0.2f\t\t%0.2f\t\t%0.2f\t\t%0.2f\t\t%s\n",
            student.getId(),student.getName(),student.getGender(),student.getAge(),student.getScoreMath(),student.getScorePhysic(),student.getScoreChemistry(),student.getScoreMedium(),student.getRankStudent());
        }
   }
   if(checkNameHaveInArray == false)
   {
    printf("Khong tim thay ten sinh vien trong mang");
   }
}


/*
    *Function: arrangeStudentByGpa()
    *Description: Hàm dùng để sắp xếp và hiển thị danh sách sinh viên có GPA tăng dần
    *Input:  None 
    *Output: None
*/
void Menu::arrangeStudentByGpa()
{
    uint8_t size_arr = listStudent.size();
    Student temp; 
    for(int i=0; i<size_arr-1;i++)
    {
        for(int j=i+1;j<size_arr;j++)
        {
            if(listStudent[i].getScoreMedium() > listStudent[j].getScoreMedium())
            {
                temp=listStudent[i];
                listStudent[i]=listStudent[j];
                listStudent[j]=temp;
            }
        }
    }
    showListStudent();
}


/*
    *Function: arrangeStudentByName()
    *Description: Hàm dùng để sắp xếp và hiển thị danh sách sinh viên theo tên theo thứ tự alphabet
    *Input:  None 
    *Output: None
*/
void Menu::arrangeStudentByName()
{
    uint8_t size_arr = listStudent.size();
    Student temp;  
    for(int i=0; i<size_arr-1;i++)
    {
        for(int j=i+1;j<size_arr;j++)
        {
            if(strcmp(listStudent[i].getName(),listStudent[j].getName()) > 0)
            {
                temp=listStudent[i];
                listStudent[i]=listStudent[j];
                listStudent[j]=temp;
            }
        }
    }
    showListStudent();
}


/*
    *Function: deleteStudentById()
    *Description: Hàm xóa sinh viên theo ID được nhập vào từ bàn phím
    *Input:  None 
    *Output: None
*/
void Menu::deleteStudentById()
{
    
    uint8_t id;
    uint8_t index=0;
    printf("%s","Nhap ID sinh vien ma ban muon xoa : ");
    scanf("%hhu",&id);
    for(Student &student : listStudent)
    {
        if(student.getId() == id)
        {
            listStudent.erase(listStudent.begin()+index);
        }
        index++;
    }
}


/*
    *Function: updateInforById()
    *Description: Hàm cập nhật thông tin của 1 sinh viên cụ thể bằng cách nhập vào Id của sinh viên đó
    *Input:  None 
    *Output: None
*/
void Menu::updateInforById()
{
    char name[20];
    uint8_t  age;
    char  gender[4];
    float math;
    float physic;
    float chemistry;
    uint8_t id;
    uint8_t option;

    typedef enum{
        changeName=1,changeAge,changeGender,changeScoreMath,changeScorePhysic,changeScoreChemistry
    }Options;

    Options options;
    printf("%s","Nhap ID sinh vien ma ban muon cap nhat thong tin:");
    scanf("%hhu",&id);
    bool checkHaveId = false;
    for(Student student : listStudent)
    {
        if(student.getId() == id)
        {
            checkHaveId = true;
        }
    }
    if(checkHaveId == true)
    {
        printf("Cac lua cho thay doi thong tin sinh vien:\n");
        printf("1. THAY DOI TEN CUA SINH VIEN\n");
        printf("2. THAY DOI TUOI CUA SINH VIEN\n");
        printf("3. THAY DOI GIOI TINH CUA SINH VIEN\n");
        printf("4. THAY DOI DIEM TOAN CUA SINH VIEN\n");
        printf("5. THAY DOI DIEM LI CUA SINH VIEN\n");
        printf("6. THAY DOI DIEM HOA CUA SINH VIEN\n");
        printf("Ban muon thay doi thong tin nao cua sinh vien? Hay nhan phim 1-6: ");
        scanf("%d",&option);
        switch (option)
        {
        case changeName:
            printf("Nhap ten thay doi cua sinh vien: "); scanf("%s",&name);
            listStudent[id].setName(name);
            break;
        case changeAge:
            ENTER_INFORMATION("Nhap tuoi cua sinh vien: ","%hhu",&age,age<18 || age>100,"Ban nhap sai! Hay nhap lai.");
            listStudent[id].setAge(age);
            break;
        case changeGender:
            ENTER_INFORMATION("Nhap gioi tinh cua sinh vien: ","%s",&gender,strcmp(gender,"Nam") != 0 && strcmp(gender,"Nu") != 0,"Ban nhap sai! Hay nhap lai.");
            listStudent[id].setGender(gender);
            break;
        case changeScoreMath:
            ENTER_INFORMATION("Nhap diem toan  cua sinh vien: ","%f",&math,math<0 || math>10,"Ban nhap sai! Hay nhap lai.");
            listStudent[id].setScoreMath(math);
            break;
        case changeScorePhysic:
            ENTER_INFORMATION("Nhap diem ly cua sinh vien: ","%f",&physic,physic<0 || physic>10,"Ban nhap sai! Hay nhap lai.");
            listStudent[id].setScorePhysic(physic);
            break;
        case changeScoreChemistry:
            ENTER_INFORMATION("Nhap diem hoa cua sinh vien: ","%f",&chemistry,chemistry<0 || chemistry>10,"Ban nhap sai! Hay nhap lai.");
            listStudent[id].setScoreChemistry(chemistry);    
        default:
            printf("Ban nhap sai..");
            break;
        }
    }
    else
    {
        printf("Khong tim thay Id sinh vien ma ban muon thay doi thong tin.\n");
    }
}




int main()
{
    //Chương trình chính
    printf("Cac chuc nang cua Menu:\n");
    printf("1. THEM SINH VIEN\n");
    printf("2. XOA SINH VIEN BOI ID\n");
    printf("3. TIM KIEM SINH VIEN THEO TEN\n");
    printf("4. SAP XEP SINH VIEN THEO GPA\n");
    printf("5. SAP XEP SINH VIEN THEO TEN\n");
    printf("6. CAP NHAT THONG TIN SINH VIEN\n");
    printf("7. HIEN THI THONG TIN SINH VIEN\n");
    uint8_t option;
    MENU_OPTIONS menu_option;
    uint8_t continueOrExit;
    Menu menu;
    do
    {
       printf("Ban muon chon chuc nang nao cua menu? Hay nhan phim 1-7: ");
       scanf("%hhu",&option);
       switch(option)
       {
       case AddStudent:
            menu.addStudent();
            break;
        case deleteById:
            menu.deleteStudentById();
            break;
        case SearchById:
            menu.searchStudentByName();
            break;
        case ArrangeByGpa:
            menu.arrangeStudentByGpa();
            break;
        case ArrangeByName:
            menu.arrangeStudentByName();
            break;
        case UpdateById:
            menu.updateInforById();
            break;
        case ShowInfor:
            menu.showListStudent();
            break;
        default:
            printf("Ban nhap sai roi...");
            break;
       }
        printf("Ban muon tiep tuc lua chon chuc nang khong? Nhan 1 de tiep tuc hoac Nhan phim bat ki de thoat: ");
        scanf("%hhu",&continueOrExit);
    } while (continueOrExit==1);
    return 0;
}