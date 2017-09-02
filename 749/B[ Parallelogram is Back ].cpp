#include<bits/stdc++.h>
using namespace std;

int main()
{
    float x1,x2,x3,x4,y1,y2,y3,y4;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    cout<<3<<endl;
    x4=(x1+x2)/2;
    y4=(y1+y2)/2;
    x4=x4-x3;
    x4=x3+2*x4;
    y4=y4-y3;
    y4=y3+2*y4;
    cout<<int(x4)<<" "<<int(y4)<<endl;
    x4=(x3+x2)/2;
    y4=(y3+y2)/2;
    x4=x4-x1;
    x4=x1+2*x4;
    y4=y4-y1;
    y4=y1+2*y4;
    cout<<x4<<" "<<y4<<endl;
    x4=(x1+x3)/2;
    y4=(y1+y3)/2;
    x4=x4-x2;
    x4=x2+2*x4;
    y4=y4-y2;
    y4=y2+2*y4;
    cout<<x4<<" "<<y4<<endl;
    return 0;
}
