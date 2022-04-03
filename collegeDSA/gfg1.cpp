#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;


int main() {
    int n,c=0;
    cin>>n;
    int arr[n],arr2[n];
    int rl = INT_MAX;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    arr2[0] = 0;
    for (int i = 1; i < n; i++)
    { arr2[i] = max(arr2[i-1], arr[i-1]);
    } 
    for (int i=n-1; i>=0; i--)
    {     
        if ((rl > arr[i]) && (arr2[i]< arr[i]) )
        { c++;
        }
        rl = min(rl, arr[i]);
    }
   cout<<c;
    return 0;
}
