#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vl ;
typedef pair<ll,ll> pl;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define all(v) (v).begin(),(v).end()
#define max(a,b) (a>b ? a : b)
#define min(a,b) (a<b ? a : b)

const int MOD = 1000000007;
const int N = 1000002;
const double PI =4*atan(1);
const double eps = 1e-7;
const long long oo = 1e18;

long double xo,yo,xa,ya,xb,yb;
ll t;

long double norme(long double a, long double b){
    return sqrt(a*a+b*b);
}

int main(){
    //ios::sync_with_stdio(0);
    freopen("inclusion.in","r",stdin);
    cin >> t ;
    while(t--){
        cin >> xo >> yo >> xa >> ya >> xb >> yb;
        xa-=xo;
        ya-=yo;
        xb-=xo;
        yb-=yo;
        long double e = xa*xb+ya*yb;
        e/=(norme(xa,ya)*(norme(xb,yb)));
        long double ans = acos(e);
        if(fabs(ans-PI)<0.00001){
                long double u=1.000;
            printf("%.3Lf\n",fabs(u));
            continue;
        }
        ans/=(2*PI);
        printf("%.3Lf\n",fabs(ans));
    }

    return 0;
}
