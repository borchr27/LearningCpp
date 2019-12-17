//Hello World
//Mitchell B
// link to helpful video: https://www.youtube.com/watch?v=DIw02CaEusY

// need to save code crtl-s, build code, crtl-shft-b, then execute with .\a.exe
#include <iostream>

using namespace std;

class BankAccount{
    private:
        float balance;

    public:
        BankAccount();
        void Deposit(float);
        void WithDrawl();
        float getBalance();

};

BankAccount::BankAccount(){
    balance = 0;
}

float BankAccount::getBalance(){
    return balance;
}

void BankAccount::Deposit(float dep){
    balance = balance + dep;
}

int main(){
    BankAccount checking;
    BankAccount savings;

    cout << "Your checkings balance is: " << checking.getBalance() << endl;
    cout << "Your savings balance is: " << savings.getBalance() << endl;

    checking.Deposit(100);
    savings.Deposit(5000);

    cout << "Your checkings balance is: " << checking.getBalance() << endl;
    cout << "Your savings balance is: " << savings.getBalance() << endl;

}

