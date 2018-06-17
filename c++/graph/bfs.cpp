#include <stdio.h>
#include <queue>
#include <string>
#include <list>

#define MAXV 1024

std::string color[MAXV];
int distance[MAXV];
int predecessor[MAXV];

class Graph{
	int V;
	std::list<int> *Adj;
public:
	Graph(int V);
	void bfs(int s);
	void addEdge(int u, int v);
};

Graph::Graph(int V)
{
    this->V = V;
    Adj = new std::list<int>[V];
}


void Graph::bfs(int s){

	int u;

	for(int i = 0; i < V; i++){
		color[i] = "White";
		distance[i] = MAXV;
		predecessor[i] = MAXV;
	}

	color[s] = "Gray";
	distance[s] = 0;
	predecessor[s] = MAXV;
	std::queue<int> Q;
	Q.push(s);

	std::list<int>::iterator i;

	while(Q.size() != 0){
		u = Q.front();
		Q.pop();
		for(i = Adj[u].begin(); i != Adj[u].end(); ++i){
			if (color[*i].compare("White") == 0){
				color[*i] = "Gray";
				distance[*i] = distance[u] + 1;
				predecessor[*i] = u;
				Q.push(*i);
			}
		}
		color[u] = "Black";
		printf("%d ", u);
	}
	printf("\n");
}

void Graph::addEdge(int u, int v)
{
    Adj[u].push_back(v);
}

int main(){

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    g.bfs(2);
 
    return 0;

}