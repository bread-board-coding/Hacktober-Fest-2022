import numpy

#return square of the number
def fitness(num):
    return num * num

#conversswapMutation
def conv(arr):
    a = [16, 8, 4, 2, 1]
    sum = 0
    i =0;
    for bit in arr:
        if bit ==1:
            sum += a[i]
        i+=1
    return sum

#populateswapMutation and fitness values
def fitValues(populateswapMutation):
    fitnessValues = []
    for chromosome in populateswapMutation:
        fitnessValues.append( (fitness(conv(chromosome)), 
                            chromosome) )
    
    return fitnessValues

def m_pool(fitnessValues):
    WheelCount = fitnessValues # Here, WheelCount is Roulette Wheel Count
    
    m_pool = []

    # Here, m_pool is Mating Pool

    WheelCount = sorted(sorted(WheelCount, key = lambda x : x[0]), key = lambda x : x[0], reverse = False)
    WheelCount[0] = WheelCount[len(WheelCount) - 1]
    for roulettetuple in WheelCount:
        m_pool.append(roulettetuple[1])
    
    return m_pool  

def cross(p_1, p_2):

# Here, p_1 indicates Parent-1 and p_2 indicates Parent-2

    temp = p_1[3:5]

    p_1 = p_1[0:3]
    p_1 = numpy.concatenate((p_1, p_2[3:5]))

    p_2 = p_2[0:3]
    p_2 = numpy.concatenate((p_2, temp))

    return numpy.array([p_1, p_2])

def twoCross(p_1, p_2):
    temp1 = numpy.copy(p_1)
    temp2 = numpy.copy(p_2)

    p_1[2:4] = temp2[2:4]
    p_2[2:4] = temp1[2:4]
    
    return numpy.array([p_1, p_2])
# crossover
def crossOver(m_pool):
    i =0
    while(i < len(m_pool)-1):
        p_1 = m_pool[i]
        p_2 = m_pool[i+1]
        m_pool[i] = cross(p_1, p_2)[0]
        m_pool[i+1] = cross(p_1, p_2)[1]
        i+=2
    if i%2 != 0:
        p_1 = m_pool[len(m_pool)-1]
        p_2 = m_pool[0]
        m_pool[len(m_pool)-1] = cross(p_1, p_2)[0]
        m_pool[0] = cross(p_1, p_2)[1]

    return m_pool

def twoPointCrossOver(m_pool):
    i =0
    while(i < len(m_pool)-1):
        p_1 = m_pool[i]
        p_2 = m_pool[i+1]
        m_pool[i] = twoCross(p_1, p_2)[0]
        m_pool[i+1] = twoCross(p_1, p_2)[1]
        i+=2
    return m_pool

def bitFlipMutation(m_pool):
    for i in range(len(m_pool)):
        for j in range(5):
            if(m_pool[i][j] == 0):
                m_pool[i][j] = 1

    return m_pool

def swapMutation(m_pool):
    for i in range(len(m_pool)):
        j = 0
        k = 4
        while(j<k):
            if m_pool[i][j] == 0  and m_pool[i][k] == 1 :
                m_pool[i][j] = 1 - m_pool[i][j]
                m_pool[i][k] = 1 - m_pool[i][k]
            else:
                j+=1
                k-=1

    return m_pool

def printAns(populateswapMutation):
    print('------------------------------------------------------------------------------------------------------------')
    print("Final populateswapMutation : ")
    for i in populateswapMutation:
        print(conv(i))
    print('------------------------------------------------------------------------------------------------------------')
    print("Final Fitness values: ")
    
    fitness = fitValues(populateswapMutation)
    max = fitness[0][0]
    for i in range(len(fitness)):
        print(fitness[i][0])
        if(fitness[i][0] > max):
            max = fitness[i][0]
    print('------------------------------------------------------------------------------------------------------------')      
    print("Max fitness : ", max)


noOfChromosomes = int(input("Enter population size(p): "))
noOfGenes = 5
population_size = (noOfChromosomes,noOfGenes)
populateswapMutation = numpy.random.randint(low=0, high=2, size=population_size) 


c  = int(input("Enter the value for crossover(c) 'Enter 0 for one point crossover, 1 for two point crossover': "))
while not(c == 0 or c == 1):
    print("Please type only either of 0 or 1")
    c  = int(input("Enter the value for crossover(c) 'Enter 0 for one point crossover, 1 for two point crossover': "))

m = int(input("Enter the value of (m) (Enter 0 for BitFlip, 1 for Swap Mutation): "))

tc = int(input("Enter the value of (t) (Enter 0 for no improvement for x iterations, 1 for pre-defined iterations) : "))
if(tc == 0):
    iterateswapMutations = int(input("Enter the value for x : "))
else:
    iterateswapMutations = int(input("Enter the pre-defined iteration value  : "))

print("Initial populateswapMutation : ")
for i in range(len(populateswapMutation)):
    print(conv(populateswapMutation[i]))

i =0
while(i<iterateswapMutations):
    if(i == iterateswapMutations - 1):
        print(printAns(populateswapMutation))
    fitnessValues = fitValues(populateswapMutation)
    newpopulateswapMutation = m_pool(fitnessValues)
    if(i<=round(0.6*iterateswapMutations)):
        newpopulateswapMutation = crossOver(newpopulateswapMutation)
    if(m == 0):
        if(i>=round(0.6*iterateswapMutations)):
            newpopulateswapMutation = bitFlipMutation(newpopulateswapMutation)
    if(m == 1):
        if(i>=round(0.6*iterateswapMutations)):
            newpopulateswapMutation = swapMutation(newpopulateswapMutation)
    
    populateswapMutation = newpopulateswapMutation
    print(printAns(populateswapMutation))
    i = i + 1