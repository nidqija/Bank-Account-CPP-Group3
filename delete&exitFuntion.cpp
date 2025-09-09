#include <iostream>
#include <string>

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
    BankAccount(int accountNumber, double accountBalance, string customerName) {
        this->accountNumber = accountNumber;
        this->accountBalance = accountBalance;
        this->customerName = customerName;
        next = nullptr;
    }

    BankAccount* getNext() {
        return next;
    }

    void setNext(BankAccount* next) {
        this->next = next;
    }
};

class Bank {
private:
    BankAccount* head;

public:
    Bank() {
        head = nullptr;
    }

    ~Bank() {
        BankAccount* current = head;
        while (current != nullptr) {
            BankAccount* temp = current;
            current = current->getNext();
            delete temp;
        }
    }

    void addAccount(int accountNumber, double accountBalance, string customerName) {
        BankAccount* newAccount = new BankAccount(accountNumber, accountBalance, customerName);
        if (head == nullptr) {
            head = newAccount;
        } else {
            BankAccount* current = head;
            while (current->getNext() != nullptr) {
                current = current->getNext();
            }
            current->setNext(newAccount);
        }
        cout << "Account successfully added!" << endl;
    }

    void displayAccount() {
        if (head == nullptr) {
            cout << "No accounts to display!" << endl;
            return;
        }

        BankAccount* current = head;
        cout << "---------------------------------------------\n";
        cout << "Acc Number | Customer Name       | Balance\n";
        cout << "---------------------------------------------\n";
        while (current != nullptr) {
            cout << current->accountNumber << "\t | "
                 << current->customerName << "\t | "
                 << current->accountBalance << "\n ";
            current = current->getNext();
        }
        cout << "===========================================\n";
    }

    void deleteAccount(int accNum) {
        if (head == nullptr) {
            cout << "No accounts to delete!" << endl;
            return;
        }

        if (head->accountNumber == accNum) {
            BankAccount* temp = head;
            head = head->getNext();
            delete temp;
            cout << "Account " << accNum << " deleted successfully!" << endl;
            return;
        }

        BankAccount* prev = head;
        BankAccount* curr = head->getNext();

        while (curr != nullptr && curr->accountNumber != accNum) {
            prev = curr;
            curr = curr->getNext();
        }

        if (curr == nullptr) {
            cout << "Account not found!" << endl;
        } else {
            prev->setNext(curr->getNext());
            delete curr;
            cout << "Account " << accNum << " deleted successfully!" << endl;
        }
    }

    
    void exitSystem() {
        cout << "Exiting system..." << endl;
    }
};

int main() {
    Bank bank;
    int choice;

    do {
        cout << "\nWelcome to XYZ Bank!" << endl;
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
        cout << "Your choice: ";
        cin >> choice;

        int accNum;
        string name;
        double amount;

        switch (choice) {
        case 1:
            cout << "Enter account number: ";
            cin >> accNum;
            cin.ignore();
            cout << "Enter customer name: ";
            getline(cin, name);
            cout << "Enter initial balance: ";
            cin >> amount;
            bank.addAccount(accNum, amount, name);
            break;

        case 2:
            bank.displayAccount();
            break;

        case 6: 
            cout << "Enter account number to delete: ";
            cin >> accNum;
            bank.deleteAccount(accNum);
            break;

        case 7: 
            bank.exitSystem();
            break;

        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
