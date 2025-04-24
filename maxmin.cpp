// find max and min element from an array using divide and conquer method 
 
#include<iostream> 
using namespace std ; 
 
pair<int,int> maxMin(int arr[], int n, int s, int e) 
{ 
    // base case 
    if(s==e) return {arr[s],arr[s]} ; // single element in array 
 
    int mid = s + (e-s)/2 ; 
 
    pair<int,int> leftMaxMin = maxMin(arr,n,s,mid) ; 
    pair<int,int> rightMaxMin = maxMin(arr,n,mid+1,e) ; 
 
    int maxi = max(leftMaxMin.first,rightMaxMin.first) ; 
    int mini = min(leftMaxMin.second,rightMaxMin.second) ; 
 
    return {maxi,mini} ; 
} 
int main() 
{ 
    int arr[] = {12, 7, 19, 5, 18, 3, 8, 11, 22, 10}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    pair<int,int> pmaxmin = maxMin(arr, n, 0, n-1); 
cout<<"Maximum element: "<<pmaxmin.first<<endl; 
cout<<"Minimum element: "<<pmaxmin.second<<endl; 
return 0 ; 
}