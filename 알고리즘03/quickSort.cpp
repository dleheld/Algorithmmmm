void quickSort(int arr[], int left, int right) {
	if (left < right) {
		int p = left, i = left + 1, j = right;
		while (i <= j) { //아직 교차하지 않았다면 계에속 진행시켜~
			while (arr[i] <= arr[p]) i++; //나보다 작은건 계속 통과
			while (arr[j] > arr[p]) j--; //나보다 큰건 계속통과
			//이제 멈췄다, 그러면 i와 j는 
			if (i < j) { //잠시 멈추면 바꿔
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		} // 교차하면 끝
		int tmp = arr[p];
		arr[p] = arr[j];
		arr[j] = tmp; 
		//pivot을 j번째로 
		quickSort(arr, left, j - 1);
		quickSort(arr, j + 1, right);
	}
}