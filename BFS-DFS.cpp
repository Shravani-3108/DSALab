//Represent a given graph using the adjacency matrix or a list to perform the DFS and using the adjacency list to perform the bfs using 
//the map of the area around the college as the graph identified the prominent landmarks as notes and perform the DFS and bfs on that

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void dfs(int node,vector<vector<int>>&myGraph,vector<bool>&vis){
    
    vis[node]=true;
    cout<<node<<" ";
    
    for(int i : myGraph[node]){
        if(!vis[i]){
            dfs(i,myGraph,vis);
        }
    }

}

void bfs(int start,vector<vector<int>> &myGraph,int v){
    vector<bool>vis(v,false);
    queue<int>q;
    q.push(start);
    vis[start]=true;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cout<<node<<"  ";

        for(auto i : myGraph[node]){
            if(!vis[i]){
                vis[i]=true;
                q.push(i);
            }
        }
    }
}


int main(){
    cout<<"Landmarks:\n0 -> Main Gate\n1 -> Library\n2 -> Canteen\n3 -> Hostel\n4 -> Auditorium\n5 -> Admin Block\n";
                        
    int v,e;
    cout<<"Enter No of vertices and edges\n";
    cin>>v>>e;
    vector<vector<int>>myGraph(v);
    cout<<"Enter vertices whichnare forming edges\n";
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        myGraph[u].push_back(v);
        myGraph[v].push_back(u);
    }
    vector<bool>vis(v,false);

    dfs(0,myGraph,vis);

}

//Enter number of vertices and edges:
// 6 7
// Enter pairs of vertices forming edges:
// 0 1
// 0 2
// 1 3
// 1 4
// 2 4
// 3 5
// 4 5
//BFS=0 1 2 3 4 5
//DFS=0 1 3 5 4 2