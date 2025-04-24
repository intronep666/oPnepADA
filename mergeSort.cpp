#include<bits/stdc++.h>
using namespace std;
void mergeSort(long int arr[], long int low, long int high);
void merge(long int arr[], long int low, long int mid, long int high);

void mergeSort(long int arr[],long int low,long int high)
{   if(low>=high)return;
    long int mid=(low+high)/2;
    //right half
    mergeSort(arr,low,mid);
    //left half
    mergeSort(arr,mid+1,high);
    //for merging
    merge(arr,low,mid,high);
}
void merge(long int arr[],long int low,long int mid,long int high)
{
   long int i=low;
    long int j=mid+1;
    long int k=0;
   vector<long int> temp(high - low + 1);// Allocate the temporary array with the correct size
    while(i<=mid&&j<=high)
    {
        if(arr[i]<=arr[j])
        {
          temp[k]=arr[i];
          i++;
          k++;
        }
        else{
            temp[k]=arr[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        temp[k]=arr[i];
        k++;
        i++;
    }
    while(j<=high)
    {
        temp[k]=arr[j];
        k++;
        j++;
    }
   for(long int i=low,k=0;i<=high;i++,k++)
   {
    arr[i]=temp[k];
   }
}
int main()
{
    long int n = 10000; 
    int it = 0; 
  
    // Arrays to store time duration 
    // of sorting algorithms 
    double  time[10]; 
    // // Seed the random number generator
    //  srand(time(0));

  
    cout<<"size, time\n"; 
  
    // Performs 10 iterations 
    while (it < 10) { 
        long int a[n];

  
        // generating n random numbers 
        // storing them in arrays a, b, c 
        for (int i = 0; i < n; i++) { 
            long int no = rand() % n + 1; 
            a[i] = no; 
            
        } 

        // merge sort 
         auto start = chrono::high_resolution_clock::now(); 
        mergeSort(a,0,n-1); 
        auto end = chrono::high_resolution_clock::now();
        
        chrono::duration<double> duration = end - start;
        time[it] = duration.count();
  

    cout << n << ", "<< time[it] << ","<<endl;

        // increases the size of array by 10000 

     n+=10000;

     it++;
}
    return 0; 
}

