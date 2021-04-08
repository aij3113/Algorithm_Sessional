#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,md=0,i=1,j,x,pft=0;
vector<ll>df[4],pdd;

void show(){
    cout<<"\tDLine  Profit\n    ------------------------"<<endl;
    for(i=0;i<n;i++){
        cout<<"\t"<<df[2][i]<<"\t"<<df[1][i]<<endl;
    }
}
void input(){
    ifstream f1;
    f1.open("input2.txt");

    f1>>n;
    while(!f1.eof()){
        f1>>x;
        if(md<x){
            md=x;
        }
        df[0].push_back(i);i+=1;
        df[1].push_back(x);
        f1>>x;
        df[2].push_back(x);
    }
    for(i=0;i<md+2;i++){
        df[3].push_back(0);
    }
    show();
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(df[1][i]<df[1][j]){
                swap(df[0][i],df[0][j]);
                swap(df[1][i],df[1][j]);
                swap(df[2][i],df[2][j]);
            }
        }
    }

}

void jobS(){
    for(i=0;i<n;i++){
        if(df[3][df[2][i]]==0){
            pdd.push_back(df[0][i]);
            df[3][df[2][i]]=1;
            pft+=df[1][i];
        }
        for(j=df[3][df[2][i]]-1;j>0;j--){
            if(df[3][j]==0){
                pdd.push_back(df[0][i]);
                df[3][j]=1;
                pft+=df[1][i];
            }
        }
    }
    cout<<"\tMax Profit: "<<pft<<"\n\tSequence:";
    for(i=0;i<pdd.size();i++){
        cout<<" "<<pdd[i];
    }
}

int main(){

    input();
    jobS();


    return 0;
}
