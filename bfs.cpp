#include<bits/stdc++.h>
using namespace std;

struct node
{
    int index;
    bool visit;
    node *parent;
    int distance;
};

const int totalNodes = 5;
node V[totalNodes];
vector<int> adj[totalNodes];


void shortestPath(int source, int destination)
{
    if(source == destination)
    {
        cout<<source<<" ";
    }
    else if(V[destination].parent == nullptr)
    {
        cout<<"Path does not exist"<<endl;
    }else{
        shortestPath(source, V[destination].parent->index);
        cout<<destination<<" ";
    }
}

//BFS Traversal
void BFS(int root){   

    V[root].visit = true;
    V[root].distance  = 0;
    
    queue<node> breadth;
    breadth.push(V[root]);
    cout<<V[root].index<<" ";
    while(!breadth.empty())
    {
        int current = breadth.front().index;        
        breadth.pop();
        for(auto xx : adj[current])
        {
            if(V[xx].visit == false)
            {
                V[xx].visit = true;
                V[xx].distance = V[current].distance+1;
                V[xx].parent = &V[current];
                breadth.push(V[xx]);               
                cout<<V[xx].index<<" ";
                
            }
        }


    }
    cout<<endl;

}



int main(){

    for(int i =0; i<totalNodes; i++)
    {
        V[i].index = i;
        V[i].visit = false;
        V[i].distance = INFINITY;
        V[i].parent = nullptr;
    }

    adj[0].push_back(4);
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(3);
    adj[3].push_back(0);
    adj[3].push_back(4);
    adj[4].push_back(1);
   
    BFS(0);
    shortestPath(0,3);

    return 0;
}