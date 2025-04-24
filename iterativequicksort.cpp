#include<bits/stdc++.h>
using namespace std;
//iterarive quickSort

// Function to partition the array on the basis of pivot element
int Partition(long int arr[],long int low,long int high)
{
    long  int pivot = arr[low];
    long int i =low+1;
    long int j=high;
  while(i<=j)
  {
    while(i<=j&&arr[i]<=pivot)
    {
      i++;
    }
    while(i<=j&&arr[j]>pivot)
    {
      j--;
    }
    if(i<j)
    {
      swap(arr[i],arr[j]);
    }   
  }
    swap(arr[low],arr[j]);
    return j;
}

// Function to perform quicksort

//using do while loop
void QSI(long int arr[],int low,int high)
{
    stack<int>st;
    do{
        while(low<high)
        {
            int j = Partition(arr,low,high);
            if((j-low)>(high-j))
            {   
                
                st.push(low);
                st.push(j-1);
                low = j+1;
            }
            else{
                
                st.push(j+1);
                st.push(high);
                high = j-1;
                
            }
        }
        if(st.empty()) return;
        high = st.top();
        st.pop();
        low = st.top();
        st.pop();
    }while(true);
            
}

// Function to check if array is sorted or not
// Function to check if array is sorted
bool isSorted(long int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) return false;
    }
    return true;
}


int main()
{
    srand(time(0)); // Seed for random numbers

    int n = 1000;
    while (n <= 10000) {
        double totalTime = 0.0;

        for (int i = 1; i <= 10; i++) {
            long int arr[n];
            
            // Generate random array of size n
            for (int j = 0; j < n; j++) {
                arr[j] = rand() % n + 1;
            }

            auto start = chrono::high_resolution_clock::now();
            QSI(arr, 0, n - 1);
            auto end = chrono::high_resolution_clock::now();

            chrono::duration<double> duration = end - start;
            totalTime += duration.count();
            // Validate sorting
            if (!isSorted(arr, n)) {
                cout << "Sorting failed for size " << n << endl;
                return 1;
            }

        }

        double avgTime = totalTime / 10;
        cout << "Size: " << n << ", Time: " << avgTime << " seconds" << endl;

        n += 1000; // Increment n properly
    }

    return 0;
}
// Time complexity: O(nlogn) in average case and O(n^2) in worst case

