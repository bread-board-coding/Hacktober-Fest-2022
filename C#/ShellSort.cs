using System;

class MyProgram {
  // function for shell sort
  static void shellsort(int[] Array) {
    int n = Array.Length;
    int gap = n/2;
    int temp, i, j;
    while(gap > 0) {
      for(i = gap; i < n; i++) {
        temp = Array[i];
        j = i;
        while(j >= gap && Array[j-gap] > temp) {
          Array[j] = Array[j-gap];
          j = j - gap;  
        }
        Array[j] = temp;
      }
      gap = gap / 2;
    }
  }

  // function to print array
  static void PrintArray(int[] Array) { 
    int n = Array.Length; 
    for (int i=0; i<n; i++)   
      Console.Write(Array[i] + " "); 
    Console.Write("\n"); 
  } 

  // test the code
  static void Main(string[] args) {
    int[] MyArray = {10, 1, 23, 50, 4, 9, -4};
    Console.Write("Original Array\n");
    PrintArray(MyArray);

    shellsort(MyArray);
    Console.Write("\nSorted Array\n");
    PrintArray(MyArray);  
  }
}