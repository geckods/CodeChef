#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100000; 
vector<int> graph[N]; 
vector<int> cycles[N];

void dfs_cycle(int u, int p, int color[], 
               int mark[], int par[], int& cyclenumber) 
{ 
  
    // already (completely) visited vertex. 
    if (color[u] == 2) { 
        return; 
    } 
  
    // seen vertex, but was not completely visited -> cycle detected. 
    // backtrack based on parents to find the complete cycle. 
    if (color[u] == 1) { 
  
        cyclenumber++; 
        int cur = p; 
        mark[cur] = cyclenumber; 
  
        // backtrack the vertex which are 
        // in the current cycle thats found 
        while (cur != u) { 
            cur = par[cur]; 
            mark[cur] = cyclenumber; 
        } 
        return; 
    } 
    par[u] = p; 
  
    // partially visited. 
    color[u] = 1; 
  
    // simple dfs on graph 
    for (int v : graph[u]) { 
  
        // if it has not been visited previously 
        if (v == par[u]) { 
            continue; 
        } 
        dfs_cycle(v, u, color, mark, par, cyclenumber); 
    } 
  
    // completely visited. 
    color[u] = 2; 
}


void addEdge(int u, int v) 
{ 
    graph[u].push_back(v); 
    graph[v].push_back(u); 
} 

// Function to print the cycles 
void printCycles(int edges, int mark[], int& cyclenumber) 
{ 
  
    // push the edges that into the 
    // cycle adjacency list 
    for (int i = 1; i <= edges; i++) { 
        if (mark[i] != 0) 
            cycles[mark[i]].push_back(i); 
    } 
  
    // print all the vertex with same cycle 
    for (int i = 1; i <= cyclenumber; i++) { 
        // Print the i-th cycle 
        cout << "Cycle Number " << i << ": "; 
        for (int x : cycles[i]) 
            cout << x << " "; 
        cout << endl; 
    } 
} 


int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL); 
  
  
    // add edges 

   	int t;
   	cin>>t;

   	for(int test=0;test<t;test++){
   		int n,m;
   		cin>>n>>m;

   		cout<<test<<" "<<n<<" "<<m<<endl;

   		for(int i=0;i<n;i++){
   			graph[i].clear();
   			cycles[i].clear();
   		}

   		int x,y;
   		for(int i=0;i<m;i++){
   			cin>>x>>y;
   			// x--;
   			// y--;
   			addEdge(x, y);
   		}

   		// arrays required to color the 
	    // graph, store the parent of node 
	    int color[N]; 
	    int par[N]; 
	  
	    // mark with unique numbers 
	    int mark[N];

	    memset(color,0,sizeof(color));
	    memset(par,0,sizeof(par));
	    memset(mark,0,sizeof(mark));
	  	
	    // store the numbers of cycle 
	    int cyclenumber = 0; 
	    int edges = 13; 
	  

	    // call DFS to mark the cycles 
	    dfs_cycle(1, 0, color, mark, par, cyclenumber); 
	    cout<<cyclenumber<<endl;
	  
	    // // function to print the cycles 
	    printCycles(edges, mark, cyclenumber); 
	}
} 