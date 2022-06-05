#include<iostream>
#include<algorithm>
using namespace std;

//Finding the minimum number of coins required to make a given amount


int main()
{
 int amount, n;
 cout<<"Enter the amount and number of denominations"<<endl;
 cin>>amount>>n;
 int* coins=new int[n];
 cout<<"Enter the denominations"<<endl;
 for(int i=0;i<n;i++)
 {
     cin>>coins[i];
 }
 int** dp=new int*[n+1]; // Number of rows being no of denominations + 1 (for 0 included) 
 for(int i=0;i<n+1;i++)
 {
     dp[i]=new int[amount+1];
 }

 // dp[i][j] is the minimum number of coins required to make amount j using denominations from 0 to i-1 in any combination but minimum no of coins in coins array
 for(int i=0;i<n+1;i++)
 {
     for(int j=0;j<amount+1;j++)
     {
         if(i==0&&j==0)
         {
             dp[i][j]=0;
         }
         else if(i==0)
         {
             dp[i][j]=INT_MAX;
         }
         else if(j==0)
         {
             dp[i][j]=0;
         }
         else if(coins[i-1]>j) // i.e 
         {
      dp[i][j]=dp[i-1][j];
         }
         else
         {
             dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]); // since min of min of (1+including ith coin , exlcuding ith coin )
         }
     }
 }

cout<<"Min number of coins are:"<<dp[n][amount]<<endl;

 for(int i=0;i<n+1;i++)
 {
    delete [] dp[i];
 }
 delete [] dp;
}