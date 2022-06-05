#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n,capacity;
    cout<<"Enter the number of items and capacity of knapsack"<<endl;
    cin>>n>>capacity;
    int* profit=new int[n];
    int* weight=new int[n];

    cout<<"Enter the profit of each item"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>profit[i];
    }
    cout<<"Enter the weight of each item"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>weight[i];
    }
    int** dp=new int*[n+1];
    for(int i=0;i<n+1;i++)
    {
        dp[i]=new int[capacity+1];
    }

    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<capacity+1;j++)
        {
            if(i==0||j==0)
            {
                dp[i][j]=0;
            }
            else if(weight[i-1]>j) // i.e weight of current object iss greater tan capacity of knapsack => exclude the current object
            {
             dp[i][j]=dp[i-1][j]; // exclude the current object => consider i-1 object and capcity of knacpsack will be same
            }
            else // => current object can be inluded in the knapsack (if its inluded or not depends upon the value)
            {
             dp[i][j]=max(profit[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]); // if current object is included in the knapsack => max of (profit of current object + max profit of knapsack with capacity of knapsack minus weight of current object) 
            }
        }
    }

    cout<<"Max profit is:"<<dp[n][capacity]<<endl; // since all objects considered and capacity of knapsack is given capacity hence the last element of dp matrix

    for(int i=0;i<n+1;i++)
    {
        delete [] dp[i];
    }
    delete [] dp;
    
}