#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n,k;
    cout<<"Enter n & k"<<endl;
    cin>>n>>k;
    int size=max(n,k);
    int** DP=new int*[size+1];
    for(int i=0;i<size+1;i++)
    {
        DP[i]=new int[size+1];
    }

    for(int i=0;i<size+1;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j==0)
            {
                DP[i][j]=1;
            }
            else if(i==j)
            {
                DP[i][j]=1;
            }
            else
            {
                DP[i][j]=DP[i-1][j]+DP[i-1][j-1];
            }
        }
    }

    cout<<n<<"C"<<k<<"="<<DP[n][k]<<endl;

    for(int i=0;i<size+1;i++)
    {
        delete[] DP[i];
    }
    delete [] DP;

}