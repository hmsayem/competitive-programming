#include <bits/stdc++.h>
using namespace std;
 
long long merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
   
    int L[n1], R[n2]; 
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    i = 0; 
    j = 0; 
    k = l; 
    long long cnt=0;
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            cnt+=n1-i;
            j++; 
        } 
        k++; 
    } 
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    }   
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
    return cnt;
} 
  
long long invCount(int arr[], int l, int r) 
{ 
    long long cnt=0;
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
        cnt=invCount(arr, l, m); 
        cnt+=invCount(arr, m+1, r); 
        cnt+=merge(arr, l, m, r); 
    }
    return cnt;
} 
 
int main() 
{ 
    int data[200005];
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>data[i];
        cout<<invCount(data,0,n-1)<<endl;
    }
} 
