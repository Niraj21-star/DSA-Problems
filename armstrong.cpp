#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int x, sum = 0, n;
    cout << "Enter a number: ";
    cin >> x;
    n = x;  // store original number
    
    // Count digits
    int digitCount = 0, temp = x;
    while (temp != 0) {
        temp = temp / 10;
        digitCount++;
    }
    //armstrong logic
    temp = x; 
    while (temp != 0) {
        int base = temp % 10;
        sum += pow(base, digitCount);
        temp = temp / 10;
    }
    
    if (n == sum)
        cout << "Armstrong";
    else
        cout << "Not Armstrong";
    
    return 0;
}

