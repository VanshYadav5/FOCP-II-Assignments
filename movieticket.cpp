#include <iostream>
#include <string>
using namespace std;

class MovieTicket {
private:
    int booked[100][100];
    int count[100];

public:
    MovieTicket() {
        for (int i = 0; i < 100; i++) {
            count[i] = 0;
            for (int j = 0; j < 100; j++) {
                booked[i][j] = 0;
            }
        }
    }

    bool BOOK(int x, int y) {
        if (booked[x][y] == 1 || count[y] >= 100)
            return false;

        booked[x][y] = 1;
        count[y]++;
        return true;
    }

    bool CANCEL(int x, int y) {
        if (booked[x][y] == 0)
            return false;

        booked[x][y] = 0;
        count[y]--;
        return true;
    }

    bool IS_BOOKED(int x, int y) {
        return booked[x][y] == 1;
    }

    int AVAILABLE_TICKETS(int y) {
        return 100 - count[y];
    }

    void Queries() {
        int Q;
        cin >> Q;

        while (Q--) {
            string query;
            cin >> query;

            if (query == "BOOK") {
                int x, y;
                cin >> x >> y;
                cout << BOOK(x, y) << endl;
            }

            else if (query == "CANCEL") {
                int x, y;
                cin >> x >> y;
                cout << CANCEL(x, y) << endl;
            }

            else if (query == "IS_BOOKED") {
                int x, y;
                cin >> x >> y;
                cout << IS_BOOKED(x, y) << endl;
            }

            else if (query == "AVAILABLE_TICKETS") {
                int y;
                cin >> y;
                cout << AVAILABLE_TICKETS(y) << endl;
            }
        }
    }
};

int main() {
    MovieTicket obj;
    obj.Queries();
    return 0;
}
