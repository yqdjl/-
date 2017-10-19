#include<bits/stdc++.h>
using namespace std;

/*
const int MAXBUF = 10000;
char buf[MAXBUF], *ps = buf, *pe = buf+1;

inline void rnext()
{
    if(++ps == pe)
        pe = (ps = buf)+fread(buf,sizeof(char),sizeof(buf)/sizeof(char),stdin);
}

template <class T>
inline bool readin(T &ans)
{
    ans = 0;
    T f = 1;
    if(ps == pe) return false;//EOF
    do{
        rnext();
        if('-' == *ps) f = -1;
    }while(!isdigit(*ps) && ps != pe);
    if(ps == pe) return false;//EOF
    do
    {
        ans = (ans<<1)+(ans<<3)+*ps-48;
        rnext();
    }while(isdigit(*ps) && ps != pe);
    ans *= f;
    return true;
}*/

int main()
{
    char s[10];
    string s1;
    cin.get(s,10);//接受输入空格,并指定最大输入数
    cin.getline(s,10,'a');//以输入a作为结束输入标志
    getline(cin,s1);//接受输入空格,并且这个是string输入流的，前面的是istream输入流的
    return 0;
}
