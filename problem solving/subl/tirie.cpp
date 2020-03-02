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

const int B=32;
const char ref='a';

struct node{
    struct node * child[B];
    bool cond;
    int num_ch;
    int num_ex;
};

struct node* getnode(){
    struct node* nnode = new node;
    nnode->cond=false;
    nnode->num_ch=0;
    nnode->num_ex=0;
    for(int i=0;i<B;i++){
        nnode->child[i]=NULL;
    }
    return nnode;
}

void insert(struct node* root , string key){
    struct *node pcrawl =  root;
    for(int i=0;i<key.size();i++){
        int index=ch[i]-ref;
        if(pcrawl->child[index]==NULL){
            pcrawl->child[index]=getnode();
        }
        pcrawl=pcrawl->child[index];
        pcrawl->num_ch++;
        if(i==0){
            pcrawl->cond=true;
            pcrawl->num_ex++;
        }
    }
}

int recherche(struct node* root , string key){
    struct *node pcrawl =  root;
    for(int i=0;i<key.size();i++){
        int index=ch[i]-ref;
        if(pcrawl->child[index]==NULL){
            return 0;
        }
        pcrawl=pcrawl->child[index];
    }
    return true;
}


void deletenode(struct node* root , string key, int pos, int si){
    if(root==NULL || pos>=si )return ;
    int ind = (key[pos]-ref);
    deletenode(root->child[ind],key,pos+1,si);
    root->num_ch--;
    if(root->num_ch==0){
        root->child[ind]=NULL;
    }
    
}


int main(){
    ios::sync_with_stdio(0);
    freopen("easy.txt","r",stdin);
        
    return 0;
}