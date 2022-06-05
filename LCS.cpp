#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
    string s1,s2;
    cout<<"Enter the two strings"<<endl;
    cin>>s1>>s2;
    // Size of the matrix will be row:size of s1+1 and column:size of s2+1
    int length1=s1.size()+1;
    int length2=s2.size()+1;
    int** dp=new int*[length1];
    for(int i=0;i<length1;i++)
    {
        dp[i]=new int[length2];
    }


    // dp[i][j] => length of lcs with size of s1 being i (i.e i consecutive characters conisderd) & size of s2 being j

   for(int i=0;i<length1;i++)
   {
       for(int j=0;j<length2;j++)
       {

       if(i==0 || j==0)
       {
           dp[i][j]=0;
       }
       else{
            if(s1[i-1]==s2[j-1]) // i.e both substrings have same initial characters => lcs 1+ lcs(s1[0..i-2],s2[0..j-])
            {
               dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
       }
       }
   }

   // lcs will be the last element of the dp matrix i.e lcs of s1 & s2 will be lcs[length1-1][length2-1];

 cout<<"Length of lcs is:"<<dp[length1-1][length2-1]<<endl;
    for(int i=0;i<length1;i++)
    {
        delete [] dp[i];
    }
    delete [] dp;
}