#include < stdio.h >
 
void heapify(int arr[], int n, int i) 
{
      int temp;
      int largest = i;
      int l = 2 * i + 1;        //left child
      int r = 2 * i + 2;       //right child
 
      if (l < n && arr[l] > arr[largest])
         largest = l;
 
      if (r < n && arr[r] > arr[largest])
         largest = r;
 
      if (largest != i) {
         temp = arr[i];
         arr[i] = arr[largest];
         arr[largest] = temp;
 
         heapify(arr, n, largest);
      }
   }
 
void heapSort(int arr[], int n)   arr array, n size of array
 {
   int temp;
 
   for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);                   three arguments,array,size,
 
   for (int i = n - 1; i >= 0; i--) {
      temp = arr[0];
      arr[0] = arr[i];
      arr[i] = temp;
 
      heapify(arr, i, 0);
   }
}
 
int main()
{
   int arr[20];
   int i,n;
   printf("Enter how namy elements?\n");
   for(i=0;i<n;i++)
   {
    scanf("%d",&arr[i]);
   }
   printf("Before sorting array elements are are: \n");
   for (i = 0; i < n; i++)
      printf("%d ", arr[i]);
   printf("\n");
   heapSort(arr, n);
   printf("\nSorted array is: \n");
   for (i = 0; i < n; ++i)
      printf("%d ", arr[i]);
}
