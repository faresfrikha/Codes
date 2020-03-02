#include <bits/stdc++.h>
     
        using namespace std;
        typedef long long ll;
        typedef vector<ll> vl ;
     
        #define mp make_pair
        #define pb push_back
        #define f first
        #define s second
        #define all(v) (v).begin(),(v).end()
     
     
        const int MOD = 1000000007;
        const int N = 1000005;
        const double PI =4*atan(1);
        const double eps = 1e-7;
        
        
        ll n,k,t;
        ll a[N];
        ll cnt=0;
 
        struct TrieNode {
            struct TrieNode *children[2];
            bool isEndOfWord;
            ll nb;
        };
 
        struct TrieNode *getNode(void){
            struct TrieNode *pNode = new TrieNode;
 
            pNode->isEndOfWord = false;
            pNode->nb=0;
            for(int i= 0;i<2;i++){
                pNode->children[i]= NULL;
            }
            return pNode;
        }
 
        void insert(struct TrieNode *root, string key){
            struct TrieNode *pCrawl = root;
 
            for(int i=0;i<key.size();i++){
                int index = key[i]-'0';
                if(!pCrawl->children[index]){
                    pCrawl->children[index]=getNode();
                }
                pCrawl = pCrawl->children[index];
                pCrawl->nb++;
            }
            pCrawl->isEndOfWord = true;
        }
 
        void remove(struct TrieNode *root, string key){
            struct TrieNode *pCrawl = root;
 
            for(int i=0;i<key.size();i++){
                int index = key[i]-'0';
                if(!pCrawl->children[index]){
                    pCrawl->children[index]=getNode();
                }
                pCrawl = pCrawl->children[index];
            }
            pCrawl->nb--;
        }
 
        bool search(struct TrieNode *root , string key){
            struct TrieNode *pCrawl = root;
 
            for(int i=0;i<key.size();i++){
                int index = key[i]-'0';
                if(!pCrawl->children[index]){
                    return false;
                }
                pCrawl = pCrawl->children[index];
            }
            //if( pCrawl->nb >0)cout << "dsf "<<pCrawl-> nb << endl;
            cnt = pCrawl->nb;
            //cout << "cnt "  << cnt << endl;
            return ( pCrawl!=NULL && pCrawl->nb>0);
        }
 
 
        int main(){
            ios::sync_with_stdio(0);
            //freopen("easy.txt","r",stdin);
            cin >> t ;
            while(t--){
                struct TrieNode*  root = getNode();
                cin >> n >> k;
                ll res=0;
                ll ans=(n*(n+1))/2;
                for(int i=0;i<n;i++){
                    cin >> a[i];
                }
                string st="";
                for(int i=0;i<=20;i++){
                    st+="0";
                }
                insert(root, st);
                for(int i=0;i<n;i++){
                	res=res^a[i];
                	a[i]=res;
                	//cout << i << " " <<a[i] <<endl; 
                    st="";
                    string stt="";
                    for(int j=20;j>=0;j--){
                    	if(res&(1<<j)){
                    		stt+="1";
                    	}else stt+="0";
                        if((1<<j) & k){
                        	if(j==0){
	                        	if(a[i]&(1<<j)){
	                                st+="0";
	                            }else st+="1";
	                            cnt=0;
	                            bool cond=search(root, st);
	                            ans-=cnt;
	                            continue;
                        	}
                            if(a[i]&(1<<j)){
                                st+="0";
                            }else st+="1";
                            continue;
                        }
                        cnt=0;
                        if(a[i]&(1<<j)){
                        	//cout << j << endl;
                            bool cond=search(root, st+"0") ; 
                            //cout << cnt << endl;
                        }else {
                            bool cond=search(root, st+'1');
                        }
                        ans-=cnt;
                        if(a[i]&(1<<j)){
                            st+='1';
                        }else{
                            st+='0';
                        }
                        if(j==0){
                        	cnt=0;
                        	bool cond=search(root, st) ; 
                        	ans-=cnt;
                        }
                        //cout << j << " "  <<st << endl;
 
                    }
                    insert(root, stt);
                }
                cout << ans<< endl;
            }
 
 
            return 0;
        } 