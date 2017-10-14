/* Five basic sorting algorithms 
 written in C++
*/
 
class sorting_algorithm {
public:
    /* Merge sort
    Worst-case performance  O(n log n)
    Best-case performance   O(n log n) typical, O(n) natural variant
    Average performance O(n log n)
    Worst-case space complexity О(n) total, O(n) auxiliary
    */
    void mergesort(int *arr, int low, int high) {
        int mid;
        if (low < high) {
            mid = (low + high) / 2;
            mergesort(arr, low, mid);
            mergesort(arr, mid+1, high);
            merge(arr, low, mid, high);
        }
        return;
    }

    void merge(int *arr, int low, int mid, int high) {
        int i, j, k;
        int n = mid - low + 1;
        int m = high - mid;
        int *A = new int(n);
        int *B = new int(m);

        for (i = 0; i < n; ++i) A[i] = arr[low+i];
        for (j = 0; j < m; ++j) B[j] = arr[mid+1+i];

        i = 0;
        j = 0;
        k = low;
        while (i < n || j < m) {
            if ((i < n && j >= m) || (i < n && A[i] <= B[j])) {
                arr[k] = A[i];
                i++;
            } else {
                arr[k] = B[j];
                j++;
            }
            k++;
        }

    }




    /* quicksort
    Worst-case performance  O(n2)
    Best-case performance   O(n log n) (simple partition) or O(n) (three-way partition and equal keys)
    Average performance O(n log n)
    Worst-case space complexity O(n) auxiliary (naive) O(log n) auxiliary (Sedgewick 1978)
    */
    void quickSort(int *arr, int left, int right) {
        int i = left, j = right;
        int tmp;
        int pivot = arr[(left + right) / 2];

      /* partition */
        while (i <= j) {
            while (arr[i] < pivot) {
                i++;
            }
            while (arr[j] > pivot) {
                j--;
            }
            if (i <= j) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
                i++;
                j--;
            }
        }

      /* recursion */
        if (left < j) {
            quickSort(arr, left, j);
        }
        if (i < right) {
            quickSort(arr, i, right);
        }
    }




    /* insertion sort
    Worst-case performance  О(n2) comparisons, swaps
    Best-case performance   O(n) comparisons, O(1) swaps
    Average performance О(n2) comparisons, swaps
    Worst-case space complexity О(n) total, O(1) auxiliary
    */
    void insertion_sort(int *arr, int length) {
        for (int i = 1; i < length; ++i) {
            for (int j = i; j > 0 && arr[j] < arr[j-1]; j--) {
                // swap
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }




    /* selection sort
    Worst-case performance  О(n2)
    Best-case performance   О(n2)
    Average performance О(n2)
    Worst-case space complexity О(n) total, O(1) auxiliary
    */
    void selection_sort(int *arr, int length) {
        for (int i = 0; i < length; ++i) {
            int min = i;
            for (int j = i+1; j < length; ++j) {
                if (arr[min] > arr[j]) {
                    min = j;
                }
            }
            if (min != i) {
                int temp = arr[i];
                arr[i] = arr[min];
                arr[min] = temp;
            }
        }
    }




    /* heap sort
    Worst-case performance  O(nlog n)
    Best-case performance   O(nlog n)
    Average performance O(nlog n)
    Worst-case space complexity O(1) auxiliary
    */

    // To heapify a subtree rooted with node i which is
    // an index in arr[]. n is size of heap
    void heapify(int arr[], int n, int i) {
        int largest = i;  // Initialize largest as root
        int l = 2*i + 1;  // left = 2*i + 1
        int r = 2*i + 2;  // right = 2*i + 2

        // If left child is larger than root
        if (l < n && arr[l] > arr[largest])
            largest = l;

        // If right child is larger than largest so far
        if (r < n && arr[r] > arr[largest])
            largest = r;

        // If largest is not root
        if (largest != i) {
            swap(arr[i], arr[largest]);

            // Recursively heapify the affected sub-tree
            heapify(arr, n, largest);
        }
    }

    // main function to do heap sort
    void heapSort(int arr[], int n) {
        // Build heap (rearrange array)
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);

        // One by one extract an element from heap
        for (int i = n-1; i >= 0; i--) {
            // Move current root to end
            swap(arr[0], arr[i]);

            // call max heapify on the reduced heap
            heapify(arr, i, 0);
        }
    }
};
