#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
typedef long long ll;
#define Max 1e17

vector<ll>arr1;
ll arr2[100000],n;

void input(ll n,ll i){
    string a,b="marge";
    b=b+to_string(i)+".txt";
    ifstream f1;

    f1.open(b);
    arr1.clear();

    while(arr1.size()<n){
        f1>>a;
        arr1.push_back(stod(a));
    }
    f1.close();
}

void output(ll n){
    for(ll i=0;i<n;i++){
        cout<<arr1[i]<<" ";
    }
    cout<<"\n"<<endl;
}

void marge(ll low,ll mid,ll high){
    ll h=low, i=low, j=mid+1;

    while((h<=mid)&&(j<=high)){
        if(arr1[h]<=arr1[j]){
            arr2[i]=arr1[h];
            h+=1;
        }
        else{
            arr2[i]=arr1[j];
            j+=1;
        }
        i+=1;
    }
    if(h>mid){
        for(ll k=j;k<=high;k++){
            arr2[i]=arr1[k];
            i+=1;
        }
    }
    else{
        for(ll k=h;k<=mid;k++){
            arr2[i]=arr1[k];
            i+=1;
        }
    }

    for(ll i=low;i<=high;i++){
        arr1[i]=arr2[i];
    }
}

void marge_sort(ll low,ll high){
    if(low<high){
        ll mid=(low+high)/2;

        marge_sort(low,mid);
        marge_sort(mid+1,high);

        marge(low,mid,high);
    }
}

int main(){
    int i;

    for(i=1;i<4;i++){
        cout<<"Enter Number of Element_(from 5000 to 50000): ";
        cin>>n;

        input(n,i);

        auto start = high_resolution_clock::now();
        marge_sort(0,n-1);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<milliseconds>(stop - start);
        cout<<"\nTime of "<<n<<" : "<<duration.count()<<" milliseconds\n"<<endl;
    }

    return 0;
}
