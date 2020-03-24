#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 30
#define MOVESCOUNT 500
#define POPSIZE 10

typedef pair<ll,ll> operation;

uint64_t timeSinceEpochMillisec() {
  using namespace std::chrono;
  return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

struct point { 
    ll x, y; 
  
    bool operator<(point p) 
    { 
        return x < p.x || (x == p.x && y < p.y); 
    } 

    ll first(){
    	return x;
    }

    ll second(){
    	return y;
    }
}; 
  
// Cross product of two vectors OA and OB 
// returns positive for counter clockwise 
// turn and negative for clockwise turn 
ll cross_product(point O, point A, point B) 
{ 
    return (A.x - O.x) * (B.y - O.y) 
           - (A.y - O.y) * (B.x - O.x); 
} 
  
// Returns a list of points on the convex hull 
// in counter-clockwise order 
vector<point> convex_hull(vector<point> A) 
{ 
    int n = A.size(), k = 0; 
  
    if (n <= 3) 
        return A; 
  
    vector<point> ans(2 * n); 
  
    // Sort points lexicographically 
    sort(A.begin(), A.end()); 
  
    // Build lower hull 
    for (int i = 0; i < n; ++i) { 
  
        // If the point at K-1 position is not a part 
        // of hull as vector from ans[k-2] to ans[k-1]  
        // and ans[k-2] to A[i] has a clockwise turn 
        while (k >= 2 && cross_product(ans[k - 2],  
                          ans[k - 1], A[i]) <= 0) 
            k--; 
        ans[k++] = A[i]; 
    } 
  
    // Build upper hull 
    for (size_t i = n - 1, t = k + 1; i > 0; --i) { 
  
        // If the point at K-1 position is not a part 
        // of hull as vector from ans[k-2] to ans[k-1]  
        // and ans[k-2] to A[i] has a clockwise turn 
        while (k >= t && cross_product(ans[k - 2], 
                           ans[k - 1], A[i - 1]) <= 0) 
            k--; 
        ans[k++] = A[i - 1]; 
    } 
  
    // Resize the array to desired size 
    ans.resize(k - 1); 
  
    return ans; 
} 



vector<vector<vector<point> > > getBoard(vector<point> vec, ll kw, ll kh){
    vector<vector<vector<point> > > myBoard(N,vector<vector<point> >(N));
    for(int i=0;i<vec.size();i++){
    	point curr=vec[i];
    	myBoard[curr.first()/kw][curr.second()/kh].push_back({curr.first()%kw,curr.second()%kh});
    }
	return myBoard;	
}

vector<vector<vector<point> > > operateBoard(vector<vector<vector<point> > > ogBoard, vector<operation> moves){
	for(int i=0;i<moves.size();i++){
		if(moves[i].first==1){
			//i need to rotate the jth column down
			vector<vector<point> >temp;
			for(int j=0;j<N;j++){
				temp.push_back(ogBoard[j][moves[i].second-1]);
			}
			for(int j=0;j<N;j++){
				ogBoard[(j+1)%N][moves[i].second-1]=temp[j];
			}			
		}
		else{
			vector<vector<point> >temp;
			for(int j=0;j<N;j++){
				temp.push_back(ogBoard[moves[i].second-1][j]);
			}
			for(int j=0;j<N;j++){
				ogBoard[moves[i].second-1][(j+1)%N]=temp[j];
			}			

			//shift jth row to the right
		}
	}
	return ogBoard;
}



vector<point> getPoints(vector<vector<vector<point> > > myBoard, ll kw, ll kh){
	vector<point> theVec;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			for(int k=0;k<myBoard[i][j].size();k++){
				theVec.push_back({i*kw+myBoard[i][j][k].first(),j*kh+myBoard[i][j][k].second()});
			}
		}
	}
	return theVec;
}

double polygonArea(vector<point> hull, int n) 
{ 
    // Initialze area 
    double area = 0.0; 
  
    // Calculate value of shoelace formula 
    int j = n - 1; 
    for (int i = 0; i < n; i++) 
    { 
        area += (hull[j].first() + hull[i].first()) * (hull[j].second() - hull[i].second()); 
        j = i;  // j is previous vertex to i 
    } 
  
    // Return absolute value 
    return abs(area / 2.0); 
} 

class Individual
{
	public:
		vector<operation> chromosome;
		double fitness;
		int kw;
		int kh;
		vector<vector<vector<point> > > ogBoard;
		Individual(vector<operation> chromosome, vector<vector<vector<point> > > ogBoard, int kw, int kh);
		Individual mate(Individual parent2);
		double cal_fitness();
};

