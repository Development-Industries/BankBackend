#ifndef BASEACCOUNT_H
#define BASEACCOUNT_H

class BaseAccount {
protected:
    float balance;
    int withdrawals;

public:
    BaseAccount() : balance(0.0f), withdrawals(0) {}
    virtual ~BaseAccount() {}

    virtual void Withdraw(float amount); // Virtual function to be overridden
    virtual void Deposit(float amount);  // Virtual function to be overridden

    float GetBalance() const { return balance; } // Returns the current balance
};

#endif // BASEACCOUNT_H
