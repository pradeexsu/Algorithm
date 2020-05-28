#include<algorithm>
#include<iostream>
#include<stdio.h>
// #include <ctime>        // std::time
// #include <cstdlib>      // std::rand, std::srand

using namespace std;
int partition(int *arr, int lo, int hi){
	int j = lo-1;
	random_shuffle(arr+lo, arr+hi+1);
	for (int i=lo; i<hi;i++){
		if(arr[i]<=arr[hi]){
			j++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[j+1], arr[hi]);
	return j+1;
}

void QuickSort(int *p, int left, int right){
	if(left>=right)
		return;
	int pivot = partition(p, left, right);
	QuickSort(p, left, pivot-1);
	QuickSort(p, pivot+1, right);
}
int main() {
	int n;
	scanf("%d",&n);
	int *p = new int[n];
	for (int i=0; i<n; i++)
		scanf("%d",p+i);
	QuickSort(p,0,n-1);
	for (int i=0; i<n; i++)
		printf("%d ",p[i]);
	
	return 0;
}
