// Contributed by Chanpreet Singh

public class main{

  public static void main(String[] args){
  
    String [] cars = {"Mercedes", "BMW", "Supra", "Civic", "Miata"};
    
    try{
            System.out.println(cars[5]);
        }
    
    catch(Exception e)
    {
            System.out.println(e);
        }
        System.out.println("My Favourite car is: ");
        System.out.println("\n");
        System.out.println(cars[2]);
        
        
    }
}
