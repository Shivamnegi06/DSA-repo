#include<iostream>


void algo(int n){
    if(n<=1){
       
        return;
    }
    if(n%2==0){
        n= n/2;
    }
    else{
        n = n*3 +1;
    }

     std::cout<<n<<" ";
     algo(n);
}

int main(){
    int number=0;
    std::cin>>number;
    std::cout<<number<<" ";
    algo(number);
    
    return 0;
}