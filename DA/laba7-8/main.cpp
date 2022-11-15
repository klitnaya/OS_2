/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Настя
 *
 * Created on 24 октября 2022 г., 16:31
 */

//#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

/*int min(int a,int b)
{
    if (a<b)
        return a;
    else
        return b;
}*/
int main() {
    int n;
    cin >> n;
    int *S = new int [n]; 
    int **a = new int *[n + 1];
    S[0] = 0; S[1] = 0;
    
    //нулевой случай
    if (n == 0 || n == 1){
        cout << 0;
        return 0;
    }
    
    for (int i = 2; i <= n; i++ ){
        int tmp = 1;
        if ((i >= 3) && (i%2 == 0 && i%3 == 0)){
            S[i] = min(i + S[i/2], i + S[i/3]);
            continue;
        }
        
        if (i >= 3 && i%3 == 0){
            if (S[i/3] + i <  i + S[i-1]){
                S[i] = S[i/3] + i;
            }
            else{
               S[i] = S[i-1] + 1;
            }
            continue;
        }
        
        if (i >= 2 && i%2 == 0){
            if (i + S[i/2] < i + S[i-1]){
               S[i] = S[i/2] + i;
            }
            else {
                S[i] = S[i-1] + i;
            }
            continue;
        }
        if (i > 1){
            S[i] = S[i - 1] + i;
        }
    }
    cout << S[n] << endl;
    int ans = n;
    while(ans > 1){
        if ((ans%3 == 0) && (ans%2 == 0)){
            if(S[ans/3] <= S[ans/2]){
                cout<<"/3"<<" ";
                ans = ans/3;
            }
            else {
                cout<<"/2"<<" ";
                ans = ans/2;
            }
            continue;
        }
        if (ans%2 == 0){
            if (S[ans/2] <= S[ans - 1]){
                cout<<"/2"<<" ";
                ans = ans/2;
            }
            else{
                cout<<"-1"<<" ";
                ans = ans - 1;
            }
            continue;
        }
        if (ans%3 == 0){
            if (S[ans/3] <= S[ans - 1]){
                cout<<"/3"<<" ";
                ans = ans/3;
            }
            else{
                cout<<"-1,"<<" ";
                ans = ans -1;
            }
            continue;
        }
        if (ans > 1){
            cout<<"-1"<<" ";
            ans = ans - 1;
            continue;
        }
    }
    return 0;

}
