#John DeRosa CS-490
#Spring 2019
#IFE V1 
#this program reads in an sqlite3 database
#the database is assumed to be formatted correctly 
#this code allows the user to walk around rooms and look at them
#not much else is done in this code
#the only commands supported are N,E,W,S,U,D and look
#there is no support for getting or looking at items

import sqlite3
import sys

#getting the "OFFSCREEN" information that is always initially printed out
conn = sqlite3.connect(sys.argv[1])
c = conn.cursor()
name = ("offscreen",)
c.execute("select desc from object where name=?", name)
p=''.join(c.fetchone())
print(p)
running=1
player=("player",)
c.execute("SELECT holder from object where name=?",player)
holder=c.fetchone()
none=None
currLocation=list(holder)

#starting the game loop
while(running):
    #asking the user for a command
    userInput=input(">")
    userInput=str(userInput.upper())
    
    
    if userInput=="LOOK":
        userInput="look"
    #grabbing info about the direction the user has chosen
    # if they cannot move there they will be told later on
    if userInput=='N' or userInput=='S' or userInput=='E' or userInput=='W' or userInput=='U'or userInput=='D':
        preLoc=currLocation
        c.execute("select("+userInput+")from object where id=?",currLocation)
        newLoc=list(c.fetchone())
        currLocation=newLoc
    # describing what the room looks like to the user
    elif userInput=="look":
        c.execute("SELECT desc FROM object where id=?",currLocation)
        currDesc=c.fetchone()
        #if there is no desc use a generic one
        if currDesc[0] is None:
            print("Nothing out of the ordinary")
        #otherwise use the one the author intended
        else:
            printableDesc=''.join(currDesc)
            print(printableDesc)
    #if the user types exit exit the game
    elif userInput=="EXIT":
        print("exiting.....")
        running=0
        break
    # if the command is unknown tell the user
    else:
        print("I didn't understand that come again")
    
    #if the user cant go in that direction tell them and reset
    if type(currLocation[0])==type(none):
        print("you cant go that way")
        currLocation=preLoc
    
    #tell the user their current location after moving
    else:
        c.execute('SELECT name FROM object WHERE id=?', currLocation)
        locName=''.join(c.fetchone())
        print(locName)