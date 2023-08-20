#include "Account.h"
using std::vector;
using std::string;
using std::to_string;

Account::Account(): balance(0), limit(50)
{
}

vector<string> Account::Report() const
{
    vector<string> report;
    report.push_back("Balance is " + to_string(balance));
    report.push_back("Transaction: ");

    for (auto t:log){
        report.push_back(t.Report());
    }

    report.push_back("--------------------");

    return report;
}

bool Account::Deposit(int amount)
{
    if (amount <= 0)
    {
        return false;
    }

    balance += amount;
    log.push_back(Transaction(amount, "Deposit"));
    return true;
}

bool Account::Withdraw(int amount)
{
    if (amount <= 0)
    {
        return false;
    }

    if ((balance + limit) >= amount)
    {
        balance -= amount;
        log.push_back(Transaction(amount, "Withdraw"));
        balance -= 1;
        log.push_back(Transaction(1, "Service Charge"));
        return true;
    }
    return false;
}
