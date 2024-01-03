
void merge(vector < int > & arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector < int > leftarr(n1);
    vector < int > rightarr(n2);

    for (int i = 0; i < n1; i++) {
        leftarr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightarr[i] = arr[mid + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (leftarr[i] <= rightarr[j]) {
            arr[k] = leftarr[i];
            i++;
        } 
        else {
            arr[k] = rightarr[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = leftarr[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = rightarr[j];
        j++;
        k++;
    }
}

void mergeSortHelper(vector < int > & arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSortHelper(arr, left, mid);
        mergeSortHelper(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void mergeSort(vector < int > & arr, int n) {
    mergeSortHelper(arr, 0, n - 1);
}
