sparse arrays

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

int main() {
 // Enter your code here. Read input from STDIN. Print output to STDOUT 
 map<string,int> m;
 string s,p;
 int n;
 cin>>n;
 for(int i=0;i<n;i++)
 {
 cin>>s;
 m[s]++;
 }
 int q;
 cin>>q;
 for(int i=0;i<q;i++)
 {
 cin>>p;
 cout<<m[p]<<endl;
 }
 return 0;
}
