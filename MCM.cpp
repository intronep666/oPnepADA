#include<bits/stdc++.h>
using namespace std;


//function to print split matrices
void print(vector<vector<int>>&s,int i,int j)
{
    if(i==j) 
    {
        cout<<"A"<<i;
    }
    else
    {
        cout<<"(";
        print(s,i,s[i][j]);
        print(s,s[i][j]+1,j);
        cout<<")";
    }
}

// Function to find the minimum cost of matrix chain multiplication
void matrixchain(vector<int>&p)
{
   int n = p.size() - 1; // number of matrices
   vector<vector<int>>m(n,vector<int>(n,0)); //cost matrix 
   vector<vector<int>>s(n,vector<int>(n,0));//split matrix
   for(int l =2;l<=n;l++)
   {
    for(int i = 0;i<n-l+1;i++)
    {
        int j = i+l-1;
        m[i][j] = INT_MAX;
        for(int k =i;k<=j-1;k++)
        {
           int q = m[i][k] + m[k+1][j] + p[i]*p[k+1]*p[j+1];
           if(q<m[i][j]){
            m[i][j] = q;
            s[i][j] = k;
           }
        }
    }
   }
   cout << "Minimum cost: " << m[0][n - 1] << endl;
     print(s,0,n-1);
}
int main()
{
    vector<int> p = {5,10,15,20,25,30};
    matrixchain(p);
    return 0;
}



































// // Function to find the minimum cost of matrix chain multiplication
// void matrixchain(vector<int> &p) {
//     int n = p.size() - 1; // Number of matrices
//     vector<vector<int>> m(n, vector<int>(n, 0)); // Cost matrix
//     vector<vector<int>> s(n, vector<int>(n, 0)); // Split matrix

//     // Fill the cost matrix using dynamic programming
//     for (int l = 2; l <= n; l++) { // l is the chain length
//         for (int i = 0; i < n - l + 1; i++) {
//             int j = i + l - 1;
//             m[i][j] = INT_MAX;
//             for (int k = i; k < j; k++) {
//                 int q = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
//                 if (q < m[i][j]) {
//                     m[i][j] = q;
//                     s[i][j] = k;
//                 }
//             }
//         }
//     }

//     cout << "Minimum cost: " << m[0][n - 1] << endl;
//     cout << "Split points: " << endl;
//     for (int i = 0; i < n - 1; i++) {
//         cout << s[i][i + 1] << " ";
//     }
//     cout << endl;
// }
// int main()
// {
//     vector<int>p = {5,10,20,2,1};
//     matrixchain(p);
//     return 0;

// }
