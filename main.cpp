#include <iostream>
#include <crtdbg.h>
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "CreditAccount.h"
#include "fstream"


// Memory leak detection setup
#define MEMORY_LEAK_LINE -1

void Deposit(BaseAccount* account, float amount) {
    account->Deposit(amount);
    std::cout << "$" << amount << " deposited!" << std::endl;
}

void Withdraw(BaseAccount* account, float amount) {
    account->Withdraw(amount);
    std::cout << "$" << amount << " withdrawn!" << std::endl;
}

int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    _CrtSetBreakAlloc(MEMORY_LEAK_LINE);

    // Create instances of each account type on the heap
    CheckingAccount* checking = new CheckingAccount();
    SavingsAccount* savings = new SavingsAccount();
    CreditAccount* credit = new CreditAccount();

    // Attempt to open the binary file for reading
    std::ifstream inFile("account_balances.bin", std::ios::binary);
    if (inFile.is_open()) {
        // Local variables to hold the read balances
        float checkingBalance, savingsBalance, creditBalance;

        // Read the balances in the same order they were written
        inFile.read(reinterpret_cast<char*>(&checkingBalance), sizeof(float));
        inFile.read(reinterpret_cast<char*>(&savingsBalance), sizeof(float));
        inFile.read(reinterpret_cast<char*>(&creditBalance), sizeof(float));

        // Set the account balances
        checking->Deposit(checkingBalance);
        savings->Deposit(savingsBalance);
        credit->Deposit(creditBalance);

        inFile.close();
        std::cout << "Account balances loaded from 'account_balances.bin'." << std::endl;
    }
    else {
        // If the file does not exist, proceed with the original initialization
        checking->Deposit(1000);
        savings->Deposit(500);
        credit->Deposit(100);
    }

    int choice = 0;
    float amount;

    while (true) {
        std::cout << "\nBanking Menu:\n";
        std::cout << "1. Deposit to Checking\n";
        std::cout << "2. Withdraw from Checking\n";
        std::cout << "3. Deposit to Savings\n";
        std::cout << "4. Withdraw from Savings\n";
        std::cout << "5. Deposit to Credit\n";
        std::cout << "6. Withdraw from Credit\n";
        std::cout << "7. Show Balances\n";
        std::cout << "8. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 8:
            // Saving account balances to a binary file before exiting
            std::ofstream outFile("account_balances.bin", std::ios::binary);
            if (outFile) {
                float checkingBalance = checking->GetBalance();
                float savingsBalance = savings->GetBalance();
                float creditBalance = credit->GetBalance();

                outFile.write(reinterpret_cast<const char*>(&checkingBalance), sizeof(float));
                outFile.write(reinterpret_cast<const char*>(&savingsBalance), sizeof(float));
                outFile.write(reinterpret_cast<const char*>(&creditBalance), sizeof(float));
                outFile.close();
                std::cout << "Account balances saved to 'account_balances.bin'." << std::endl;
            }
            else {
                std::cout << "Error opening file to save balances." << std::endl;
            }

            // Memory cleanup
            delete checking;
            delete savings;
            delete credit;
            return 0;
            // Additional cases handling other menu options...
        }
    }

    return 0;  // This line is typically not reached; provided for completeness
}
