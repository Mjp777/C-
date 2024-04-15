You are given  integers.Sort the  integers and print the sorted order.
Store the  integers in a vector.Vectors are sequence containers representing arrays that can change in size.

  #include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    for (int i = 0; i < n; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;   
    return 0;
}
