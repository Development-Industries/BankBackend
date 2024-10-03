#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "BaseAccount.h"
#include <iostream>

class CheckingAccount : public BaseAccount {
public:
    CheckingAccount() : BaseAccount() {}
    void Withdraw(float amount) override; // Override the Withdraw method
};

#endif // CHECKINGACCOUNT_H
