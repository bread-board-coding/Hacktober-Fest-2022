#!/usr/bin/env python
# coding: utf-8

# In[ ]:


#importing random library to generate random 3 digits number
import random

#class in which all the attributes and constant will be initialize
class data_input:
   def __init__(self):
       #people in event
       self.adults = int(input("Enter the number of adults: "))
       self.childs = int(input("Enter the number of childrens: "))
       self.deposit = int(input("Enter the deposit amount: "))
       
       #constants meals
       self.deluxmeal = 25.95
       self.standardmeal = 21.75
       
       #hall prices as constants
       self.hallA = 1000.00
       self.hallB = 850.00
       self.hallC = 750.00
       self.hallH = "is home"
       
       #Invoice number
       self.invoice = random.randrange(1,999)
       #letting user select meal type
       print("\nChoose the meal type \n\t(a) Delux meal ${}/person  \n\t(b) Standard meal ${}/person ".format(self.deluxmeal,self.standardmeal))
       self.meal = input("Your answer: ")
       
       #letting user select hall type
       print("\nChoose the hall type \n\t(a) Hall– A ${} \n\t(b) Hall– B ${} \n\t(c) Hall– C ${} \n\t(h) Hall– H ${} ".format(self.hallA,self.hallB,self.hallC,self.hallH))
       self.venue = input("Your answer: ")
       
       #Either catering on a weekend or not
       self.weekend = input("Is catering on a weekend? ")
       
       #Discounts
       print("There is special discount if you pay within 10 days")
       print("Discount: \n\t(a) bill < $1000.00 the discount is  2%\n\t(b) bill < $2000.00 the discount is  4%\n\t(c) bill < $5000.00 the discount is  5%\n\t(d) bill > $5000.00 the discount is  7%")
       self.speedypay = input("Do you agree to pay within 10 days to avail discount?: ")
       
       if self.speedypay == "yes" or self.speedypay == "y" or self.speedypay == "Y" or self.speedypay == "Yes":
           print("Great choice! your discount will be shown at the end of the receipt")

