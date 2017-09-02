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

char S[107];

int main()
{
	int i,j,k,l,nb,ns,nc,pb,ps,pc,mb,ms,mc;

	ll r,t,ans=0;

	ss(S);

	mb = ms = mc = 0;
	for(i=0;S[i]!=&#39;\0&#39;;i++)
		if(S[i]==&#39;B&#39;)
			mb++;
		else if(S[i]==&#39;S&#39;)
			ms++;
		else
			mc++;

	sd(nb);	sd(ns);	sd(nc);
	
	sd(pb);	sd(ps);	sd(pc);

	slld(r);

	if(mb==0 && ms!=0 && mc!=0)
	{
		mb = mc;	mc = 0;
		nb = nc;
		pb = pc;
	}

	if(mb!=0 && ms==0 && mc!=0)
	{
		ms = mc;	mc = 0;
		ns = nc;
		ps = pc;
	}

	if(mb==0 && ms==0 && mc!=0)
	{
		mb = mc;	mc = 0;
		nb = nc;
		pb = pc;
	}

	if(mb==0 && ms!=0 && mc==0)
	{
		mb = ms;	ms = 0;
		nb = ns;
		pb = ps;
	}	

	if(mb!=0 && ms!=0 && mc!=0)
	{	
		// printf("%d %d %d\n", mb,ms,mc );
		while(nb>=mb && ns>=ms && nc>=mc)
		{
			nb-=mb;	ns-=ms;	nc-=mc;
			ans++;
		}
		// printf("-> %lld\n", ans );
		while( nb>=mb && ns>=ms && nc<mc && r>=(mc-nc)*pc )
		{
			r-=(mc-nc)*pc;
			nb-=mb;	ns-=ms;	nc=0;
			ans++;
		}		
		// printf("-> %lld\n", ans );
		while( nb>=mb && nc>=mc && ns<ms && r>=(ms-ns)*ps )
		{
			r-=(ms-ns)*ps;
			nb-=mb;	nc-=mc;	ns=0;
			ans++;
		}	
		// printf("-> %lld\n", ans );
		while( nc>=mc && ns>=ms && nb<mb && r>=(mb-nb)*pb )
		{
			r-=(mb-nb)*pb;
			nc-=mc;	ns-=ms;	nb=0;
			ans++;
		}
		// printf("-> %lld\n", ans );
		while(nb>=mb && ns<ms && nc<mc && r>=(ms-ns)*ps+(mc-nc)*pc)
		{
			r-=((ms-ns)*ps+(mc-nc)*pc);
			ns = 0;	nc = 0;
			nb-=mb;	
			ans++;
		}
		// printf("-> %lld\n", ans );
		while(ns>=ms && nb<mb && nc<mc && r>=(mb-nb)*pb+(mc-nc)*pc)
		{
			r-=((mb-nb)*pb+(mc-nc)*pc);
			nb = 0;	nc = 0;
			ns-=ms;	
			ans++;
		}
		// printf("-> %lld\n", ans );
		while(nc>=mc && ns<ms && nb<mb && r>=(ms-ns)*ps+(mb-nb)*pb)
		{
			r-=((ms-ns)*ps+(mb-nb)*pb);
			ns = 0;	nb = 0;
			nc-=mc;	
			ans++;
		}
		// printf("-> %lld\n", ans );
		if(nc<mc && ns<ms && nb<mb && r>=(ms-ns)*ps+(mb-nb)*pb+(mc-nc)*pc)
		{
			r-=((ms-ns)*ps+(mb-nb)*pb+(mc-nc)*pc);			
			ns = nb = nc = 0;
			ans++;
		}
		// printf("-> %lld\n", ans );
		ans += (r/(pb*mb+ps*ms+pc*mc));
		// printf("-> %lld\n", ans );
		printf("%lld\n", ans );
	}
	else if(mb!=0 && ms!=0 && mc==0)
	{
		while(nb>=mb && ns>=ms)
		{
			nb-=mb;	ns-=ms;
			ans++;
		}

		while( nb>=mb && ns<ms && r>=(ms-ns)*ps )
		{
			r-=(ms-ns)*ps;
			nb-=mb;	ns=0;
			ans++;
		}

		while( ns>=ms && nb<mb && r>=(mb-nb)*pb )
		{
			r-=(mb-nb)*pb;
			ns-=ms;	nb=0;
			ans++;
		}

		if( ns<ms && nb<mb && r>=(ms-ns)*ps+(mb-nb)*pb)
		{
			r-=((ms-ns)*ps+(mb-nb)*pb);			
			ns = nb = 0;
			ans++;
		}

		ans += (r/(pb*mb+ps*ms));		
		printf("%lld\n", ans );
	}
	else if(mb!=0 && ms==0 && mc==0)
	{
		while(nb>=mb)
		{
			nb-=mb;
			ans++;
		}

		if(nb<mb &&r>=(mb-nb)*pb)
		{
			r-=((mb-nb)*pb);
			nb = 0;
			ans++;
		}

		ans += (r/(pb*mb));
		printf("%lld\n", ans );
	}				

	return 0;
}
