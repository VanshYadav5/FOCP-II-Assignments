#include <iostream>
#include <string>
using namespace std;

const int MAX_ACCOUNTS = 1000;

class BankSystem {
private:
    bool accountActive[MAX_ACCOUNTS];
    int accountBalance[MAX_ACCOUNTS];

public:
    BankSystem() {
        for (int i = 0; i < MAX_ACCOUNTS; i++) {
            accountActive[i] = false;
            accountBalance[i] = 0;
        }
    }

    bool createAccount(int userId, int amount) {
        if (!accountActive[userId]) {
            accountActive[userId] = true;
            accountBalance[userId] = amount;
            return true;
        } else {
            accountBalance[userId] += amount;
            return false;
        }
    }

    bool debitAmount(int userId, int amount) {
        if (!accountActive[userId] || accountBalance[userId] < amount)
            return false;

        accountBalance[userId] -= amount;
        return true;
    }

    bool creditAmount(int userId, int amount) {
        if (!accountActive[userId])
            return false;

        accountBalance[userId] += amount;
        return true;
    }

    int getBalance(int userId) {
        if (!accountActive[userId])
            return -1;

        return accountBalance[userId];
    }

    void processQueries() {
        int totalQueries;
        cin >> totalQueries;

        while (totalQueries--) {
            string command;
            cin >> command;

            if (command == "CREATE") {
                int userId, amount;
                cin >> userId >> amount;
                cout << createAccount(userId, amount) << endl;
            }

            else if (command == "DEBIT") {
                int userId, amount;
                cin >> userId >> amount;
                cout << debitAmount(userId, amount) << endl;
            }

            else if (command == "CREDIT") {
                int userId, amount;
                cin >> userId >> amount;
                cout << creditAmount(userId, amount) << endl;
            }

            else if (command == "BALANCE") {
                int userId;
                cin >> userId;
                cout << getBalance(userId) << endl;
            }
        }
    }
};

int main() {
    BankSystem bankObj;
    bankObj.processQueries();
    return 0;
}
