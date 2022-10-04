import java.util.Scanner;
public class SubtractTwoNum2{
public static void main(String args[]){
  int sub;//declare variable to find subtraction
Scanner scan=new Scanner(System.in);
//create a scanner instance for receives input
// from the user - input from keyboard
System.out.print("Enter the value to num1: ");
int num1=scan.nextInt();
System.out.print("Enter the value to num2: ");
int num2=scan.nextInt();

System.out.print("subtraction of "+num2+"-"+num1+" :"+subtraction(num1,num2));
//display the subtraction of two numners
}

static int subtraction(int x,int y){
  return y-x;
}

}
