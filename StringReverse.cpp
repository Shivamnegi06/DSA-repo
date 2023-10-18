#include<iostream>
#include <bits/stdc++.h> 

using namespace std;

void reverse(string &str,int start,int end){
	
    if(start>end){
		return;
	}
	swap(str[start],str[end]);
    start++;
    end--;
    reverse(str,start,end);
    
}
int main(){	
    string str = "azcse";

	int start = 0;
	int end = str.length()-1;
	reverse(str,start,end);
	cout<<str;

    return 0;
	
}