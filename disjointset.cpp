#include<bits/stdc++.h>
using namespace std;
class Disjoint{
public:
    vector<int>rank,parent,size;
    Disjoint(int n){
    rank.resize(n+1,0);
    parent.resize(n+1);
    size.resize(n+1);
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }

    }
    int findupair(int node){
        if(node==parent[node])
        return node;
        return parent[node]=findupair(parent[node]);
    }
    void unionbyrank(int x,int y){
        int parx=findupair(x);
        int pary=findupair(y);
        if(parx==pary)
        return;
        if(rank[parx]<rank[pary])
        parent[parx]=pary;
        else if(rank[parx]>rank[pary])
        parent[pary]=parx;
        else{
            parent[parx]=pary;
            rank[pary]++;
        }

    }
    void unionbysize(int x,int y){
        int parx=findupair(x);
        int pary=findupair(y);
        if(parx==pary)
        return;
        else if(size[parx]<size[pary]){
            parent[parx]=pary;
            size[parx]+=size[pary];
        }
        else if(size[pary]<size[parx]){
            parent[pary]=parx;
            size[pary]+=size[parx];
        }
    }


};
int main(){
 Disjoint ds(7);
    ds.unionbysize(1, 2); 
    ds.unionbysize(2, 3); 
    ds.unionbysize(4, 5); 
    ds.unionbysize(6, 7); 
    ds.unionbysize(5, 6); 
    // if 3 and 7 same or not 
    if(ds.findupair(3) == ds.findupair(7)) {
        cout << "Same\n"; 
    }
    else cout << "Not same\n"; 

    ds.unionbysize(3, 7); 

    if(ds.findupair(3) == ds.findupair(7)) {
        cout << "Same\n"; 
    }
    else cout << "Not same\n"; 
	return 0;
}