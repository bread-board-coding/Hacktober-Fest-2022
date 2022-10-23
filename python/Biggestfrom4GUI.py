import tkinter as tk
from tkinter import *
from turtle import color


def updateLabel(largest, smallest):
    txt = "Largest is " + str(largest) + " and Smallest is " + str(smallest)
    label.config(text=txt)


def inputList():
    inputList = insert_n.get()
    lst = inputList.split(',')  # split the string into list
    listOfNums = [int(index) for index in lst]  # convert to integer
    # calculate smallest and largest
    smallest = 999999
    largest = 0
    for i in listOfNums:
        if i > largest:
            largest = i
        if i < smallest:
            smallest = i
    updateLabel(largest, smallest)


window = Tk()
window.geometry('300x400')
window.title('Summation')

insert_n = tk.Entry(window)
insert_n.pack()


greeting = Label(window, text="Enter 4 seperated numbers:")
button = tk.Button(window, text='Calculate',
                   command=inputList, bg='green', fg='White')
label = Label(window, text="")

greeting.pack()
button.pack()
label.pack()

window.mainloop()
