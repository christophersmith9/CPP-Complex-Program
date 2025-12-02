#include <bits/stdc++.h> // Header to include almost every standard C++ library when compiled by g++. Bad practice in professional development.

#include "Customer.cpp"    // Many C++ IDEs include automatic header file creation.
#include "Account.cpp"
#include "SavingAccount.cpp"
#include "CheckingAccount.cpp"

using namespace std;     // Contains all functions/classes/objects/identifiers that are part of the C++ standard library. Bad practice in professional development.


class Bank {
    // private by default in C++
    unordered_set<Account*, AccountHashfunc> accounts;

    public:
        // Default constructor
        Bank(){}
        
        void add(Account* account) {
            accounts.insert(account);
        }

        void accrue(double rate) {
            for_each(accounts.begin(), accounts.end(), [&rate](Account* acc) { acc->accrue(rate); });
        }

        string toString() {
            string r = "";
            for (const auto& account : accounts) {
                r += account->toString();
                r += "\n";
            }
            return r;
        }


};

int main() {

    Bank* bank = new Bank();

    Customer* c = new Customer(std::string("Ann"));

    CheckingAccount* checkAccOne = new CheckingAccount(std::string("01001"),c,100.00);
    SavingAccount* checkAccTwo = new SavingAccount(std::string("01002"),c,200.00);
    bank->add(checkAccOne);
    bank->add(checkAccTwo);

    bank->accrue(0.02);
    cout << bank->toString() << endl;

    
    return 0;
}