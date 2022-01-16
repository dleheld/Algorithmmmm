void quickSort(int arr[], int left, int right) {
	if (left < right) {
		int p = left, i = left + 1, j = right;
		while (i <= j) { //���� �������� �ʾҴٸ� �迡�� �������~
			while (arr[i] <= arr[p]) i++; //������ ������ ��� ���
			while (arr[j] > arr[p]) j--; //������ ū�� ������
			//���� �����, �׷��� i�� j�� 
			if (i < j) { //��� ���߸� �ٲ�
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		} // �����ϸ� ��
		int tmp = arr[p];
		arr[p] = arr[j];
		arr[j] = tmp; 
		//pivot�� j��°�� 
		quickSort(arr, left, j - 1);
		quickSort(arr, j + 1, right);
	}
}