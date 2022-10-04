//Kadane_Algorithm
//To Find Maximum Subarray Sum.
//Subarray is continuous sequence in array/list.
public class Kadane_Algo {

    public static void main(String[] args) {

        int[] arr = {-2,1,-3,4,-1,2,1,-5,4};
        int len = arr.length;
        System.out.println(maxArray(arr,len)); 
        //Max subarray sum is 6 of elements [4,-1,2,1] which is a contiguous subarray.
        
    }

    
    public static int maxArray(int arr[], int n)
    {
        //Logic is When Total Sum becomes negative 
        //Start from Fresh i.e. Take totsum(Total sum) as element at that position

        //And In Every iteration find Maximum of totsum and Maxsum , and store it in Maxsum.
        int totsum = 0;
        int maxsum = Integer.MIN_VALUE;
        for(int i=0;i<arr.length;i++)
        {   
            //Check that total sum is positive
            if(totsum >= 0)
            {
                totsum = totsum + arr[i];
            }
            else{
                totsum = arr[i]; 
            }
            maxsum = Math.max(totsum,maxsum); //Updating Maximum sum till iteration.          
        }
        return maxsum;
        

    }
    
}
