#include<iostream>
#include<bits/stdc++.h>



bool palindrome(std::string& str,int start, int end){
    if(start>end){
        return true;
    }
    if(str[start]!=str[end]){
        return false;
    }
    start++;
    end--;
    return palindrome(str,start,end);


}

int main(){

    std::string str = "aabccbaa";
    int start = 0;
    int end = str.length()-1;

    bool ifPalindrome = palindrome(str,start,end );

    if(ifPalindrome){
        std::cout<<"It is palindrome";

    }

    else{
        std::cout<<"It is not palindrome";
    }

}

