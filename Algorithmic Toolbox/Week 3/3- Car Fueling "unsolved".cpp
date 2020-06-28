// Time Complexity: O(N)
#include <iostream>
#include <vector>

using namespace std;

int optimal(int dist, int max_travel, int n,vector<int>stops)
{
    int counter = 0,walked=0;
    for (int j = 0; j < stops.size(); j++)
    {
        for (int i = j + 1; i < stops.size(); i++)
        {
            if (walked >= dist)
            {
                return counter;
            }
            if (stops[i] - stops[j] > max_travel)
            {
                walked += (stops[i - 1] - stops[j]);
                j = i - 1;
                counter++;
            }
        }
    }
    if (walked < dist)
        return -1;
}


int main() 
{
    int dist, max_travel, n;
    vector <int> stops;
    //vector size is ( n stops +2 ) the 2 is start and end position
    stops[0] = 0;
    cin >> dist >> max_travel >> n;
    for (int i = 1; i < n + 1; i++)
    {
        cin >> stops[i];
    }
    stops[n + 1] = dist;
    cout << optimal(dist, max_travel,n, stops)<<endl;
}
