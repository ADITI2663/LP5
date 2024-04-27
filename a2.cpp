// // #include<bits/stdc++.h>
// // #include<omp.h>

// // using namespace std;

// // void merge(int arr[],int low,int mid,int high)
// // {
// //     int n1 = mid-low+1;
// //     int n2 = high-mid;
    
// //     int left[n1];
// //     int right[n2];
    
// //     for(int i=0;i<n1;i++) left[i] = arr[low+i];
// //     for(int j=0;j<n2;j++) right[j] = arr[mid+1+j];
    
// //     int i=0,j=0,k=low;
    
// //     while(i<n1 && j<n2)
// //     {
// //         if(left[i] <= right[j])
// //         {
// //             arr[k] = left[i];
// //             i++;
// //         }
// //         else
// //         {
// //             arr[k] = right[j];
// //             j++;
// //         }
// //         k++;
// //     }
    
// //     while(i<n1)
// //     {
// //         arr[k] = n1;
// //         i++;
// //         k++;
// //     }
// //     while(j<n2)
// //     {
// //         arr[k] = n2;
// //         j++;
// //         k++;
// //     }
// // }

// // void parallelMergeSort(int arr[],int low,int high)
// // {
// //     if(low < high)
// //     {
// //        int mid = (low+high)/2;
        
// //         #pragma omp parallel sections
// //         {
// //             #pragma omp section
// //             {
// //                 parallelMergeSort(arr,low,mid);
// //             }
// //             #pragma omp section
// //             {
// //                 parallelMergeSort(arr,mid+1,high);
// //             }
// //         }
// //     }
// // }

// // void mergesort(int arr[],int low,int high)
// // {
// //     if(low < high)
// //     {
// //        int  mid = (low + high)/2;
// //         mergesort(arr,low,mid);
// //         mergesort(arr,mid+1,high);
// //         merge(arr,low,mid,high);
// //     }
// // }

// // void bubbleSort(int arr[],int n)
// // {
// //     for(int i=0;i<n-1;i++)
// //     {
// //         for(int j=0;j<n-1-i;j++)
// //         {
// //             if(arr[j] > arr[j+1]) swap(arr[j],arr[j+1]);
// //         }
        
// //     }
// // }

// // void parallelBubbleSort(int arr[],int n)
// // {
// //     for(int i=0;i<n;i++)
// //     {
// //         #pragma omp parallel for
// //         for(int j=1;j<n;j+=2)
// //         {
// //             if(arr[j] < arr[j-1])
// //             {
// //                 swap(arr[j],arr[j-1]);
// //             }
// //         }
        
// //         #pragma omp barrier
        
// //         #pragma omp parallel for
// //         for(int j=2;j<n;j+=2)
// //         {
// //             if(arr[j] < arr[j-1])
// //             {
// //                 swap(arr[j],arr[j-1]);
// //             }
// //         }
// //     }
    
    
// // }

// // void printArray(int arr[],int n)
// // {
// //     for(int i=0;i<n;i++)
// //     {
// //         cout<<arr[i]<< " ";
// //     }
// // }

// // int main()
// // {
// //    int n;
// //     cout << "\n Enter the size of array:";
// //     cin >> n;
// //     int *arr1 = new int[n]; // Dynamic memory allocation

// //     for (int i = 0; i < n; i++) {
// //         cin >> arr1[i];
// //     }
// //     int *arr2 = new int[n];
// //     int *arr3 = new int[n];
// //     int *arr4 = new int[n];

// //     // Copy arrays manually
// //     for (int i = 0; i < n; i++) {
// //         arr2[i] = arr1[i];
// //         arr3[i] = arr1[i];
// //         arr4[i] = arr1[i];
// //     }

// //     double start_time, end_time;

// //     // Measure Parallel Bubble Sort time
// //     start_time = omp_get_wtime();
// //     parallelBubbleSort(arr1, n);
// //     end_time = omp_get_wtime();
// //     printArray(arr1, n);
// //     cout << "Parallel Bubble Sort took : " << end_time - start_time << " seconds.\n";

// //     // Measure Sequential Bubble Sort time
// //     start_time = omp_get_wtime();
// //     bubbleSort(arr2, n);
// //     end_time = omp_get_wtime();
// //     printArray(arr2, n);
// //     cout << "Sequential Bubble Sort took : " << end_time - start_time << " seconds.\n";

// //     // Measure Parallel Merge Sort time
// //     start_time = omp_get_wtime();
// //     parallelMergeSort(arr3, 0, n - 1);
// //     end_time = omp_get_wtime();
// //     printArray(arr3, n);
// //     cout << "Parallel Merge Sort took: " << end_time - start_time << " seconds\n";

