#include <iostream>
using namespace std;

void fast() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
//Euclid's Algorithm for GCD
int64_t GCD(int64_t x, int64_t y)
{
	if (y == 0)
		return x;
	else
		return GCD(y, x % y);
}


int main()
{
	fast();
	int64_t x, y;
	cin >> x >> y;
	cout << GCD(x, y) << endl;
}
