#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

queue<int>qq;
int gp[105][05]={0};
int vis[105]={0};

void bfs(int x,int v){
    for(int i=1;i<=v;i++){
        if(gp[x][i]==1 && vis[i]!=1){
            qq.push(i);
        }
    }

    while(!qq.empty()){
        x=qq.front();
        qq.pop();
        if(vis[x]!=1){
            cout<<x<<"\t";
            vis[x]=1;
        }
        bfs(x,v);
    }
}

int main(){
    int v,i,j,k;

    cout<<"Enter the Number of vertexes: ";
    cin>>v;

    cout<<"\nEnter graph data in matrix form:"<<endl;
    for(i=1;i<=v;i++){
        for(j=1;j<=v;j++){
            cin>>gp[i][j];
        }
    }

    cout<<"Enter the starting vertex: ";
    cin>>k;
    vis[k]=1;
    cout<<"\nThe node which are reachable are: ";
    bfs(k,v);
    cout<<endl;


    return 0;
}
