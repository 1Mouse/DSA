//Binary search an element in a given array
#include <iostream>
using namespace std;

//Recursive way
int Binary_Search_Recursive(int arr[], int L, int R, int X)
{
    
    if (R >= L)
    {
        int mid = L + (R - L) / 2;

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

//Iterative way
int Binary_Search_Iterative(int arr[], int L, int R, int X)
{
    while (L <= R) {
        int mid = L + (R - L) / 2;

        // Check if x is present at mid 
        if (arr[mid] == X)
            return mid;

        // If x greater, ignore left half 
        if (arr[mid] < X)
            L = mid + 1;

        // If x is smaller, ignore right half 
        else
            R = mid - 1;
    }

    // if we reach here, then element was 
    // not present 
    return -1;
}

int main() 
{
    int arr[8] = { 1,2,3,4,5,6,7,8};

    //L is left, R is Right, X is the item we search for
    int L = 0, R = 7, X = 3;

    int Found_Index= Binary_Search_Recursive(arr, L, R, X);
    cout << arr[Found_Index] << " Found at index  " << Found_Index << endl;
}
