//
// Created by Shaan Parikh on 3/17/18.
//

#include "header_file.h"
#include <ctime>
#include <vector>
#include <ctime>
#include <string>
#include <algorithm>
#include <iomanip>



void menu(int *num) {

    int select = 0;
    cout << "Welcome! Select options below:" << endl;

    cout << "\t1. Make new account."
         << "\n\t2. Deposit to an account."
         << "\n\t3. Withdraw from an account."
         << "\n\t4. Transfer money."
         << "\n\t5. Print account."
         << "\n\t6. Activate/Deactivate an account."
         << "\n\t7. Delete an account."
         << "\n\t8. Display all accounts."
         << "\n\t9. Quit."
         << endl;

    cout << "Selection:\t";
    cin >> select;

// While loops will check if the input is valid or invalid, and will prompt the user to plug in valid input
    while (select < 1 || select > 9)
    {
        cout << "Enter number from 1-9." << endl;
        cin >> select;
        while (!select){
            cout << "Invalid Input.\nEnter new number" << endl;
            cin.clear();
            cin.ignore(10000,'\n');
            cin >> select;
        }
    }
    while (!select)
    {
        cout << "Invalid Input.\nEnter new number" << endl;
        cin.clear();
        cin.ignore(10000,'\n');
        cin >> select;
        while (select < 1 || select > 9){
            cout << "Enter number from 1-9." << endl;
            cin >> select;
        }
    }
    //

    *num = select;

}

void makeAccount(vector<Account>& Accounts ) {

    int acc;
    string first;
    string last;
    double start;

    srand(time(0));
    acc = (rand() % 9000) + 1000; // Gets a random 4 digit number


    cout << "Creating bank account number: " << acc << endl;
    cout << "\n" << endl;
    cout << "Enter first name: " << endl;
    cin >> first; // user inputs name
    cout << "Enter last name: " << endl;
    cin >> last; // user inputs name
    cout << "Enter starting balance" << endl;
    cin >> start; // user inputs starting balance

    // While loops will check if the input is valid or invalid, and will prompt the user to plug in valid input
    while (start < 0){
        cout << "Enter positive number"<<endl;
        cin >> start;
            while (!start){
                cout << "Invalid Input.\nEnter new number" << endl;
                cin.clear();
                cin.ignore(120,'\n');
                cin >> start;
            }
    }
    while (!start ){
        cout << "Invalid Input.\nEnter new number" << endl;
        cin.clear();
        cin.ignore(120,'\n');
        cin >> start;
        while (start < 0){
            cout << "Enter positive number" << endl;
            cin >> start;
        }
    }
//All the information sent into the vector in struct format

        Account user;
        user.accountBalance = start;
        user.accountNumber = acc;
        user.active = true;
        user.firstName = first;
        user.lastName = last;
        Accounts.push_back(user);

        sortAccount(Accounts); // sorts the bank accounts as they are created




}


void printAccount(vector<Account>& Accounts){



    int acc;

    cout << "Enter account number to print: " << endl;
    cin >> acc;

    // While loops will check if the input is valid or invalid, and will prompt the user to plug in valid input
    while (acc < 0){
        cout << "Enter positive number"<<endl;
        cin >> acc;
        while (!acc){
            cout << "Invalid Input.\nEnter new number" << endl;
            cin.clear();
            cin.ignore(120,'\n');
            cin >> acc;
        }
    }
    while (!acc){
        cout << "Invalid Input.\nEnter new number" << endl;
        cin.clear();
        cin.ignore(120,'\n');
        cin >> acc;
        while (acc < 0){
            cout << "Enter positive number" << endl;
            cin >> acc;
        }
    }
//for loop will locate vector that user inputs, and will display all of the account information stored in the vector
for (int i = 0; i < Accounts.size(); i++){


    if (Accounts[i].accountNumber == acc) {
        if(Accounts[i].active ) {


            cout << "\n" << setw(20)
                 << "Account Number: " << Accounts[i].accountNumber

                 << "   " << "Balance: $" << Accounts[i].accountBalance
                 << "\n" << setw(20)
                 << "First name: " << Accounts[i].firstName

                 << "  " << "Last name: " << Accounts[i].lastName
                 << "\n"
                 << endl;
        }
        else
            cout << "Account is not active. Process cannot be done! First, you need to\n"
                    "activate this account."<<endl; //if account not active, will display message
    }else
    cout << "This account does not exist."<<endl;


}
    }

