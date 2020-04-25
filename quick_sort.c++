#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int p,int r) {
	if(p==r)
	    return p;
	int x=arr[p];
	int i=p,j=i+1;
	for(;j<=r;j++) {
		if(arr[j]<=x) {
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i],arr[p]);
	cout<<"\npart  ";
	//for(int i=p;i<=r;i++)
	//	cout<<arr[i]<<" ";
	//cout<<endl;
	return i;
}

void quicksort(int arr[],int low,int high) {
	if(low<high) {
		int pivot=partition(arr,low,high);
		cout<<arr[pivot]<<"HHH";
		quicksort(arr,low,pivot-1);
		quicksort(arr,pivot+1,high);
	}
}


int main() {
	int n;
	cout<<"Emter number of elements: ";
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	quicksort(arr,0,n-1);
	//cout<<partition(arr,0,n-1);
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
}
