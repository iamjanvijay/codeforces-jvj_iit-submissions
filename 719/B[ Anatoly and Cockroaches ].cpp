#include <bits/stdc++.h>

using namespace std;

char S[100007];

int costrbrb(int N)
{
	int cost = 0;

	int x = 0, y = 0;

	for(int i=0;i<N;i+=2) // rbrb
	{
		if(S[i] == &#39;b&#39;)
			x++;
	}

	for(int i=1;i<N;i+=2) // rbrb
	{
		if(S[i] == &#39;r&#39;)
			y++;
	}

	cost = x + y - min(x,y);	

	return cost;
}

int costbrbr(int N)
{
	int x = 0, y = 0;

	int cost = 0;

	for(int i=0;i<N;i+=2) // brbr
	{
		if(S[i] == &#39;r&#39;)
			x++;
	}

	for(int i=1;i<N;i+=2) // brbr
	{
		if(S[i] == &#39;b&#39;)
			y++;
	}

	cost = x + y - min(x,y);

	return cost;
}

int cost(int N)
{
	int cost1 = 0, cost2 = 0;

	cost1 = costrbrb(N);
	cost2 = costbrbr(N);

	return min(cost2,cost1);			
}

int main()
{
	int N;
	scanf("%d",&N);

	scanf("%s",S);

	printf("%d\n",cost(N));

	return 0;
}