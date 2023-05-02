#include<iostream>
#include<cmath>
using namespace std;

int count = 0;
int dem(int a)
{
    int d=0;
    while(a!=0)
    {
        d++;
        a=a/10;
    }
    return d;
}
bool amstrong(int a, int d)
{
    int b=a;
    int s=0;
    while(b!=0)
    {
        s=s+pow(b%10,d);
        b/=10;
        if(s>a) return false;
    }
    return s==a;
}
int tongtrudonvi(int a, int d)
{
    int s=0;
    int b=pow(a%10,d);
    while(a!=0)
    {
        s=s+pow(a%10,d);
        a/=10;
    }
    return s-b;
}
int nammoadidaphat(int &i,int i2, int c, int c2, int s,int b)
{
    if(c2==0) 
    {
        while(i2<10)
        {
            if(s+pow(i2,c)==i)
            {
                count++;
                cout<<i<<" ";
            }
            if(i==b) return 0;
            i++;
            i2++;
        }
    }
    else
    {
        int mu=pow(10,c2);
        while(i2/mu<10)
        {
            nammoadidaphat(i,i2%mu,c,c2-1,s+pow(i2/mu,c),b);
            i2=i2+mu-i2%mu;
        }
    }
    return 0;
}
int main()
{
    int a, b;
    cin>>a;
    cin>>b;
    int c=dem(a);
    int i=a;
    int s=tongtrudonvi(a,c);
    while(i<=b)
    {
        if(i/a>=10)
        {
            c++;
            a=a*10;
        }
        nammoadidaphat(i,i,c,c-1,0,b);
        i++;
    }
    if (count == 0) {
        cout << -1;
    }
}