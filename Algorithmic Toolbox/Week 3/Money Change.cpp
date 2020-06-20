#include <iostream>
using namespace std;

//Complexity= Big O(1)
int Coins(int Money) {
    int Coins = Money / 10 + (Money % 10) / 5 + ((Money % 10) % 5) / 1;
    return Coins;
}



int main() {
    int Money;
    cin >> Money;
    cout << Coins(Money);
}
