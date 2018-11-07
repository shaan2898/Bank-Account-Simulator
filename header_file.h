//
// Created by Shaan Parikh on 3/17/18.
//

#ifndef UNTITLED11_HEADER_FILE_H
#define UNTITLED11_HEADER_FILE_H

#endif //UNTITLED11_HEADER_FILE_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Account {

    int accountNumber;
    string lastName;
    string firstName;
    double accountBalance;
    bool active;

}; //struct to store different information in bank account


void menu(int*); //displays menu

void makeAccount(vector<Account>& ); //makes account

void printAccount(vector<Account>& ); //print account

void transfer(vector<Account>&); //transfer

void PrintAllAccount(vector<Account>&); //print all accounts

void depositAccount(vector<Account>&); // deposit to account

void ActiveDeactive(vector<Account>&); //activate/deactivate account

void withdrawAccount(vector<Account>&); //withdraw from account

void sortAccount(vector<Account>&); // sort the accounts using the account numbers

void deleteAccount(vector<Account>&); //delete account









