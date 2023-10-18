// 2 11 10 90 23 50

#include<iostream>



int partition(int *arr,int start,int end){

    int pivot  =arr[start];
    int count =0;
    for(int i =start;i<=end;i++){
        if(arr[i]<pivot){
            count++;
        }
    }
    int pivotIndex = start + count;
    
    std::swap(arr[pivotIndex],arr[start]);
    int i =0;
    int j= end;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        
        if(arr[i]>arr[j]){
            std::swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }

    return pivotIndex;
    
}

void quickSort(int *arr,int start,int end){

    //base case 
    if(start>=end){
        return;
    }
    //partition
    int p = partition(arr,start,end);

    //recursive relation
    quickSort(arr,start,p-1);
    quickSort(arr,p+1,end);

}

int main(){
    
    int arr[10] = {10,4,2,7,1,9,11,8,15,6};

    quickSort(arr,0,9);
    
    for(int i=0;i<10;i++){
        std::cout<<arr[i]<<" ";
    }

    return 0;
}