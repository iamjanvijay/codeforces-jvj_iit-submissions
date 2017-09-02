#include <bits/stdc++.h>
using namespace std;

#define sd(x) scanf("%d",&x)
#define su(x) scanf("%u",&x)
#define slld(x) scanf("%lld",&x)
#define sc(x) scanf("%c",&x)
#define ss(x) scanf("%s",x)
#define sf(x) scanf("%f",&x)
#define slf(x) scanf("%lf",&x)
#define ll long long int
#define mod(x,n) (x+n)%n

bool TF[100];
string Strset[100];
string ANS[100];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n;
	string S,T;

	sd(n);	sd(k);

	for(i=0;i<n-k+1;i++)
	{
		cin >> S;
		if(S=="YES")
			TF[i] = true;
		else
			TF[i] = false;
	}

	for(i=0;i<26;i++)
		Strset[i].push_back((char)(&#39;A&#39;+i));

	for(i;i<26+26;i++)
	{
		Strset[i] = "A";
		Strset[i].push_back((char)(&#39;a&#39;+i-26));
	}

	// for(i=0;i<52;i++)
	// 	cout << Strset[i] << endl;

	i=0;	j=0;
	if(TF[0])
	{
		for(l=0;l<k;l++)
			ANS[l] = Strset[j++];

	}
	else
	{
		for(l=0;l<k-1;l++)
			ANS[l] = Strset[j++];
		ANS[l] = ANS[0];			
	}	
	i++;

	for(i;i<n-k+1;i++)
	{
		if(TF[i])
		{
			ANS[i+k-1] = Strset[j++];
		}
		else
		{
			ANS[i+k-1] = ANS[i];
		}
	}	

	for(i=0;i<n;i++)
		cout << ANS[i] << " ";
	cout << endl;
	
	return 0;
}