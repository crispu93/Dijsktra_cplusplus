#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <utility> //pair, make_pair
#include <queue> 

//#define INF (unsigned)(~0)
#define INF 1000000
using namespace std;

// class representation of undirected graph with n nodes labeled 0,1,...,n-1
class graph {
    int n;
    vector< vector< pair<int,int> > > adjList;

    public:
    graph(int n) {
        this->n = n;
        this->adjList.resize(n);
    }

    void addEdge(int i, int j, int w) {
        this->adjList[i].push_back(make_pair(j,w));
        this->adjList[j].push_back(make_pair(i,w));
    }

    bool isEdge(int i, int j) {
        for (auto x: adjList[i]) {
            if (x.first == j) {
                return true;
            }
        }
        return false;
    }

    // Generate a random graph with m edges and weights in the interval [min,max]
    void erdosRenyi(int m, int min, int max) {
        while (m--) {
            int i = rand()%this->n;
            int j = rand()%this->n;
            int w = min + rand()%max + 1;

            if ( isEdge(i,j) || i == j ) {
                m++;
                continue;
            }
            
            addEdge(i, j, w);
        }
    }

    void printEdges() {
        for (int i = 0; i<this->n; i++){
            for (auto x: this->adjList[i]) {
                cout<<i<<";"<<x.first<<";"<<x.second<<endl;
            }
        }
    }

    void printTofile(string ofile) {
        ofstream file;
        file.open(ofile);
        file<<"Source;Target;Label;Weight"<<endl;
        for (int i = 0; i<this->n; i++){
            for (auto x: adjList[i]) {
                if(i<x.first) 
                    file<<i<<";"<<x.first<<";"<<x.second<<";"<<x.second<<endl;
            }
        }
        file.close();
    }

    graph dijkstra(int s) {
        int n = this->n;
        graph dij_tree = graph(n);
        vector<int> dist;
        vector<bool> proc;   //processed vertex
        priority_queue<pair<int,int> > pq;    //Max priority queue
        dist.resize(n);
        proc.resize(n);
        for (int i=0; i<n; ++i) {
            dist[i]=INF;
            proc[i] = false;
        }
        dist[s] = 0;
        pq.push({0,s});
        while (!pq.empty()) {
            int top = pq.top().second;
            pq.pop();
            if (proc[top]) 
                continue;
            proc[top] = true;
            for (auto x: adjList[top]){
                int u = x.first;
                int w = x.second;
                //dij_tree.addEdge(top,u,w);
                if(dist[top]+w <dist[u]) {
                    dist[u] = dist[top]+w;
                    pq.push({-dist[u],u});
                    dij_tree.addEdge(top,u,w);
                }
            }
        }
        return dij_tree;
    }
};

int main() {
    graph g = graph(5);
    g.erdosRenyi(10,0,10);
    g.printEdges();
    g.printTofile("graph.csv");
    graph dij_g = g.dijkstra(0);
    cout<<"Dijstra output"<<endl;
    dij_g.printEdges();
    dij_g.printTofile("dijstra.csv");
    return 0;
}