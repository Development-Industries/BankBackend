#include "CheckingAccount.h"

void CheckingAccount::Withdraw(float amount) {
    if (withdrawals >= 10) {
        std::cout << "CheckingAccount: A $5 fee has been applied due to more than 10 withdrawals." << std::endl;
        balance -= 5.0f;
    }
    BaseAccount::Withdraw(amount); // Call the base class Withdraw method
}
