#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <vector>

using namespace std;


class SinhVien{
private:
    uint8_t ID;
    char    Ten_SV[20];
    char    Gioi_Tinh[4];
    uint8_t Tuoi;
    double  Diem_Toan;
    double  Diem_Ly;
    double  Diem_Hoa;
    double  Diem_Trung_Binh;
    char    Hoc_Luc[11];
public:
    SinhVien(const char ten[],const char gioi_tinh[],const uint8_t tuoi,
                const double diem_toan,const double diem_ly,const double diem_hoa);
    SinhVien();
    void   Set_TenSV(const char ten[]);
    void   Set_Gioi_Tinh(const char gioi_tinh[]);
    void   Set_Tuoi(const uint8_t tuoi);
    void   Set_Diem_Toan(const double diem_toan);
    void   Set_Diem_Ly(const double diem_ly);
    void   Set_Diem_Hoa(const double diem_hoa);

    uint32_t Get_ID();
    char*    Get_Ten_SV();
    char*    Get_Gioi_Tinh();
    uint8_t  Get_Tuoi();
    double   Get_Diem_Toan();
    double   Get_Diem_Ly();
    double   Get_Diem_Hoa();
    double   Get_Diem_Trung_Binh();
    char*    Get_Hoc_Luc();
};


void SinhVien::Set_TenSV(const char ten[])
{
    strcpy(Ten_SV,ten);
}

void SinhVien::Set_Tuoi(uint8_t tuoi)
{
    Tuoi=tuoi;
}

void SinhVien::Set_Gioi_Tinh(const char gioi_tinh[])
{
    strcpy(Gioi_Tinh,gioi_tinh);
}


void SinhVien::Set_Diem_Hoa(const double diem_hoa)
{
    Diem_Hoa=diem_hoa;
}

void SinhVien::Set_Diem_Toan(const double diem_toan)
{
    Diem_Toan=diem_toan;
}

void SinhVien::Set_Diem_Ly(const double diem_ly)
{
    Diem_Ly=diem_ly;
}
uint32_t SinhVien::Get_ID()
{
    return ID;
}
char* SinhVien::Get_Ten_SV()
{
    return Ten_SV;
}

uint8_t SinhVien::Get_Tuoi()
{
    return Tuoi;
}

char* SinhVien::Get_Gioi_Tinh()
{
    return Gioi_Tinh;
}

double SinhVien::Get_Diem_Toan()
{
    return Diem_Toan;
}

double SinhVien::Get_Diem_Hoa()
{
    return Diem_Hoa;
}

double SinhVien::Get_Diem_Ly()
{
    return Diem_Ly;
}

double SinhVien::Get_Diem_Trung_Binh()
{
    Diem_Trung_Binh=(Diem_Toan+Diem_Ly+Diem_Hoa) / 3;
    return Diem_Trung_Binh;
}

char* SinhVien::Get_Hoc_Luc()
{
    
    if(Get_Diem_Trung_Binh()>=8)
    {
        strcpy(Hoc_Luc,"GIOI");
    }
    else if (Get_Diem_Trung_Binh()>=6.5)
    {
        strcpy(Hoc_Luc,"KHA");
    }
    else if (Get_Diem_Trung_Binh()>=5)
    {
        strcpy(Hoc_Luc,"TRUNG BINH");
    }
    else if (Get_Diem_Trung_Binh()<5)
    {
        strcpy(Hoc_Luc,"YEU");
    }
    return Hoc_Luc;
}

SinhVien::SinhVien(const char ten[],const char gioi_tinh[],const uint8_t tuoi,const double diem_toan,const double diem_ly,const double diem_hoa)
{
    static uint8_t id = 0;
    ID=id;
    id++;
    strcpy(Ten_SV,ten);
    strcpy(Gioi_Tinh,gioi_tinh);
    Tuoi=tuoi;
    Diem_Toan=diem_toan;
    Diem_Ly=diem_ly;
    Diem_Hoa=diem_hoa;
}

