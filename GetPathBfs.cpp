#include<bits/stdc++.h>
using namespace std;
void pathbfs(int **edges,int n,int a,int b,bool*visited,map<int,int>&mp){
queue<int>q;

for(int i=0;i<n;i++){
    visited[i]=false;
}
q.push(a);
visited[a]=true;
while(!q.empty()){
    int cv=q.front();
    q.pop();
    visited[cv]=true;
    if(cv==b)
    return;
    for(int i=0;i<n;i++){
        if(i==a)
        continue;
        if(edges[cv][i]==1&&!visited[i]){
            q.push(i);
            visited[i]=true;
            if(mp.count(i)==0)
            mp[i]=cv;        }
    }

}



}
int main(){
    int n,e;
    cin>>n>>e;
    int**edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
    int f,s;
    cin>>f>>s;
    
        edges[f][s]=1;
        edges[s][f]=1;
    }
    int a,b;
    cin>>a>>b;
    bool* visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    map<int,int>mp;
    pathbfs(edges,n,a,b,visited,mp);
    if(visited[b]){
        int t=b;
        while(t!=a){
            cout<<t<<" ";
            t=mp[t];
        }
        cout<<t<<" ";
    }
    cout<<endl;

}