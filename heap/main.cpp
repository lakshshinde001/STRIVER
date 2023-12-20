#include<iostream>
using namespace std;

class heap{
	public : 
		int arr[100];
		int size;
	heap(){
		arr[0] = -1;
		size = 0;
	}
	void insert(int value){
		size = size + 1;
		int index = size;
		arr[index] = value;
		
		while(index > 1){
			int parent = index / 2;
			if(arr[index] > arr[parent]){
				swap(arr[parent], arr[index]);
				index = parent;
			}else{
				return;
			}	
		}
	}
	void print(){
		for(int i=1; i<=size; i++){
			cout<<arr[i]<<" ";
		}cout<<endl;
	}
	void deleteFromHeap(){
		if(size == 0){
			cout<<"\nHeap is Empty : ";
			return;
		}
		arr[1] = arr[size];
		size--;
		
		int i=1;
		while(i <=size){
			int left = i*2;
			int right = i*2+1;
			
			if(left < size && arr[left] > arr[i]){
				swap(arr[i], arr[left]);
				i = left;
			}else if(right < size && arr[right] > arr[i]){
				swap(arr[i], arr[right]);
				i = right;
			}else{
				return;
			}
			
		}
		
	}
	void heapify(int arr[], int n, int i){
		int largest = i;
		int left = 2*i;
		int right = 2*i+1;
		
		
		if(left <= n && arr[left] > arr[largest]){
			largest = left;
		}
		if(right <= n && arr[right] > arr[largest]){
			largest = right;
		}
		if(largest != i){
			swap(arr[largest], arr[i]);
			heapify(arr, n, largest);
		}
	}
	void heapSort(int arr[], int n){
		int size = n;
		
		while(size > 1){
			swap(arr[size], arr[1]);
			size--;
			heapify(arr, size, 1);
		}
	}
};

int main(){
	
	heap h;
//	h.insert(10);
//	h.insert(30);
//	h.insert(5);
//	h.insert(100);
//	h.insert(110);
//	h.insert(50);
//	h.print();
//	h.deleteFromHeap();
//	h.deleteFromHeap();
	int arr[10] = {-1,34,394,33,45,34,78,46,86,300};
	int n = 9;
	for( int i = n/2; i>0; i--){
		h.heapify(arr, n, i);
	}
	cout<<"Max heap ";
	for( int i = 1; i<=n; i++){
		cout<<arr[i]<<" ";
	}	
	
	h.heapSort(arr,n);
	cout<<"\nSorted Array : ";
	for( int i = 1; i<=n; i++){
		cout<<arr[i]<<" ";
	}	
	
	return 0;
}
