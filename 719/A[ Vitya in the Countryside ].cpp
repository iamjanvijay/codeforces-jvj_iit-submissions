#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N,last=-1,slast;
	scanf("%d",&N);

	for(int i=0;i<N;i++)
	{
		slast = last;
		scanf("%d",&last);
	}
	//cout << slast << " " << last <<endl;

	if(last==15)
		printf("DOWN\n");
	else if(last==0)
		printf("UP\n");
	else if(N==1)
		printf("-1\n");
	else if(last-slast==-1)
		printf("DOWN\n");
	else 
		printf("UP\n");			

	return 0;
}