class Menu{
private:
    vector<SinhVien> Danh_Sach_Sinh_Vien;
    vector<SinhVien> Danh_Sach_Sinh_Vien_Theo_GPA_Tang_Dan;
    vector<char> Mang_Luu_Ten_SV;
    void xoa_sinh_vien_id(uint8_t id);
    void tim_kiem_sinh_vien(char ten[20]);
    void sap_xep_sinh_vien_gpa();
    void sap_xep_sinh_vien_ten();

public: 
    void Them_Sinh_Vien();
    void Hien_Thi_Danh_Sach();
    void Cap_Nhat_Thong_Tin_Boi_ID();
    void Xoa_Sinh_Vien_Theo_ID();
    void Tim_Kiem_Sinh_Vien_Theo_Ten();
    void Sap_Xep_Sinh_Vien_Theo_GPA();
    void Sap_Xep_Sinh_Vien_Theo_Ten();
    void Ghi_Danh_Sach_Sinh_Vien_Vao_Filetxt();
    void Hien_Thi(vector<SinhVien> DSSV);
};


#define NHAP_THONG_TIN(Noi_Dung1,Kieu_Du_Lieu,Bien,Dieu_Kien,Noi_Dung2)     \
    do                                                                      \
    {                                                                       \
        printf("%s",Noi_Dung1);                                             \
        scanf(Kieu_Du_Lieu,Bien);                                           \
        if(Dieu_Kien){                                                      \
            printf(Noi_Dung2);                                              \
        }                                                                   \   
    }while(Dieu_Kien);                                                      \



void Menu::xoa_sinh_vien_id(uint8_t id)
{
    uint8_t i=0;
    for(SinhVien SV : Danh_Sach_Sinh_Vien)
    {
        if(SV.Get_ID() == id)
        {
            Danh_Sach_Sinh_Vien.erase(Danh_Sach_Sinh_Vien.begin()+i);
        }
        i++;
    }
}
SinhVien::SinhVien()
{

}
void Menu::sap_xep_sinh_vien_gpa()
{
    uint8_t size_arr = Danh_Sach_Sinh_Vien.size();
    SinhVien temp;  
    for(int i=0; i<size_arr-1;i++)
    {
        for(int j=i+1;j<size_arr;j++)
        {
            if(Danh_Sach_Sinh_Vien[i].Get_Diem_Trung_Binh() > Danh_Sach_Sinh_Vien[j].Get_Diem_Trung_Binh())
            {
                temp=Danh_Sach_Sinh_Vien[i];
                Danh_Sach_Sinh_Vien[i]=Danh_Sach_Sinh_Vien[j];
                Danh_Sach_Sinh_Vien[j]=temp;
            }
        }
    }
    Hien_Thi(Danh_Sach_Sinh_Vien);
}
void Menu::Sap_Xep_Sinh_Vien_Theo_Ten()
{
    uint8_t size_arr = Danh_Sach_Sinh_Vien.size();
    SinhVien temp;  
    for(int i=0; i<size_arr-1;i++)
    {
        for(int j=i+1;j<size_arr;j++)
        {
            if(strcmp(Danh_Sach_Sinh_Vien[i].Get_Ten_SV(),Danh_Sach_Sinh_Vien[j].Get_Ten_SV()) > 0)
            {
                temp=Danh_Sach_Sinh_Vien[i];
                Danh_Sach_Sinh_Vien[i]=Danh_Sach_Sinh_Vien[j];
                Danh_Sach_Sinh_Vien[j]=temp;
            }
        }
       
    }
    Hien_Thi(Danh_Sach_Sinh_Vien);
}

void Menu::Hien_Thi(vector<SinhVien> DSSV)
{
    printf("ID\tTen\tGioitinh\tTuoi\tDiem_toan\tDiem_ly\t\tDiem_hoa\tDiem_TB\t\tHoc_Luc\n");
    for(SinhVien SV : DSSV)
    {
        printf(" %hhu\t%s\t%s\t\t%hhu\t%0.2lf\t\t%0.2lf\t\t%0.2lf\t\t%0.2lf\t\t%s\n",
        SV.Get_ID(),SV.Get_Ten_SV(),SV.Get_Gioi_Tinh(),SV.Get_Tuoi(),SV.Get_Diem_Toan(),SV.Get_Diem_Ly(),SV.Get_Diem_Hoa(),SV.Get_Diem_Trung_Binh(),SV.Get_Hoc_Luc());
    }
}

