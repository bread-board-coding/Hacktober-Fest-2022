import java.util.Scanner;

public class main{
    static public void main(String[] args){
        float num1;
        float num2;
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter the First number");
        num1=scan.nextFloat();
        System.out.println("Enter the Second number");
        num2=scan.nextFloat();
        System.out.println(num1);
        System.out.println(num2);
        System.out.println("\n");
        String prompt = "Enter 0 for Sum,"+ " 1 for difference," + " 2 for multiplication," + "3 for division";
        System.out.println(prompt);
        int input=scan.nextInt();
        switch(input){
            case 0: 
                System.out.println("You have selected to add these numbers."+" and ");
                System.out.print("the result is: ");
                System.out.print(num1+num2);
                break;
            case 1: 
                System.out.println("You have selected to subtract these numbers and ");
                System.out.print("the result is: ");
                System.out.print(num1-num2);
                break;
            case 2: 
                System.out.println("You have selected to multiply these numbers and ");
                System.out.print("the result is: ");
                System.out.print(num1*num2);        
                break;
            case 3: 
                System.out.println("You have selected to divide these numbers and ");
                System.out.print("the result is: ");
                System.out.print(num1/num2);
                break;    
            default:
            System.out.println("Invalid");
            
        }
        
    }
}
