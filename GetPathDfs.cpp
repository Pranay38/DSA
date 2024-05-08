#include<bits/stdc++.h>
using namespace std;
vector<int>getpath(int**edges,int a,int b,int n,bool*visited){
    visited[a]=true;
    if(a==b){
    vector <int> temp;
    temp.push_back(a);
    return temp;
  }

    vector<int>ans;
    for(int i=0;i<n;i++){
        if(i==a)
        continue;
        if(edges[a][i]==1&&!visited[i]){
            ans=getpath(edges,i,b,n,visited);
        }
        if(!ans.empty()){
            ans.push_back(a);
            return ans;
            
        }
    }
    return ans;

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
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    int a,b;
    cin>>a>>b;

    bool *visited= new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    vector<int>path;
    path=getpath(edges,a,b,n,visited);

    for(int i=0;i<path.size();i++){
        cout<<path[i]<<endl;
    }

}