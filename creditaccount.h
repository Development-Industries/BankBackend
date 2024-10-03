#ifndef CREDITACCOUNT_H
#define CREDITACCOUNT_H

#include "BaseAccount.h"
#include <iostream>

class CreditAccount : public BaseAccount {
private:
    int amountSpent;

public:
    CreditAccount() : BaseAccount(), amountSpent(0) {}
    void Withdraw(float amount) override; // Override the Withdraw method
};

#endif // CREDITACCOUNT_H
