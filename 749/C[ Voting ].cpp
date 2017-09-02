#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

char S[200007];
queue<int> D;
queue<int> R;

int main()
{
	int i,N,D_C,R_C;
	scanf("%d",&N);

	scanf("%s",S);

	for(i=0;i<N;i++)
		if(S[i]==&#39;D&#39;)
			D.push(i);
		else
			R.push(i);

	i=0;
	while(i<N-1 && D.size()!=0 && R.size()!=0)
	{
		D_C = D.front();
		R_C = R.front();

		if( D_C < R_C )
		{
			R.pop();
			D.pop();
			D.push(N+D_C);
		}
		else
		{
			D.pop();
			R.pop();
			R.push(N+R_C);
		}
		i++;
	}

	if(R.size() != 0)
		printf("R\n");
	else
		printf("D\n");

	return 0;
}
