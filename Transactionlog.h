#ifndef TRANSACTIONLOG_H
#define TRANSACTIONLOG_H
#include "Transaction.h"
#include<vector>
using namespace std;

//This class will be used for Transactionlog and Transactionlog.cpp
class Transactionlog
{
    std::vector<Transaction> m_transaction;
    double get_total(int daynum);

public:
    void add(const Transaction &t);
    void read();
    void print();
    vector<double> get_daily_balances();
    void print_interest();
};

#endif

