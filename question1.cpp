#include <iostream>

using namespace std;


class BankAccount {

    private:
    string accountNumber;
    double accountBalance;
    string customerName;


    public:
      friend void printMenu();

    



    


};


void printMenu(){
    cout << "Welcome to XYZ Bank!" << endl;
    cout << "Enter your number for the following options: " << endl;
    cout << "--------------------------" << endl;
    cout << "1. Create Account" << endl;
    cout << "2. Display All Accounts" << endl;
    cout << "3. Deposit Money" << endl;
    cout << "4. Withdraw Money" << endl;
    cout << "5. Search Account" << endl;
    cout << "6. Delete Account" << endl;
    cout << "7. Exit System" << endl;
    cout << "--------------------------" << endl;
    cout << "Your choice: " << endl;
    
}





int main(){
    printMenu();
    
    return 0;
}