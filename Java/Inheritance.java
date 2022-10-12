//Contributed by Chanpreet Singh

class abc{  
void level_1(){
    
    System.out.println("First Level");
    
}  

}  
class tan extends abc

{  

void level_2()
{
    System.out.println("Second level");
    
    }  
    
    
    }  

class puppy extends tan
{  
void level_3()
{
    System.out.println("Third level");
    
    }  

    
}  


class inheritance{  
public static void main(String args[]){  
puppy d=new puppy();  
d.level_1();  
d.level_2();  
d.level_3();  

    
}
    
}  
