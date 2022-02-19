#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

typedef long long ll;
typedef pair<int,pair<int,int>> pp;

priority_queue<pp, vector<pp>, greater<pp> >pq;
map<pair<int,int>,int>mp;

vector<int>tree[1005];
int adjmat[1005][1005];
int parent[1005],rnk[1005];
int cost;
int root;

void initialize()
{
    cost=0;
    for(int i=0; i<1002; i++)
    {
        tree[i].clear();
        parent[i]=i;
        rnk[i]=0;
    }
}

int find_parent_without(int x){
    if(parent[x]=x){
        return x;
    }
    else{
        return find_parent_without(parent[x]);
    }
}

int find_parent_with(int x){
    if(parent[x]=x){
        return x;
    }
    else{
        return parent[x]=find_parent_with(parent[x]);
    }
}

void kruskal_without_rank_compressed_djset(){
    priority_queue<pp, vector<pp>, greater<pp>> pq1 = pq;

    for(int i=0; i<pq1.size();i++){
        pp p1=pq1.top();
        pq1.pop();
        pair<int,int>p2;
        p2=p1.second;

        int x=find_parent_without(p2.first);
        int y=find_parent_without(p2.second);

        if(x!=y){
            parent[x]=y;
            cost+=p1.first;
            tree[p2.first].push_back(p2.second);
            tree[p2.second].push_back(p2.first);
        }
    }
}

void kruskal_with_rank_compressed_djset(){
    priority_queue<pp, vector<pp>, greater<pp>> pq1 = pq;

    for(int i=0; i<pq1.size();i++){
        pp p1=pq1.top();
        pq1.pop();
        pair<int,int>p2;
        p2=p1.second;

        int x=find_parent_with(p2.first);
        int y=find_parent_with(p2.second);

        if(x!=y){
            if(rnk[x]>rnk[y]){
                swap(x,y);
            }
            parent[x]=y;
            if(rnk[x]==rnk[y]){
                rnk[y]+=1;
            }
            cost+=p1.first;
            tree[p2.first].push_back(p2.second);
            tree[p2.second].push_back(p2.first);
        }
    }
}

int main(){

    memset(adjmat,0,sizeof(adjmat));

    int n,e,a,b,c;

    cout<<"Enter N & E: ";
    cin>>n>>e;
    if(n==0&& e==0)
    {
        return 0;
    }

//    srand(time(0));
    for(int i=0; i<e; i++)
    {
        a=(rand()%n)+1;
        b=(rand()%n)+1;
        if(mp[ {a,b}]!=0 || mp[ {b,a}]!=0 || a==b)
        {
            i-=1;
            continue;
        }
        mp[ {a,b}]=1;
        mp[ {b,a}]=1;
        c=(rand()%7)+3;
        cout<<"Enter E to E & C: ";
        cout<<a<<" "<<b<<" "<<c<<endl;
        pq.push({c,{a,b}});
        adjmat[a][b]=c;
        adjmat[b][a]=c;
    }

    initialize();
    auto start = high_resolution_clock::now();
    kruskal_with_rank_compressed_djset();
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    cout<<"kruskal_with_rank_compressed_djset: "<<duration.count()<<" Microseconds"<<endl;
    cout<<cost<<endl;

    initialize();
    start = high_resolution_clock::now();
    kruskal_without_rank_compressed_djset();
    stop = high_resolution_clock::now();

    duration = duration_cast<microseconds>(stop - start);
    cout<<"kruskal_without_rank_compressed_djset: "<<duration.count()<<" Microseconds"<<endl;
    cout<<cost<<endl;



    return 0;
}
