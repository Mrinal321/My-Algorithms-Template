#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int PI[N], i, j;

void kmp_PI(string pattern){
    PI[0] = 0;
    j = 0;
    for(i = 1; i < pattern.size(); i++){
        //cout << pattern[i];
        while(pattern[i] != pattern[j]){

            if(j > 0) j = PI[j-1];
            else break;
        }
        if(pattern[i] == pattern[j]){
            PI[i] = PI[j]+1; j++;
        }
    }
}

int main(){
    string s; cin >> s;
    kmp_PI(s);

    for(i = 0; i < s.size(); i++) cout << PI[i] << " ";
}    