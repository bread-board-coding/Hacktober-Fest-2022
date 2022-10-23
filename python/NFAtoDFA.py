import pandas as pd  # using pandas library to create tables of nfa and dfa

nfa = {}                                 
no_states = int(input("No. of states : "))            
transitions = int(input("No. of transitions : "))       
for i in range(no_states):  
    state = input("state name : ")            
    nfa[state] = {}                          
    for j in range(transitions):
        path = input("path : ")               
        print("Enter end state from state {} travelling through path {} : ".format(state,path))
        reaching_state = [x for x in input().split()]  
        nfa[state][path] = reaching_state    


print("\nNFA Dictionary : \n")
print(nfa)                                    
print("\nPrinting NFA table : ")
nfa_table = pd.DataFrame(nfa)
print(nfa_table.transpose())                 # using transpose function to convert dictionary into table

print("Enter final state of NFA : ")
nfa_final_state = [x for x in input().split()]      
                
new_states_list = []                          
dfa = {}                                      
keys_list = list(list(nfa.keys())[0])              # writing states in the dictionary   
path_list = list(nfa[keys_list[0]].keys())         # creating paths through the states in dictionary



dfa[keys_list[0]] = {}                        
for y in range(transitions):
    var = "".join(nfa[keys_list[0]][path_list[y]])  
    dfa[keys_list[0]][path_list[y]] = var            
    if var not in keys_list:                        
        new_states_list.append(var)                  
        keys_list.append(var)                      
        

while len(new_states_list) != 0:                     
    dfa[new_states_list[0]] = {}                     
    for t in range(len(new_states_list[0])):
        for i in range(len(path_list)):
            temp = []                               
            for j in range(len(new_states_list[0])):
                temp += nfa[new_states_list[0][j]][path_list[i]] 
            s = ""
            s = s.join(temp)                        
            if s not in keys_list:                  
                new_states_list.append(s)           
                keys_list.append(s)                
            dfa[new_states_list[0]][path_list[i]] = s  
        
    new_states_list.remove(new_states_list[0])     
     

print("\nDFA Dictionary: \n")    
print(dfa)                                          
print("\nPrinting DFA table : ")
dfa_table = pd.DataFrame(dfa)
print(dfa_table.transpose())            # using transpose function to convert dictionary into table

dfa_states_list = list(dfa.keys())
dfa_final_states = []
for x in dfa_states_list:
    for i in x:
        if i in nfa_final_state:
            dfa_final_states.append(x)
            break
        
print("\nFinal states of the DFA are : ",dfa_final_states)  