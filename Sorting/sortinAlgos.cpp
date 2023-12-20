#include<iostream>
#include<vector>
using namespace std;

void selectionSort(int arr[], int n){
    for(int i=0; i <= n-2; i++){
        int mini = i;
        for(int j=i; j <= n-1; j++){
            if(arr[mini] > arr[j]){
                mini = j;
            }
        }
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
}
void bubbleSort(int arr[], int n){
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<i; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void insertionSort(int arr[], int n){
    for(int i=0; i<n; i++){
        int j = i;
        while(j>0 && arr[j] < arr[j-1]){
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
}

int position(vector<int> &arr, int low, int high){
    int i=low;
    int j= high;
    int pivot = arr[low];

    while(i<j){
        while(arr[i] <= pivot && i <= high){
            i++;
        }
        while(arr[j] > pivot && j>= low3){
            j--;    
        }
        if(i<j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
     if(i>j){
            int temp = arr[low];
            arr[low] = arr[j];
            arr[j] = temp;
        }
    return j;
}
void qs(vector<int> &arr, int low, int high){
    if(low < high){
       int  pIndex = position(arr, low, high);
        qs(arr, low, pIndex-1);
        qs(arr,pIndex+1, high);
    }
}
vector<int>QuickSort(vector<int> arr){
    int low = 0;
    int high = arr.size()-1;
    qs(arr,low, high);
    return arr;
}

int main()
{
   
    vector<int> arr= {4, 6, 2, 5, 7, 9, 1, 3};
    
    cout<<"\nBefore Applying Quick Sort: ";
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    // bubbleSort(arr,n);
    // cout<<"\nAfter applying Bubble Sort: ";
    // for(int i=0; i<n; i++){
    //     cout<<arr[i]<<" ";
    // }
    arr = QuickSort(arr);
    cout<<"\nAfter Quick  Sort: ";
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}