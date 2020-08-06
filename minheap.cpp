#include<bits/stdc++.h>
using namespace std;

#define ll long long int

vector<ll>p;
vector<ll>q;

int minheap(ll a[], int n, int i)
{
    ll sum =0;
    int minimum = i;
    int l = (2*minimum)+1;
    int r = (2*minimum)+2;
    while(l<=n&&a[l]<a[minimum])
        minimum = l;
    while(r<=n&&a[r]<a[minimum])
        minimum = r;
    if(minimum!=i)
    {
        sum++;
        p.push_back(i);
        q.push_back(minimum);
        int temp = a[i];
        a[i] = a[minimum];
        a[minimum] = temp;
        minheap(a, n,minimum);
    }
    return 0;
}

int main()
{
    int n,sum=0,k=0;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i = n/2;i>=0;i--)
        minheap(a,n,i);
    int length = p.size();
    cout<<length<<"\n";
    for(int i=0;i<length;i++)
        {
            cout<<p[i]<<" "<<q[i]<<"\n";
        }
    return 0;
}
