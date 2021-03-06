#include <iostream>
using namespace std;

int moneyChange(int Coins[], int numberOfCoins, int Money)
{
    int Table[Money + 1];

    Table[0] = 0;

    for (int i = 1; i <= Money; i++)
        Table[i] = INT_MAX;

    for (int i = 1; i <= Money; i++)
    {

        for (int j = 0; j < numberOfCoins; j++)
            if (Coins[j] <= i)
            {
                int subResult = Table[i - Coins[j]];
                if (subResult != INT_MAX && subResult + 1 < Table[i])
                    Table[i] = subResult + 1;
            }
    }

    for (int i = 0; i <= Money; i++)
        cout << Table[i] << " ";
    cout << endl;
    return Table[Money];
}

int main()
{
    int Coins[3] = {1, 2, 3};
    int Money;
    cin>> Money;
    cout << moneyChange(Coins, 3, Money);
    return 0;
}
