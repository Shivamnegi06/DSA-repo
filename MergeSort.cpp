#include<iostream>
#include<bits/stdc++.h>

void merge(int *arr,int start,int end){

    int mid = start + (end-start)/2;
    
    int len1 = mid -  start + 1;
    int len2 = end - mid;

    //create new arrays
    int *first = new int[len1];
    int *second = new int[len2];

    //copy the values of array into new array
    int k = start;
    for(int i=0; i<len1;i++){
        first[i] = arr[k++];
    }

    k=mid+1;    
    for(int i=0;i<len2;i++){
        second[i] = arr[k++];
    }

    //merge 2 sorted array
    int index1 = 0;
    int index2 = 0;
    k = start;
    while(index1<len1 && index2<len2){
        if(first[index1]<second[index2]){
            arr[k++] = first[index1++];
        }
        else{
            arr[k++] = second[index2++];    
        }
    }
    while(index1<len1){
        arr[k++] = first[index1++];
    }
    while(index2<len2){
        arr[k++] = second[index2++];
    }

    delete []first;
    delete []second;
}


void mergeSort(int *arr,int start,int end){

    if(start>=end){
        return;
    }
    int mid = start + (end-start)/2;
    
    //left sort 
    mergeSort(arr,start,mid);
    //right sort
    mergeSort(arr,mid+1,end);

    //merge
    merge(arr,start,end);
}
int main(){
    int arr[10] = {4,2,3,1,5,8,7,9,6,10};
    int size = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr,0,size-1);

    for(int i =0;i<size;i++){
        std::cout<<arr[i]<<" ";
    }

    return 0;
}