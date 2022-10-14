//PICK THE POINTS

import java.util.*;

class GFG{

// Function to sort by column
public static void sortbyColumn(int arr[][],
        int col)
{
 
 // Using built-in sort function Arrays.sort
 Arrays.sort(arr, new Comparator<int[]>()
 {
  @Override
  
  // Compare values according to columns
  public int compare(final int[] entry1,
      final int[] entry2)
  {
   
   // To sort in descending order revert
   // the '>' Operator
   if (entry1[col] > entry2[col])
    return 1;
   else
    return -1;
  }
 }); // End of function call sort().
}

// Function to count the minimum number of
// steps required to delete all the segments
static int cntMinSteps(int[][] arr, int N)
{
 
 // Stores count of steps required
 // to delete all the line segments
 int cntSteps = 1;
 
 // Sort the array based on end points
 // of line segments
 sortbyColumn(arr, 1);
 
 // Stores point on X-axis
 int Points = arr[0][1];
 
 // Traverse the array
 for(int i = 0; i < N; i++)
 {
  
  // If arr[1][0] is
  // greater than Points
  if(arr[i][0] > Points)
  {
   
   // Update cntSteps
   cntSteps++;
   
   // Update Points
   Points = arr[i][1];
  }
 }
 return cntSteps;
}

// Driver Code
public static void main(String[] args)
{
 int[][] arr = { { 1, 3 }, { 2, 5 },
     { 3, 6 } };
       
 int N = arr.length;
 
 System.out.print(cntMinSteps(arr, N));
}
}