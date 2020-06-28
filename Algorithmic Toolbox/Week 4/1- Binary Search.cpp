//Binary search an element in a given array
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

//size of arr is a global variable as sizeof() function gave me errors
ll n;

//Recursive way
/*ll Binary_Search_Recursive(ll arr[], ll L, ll R, ll X)
{

    if (R >= L)
    {
        ll mid = L + (R - L) / 2;

        if (arr[mid] == X)
            return mid;
        if (arr[mid] > X)
            return Binary_Search_Recursive(arr, L, mid - 1, X);
        if (arr[mid] < X)
            return Binary_Search_Recursive(arr, mid+1, R, X);
    }

    //if not found
    return -1;
}
*/
//Iterative way
ll Binary_Search_Iterative(ll arr[], ll arr2[], ll i,ll R=n-1,ll L=0)
{
    while (L <= R) {
        ll mid = L + (R - L) / 2;

        // Check if x is present at mid 
        if (arr[mid] == arr2[i])
            return mid;

        // If x greater, ignore left half 
        if (arr[mid] < arr2[i])
            L = mid + 1;

        // If x is smaller, ignore right half 
        else
            R = mid - 1;
    }

    // if we reach here, then element was 
    // not present 
    return -1;
}

int main() {
  
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll k;
    cin >> k;
    ll arr2[k];
    for (ll i = 0; i < k; i++)
    {
        cin >> arr2[i];
    }
    for (ll i = 0; i < k; ++i)
    {
        cout << Binary_Search_Iterative(arr, arr2, i) << " ";
    }


    cout << endl;
    return 0;
}
