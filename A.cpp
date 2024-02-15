#include <iostream>
#include <cstring> 
using namespace std;
 const int N =3e6+4;
 int tot,a[N],ch[N][26];
 int val[N],End[N];

 void insert(int len){
 	int u=0;
 	
 	for(int i=1;i<=len;i++){
 		int c=a[i];
 		
 		if(ch[u][c]==0) ch[u][c]=++tot;
 		u=ch[u][c];
 		val[u]++;
 	}
 	End[u]++;
 }
 void find(int len){
 	int u=0,flag=1;
	int ans=0;
 	
 	for(int i=1;i<=len;i++){
 		int c=a[i];
 		if(ch[u][c]==0){ flag=0; break;}
 		
 		u=ch[u][c];
 		ans+=End[u];
 	}
 	if(flag) ans=ans+val[u]-End[u];
 	cout<<ans<<endl;
 }
 signed main(){
 	int n,q,tes;
 	cin>>n>>q;
 	for(int i=1;i<=n;i++){
 		cin>>tes;
 		for(int j=1;j<=tes;j++) cin>>a[j];
 		insert(tes);
 	}
 	for(int i=1;i<=q;i++){
 		cin>>tes;
 		for(int j=1;j<=tes;j++) cin>>a[j];
 		find(tes);
 	}
 }
 
 

