#include <iostream>
#include <vector>
#include<algorithm>

#define ll long long 
#define ld long double
using namespace std;

struct items {
	ll values;
	ll weights;
	ld Fraction_Value;
};

ld get_optimal_value(ll capacity, vector<items> Inputs) {
	ld Current_weight = 0.0;
	ld Optimal_value = 0.0;

	for (ll i = 0; i < Inputs.size(); i++)
	{
		if (capacity >= Inputs[i].weights && (capacity - Current_weight) >= Inputs[i].weights)
		{
			Current_weight += Inputs[i].weights;
			Optimal_value += Inputs[i].values;
		}
		else
		{
			Optimal_value += (capacity - Current_weight) * Inputs[i].Fraction_Value;
		}
	}
	return Optimal_value;
}

bool Compare(items i, items j)
{
	return(i.Fraction_Value > j.Fraction_Value);
}

void disp(vector <items>Inputs)
{
	for (ll i = 0; i < Inputs.size(); i++) {
		cout << Inputs[i].values << "\t" << Inputs[i].weights << "\t" << Inputs[i].Fraction_Value << endl;
		Inputs[i].Fraction_Value = Inputs[i].values / Inputs[i].weights;
	}
}
int main() {
	ll n;
	ll capacity;
	cin >> n >> capacity;
	vector<items> Inputs(n);

	for (ll i = 0; i < n; i++) {
		cin >> Inputs[i].values >> Inputs[i].weights;
		Inputs[i].Fraction_Value = (ld)Inputs[i].values / Inputs[i].weights;
	}
	sort(Inputs.begin(), Inputs.end(), Compare);

	//disp(Inputs);

	ld optimal_value = get_optimal_value(capacity, Inputs);

	cout.precision(10);
	cout << optimal_value << endl;
	return 0;
}
