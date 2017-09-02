#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
				
LL MAX = 10000000000000000;

struct edge
{
	int u;
	int v;
	LL WT;
};

struct Pair
{
    LL V;
    LL WT; 

};

struct lesser
{
  bool operator()(const Pair& lhs, const Pair& rhs) const
  {
    return lhs.WT > rhs.WT;
  }
};

vector<Pair> G[1007]; //GRAPH
map<int,int> Pos[1007];
map<int,int> next;
map<pair<int,int>,bool> exists;

void Dijkstra(int N,int S,LL W[],int P_t[])
{

	int Parent[1007];
	LL ANS[1007];
	bool included[1007];

	for(int i=0;i<N;i++)
	{
		Parent[i] = -1; ANS[i] = MAX; included[i] = false; 
	}

    Pair temp,temp1;
    priority_queue<Pair,vector<Pair>,lesser> P;

    Parent[S] = S;
    ANS[S] = 0;

    temp.V = S; temp.WT = 0;

    P.push(temp);

    while( P.size() != 0 )
    {
        temp = P.top(); P.pop();

        if(included[temp.V])
            continue;

        included[temp.V] = true;

        LL size = G[temp.V].size();

        for(LL i=0;i<size;i++)
        {
            if( included[ G[temp.V][i].V ] == false && G[temp.V][i].WT + temp.WT < ANS[ G[temp.V][i].V ]) 
            {
                ANS[ G[temp.V][i].V ] =  G[temp.V][i].WT + temp.WT ;
                Parent[ G[temp.V][i].V ] =  temp.V ;
                temp1.V = G[temp.V][i].V;
                temp1.WT =  ANS[ G[temp.V][i].V ]; 
                P.push(temp1);            
            }      
        }    
    }

    for(int i=0;i<N;i++)
    {
    	W[i] = ANS[i]; P_t[i] = Parent[i];
    }    

}

int main()
{

	int i,u,v,N,M,S,T;
	LL L,wt;

	cin >> N >> M >> L >> S >> T ;

	vector<edge> VE;
	vector<edge> E;

	for(i=0;i<M;i++)
	{
		cin >> u >> v >> wt;

		edge temp;
		temp.u = u; temp.v = v; temp.WT = wt;

		if(wt==0)
		{
			exists[make_pair(u,v)] = true;
			exists[make_pair(v,u)] = true;
			VE.push_back(temp);
		}
		else
		{
			E.push_back(temp);

        	Pair temp1; 
        
        	temp1.V = v ;
        	temp1.WT = wt;

        	Pos[u][v] =  G[u].size();
        	G[u].push_back(temp1);

        	temp1.V = u;
        	Pos[v][u] =  G[v].size();
        	G[v].push_back(temp1);
		}	

	}

	int P[1007]; LL W[1007];

	Dijkstra(N,S,W,P);

	if( W[T] < L )	
	{
		cout<<"NO\n";
		return 0;
	}

	int size = VE.size();

	for(i=0;i<size;i++)
	{
		VE[i].WT = 1; 

		u = VE[i].u ; v = VE[i].v ; wt = VE[i].WT ;

    	Pair temp1; 
    
    	temp1.V = v ;
    	temp1.WT = wt;
    	Pos[u][v] =  G[u].size();
    	G[u].push_back(temp1);

    	temp1.V = u;
    	Pos[v][u] =  G[v].size();
    	G[v].push_back(temp1);		
	}

	Dijkstra(N,S,W,P);

	if(W[T]>L)
	{
		cout<<"NO\n";
		return 0;	
	}

	i = T;
	while(i!=S)
	{
		if(exists[make_pair(i,P[i])])
		{
			G [ i ][ Pos[i][P[i]] ].WT = -1;
			G [ P[i] ] [ Pos[P[i]][i] ].WT = -1;
		}
		i=P[i];
	}

	int k = 0;

	for(i=0;i<size;i++)
	{
		u = VE[i].u ; v = VE[i].v ; wt = VE[i].WT ;

		if( G [ v ][ Pos[v][u] ].WT == -1 )
		{
			G [ v ][ Pos[v][u] ].WT = 1;
			G [ u ][ Pos[u][v] ].WT = 1;
			next[k++] = i;
		}
		else
		{
			G [ v ][ Pos[v][u] ].WT = MAX;
			G [ u ][ Pos[u][v] ].WT = MAX;
			VE[i].WT = MAX;			
		}	

	}

	i=0;
	while( W[T] < L && i<k )
	{

		u = VE[next[i]].u ; v = VE[next[i]].v ; wt = VE[next[i]].WT ;

		VE[next[i]].WT += L-W[T];
		G [ v ][ Pos[v][u] ].WT += L-W[T];
		G [ u ][ Pos[u][v] ].WT += L-W[T];

		Dijkstra(N,S,W,P);

		i++;
	}

	cout<<"YES\n";

	for(i=0;i<size;i++)
	{
		u = VE[i].u ; v = VE[i].v ; wt = VE[i].WT ;
		cout<<u<<" "<<v<<" "<<wt<<"\n";
	}

	size = E.size();	
	
	for(i=0;i<size;i++)
	{
		u = E[i].u ; v = E[i].v ; wt = E[i].WT ;
		cout<<u<<" "<<v<<" "<<wt<<"\n";
	}

	return 0;
}