#class for the calculation and displaying receipt
class calculations(data_input):
   #method for calculating meal cost
   def mealcost(self):
       
       #calculation for meal price if meal is delux 
       if self.meal == "a" or self.meal == "D" or self.meal == "Delux":
           
           #calculation for meal price if meal is delux and catering is on week end
           if self.weekend == "Y" or self.weekend == "yes" or self.weekend == "y" or self.weekend == "Yes":
               self.total_mealcost_adults = self.adults * self.deluxmeal
           
               self.total_mealcost_childrens = (self.childs * (self.deluxmeal*.50))
               
               self.total_mealcost = (self.total_mealcost_childrens + self.total_mealcost_adults)
               
               self.surcharge = self.total_mealcost*.10
               
               self.gratuity = self.total_mealcost*.20
               
               self.total = self.total_mealcost + self.surcharge + self.gratuity
               
               
               
               return round(self.total,2)
           #calculation for meal price if meal is delux and catering is NOT on weekend
           elif self.weekend == "N" or self.weekend == "no" or self.weekend == "n" or self.weekend == "No":
               self.total_mealcost_adults = self.adults * self.deluxmeal

               self.total_mealcost_childrens = self.childs * (self.deluxmeal*.50)
               
               self.total_mealcost = (self.total_mealcost_childrens + self.total_mealcost_adults)

               self.gratuity = self.total_mealcost*.20
               
               self.total = self.total_mealcost + self.gratuity
               
               
               
               return round(self.total,2)
       
       #calculation for meal price if meal is standard 
       elif self.meal == "b" or self.meal == "S" or self.meal == "Standard":
           
           #calculation for meal price if meal is standard and catering is on weekend
           if self.weekend == "Y" or self.weekend == "yes" or self.weekend == "y"  or self.weekend == "yes" or self.weekend == "Yes": 
                                       
               self.total_mealcost_adults = self.adults * self.standardmeal
                                       
               self.total_mealcost_childrens = (self.childs * (self.standardmeal*.50))
                                       
               self.total_mealcost = (self.total_mealcost_childrens + self.total_mealcost_adults)
               
               self.surcharge = self.total_mealcost*.10
               
               self.gratuity = self.total_mealcost*.20
               
               self.total = self.total_mealcost + self.surcharge + self.gratuity
               
               return round(self.total,2)
           
           #calculation for meal price if meal is standard and catering is NOT on weekend
           elif self.weekend == "N" or self.weekend == "no" or self.weekend == "n"  or self.weekend == "No":
               self.total_mealcost_adults = self.adults * self.standardmeal
                                       
               self.total_mealcost_childrens = (self.childs * (self.standardmeal*.50))
               
               self.total_mealcost = (self.total_mealcost_childrens + self.total_mealcost_adults)
                                       
               self.gratuity = self.total_mealcost*.20
               
               self.total = self.total_mealcost + self.gratuity

               return round(self.total,2)
            
   #mrthod for displaying receipt    
   def display(self):
       print("\n\n")
       
       #making test bold and decoration
       print("\33[1m" + "/-"*30,end="")
       print("/")

       #Header, center align
       print("Caswell Catering and Convention Services".center(61))
       print("Final Bill".rjust(36),end="")

       print("Invoice Number#{:03}".rjust(26).format(self.invoice))

       #end of header
       print("/-"*30,end="")
       print("/")

       #aligning text 
       gap = "".ljust(4)
       
       
       #Start of first section
       #Displaying first section of the receipt 
       print(gap,"Number of adults:".ljust(20),self.adults)
       print(gap,"Number of children:".ljust(20),self.childs)
       
       #Gratuity
       print(gap,"Gratuity:".ljust(20),"20%")

       if self.weekend == "Y" or self.weekend == "yes" or self.weekend == "y"  or self.weekend == "yes" or self.weekend == "Yes": 
           print(gap,"Weekend:".ljust(20),"Yes")
           
       elif self.weekend == "N" or self.weekend == "no" or self.weekend == "n" or self.weekend == "No":
           print(gap,"Weekend:".ljust(20),"No")


       #Displaying meal cost based on the user selection
       if self.meal == "a" or self.meal == "D" or self.meal == "Delux":
           print(gap,"Cost per delux meal for adult:".ljust(32),"${}".format(self.deluxmeal))
           print(gap,"Cost per delux meal for child:".ljust(32),"${:.2f}".format(self.deluxmeal*.50))
       elif self.meal == "b" or self.meal == "S" or self.meal == "Standard":
           print(gap,"Cost per standard meal for adult:".ljust(32),"${}".format(self.standardmeal))
           print(gap,"Cost per standard meal for child:".ljust(32),"${:.2f}".format(self.standardmeal*.50))
           
       #End of first section
       print(gap,"-"*45)
       
       #Start of second section
       print(gap,"Total cost for adult meals:".ljust(32),"${:.2f}".format(self.total_mealcost_adults))
       print(gap,"Total cost for child meals:".ljust(32),"${:.2f}".format(self.total_mealcost_childrens),end="\n\n")
       print(gap,"Total food cost:".ljust(32),"${:.2f}".format(self.total_mealcost))
       
       

       
       #End of second section
       print(gap,"-"*45)
       
       #Start of third section
       print(gap,"Gratuity:".ljust(32),"${:.2f}".format(self.gratuity))




       #Displaying Hall type and price based on user selection
       #Also calculating subtotal 
       if self.venue == "C" or self.venue == "c":
           print(gap,"Hall C-Room fee:".ljust(32),"${:.2f}".format(self.hallC))
           self.Taxes = ((self.total - self.gratuity)+self.hallC)*0.06875

           subtotal = self.total + self.hallC + self.Taxes

       elif self.venue == "A" or self.venue == "a":
           print(gap,"Hall A-Room fee:".ljust(32),"${:.2f}".format(self.hallA))
           self.Taxes = ((self.total - self.gratuity)+self.hallA)*0.06875
           
           subtotal = self.total  + self.hallA + self.Taxes
           
       elif self.venue == "B" or self.venue == "b":
           print(gap,"Hall B-Room fee:".ljust(32),"${:.2f}".format(self.hallB))
           self.Taxes = ((self.total - self.gratuity)+self.hallB)*0.06875
           
           subtotal = self.total + self.hallB + self.Taxes
           
       elif self.venue == "H" or self.venue == "h":
           print(gap,"Hall H-Room fee:".ljust(32),"${:.2f}".format(0))
           self.Taxes = ((self.total - self.gratuity))*0.06875
           
           subtotal = self.total  +  self.Taxes
           
       #calculating and displaying weekend charges if event is on weekend
       if self.weekend == "Y" or self.weekend == "yes" or self.weekend == "y"  or self.weekend == "yes" or self.weekend == "Yes":

           print(gap,"Weekend charge:".ljust(32),"${:.2f}".format(self.surcharge))
           
           
       #Calculating and displaying taxes
       print(gap,"Taxes".ljust(32),"${:.2f}".format(self.Taxes))
       
       #End of third section
       print(gap,"-"*45)




       #Start of 4rth section
       
       #Displaying subtotal
       print(gap,"Subtotal".ljust(32),"${:.2f}".format(subtotal),end="\n\n")
       
       #Substracting deposit amount
       print(gap,"Less deposit".ljust(32),"${:.2f}".format(self.deposit))

       #Substracting speedy pay discount from subtotal based on the given condition
       if self.speedypay == "yes" or self.speedypay == "y" or self.speedypay == "Y" or self.speedypay =="Yes":

           if subtotal < 1000.00:
               discount = subtotal * .02
           elif subtotal < 2000.00:
               discount = subtotal * .04
           elif subtotal < 5000.00:
               discount = subtotal * .05
           elif subtotal > 5000.00:
               discount = subtotal * .07

           print(gap,"Less speedypay".ljust(32),"${:.2f}".format(discount))
           
           print("")
           
           #Displaying the due Ballance after discount
           print(gap,"Ballance Due:".ljust(32),"${:.2f}".format(subtotal-discount-self.deposit))
       else:
           #Displaying the due Ballance without discount
           print("")
           print(gap,"Ballance Due:".ljust(32),"${:.2f}".format(subtotal-self.deposit))
       
       #End of script and 4rth section
       
       #Footer
       print("/-"*30,end="")
       print("/")
       print("Thank you for using Caswell Catering".center(61),end="\n\n")
       
#Creating objects and calling functions
obj = calculations()
obj.mealcost()
obj.display()        
       
       
       
       
       

