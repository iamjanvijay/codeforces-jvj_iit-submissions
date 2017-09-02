#include <bits/stdc++.h>

using namespace std;

char S[107][107];
int Slen[107];

char Pwd[107];
int Pwdlen;

int main()
{
	int N,K;

	scanf("%d%d",&N,&K);

	for(int i=0;i<N;i++)
	{
		scanf("%s",S[i]);
		Slen[i] = strlen(S[i]);
	}

	scanf("%s",Pwd);
	Pwdlen = strlen(Pwd);

	int sm = 0, eq = 0;

	for(int i=0;i<N;i++)
	{
		if(Slen[i]<Pwdlen)
			sm++;
		if(Slen[i]==Pwdlen)
			eq++;
	}

	int best = sm + ( (sm/K) * 5 ) + 1;	
	int worst = sm+eq-1 + ( ((sm+eq-1)/K)*5 ) + 1;

	printf("%d %d\n",best,worst);
	return 0;
} 