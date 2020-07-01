//Naive solution for Polynomial Multiplication

//in this program we needed to return an array from a function 
//this process can happen by 3 ways "mentioned in the following link
//https://www.geeksforgeeks.org/return-local-array-c-function/

#include <iostream>
using namespace std;

// A[] represents coefficients of first polynomial 
// B[] represents coefficients of second polynomial 
// m and n are sizes of A[] and B[] respectively 
int* multiply(int A[], int B[], int m, int n)
{
    int* prod = new int[m + n - 1];
   
    // Initialize the porduct polynomial 
    for (int i = 0; i < m + n - 1; i++)
    {
        prod[i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        // Multiply the current term of first polynomial 
        // with every term of second polynomial. 
        for (int j = 0; j < n; j++)
            prod[i + j] += A[i] * B[j];
    }

    return prod;
}
void printPoly(int A[], int m)
{
    for (int i = 0; i < m; i++)
    {
        cout << A[i];
        if (i != 0)
            cout << "x^" << i;
        if (i != m - 1)
            cout << " + ";
    }
    cout << endl;
}

int main()
{

    // The following array represents polynomial 5 + 10x^2 + 6x^3 
    int A[] = { 5, 0, 10, 6 };
    // The following array represents polynomial 1 + 2x + 4x^2 
    int B[] = { 1, 2, 4 };

    int m = sizeof(A) / sizeof(A[0]);
    int n = sizeof(B) / sizeof(B[0]);

    cout << "First polynomial is A\n";
    printPoly(A, m);
    cout << "Second polynomial is B\n";
    printPoly(B, n);

    int* C = multiply( A, B,  m,  n);

    cout << "Product polynomial is C\n";
    printPoly(C, m + n - 1);
}
