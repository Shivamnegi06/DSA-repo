#include<iostream>

bool isThere(int *arr, int size, int element){

    if(size==0){
        return false;
    }
    
    if(arr[0]==element){
        return true;
    }

    bool ifPresent = true;
    ifPresent = isThere(arr+1,size-1,element);    
    return ifPresent;

}

int main(){

    int arr[5] = {1,2,3,4,5};
    int keyElement = 8;

    bool presentorNot = isThere(arr, 5,keyElement);

    if(presentorNot){
        std::cout<<"present";
    }
    else{
        std::cout<<"absent";
    }
}