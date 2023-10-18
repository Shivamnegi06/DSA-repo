#include<iostream>

void bubblesort(int *arr, int size){
    if(size==0){
        return;
    }
    for(int x=1;x<size;x++){
        if(arr[x-1]>arr[x]){
            std::swap(arr[x-1],arr[x]);
        }
    }
    size--;
    bubblesort(arr,size);
}
int main(){

    int arr[5]={10,40,20,8,6};
    int i=0;
    int j=1;
    int size = sizeof(arr)/sizeof(arr[0]);
    bubblesort(arr,size);
    for(int it=0 ; it<size ; it++){
        std::cout<<arr[it]<<" ";
    }

}