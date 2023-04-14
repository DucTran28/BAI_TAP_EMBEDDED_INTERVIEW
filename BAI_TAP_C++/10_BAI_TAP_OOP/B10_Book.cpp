/*
    *File: Bai10.cpp
    *Author: Tran Ngoc Duc
    *Date: 1/4/2023
    *Description: Chương trình tạo 1 lớp Sách chứa các thuộc tính và các phương thức 
                       để mượn, trả và in các thông tin của sách
*/

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <vector>

using namespace std;


/*
    *Function : Class Book
    *Description: Chứa các Property và Method của Class Book
*/
class Book{
    private:
        char nameOfBook[20];
        char nameOFAuthor[20];
        uint16_t publishYear;
        uint8_t  amountBook;
    public:
        Book(const char name[], const char author[],const uint16_t publish,uint8_t amount);
        void      setAmountBook(uint8_t amount);
        char*     getNameOfBook();
        char*     getNameOfAuthor();
        uint16_t  getPublishYear();
        uint8_t   getAmountBook();
        void      showInforOfBook();
};


/*
    *Function: Constructor của class Book
    *Description: Hàm khởi tạo giá trị cho các thuộc tính khi tạo obj
    *Input
        *name:    tên sách
        *author:  tên tác giả
        *publish: năm xuất bản
        *amount:  số lượng sách
    *Output:None
*/
Book::Book(const char name[], const char author[],const uint16_t publish,uint8_t amount)
{
    strcpy(nameOfBook,name);
    strcpy(nameOFAuthor,author);
    publishYear=publish;
    amountBook=amount;
}


/*
    *Function: setAmountBook()
    *Description: Hàm set giá trị cho thuộc tính số lượng sách của class
    *Input: 
        amount: số lượng sách muốn set
    *Output:None
*/
void Book::setAmountBook(uint8_t amount)
{
    amountBook=amount;
}



/*
    *Function: getNameOfBook()
    *Description: Hàm get giá trị thuộc tính tên sách của class
    *Input: None
    *Output: 
        return: giá trị thuộc tính tên sách của class
*/
char* Book::getNameOfBook()
{
    return nameOfBook;
}


/*
    *Function: getNameOfAuthor()
    *Description: Hàm get giá trị thuộc tính tên tác giả của class
    *Input: None
    *Output: 
        return: giá trị thuộc tính tên tác giả của class
*/
char* Book::getNameOfAuthor()
{
    return nameOFAuthor;
}


/*
    *Function: getPublishYear()
    *Description: Hàm get giá trị thuộc tính năm xuất bản sách của class
    *Input: None
    *Output: 
        return: giá trị thuộc tính năm xuất bản sách của class
*/
uint16_t Book::getPublishYear()
{
    return publishYear;
}


/*
    *Function: getAmountBook()
    *Description: Hàm get giá trị thuộc tính số lượng sách của class
    *Input: None
    *Output: 
        return: giá trị thuộc tính số lượng sách của class
*/
uint8_t Book::getAmountBook()
{
    return amountBook;
}


/*
    *Function: showInforOfBook()
    *Description: Hàm hiển thị các thông tin về sách: tên sách, tên tác giả , năm xuất bản và số lượng hiện có
    *Input:  None
    *Output: None
*/
void Book::showInforOfBook()
{
    printf("Ten sach: %s\n",getNameOfBook());
    printf("Ten tac gia: %s\n",getNameOfAuthor());
    printf("Nam xuat ban: %u\n",getPublishYear());
    printf("So luong sach: %hhu\n",getAmountBook());
}



/*
    *Function : Class Manage
    *Description: Chứa các Property và Method của Class Manage
*/
class Manage{
    private:
        vector <Book> listBook;
    public:
        void addBook(Book book);
        bool borrowBook(char nameBookWantBorrow[],uint8_t _amount);
        void giveBackBook(char nameBookWantGiveBack[],uint8_t _amount);
        void showListBook();
};


/*
    *Function:addBook()
    *Description: Hàm thêm sách vào danh sách book
    *Input:
        *_book: sách(obj thuộc class Book)
    *Output: None
*/
void Manage::addBook(Book _book)
{
    listBook.push_back(_book);
}

/*
    *Function:showListBook()
    *Description: Hiển thị danh sách thông tin về các cuốn sách.
    *Input:  None
    *Output: None
*/
void Manage::showListBook()
{
    printf("%s\t%s\t%s\t%s\n","Ten sach ","Ten tac gia ","Nam xuat ban","So luong sach ");
    for(Book book : listBook)
    {
        printf("%s\t%s\t    %u\t    %hhu\n",book.getNameOfBook(),book.getNameOfAuthor(),book.getPublishYear(),book.getAmountBook());
    }
}


/*
    *Function: borrowBook()
    *Description: Hàm mượn sách
    *Input:  
        *nameBookWantBorrow: tên cuốn sách muốn mượn
        *_amount: số lượng muốn mượn
    *Output: None
*/
bool Manage::borrowBook(char nameBookWantBorrow[],uint8_t _amount)
{
    bool haveOrNoBookWantBorrow = 0;   //Biến để kiểm tra có cuốn sách người mượn muốn mượn có trong danh sách book không?
    for(Book &book : listBook)
    {
        if(strcmp(nameBookWantBorrow,book.getNameOfBook()) == 0)
        {
            haveOrNoBookWantBorrow=true;
            if(_amount <= book.getAmountBook())
            {
                printf("Ban da muon sach thanh cong.\n");
                book.setAmountBook(book.getAmountBook() - _amount);
                return 0;
            }
            else
            {
                printf("So luong sach ban muon muon vuot qua so luong chung toi hien co.Vui long giam so luong.\n");
                return 0;
            } 
        }
        else
        {
            haveOrNoBookWantBorrow=false;
        }
    }
    if(haveOrNoBookWantBorrow == false)
    {
        printf("Khong tim thay cuon sach ma ban muon muon.\n");
    }
}


/*
    *Function: giveBackBook()
    *Description: Hàm trả sách
    *Input:  
        *nameBookWantGiveBack: tên cuốn sách muốn trả
        *_amount: số lượng trả
    *Output: None
*/
void Manage::giveBackBook(char nameBookWantGiveBack[],uint8_t _amout)
{
    for(Book &book : listBook)
    {
        if(strcmp(nameBookWantGiveBack,book.getNameOfBook()) == 0)
        {
            printf("Ban da tra sach thanh cong.\n");
            book.setAmountBook(book.getAmountBook() + _amout);
        }
    }
}





int main(void)
{
    //Chương trình chính
    Book book1("Dac Nhan Tam","Dale Carnegie",1936,100);
    Book book2("Nha Gia Kim","Paulo Coelho",1988,150);
    Book book3("Mat Biec","Nguyen Nhat Anh",1990,250);
    Manage manage;
    manage.addBook(book1);
    manage.addBook(book2);
    manage.addBook(book3);
    manage.showListBook();
    manage.borrowBook("Nha Gia Kim",70);
    manage.showListBook();
    manage.giveBackBook("Nha Gia Kim",70);
    manage.showListBook();
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    return 0;
}