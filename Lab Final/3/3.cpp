#include<bits/stdc++.h>
using namespace std;

int wt=11,w1,n=0;
float p=0;
float dp[20][20];
vector<float>nwp[5];
void show();

void input(int w[],int v[]){
    for(int i=0;i<5;i++){
        nwp[0].push_back(i+1);
        nwp[1].push_back(w[i]);
        nwp[2].push_back(v[i]);
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
}

void fractional_knapsack(){
    w1=wt;
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
    cout<<"\n\tFractional Knapsack: "<<p<<endl;
}

void zero_one_knapsack(int w[], int v[]){

    for(int i=0;i<=wt;i++){
        for(int j=0;j<=5;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if(i-w[j-1]<0){
                dp[i][j]=dp[i][j-1];
            }
            else{
                dp[i][j]=max(dp[i][j-1],(dp[i-w[j-1]][j] + v[j-1]));

            }
        }
    }

    cout<<"\n\t0/1 Knapsack: "<<dp[wt][5]<<endl;

}

void show(){
    cout<<"\tItem  Weight  Profit    || P/W"<<endl;
    cout<<"    ------------------------------------"<<endl;
    for(int i=0;i<nwp[0].size();i++){
        cout<<"\t"<<nwp[0][i]<<"\t"<<nwp[1][i]<<"\t"<<nwp[2][i]<<"\t|| "<<nwp[3][i]<<endl;
    }

}


int main(){
    int w[6]={1,2,5,6,7};
    int v[6]={1,6,18,22,28};

    input(w,v);
    fractional_knapsack();
    zero_one_knapsack(w,v);




    return 0;
}
