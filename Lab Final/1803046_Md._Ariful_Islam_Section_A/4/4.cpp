#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

typedef long long ll;
#define M 10001

void menu(){
    cout<<"\nEnter N (Press 0 to Exit): ";
}

int main(){
    ll n,i,j;
    vector<ll>cn,cb,cc;

    while(1){
        ll a;
        menu();
        cin>>a;

        if(a<0) {
            cout<<"Invalid Input"<<endl;
            continue;
        }

        if(a==0){
            cout<<"\nExiting..."<<endl;
            break;
        }

        ll mx,mn,x;

        vector<ll>bsort_array,pos_csort,csort_array;
        map<ll,ll>mp;

        //Creating File

        ofstream f1;
        ifstream f2;
        f1.open("input.txt");

        n=a;
        cn.push_back(n);

        srand(time(0));
        x=rand()%M;
        mx=x;
        mn=x;
        f1<<x;
        csort_array.push_back(-1);

        for(i=1;i<n;i++){
            x=rand()%M;
            f1<<" ";
            f1<<x;
            mx=max(mx,x);
            mn=min(mn,x);
            csort_array.push_back(-1);
        }
        f1.close();

        //Counting time for bubble sort
        auto start = high_resolution_clock::now();

        f2.open("input.txt");

        while(!f2.eof()){
            f2>>x;
            bsort_array.push_back(x);
        }
        f2.close();

        // Bubble sort
        for(i=0;i<n-1;i++){
            for(j=i+1;j<n;j++){
                if(bsort_array[i]>bsort_array[j]){
                    swap(bsort_array[i],bsort_array[j]);
                }
            }
        }

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<milliseconds>(stop - start);
        cout<<"Bubble Sort: "<<duration.count()<<" Milliseconds"<<endl;
        cb.push_back(duration.count());


        //Counting time for counting sort
        start = high_resolution_clock::now();

        f2.open("input.txt");
        //Counting sort
        while(!f2.eof()){
            f2>>x;
            mp[x]+=1;
        }
        f2.close();

        for(i=mn;i<=mx;i++){
            if(i==mn){
                pos_csort.push_back(mp[i]);
                continue;
            }
            pos_csort.push_back(mp[i]+pos_csort[i-mn-1]);
        }

        f2.open("input.txt");
        while(!f2.eof()){
            f2>>x;
            csort_array[pos_csort[x-mn]-1]=x;
            pos_csort[x-mn]-=1;
        }

        stop = high_resolution_clock::now();

        duration = duration_cast<milliseconds>(stop - start);
        cout<<"Counting Sort: "<<duration.count()<<" Milliseconds"<<endl;
        cc.push_back(duration.count());

        f2.close();
    }

    for(i=0;i<cn.size()-1;i++){
        for(j=i+1;j<cn.size();j++){
            if(cn[i]>cn[j]){
                swap(cn[i],cn[j]);
                swap(cb[i],cb[j]);
                swap(cc[i],cc[j]);
            }
        }
    }

    cout<<"\nN\tB_S\tC_S"<<endl;
    for(i=0;i<cn.size();i++){
        cout<<cn[i]<<"\t"<<cb[i]<<"\t"<<cc[i]<<endl;
    }


    return 0;
}
