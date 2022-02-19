#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

typedef long long ll;

int adjmat[505][505];
vector<pair<int,int>>adjlist[505];
vector<int>usa;
map<pair<int,int>,int>mp;
int cost[505];
int parent[505];
int binhp[700];
int hps;

void initialize(){
    hps=0;
    for(int i=0;i<502;i++){
        cost[i]=INT_MAX;
        parent[i]=0;
    }
}

void binhp_add(int z){
        binhp[hps]=z;
        for(int i=hps;i>0;i=i/2){
            int par = (i-1)/2;
            if(cost[binhp[par]]>cost[binhp[i]]){
                swap(binhp[par],binhp[i]);
            }
        }
}

void binhp_pop(){
    int i=0;
    while(((i*2)+1)<=hps){
        if((i*2)+2<=hps){
            if(binhp[i]>binhp[(i*2)+2] && binhp[(i*2)+1]>binhp[(i*2)+2]){
                binhp[i]=binhp[(i*2)+2];
                i=(i*2)+2;
            }
            else if(binhp[i]>binhp[(i*2)+1] && binhp[(i*2)+2]>binhp[(i*2)+1]){
                binhp[i]=binhp[(i*2)+1];
                i=(i*2)+1;
            }
            else{
                break;
            }
        }
        else{
            if(binhp[i]>binhp[(i*2)+1])
                binhp[i]=binhp[(i*2)+1];
                i=(i*2)+1;
            }
    }
}

int binhp_adjmat(int x, int y){
    for(int i=1;i<=101;i++){
        if(adjmat[x][i]!=-1){
            if(cost[i]>(cost[x]+adjmat[x][i])){
                parent[i]=x;
                cost[i]=cost[x]+adjmat[x][i];
                binhp_add(i);
                hps+=1;
            }
        }
    }

    while(hps>0){
        x=binhp[0];
        binhp_pop();
        hps-=1;
        binhp_adjmat(x,y);
    }
}


int binhp_adjlist(int x, int y){
    for(int i=0;i<adjlist[x].size();i++){
        pair<int,int>pp;
        pp = adjlist[x][i];

        if(cost[pp.first]>(cost[x]+pp.second)){
                parent[pp.first]=x;
                cost[pp.first]=cost[x]+pp.second;
                binhp_add(pp.first);
                hps+=1;
        }
    }

    while(hps>0){
        x=binhp[0];
        binhp_pop();
        hps-=1;
        binhp_adjmat(x,y);
    }
}


int usa_adjmat(int x, int y){
    for(int i=1;i<=101;i++){
        if(adjmat[x][i]!=-1){
            if(cost[i]>(cost[x]+adjmat[x][i])){
                parent[i]=x;
                cost[i]=cost[x]+adjmat[x][i];
                usa.push_back(i);
                hps+=1;
            }
        }
    }

    while(usa.size()>0){
        x=cost[usa[0]];
        int z=0;
        for(int i=1;i<usa.size();i++){
            if(cost[usa[i]]<x){
                x=cost[usa[i]];
                z=i;
            }
        }
        x=usa[z];
        usa.erase(usa.begin()+z);

        hps-=1;
        usa_adjmat(x,y);
    }
}

int usa_adjlist(int x, int y){
    for(int i=0;i<adjlist[x].size();i++){
        pair<int,int>pp;
        pp = adjlist[x][i];

        if(cost[pp.first]>(cost[x]+pp.second)){
                parent[pp.first]=x;
                cost[pp.first]=cost[x]+pp.second;
                usa.push_back(pp.first);
                hps+=1;
        }
    }

    while(usa.size()>0){
        x=cost[usa[0]];
        int z=0;
        for(int i=1;i<usa.size();i++){
            if(cost[usa[i]]<x){
                x=cost[usa[i]];
                z=i;
            }
        }
        x=usa[z];
        usa.erase(usa.begin()+z);

        hps-=1;
        usa_adjlist(x,y);
    }
}




int main(){
    memset(adjmat,-1,sizeof(adjmat));

    int n,e,a,b,c;

    cout<<"Enter N & E: ";
    cin>>n>>e;


    for(int i=0;i<e;i++){
        //srand(time(0));
        a=(rand()%n)+1;
        //srand(time(0));
        b=(rand()%n)+1;
        if(mp[{a,b}]!=0 || mp[{b,a}]!=0 || a==b){
            i-=1;
            continue;
        }
        mp[{a,b}]=1;
        mp[{b,a}]=1;
        //srand(time(0));
        c=(rand()%7)+3;
        cout<<"Enter E to E & C: ";
        cout<<a<<" "<<b<<" "<<c<<endl;
        adjmat[a][b]=c;
        adjmat[b][a]=c;
        adjlist[a].push_back(make_pair(b,c));
        adjlist[b].push_back(make_pair(a,c));
    }

    while(1){
        cout<<"Enter Nodes(0 0 to exit): ";
        cin>>a>>b;
        if(a<1 || a>n || b<1 ||b>n){
            cout<<"Exiting..."<<endl;
            break;
        }


        initialize();
        cost[a]=0;
        auto start = high_resolution_clock::now();
        binhp_adjmat(a,n);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);
        cout<<"Binary Heap AdjMat: "<<duration.count()<<" Microseconds"<<endl;
        cout<<cost[b]<<endl;

        initialize();
        cost[a]=0;
        start = high_resolution_clock::now();
        binhp_adjlist(a,n);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        cout<<"Binary Heap AdjList: "<<duration.count()<<" Microseconds"<<endl;
        cout<<cost[b]<<endl;

        initialize();
        cost[a]=0;
        start = high_resolution_clock::now();
        usa_adjmat(a,n);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        cout<<"UnSorted Array AdjMat: "<<duration.count()<<" Microseconds"<<endl;
        cout<<cost[b]<<endl;

        initialize();
        cost[a]=0;
        start = high_resolution_clock::now();
        usa_adjlist(a,n);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        cout<<"UnSorted Array AdjList: "<<duration.count()<<" Microseconds"<<endl;
        cout<<cost[b]<<endl;
    }


    return 0;
}
