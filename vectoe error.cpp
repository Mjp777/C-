vector error 
You are provided with a vector of  integers. Then, you are given  queries. For the first query, you are provided with  integer, which denotes a position in the vector. 
The value at this position in the vector needs to be erased. The next query consists of  integers denoting a range of the positions in the vector.
The elements which fall under that range should be removed. The second query is performed on the updated vector which we get after performing the first query.

  
  #include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n; // Read the size of the vector

    vector<int> v(n); // Declare a vector of size n

    for (int i = 0; i < n; i++) {
        cin >> v[i]; // Read the elements of the vector
    }

    int q1;
    cin >> q1; // Read the index to erase
    v.erase(v.begin() + q1 - 1); // Erase the element at index q1

    int q2, q3;
    cin >> q2 >> q3; // Read the range [q2, q3) to erase
    v.erase(v.begin() + q2 - 1, v.begin() + q3 - 1); // Erase the elements in the given range

    cout << v.size() << endl; // Print the size of the vector

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " "; // Print the elements of the vector
    }   
    return 0;
}
