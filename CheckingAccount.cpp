// If CA_CPP is not defined, define it (start of header guard)
#ifndef CA_CPP
// Define CA_CPP to prevent multiple inclusions
#define CA_CPP

#include <string>

#include "Account.cpp"
#include "Customer.cpp"

class CheckingAccount : public Account {
    public:
        CheckingAccount(std::string numberIn, Customer* customerIn, double balanceIn) {
            number=numberIn;
            customer=*customerIn;
            bal=balanceIn;
        }

        void accrue(double rate) {}
};

#endif // CA_CPP