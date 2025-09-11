#include <iostream>
#include <string>
#include <limits>

using namespace std;
class BankAccount {

    private:
    int accountNumber;
    double accountBalance;
    string customerName;
    BankAccount* next;

    public:
      friend void printMenu();
      friend class Bank;

      BankAccount() = default;
      BankAccount(int accountNumber , double accountBalance , string customerName){
        this->accountNumber = accountNumber;
        this->accountBalance = accountBalance;
        this->customerName = customerName;
        next = nullptr;
      }

      BankAccount* getNext(){
        return next;
      }

      void setNext(BankAccount* next){
        this->next = next;
      }

      int getAccountNumber() { 
        return accountNumber; }
      
      double getAccountBalance() {
        return accountBalance; }
      
      string getCustomerName() {
        return customerName; }
};

class Bank {
     private:
       BankAccount *head;

     public:
       Bank(){
        head = nullptr;
       }

       ~Bank(){
        BankAccount* current = head;
        while (current != nullptr) {
            BankAccount* temp = current;
            current = current->getNext();
            delete temp;
        }
       }

       void addAccount(int accountNumber , double accountBalance , string customerName){
         BankAccount* newAccount = new BankAccount(accountNumber , accountBalance , customerName);
         if (head == nullptr){
            head = newAccount;

         } else {
            BankAccount* current = head;
            while(current->getNext() != nullptr){
                current = current->getNext();
            }
            current->setNext(newAccount);
         }

         cout << "Account successfully added!" << endl;
       }


     void displayAccount(){
        if(head == nullptr){
            cout << "No accounts to display!" << endl;
            return;
        }

        BankAccount* current = head;
        cout << "---------------------------------------------\n";
        cout << "Acc Number | Customer Name       | Balance\n";
        cout << "---------------------------------------------\n";
        while (current != nullptr){
            cout << current->accountNumber << "\t | "
                 << current->customerName << "\t | "
                 << current->accountBalance << "\n ";
                 current = current->getNext();

        }

        cout << "===========================================\n";
     }

        BankAccount* searchAccount (int accountNumber) {
          BankAccount* current = head;
          while (current != nullptr) {
            if (current-> accountNumber == accountNumber)
              return current;
              current = current->getNext();
          }
          return nullptr;
        }

     void deposit (int accountNumber, double amount) {
      BankAccount* account = searchAccount (accountNumber);
      if (!account) {
        cout << "Account not found!" << endl;
        return;
      }
      account->accountBalance += amount;
      cout << "Deposit successful! New balance: " << account -> accountBalance << endl;
     }
    
     void withdraw (int accountNumber, double amount) { 
      BankAccount* account = searchAccount (accountNumber);
      if (!account) {
        cout << "Account not found!" << endl;
        return;
      }
      if (amount > account -> accountBalance) {
        cout << "Balance Insufficient! " << endl;
        return;
      }
      account -> accountBalance -= amount;
      cout << "Withdrawal successful! New Balance: " << account -> accountBalance << endl;
     }
};

int main(){
    Bank bank;
    int choice;

    do{
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
    cin >> choice;

    int accNum;
    string name;
    double amount;

      if (cin.fail() || choice < 1 || choice > 7) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid choice! Enter a number between 1 and 7." << endl;
                continue;
            }
    switch(choice){
        case 1:{
    
    while (true) {
        cout << "Enter account number: ";
        cin >> accNum;

        if (cin.fail() || accNum <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid account number! Must be a positive integer." << endl;
            continue;
        }

        if (bank.searchAccount(accNum) != nullptr) {
            cout << "Account number already exists! Try again." << endl;
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        break; 
    }

  
    while (true) {
        cout << "Enter customer name: ";
        getline(cin, name);

        bool isValid = true;
        if (name.empty()) {
            cout << "Customer name cannot be empty!" << endl;
            continue;
        } 

        for (char c : name) {
           if(isdigit(c)){
            isValid = false;
            break;
           }
        }

        if(!isValid){
          cout << "Customer name cannot contain numbers!" << endl;
          continue;
        }
        break;
    }

   
    while (true) {
        cout << "Enter initial balance: ";
        cin >> amount;
        if (cin.fail() || amount < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Initial balance cannot be negative!" << endl;
            continue;
        }

        bool isValid = true;

        for (char c : to_string(amount)){
          if(isalpha(c)){
             isValid = false;
             break;
          }
        }

        if(!isValid){
          cout << "Initial balance must be a valid number!" << endl;
          continue;
        }
        break;
    }

    bank.addAccount(accNum, amount, name);
    break;
}
        case 2:
          bank.displayAccount();
          break;

        case 3:
          while (true) {
            cout << "Enter account number: ";
            cin >> accNum;

          if (cin.fail() || accNum <= 0) {
            cin.clear();

            cin.ignore (numeric_limits < streamsize > :: max (), '\n' );
            cout << "Invalid account number! Must be a positive integer." << endl;
            continue;
          }

            cin.ignore (numeric_limits < streamsize > :: max (), '\n');
            break;
          }
          
          cout << "Enter deposit amount: " << endl;
          cin >> amount;
          bank.deposit (accNum, amount);
          break;

        case 4: 
        while (true) {
          cout << "Enter account number: " << endl;
          cin >> accNum;

          if (cin.fail() || accNum <= 0) {} {
            cin.clear ();

            cin.ignore (numeric_limits < streamsize > :: max (), '\n' );
            cout << "Invalid account number! Must be a positive integer." << endl;
            continue;
          }

           cin.ignore (numeric_limits < streamsize > :: max (), '\n');
           break;
        }
          cout << "Enter withdraw amount: " << endl;
          cin >> amount;
          bank.withdraw (accNum, amount);
          break;

        case 5:
        while (true) {
          cout << "Enter account number to search: " << endl;
          cin >> accNum;

          if (cin.fail() || accNum <= 0) {
            cin.clear ();

            cin.ignore (numeric_limits < streamsize > :: max (), '/n');
            cout << "Invalid account number! Must be a positive integer." << endl;
            continue;
          } 
            cin.ignore (numeric_limits < streamsize > :: max (), '/n');
            break;
        }
          {
            BankAccount* account = bank.searchAccount (accNum);
            if (account) {
              cout << "Account Found!" << endl;
              cout << "Account Number: " << account -> getAccountNumber()  << endl;
              cout << "Customer Name: " << account -> getCustomerName() << endl;
              cout << "Account Balance: " << account -> getAccountBalance() << endl;
            } 
            else {
              cout << "Account not Found!" << endl;
            }
          }
          break;
    }
    } while (choice != 7);
    
    return 0;
}