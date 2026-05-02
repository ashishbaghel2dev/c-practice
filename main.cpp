#include<iostream>
#include <map>

using namespace std;

int main()
{
    map<int, map<int ,string>> m;
    
m[122][8] = "one";
m[1][2] = "two";
m[2][1] = "three";

cout << m[122][8] << endl; // Output: one
cout << m[1][2] << endl; // Output: two
cout << m[2][1] << endl; // Output: three

    return 0;
}