void Menu::tim_kiem_sinh_vien(char ten[20])
{
    uint8_t i=0;
    for(SinhVien SV : Danh_Sach_Sinh_Vien)
    {
        if(strcmp(SV.Get_Ten_SV(),ten) == 0 )
        {
            printf("ID\tTen\tGioitinh\tTuoi\tDiem_toan\tDiem_ly\t\tDiem_hoa\tDiem_TB\t\tHoc_Luc\n");
            printf(" %hhu\t%s\t%s\t\t%hhu\t%0.2lf\t\t%0.2lf\t\t%0.2lf\t\t%0.2lf\t\t%s\n",
            SV.Get_ID(),SV.Get_Ten_SV(),SV.Get_Gioi_Tinh(),SV.Get_Tuoi(),SV.Get_Diem_Toan(),SV.Get_Diem_Ly(),SV.Get_Diem_Hoa(),SV.Get_Diem_Trung_Binh(),SV.Get_Hoc_Luc());
        }
        i++;
    }
}

void Menu::Them_Sinh_Vien()
{
    uint8_t Continue_or_Exit;
    char ten[20];
    uint8_t  tuoi;
    char gioitinh[4];
    double diemtoan;
    double diemly;
    double diemhoa;
    do
    {
        printf("Nhap ten sinh vien: ");
        scanf("%s",&ten);
        printf("Nhap gioi tinh cua sinh vien: ");
        scanf("%s",&gioitinh);
        NHAP_THONG_TIN("Nhap tuoi cua sinh vien: ","%hhu",&tuoi,tuoi<18 || tuoi>100,"Ban nhap sai! Hay nhap lai.");
        NHAP_THONG_TIN("Nhap diem toan cua sinh vien: ","%lf",&diemtoan,diemtoan<0 || diemtoan>10,"Ban nhap sai! Hay nhap lai.");
        NHAP_THONG_TIN("Nhap diem ly cua sinh vien: ","%lf",&diemly,diemly<0 || diemly>10,"Ban nhap sai! Hay nhap lai.");
        NHAP_THONG_TIN("Nhap diem hoa cua sinh vien: ","%lf",&diemhoa,diemhoa<0 || diemhoa>10,"Ban nhap sai! Hay nhap lai.");
        SinhVien sv(ten,gioitinh,tuoi,diemtoan,diemly,diemhoa);
        Danh_Sach_Sinh_Vien.push_back(sv);

        printf("%s","Ban co muon nhap them sinh vien nua khong? ");
        printf("%s","Nhan 1 (Yes) or 0 (No): ");
        scanf("%hhu",&Continue_or_Exit);
    }while(Continue_or_Exit == 1);
}

void Menu::Tim_Kiem_Sinh_Vien_Theo_Ten()
{
    char ten[20];
    printf("%s","Nhap ten sinh vien muon tim kiem: ");
    scanf("%s",&ten);
    tim_kiem_sinh_vien(ten);
}

void Menu::Hien_Thi_Danh_Sach()
{
    printf("%s\n","Thong tin cua sinh vien :");
    Hien_Thi(Danh_Sach_Sinh_Vien);
}


void Menu::Sap_Xep_Sinh_Vien_Theo_GPA()
{
    sap_xep_sinh_vien_gpa();
}


void Menu::Xoa_Sinh_Vien_Theo_ID()
{
    uint8_t id;
    printf("%s","Nhap ID sinh vien ma ban muon xoa : ");
    scanf("%hhu",&id);
    xoa_sinh_vien_id(id);
}

int main()
{
    Menu mn;
    mn.Them_Sinh_Vien();
    mn.Hien_Thi_Danh_Sach();
    mn.Tim_Kiem_Sinh_Vien_Theo_Ten();
    mn.Sap_Xep_Sinh_Vien_Theo_GPA();
    mn.Sap_Xep_Sinh_Vien_Theo_Ten();
    mn.Xoa_Sinh_Vien_Theo_ID();
    mn.Sap_Xep_Sinh_Vien_Theo_GPA();
    return 0;
}