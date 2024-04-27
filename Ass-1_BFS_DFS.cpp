#include<bits/stdc++.h>
#include<omp.h>
using namespace std;

class Graph{
    int V;
    vector<vector<int>>adj;
public:
Graph(int V):V(V),adj(V){}

void addEdge(int v,int w)
{
    adj[v].push_back(w);
}

void bfs(int start)
{
    vector<int>visited(V,0);
    visited[V]=1;
    queue<int>q;
    q.push(start);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        cout<<node<<" ";

        for(int i=0;i<adj[node].size();i++)
        {
            int n1 = adj[node][i];
            if(!visited[n1])
            {
                visited[n1]=1;
                q.push(n1);
            }
        }
    }

}

void bfsp(int start)
{
    vector<int>visited(V,0);
    visited[V]=1;
    queue<int>q;
    q.push(start);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        cout<<node<<" ";

        #pragma omp parallel for 
        for(int i=0;i<adj[node].size();i++)
        {
            int n1 = adj[node][i];
            
            if(!visited[n1])
            {
                #pragma omp task
                visited[n1]=1;
                q.push(n1);
            }
        }
    }

}

void dfs(int start,vector<int>&visited)
{
    visited[start] = 1;
    cout<<start<<" ";

    for(int i=0;i<adj[start].size();i++)
    {
        int node = adj[start][i];
        if(!visited[node])
        {
            dfs(node,visited);
        }
    }
}


void dfsp(int start,vector<int>&visited)
{
    visited[start] = 1;
    cout<<start<<" ";

    #pragma omp parallel for
    for(int i=0;i<adj[start].size();i++)
    {
        int node = adj[start][i];
        if(!visited[node])
        {
            #pragma omp task
            dfs(node,visited);
        }
    }
}

void dfs1(int start)
{
    vector<int>visited(V,0);
    dfs(start,visited);
}

void dfs2(int start)
{
    vector<int>visited(V,0);
    dfsp(start,visited);
}

};

int main()
{
    int n;
    cout<<"Enter the number of vertices :";
    cin>>n;
    Graph g(n);
 
    char ch;
    while(true)
    {
        cout<<"\n Do you want to enter the vertex :";
        cin>>ch;
        if(ch=='y')
        {
            int v,w;
            cout<<"\n Enter the edges:";
            cin>>v>>w;
            g.addEdge(v,w);
        }
        else{
            break;
        }

    }

    double stime,etime;
    stime = omp_get_wtime();
    g.bfs(0);
    etime = omp_get_wtime();
    cout<<"\n Time for bfs is : "<<etime - stime <<endl;

    stime = omp_get_wtime();
    #pragma omp parallel
    {
      #pragma omp single nowait
      g.bfs(0);
    }

    etime = omp_get_wtime();
    cout<<"\n Time for bfs parallel is : "<<etime - stime <<endl;

    stime = omp_get_wtime();
    g.dfs1(0);
    etime = omp_get_wtime();
    cout<<"\n Time for dfs is : "<<etime - stime <<endl;

    stime = omp_get_wtime();
    #pragma omp parallel
    {
        #pragma omp single nowait
        g.dfs2(0);
    }
    etime = omp_get_wtime();
    cout<<"\n Time for dfs parallel is : "<<etime - stime <<endl;

}

