#pragma once

#include <vector>
#include <string>
#include "Transaction.h"

class Account
{
private:
    int balance;
    std::vector<Transaction> log;
    int limit;
public:
    Account();
    std::vector<std::string> Report() const;
    bool Deposit(int amount);
    bool Withdraw(int amount);
    int GetBalance() const { return balance; }
};
