//Recursive program to linearly search an element in a given array
#include <iostream>
using namespace std;

int Linear_Search(int arr[], int L, int R, int X)
{
    //Termination condition in case the item is not found
    if (R < L)
        return -1;

    if (arr[L] == X)
        return L;
    if (arr[R] == X)
        return R;
    //Recursive
    return (Linear_Search(arr, L+1, R-1, X));
}

int main() 
{
    int arr[5] = { 1,2,3,4,5 };

    //L is left, R is Right, X is the item we search for
    int L = 0, R = 4, X = 3;

    int Found_Index= Linear_Search(arr, L, R, X);
    cout << arr[Found_Index] << " Found at index  " << Found_Index << endl;
}
