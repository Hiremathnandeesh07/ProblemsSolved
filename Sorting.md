# Sorting Algorithms

bubble sort ,selection sort,merge sort,insertion sort,quick sort

> > # 1. Bubble Sort :

- Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in the wrong order. This algorithm is not suitable for large data sets as its average and worst-case time complexity is quite high.
- In Bubble Sort algorithm,
  > traverse from left and compare adjacent elements and the higher one is placed at right side.
  > In this way, the largest element is moved to the rightmost end at first.
  > This process is then continued to find the second largest and place it and so on until the data is sorted.

* Total no. of passes: n-1
* Total no. of comparisons: n\*(n-1)/2

```cpp
#include <stdio.h>

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++) {
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Original array: \n");
    printArray(arr, n);
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
```

- ### Worst Time Complexity: O(N2) (when the array is in reverse order)

- ### Worst space complexity : O(1)

- ### Total number of comparison (Worst case) = N(N-1)/2

### Best time complexity : O(N)

> Bubble sort takes minimum time (Order of n) when elements are already sorted. Hence it is best to check if the array is already sorted or not beforehand, to avoid O(N2) time complexity.

### Advantages of Bubble Sort:

> Bubble sort is easy to understand and implement.\
> It does not require any additional memory space.\
> It is a stable sorting algorithm, meaning that elements with the same key value maintain their relative order in the sorted output.

### Disadvantages of Bubble Sort:

> Bubble sort has a time complexity of O(N2) which makes it very slow for large data sets.\
> Bubble sort is a comparison-based sorting algorithm, which means that it requires a comparison operator to determine the relative order of elements in the input data set. It can limit the efficiency of the algorithm in certain cases.

> > # 2. Selection Sort :

- The algorithm repeatedly selects the smallest (or largest) element from the unsorted portion of the list and swaps it with the first element of the unsorted part. This process is repeated for the remaining unsorted portion until the entire list is sorted.

* 1. find the minimun element
* 2. swap with the first element of unsorted array (i.e at the begging the unsorted array is the given array itself)
* 3. now your new unsorted array starts from index 1 (not zer0 because the minimum element is already placed at the first position in step 2)
* 4. continue the same steps

```cpp
#include <stdio.h>

// Function to perform selection sort
void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n-1; i++) {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        // Swap the found minimum element with the first element
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Original array: \n");
    printArray(arr, n);
    selectionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
```

### Time Complexity

**Best Case: O(n^2)**\
**Worst Case: O(n^2)**

### Interview Questions

1. **Explain how the Selection Sort algorithm works.**

   - Selection Sort divides the input array into two subarrays: sorted and unsorted. It repeatedly selects the minimum element from the unsorted subarray and places it at the beginning of the sorted subarray. This process continues until the entire array is sorted.

2. **What are the best and worst-case time complexities of Selection Sort?**

   - Both the best and worst-case time complexities of Selection Sort are `O(n^2)`, where `n` is the number of elements in the array.

3. **Can you optimize the Selection Sort algorithm in any way?**

   - Yes, Selection Sort can be optimized by minimizing the number of swaps. Instead of immediately swapping elements when the minimum is found, the algorithm can keep track of the index of the minimum element and perform a single swap after completing the iteration.

4. **Compare Selection Sort with other sorting algorithms like Bubble Sort or Insertion Sort.**

   - Selection Sort, Bubble Sort, and Insertion Sort are all comparison-based sorting algorithms with quadratic time complexities.
   - Selection Sort repeatedly selects the minimum element from the unsorted portion and places it at the beginning, while Bubble Sort repeatedly swaps adjacent elements if they are in the wrong order, and Insertion Sort iteratively places each element in its correct position by shifting larger elements to the right.

5. **Discuss scenarios where Selection Sort might be preferred over other sorting algorithms.**

   - Selection Sort might be preferred when simplicity and ease of implementation are more important than efficiency.
   - It can also be useful when auxiliary space is limited since it only requires a constant amount of additional memory.
   - In situations where the dataset is small or nearly sorted, the overhead of more complex algorithms might outweigh the benefits.

6. **Can you implement Selection Sort recursively?**

   - Yes, Selection Sort can be implemented recursively. The recursive version selects the minimum element from the unsorted subarray and places it at the beginning, then recursively calls itself for the remaining unsorted subarray.

7. **How does Selection Sort perform on large datasets compared to more efficient sorting algorithms?**

   - Selection Sort performs poorly on large datasets compared to more efficient sorting algorithms like Quick Sort or Merge Sort due to its quadratic time complexity. As the size of the dataset increases, the number of comparisons and swaps grows quadratically, leading to longer execution times.

8. **Is Selection Sort stable or unstable? Explain.**

   - Selection Sort is generally unstable because it does not preserve the relative order of equal elements. If there are two identical elements in the array, they may swap positions during the sorting process, potentially changing their relative order in the sorted array.

9. **What are some practical applications where Selection Sort might be used?**

   - Selection Sort might be used in situations where simplicity is more important than efficiency, such as sorting small arrays or implementing simple educational examples.
   - It can also be used as a building block in more complex algorithms or as part of an initial sorting step before applying a more efficient algorithm.

10. **How do you detect if a list is already sorted in Selection Sort?**
    - In Selection Sort, you can detect if a list is already sorted by observing that no swaps were made during an entire iteration over the array. If no swaps occur, it means that the array is already sorted, and you can terminate the algorithm early.

## 3. Insertion Sort :

- this always takes an element and place it in correct position
- Start with the Second Element: Begin with the second element of the array and consider it as a single-element sorted array.

* Insertion Step: For each subsequent element, compare it with the elements to its left in the sorted portion of the array. Move each larger element one position to the right until finding the correct position for the current element.

* Repeat: Repeat this process for each element in the array until the entire array is sorted.

```cpp
#include<stdio.h>

void insertion_sort(int arr[], int n) {
    // insertion sort
    for (int i = 1; i < n; i++) {
        int j = i;

        while (j > 0 && arr[j-1] > arr[j]) {
            // Swap elements if they are in the wrong order
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
    printf("After insertion sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {13,46,24,52,20,9};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Before insertion sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    insertion_sort(arr, n);
    return 0;
}
```

### Time Complexity

**Best Case: O(n)** the input array is already sorted or nearly sorted.
In this case, the inner while loop will rarely execute, as there will be few or no elements to shift.

**Average Case:O(n^2)** the input array is partially sorted or has elements in random order.
Each element must be compared with and possibly shifted past every other element in the sorted portion of the array.\
the number of comparisons and shifts required for each element will be approximately half of the elements already sorted.\

**Worst Case: O(n^2)** the input array is in reverse sorted order.
In this case, every element must be compared with and shifted past every other element in the sorted portion of the array.
