#include<iostream>

bool isPresent(int *arr, int start, int end, int key){
   int mid = start + (end-start)/2;
   int found = false;
   if(start>end){
    return found;
   }
   if(arr[mid]==key){
    found = true;
    return found;
   }
   else if(arr[mid]>key){
    end = mid-1;
    found = isPresent(arr,start,end,key);
   }
   else{
    start = mid+1;
    found = isPresent(arr,start,end,key);
   }
   
   return found; 


}

int main(){

    int arr[10]={2,3,5,6,10,34,58,89,90,91};
    int element = 91;
    int start = 0;
    int end = 9;
    bool found =isPresent(arr,start,end,element);
    if(found){
    
        std::cout<<"Element Found.";
        

    }
    else{

        std::cout<<"Element not found.";

    }

    return 0;  
}