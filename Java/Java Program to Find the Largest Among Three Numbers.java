public class Largest {

    public static void main(String[] args) {

        double n1 = -4.5, n2 = 3.9, n3 = 2.5;

        if( n1 >= n2 && n1 >= n3)
            System.out.println(n1 + " is the largest number.");

        else if (n2 >= n1 && n2 >= n3)
            System.out.println(n2 + " is the largest number.");

        else
            System.out.println(n3 + " is the largest number.");
    }
}
Output

3.9 is the largest number.
In the above program, three numbers -4.5, 3.9 and 2.5 are stored in variables n1, n2 and n3 respectively.

Then, to find the largest, the following conditions are checked using if else statements

If n1 is greater or equals to both n2 and n3, n1 is the greatest.
If n2 is greater or equals to both n1 and n3, n2 is the greatest.
Else, n3 is the greatest.
The greatest number can also be found using a nested if..else statement.

Example 2: Find the largest number among three using nested if..else statement
public class Largest {

    public static void main(String[] args) {

        double n1 = -4.5, n2 = 3.9, n3 = 5.5;

        if(n1 >= n2) {
            if(n1 >= n3)
                System.out.println(n1 + " is the largest number.");
            else
                System.out.println(n3 + " is the largest number.");
        } else {
            if(n2 >= n3)
                System.out.println(n2 + " is the largest number.");
            else
                System.out.println(n3 + " is the largest number.");
        }
    }
}
Output

5.5 is the largest number.
In the above program, instead of checking for two conditions in a single if statement, we use nested if to find the greatest.

Then, to find the largest, the following conditions are checked using if else statements

If n1 is greater or equals to n2,
and if n1 is greater or equals to n3, n1 is the greatest.
else, n3 is the greatest.
Else,
if n2 is greater or equals to both n3, n2 is the greatest.
else, n3 is the greatest.
Share on:
Did you find this article helpful?
Related Examples
Java Example

Find Largest Element of an Array

Java Example

Find GCD of two Numbers

Java Example

Find LCM of two Numbers

Java Example

Check Whether a Number is Positive or Negative


Join our newsletter for the latest updates.
Enter Email Address*
Join


Tutorials
Python 3 Tutorial
JavaScript Tutorial
SQL Tutorial
C Tutorial
Java Tutorial
Kotlin Tutorial
C++ Tutorial
Swift Tutorial
C# Tutorial
Go Tutorial
DSA Tutorial
Examples
Python Examples
JavaScript Examples
C Examples
Java Examples
Kotlin Examples
C++ Examples
Company
About
Advertising
Privacy Policy
Terms & Conditions
Contact
Blog
Youtube
Apps
Learn Python
Learn C Programming
Learn Java
© Parewa Labs Pvt. Ltd. All rights reserved.

   
