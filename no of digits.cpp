#include <iostream>
using namespace std;

class Solution {
public:
    int countDigit(int n) {
        int counter = 0;

        if (n < 0) n = -n;

        while (n > 0) {
            counter++;
            n = n / 10;
        }

        return counter;
    }
};

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    Solution sol;
    int result = sol.countDigit(n);
    cout << "Number of digits: " << result << endl;

    return 0;
}

