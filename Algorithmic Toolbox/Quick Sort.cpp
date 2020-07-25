#include <iostream>
using namespace std;

//int Partiton (int items[], int Begin, int End){
//
//    int i = Begin;
//    int j = End;
//    int Pivot = i;
//
//    while (true){
//
//        while (items[Pivot] <= items[j] && Pivot!=j){
//            j--;
//        }
//
//
//        if (Pivot == j)
//            break;
//
//        else if (items[Pivot] > items[j]){
//            swap(items[Pivot], items[j]);
//            Pivot = j;
//        }
//
//        while (items[Pivot] >= items[i] && Pivot!=i){
//            i++;
//        }
//
//        if (Pivot == i)
//            break;
//
//        else if (items[Pivot] < items[i]){
//            swap(items[Pivot], items[i]);
//            Pivot = i;
//        }
//    }
//
//    return Pivot;
//}

int Partiton(int items[], int Left, int Right)
{

    int Pivot = items[Left];
    int i = Left;
    int j = Right;

    while (i < j)
    {

        do
        {
            i++;
        } while (items[i] <= Pivot);

        do
        {
            j--;
        } while (items[j] > Pivot);

        if (i < j)
            swap(items[i], items[j]);
    }

    swap(items[Left], items[j]);
    return j;
}

// quick sort function
void quickSort(int items[], int Left, int Right)
{

    if (Left < Right)
    {

        int Pivot = Partiton(items, Left, Right);

        // for sorting leftSubArray
        quickSort(items, Left, Pivot);

        // for sorting rightSubArray
        quickSort(items, Pivot + 1, Right);
    }
}

// print function
void print(int items[], int Size)
{
    cout << "\n\n[ ";
    for (int i = 0; i < Size; i++)
    {
        cout << items[i] << " ";
    }
    cout << "]\n\n\n";
}

/*
Working of Quick Sort [5 3 10 1 2 8]

#1
call quickSort([], 0, 6)
left = 0, right = 6
call Partiton([], 0, 6)
items = [1 3 2 5 10 8]
return j = 3
Pivot = 3

// for sorting leftSubArray
call quickSort([], 0, 3)
left = 0, right = 3
call Partiton([], 0, 3)
items = [1 3 2 5 10 8]
return j = 0
Pivot = 0

// for sorting leftSubArray
call quickSort([], 0, 0)
left = 0, right = 0
XXXXXXXXXXXXXXXXXXXXXXXXXXX



#2
// for sorting rightSubArray
call quickSort([], 1, 3)
left = 1, right = 3
call Partiton([], 1, 3)
items = [1 2 3 5 10 8]
return j = 2
Pivot = 2

// for sorting leftSubArray
call quickSort([], 1, 2)
left = 1, right = 2
call Partiton([], 1, 2)
items = [1 2 3 5 10 8]
return j = 1
Pivot = 1

// for sorting leftSubArray
call quickSort([], 1, 1)
left = 1, right = 1
XXXXXXXXXXXXXXXXXXXXXXXXXXX



#3
// for sorting rightSubArray
call quickSort([], 2, 2)
left = 2, right = 2
XXXXXXXXXXXXXXXXXXXXXXXXXXX



#4
// for sorting rightSubArray
call quickSort([], 3, 3)
left = 3, right = 3
XXXXXXXXXXXXXXXXXXXXXXXXXXX



#5
// for sorting rightSubArray
call quickSort([], 4, 6)
left = 4, right = 6
call Partiton([], 4, 6)
items = [1 2 3 5 8 10]
return j = 5
Pivot = 5

// for sorting leftSubArray
call quickSort([], 4, 5)
left = 4, right = 5
items = [1 2 3 5 8 10]
return j = 4
Pivot = 4

// for sorting leftSubArray
call quickSort([], 4, 4)
left = 4, right = 4
XXXXXXXXXXXXXXXXXXXXXXXXXXX



#6
// for sorting rightSubArray
call quickSort([], 5, 5)
left = 5, right = 5
XXXXXXXXXXXXXXXXXXXXXXXXXXX



#7
// for sorting rightSubArray
call quickSort([], 6, 6)
left = 6, right = 6
XXXXXXXXXXXXXXXXXXXXXXXXXXX


*Sorting Levels*
[ 1 3 2 5 10 8 ]

[ 1 3 2 5 10 8 ]

[ 1 2 3 5 10 8 ]

[ 1 2 3 5 10 8 ]

[ 1 2 3 5 8 10 ]

[ 1 2 3 5 8 10 ]

[ 1 2 3 5 8 10 ]

*/

int main()
{

    int items[6] = {5, 3, 10, 1, 2, 8};
    quickSort(items, 0, 6);
    print(items, 6);
}
