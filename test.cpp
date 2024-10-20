#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef map<int,int>mii;
typedef unordered_map<int,int>umii;
typedef set<int,int>sii;
typedef multiset<int,int>msii;
const int mod=1000000007;
vector<int> spf(1000001);
#define fer(i,a,b) for (int i = a; i <b; i++)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
vector<int>div(int n)
{
    vector<int>v;
    while(n!=1)
    {
        v.push_back(spf[n]);
        n=n/spf[n];
    }
    return v;
}
long long modexpo(long long base, long long expo) {
    long long result = 1;
    base = base % mod;
    
    while (expo > 0) {
        if (expo % 2 == 1) {
            result = (result * base) % mod;
        }
        expo = expo >> 1;
        base = (base * base) % mod;
    }
    
    return result;
}
vector<int>spff(int n) {
    for (int i = 1; i <= n; i++) {
        spf[i] = i;
    }
    for (int i = 2; i * i <= n; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= n; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }

    return spf;
}
vector<bool> sieve(int n){
    vector<bool>prime(n+1,true);
    prime[0]=false;
    prime[1]=false;
    for(int i=2; i*i <= n; i++)
    {
        if(prime[i])
        {
            for(int j = i*i; j <= n; j = j+i)
            {
                prime[j] = false;
            }
        }
    }
    return prime;
}
bool is_prime(int number) {
    if (number <= 1) {
        return false;
    }
    if (number <= 3) {
        return true;
    }
    if (number % 2 == 0 || number % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}
vector<int> next_greater_element(int a[],int n)
{
    stack<int> s;
    vector<int> b(n, -1);
    for(int i = 0; i < n; i++)
    {
        if(s.empty())
        {
            s.push(a[i]);
        }
        else
        {
            int j = i;
            while(a[i] > s.top())
            {
                j--;
                b[j] = a[i];
                s.pop();
                if(s.empty()) break;
            }
            s.push(a[i]);
        }
    }
    return b;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int xc,yc,k;
        cin>>xc>>yc>>k;
        cout<<xc<<" "<<yc<<"\n";
        k--;
        int m=1;
        for(int i=0;i<k;i++)
        {
            cout<<xc-m<<" "<<yc<<"\n";
            cout<<xc+m<<" "<<yc<<"\n";
            m++;
        }
    }
    return 0;
}