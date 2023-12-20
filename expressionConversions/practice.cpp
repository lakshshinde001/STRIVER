//#include<iostream>
//using namespace std;
//
//class heap{
//	public :
//void heapify(int arr[], int n, int i){
//		int largest = i;
//		int left = 2*i;
//		int right = 2*i+1;
//		
//		
//		if(left <= n && arr[left] > arr[largest]){
//			largest = left;
//		}
//		if(right <= n && arr[right] > arr[largest]){
//			largest = right;
//		}
//		if(largest != i){
//			swap(arr[largest], arr[i]);
//			heapify(arr, n, largest);
//		}
//	}
//	void heapsort(int arr[], int n){
//		int size = n;
//		while(size > 1){
//			swap(arr[1], arr[size]);
//			size--;
//			heapify(arr, size, 1);
//		}
//	}
//};
//
//int main(){	
//	heap h;
//	
//	int arr[6] = {-1,20,12,4,56,3};
//	int n = 5;
//	for(int i=n/2; i>=1; i--){
//		h.heapify(arr, n, i);
//	} 
//	for(int i=1; i<n; i++){
//		cout<<arr[i]<<" ";
//	}
//	h.heapsort(arr, n);
//	cout<<"\nSorted Array = ";
//	for(int i=1; i<n; i++){
//		cout<<arr[i]<<" ";
//	}
//	
//	return 0;
//}
//#include<iostream>
//using namespace std;
//
//class solution{
//	public : 
//		int partition(int arr[],int low, int high ){
//			int pivot = arr[low];
//			int i = low;
//			int j = high;
//			
//			while(i<j){
//				while(arr[i] <= pivot && i <= high-1){
//					i++;
//				}
//				while(arr[j] >= pivot && j > low){
//					j--;
//				}
//				if(i < j){
//					swap(arr[i], arr[j]);
//				}
//			}
//			swap(arr[low], arr[j]);
//			return j;
//		}
//		
//		void quickSort(int arr[], int low, int high){
//			if(low < high){
//				int pIndex = partition(arr, low ,high);
//				quickSort(arr, low, pIndex);
//				quickSort(arr, pIndex+1, high);
//			}
//		}
//};
//int main(){
//	
//	int arr[5] = {5,1,2,3,4};
//	solution s;
//	s.quickSort(arr, 0, 4);
//	for(int i=0; i<5; i++){
//		cout<<arr[i]<<" ";
//	}
//	return 0;
//}
//#include<iostream>
//#include<vector>
//using namespace std; 
//
//class solution {
//	public : 
//		void merge(int arr[], int low, int mid, int high){
//			int left = low;
//			int right = mid +1;
//			vector<int>temp;
//			
//			while(left <= mid && right <= high ){
//				if(arr[left] <= arr[right]){
//					temp.push_back(arr[left]);
//					left++;
//				}else {
//					temp.push_back(arr[right]);
//					right++;
//				}
//			}
//			while(left <= mid){
//				temp.push_back(arr[left]);
//				left++;
//			}
//			while(right <= high){
//				temp.push_back(arr[right]);
//				right++;
//			}
//			
//			for(int i=low; i<=high; i++){
//				arr[i]= temp[i-low];
//			}
//			
//			
//		}
//		void mergeSort(int arr[], int low, int high){
//			if(low >= high){
//				return;
//			}
//			int mid = (low+high) /2;
//			mergeSort(arr, low, mid);
//			mergeSort(arr, mid+1, high);
//			merge(arr, low, mid, high);
//		}
//};
//
//int main(){
//	int arr[5] = { 4,2,3,5,1};
//	solution s; 
//	
//	s.mergeSort(arr, 0, 4);
//	for(int i=0; i<5; i++){
//		cout<<arr[i]<<" ";
//	}
//	cout<<endl;
//	
//	return 0;
//}
//
//#include<iostream>
//using namespace std;
//
//void bubbleSort(int arr[], int n){
//	for(int i =0; i<n; i++){
//		for(int j=0; j<n-i-1; j++){
//			if(arr[j] > arr[j+1]){
//				swap(arr[j], arr[j+1]);
//			}
//		}
//	}
//}
//
//int main(){
//	
//	int arr[5] = {4,3,2,5,1};
//	bubbleSort(arr,5);
//	for(int i=0; i<5; i++){
//		cout<<arr[i]<<" ";
//	}
//	return 0;
//}

//
//#include<iostream>
//using namespace std;
//
//void selectionSort(int arr[], int n){
//	for(int i=0; i<n; i++){
//		int mini = i;
//		for(int j=i+1;j<n; j++){
//			if(arr[mini] > arr[j]){
//				mini = j;
//			}
//		}
//		swap(arr[mini], arr[i]);
//	}
//	
//}
//int main(){
//	int arr[5] = {3,2,1,5,4};
//	selectionSort(arr,5);
//	for(int i=0; i<5; i++){
//		cout<<arr[i]<<" ";
//	}
//	return 0;
//}


//#include<iostream>
//using namespace std;
//
//void insertionSort(int arr[], int n){
//	for(int i=0; i<n; i++){
//		int j =i; 
//		
//		while(j>0 && arr[j-1] > arr[j]){
//			swap(arr[j-1], arr[j]);
//			j--;
//		}
//	}
//}
//
//int main(){
//	int arr[5] = {2,1,3,4,5};
//	insertionSort(arr, 5);
//	for(int i=0; i<5; i++){
//		cout<<arr[i]<<" ";
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int linearSearch(int arr[], int n, int key){
//	for(int i=0; i<n; i++){
//		if(arr[i] == key){
//			return i;
//		}
//	}
//	return -1;
//}
//
//int main(){
//	int n=5;
//	int arr[n] = {3,2,1,5,4};
//	int key = 5;
//	
//	int ans = linearSearch(arr,n, key);
//	
//	if(ans == -1){
//		cout<<"\nKey Not Found ";
//	}else{
//		cout<<"\nKey Fount at index : "<<ans; 
//	}
//	
//	return 0;
//}

#include<iostream>
using namespace std;



int main(){
	
	return 0;
}