Individual::Individual(vector<operation> chromosome,vector<vector<vector<point> > > ogBoard, int kw, int kh){
	this->chromosome=chromosome;
	this->ogBoard=ogBoard;
	this->kw=kw;
	this->kh=kh;
	fitness=cal_fitness();
};

int random_num(int start, int end) 
{ 
    int range = (end-start)+1; 
    int random_int = start+(rand()%range); 
    return random_int; 
} 

operation mutated_genes() 
{ 
	return {rand()%2+1,rand()%N+1};
} 

Individual Individual::mate(Individual par2) 
{ 
    // chromosome for offspring 
    vector<operation> child_chromosome;
  
    int len = chromosome.size(); 
    for(int i = 0;i<len;i++) 
    { 
        // random probability  
        double p = ((double)(rand()))/RAND_MAX; 
  
        if(p < 0.45) 
            child_chromosome.push_back(chromosome[i]);   
        else if(p < 0.90) 
            child_chromosome.push_back(par2.chromosome[i]);   
        else
            child_chromosome.push_back(mutated_genes()); 
    } 
  
    // create new Individual(offspring) using  
    // generated chromosome for offspring 
    return Individual(child_chromosome, ogBoard, kw, kh); 
}; 

double Individual::cal_fitness(){
	vector<vector<vector<point> > > newBoard=operateBoard(ogBoard,this->chromosome);
   	vector<point> newPoints=getPoints(newBoard,kw,kh);
    vector<point> newHull=convex_hull(newPoints);
    return 0-polygonArea(newHull,newHull.size());
} 

bool operator<(const Individual &ind1, const Individual &ind2) 
{ 
    return ind1.fitness < ind2.fitness; 
}


int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint64_t startTime=timeSinceEpochMillisec();
    srand(time(0));

    ll w,h,r;
    cin>>w>>h>>r;

    vector<point> vec;

    ll x,y;
    for(int i=0;i<r;i++){
    	cin>>x>>y;
    	vec.push_back({x,y});
    }

    //w=h=720720
    //we'll use 30x30 grid

    ll n,m;
    n=m=N;

    ll kw=w/n;
    ll kh=h/m;

    vector<vector<vector<point> > > myBoard=getBoard(vec,kw,kh);

    // for(int i=0;i<N;i++){
    // 	for(int j=0;j<N;j++){
    // 		cerr<<myBoard[i][j].size()<<" ";
    // 	}
    // 	cerr<<endl;
    // }

    // vector<operation> opVec;
    // opVec.push_back({1,2}); 
    // opVec.push_back({2,3}); 
    // opVec.push_back({2,3});

    // myBoard=operateBoard(myBoard,opVec); 
    // vector<point> newPoints = getPoints(myBoard,kw,kh);
    // vector<point> ans = convex_hull(newPoints);

    // for(int i=0;i<N;i++){
    // 	for(int j=0;j<N;j++){
    // 		cerr<<myBoard[i][j].size()<<" ";
    // 	}
    // 	cerr<<endl;
    // }


    // for(int i=0;i<ans.size();i++){
    // 	cerr<<ans[i].first()<<" "<<ans[i].second()<<endl;
    // }
    // cerr<<polygonArea(ans,ans.size())<<endl;

    double bestVal=INT_MAX;
    vector<operation> bestVec;

    vector<Individual> population;
    for(int i=0;i<POPSIZE;i++){
    	vector<operation> testVec;
    	for(int i=0;i<MOVESCOUNT;i++){
    		testVec.push_back(mutated_genes());
    	}
    	population.push_back(Individual(testVec,myBoard,kw,kh));
    }

    int generationNo=0;
    while(timeSinceEpochMillisec()-startTime<4500){
    	// cerr<<time(0)<<endl;
    	vector<Individual> newGeneration;

    	sort(population.begin(), population.end()); 

    	bestVec=population[0].chromosome;
    	bestVal=population[0].fitness;
    	cerr<<generationNo<<" "<<bestVal<<endl;
		int s = (10*POPSIZE)/100; 
        for(int i = 0;i<s;i++) 
            newGeneration.push_back(population[i]);

		s = (90*POPSIZE)/100; 
        for(int i = 0;i<s;i++) 
        { 
            int len = population.size(); 
            int r = random_num(0, POPSIZE/2); 
            Individual parent1 = population[r]; 
            r = random_num(0, POPSIZE/2); 
            Individual parent2 = population[r]; 
            Individual offspring = parent1.mate(parent2); 
            newGeneration.push_back(offspring);  
        } 
        population = newGeneration; 
        generationNo++;
    }

    cout<<n<<" "<<m<<" "<<bestVec.size()<<endl;
    for(int i=0;i<bestVec.size();i++){
    	cout<<bestVec[i].first<<" "<<bestVec[i].second<<endl;
    }
    // cerr<<bestVal<<endl;
}