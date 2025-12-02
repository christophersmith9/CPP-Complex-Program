// If CUSTOMER_CPP is not defined, define it (start of header guard)
#ifndef CUSTOMER_CPP
// Define CUSTOMER_CPP to prevent multiple inclusions
#define CUSTOMER_CPP

#include <string>

class Customer {
    std::string name;

    public:
        Customer(std::string nameIn) : name(nameIn) {}; // C++ has this nice way to make constructors with :
        Customer(){}

        std::string toString() {
            return name;
        }
};

#endif // CUSTOMER_CPP
