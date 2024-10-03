#include "CreditAccount.h"

void CreditAccount::Withdraw(float amount) {
    if (amountSpent + amount > 40.0f) {
        std::cout << "CreditAccount: Spending limit exceeded! A $5000 fee has been applied." << std::endl;
        balance -= 5000.0f;
    }
    else {
        amountSpent += amount;
        BaseAccount::Withdraw(amount);
    }
}
