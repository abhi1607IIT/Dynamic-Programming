/*
 Given a posisitive integer n find the min steps to reduce n to 1
 We can do the following
 1. 1 + f(n-1)
 2. 1+ f(n/2) if n%2==0
 3. 1+f(n/3) if n%3==0
 */




#include <iostream>
using namespace std;

int minsteps(int n){
    if(n==1){
        return 0;
    }
    int ans=1+minsteps(n-1);
    if(n%2==0){
        ans=min(ans,minsteps(n/2)+1);
    }
    if(n%3==0){
        ans=min(ans,minsteps(n/3)+1);
    }
    return ans;
}


int minsteps_rec_dp(int n,int*arr){
    if(n==1){
        return 0;
    }
    if(arr[n]>0){
        return arr[n];                      //top bottom approach
    }
    int ans=1+minsteps_rec_dp(n-1,arr);
    if(n%2==0){
        ans=min(ans,minsteps_rec_dp(n/2,arr)+1);
    }
    if(n%3==0){
        ans=min(ans,minsteps_rec_dp(n/3,arr)+1);
    }
    arr[n]=ans;
    return ans;
}

int minsteps_itr_dp(int n){
    int*arr=new int [n+1];
    arr[0]=0;
    arr[1]=0;
    for(int i=2;i<=n;i++){
        arr[i]=arr[i-1]+1;
        if(i%2==0){
            arr[i]=min(arr[i],arr[i/2]+1);
        }
        if(i%3==0){
            arr[i]=min(arr[i],arr[i/3]+1);
        }
    }
    return arr[n];
}

int main() {
    int n;
    cin>>n;
    cout<<minsteps(n)<<endl;
    int*arr=new int [n+1];
    for(int i=0;i<=n;i++){
        arr[i]=0;
    }
    cout<<minsteps_rec_dp(n,arr)<<endl;
    cout<<minsteps_itr_dp(n)<<endl;
}