#include <iostream>
#include<cstdlib>
using namespace std;


long long int lcm_naive(long long int a, long long int b)
{
    for (long long int l = 1; l <= (long long int)a * b; ++l)
        if (l % a == 0 && l % b == 0)
            return l;

    return (long long int)a * b;
}

long long int gcd_euclid(long long int a, long long int b) 
{
    if (b == 0)
        return a;
    else
        return gcd_euclid(b, a % b);
}

long long int lcm_opt(long long int a, long long int b) 
{
    long long int lcm = (a * b) / gcd_euclid(a, b);
    return lcm;
}

void test(long long int& a, long long int& b)
{
    a = rand() % 100000;
    b = rand() % 100000;
    cout << a << " " << b << endl;
    
}

int main() {
    
   long long int a, b;
   cin >> a >> b;
   //srand(time(0));
   // test(a,b);
   //cout << lcm_naive(a, b) << endl;
    cout << lcm_opt(a, b) << endl;
    return 0;
}
