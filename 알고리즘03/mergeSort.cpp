//MergeSort
void mergeSort(int arr[], int size) {
	if (size == 1) return;
	int mid = size / 2;
	mergeSort(arr, mid);
	mergeSort(arr + mid, size - mid);



}