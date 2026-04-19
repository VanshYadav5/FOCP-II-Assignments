#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string solve(int n, vector<int>& arr) {

    sort(arr.begin(), arr.end(), greater<int>());

    vector<int> effective;

    for(int i = 0; i < n; ) {
        int val = arr[i];
        int count = 0;

        while(i < n && arr[i] == val) {
            count++;
            i++;
        }

        // add at most twice
        effective.push_back(val);
        if(count > 1) effective.push_back(val);
    }

    int alex = 0, bob = 0;

    for(int i = 0; i < effective.size(); i++) {
        if(i % 2 == 0) alex += effective[i];
        else bob += effective[i];
    }

    if(alex > bob) return "Alex";
    else return "Bob";
}

int main() {

    int T;
    cin >> T;

    while(T--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << solve(n, arr) << "\n";
    }

    return 0;
}