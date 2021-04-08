#include<bits/stdc++.h>
using namespace std;

int w,w1,n=0;
float x,p=0;
vector<float>nwp[5];
void show();

void input(){
    ifstream f1;
    f1.open("input1.txt");

    f1>>w;

    while(!f1.eof()){
        f1>>x;
        nwp[0].push_back(x);
        f1>>x;
        nwp[1].push_back(x);
        f1>>x;
        nwp[2].push_back(x);
    }
    for(int i=0;i<nwp[0].size();i++){
        nwp[3].push_back(nwp[2][i]/nwp[1][i]);
    }
    show();
    for(int i=0;i<nwp[0].size();i++){
        for(int j=i+1;j<nwp[0].size();j++){
            if(nwp[3][i]<nwp[3][j]){
                swap(nwp[0][i],nwp[0][j]);
                swap(nwp[1][i],nwp[1][j]);
                swap(nwp[2][i],nwp[2][j]);
                swap(nwp[3][i],nwp[3][j]);
            }
        }
    }
    w1=w;
}

void Knapsack(){
    while(w1>0){
        if(w1>=nwp[1][n]){
            p+=nwp[2][n];
            w1-=nwp[1][n];
        }
        else{
            p+=(nwp[2][n]*w1)/nwp[1][n];
            w1=0;
        }
        n+=1;
    }
    cout<<"\n\tMaximum Profit: "<<p<<endl;
}
void show(){
    cout<<"\tItem  Weight  Profit    || P/W"<<endl;
    cout<<"    ------------------------------------"<<endl;
    for(int i=0;i<nwp[0].size();i++){
        cout<<"\t"<<nwp[0][i]<<"\t"<<nwp[1][i]<<"\t"<<nwp[2][i]<<"\t|| "<<nwp[3][i]<<endl;
    }

}

int main(){

    input();
    Knapsack();


    return 0;
}
