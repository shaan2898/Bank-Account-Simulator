#include <iostream>
#include <iomanip>

using std::setw;
using std::setprecision;
using std::fixed;
using std::showpoint;

#include <cstdlib>
using std::rand;
using std::srand;

#include <ctime>
using std::time;

#include <vector>
using std::vector;
#include <algorithm>



using namespace std;

#include "header_file.h"


int main() {


    vector <Account> bankAccounts;


    //vector of list of accounts
    int input = 0;

    bool loop = true;

    //transfer if person doesnt have enough money
    do {
        menu(&input);

//switch case to select menu options
        switch (input) {

            case 1:
                makeAccount(bankAccounts); //Calls Make Account function
                break;
            case 2:
                depositAccount(bankAccounts); // Calls Deposit Account function
                break;
            case 3:
                withdrawAccount(bankAccounts); // Calls Withdraw Account function
                break;
            case 4:
                transfer(bankAccounts); // Calls Transfer Function
                break;
            case 5:
                printAccount(bankAccounts); // Calls Print Account function
                break;
            case 6:
                ActiveDeactive(bankAccounts); // Calls Active Deactive function
                break;
            case 7:
                deleteAccount(bankAccounts); // Calls Delete Account function
                break;
            case 8:
                PrintAllAccount(bankAccounts); // Calls Print All Accounts function
                break;
            case 9:
                cout <<"Bank is closed!" << endl; // Closes bank
                loop = false; // Exit while loop
                break;
        }

    }
       while (loop);

    return 0;

}