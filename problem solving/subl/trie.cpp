        struct TrieNode {
            struct TrieNode *children[26];
            bool isEndOfWord;
        };

        struct TrieNode *getNode(void){
            struct TrieNode *pNode = new TrieNode;

            pNode->isEndOfWord = false;
            for(int i= 0;i<26;i++){
                pNode->children[i]= NULL;
            }
            return pNode;
        }

        void insert(struct TrieNode *root, string key){
            struct TrieNode *pCrawl = root;

            for(int i=0;i<key.size();i++){
                int index = key[i]-'a';
                if(!pCrawl->children[index]){
                    pCrawl->children[index]=getNode();
                }
                pCrawl = pCrawl->children[index];
            }
            pCrawl->isEndOfWord = true;
        }

        bool search(struct TrieNode *root , string key){
            struct TrieNode *pCrawl = root;

            for(int i=0;i<key.size();i++){
                int index = key[i]-'a';
                if(!pCrawl->children[index]){
                    return false;
                }
                pCrawl = pCrawl->children[index];
            }
            return ( pCrawl!=NULL  && pCrawl->isEndOfWord );
        }

        bool isempty(TrieNode*  root){

            for(int i=0;i<26;i++){
                if(root->children[i])return false;
            }
            return true;
        }

        TrieNode*  remove(TrieNode* root, string key, int depth =0){

            if(!root)return NULL;

            if(depth ==  key.size()){
                if(root->isEndOfWord){
                    root->isEndOfWord=false;
                }
                if(isempty(root)){
                    delete(root);
                    root= NULL;
                }
                return root;
            }
            int index = key[depth]-'a';
            root->children[index]=remove(root->children[index], key, depth+1);

            if(isempty(root) && isEndOfWord==false){
                delete(root);
                root=NULL;
            }
            return root;
        }



        ///////////  x^y < z
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
        ll x,y;
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
        }

        void remove(struct TrieNode *root, string key){
            struct TrieNode *pCrawl = root;

            for(int i=0;i<key.size();i++){
                int index = key[i]-'0';
                if(!pCrawl->children[index]){
                    pCrawl->children[index]=getNode();
                }
                pCrawl = pCrawl->children[index];
                pCrawl->nb--;
            }
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
            return (pCrawl->nb>0);
        }


        int main(){
            ios::sync_with_stdio(0);
            //freopen("easy.txt","r",stdin);
            cin >> t ;
            struct TrieNode*  root = getNode();
            n=0;
            while(t--){
                cin >> x >>  y ;
                if(x==1){
                    string st="";
                    n++;
                    for(int i=30;i>=0;i--){
                        if((1ll<<i)&y){
                            st+="1";
                        }else st+="0";
                    }
                    insert(root, st);
                    continue;
                }
                if(x==2){
                    n--;
                    string st="";
                    for(int i=30;i>=0;i--){
                        if((1ll<<i)&y){
                            st+="1";
                        }else st+="0";
                    }
                    remove(root, st);
                    continue;
                }
                cin >> k;
                string st="";
                st="";
                ll ans=0;
                //cout << y << " " << k << endl;
                for(int j=30;j>=0;j--){
                    if((1ll<<j) & k){
                        if(j==0){
                            if(y&(1ll<<j)){
                                st+="0";
                            }else st+="1";
                            cnt=0;
                            bool cond=search(root, st);
                            ans+=cnt;
                            continue;
                        }
                        if(y&(1<<j)){
                            st+="0";
                        }else st+="1";
                        continue;
                    }
                    cnt=0;
                    if(y&(1ll<<j)){
                        //cout << j << endl;
                        bool cond=search(root, st+"0") ; 
                        //cout << cnt << endl;
                    }else {
                        bool cond=search(root, st+'1');
                    }
                    ans+=cnt;
                    if(y&(1<<j)){
                        st+='1';
                    }else{
                        st+='0';
                    }
                    if(j==0){
                        cnt=0;
                        bool cond=search(root, st) ; 
                        ans+=cnt;
                    }
                    //cout << j << " "  <<st << endl;

                }
             cout << n-ans<< endl;
            }


            return 0;
        }



        //////////////////
        const int AlPHA = 2, B = 30;
int res;
 
struct Node {
    Node *next[AlPHA];
    int freq;
    Node() {
        freq = 0;
        for (int i = 0; i < AlPHA; ++i)
            next[i] = NULL;
    }
} *Trie;
 
void insert(int p) {
    Node *cur = Trie;
    for (int i = B - 1; i >= 0; --i) {
        int bit = (p >> i) & 1; 
        if (cur->next[bit] == NULL)
            cur->next[bit] = new Node();
        cur = cur->next[bit];
        ++cur->freq;
    }
}
 
void remove(Node *cur, int at, int p) {
    if (cur == NULL || at == -1)
        return;
    int bit = (p >> at) & 1; 
    remove(cur->next[bit], at - 1, p);
    if (--cur->next[bit]->freq == 0)
        cur->next[bit] = NULL;
}
 
void DFS(Node *cur, int at, int p, int l) {
    if (cur == NULL || at == -1)
        return;
    int curL = (l >> at) & 1;
    int curP = (p >> at) & 1;
    if (curL == 0 && curP == 0) {
        DFS(cur->next[0], at - 1, p, l);
        return;
    }
    if (curL == 0 && curP == 1) {
        DFS(cur->next[1], at - 1, p, l);
        return;
    }
    if (curL == 1 && curP == 0) {
        if (cur->next[0] != NULL)
            res += cur->next[0]->freq;
        DFS(cur->next[1], at - 1, p, l);
        return;
    }
    if (cur->next[1] != NULL)
        res += cur->next[1]->freq;
    DFS(cur->next[0], at - 1, p, l);    
}