#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int minValueOfVector(vector<int> cost)
{
    int minValue=INT_MAX;
    for(int i=0;i<cost.size();i++)
    {
        if(cost[i]<minValue)
        {
            minValue=cost[i];
        }
    }
    return minValue;
}


int main()
{
    int numberOfVertices;
    cout<<"Enter the number of vertices"<<endl;
    cin>>numberOfVertices;
    int** graph=new int*[numberOfVertices];
    for(int i=0;i<numberOfVertices;i++)
    {
        graph[i]=new int[numberOfVertices];
    }
    cout<<"Enter the adjacency matrix"<<endl;

// Initializing the graph 0 => No edge
  
for(int i=0;i<numberOfVertices;i++)
{  
    for(int j=0;j<numberOfVertices;j++)
    {
       graph[i][j]=0; 
    }
}

// Taking the adjacency matrix as input
for(int i=0;i<numberOfVertices;i++)
{  
    for(int j=0;j<numberOfVertices;j++)
    {
        cin>>graph[i][j];
    }
}

// creating  matrix containing elemst presnet at that stage where stage is the row & columns repsresnt whether that vertex is at that stage or not

int numberOfStages;
cout<<"Enter the number of stages"<<endl;
cin>>numberOfStages;
// Matrix wil have rows== nno of stages , columns == number of vertices
bool** stages=new bool*[numberOfStages];
for(int i=0;i<numberOfStages;i++)
{
    stages[i]=new bool[numberOfVertices];
}
for(int i=0;i<numberOfStages;i++)
{
    for(int j=0;j<numberOfVertices;j++)
    {
        stages[i][j]=false;
    }
}

// Now taking input as which vertex is at which stage
for(int i=0;i<numberOfVertices;i++)
{
    cout<<"Enter the vertex & stage of vertex respectively"<<endl;
    int vertex,stage;
    cin>>vertex>>stage;// Coutning sateges from 0 instead of 1 => if 4 stages then stages are: 0 , 1 , 2 , 3
    stages[stage][vertex]=true;
}

// dp[i][j]-> repsernts cost to reach destination from vertex j at stage i
int**dp =new int*[numberOfStages];
for(int i=0;i<numberOfStages;i++)
{
    dp[i]=new int[numberOfVertices];
}

// Thus Now we'll initialize the dp matrix with infinity
// dp[i][j]-> repsernts cost to reach destination from vertex j at stage i , dp[i][j]== infinity if vertex j is not at stage i
for(int i=0;i<numberOfStages;i++)
{
    for(int j=0;j<numberOfVertices;j++)
    {
        dp[i][j]=INT_MAX;
    }
}

// Now we find path from source to destination
// destination vertex we'll take as input since at last stage there can be many vertices
int destination;
cout<<"Enter the destination vertex"<<endl;
cin>>destination;   
dp[numberOfStages-1][destination]=0; // Since cost to reach destination from destination is 0

// We'll start from Second last stage since assuming last stage has only one vertex

for(int i=numberOfStages-2;i>=0;i--)
{
    for(int j=0;j<numberOfVertices;j++)
    { // j -> cur vertex on that stage
        if(stages[i][j]) // => The vertex is at that stage thus now we'll explore all vertices adjacent to it and find the min cost
        {
            vector<int> cost;
            for(int k=0;k<numberOfVertices;k++)
            {
                if(graph[j][k]!=0) // => edge bw j & k exits 
                {
                      cost.push_back(graph[j][k]+dp[i+1][k]); // since cost to reach destination vertex from vertex j having k as adjacent (at next immediate stage) is cost of edge bw j k + cost to reach destination from k whch is at next stage i.e i+1 here since i represnets current stage
                }
            }

            int realCost= minValueOfVector(cost);
            dp[i][j]=realCost;
        }
    }
}

cout<<"Cost to reach from vertex to destination is"<<endl;

for(int i=0;numberOfStages;i++)
{
    for(int j=0;j<numberOfVertices;j++)
    {
        if(dp[i][j]!=INT_MAX)// => There's a path from vertex j at stage i to reach destination
        {
             cout<<"Vertex "<<j<<"at stage"<<i<<" has cost"<<dp[i][j]<<endl;
        }
    }
}





    for(int i=0;i<numberOfVertices;i++)
    {
        delete [] graph[i];
    }
    delete [] graph;
}
/*

0 1 2 5 0 0 0 0
    0 0 0 0 4 11 0 0
    0 0 0 0 9 5 16 0
    0 0 0 0 0 0 2 0
    0 0 0 0 0 0 0 18
    0 0 0 0 0 0 0 13
    0 0 0 0 0 0 0 2
    0 0 0 0 0 0 0 0

4 stages
*/


/*
0 0
1 1
2 1
3 1
4 2
5 2
6 2
7 3


*/