#include<bits/stdc++.h>
using namespace std;


vector<int> g[1000];
int timer;
int tin[1000];
int low[1000];  // lowest insertion time for the node
bool vis[1000];
// what if it is not in recursion stack

// this is for bridge
void bridge(int u,int par){
    tin[u]=timer;
    low[u]=timer;
    timer++;
    for(auto v:g[u]){
        if(v==par)continue; // it will neever take value of par
        if(vis[v]){
            //this means edge u->v can never be a bridge
            // as v is already visited from some other path
            low[u]=min(low[v],low[u]);
        }
        else {
            bridge(v,u);
            low[u]=min(low[u],low[v]); // this nptifies of the backedge
            if(low[v]>tin[u]){
                // this is a bridge 
                cout<<u<<" "<<v<<endl;
            }
        }
    }
}


void articulation(int u,int parent){
    tin[u]=timer;
    low[u]=timer;
    timer++;
    vis[u]=true;
    int child=0;
    for(auto v:g[u]){
        if(v==parent)continue;
        if(!vis[v]){
            articulation(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=tin[u]&&parent!=-1){
                // this is the aticulation point
            }
        }
        else {
            low[u]=min(low[v],low[u]);
        }
    }

    if(parent==-1&&child>1){
        // u is also the articulation point
        // and u is the root
    }
}


