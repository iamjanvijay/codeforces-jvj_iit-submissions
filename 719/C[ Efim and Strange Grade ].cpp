#include <bits/stdc++.h>

using namespace std;

char S[200007];

void increment(int first,int last)
{
	int carry = 1;

	int i = last;

	while(carry != 0)
	{
		if(S[i]!=&#39;9&#39;)
		{
			S[i]++;
			carry--;
		}
		else
		{
			S[i] = &#39;0&#39;;
		}
		i--;	
	}	

}

int main()
{
	int N,T;
	scanf("%d%d",&N,&T);

	S[0] = &#39;0&#39;;
	scanf("%s",S+1);

	int dot = 0;

	for(int i=1;i<N+1;i++)
	{
		if(S[i]==&#39;.&#39;)
		{
			dot = i; break;
		}
	}

	bool flag = false;

	if(S[dot+1]>=&#39;5&#39; && T>0)
	{
		S[dot] = &#39;\0&#39;;
		increment(1,dot-1);
		T--;
		flag = true;
	}	

	if(flag == false)
	{
		int x = 0;

		for(int i = dot+1;i<N+1;i++)
		{
			if(i+1<N+1 && T>0 && S[i+1]>=&#39;5&#39;)
			{
				S[i]++;
				S[i+1] = &#39;\0&#39;;
				x = i - 1;
				T--;
				break;
			}	
		}	

		while( x>=dot+1 && T>0 && S[x+1] >= &#39;5&#39; )
		{
			S[x]++;
			S[x+1] = &#39;\0&#39;;
			x--;
			T--;
		}

		if(T>0 && S[dot+1]>=&#39;5&#39;)
		{
			S[dot] = &#39;\0&#39;;
			increment(1,dot-1);
			T--;
		}	

	}

	if(S[0]==&#39;0&#39;)
		printf("%s\n",S+1);
	else
		printf("%s\n",S);

	return 0;
}
