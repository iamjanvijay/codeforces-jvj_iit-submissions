#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

struct Node
{
	int NumOpen;
	int NumClose;
	int NumCorrect;

	Node()
	{	}

	Node(int a,int b, int c)
	{
		NumOpen = a;
		NumClose = b;
		NumCorrect = c;
	}

};

char S[1000007];
Node T[(1<<21)];

void createTree(int first,int last,int current)
{
	if(first == last)
	{
		if(S[first]==&#39;(&#39;) // opening bracket
		{
			T[current].NumOpen = 1; T[current].NumClose = 0; T[current].NumCorrect = 0;
		}
		else // closing bracket
		{
			T[current].NumOpen = 0; T[current].NumClose = 1; T[current].NumCorrect = 0;
		}
		return;
	}

	int mid = (first+last)/2;

	createTree(first,mid,2*current + 1);	createTree(mid+1,last,2*current + 2);

	int K = min(T[2*current + 1].NumOpen,T[2*current + 2].NumClose);
	T[current].NumOpen = T[2*current + 1].NumOpen + T[2*current + 2].NumOpen - K;
	T[current].NumClose = T[2*current + 1].NumClose + T[2*current + 2].NumClose - K;
	T[current].NumCorrect = T[2*current + 1].NumCorrect + T[2*current + 2].NumCorrect + 2*K;
}

Node querySolver(int Qfirst,int Qlast,int first,int last,int current)
{
	if(Qlast<first || last < Qfirst)
		return Node(0,0,0);
	if(Qfirst<=first && last<=Qlast)
		return T[current];

	int mid = (first+last)/2;
	Node L = querySolver(Qfirst,Qlast,first,mid,2*current + 1);
	Node R = querySolver(Qfirst,Qlast,mid+1,last,2*current + 2);

	Node Cur;
	int K = min(L.NumOpen,R.NumClose);
	Cur.NumOpen = L.NumOpen + R.NumOpen - K;
	Cur.NumClose = L.NumClose + R.NumClose - K;
	Cur.NumCorrect = L.NumCorrect + R.NumCorrect + 2*K;
	return Cur;
}

int main()
{
	scanf("%s",S);
	int M,L,R,N = strlen(S);

	createTree(0,N-1,0);

	scanf("%d",&M);
	while(M--)
	{
		scanf("%d%d",&L,&R);	L--;	R--;

		Node temp = querySolver(L,R,0,N-1,0);

		printf("%d\n", temp.NumCorrect );
	}
	return 0;
}
