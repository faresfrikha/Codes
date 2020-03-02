#include <bits/stdc++.h>

        using namespace std;

        /* ---*-----*-----
        ---------o--------
        -----------------*/

        typedef long long ll;
        typedef long double ld;

        typedef vector<ll> vl;

        #define mp make_pair
        #define pb push_back
        #define f first
        #define s second
        #define lb lower_bound
        #define ub upper_bound

        const int MOD = 998244353;
        const int N = 200005;
        const double PI =4*atan(1);
        const ll MAX=9223372036854775807;

        //set<char> vowel={'A', 'O', 'Y','E', 'U', 'I','a','o','e','u','i'};

        int dx[]={1,-1,0,0,1,-1,1,-1};
        int dy[]={0,0,1,-1,1,1,-1,-1};

        ll gcd(ll a, ll b) { return (b == 0 ? a : gcd(b, a % b)); }
        ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
        bool issquare(ll w ){return trunc(sqrt(w))*trunc(sqrt(w))==w;}
        bool isprime(ll u){for(ll i=2;i<=(int)sqrt(u);i++){if(u%i==0)return 0;}return 1;}
        ll mod(ll to_mod,ll MOD){to_mod%=MOD;while(to_mod<0)to_mod+=MOD;return to_mod%MOD;}
        ll moduloMultiplication(ll a,ll b,ll mod){ll res = 0;a %= mod;while (b){if (b & 1)
            res = (res + a) % mod;a = (2 * a) % mod;b >>= 1;}return res;}
        ll power(ll x, ll y/*,ll p*/){ll res = 1;x = x /*% p*/;
            while (y > 0){if (y & 1)res = (res*x)/* % p*/;y = y>>1;x = (x*x) /*% p*/;}return res;}
      /*  ll _sieve_size;bitset<15000100> bs;vl primes;
        void sieve(ll upperbound) {_sieve_size = upperbound + 1;bs.set();bs[0] = bs[1] = 0;
            for (ll i = 2; i<= _sieve_size; i++) if (bs[i]) {for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;primes.pb(i);} }
        */


        ll n,m,x,y,t,k,z,w,l,r,ans,res,c,a,b;
        string ch,sh;
       // map<pair<string,string,ll> > vis;
        map<ll,ll> maa;
        map<ll,pair<ll,ll> > lvl;
        map<ll,vector<pair<ll,ll> > > v;
        map<ll,vl> problem_maset;
        ll parent[50];
        map<ll,ll> yezzy_mel_bleda;
        pair<ll,ll> kiddo[50];

        ll howmany(ll src,ll lvvl,ll cond=-1){
            ll easy=0;
            //cout << src << endl;
            if(kiddo[src].f!=-1){
                easy+=1+howmany(kiddo[src].f,lvvl+1,0ll);
            }
            yezzy_mel_bleda[src]=easy;
            if(kiddo[src].s!=-1){
                easy+=1+howmany(kiddo[src].s,lvvl+1,1ll);
            }
            if(cond==0)lvl[src]=mp(lvvl,0ll);
            else if(cond==1)lvl[src]=mp(lvvl,1ll);

            return easy;


        }

        void lool(ll src,ll louwel){
        	if(maa[louwel]<maa[src] && kiddo[src].f==-1){
        		kiddo[src].f=louwel;
        		parent[louwel]=src;
        		return;
        	}

        	if(maa[louwel]>maa[src] && kiddo[src].s==-1){
        		kiddo[src].s=louwel;
        		parent[louwel]=src;
        		return;
        	}
        	if(maa[louwel]<maa[src] ){
        		lool(kiddo[src].f,louwel);
        		return ;
        	}

        	if(maa[louwel]>maa[src] ){
        		lool(kiddo[src].s,louwel);
        		return ;
        	}

        }

      /*  void print_tree(ll src, ll troll=-1){
            if(troll==-1){
                for(int i=0;i<yezzy_mel_bleda[src];i++){
                    cout << " ";
                }
                cout << char(src+97);
                print(tree)
                return;
            }
        }
 */

        int main(){
            ios::sync_with_stdio(0);
            //cin.tie(NULL);

            while(cin>> ch){
            	//cout << ch << endl;
            	cin >> sh;
            	//vis[mp(ch,sh)]=1;

                //cout << sh << endl;
                n=ch.size();
                maa.clear();
                lvl.clear();
                v.clear();
                problem_maset.clear();
                yezzy_mel_bleda.clear();
                for(int i=0;i<n;i++){
                    maa[ch[i]-'a']=i;


                }
                for(int i=0;i<='z'-'a';i++){
                	kiddo[i]=mp(-1,-1);
                	parent[i]=-1;
                }
                //cout << "hamma"<< endl;
                ll raslekbir=sh[0]-'a';
                parent[raslekbir]=-1;
                ll ras= raslekbir;

                for(int i=1;i<n;i++)
                {
                	//cout <<"hamma"<< endl;
                	//cout << parent[1]<< endl;
                    a=sh[i]-'a';
                    lool(raslekbir,a);


                }//cout <<"hamma"<< endl;
                //cout << parent[1]<< endl;
                b=howmany(raslekbir,0);
                //cout <<"hamma"<< endl;
                //print_tree(raslekbir);
                //cout << yezzy_mel_bleda[1];
                for(auto t:lvl){
                    v[t.s.f].pb(mp(t.f,t.s.s));
                }
                for(int j=0;j<yezzy_mel_bleda[raslekbir];j++){
                    cout << " ";
                }
                //cout << parent[6]<< endl;
                cout << char(raslekbir+97);
                ll j=1;
                vector<pair<ll,ll> > pos;
                map<ll,ll> lkol;
                lkol[raslekbir]=yezzy_mel_bleda[raslekbir]+1;
                //cout << parent[2]<< endl;
                //cout << lvl[2].f;
                //cout << yezzy_mel_bleda[raslekbir] << endl;
                //cout << lkol[raslekbir]<< endl;
                //cout << raslekbir << endl;
                //cout << parent[2]<< endl;
                while(v[j].size()>0){
                        cout << endl;
                    pos.clear();

                    for(auto t: v[j]){
                    //	cout << j << " " << t.f << " " << t.s<<" "<<yezzy_mel_bleda[t.f] << endl;
                        if(t.s==0){
                            pos.pb(mp(lkol[parent[t.f]]-yezzy_mel_bleda[parent[t.f]]+yezzy_mel_bleda[t.f],t.f));
                            lkol[t.f]=lkol[parent[t.f]]-yezzy_mel_bleda[parent[t.f]]+yezzy_mel_bleda[t.f];
                            //cout << lkol[parent[t.f]]<< endl;
                        }else{
                             pos.pb(mp(lkol[parent[t.f]]+yezzy_mel_bleda[t.f]+1,t.f));
                             lkol[t.f]=lkol[parent[t.f]]+yezzy_mel_bleda[t.f]+1;
                             //cout << lkol[parent[t.f]]+yezzy_mel_bleda[t.f]+1<<endl;
                             //cout << t.f << " "<<parent[t.f] << endl;
                        }
                    }
                    sort(pos.begin(),pos.end());
                    ll u=0;
                    for(int i=0;i<pos.size();i++){
                    	//cout << pos[i].f << endl;
                        for(int j=u+1;j<pos[i].f;j++){
                            cout << " ";
                        }
                        cout << char(pos[i].s+97);
                        u=pos[i].f;
                    }

                    j++;
                   /* cin >> ch;
                cin >> sh;
                if(vis[mp(ch,sh)])break;*/
                }
            }



            return 0;
        }
