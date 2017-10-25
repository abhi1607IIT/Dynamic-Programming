/*
 Given a value N, if we want to make change for N cents, and we have infinite supply of
 each of S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change?

 INPUT
 L1 : VALUE
 L2 : NO OF DENOMINATION
 L3 : ALL DENOMINATION VALUES

 EXAMPLE
 4
 2
 1 2
 */

#include <iostream>
using namespace std;

int waystochange(int value,int*arr,int k){
    if(value==0){
        return 1;
    }
    if(value<0){
        return 0;
    }
    if(k==0){
        return 0;
    }
    int ans1=waystochange(value-arr[0],arr,k);
    int ans2=waystochange(value,arr+1,k-1);

    return ans1+ans2;
}

int waystochange_rec_dp(int value,int *arr,int k,int **store){
    if(value==0){
        return 1;
    }
    if(value<0){
        return 0;
    }
    if(k==0){
        return 0;
    }
    if(store[value][k]>-1){
        return store[value][k];
    }

    int ans1=waystochange(value-arr[0],arr,k);
    int ans2=waystochange(value,arr+1,k-1);
    store[value][k]=ans1+ans2;
    return ans1+ans2;
}

int main(){
    int value,k;
    cin>>value>>k;
    int*arr=new int [k];
    for(int i=0;i<k;i++){
        cin>>arr[i];
    }
    int**store=new int* [value+1];
    for(int i=0;i<value+1;i++){
        store[i]=new int [k+1];
    }
    for(int i=0;i<value+1;i++){
        for(int j=0;j<k+1;j++){
            store[i][k]=-1;
        }
    }
    cout<<waystochange(value,arr,k)<<endl;
    cout<<waystochange_rec_dp(value,arr,k,store)<<endl;
}

