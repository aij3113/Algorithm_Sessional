#include<bits/stdc++.h>
using namespace std;

ifstream f1;

void InOr(int &n, vector<int>&item, vector<float>&weight, vector<float>&profit, vector<float>&pbw){
    float x;
    for(int i=0;i<n;i++){
        f1>>x;
        item.push_back(x);
        f1>>x;
        weight.push_back(x);
        f1>>x;
        profit.push_back(x);
        pbw.push_back((profit[i]/weight[i]));
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(pbw[i]<pbw[j]){
                swap(pbw[i],pbw[j]);
                swap(item[i],item[j]);
            }
        }
    }
}

void show(int &n, int &m, vector<int>&item, vector<float>&weight, vector<float>&profit, vector<float>&pbw){
    cout<<"\n  Knapsack: "<<m<<"\n  Item   Weight   Profit\n --------------------------"<<endl;
    for(int i=0;i<n;i++){
        cout<<"   "<<i+1<<"\t  "<<weight[i]<<"\t  "<<profit[i]<<endl;
    }
}

void Knapsack(int &n, int &m, vector<int>&item, vector<float>&weight, vector<float>&profit){
    float x[n+3],w=0,p=0,u;
    int i;

    for(i=0;i<=n;i++){
        x[i]=0.0;
    }

    u=float(m);

    for(i=0;i<n;i++){
        if(weight[item[i]-1]>u){
            break;
        }
        x[item[i]-1]=1.0; u=u-weight[item[i]-1];
    }
    if(i<=n-1){
        x[item[i]-1]= u/weight[item[i]-1];
    }

    cout<<"\n  Fractional Amount: ";
    for(i=0;i<n;i++){
        cout<<x[i]<<" ";
        w+=weight[i]*x[i];
        p+=x[i]*profit[i];
    }
    cout<<"\n  Total Weight: "<<w<<endl;;
    cout<<"  Total Profit: "<<p<<endl;
}

int main(){
    int i,j,k,t,n,m;

    f1.open("greedy.txt");
    f1>>t;

    for(i=1;i<=t;i++){
        vector<float>weight,profit,pbw;
        vector<int>item;

        f1>>m;
        f1>>n;

        InOr(n,item,weight,profit,pbw);
        show(n,m,item,weight,profit,pbw);

        cout<<"\n  Solution: "<<i<<endl;

        Knapsack(n,m,item,weight,profit);

    }


    return 0;
}
