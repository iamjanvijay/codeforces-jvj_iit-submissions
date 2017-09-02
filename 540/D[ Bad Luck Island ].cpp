#include <bits/stdc++.h>
#include <queue>
using namespace std;

double Prob[105][105][105]={0};

bool Found[105][105][105]; 

struct tier
{
	int S,P,R;
};

void setFound(tier T)
{
	Found[T.S][T.P][T.R] = true;
}

bool isFound(tier T)
{
	return Found[T.S][T.P][T.R];
}

int main()
{
	int S,P,R; //stone paper scissor

	scanf("%d%d%d",&S,&R,&P);

	Prob[S][P][R] = 1.0;

	tier T;

	queue<tier> Q;

	T.S = S; T.P = P; T.R = R;

	Q.push(T);

	while(Q.size()!=0)
	{
		T = Q.front(); Q.pop();

		if( T.S > 0 && T.P > 0 )
		{
			Prob [ T.S -1 ] [ T.P ] [ T.R ] += ( Prob[ T.S ][ T.P ][ T.R ] * (T.S * T.P) / ((T.S * T.P)+(T.R * T.P)+(T.S * T.R)) );
			if( !( ( T.S > 0 && T.P == 0 && T.R == 0 ) || ( T.S == 0 && T.P > 0 && T.R == 0 ) || ( T.S == 0 && T.P == 0 && T.R > 0 ) ) )
			{
				tier T1 = T ;
				T1.S = T1.S - 1;
				if(!isFound(T1))
				{
					Q.push(T1);
					setFound(T1);
				}
			}	
		}
		if( T.P > 0 && T.R > 0 )
		{
			Prob [ T.S ] [ T.P - 1 ] [ T.R ] += ( Prob [ T.S ] [ T.P ] [ T.R ] * (T.R * T.P) / ((T.S * T.P)+(T.R * T.P)+(T.S * T.R)) );
			if( !( ( T.S > 0 && T.P == 0 && T.R == 0 ) || ( T.S == 0 && T.P > 0 && T.R == 0 ) || ( T.S == 0 && T.P == 0 && T.R > 0 ) ) )
			{
				tier T1 = T ;
				T1.P = T1.P - 1;
				if(!isFound(T1))
				{
					Q.push(T1);
					setFound(T1);
				}
			}			
		}
		if( T.R > 0 && T.S > 0 )
		{	
			Prob [ T.S ] [ T.P ] [ T.R - 1 ] += ( Prob [ T.S ] [ T.P ] [ T.R ] * (T.S * T.R) / ((T.S * T.P)+(T.R * T.P)+(T.S * T.R)) );
			if( !( ( T.S > 0 && T.P == 0 && T.R == 0 ) || ( T.S == 0 && T.P > 0 && T.R == 0 ) || ( T.S == 0 && T.P == 0 && T.R > 0 ) ) )
			{
				tier T1 = T ;
				T1.R = T1.R - 1;
				if(!isFound(T1))
				{
					Q.push(T1);
					setFound(T1);
				}
			}	    
	    }	
	}

	double P_S = 0,P_P = 0,P_R = 0;
	int i;
	for(i=1;i<=S;i++)
		P_S += Prob[i][0][0];

	for(i=1;i<=P;i++)
		P_P += Prob[0][i][0];

	for(i=1;i<=R;i++)
		P_R += Prob[0][0][i];

	printf("%0.12lf %0.12lf %0.12lf\n",P_S,P_R,P_P);				

	return 0;
}