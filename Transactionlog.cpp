#include<iostream>
#include "Transactionlog.h"

using namespace std;

const int MAX_DAY = 30;

void Transactionlog::add(const Transaction &t)
{
    m_transaction.push_back(t);
}
//This is a print function for Transactionlog that will print all transactions as a bank statement. It will also print the daily balance of each day.
void Transactionlog::print()
{
    vector<double> balances = get_daily_balances();
    for(int day=0;day < MAX_DAY;day++)
    {
        std::cout << "\n---------------------\n";
        for(int m=0; m < m_transaction.size(); ++m)
        {
            Transaction trans = m_transaction[m];
            if(trans.get_day() == day+1)
                std::cout << trans.to_string() << std::endl;
        }
        std::cout << "The balance for day " << day+1 << ": " << balances[day] << " "<< "\n---------------------\n";
    }
    print_interest();
}

//Constructing a read function for the Transactionlog class
void Transactionlog::read()
{
    Transaction tran;
    while(! std::cin.eof())
    {
        tran.read();
        add(tran);
    }
}

//Finds the total of transactions and returns the total
double Transactionlog::get_total(int daynum)
{
    double total = 0.0;
    for (int i = 0; i < m_transaction.size(); ++i)
    {
        Transaction trans = m_transaction[i];
        if(trans.get_day() == daynum)
            total += trans.get_amount();
    }
    return total;
}

//Used to get daily balance of each day
vector<double> Transactionlog::get_daily_balances()
{
    vector<double> daily_balances;
    double balance = 0.0;
    for(int day=0;day<MAX_DAY;day++)
    {
        balance += get_total(day+1);
        daily_balances.push_back(balance);
    }
    return daily_balances;
}
//Function that computes and prints the average daily balance and minimum daily balance. It also computes the interest of both.  
void Transactionlog::print_interest()
{
    vector<double> balances = get_daily_balances();
    double lowest = balances[0];
    for(int i = 0;i <MAX_DAY; ++i)
    {
        if(balances[i] < lowest)
            lowest = balances[i];
    }
    double min_interest = lowest * .005;
    cout << "The minimum daily balance is: " << lowest << endl;
    cout << "The interest earned is: " << min_interest << endl;

    double sum = 0.0;
    for(int i = 0; i < MAX_DAY; ++i)
    {
        sum += balances[i];
    }
    double average = sum / MAX_DAY;
    double avg_interest = average *.005;
    cout << "The average daily balance is: " << average << endl;
    cout << "The interest earned is: " << avg_interest << endl;
}