// //     // Measure Sequential Merge Sort Time
// //     start_time = omp_get_wtime();
// //     mergesort(arr4, 0, n - 1);
// //     end_time = omp_get_wtime();
// //     printArray(arr4, n);
// //     cout << "Sequential Merge Sort took: " << end_time - start_time << " seconds\n";

// //     // Free dynamically allocated memory
// //     delete[] arr1;
// //     delete[] arr2;
// //     delete[] arr3;
// //     delete[] arr4;
   
// //    return 0;
  
// // }


// #include <bits/stdc++.h>
// #include <omp.h>

// using namespace std;

// void merge(int arr[], int low, int mid, int high) {
//     // Create arrays of left and right partititons
//     int n1 = mid - low + 1;
//     int n2 = high - mid;

//     int left[n1];
//     int right[n2];
    
//     // Copy all left elements
//     for (int i = 0; i < n1; i++) left[i] = arr[low + i];
    
//     // Copy all right elements
//     for (int j = 0; j < n2; j++) right[j] = arr[mid + 1 + j];
    
//     // Compare and place elements
//     int i = 0, j = 0, k = low;

//     while (i < n1 && j < n2) {
//         if (left[i] <= right[j]){
//             arr[k] = left[i];
//             i++;
//         } 
//         else{
//             arr[k] = right[j];
//             j++;
//         }
//         k++;
//     }

//     // If any elements are left out
//     while (i < n1) {
//         arr[k] = left[i];
//         i++;
//         k++;
//     }

//     while (j < n2) {
//         arr[k] = right[j];
//         j++;
//         k++;
//     }
// }

// void parallelMergeSort(int arr[], int low, int high) {
//     if (low < high) {
//         int mid = (low + high) / 2;

//         #pragma omp parallel sections
//         {
//             #pragma omp section
//             {
//                 parallelMergeSort(arr, low, mid);
//             }

//             #pragma omp section
//             {
//                 parallelMergeSort(arr, mid + 1, high);
//             }
//         }
//         merge(arr, low, mid, high);
//     }
// }

// void mergeSort(int arr[], int low, int high) {
//     if (low < high) {
//         int mid = (low + high) / 2;
//         mergeSort(arr, low, mid);
//         mergeSort(arr, mid + 1, high);
//         merge(arr, low, mid, high);
//     }
// }

// void bubbleSort(int array[], int n){
//     for (int i = 0; i < n - 1; i++){
//         for (int j = 0; j < n - i - 1; j++){
//             if (array[j] > array[j + 1]) swap(array[j], array[j + 1]);
//         }
//     }
// }


// void parallelBubbleSort(int arr[],int n)
// {
//     for(int i=0;i<n;i++)
//     {
//         #pragma omp parallel for
//         for(int j=1;j<n;j+=2)
//         {
//             if(arr[j] < arr[j-1])
//             {
//                 swap(arr[j],arr[j-1]);
//             }
            
//         }
        
//         #pragma omp barrier
        
//         #pragma omp parallel for
//         for(int j=2;j<n;j+=2)
//         {
//             if(arr[j] < arr[j-1])
//             {
//                 swap(arr[j],arr[j-1]);
//             }
//         }
//     }
// }

// void printArray(int arr[], int n){
//     // if (n > 10) return;
//     for(int i = 0; i < n; i++) cout << arr[i] << " ";
//     cout << "\n";
// }

// int main() {
//     int n;
//     cout << "Enter the size of the array: ";
//     cin >> n;

//     int arr[n];
//     double start_time, end_time;

//     cout << "Enter " << n << " elements of the array: ";
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     int arr_copy1[n], arr_copy2[n], arr_copy3[n], arr_copy4[n];
//     // Create copies of the original array
   
//     // Create copies of the original array
//     copy(arr, arr + n, arr_copy1);
//     copy(arr, arr + n, arr_copy2);
//     copy(arr, arr + n, arr_copy3);
//     copy(arr, arr + n ,arr_copy4);
    

//     // Measure Sequential Merge Sort Time
//     start_time = omp_get_wtime();
//     mergeSort(arr_copy1, 0, n - 1);
//     end_time = omp_get_wtime();
//     cout << "Sorted array using Sequential Merge Sort: ";
//     printArray(arr_copy1, n);
//     cout << "Sequential Merge Sort took: " << end_time - start_time << " seconds" << endl;

