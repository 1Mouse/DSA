#include <iostream>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<numbers>
using namespace std;

int64_t GCD(int64_t x, int64_t y)
{
    int64_t Great;
    for (int64_t i = 1; i <= min(x, y); i++)
    {
        if (x % i == 0 && y % i == 0)
        {
            Great = i;
        }
    }
    return Great;
}


int main()
{
    int64_t x, y;
    cin >> x >> y;
    cout << GCD(x, y) << endl;
}
