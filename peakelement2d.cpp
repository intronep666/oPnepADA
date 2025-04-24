#include<bits/stdc++.h>
using namespace std;
int findmax(vector<vector<int>>&mat,int n,int m,int col)
{
    int max = -1;
    int max_index = -1;
    for(int i=0;i<n;i++)
    {
       if(mat[i][col]>max)
       {
           max = mat[i][col];
           max_index = i;
       }
    }
    return max_index;
}


vector<int>findpeak(vector<vector<int>>&mat)
{
    int n = mat.size();
    int m = mat[0].size();
    int low = 0;
    int high = m-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        int max_index = findmax(mat,n,m,mid);
        if((mid==0||mat[max_index][mid-1]<mat[max_index][mid])&&(mid==m-1||mat[max_index][mid]>mat[max_index][mid+1]))
        {
            return {max_index,mid};
        }
        else if(mid>0&&mat[max_index][mid-1]>mat[max_index][mid])
        {
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return {-1,-1};
}
int main()
{
    vector<vector<int>>mat = {{10,8,10,10},
                               {14,13,12,11},
                               {15,9,11,21},
                               {16,17,19,20}};
    vector<int>res = findpeak(mat);
    cout<<"Peak element is= "<<mat[res[0]][res[1]]<<endl;
    return 0;
}