#include "BaseAccount.h"

void BaseAccount::Withdraw(float amount) {
    balance -= amount;
    withdrawals++;
}

void BaseAccount::Deposit(float amount) {
    balance += amount;
}
