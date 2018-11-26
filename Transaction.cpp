#include "Transaction.h"
#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

Transaction::Transaction()
{
    m_day = 0;
    m_amount = 0;
    m_description = "Undefined";
}

Transaction::Transaction(int day, double amount, std::string description)
{
    m_day = day;
    m_amount = amount;
    m_description = description;
}

string Transaction::to_string()
{
    string day = std::to_string(m_day);
    string amount = std::to_string(m_amount);
    return (day + " " + amount + " " +  m_description);
}

//Creating read function for Transaction class     
void Transaction::read()
{
    string substr = "";
    string str;
    getline(cin,str);
    int i = 0;

    while (str[i] != ' ')
    {
        substr += str[i] ;
        ++i;
    }
    ++i;
    m_day = atoi(substr.c_str());
    substr = "";
    while (str[i] != ' ')
    {
        substr += str[i] ;
        ++i;
    } 
    i++;
    m_amount = atof(substr.c_str());
    substr = "";
    while (i < str.size())
    {
        substr +=str[i] ;
        ++i;
    }
    m_description = substr;
}

//Declaring get_day function   
double Transaction::get_day()
{
    return m_day;
}    

//Declaring get_amount function 
double Transaction::get_amount()
{
    return m_amount;
}