void transfer(vector<Account>& Accounts) {

    int send, to;
    double amount;

    cout << "Enter account number for the sender: " << endl;
    cin >> send;

    cout << "Enter account number for the receiver: " << endl;
    cin >> to;

    cout << "Enter amount to be transferred: " << endl;
    cin >> amount;

//for loops will locate both vectors to transfer money
    for (int i = 0; i < Accounts.size(); i++) {

        for (int j = 0; j < Accounts.size(); j++) {

            if (Accounts[i].accountNumber == send) {
                //checks if accounts are active
                if (Accounts[i].active && Accounts[j].active) {
                    //checks if account has enough money to transfer
                    if (Accounts[i].accountBalance >= amount) {

                        if (Accounts[j].accountNumber == to) {

                            //transfers money from both accounts
                            Accounts[i].accountBalance = Accounts[i].accountBalance - amount;
                            Accounts[j].accountBalance = Accounts[j].accountBalance + amount;
                        }
                    }
                    else cout<<"Account doesn't have enough money"<<endl;
                    break;
                }else
                    cout
                            << "One or both accounts are not active. Process cannot be done! First, you need to\n"
                                    "activate both accounts." << endl;

                        // if accounts not active or have enough money, will output a message to user
            }

        }
    }
}

void PrintAllAccount(vector<Account>& Accounts){

//for loops locate all of the bank accounts stored in the vector
    for (int i = 0 ; i < Accounts.size() ; i++ ) {


            if (Accounts[i].active) {

                    //outputs every account found in the vector
                cout << "\n" << setw(20)
                     << "Account Number: " << Accounts[i].accountNumber

                     << "   " << "Balance: $" << Accounts[i].accountBalance
                     << "\n" << setw(20)
                     << "First name: " << Accounts[i].firstName

                     << "  " << "Last name: " << Accounts[i].lastName
                     << "\n"
                     << endl;
            } else
                cout << setw(12)<< "Account " << Accounts[i].accountNumber << " is not active. Process cannot be done! \n"
                        "    First, you need to activate this account.\n"<< endl;
        }

    }



