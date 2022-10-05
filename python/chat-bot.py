import random

hello = ["hi","How can i help you?", "hello", "good morning,how can i help you?","hello there","hi Pinky"]
bye = ["cya", "see you later","bye" ,"goodbye", "i am Leaving", "have a Good day"]
howare = ["how are you","whats up","how you doing"]
name = ["whats your name","what is your name","do you have any name","what should i call you","name"]
time = ["how can i set your timing?"]
helpme = ["how can i customize you to disconnect?","at what time you disconnect"]


print("*******************************************************\n")

while True:
	a = input('User said -')

	if a.lower() in hello:
		botans = ["Hello !","hi","hi there","welcome","hi, i'm happy you know me","hi , pinky at your service"]
		print('Bot said - '+random.choice(botans)+'\n')

	elif a.lower() in bye:
		botans = ["sad to see you go :(","bye","miss you","Pinky promise me, you come again"]
		print('Bot said - '+random.choice(botans)+'\n')

	elif a.lower() in howare:
		botans = ["I am fine ,thanks ","Happy","I am good"]
		print('Bot said -'+ random.choice(botans)+'\n')

	elif a.lower() in name:
		botans = ["My name is Pinky,","You can call me Pinky","pinky in your service","My friends call me pinky","Pinky form that T&C page"]
		print('Bot said -'+ random.choice(botans)+'\n')

	elif a.lower() in bye:
		botans = ["Sad to see you go :(", "Talk to you later", "Goodbye!","Have a nice Day","Pinky promise me , you come again"]
		print('Bot said -'+random.choice(botans)+'\n')

    elif a.lower() in helpme:
		botans = ["i can help you to destract from me xD","we help people to keep away from social websites for some amount of time","you can use me to get rid from social sites for some while and have fun with your mates ;)" ]
	    print('Bot said - '+random.choice(botans)+'\n' )
	
	else:
		print('Bot said - Sorry What ?''\n')
