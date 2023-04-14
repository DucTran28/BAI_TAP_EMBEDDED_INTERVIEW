/*
    *File: Bai8.cpp
    *Author: Tran Ngoc Duc
    *Date: 1/4/2023
    *Description: Chương trình tạo 1 lớp tài khoản ngân hàng chứa các thuộc tính và các phương thức 
                        để kiểm tra số dư, rút tiền và nạp tiền vào tài khoản.
*/


#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <string.h>

using namespace std;



/*
    *Function : Class AccountBank
    *Description: Chứa các Property và Method của Class AccountBank
*/
class AccountBank{
    private:
        uint32_t  numberAccount;
        char      nameAccount[20];
        uint32_t  balanceAccount;   
    public:
        AccountBank(uint32_t numberAccount, const char nameAccount[],uint32_t  balanceAccount);
        void setBalanceAccount(uint32_t amountMoney);
        uint32_t  getNumberAccount();
        char*     getNameAccount();
        uint32_t  getBalanceAccount(); 
};



/*
    *Function: Constructor của class AccountBank
    *Description: Hàm khởi tạo giá trị cho các thuộc tính khi tạo obj
    *Input
        *numerAcc:   số tài khoản
        *nameAcc:    tên tài khoản
        *balanceAcc: số dư tài khoản
    *Output:None
*/
AccountBank::AccountBank(uint32_t numberAcc,const char nameAcc[],uint32_t balanceAcc)
{
    numberAccount = numberAcc;
    strcpy(nameAccount,nameAcc);
    balanceAccount=balanceAcc;
}



/*
    *Function: setBalanceAccount()
    *Description: Hàm set giá trị cho thuộc tính số dư tài khoản của class
    *Input: 
        amountMoney: số dư tài khoản muốn set
    *Output:None
*/
void AccountBank::setBalanceAccount(uint32_t amountMoney)
{
    balanceAccount=amountMoney;
}


/*
    *Function: getNumberAccount()
    *Description: Hàm get thuộc tính số tài khoản của class
    *Input: None
    *Output: 
        return: giá trị thuộc tính số tài khoản của class
*/
uint32_t AccountBank::getNumberAccount()
{
    return numberAccount;
}


/*
    *Function: getNameAccount()
    *Description: Hàm get thuộc tính tên tài khoản của class
    *Input: None
    *Output: 
        return: giá trị thuộc tính số tài khoản của class
*/
char* AccountBank::getNameAccount()
{
    return nameAccount;
}


/*
    *Function: getBalanceAccount()
    *Description: Hàm get thuộc tính số dư tài khoản của class
    *Input: None
    *Output: 
        return: giá trị thuộc tính số tài khoản của class
*/
uint32_t AccountBank::getBalanceAccount()
{
    return balanceAccount;
}



/*
    *Function : Class Client
    *Description: Chứa các Property và Method của Class Client
*/
class Client{
    private:
        vector <AccountBank> listAccount;
    public:
        void     addAccount(AccountBank account);
        bool     depositMoney(uint32_t numberAcc, uint32_t money);
        bool     withdrawMoney(uint32_t numberAcc, uint32_t money);
        void     showListAccount();
};



/*
    *Function:addAccount()
    *Description: Hàm thêm tài khoản vào danh sách các tài khoản
    *Input:
        *account: tài khoản (obj thuộc class AccountBank)
    *Output: None
*/
void Client::addAccount(AccountBank account)
{
    listAccount.push_back(account);
}



/*
    *Function:showListAccount()
    *Description: Hàm hiển thị các thông tin số tài khoản, tên và số dư tài khoản
    *Input:None
    *Output: None
*/
void Client::showListAccount()
{
    printf("%s\t\t%s\t\t%s\n","So tai khoan ","Ten tai khoan","So du ");
    for(AccountBank account : listAccount)
    {
        printf("%u\t\t%s\t\t%u\n",account.getNumberAccount(),account.getNameAccount(),account.getBalanceAccount());
    }
}


/*
    *Function:depositMoney()
    *Description: Hàm nạp tiền vào tài khoản
    *Input:
        *numberAcc; số tài khoản muốn nạp tiền vào
        *money: số tiền muốn nạp
    *Output: None
*/
bool Client::depositMoney(uint32_t numberAcc, uint32_t money)
{
    bool checkNumberAccount=false;   //Biến kiểm tra xem có tìm thấy số tài khoản muốn nạp tiền vào hay không
    for(AccountBank &account : listAccount)
    {
        if(numberAcc == account.getNumberAccount())
        {
            checkNumberAccount = true;
            account.setBalanceAccount(account.getBalanceAccount() + money);
            printf("Ban da nap tien thanh cong.\n");
            return checkNumberAccount;
        }
        else
        {
             checkNumberAccount =false;
        }
    }
    if(checkNumberAccount == false)
    {
        printf("Khong tim thay so tai khoan cua ban.\n");
    }
}


/*
    *Function:withdrawMoney()
    *Description: Hàm rút tiền từ tài khoản
    *Input:
        *numberAcc; số tài khoản muốn rút tiền ra
        *money: số tiền muốn rút
    *Output: None
*/
bool Client::withdrawMoney(uint32_t numberAcc, uint32_t money)
{
    bool checkNumberAccount=false;  //Biến kiểm tra xem có tìm thấy số tài khoản muốn rút tiền không?
    for(AccountBank &account : listAccount)
    {
        if(numberAcc == account.getNumberAccount())
        {
            checkNumberAccount = true;
            if(money <= account.getBalanceAccount())
            {
                account.setBalanceAccount(account.getBalanceAccount() - money);
                printf("Ban da rut tien thanh cong.\n");
                return 1;
            }
            else
            {
                printf("So tien rut vuot qua so du cua ban. Vui long nap them tien vao tai khoan.\n");
                return 1;
            }
        }
        else
        {
             checkNumberAccount =false;
        }
    }
    if(checkNumberAccount == false)
    {
        printf("Khong tim thay so tai khoan cua ban.\n");
    }
}

int main(void)
{
    AccountBank account1(314100024,"Tran Ngoc Duc",2000000);
    AccountBank account2(314100025,"Tran Thi Hanh",3000000);
    AccountBank account3(314100026,"Tran Thi Anh",4000000);
    Client client;
    client.addAccount(account1);
    client.addAccount(account2);
    client.addAccount(account3);
    client.showListAccount();
    printf("\n");
    client.withdrawMoney(314100025,5000000);
    client.showListAccount();
    printf("\n");
    client.depositMoney(314100026,1000000);
    client.showListAccount();

}