#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "BaseAccount.h"
#include <iostream>

class SavingsAccount : public BaseAccount {
public:
    SavingsAccount() : BaseAccount() {}
    void Withdraw(float amount) override; // Override the Withdraw method
};

#endif // SAVINGSACCOUNT_H
