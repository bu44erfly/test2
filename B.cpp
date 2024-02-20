#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <cstring>
using namespace std ;
const int  N=5001;
#define int long long
const int mod =998244353;

 vector<int> G[N] ; void add(int x,int y){G[x].push_back(y);}
 map<int,bool> vis;
 stack<int> s;
 int n ,flg ;
 void dfs(int x,int fa){
    
    if(vis[x]==2 ||flg) return ;
    if(vis[x] ==1){
        flg =1 ;
        while(s.size()) cout <<s.top() <<' ',s.pop() ;
        return ;
    }
   
    s.push(x); 
    vis[x] = 1;
    for(int y: G[x]) if(y!=fa)
        dfs(y,x) ;
    
    vis[x] =2 ; s.pop() ;
 }
 signed main(){
   int m ; cin>>n>>m ;
    for(int i=1;i<=m;i++){
        int x,y ;cin>>x>>y ;add(x,y),add(y,x) ;
    }
    dfs(1,0) ;
 }
