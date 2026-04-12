#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int a[100000];  

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int operations = 0;

    
    for(int i = 0; i <= n - k; i++) {
        if(a[i] == 1) {
            
            for(int j = i; j < i + k; j++) {
                if(a[j] == 1)
                    a[j] = 0;
                else
                    a[j] = 1;
            }
            operations++;
        }
    }

    // Check remaining elements
    for(int i = n - k + 1; i < n; i++) {
        if(a[i] == 1) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << operations << endl;

    return 0;
}