#John DeRosa CS-490
#Spring 2019
#IFE V2 
#this program reads in an sqlite3 database
#the database is assumed to be formatted correctly by the author of the game
#this code allows the user to walk around rooms and look at them
#it also allows the user to look at/examine items and rooms
#The user can also now drop and pick up items if the author deems them as getable.
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

c.execute("SELECT MAX(id) FROM object")
MAX_ID=c.fetchone()
MAX_OBJ=int(MAX_ID[0])+1

c.execute("SELECT MAX(id) FROM verbs")
MAX_ID=c.fetchone()
MAX_VERB=int(MAX_ID[0])+1
tempUserVerb=""
#starting the game loop
while(running):
    #asking the user for a command
    userInput=input(">")
    nonUpperInput=userInput
    userInput=str(userInput.upper())
    userVerb=""
    tempUserVerb=""
    AVC=""
    #loop that determines what command that user is trying to use
    #this will convert the synonyms to the actual command that the user is trying to use
#######################################################
###PARSING FOR THE VERBS/SYNONYMS#############################
#######################################################
    for x in range(MAX_VERB):
        idNum=str(x)
        L_idNum=(idNum,)
        c.execute("SELECT verb FROM verbs WHERE id=?",L_idNum)
        verb=list(c.fetchone())
        if verb[0] in nonUpperInput:
            if nonUpperInput.find(verb[0])==0:
                #print(verb[0])
                index=nonUpperInput.find(verb[0]) 
                tempUserVerb=verb[0]
            if len(tempUserVerb)>len(userVerb):
                userVerb=tempUserVerb
            passable_userVerb=(userVerb,)
            c.execute("SELECT verb_id FROM verbs where verb=?",passable_userVerb)
            actualCommandID=c.fetchone()
            #print(actualCommandID[0])
            if type(none)!=type(actualCommandID):
                list_actualCommandID=(actualCommandID,)
                c.execute("SELECT verb FROM verbs where id=?",actualCommandID)
                AVC=c.fetchone()
                #print(AVC[0])
    
    #print("USER VERB:",userVerb)
    #print("SYNONYM: ",AVC[0])
    offSet=len(userVerb)
    #print("LENGTH:",offSet)


#######################################################
###PARSING FOR THE OBJECTS#############################
#######################################################
    inputSub=nonUpperInput[(offSet+1):]
    #print(inputSub)
    tempOBJ=""
    userOBJ=""
    actualOBJ=""
    passableOBJ=""
    actualOBJid=("",)
    if inputSub!="":
        for x in range(MAX_OBJ):
            idNum=str(x)
            L_idNum=(idNum,)
            c.execute("SELECT name FROM object where id=?",L_idNum)
            OBJ=list(c.fetchone())
            #print(OBJ[0])
            if OBJ[0] in inputSub:
                tempOBJ=OBJ[0]
                if len(tempOBJ)>len(userOBJ):
                    userOBJ=tempOBJ
                passableOBJ=(userOBJ,)
                c.execute("SELECT id FROM object where name=?",passableOBJ)
                actualOBJid=c.fetchone()
    #if type(none)!=type(actualOBJid[0]):
        #print(actualOBJid[0])
    #print(actualOBJid[0])
    if AVC!="":
        if AVC[0]=="look" and (actualOBJid[0]!=""):
            c.execute("select holder from object where id=?",actualOBJid)
            OBJholder=c.fetchone()
            if(currLocation[0]==OBJholder[0]):
                c.execute("select desc from object where id=?",actualOBJid)
                itemDesc=c.fetchone()
                if itemDesc[0]:
                    print(itemDesc[0])
                else:
                    print("This item is rather hard to describe")
            else:
                print("You can't see that right now.")


        elif AVC[0]=="look" and actualOBJid[0]=="":
            itemFound=1
            c.execute("SELECT desc FROM object where id=?",currLocation)
            roomDesc=c.fetchone()
            if roomDesc[0]:
                print(roomDesc[0])
                print("")
            else:
                print("I'm not quite sure how to describe this place.")
                print("")
            print("You can see:")
            for t in range(MAX_OBJ):
                tID=(str(t),currLocation[0])
                c.execute("SELECT name, short_desc FROM object where id=? and name!='player' and holder=?",tID)
                lookRoom=c.fetchone()
                c.execute("SELECT desc FROM object where id=?",currLocation)
                roomDesc=c.fetchone()
                if type(lookRoom)!=type(none):
                    itemFound=0
                    print(lookRoom[0],lookRoom[1])
                elif itemFound and t==(MAX_OBJ-1) :
                    print("Nothing of interest.")
            print("")


        if AVC[0]=="examine" and (actualOBJid[0]!=""):
            c.execute("select holder from object where id=?",actualOBJid)
            OBJholder=c.fetchone()
            if(currLocation[0]==OBJholder[0]):
                c.execute("select first_time_desc from object where id=?",actualOBJid)
                itemExamine=c.fetchone()
                if itemExamine[0]:
                    print(itemExamine[0])
                    print("")
                else:
                    print("Not much more to this item")
                    print("")
            else:
                print("You can't see that right now.")
                print("")

        elif AVC[0]=="examine" and actualOBJid[0]=="":
            c.execute("select first_time_desc from object where id=?",currLocation)
            roomFirst=c.fetchone()
            if roomFirst[0]:
                print(roomFirst[0])
                print("")


        
        if AVC[0]=="get" and not(actualOBJid[0]):
            print("You didnt name an item to get.")
            print("")
        elif AVC[0]=="get" and actualOBJid!="":
            c.execute("select is_getable from object where id=?",actualOBJid)
            getable=c.fetchone()
            if getable[0]==0:
                print("This item cant be picked up")
            else:
                c.execute("UPDATE object SET holder=1 where id=?",actualOBJid)


        if AVC[0]=="drop" and not(actualOBJid[0]):
            print("You didnt name an item to drop.")
            print("")
        elif AVC[0]=="drop" and actualOBJid[0]:
            c.execute("SELECT holder from object where id=?", actualOBJid)
            dropable=c.fetchone()
            #print(type(dropable[0]))
            if dropable[0]==1:
                updater=(currLocation[0],actualOBJid[0])
                c.execute("UPDATE object SET holder=? where id=?",updater)
            else:
                print("You cant drop that item")
                print("")

        
        if AVC[0]=='n' or AVC[0]=='s' or AVC[0]=='e' or AVC[0]=='w' or AVC[0]=='u'or AVC[0]=='d':
            UpperAVC=AVC[0].upper()
            preLoc=currLocation
            c.execute("select("+UpperAVC+")from object where id=?",currLocation)
            newLoc=list(c.fetchone())
            currLocation=newLoc
        if type(currLocation[0])==type(none):
            print("you cant go that way")
            print("")
            currLocation=preLoc
        
        #tell the user their current location after moving
        else:
            c.execute('SELECT name FROM object WHERE id=?', currLocation)
            locName=''.join(c.fetchone())
            print("You are in the",locName)
            print("")
    else:
        print("sorry i didnt understand come again")
        c.execute('SELECT name FROM object WHERE id=?', currLocation)
        locName=''.join(c.fetchone())
        print("You are in the",locName)
        print("")

