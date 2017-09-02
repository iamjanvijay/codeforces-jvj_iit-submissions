#include <bits/stdc++.h>
using namespace std;

#define sd(x) 		scanf("%d",&x)
#define su(x) 		scanf("%u",&x)
#define slld(x) 	scanf("%lld",&x)
#define sc(x) 		scanf("%c",&x)
#define ss(x) 		scanf("%s",x)
#define sf(x) 		scanf("%f",&x)
#define slf(x)		scanf("%lf",&x)
#define ll 			long long int
#define mod(x,n) 	(x+n)%n
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define Mod         1000000007


int c[5050];
int main()
{
    int i,j,k,n,m,cnt=0;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++) scanf("%d",&c[i]);
    sort(c,c+n);
    for(i=0;i<n;i++){
        if(c[i]!=c[(i+n/2)%n]) cnt++;
    }
    printf("%d\n",cnt);
    for(i=0;i<n;i++){
        printf("%d %d\n",c[i],c[(i+n/2)%n]);
    }
    return 0;
}