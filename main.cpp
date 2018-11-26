/*
File: main.cpp
Description: The purpose of this program is to keep track of and print all transactions made in a 30-day period. Transactions include all deposits and withdrawals.This program will also compute the interest earned by using the minimum and average daily balances. 
Author: Ankur Solanky
Email: solankya142127@student.vvc.edu
Date Created: Tue Nov  6 18:20:25 PST 2018
*/

#include "Transaction.h"
#include "Transactionlog.h"
#include<iostream>
#include<vector>

int main()
{
    Transactionlog tl;
    tl.read();
    tl.print();

    return 0;
}

