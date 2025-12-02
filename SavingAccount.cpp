// If SA_CPP is not defined, define it (start of header guard)
#ifndef SA_CPP
// Define SA_CPP to prevent multiple inclusions
#define SA_CPP

#include <string>

#include "Account.cpp"
#include "Customer.cpp"

class SavingAccount : public Account {
    double interest=0;

    public:
        SavingAccount(std::string numberIn, Customer* customerIn, double balanceIn) {
            number=numberIn;
            customer=*customerIn;
            bal=balanceIn;
        }

        void accrue(double rate) override {
            interest += bal * rate;
            bal += bal * rate;
        }
};

#endif // SA_CPP