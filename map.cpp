#include<iostream>
#include<algorithm>
#include <vector>
using namespace std;

int main()
{
  vector<int> arr = {5, 2, 9, 1, 5, 6};
    int n = arr.size();
    sort(arr.begin(), arr.end());
    cout << "Sorted array: ";
   for(int i: arr) {
        cout << i << " ";
    }
    cout << endl;


    return 0;
}