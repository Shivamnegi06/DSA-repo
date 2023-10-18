#include<iostream>

int sumArray(int *arr, int size){

    if(size==0){
        return 0;
    }

    int sum = arr[0]+sumArray(arr+1,size-1);
    return sum;
}

int main(){
    int arr[5] = {10,2,3,4,5};
    int size = 5;

    int answer = sumArray(arr,size);
    std::cout<<answer;

    return 0;
}