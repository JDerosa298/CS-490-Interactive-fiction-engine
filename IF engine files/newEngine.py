import sqlite3
import sys

conn = sqlite3.connect('mollys_mansion.db')
c = conn.cursor()

name = ("offscreen",)
c.execute("select desc from object where name=?", name)

p=''.join(c.fetchone())

print(p)

running=1

currLocation=" "

player=("player",)

c.execute("SELECT holder from object where name=?",player)

holder = c.fetchone()

#print(holder[0])

initialLoc=list(holder)

currLocation=list(holder)
#History location for none-type error catching
prevLocation = currLocation
#print(currLocation)

c.execute("SELECT name from object where id=?",initialLoc)
initLocName= ''.join(c.fetchone())
print(initLocName)
none = None
while(running):

#Input getter and direction determinerrrrr
    input= input("Enter ")
    input = str(input.upper())
    if input == "LOOK":
        input = input.lower()
    if input == 'U' or input =='D' or input =='N' or input =='S' or input =='E' or input =='W':
        c.execute("SELECT("+input+") from object WHERE id=?",currLocation)

#Conditional statements
    elif input=="look":
        c.execute("SELECT desc FROM object where id=?",currLocation)
        currDesc=c.fetchone()
        if currDesc[0] is None:
            print("Nothing out of the ordinary")
        else:
            printableDesc=''.join(currDesc)
            print(printableDesc)
    elif input=="Exit" or input=="exit":
        print("exiting.....")
        running=0
        break
    else:
        print("I didn't understand that come again")

#--------------------------------------------------------------------------------------
#None-Type checking for your location variables
    holder = c.fetchone()
    if type(holder) == type(none):
        continue
    currLocation = list(holder)
    if type(currLocation[0]) == type(none):
        print ("Cant go that way dummy")
        currLocation = prevLocation
    else:
        prevLocation = currLocation
#Displays your location variable
    c.execute('SELECT name FROM object WHERE id=?', currLocation)
    print ('\n\n' ,"You are in the", ''.join(c.fetchone()), '\n\n')
