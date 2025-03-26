//Represent a given graph using the adjacency matrix or a list to perform the DFS and using the adjacency list to perform the bfs using 
//the map of the area around the college as the graph identified the prominent landmarks as notes and perform the DFS and bfs on that

#include<iostream>
#include<vector>
#include<queue>

using namespace std;


void bfs(int start,vector<vector<int>> myGraph,int v){
    vector<bool>vis(v,false);
    queue<int>q;
    q.push(0);
    vis[0]=true;
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

    bfs(0,myGraph,v);

}

