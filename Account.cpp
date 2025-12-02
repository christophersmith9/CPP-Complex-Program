// If ACCOUNT_CPP is not defined, define it (start of header guard)
#ifndef ACCOUNT_CPP
// Define ACCOUNT_CPP to prevent multiple inclusions
#define ACCOUNT_CPP

#include <string>
#include <functional>

#include "Customer.cpp"


class Account {
    protected: 
        Customer customer;
        double bal; // C++ doesn't like variables with the same name as functions.

    public:
        std::string number;

        Account(){}

        Account(std::string numberIn, Customer* customerIn, double balanceIn) {
            number=numberIn;
            customer=*customerIn;
            bal=balanceIn;
        }

        virtual void accrue(double rate){}

        double balance() {
            return bal;
        }

        void deposit(double amount) {
            bal+=amount;
        }
        
        void withdraw(double amount) {
            bal+=amount;
        }
        
        std::string toString() {
            std::stringstream stream;
            stream << std::fixed << std::setprecision(2) << bal;
            return  number + ":" + customer.toString() + ":" + stream.str();
        }

        bool operator==(const Account& a) const {
            return number == a.number;
        }
    
};

class AccountHashfunc {
    public:
        size_t operator()(const Account* a) const {
            return std::hash<std::string>()((*a).number);
        }
};

#endif // ACCOUNT_CPP