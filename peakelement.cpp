#include<bits/stdc++.h>
using namespace std;
//find a peak element in an array
//1. brute force approach using linear search
// int peak(int*arr,int n){
// for(int i=0;i<n;i++)
// {
//     if((i==0||arr[i-1]<arr[i])&&(i==n-1||arr[i]>arr[i+1]))
//     return i;
// }
// return -1;
// }

//2.Optimized approach using Binary search
int peak(int*arr,int n)
{
    if(n==1)return 0;
    if(arr[0]>arr[1])return 0;
    if(arr[n-1]>arr[n-2])return n-1;
    int low = 1; int high = n-2;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if((arr[mid]>arr[mid-1])&&(arr[mid]>arr[mid+1]))return mid;
        else if(arr[mid]>arr[mid-1]){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;
}

int main()
{
   int arr[5]= {11,13,20,25,18} ;
   int res= peak(arr,5);
   cout<<"Result is= "<<arr[res]<<endl;

   return 0;
}