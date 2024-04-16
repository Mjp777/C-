lower bound
You are given  integers in sorted order. Also, you are given  queries. In each query, you will be given an integer and you have to tell whether that integer is present in the array. 
  If so, you have to tell at which index it is present and if it is not present, you have to tell the index at which the smallest integer that is just greater than the given number is present.

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

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int q;
    cin >> q; 

    for (int i = 0; i < q; i++) {
        int x;
        cin >> x; 

        vector<int>::iterator low = lower_bound(v.begin(), v.end(), x);

        if (v[low - v.begin()] == x) {
            cout << "Yes " << (low - v.begin() + 1) << endl; 
        } else {
            cout << "No " << (low - v.begin() + 1) << endl; 
        }
    }
    return 0;
}
