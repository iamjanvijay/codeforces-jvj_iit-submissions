#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int rootM = 1;

struct Dquery
{
	int L;
	int R;
	int i;

	bool operator < (const Dquery& B) const
	{
		if( (L/rootM) != ((B.L)/rootM) )
			return (L/rootM) < ((B.L)/rootM);
		else
			return R < B.R ;
	}
};


Dquery Q[200007];
LL results[200007] = {0} ;

int A[200007] = {0};
int counts[1000007] = {0};
LL distincts = 0;

void add_pos(int K)
{
	distincts += ((LL)(2*counts[A[K]] + 1)*A[K]);
	counts[A[K]]++; 
}

void rem_pos(int K)
{
	distincts += ((LL)(-2*counts[A[K]] + 1)*A[K]);
	counts[A[K]]--;
}

void init(int &curL,int &curR)
{
	curL = 0;
	curR = 0;
	add_pos(0);
}

int main()
{
	int i,j,N,M,L,R;
	Dquery temp;

	scanf("%d%d",&N,&M);

	for(i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
	}	


	for(i=0;i<M;i++)
	{
		scanf("%d%d",&(temp.L),&(temp.R));
		(temp.L)--;	(temp.R)--; temp.i = i;
		Q[i] = temp;
	}

	rootM = (int) sqrt(M);

	sort(Q,Q+M);

	int curL,curR;

	init(curL,curR); 

	for(i=0;i<M;i++)
	{
		L = Q[i].L; R = Q[i].R; j = Q[i].i;

		if(L<curL)
		{
			while(curL!=L)
			{
				add_pos(--curL);
			}	
		}

		if(R>curR)
		{
			while(curR!=R)
			{
				add_pos(++curR);
			}
		}

		if(L>curL)
		{
			while(curL!=L)
			{
				rem_pos(curL++);
			}	
		}

		if(R<curR)
		{
			while(curR!=R)
			{
				rem_pos(curR--);
			}	
		}

		results[j] = distincts;

	}

	for(i=0;i<M;i++)
	{
		cout << results[i] <<"\n";
	}	

	return 0;
}