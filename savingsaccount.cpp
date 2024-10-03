#include "SavingsAccount.h"

void SavingsAccount::Withdraw(float amount) {
    if (withdrawals >= 3) {
        std::cout << "SavingsAccount: Withdrawal limit reached. No more withdrawals allowed." << std::endl;
    }
    else {
        BaseAccount::Withdraw(amount);
    }
}