void depositAccount(vector<Account>& Accounts) {

    int num;
    double amount;

    cout << "Enter account number for deposit: " << endl;
    cin >> num;
    // While loops will check if the input is valid or invalid, and will prompt the user to plug in valid input
    while (num < 0){
        cout << "Enter positive number"<<endl;
        cin >> num;
        while (!num ){
            cout << "Invalid Input.\nEnter new number" << endl;
            cin.clear();
            cin.ignore(120,'\n');
            cin >> num;
        }
    }
    while (!num ){
        cout << "Invalid Input.\nEnter new number" << endl;
        cin.clear();
        cin.ignore(120,'\n');
        cin >> amount;
        while (num < 0){
            cout << "Enter positive number" << endl;
            cin >> num;
        }
    }
    //
    cout << "Enter amount to be deposited: " << endl;
    cin >> amount;
    // While loops will check if the input is valid or invalid, and will prompt the user to plug in valid input
    while (amount < 0){
        cout << "Enter positive number"<<endl;
        cin >> amount;
        while (!amount && (amount != 0)){
            cout << "Invalid Input.\nEnter new number" << endl;
            cin.clear();
            cin.ignore(120,'\n');
            cin >> amount;
        }
    }
    while (!amount && (amount != 0)){
        cout << "Invalid Input.\nEnter new number" << endl;
        cin.clear();
        cin.ignore(120,'\n');
        cin >> amount;
        while (amount < 0){
            cout << "Enter positive number" << endl;
            cin >> amount;
        }
    }
//for loop will locate vector
    for (int i = 0; i < Accounts.size(); i++) {


        if (Accounts[i].active) {

            if (Accounts[i].accountNumber == num) {

                Accounts[i].accountBalance = Accounts[i].accountBalance + amount;      //will add amount to user account
            }
        }
        else cout<<"Account is not active. Process cannot be done! First, you need to\n"
                    "activate this account."<<endl;
    }
}
void withdrawAccount(vector<Account>& Accounts){

    int num;
    double amount;

    cout << "Enter account number for withdrawal: " << endl;
    cin >> num;
// While loops will check if the input is valid or invalid, and will prompt the user to plug in valid input
    while (num < 0){
        cout << "Enter positive number"<<endl;
        cin >> num;
        while (!num ){
            cout << "Invalid Input.\nEnter new number" << endl;
            cin.clear();
            cin.ignore(120,'\n');
            cin >> num;
        }
    }
    while (!num ){
        cout << "Invalid Input.\nEnter new number" << endl;
        cin.clear();
        cin.ignore(120,'\n');
        cin >> num;
        while (num < 0){
            cout << "Enter positive number" << endl;
            cin >> num;
        }
    }
//
    cout << "Enter amount to be withdrawn: " << endl;
    cin >> amount;
// While loops will check if the input is valid or invalid, and will prompt the user to plug in valid input
    while (amount < 0){
        cout << "Enter positive number"<<endl;
        cin >> amount;
        while (!amount ){
            cout << "Invalid Input.\nEnter new number" << endl;
            cin.clear();
            cin.ignore(120,'\n');
            cin >> amount;
        }
    }
    while (!amount){
        cout << "Invalid Input.\nEnter new number" << endl;
        cin.clear();
        cin.ignore(120,'\n');
        cin >> amount;
        while (amount < 0){
            cout << "Enter positive number" << endl;
            cin >> amount;
        }
    }
//for loop locates vector
    for (int i = 0; i < Accounts.size(); i++) {

        if (Accounts[i].accountBalance >= amount) {


            if (Accounts[i].active) {

                if (Accounts[i].accountNumber == num) {

                    Accounts[i].accountBalance = Accounts[i].accountBalance - amount; //will subtract amount from user account
                }

            } else
                cout << "Account is not active. Process cannot be done! First, you need to\n"
                        "activate this account." << endl;
        }else
        cout << "Account does not have enough money."<<endl;
    }
}

void deleteAccount(vector<Account>& Accounts){

    int acc;

    cout << "Enter account number to be deleted: " << endl;
    cin >> acc;
// While loops will check if the input is valid or invalid, and will prompt the user to plug in valid input
    while (acc < 0){
        cout << "Enter positive number"<<endl;
        cin >> acc;
        while (!acc){
            cout << "Invalid Input.\nEnter new number" << endl;
            cin.clear();
            cin.ignore(120,'\n');
            cin >> acc;
        }
    }
    while (!acc ){
        cout << "Invalid Input.\nEnter new number" << endl;
        cin.clear();
        cin.ignore(120,'\n');
        cin >> acc;
        while (acc < 0){
            cout << "Enter positive number" << endl;
            cin >> acc;
        }
    }

//

    for(int i = 0; i < Accounts.size(); i++)
    {
        if(Accounts[i].accountNumber == acc)
        {
            Account user = Accounts[i];
            Accounts.erase(Accounts.begin() + i ); // will erase or delete account that user inputted
        }

        }
    }


void ActiveDeactive(vector<Account>& Accounts)
{

    int acc, ad;

    cout << "Enter account number for activation/deactivation: " << endl;
    cin >> acc;

    cout << "Press 1 to activate, 0 to deactivate: " << endl;
    cin >> ad;

    for (int i = 0; i <Accounts.size(); i++)
    {
        if(Accounts[i].accountNumber == acc)
        {

            if(ad == 1 )
            {
                Accounts[i].active = true; //activates account when user inputs 1
            }
            if(ad == 0)
            {
                Accounts[i].active = false; //deactivates account when user inputs 0
            }
        }
    }
}

void sortAccount(vector<Account>& Accounts){
    bool swapp;

    do{
        swapp = false;
        for(int i= 0; i < (Accounts.size()-1) ;i++)
        {
            if(Accounts[i].accountNumber > Accounts[i+1].accountNumber)
            {
                swap(Accounts[i],Accounts[i+1]); //will swap accounts to place them from least to greatest by account number
                swapp = true;
            }
        }
    } while (swapp);
}

