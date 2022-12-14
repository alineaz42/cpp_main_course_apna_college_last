// #include"bits/stdc++.h"
#include<iostream>
#include<vector>
using namespace std;

void formNumverDivByThree(vector<int> arr,int k){
    pair<int,int> ans;
    int sum = 0;
    for(int i=0;i<k;i++){
        sum = sum+arr[i];
    }
    bool found = false;
    if(sum%3==0){
        found=true;
        ans = make_pair(0,k-1);
    }
    for(int i = k;i<arr.size();i++){
        if(found){
            break;
        }
        sum += arr[i]-arr[i-k];
        if(sum%3==0){
            ans=make_pair(i-k+1,i);
            found = true;
        }
    }
    if(!found){
        ans = make_pair(-1,0);
    }
    if(ans.first==-1){
        cout<<"No such subarray exists"<<endl;
    }else{
        for(int i = ans.first;i<=ans.second;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
}
int main()
{
    vector<int> arr = {84,23,45,12,56,82};
    formNumverDivByThree(arr,3);
    return 0;
}