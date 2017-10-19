#include<bits/stdc++.h>
using namespace std;
using LL=int64_t;

LL gcd(LL a,LL b,LL& x,LL& y) {
    if(!b) {x=1;y=0;return a;}
    LL res=gcd(b,a%b,y,x);
    y-=x*(a/b);
    return res;
}

bool linear_equation(LL a,LL b,LL c,LL &x,LL &y)
{
    LL d=gcd(a,b,x,y);
    if(c%d) return false;//нч╫Б
    LL k=c/d;
    x*=k; y*=k;    //ЁУ╫Б
    LL tb=b/(__gcd(a,b)),ta=a/(__gcd(a,b));
    LL t=x/tb;
    x=x-tb*t;y=y+ta*t;
    if(x<0) {
        if(tb>0)  x+=tb,y-=ta;
        else  x-=tb,y+=ta;
    }
    return true;
}

int main()
{
    LL a,b,c,x,y;
    cin>>a>>b>>c;
    if(linear_equation(a,b,c,x,y)) {
        cout<<x<<" "<<y<<endl;
    }
    else cout<<"No Solution\n";
    return 0;
}
