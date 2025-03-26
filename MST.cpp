//You have a business with several officers you want to leave a phone 
//lines to connect thema with each other and the phone company charges
// different amounts of money to connect different parts of cities you want to set of lines
// that connects all your offices with the minimum total cost solve the problem by suggesting the appropriate data structure
// Following is the execution of above problem by using prims algorithm -using priority queue 

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<pair<int ,int>> mstEdges(int v, vector<vector<pair<int,int>>> &adjlist){

    vector<bool>vis(v,false); // visited array to mark node when it is visited.
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    vector<pair<int,int>>MST;
    // inserting this as first node.
    pq.push({0,{0,-1}});

    while(!pq.empty()){
        
        int node=pq.top().second.first;
        int parent=pq.top().second.second;

        pq.pop();

        if(vis[node]) continue; // here it is checking does node is visited 
        //if vis[node]==true then continue which will skip all logic further it and hed to the next iteration
        vis[node]=true; // if vis[node]== false then mark it as visited.

        if(parent!=-1){
            MST.push_back({parent,node});

        }
        // now to add adjacent of parent node 

        for(auto i : adjlist[node]){
            int neighbour=i.first;
            int edgeWt=i.second;
            if(!vis[neighbour]){
                pq.push({edgeWt,{neighbour,node}});
            }
        }
    }

    return MST;
}

int main(){
    int v , e;
    cout<<"Enter no of cities and roads \n";
    cin>>v>>e;
    // Adjacency list to store undirected weighted graph

    vector<vector<pair<int,int>>>adjlist(v);

    cout<<"Enter edges with cost(1st city , 2nd city, cost)";

    for(int i=0; i<e; i++){
        int u,v,w;
        cin>>u>>v>>w;
        adjlist[u].push_back({v,w});
        adjlist[v].push_back({u,w});
    }
    cout<<"Adjacency list representation\n";
    for(int i=0;i<v;i++){
        cout<<i<<" -> ";
        for(auto i : adjlist[i]){
            cout<<" ( "<< i.first <<" , "<<i.second<<" ) ";
        }
        cout<<endl;

    }

    // Displaying Set of edges forming Minimum Spanning Tree
    cout<<"Here is the MST Set of lines\n";
    vector<pair<int,int>>MST=mstEdges(v, adjlist);
    for(pair<int,int> i : MST){
        int u = i.first;
        int v = i.second;
        cout<< u << " - > "<< v;
        cout<<endl; 
    }
}


