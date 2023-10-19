#include<iostream>

int recPower(int number, int power){
    if(power==0){
        return 1;
    }
    if(power==1){
        return number;
    }

    int answer = number*recPower(number,--power);
    return answer;

}

int main(){

    int number  = 3;
    int power = 2;

    int answer = recPower(number,power);
    std::cout<<answer;
}