//     // Measure Parallel Merge Sort Time
//     start_time = omp_get_wtime();
//     parallelMergeSort(arr_copy2, 0, n - 1);
//     end_time = omp_get_wtime();
//     cout << "Sorted array using Parallel Merge Sort: ";
//     printArray(arr_copy2, n);
//     cout << "Parallel Merge Sort took: " << end_time - start_time << " seconds" << endl;

//     // Measure Sequential Bubble Sort time
//     start_time = omp_get_wtime();
//     bubbleSort(arr_copy3, n);
//     end_time = omp_get_wtime();
//     cout << "Sorted array using Sequential Bubble Sort: ";
//     printArray(arr_copy3, n);
//     cout << "Sequential Bubble Sort took: " << end_time - start_time << " seconds" << endl;

//    // Measure Sequential Bubble Sort time
//     start_time = omp_get_wtime();
//     parallelBubbleSort(arr_copy4, n);
//     end_time = omp_get_wtime();
//     cout << "Sorted array using Parallel Bubble Sort: ";
//     printArray(arr_copy4, n);
//     cout << "Parallel Bubble Sort took: " << end_time - start_time << " seconds" << endl;

//     return 0;

//     // g++ 2_merge_bubble.cpp -lgomp -o 2_merge_bubble && ./2_merge_bubble
// }

#include<bits/stdc++.h>
#include<omp.h>

using namespace std;

void merge(int arr[],int low,int mid,int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    
    int left[n1];
    int right[n2];
    
    for(int i=0;i<n1;i++) left[i] = arr[low + i];
    for(int j=0;j<n2;j++) right[j] = arr[mid + 1 + j];
    
    int i=0,j=0,k=low;
    while(i < n1 && j < n2)
    {
        if(left[i] < right[j])
        {
            arr[k] = left[i];
            i++;
            
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    
    while(i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void parallelMergesort(int arr[],int low,int high)
{
    if(low < high)
    {
        int mid = (low + high)/2;
        #pragma omp parallel sections
        {
            #pragma omp section 
            {
                parallelMergesort(arr,low,mid);
            }
            #pragma omp section 
            {
                parallelMergesort(arr,mid+1,high);
            }
        }
        
        merge(arr,low,mid,high);
    }
}

void mergeSort(int arr[],int low,int high)
{
    if(low < high)
    {
        int mid = (low + high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

void bubblesort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j] > arr[j+1]) swap(arr[j],arr[j+1]);
        }
    }
}

void bubblesortparallel(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        #pragma omp parallel for
        for(int j=1;j<n;j+=2)
        {
            if(arr[j] < arr[j-1] ) 
            {
                swap(arr[j],arr[j-1]);
            }
        }
        
        #pragma omp barrier
        
        #pragma omp parallel for
        for(int j=2;j<n;j+=2)
        {
            if(arr[j] < arr[j-1])
            {
                swap(arr[j],arr[j-1]);
            }
        }
    }
}

void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i] << " ";
    }
    cout<<endl;
}

int main()
{
    int n;
    cout<<"\n Enter :";
    cin>>n;
    
    int arr[n];
    for(int i=0;i<n;i++)
    {
       cin>>arr[i];   
    }
    
    int arr1_copy[n],arr2_copy[n],arr3_copy[n],arr4_copy[n];
    
    copy(arr,arr+n,arr1_copy);
    copy(arr,arr+n,arr2_copy);
    copy(arr,arr+n,arr3_copy);
    copy(arr,arr+n,arr4_copy);
    
    double stime,etime;
    
    stime = omp_get_wtime();
    mergeSort(arr1_copy,0,n-1);
    etime = omp_get_wtime();
    cout<<"Sorted Array using sequential merge sort :";
    print(arr1_copy,n);
    cout << "Parallel Bubble Sort took: " << etime-stime << " seconds" << endl;
    
    stime = omp_get_wtime();
    parallelMergesort(arr2_copy,0,n-1);
    etime = omp_get_wtime();
    cout<<"Sorted Array using paralell merge sort :";
    print(arr2_copy,n);
    cout << "Parallel Bubble Sort took: " << etime-stime << " seconds" << endl;
    
    stime = omp_get_wtime();
    bubblesort(arr3_copy,n);
    etime = omp_get_wtime();
    cout<<"Sorted Array using Bubble sort :";
    print(arr3_copy,n);
    cout << "Parallel Bubble Sort took: " << etime-stime << " seconds" << endl;
    
    stime = omp_get_wtime();
    bubblesortparallel(arr4_copy,n);
    etime = omp_get_wtime();
    cout<<"Sorted Array using Bubble sort paralell :";
    print(arr4_copy,n);
    cout << "Parallel Bubble Sort took: " << etime-stime << " seconds" << endl;
    
    return 0;
}
