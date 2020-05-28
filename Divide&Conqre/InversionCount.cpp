#include <stdio.h> 

using namespace std; 
int _mergeSort(int *, int*, int, int );
int merge(int*, int*, int, int, int);

int mergeSort(int *arr,int *temp, int array_size) 
{ 
	return _mergeSort(arr, temp, 0, array_size - 1); 
} 


int _mergeSort(int *arr, int *temp, int left, int right) 
{ 
	int mid, inv_count = 0; 
	if (right > left) { 
		mid = (right + left) / 2; 
		inv_count += _mergeSort(arr, temp, left, mid); 
		inv_count += _mergeSort(arr, temp, mid + 1, right); 
		inv_count += merge(arr, temp, left, mid + 1, right); 
	} 
	return inv_count; 
} 

int merge(int *arr, int *temp, int left, int mid, int right) 
{ 
	int i, j, k; 
	int inv_count = 0; 

	i = left;
	j = mid; 
	k = left;
	while ((i <= mid - 1) && (j <= right)) { 
		if (arr[i] <= arr[j]) { 
			temp[k++] = arr[i++]; 
		} 
		else { 
			temp[k++] = arr[j++]; 
			inv_count = inv_count + (mid - i); 
		} 
	} 
	while (i <= mid - 1) 
		temp[k++] = arr[i++]; 
	while (j <= right) 
		temp[k++] = arr[j++]; 
	for (i = left; i <= right; i++) 
		arr[i] = temp[i]; 

	return inv_count; 
} 

int main() 
{ 
	int *arr = new int[200005];
	int *temp = new int[200005];
	int t, ans, n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for (int i=0; i<n; i++)
				scanf("%d",arr+i);
		ans = mergeSort(arr, temp, n);
		printf("%d\n",ans);
	}
	delete [] temp;
	delete [] arr;
	return 0; 
}
