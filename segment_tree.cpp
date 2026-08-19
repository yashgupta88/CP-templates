#include <bits/stdc++.h>

using namespace std;

class SGTree{

    vector<int> seg;

public :

SGTree(int n){
    seg.resize(4*n+1);
}


void build(int i,int low, int high , vector<int> &a){
    if(low == high){
        seg[i]=a[low];
        return ;
    }

    int mid=(low+high) / 2;

    build(2*i+1,low,mid,a);

    build(2*i+2,mid+1,high,a);

    seg[i] = min(seg[2*i+1],seg[2*i+2]);
}

int query(int i,int low,int high,int l,int r){

    if(r<low || l>high){
        return INT_MAX;
    }

    if(low>=l && high<=r){
        return seg[i];
    }

    int mid=(low+high)/2;

    return min(query(2*i+1,low,mid,l,r) , query(2*i+2,mid+1,high,l,r));
}

void update(int i, int low,int high ,int ind, int val){
    if(low==high ) {
        seg[i]=val;
        return ;
    }

    int mid=(low+high) / 2;

    if(ind <= mid) update(2*i+1, low, mid,ind ,val);
    else update(2*i+2, mid+1,high,ind ,val);

    seg[i]=min(seg[2*i+1] , seg[2*i+2]);
}

};
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

   SGTree sg1(n);
   sg1.build(0,0,n-1,a);

  
    int q;
    cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<sg1.query(0,0,n-1,x,y);
    }
}

int main(){
    solve();
}