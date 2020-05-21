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
holder=c.fetchone()
newLocation=holder
#print(holder[0])
initialLoc=str(holder[0])
currLocation=str(holder[0])
#print(currLocation)
c.execute("SELECT name from object where id=?",initialLoc)
initLocName= ''.join(c.fetchone())
print(initLocName)
commandsRun=0
while(running):
    userInput=input(">")
    if userInput=='N' or userInput=='n':
        if not(newLocation[0] is None):
            if newLocation[0]>=10 and commandsRun>0:
                c.execute("SELECT N from object WHERE id=?",(currLocation,))
                newLocation=c.fetchone()
            else:
                c.execute("SELECT N from object WHERE id=?",currLocation)
                newLocation=c.fetchone()
        if newLocation[0] is None:
            print("You can't go that way")
        else:
            currLocation=str(newLocation[0])
    elif userInput=='E' or userInput=='e':
        if not(newLocation[0] is None):
            if newLocation[0]>=10 and commandsRun>0:
                c.execute("SELECT E from object WHERE id=?",(currLocation,))
                newLocation=c.fetchone()
            else:
                c.execute("SELECT E from object WHERE id=?",currLocation)
                newLocation=c.fetchone()
        if newLocation[0] is None:
            print("You can't go that way")
        else:
            currLocation=str(newLocation[0])
    elif userInput=='S' or userInput=='s':
        if not(newLocation[0] is None):
            if newLocation[0]>=10 and commandsRun>0:
                c.execute("SELECT S from object WHERE id=?",(currLocation,))
                newLocation=c.fetchone()
            else:
                c.execute("SELECT S from object WHERE id=?",currLocation)
                newLocation=c.fetchone()
        if newLocation[0] is None:
            print("You can't go that way")
        else:
            currLocation=str(newLocation[0])
    elif userInput=='W' or userInput=='w':
        if not(newLocation[0] is None):
            if newLocation[0]>=10 and commandsRun>0:
                c.execute("SELECT W from object WHERE id=?",(currLocation,))
                newLocation=c.fetchone()
            else:
                c.execute("SELECT W from object WHERE id=?",currLocation)
                newLocation=c.fetchone()
        if newLocation[0] is None:
            print("You can't go that way")
        else:
            currLocation=str(newLocation[0])
    elif userInput=='U' or userInput=='u':
        if not(newLocation[0] is None):
            if newLocation[0]>=10 and commandsRun>0:
                c.execute("SELECT U from object WHERE id=?",(currLocation,))
                newLocation=c.fetchone()
            else:
                c.execute("SELECT U from object WHERE id=?",currLocation)
                newLocation=c.fetchone()
        if newLocation[0] is None:
            print("You can't go that way")
        else:
            currLocation=str(newLocation[0])
    elif userInput=='D' or userInput=='d':
        if not(newLocation[0] is None):
            if newLocation[0]>=10 and commandsRun>0:
                c.execute("SELECT D from object WHERE id=?",(currLocation,))
                newLocation=c.fetchone()
            else:
                c.execute("SELECT D from object WHERE id=?",currLocation)
                newLocation=c.fetchone()

        if newLocation[0] is None:
            print("You can't go that way")
        else:
            currLocation=str(newLocation[0])
    elif userInput=="Exit" or userInput=="exit":
        print("exiting.....")
        running=0
        break
    elif userInput=="Look" or userInput=="look":
        c.execute("SELECT desc FROM object where id=?",currLocation)
        currDesc=c.fetchone()
        if currDesc[0] is None:
            print("Nothing out of the ordinary")
        else:
            printableDesc=''.join(currDesc)
            print(printableDesc)
    else:
        print("I didn't understand that come again")
   
    if not(newLocation[0]is None):
        if newLocation[0]>=10:
            c.execute("SELECT name from object where id=?",(currLocation,))
            locName=''.join(c.fetchone())
            print(locName)
        else:
            c.execute("SELECT name from object where id=?",currLocation)
            locName=''.join(c.fetchone())
            print(locName)
    commandsRun+=1