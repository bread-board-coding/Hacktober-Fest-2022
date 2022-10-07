# This is a sample code for playing rock paper scissors

from random import randint
def game():
    pc_choice=['rock','paper','scissors']
    choice = randint(1,3)
    print (choice)
    print (pc_choice[choice-1])
    user_input=input('Choose rock or paper or scissors: ')
    if user_input==pc_choice[choice-1]:
        print ('Draw')
        return 
    else :
        if (user_input=='rock' and pc_choice[choice-1]=='scissors'):
            print ('Human won')
            return
        else:
            print ('PC won')
            return
        if (user_input=='paper' and pc_choice[choice-1]=='rock'):
            print ('Human won')
            return
        else:
            print ('PC won')
            return
        if (user_input=='scissors' and pc_choice[choice-1]=='paper'):
            print ('Human won')
            return
        else:
            print ('PC won')
            return
game()
again= input('Do you want to play again? ')
while again=='yes':     
    game()
