#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;

// i-> Start index , j-> End index, number of matrices whose muktilication is deone in cost(i,j) is
// j-i+1
int costMemoization(int i,int j,int* A)
{
    if(i==j) // => Single matrix thus cost wil be 0 of operations to multiply a single matrix
    {
        return 0;
    }

  int minValue=INT_MAX;// Doing All partitions from k=i to k=j-1
  // Whatever is min value will be the cost of multiplication of matrices from i to j
  for(int k=i;k<=j-1;k++)
  {
      int tempCost=costMemoization(i,k,A)+costMemoization(k+1,j,A)+A[i-1]*A[k]*A[j];
      if(tempCost<minValue)
      {
          minValue=tempCost;
          cout<<"Min Value is "<<minValue<<endl;
      }
  }
  return minValue;
  
}

// n-> No of matrices , A->conatining dimensions Of matrices
int mcmDP(int n,int* A)
{
    int** dp=new int*[n+1];
    for(int i=0;i<n+1;i++)
    {
        dp[i]=new int[n+1];
    }
    // dp[i][j]-> represents the minimum cost of multiplying matrices from i to j , i.e j-i+1 matrices
    // Creating a n+1 x n+1 matrix will ignore the first row and first column
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            if(i==j)
            {
                dp[i][j]=0; // Since Cost / min number of operations to multiply a single matrix is 0
            }
        }
    }
    // Now we'll find the cost / min operatios to multiply rest matrices

// Traversing columns wise from 3rd column to nth column 
    for(int l=2;l<n+1;l++)
    {
        // Now we'll traverse diagonally from top left to bottom right
        // with starting from row with index 1 i.e 2nd row and lth column (For every iteration of outer loop) and traversing till both i (for rows)<n+1 && j(for columns)<n+1 both should be true
        for(int i=1,j=l;i<n+1&&j<n+1;i++,j++)
        {
            // Now we'll find cmin cost / operations to multiply matrices from i to j by doing partitions from k=i to k=j-1
            int minValue=INT_MAX;
            for(int k=i;k<=j-1;k++)
            {
                int tempCost=dp[i][k]+dp[k+1][j]+A[i-1]*A[k]*A[j];
                if(tempCost<minValue)
                {
                    minValue=tempCost;
                }
            }
            dp[i][j]=minValue; // i.e minimum partition's / combination's value
        }

    }
    // Now answer wil be dp[1][n] i.e cost of multiplying matrices from 1 to n
    return dp[1][n];

}

int main()
{
    int n;
    cout<<"Enter the number of matrices"<<endl;
    cin>>n;
    int* A=new int[n+1];// A-> Stores the diemsnions of the matrices
    // Dimesnion of ith matrix is A[i-1]*A[i]
    cout<<"Enter the dimensions of the matrices"<<endl;
    for(int i=0;i<n+1;i++)
    {
        cin>>A[i];
    }
    cout<<"Min cost of multiplication of matrices is:"<<costMemoization(1,n,A)<<endl;
    cout<<"Min cost of multiplication of matrices is (DP): "<<mcmDP(n,A)<<endl;

    delete [] A;
}