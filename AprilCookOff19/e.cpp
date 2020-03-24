#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef struct edge Edge;
typedef struct node Node;

struct node{
	int index;
	ll min = LLONG_MIN;
	ll max = LLONG_MAX;
	int edgecount=0;
	int currarraysize=1;
	Edge** edgearray;
};

struct edge{
	int type;
	ll c;
	Node* source;
	Node* target;
};

Node* newNode(int index){
	Node* myNode = (Node*)malloc(sizeof(Node));
	myNode->edgearray = (Edge**)malloc(sizeof(Edge*));
	myNode->index = index;
	myNode->min = LLONG_MIN;
	myNode->max = LLONG_MAX;
	myNode->edgecount=0;
	myNode->currarraysize=1;
	return myNode;
}

void addEdge(Node* mynode, Edge* myedge){
	mynode->edgearray[mynode->edgecount++] = myedge;
	if(mynode->currarraysize == mynode->edgecount){
		mynode->currarraysize*=2;
		mynode->edgearray = (Edge**)realloc(mynode->edgearray, sizeof(Edge*)*mynode->currarraysize);
	}
}

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin>>t;


	for(int test=0;test<t;test++){
		int n,m;
		cin>>n>>m;

//		cout<<"NM"<<n<<" "<<m<<endl;

		Node* nodearray[n];
		for(int i=0;i<n;i++){
			nodearray[i]=newNode(i);
		}

		ll t,u,v,c;

		for(int i=0;i<m;i++){
			cin>>t>>u>>v>>c;
//			cout<<"TUVC"<<t<<" "<<u<<" "<<v<<" "<<c<<endl;
			Edge* newEdge = (Edge*)malloc(sizeof(Edge));
			newEdge->type = t;
			newEdge->c = c;
			newEdge->source = nodearray[u-1];
			newEdge->target = nodearray[v-1];
			addEdge(nodearray[u-1],newEdge);
			addEdge(nodearray[v-1],newEdge);
		}

		queue<int> que;
		que.push(0);

		nodearray[0]->min=0;
		nodearray[0]->max=0;

		int nextNode;
		Edge* nextEdge;


//		cout<<nodearray[0]->edgecount<<endl;

		int seen[n];
		for(int i=0;i<n;i++){
			seen[i]=0;
		}

		while(!que.empty()){
			nextNode = que.front();
			seen[nextNode]=1;
			que.pop();
			Node* source;
			Node* targ;
			for(int i=0;i<nodearray[nextNode]->edgecount;i++){


				nextEdge = nodearray[nextNode]->edgearray[i];
//				cout<<"NE:"<<nextEdge->target->index<<endl;

				if(nextEdge->source == nodearray[nextNode]){
					if(nextEdge->type == 1){
						int uminusc = nextEdge->source->min - nextEdge->c; 
						if(uminusc < nextEdge->target->max){
							nextEdge->target->max = uminusc;
						}
					}
					else{
						int uminusc = nextEdge->source->min - nextEdge->c; 
						if(uminusc+1 > nextEdge->target->min){
							nextEdge->target->min = uminusc+1;
						}
					}

					if(nextEdge->target->min >= nextEdge->target->max && !seen[nextEdge->target->index]){
						que.push(nextEdge->target->index);
					}
				}
				else{
					if(nextEdge->type == 1){
						int vplusc = nextEdge->target->min + nextEdge->c; 
//						cout<<vplusc<<" "<<nextEdge->source->min<<endl;
						if(vplusc > nextEdge->source->min){
							nextEdge->source->min = vplusc;
						}
					}
					else{
						int vplusc = nextEdge->target->min + nextEdge->c; 
						if(vplusc-1 < nextEdge->source->max){
							nextEdge->source->max = vplusc-1;
						}
					}

					if(nextEdge->source->min >= nextEdge->source->max && !seen[nextEdge->source->index]){
						que.push(nextEdge->source->index);
					}
				}
			}
		}

		bool works = true;

		for(int i=0;i<n;i++){
			if(nodearray[i]->min != nodearray[i]->max){
				works = false;
				cout<<"NO"<<endl;
				break;
			}
		}

		if(works){
			cout<<"YES"<<endl;
			for(int i=0;i<n;i++){
				cout<<nodearray[i]->min<<" ";
			}
			cout<<endl;
		}
	}
}