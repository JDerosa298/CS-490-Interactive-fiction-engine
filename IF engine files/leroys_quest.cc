#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include<vector>

using namespace std;

int current_event= 0;
int score=0;
string operand="";
bool locations_visited[8]={0};
bool acomplishments[]={0};
bool command_entered = false;
bool gameRunning = true;
bool itemsGained[7]={false};
bool pay_chasm=false;
bool pay_well=false;
// item codes
int handle = 0;
int key = 1;
int fish = 2;
int redX = 3;
int shovel = 4;
int mirror = 5;


// location codes
int leroys_tower = 0;
int treasureland = 1;
int braids = 2;
int falcons_keep = 3;
int red_chasm = 4;
int wish_well = 5;
int heavens_peak = 6;
int mermaid_cove = 7;
// need to make a code for each state ie transition or move
// codes for each item all stored as ints
bool hasKey=false;
bool hasHandle=false;
bool hasShovel=false;


struct location
{
string name;
int place_id;
string items [15];
void (*desc)(void);
void (*con_desc)(void);
void (*handle)(string,string);
};

struct player
{
    int current_location;
    string inventory [15];
    int coins;
    void player_desc();
    void INV();
};

//the players inventory function
void player::INV()
{
    int i=0;
    cout<<"Your inventory currently contains."<<endl;
    for (i=0;i<15;i++)
        {
            cout<<inventory[i]<<endl;
        }
    cout<<"And "<<coins<<" coins."<<endl;

}

void player::player_desc()
{
 std::cout<<"You are and individual of average height and you have no physical features that stand out. The garb that you are wearing is of superior quality. It is embroidered with what appears to be a seal that resembles an acorn. In your pocket there is 6 gold coins";
};
//overloaded functions for leroys tower
void handleForTower(string event, string operand);
void descForTower(void);
void conDescForTower(void);
void prgrmExit(void);
//*******************************
void handleForTland(string event, string operand);
//*******************************
void handleForBraids(string event, string operand);
//*******************************
void handleForWW(string event, string operand);
void handleForChasm(string event,string operand);
void handleForHP(string event,string operand);
void handleForMM(string event,string operand);
void handleForFK(string event,string operand);
//BEGINNING OF THE ACTUAL PROGRAM HERE!!!!!!!!!!!!!!!!!!!!
//THIS MARKS THE START OF CODE THAT WILL ACTUALLY RUN THE GAME
//CODE ABOVE THIS SECTION IS FOR DECLERATION PURPOSES
void help();
void exiter();
int current_location=-1;
location leroysTower;
location treasureLand;
location Braids;
location falconsKeep;
location redChasm;
location wishWell;
location heavensPeak;
location mermaidCove;

player LEROY;



int main (void)
{
// creating an instance of location that will be a copy of the current location

// block of initializing each location with its needed data to function in the game
current_location=leroys_tower;
leroysTower.place_id= leroys_tower;
leroysTower.handle= &handleForTower;
leroysTower.desc= &descForTower;
leroysTower.name= "Leroy's Tower";
LEROY.player_desc();
LEROY.coins=6;
treasureLand.handle=&handleForTland;
Braids.handle=&handleForBraids;
redChasm.handle=&handleForChasm;
wishWell.handle=&handleForWW;
heavensPeak.handle=&handleForHP;
mermaidCove.handle=&handleForMM;
falconsKeep.handle=&handleForFK;
//a place to store the text that the user will be input

locations_visited[leroys_tower]=true;
current_location=leroys_tower;
bool running =true;
string  test_string="";
string  test_string_copy="";
string event = "";
string operand = "";
 while(running)
    {
     // statement to check if this is the first command the the user has entered
        if (command_entered == false)
        {
        std::cout<<"You awake beside a large pyramid structure. Laying next to you there is a broken coconut. You suddenly feel a sharp pain in your head.You come to the realization that you don't remember your own name."<< endl;
        std::cout<<">";
        getline(cin,test_string);
        //std::cin>> test_string;
        test_string_copy=test_string;
            if (!test_string.empty())
                {
                    if(!test_string.find(" "))
                    {
                        test_string.append(" ");
                    }
                    command_entered = true;
                    //transform(test_string.begin(), test_string.end(),test_string.begin(),::tolower);
                    for(int go=0;go<test_string.length();go++)
                    {
                        test_string[go]=tolower(test_string[go]);
                    }
                    event = test_string.substr(0,test_string.find(' '));
                    operand = test_string_copy.substr(test_string_copy.find(' '), test_string_copy.length()-1);
                    cout<<operand<<endl;
                    if(event=="exit")
                    {
                        exiter();
                    }
                    else if(event=="help")
                    {
                        help();
                    }

                    switch(current_location)
                    {
                        case 0:
                            leroysTower.handle(event,operand);
                            break;
                        case 1:
                            treasureLand.handle(event,operand);
                            break;
                        case 2:
                            Braids.handle(event,operand);
                            break;
                        case 4:
                            redChasm.handle(event,operand);
                            break;
                        case 5:
                            wishWell.handle(event,operand);
                            break;
                        case 6:
                            heavensPeak.handle(event,operand);
                            break;
                        case 7:
                            mermaidCove.handle(event,operand);
                            break;
                        case 3:
                            falconsKeep.handle(event,operand);
                            break;


                    }

                }


        }
        else
        {
        std::cout<<">";
        std::cin >> test_string;
        test_string_copy=test_string;
            if (!test_string.empty())
                {
                    command_entered = true;
                    //transform(test_string.begin(), test_string.end(),test_string.begin(),::tolower);
                    for(int go=0;go<test_string.length();go++)
                    {
                        test_string[go]=tolower(test_string[go]);
                    }
                    event = test_string.substr(0,test_string.find(' '));
                    operand = test_string_copy.substr(test_string_copy.find(' '), test_string_copy.length()-1);
                    if(event=="exit")
                    {
                        exiter();
                    }
                     else if(event=="help")
                    {
                        help();
                    }

                    switch(current_location)
                    {
                        case 0:
                            leroysTower.handle(event,operand);
                            break;
                        case 1:
                            treasureLand.handle(event,operand);
                            break;
                        case 2:
                            Braids.handle(event,operand);
                            break;
                        case 4:
                            redChasm.handle(event,operand);
                            break;
                        case 5:
                            wishWell.handle(event,operand);
                            break;
                        case 6:
                            heavensPeak.handle(event,operand);
                            break;
                        case 7:
                            mermaidCove.handle(event,operand);
                            break;
                        case 3:
                            falconsKeep.handle(event,operand);
                            break;


                    }
                }
        }
}
return(0);
}




void handleForTower(string event, string operand)
{   int i=0;

    if(event=="n" || event=="N" )
    {
        cout<<"if you head that way you'll hit then ocean"<<endl;
    }
    else if (event=="s"||event=="S")
    {
       cout<<"It appears that theres nothing but a mound in your way in that direction"<<endl;
    }
     else if (event=="e"||event=="E")
    {
       cout<<"If you head too far that way you'll fall into the sea."<<endl;
    }
     else if (event=="w"||event=="W"|| event=="sw" || event=="SW")
    {
        if(locations_visited[red_chasm]==false)
            {
                cout<<"You appear at a giant red swirling hole in the ground. You see a sign that reads Welcome to The Red Chasm. Where all men pay their debts."<<endl;
                locations_visited[red_chasm]=true;
                current_location=red_chasm;
            }
        else
            {
                cout<<"You're back at The Red Chasm;"<<endl;
                current_location=red_chasm;
            }
    }
     else if (event=="ne"||event=="NE")
    {
       if(locations_visited[treasureland]==false)
            {
                cout<<"In front of you is a massive forest. There is a sign that reads Treasureland. At your feet you see a red x"<<endl;
                locations_visited[treasureland]=true;
                current_location=treasureland;
            }
        else
            {
                cout<<"You have returned to Treasureland"<<endl;
                current_location=treasureland;
            }
    }
     else if (event=="nw"||event=="NW")
    {
       if(locations_visited[heavens_peak]==false)
            {
                cout<<"You stand in awe of the massive Heavenly peaks. At the base of these peaks you see a camp with tools strewn everywhere "<<endl;
                locations_visited[heavens_peak]=true;
                current_location=heavens_peak;
            }
        else
            {
                cout<<"You have returned to Heaven's Peak."<<endl;
                current_location=heavens_peak;
            }
    }
     else if (event=="se"||event=="SE")
    {
       if(locations_visited[braids]==false)
            {
                cout<<"Before you there are numerous weird structures. However,one of these braid like buildings appears to be a black smith's shop you enter."<<endl;
                locations_visited[braids]=true;
                current_location=braids;
            }
        else
            {
                cout<<"You have returned to Braids Blacksmithing."<<endl;
                current_location=braids;
            }
    }


    //code for the go event/ command
   else if ((event=="GO"||event=="go") && !(operand.empty()) )
    {
        if( operand.substr(0)=="t" && (operand.substr(operand.length()-1))=="d")
        {

            if(locations_visited[treasureland]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
                current_location=treasureland;
            }
            else
            {
                cout<<"You have returned to Treasureland"<<endl;
                current_location=treasureland;
            }
        }
         else if( operand.substr(0)=="b" && (operand.substr(operand.length()-1))=="s")
        {

            if(locations_visited[braids]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to Braids Blacksmithing."<<endl;
               current_location=braids;
            }
        }
         else if(operand.substr(0)=="l" && (operand.substr(operand.length()-1))=="r")
        {

            if(locations_visited[leroys_tower]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to the Tower."<<endl;
               current_location=leroys_tower;
            }
        }
         else if(operand.substr(0)=="f" && (operand.substr(operand.length()-1))=="p")
        {

            if(locations_visited[falcons_keep]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to Falcons Keep"<<endl;
               current_location=falcons_keep;
            }
        }
         else if( operand.substr(0)=="h" && (operand.substr(operand.length()-1))=="k")
        {

            if(locations_visited[heavens_peak]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to Heavens Peak"<<endl;
               current_location=heavens_peak;
            }
        }
        else if( operand.substr(0)=="r" && (operand.substr(operand.length()-1))=="m")
        {

            if(locations_visited[red_chasm]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to The Red Chasm."<<endl;
               current_location=red_chasm;
            }
        }
        else if( operand.substr(0)=="w" && (operand.substr(operand.length()-1))=="l")
        {

            if(locations_visited[wish_well]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to The Wish Well"<<endl;
               current_location=wish_well;
            }
        }
        else if( operand.substr(0)=="m" && (operand.substr(operand.length()-1))=="e")
        {

            if(locations_visited[mermaid_cove]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to Mermaid Cove"<<endl;
               current_location=mermaid_cove;
            }
        }
    // the get command
    else if((event=="get" || event=="Get") && !operand.empty())
        {

            for(i=0;i<15;i++)
            {
                if(leroysTower.items[i]==operand && LEROY.inventory[i]=="")
                {
                    LEROY.inventory[i]=leroysTower.items[i];
                    leroysTower.items[i]="";
                }
                else if ((leroysTower.items[i]==operand)&& !(LEROY.inventory[i]==""))
                {
                    int k = i;
                    for (k=i;k<7;k++)
                    {
                        if(LEROY.inventory[k]=="")
                        {
                            LEROY.inventory[k]=leroysTower.items[i];
                            leroysTower.items[i]="";
                            itemsGained[i]=true;
                            k=7;
                        }
                         else
                        {
                            cout<<"This item isn' t available here."<<endl;
                            k=7;
                        }
                    }

                }

            }

        }

    // the drop command
    else if((event=="drop" || event=="Drop") && !operand.empty())
        {
            for(i=0;i<7;i++)
            {
                if((LEROY.inventory[i]==operand)&& (leroysTower.items[i]==""))
                {
                    leroysTower.items[i]=LEROY.inventory[i];
                    LEROY.inventory[i]= "";
                    itemsGained[i]=false;
                }
                else if ((LEROY.inventory[i]==operand)&& !(leroysTower.items[i]==""))
                {
                    int j = i;
                    for(j=i;j<15;j++)
                        {
                            if(leroysTower.items[j]=="")
                            {
                                leroysTower.items[j]=LEROY.inventory[i];
                                LEROY.inventory[i]= "";
                                itemsGained[i]=false;
                                j=7;
                            }
                            else
                            {
                                cout<<"This item can't be dropped at this time"<<endl;
                                j=7;
                            }
                        }
                }


            }

        }
        // the use command

    else if (event == "use" || event =="Use")
        {

            if(operand=="key"&& itemsGained[key]==true)
                {
                    cout<<"You unlock the door to the pyramid. A man greets you by saying. Welcome home Leroy! We've been awaiting your return since you were hit on the head with a coconut mere inches outside this door."<<endl;
                }
            else
                {
                    cout<<"You try to open the door but it is locked. Where is the key??"<<endl;
                }

        }
    else if(event=="look" || event=="Look")
    {
        if(operand=="door")
        {
            cout<<"In front of the pyramid like structure theres a solid door which appears to be made of steel. It's locked."<<endl;
        }
        else if (operand=="handle"&& itemsGained[handle]==true)
        {
            cout<<"This appears to be a very well made handle that any tool maker would love to turn into a full tool. However, being that the handle doesn't have anything attached to it it is currently useless."<<endl;
        }
        else if (operand=="key" && itemsGained[key]==true)
        {
            cout<<" You notice that the key is made of solid steel and has an acorn crest etched into it."<<endl;
        }
        else if(operand=="fish"&& itemsGained[fish]==true)
        {
            cout<<"You cant place why you think this but for some reason the fish looks exceptionally tasty."<<endl;
        }
        else if(operand=="shovel" && itemsGained[shovel]==true)
        {
            cout<<"The shovel begins to tell you its life story. Amongst the information the shovel says that its always dreamed of being used to dig up treasure. You must have been hit on the head really hard"<<endl;
        }
        else if(operand=="mirror" && itemsGained[mirror]==true)
        {
            cout<<"You gaze upon yourself in the mirror. As your eyes begin to water you notice that there is a tatoo of an acorn crest on your forehead."<<endl;
        }
    }
    else
        {
         cout<<"I'm sorry you can't do that right now."<<endl;
        }


    }
return;
}

// description function for the tower
void descForTower(void)
{
cout<<"Your gaze is set upon a mighty tower that. As your eyes follow from the base to the clouds you notice that the tower has carvings in the stones which it has been erected from. These carvings appear to be of acorns."<<endl;
return;
}


void help()
{
    cout<<"Help: prints out commands that the system can handle."<<endl;
    cout<<"N,E,W,S: Moves the player in that direction if possible."<<endl;
    cout<<"Go <location>: moves the player to a location if they have already been there."<<endl;
    cout<<"Exit: exits the game."<<endl;
    cout<<"Get <item>: takes an item from a location and put it in the users inventory if possible."<<endl;
    cout<<"i or inv: lists the items in the users inventory."<<endl;
    cout<<"Use <item>: uses or applies an item that the user has to a location."<<endl;
    cout<<"Drop <item>: drops an item from the users inventory leaving it in that location."<<endl;
    cout<<"Look <item>: Further examine an item."<<endl;

}
void exiter()
{
    char userAns;
    cout<<"are you sure that you want to abandon the quest for your name? [y/n]"<<endl;
    cin>>userAns;
    if(userAns=='y')
    {
        gameRunning=false;
    }
    else if (userAns=='n')
    {
        gameRunning=true;
    }
    else
    {
        cout<<"Your input wasn't understood"<<endl;
    }
}




void handleForTland(string event, string operand)
{   int i=0;

    if(event=="n" || event=="N" )
    {
        cout<<"If you head that way you'll hit then ocean"<<endl;
    }
    else if (event=="s"||event=="S")
    {
        if(locations_visited[braids]==false)
            {
                cout<<"Before you there are numerous weird structures. However,one of these braid like buildings appears to be a black smith's shop you enter."<<endl;
                locations_visited[braids]=true;
                current_location=braids;
            }
        else
            {
                cout<<"You have returned to Braids Blacksmithing."<<endl;
                current_location=braids;
            }
    }
     else if (event=="e"||event=="E")
    {
       cout<<"If you head too far that way you'll fall into the sea."<<endl;
    }
     else if (event=="w"||event=="W")
    {
      if(locations_visited[heavens_peak]==false)
            {
                cout<<"You stand in awe of the massive Heavenly peaks. At the base of these peaks you see a camp with tools strewn everywhere. Theres is a particular handle that catches your eye. "<<endl;
                locations_visited[heavens_peak]=true;
                current_location=heavens_peak;
            }
        else
            {
                cout<<"You have returned to Heaven's Peak."<<endl;
                current_location=heavens_peak;
            }
    }
     else if (event=="ne"||event=="NE")
    {
       cout<<"theres nothing but trees and ocean that way"<<endl;
    }
     else if (event=="nw"||event=="NW")
    {
       cout<<"Theres nothing but a cliff and the ocean over there pal."<<endl;
    }
     else if (event=="se"||event=="SE")
    {
       cout<<"Keep walking that way and your in for a long fall and a swim."<<endl;
    }
    else if (event=="sw"||event=="SW")
    {
        cout<<"you have returned to the large tower with acorns carved on its exterior walls and a large steel door that is locked."<<endl;
        current_location=leroys_tower;
    }




    //code for the go event/ command
    else if ((event=="GO"||event=="go") && !(operand.empty()) )
    {
        if( operand.substr(0)=="t" && (operand.substr(operand.length()-1))=="d")
        {

            if(locations_visited[treasureland]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
                current_location=treasureland;
            }
            else
            {
                cout<<"You have returned to Treasureland"<<endl;
                current_location=treasureland;
            }
        }
         else if( operand.substr(0)=="b" && (operand.substr(operand.length()-1))=="s")
        {

            if(locations_visited[braids]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to Braids Blacksmithing."<<endl;
               current_location=braids;
            }
        }
         else if(operand.substr(0)=="l" && (operand.substr(operand.length()-1))=="r")
        {

            if(locations_visited[leroys_tower]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to the Tower."<<endl;
               current_location=leroys_tower;
            }
        }
         else if(operand.substr(0)=="f" && (operand.substr(operand.length()-1))=="p")
        {

            if(locations_visited[falcons_keep]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to Falcons Keep"<<endl;
               current_location=falcons_keep;
            }
        }
         else if( operand.substr(0)=="h" && (operand.substr(operand.length()-1))=="k")
        {

            if(locations_visited[heavens_peak]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to Heavens Peak"<<endl;
               current_location=heavens_peak;
            }
        }
        else if( operand.substr(0)=="r" && (operand.substr(operand.length()-1))=="m")
        {

            if(locations_visited[red_chasm]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to The Red Chasm."<<endl;
               current_location=red_chasm;
            }
        }
        else if( operand.substr(0)=="w" && (operand.substr(operand.length()-1))=="l")
        {

            if(locations_visited[wish_well]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to The Wish Well"<<endl;
               current_location=wish_well;
            }
        }
        else if( operand.substr(0)=="m" && (operand.substr(operand.length()-1))=="e")
        {

            if(locations_visited[mermaid_cove]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to Mermaid Cove"<<endl;
               current_location=mermaid_cove;
            }
        }
    // the get command
    else if((event=="get" || event=="Get") && !operand.empty())
        {

            for(i=0;i<15;i++)
            {
                if(treasureLand.items[i]==operand && LEROY.inventory[i]=="")
                {
                    LEROY.inventory[i]=treasureLand.items[i];
                    treasureLand.items[i]="";
                }
                else if ((treasureLand.items[i]==operand)&& !(LEROY.inventory[i]==""))
                {
                    int k = i;
                    for (k=i;k<7;k++)
                    {
                        if(LEROY.inventory[k]=="")
                        {
                            LEROY.inventory[k]=treasureLand.items[i];
                            treasureLand.items[i]="";
                            itemsGained[i]=true;
                            k=7;
                        }
                         else
                        {
                            cout<<"This item isn' t available here."<<endl;
                            k=7;
                        }
                    }

                }

            }

        }

    // the drop command
    else if((event=="drop" || event=="Drop") && !operand.empty())
        {
            for(i=0;i<7;i++)
            {
                if((LEROY.inventory[i]==operand)&& (treasureLand.items[i]==""))
                {
                    treasureLand.items[i]=LEROY.inventory[i];
                    LEROY.inventory[i]= "";
                    itemsGained[i]=false;
                }
                else if ((LEROY.inventory[i]==operand)&& !(treasureLand.items[i]==""))
                {
                    int j = i;
                    for(j=i;j<15;j++)
                        {
                            if(treasureLand.items[j]=="")
                            {
                                treasureLand.items[j]=LEROY.inventory[i];
                                LEROY.inventory[i]= "";
                                itemsGained[i]=false;
                                j=7;
                            }
                            else
                            {
                                cout<<"This item can't be dropped at this time"<<endl;
                                j=7;
                            }
                        }
                }


            }

        }
        // the use command

    else if (event == "use" || event =="Use")
        {

            if(operand=="shovel" && itemsGained[redX]==false)
            {
                    cout<<"The shovel whispers to you. I think this is where I'm meant to dig but I don't know where exactly."<<endl;
            }
            else if(operand=="shovel"&&itemsGained[redX]==true)
            {
                cout<<"the shovel yells im meant to dig over there at that red x!!. It then jumps out of your hands and starts digging. It uncovers a key that is made of metal and has an acorn on it."<<endl;
                itemsGained[key]=true;
            }
            else
                {
                    cout<<"You try to open the door but it is locked. Where is the key??"<<endl;
                }

        }
    else if(event=="look" || event=="Look")
    {
        if(operand=="redX")
        {
            cout<<"The shovel seems to be pulled towards the red x thats now on the ground."<<endl;
        }
        else if (operand=="handle"&& itemsGained[handle]==true)
        {
            cout<<"This appears to be a very well made handle that any tool maker would love to turn into a full tool. However, being that the handle doesn't have anything attached to it it is currently useless."<<endl;
        }
        else if (operand=="key" && itemsGained[key]==true)
        {
            cout<<" You notice that the key is made of solid steel and has an acorn crest etched into it."<<endl;
        }
        else if(operand=="fish"&& itemsGained[fish]==true)
        {
            cout<<"You cant place why you think this but for some reason the fish looks exceptionally tasty."<<endl;
        }
        else if(operand=="shovel" && itemsGained[shovel]==true)
        {
            cout<<"The shovel begins to tell you its life story. Amongst the information the shovel says that its always dreamed of being used to dig up treasure. You must have been hit on the head really hard"<<endl;
        }
        else if(operand=="mirror" && itemsGained[mirror]==true)
        {
            cout<<"You gaze upon yourself in the mirror. As your eyes begin to water you notice that there is a tatoo of an acorn crest on your forehead."<<endl;
        }
    }
    else
        {
         cout<<"I'm sorry you can't do that right now."<<endl;
        }


    }
return;
}

void handleForBraids(string event, string operand)
{   int i=0;

    if(event=="n" || event=="N" )
    {
        if(locations_visited[treasureland]==false)
            {
                cout<<"In front of you is a massive forest. There is a sign that reads Treasureland."<<endl;
                locations_visited[treasureland]=true;
                current_location=treasureland;
            }
        else
            {
                cout<<"You have returned to Treasureland"<<endl;
                current_location=treasureland;
            }
    }
    else if (event=="s"||event=="S")
    {
       cout<<"The only thing that way is a cliff and the ocean"<<endl;
    }
     else if (event=="e"||event=="E")
    {
       cout<<"If you head too far that way you'll fall into the sea."<<endl;
    }
     else if ( event=="sw" || event=="SW")
    {
        if(locations_visited[falcons_keep]==false)
            {
                cout<<"You seems to have found yourself a hatchery. You notice a mirror perched on the rocks above you. A Falcon Greets you and offers to get the mirror in return for a tasty fish.,"<<endl;
                locations_visited[falcons_keep]=true;
                current_location=falcons_keep;
            }
        else
            {
                cout<<"You're back at Falcons Keep"<<endl;
                current_location=falcons_keep;
            }
    }
     else if (event=="ne"||event=="NE")
    {
        cout<<"Theres nothing but ocean that way"<<endl;
    }
     else if (event=="nw"||event=="NW")
    {
      cout<<"you have returned to the large tower with acorns carved on its exterior walls and a large steel door that is locked."<<endl;
      current_location=leroys_tower;
    }
     else if (event=="se"||event=="SE")
    {
       cout<<"How many times do I have to say it....thats the ocean"<<endl;
    }


    //code for the go event/ command
    else if ((event=="GO"||event=="go") && !(operand.empty()) )
    {
        if( operand.substr(0)=="t" && (operand.substr(operand.length()-1))=="d")
        {

            if(locations_visited[treasureland]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
                current_location=treasureland;
            }
            else
            {
                cout<<"You have returned to Treasureland"<<endl;
                current_location=treasureland;
            }
        }
         else if( operand.substr(0)=="b" && (operand.substr(operand.length()-1))=="s")
        {

            if(locations_visited[braids]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to Braids Blacksmithing."<<endl;
               current_location=braids;
            }
        }
         else if(operand.substr(0)=="l" && (operand.substr(operand.length()-1))=="r")
        {

            if(locations_visited[leroys_tower]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to the Tower."<<endl;
               current_location=leroys_tower;
            }
        }
         else if(operand.substr(0)=="f" && (operand.substr(operand.length()-1))=="p")
        {

            if(locations_visited[falcons_keep]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to Falcons Keep"<<endl;
               current_location=falcons_keep;
            }
        }
         else if( operand.substr(0)=="h" && (operand.substr(operand.length()-1))=="k")
        {

            if(locations_visited[heavens_peak]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to Heavens Peak"<<endl;
               current_location=heavens_peak;
            }
        }
        else if( operand.substr(0)=="r" && (operand.substr(operand.length()-1))=="m")
        {

            if(locations_visited[red_chasm]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to The Red Chasm."<<endl;
               current_location=red_chasm;
            }
        }
        else if( operand.substr(0)=="w" && (operand.substr(operand.length()-1))=="l")
        {

            if(locations_visited[wish_well]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to The Wish Well"<<endl;
               current_location=wish_well;
            }
        }
        else if( operand.substr(0)=="m" && (operand.substr(operand.length()-1))=="e")
        {

            if(locations_visited[mermaid_cove]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to Mermaid Cove"<<endl;
               current_location=mermaid_cove;
            }
        }
    // the get command
    else if((event=="get" || event=="Get") && !operand.empty())
        {

            for(i=0;i<15;i++)
            {
                if(Braids.items[i]==operand && LEROY.inventory[i]=="")
                {
                    LEROY.inventory[i]=Braids.items[i];
                    Braids.items[i]="";
                }
                else if ((Braids.items[i]==operand)&& !(LEROY.inventory[i]==""))
                {
                    int k = i;
                    for (k=i;k<7;k++)
                    {
                        if(LEROY.inventory[k]=="")
                        {
                            LEROY.inventory[k]=Braids.items[i];
                            Braids.items[i]="";
                            itemsGained[i]=true;
                            k=7;
                        }
                         else
                        {
                            cout<<"This item isn' t available here."<<endl;
                            k=7;
                        }
                    }

                }

            }

        }

    // the drop command
    else if((event=="drop" || event=="Drop") && !operand.empty())
        {
            for(i=0;i<7;i++)
            {
                if((LEROY.inventory[i]==operand)&& (Braids.items[i]==""))
                {
                    Braids.items[i]=LEROY.inventory[i];
                    LEROY.inventory[i]= "";
                    itemsGained[i]=false;
                }
                else if ((LEROY.inventory[i]==operand)&& !(Braids.items[i]==""))
                {
                    int j = i;
                    for(j=i;j<15;j++)
                        {
                            if(Braids.items[j]=="")
                            {
                                Braids.items[j]=LEROY.inventory[i];
                                LEROY.inventory[i]= "";
                                itemsGained[i]=false;
                                j=7;
                            }
                            else
                            {
                                cout<<"This item can't be dropped at this time"<<endl;
                                j=7;
                            }
                        }
                }


            }

        }
        // the use command

    else if (event == "use" || event =="Use")
        {

            if(operand=="handle"&& itemsGained[handle]==true)
                {
                    cout<<"You offer the handle to the shop keep in return for a tool. He gladly takes the handle and leaves the shovel on the counter for you."<<endl;
                    itemsGained[handle]=false;
                }
            else
                {
                    cout<<"You offer to trade with the shop keep but you don't have anything that peaks his interest."<<endl;
                }

        }
    else if(event=="look" || event=="Look")
    {
        if(operand=="keep")
        {
            cout<<"The shop keep looks like hes made many a deal in his day. The tools he makes while expertly crafted look hobbled together from different parts."<<endl;
        }
        else if (operand=="handle"&& itemsGained[handle]==true)
        {
            cout<<"This appears to be a very well made handle that any tool maker would love to turn into a full tool. However, being that the handle doesn't have anything attached to it it is currently useless."<<endl;
        }
        else if (operand=="key" && itemsGained[key]==true)
        {
            cout<<" You notice that the key is made of solid steel and has an acorn crest etched into it."<<endl;
        }
        else if(operand=="fish"&& itemsGained[fish]==true)
        {
            cout<<"You cant place why you think this but for some reason the fish looks exceptionally tasty."<<endl;
        }
        else if(operand=="shovel" && itemsGained[shovel]==true)
        {
            cout<<"The shovel begins to tell you its life story. Amongst the information the shovel says that its always dreamed of being used to dig up treasure. You must have been hit on the head really hard"<<endl;
        }
        else if(operand=="mirror" && itemsGained[mirror]==true)
        {
            cout<<"You gaze upon yourself in the mirror. As your eyes begin to water you notice that there is a tatoo of an acorn crest on your forehead."<<endl;
        }
    }
    else
        {
         cout<<"I'm sorry you can't do that right now."<<endl;
        }


    }
return;
}

void handleForChasm(string event,string operand)
{   int i=0;

    if(event=="n" || event=="N" )
    {
        if(locations_visited[heavens_peak]==false)
            {
                cout<<"You stand in awe of the massive Heavenly peaks. At the base of these peaks you see a camp with tools strewn everywhere "<<endl;
                locations_visited[heavens_peak]=true;
                current_location=heavens_peak;
            }
        else
            {
                cout<<"You have returned to Heaven's Peak."<<endl;
                current_location=heavens_peak;
            }
    }
    else if (event=="s"||event=="S")
    {
       cout<<"The only thing that way is a cliff and the ocean"<<endl;
    }
     else if (event=="e"||event=="E")
    {
         if(locations_visited[braids]==false)
            {
                cout<<"Before you there are numerous weird structures. However,one of these braid like buildings appears to be a black smith's shop you enter."<<endl;
                locations_visited[braids]=true;
                current_location=braids;
            }
        else
            {
                cout<<"You have returned to Braids Blacksmithing."<<endl;
                current_location=braids;
            }

    }
      else if ( event=="sw" || event=="SW")
    {
        if(locations_visited[wish_well]==false)
            {
                cout<<"You reach the peak of a cliff high above the ocean upon this peak there is a wishing well. You hear a voice from down in the well say ill tell you what you don't know for a gold coin."<<endl;
                locations_visited[wish_well]=true;
                current_location=wish_well;
            }
        else
            {
                cout<<"You have returned to Braids Blacksmithing."<<endl;
                current_location=braids;
            }
    }

     else if ( event=="w" || event=="W")
    {
       cout<<"If you head too far that way you'll fall into the sea."<<endl;
    }

     else if (event == "ne" || event == "NE")
    {
        cout<<"you have returned to the large tower with acorns carved on its exterior walls and a large steel door that is locked."<<endl;
        current_location=leroys_tower;
    }
     else if (event=="nw"||event=="NW")
    {
      if(locations_visited[mermaid_cove]=false)
      {
          cout<<"You arrive at a small inlet. In the water you see mermaids swimming around.One comes ashore and offers you a fish for the price of a gold coin."<<endl;
          current_location=mermaid_cove;
      }
      else
      {
          cout<<"you have returned to the mermaid cove."<<endl;
          current_location=mermaid_cove;
      }
    }
     else if (event=="se"||event=="SE")
    {
       cout<<"Theres an impassible mound in that direction."<<endl;
    }


    //code for the go event/ command
    else if ((event=="GO"||event=="go") && !(operand.empty()) )
    {
        if( operand.substr(0)=="t" && (operand.substr(operand.length()-1))=="d")
        {

            if(locations_visited[treasureland]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
                current_location=treasureland;
            }
            else
            {
                cout<<"You have returned to Treasureland"<<endl;
                current_location=treasureland;
            }
        }
         else if( operand.substr(0)=="b" && (operand.substr(operand.length()-1))=="s")
        {

            if(locations_visited[braids]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to Braids Blacksmithing."<<endl;
               current_location=braids;
            }
        }
         else if(operand.substr(0)=="l" && (operand.substr(operand.length()-1))=="r")
        {

            if(locations_visited[leroys_tower]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to the Tower."<<endl;
               current_location=leroys_tower;
            }
        }
         else if(operand.substr(0)=="f" && (operand.substr(operand.length()-1))=="p")
        {

            if(locations_visited[falcons_keep]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to Falcons Keep"<<endl;
               current_location=falcons_keep;
            }
        }
         else if( operand.substr(0)=="h" && (operand.substr(operand.length()-1))=="k")
        {

            if(locations_visited[heavens_peak]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to Heavens Peak"<<endl;
               current_location=heavens_peak;
            }
        }
        else if( operand.substr(0)=="r" && (operand.substr(operand.length()-1))=="m")
        {

            if(locations_visited[red_chasm]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to The Red Chasm."<<endl;
               current_location=red_chasm;
            }
        }
        else if( operand.substr(0)=="w" && (operand.substr(operand.length()-1))=="l")
        {

            if(locations_visited[wish_well]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to The Wish Well"<<endl;
               current_location=wish_well;
            }
        }
        else if( operand.substr(0)=="m" && (operand.substr(operand.length()-1))=="e")
        {

            if(locations_visited[mermaid_cove]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to Mermaid Cove"<<endl;
               current_location=mermaid_cove;
            }
        }
    // the get command
    else if((event=="get" || event=="Get") && !operand.empty())
        {

            for(i=0;i<15;i++)
            {
                if(redChasm.items[i]==operand && LEROY.inventory[i]=="")
                {
                    LEROY.inventory[i]=redChasm.items[i];
                    redChasm.items[i]="";
                }
                else if ((redChasm.items[i]==operand)&& !(LEROY.inventory[i]==""))
                {
                    int k = i;
                    for (k=i;k<7;k++)
                    {
                        if(LEROY.inventory[k]=="")
                        {
                            LEROY.inventory[k]=redChasm.items[i];
                            redChasm.items[i]="";
                            itemsGained[i]=true;
                            k=7;
                        }
                         else
                        {
                            cout<<"This item isn' t available here."<<endl;
                            k=7;
                        }
                    }

                }

            }

        }

    // the drop command
    else if((event=="drop" || event=="Drop") && !operand.empty())
        {
            for(i=0;i<7;i++)
            {
                if((LEROY.inventory[i]==operand)&& (redChasm.items[i]==""))
                {
                    redChasm.items[i]=LEROY.inventory[i];
                    LEROY.inventory[i]= "";
                    itemsGained[i]=false;
                }
                else if ((LEROY.inventory[i]==operand)&& !(redChasm.items[i]==""))
                {
                    int j = i;
                    for(j=i;j<15;j++)
                        {
                            if(redChasm.items[j]=="")
                            {
                                redChasm.items[j]=LEROY.inventory[i];
                                LEROY.inventory[i]= "";
                                itemsGained[i]=false;
                                j=7;
                            }
                            else
                            {
                                cout<<"This item can't be dropped at this time"<<endl;
                                j=7;
                            }
                        }
                }


            }

        }
        // the use command

    else if (event == "use" || event =="Use")
        {

            if(operand=="coin"&& LEROY.coins>0 && pay_chasm==false)
                {
                    cout<<"You toss a single gold coin into the chasm. The well that there is a treasure hidden in this land"<<endl;
                    cout<<"The chasm then states that the treasure is located in a place who's anthem is."<<endl;
                    cout<<"________ is the place to be. ________, where the acorns are free.________is for you and me and all the fuzzy creatures in the world."<<endl;
                    LEROY.coins--;
                    pay_chasm=true;
                }
            else
                {
                    cout<<"The chasm whispers back. Please I cant take anymore handouts its lowering my self esteem."<<endl;
                }

        }
    else if(event=="look" || event=="Look")
    {
        if(operand=="Sign")
        {
            cout<<"the sign for the chasm has fine print that read the price of knowledge isn't knowing its a gold coin!!!"<<endl;
        }
        else if (operand=="handle"&& itemsGained[handle]==true)
        {
            cout<<"This appears to be a very well made handle that any tool maker would love to turn into a full tool. However, being that the handle doesn't have anything attached to it it is currently useless."<<endl;
        }
        else if (operand=="key" && itemsGained[key]==true)
        {
            cout<<" You notice that the key is made of solid steel and has an acorn crest etched into it."<<endl;
        }
        else if(operand=="fish"&& itemsGained[fish]==true)
        {
            cout<<"You cant place why you think this but for some reason the fish looks exceptionally tasty."<<endl;
        }
        else if(operand=="shovel" && itemsGained[shovel]==true)
        {
            cout<<"The shovel begins to tell you its life story. Amongst the information the shovel says that its always dreamed of being used to dig up treasure. You must have been hit on the head really hard"<<endl;
        }
        else if(operand=="mirror" && itemsGained[mirror]==true)
        {
            cout<<"You gaze upon yourself in the mirror. As your eyes begin to water you notice that there is a tatoo of an acorn crest on your forehead."<<endl;
        }
    }
    else
        {
         cout<<"I'm sorry you can't do that right now."<<endl;
        }


    }
return;
}



void handleForWW(string event,string operand)
{   int i=0;

    if(event=="n" || event=="N" )
    {
       cout<<"You're on a cliff you can only head east"<<endl;
    }

    else if (event=="s"||event=="S")
    {
       cout<<"You're on a cliff you can only head east"<<endl;
    }
     else if (event=="e"||event=="E")
    {
          if(locations_visited[red_chasm]==false)
            {
                cout<<"You appear at a giant red swirling hole in the ground. You see a sign that reads Welcome to The Red Chasm. Where all men pay their debts."<<endl;
                locations_visited[red_chasm]=true;
                current_location=red_chasm;
            }
        else
            {
                cout<<"You're back at The Red Chasm;"<<endl;
                current_location=red_chasm;
            }

    }
      else if ( event=="sw" || event=="SW")
    {
        cout<<"You're on a cliff you can only head east"<<endl;
    }

     else if ( event=="w" || event=="W")
    {
       cout<<"You're on a cliff you can only head east"<<endl;
    }

     else if (event=="ne"||event=="NE")
    {
        cout<<"You're on a cliff you can only head east"<<endl;
    }
     else if (event=="nw"||event=="NW")
    {
      cout<<"You're on a cliff you can only head east"<<endl;
    }
     else if (event=="se"||event=="SE")
    {
       cout<<"You're on a cliff you can only head east"<<endl;
    }


    //code for the go event/ command
    else if ((event=="GO"||event=="go") && !(operand.empty()) )
    {
        if( operand.substr(0)=="t" && (operand.substr(operand.length()-1))=="d")
        {

            if(locations_visited[treasureland]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
                current_location=treasureland;
            }
            else
            {
                cout<<"You have returned to Treasureland"<<endl;
                current_location=treasureland;
            }
        }
         else if( operand.substr(0)=="b" && (operand.substr(operand.length()-1))=="s")
        {

            if(locations_visited[braids]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to Braids Blacksmithing."<<endl;
               current_location=braids;
            }
        }
         else if(operand.substr(0)=="l" && (operand.substr(operand.length()-1))=="r")
        {

            if(locations_visited[leroys_tower]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to the Tower."<<endl;
               current_location=leroys_tower;
            }
        }
         else if(operand.substr(0)=="f" && (operand.substr(operand.length()-1))=="p")
        {

            if(locations_visited[falcons_keep]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to Falcons Keep"<<endl;
               current_location=falcons_keep;
            }
        }
         else if( operand.substr(0)=="h" && (operand.substr(operand.length()-1))=="k")
        {

            if(locations_visited[heavens_peak]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to Heavens Peak"<<endl;
               current_location=heavens_peak;
            }
        }
        else if( operand.substr(0)=="r" && (operand.substr(operand.length()-1))=="m")
        {

            if(locations_visited[red_chasm]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to The Red Chasm."<<endl;
               current_location=red_chasm;
            }
        }
        else if( operand.substr(0)=="w" && (operand.substr(operand.length()-1))=="l")
        {

            if(locations_visited[wish_well]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to The Wish Well"<<endl;
               current_location=wish_well;
            }
        }
        else if( operand.substr(0)=="m" && (operand.substr(operand.length()-1))=="e")
        {

            if(locations_visited[mermaid_cove]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to Mermaid Cove"<<endl;
               current_location=mermaid_cove;
            }
        }
    // the get command
    else if((event=="get" || event=="Get") && !operand.empty())
        {

            for(i=0;i<15;i++)
            {
                if(wishWell.items[i]==operand && LEROY.inventory[i]=="")
                {
                    LEROY.inventory[i]=wishWell.items[i];
                    wishWell.items[i]="";
                }
                else if ((wishWell.items[i]==operand)&& !(LEROY.inventory[i]==""))
                {
                    int k = i;
                    for (k=i;k<7;k++)
                    {
                        if(LEROY.inventory[k]=="")
                        {
                            LEROY.inventory[k]=wishWell.items[i];
                            wishWell.items[i]="";
                            itemsGained[i]=true;
                            k=7;
                        }
                         else
                        {
                            cout<<"This item isn' t available here."<<endl;
                            k=7;
                        }
                    }

                }

            }

        }

    // the drop command
    else if((event=="drop" || event=="Drop") && !operand.empty())
        {
            for(i=0;i<7;i++)
            {
                if((LEROY.inventory[i]==operand)&& (wishWell.items[i]==""))
                {
                    wishWell.items[i]=LEROY.inventory[i];
                    LEROY.inventory[i]= "";
                    itemsGained[i]=false;
                }
                else if ((LEROY.inventory[i]==operand)&& !(wishWell.items[i]==""))
                {
                    int j = i;
                    for(j=i;j<15;j++)
                        {
                            if(wishWell.items[j]=="")
                            {
                                wishWell.items[j]=LEROY.inventory[i];
                                LEROY.inventory[i]= "";
                                itemsGained[i]=false;
                                j=7;
                            }
                            else
                            {
                                cout<<"This item can't be dropped at this time"<<endl;
                                j=7;
                            }
                        }
                }


            }

        }
        // the use command

    else if (event == "use" || event =="Use")
        {

            if(operand=="coin"&& LEROY.coins>0 && pay_well==false)
                {
                    cout<<"You drop a coin into the well. The well states that there is a red x located in Treasureland."<<endl;
                    cout<<"You know Treasureland"<<endl;
                    cout<<"Treasureland is the place to be. Treasureland, where the acorns are free. Treasureland is for you and me and all the fuzzy creatures in the world."<<endl;
                    LEROY.coins--;
                    pay_well=true;
                    itemsGained[redX]=true;
                }
            else
                {
                    cout<<"The well says that it doesn't want to scam you anymore."<<endl;
                }

        }
    else if(event=="look" || event=="Look")
    {
        if(operand=="Sign")
        {
            cout<<"the sign on the well says that the return policy is that there is no return policy."<<endl;
        }
        else if (operand=="handle"&& itemsGained[handle]==true)
        {
            cout<<"This appears to be a very well made handle that any tool maker would love to turn into a full tool. However, being that the handle doesn't have anything attached to it it is currently useless."<<endl;
        }
        else if (operand=="key" && itemsGained[key]==true)
        {
            cout<<" You notice that the key is made of solid steel and has an acorn crest etched into it."<<endl;
        }
        else if(operand=="fish"&& itemsGained[fish]==true)
        {
            cout<<"You cant place why you think this but for some reason the fish looks exceptionally tasty."<<endl;
        }
        else if(operand=="shovel" && itemsGained[shovel]==true)
        {
            cout<<"The shovel begins to tell you its life story. Amongst the information the shovel says that its always dreamed of being used to dig up treasure. You must have been hit on the head really hard"<<endl;
        }
        else if(operand=="mirror" && itemsGained[mirror]==true)
        {
            cout<<"You gaze upon yourself in the mirror. As your eyes begin to water you notice that there is a tatoo of an acorn crest on your forehead."<<endl;
        }
    }
    else
        {
         cout<<"I'm sorry you can't do that right now."<<endl;
        }


    }
return;
}




void handleForHP(string event,string operand)
{   int i=0;

    if(event=="n" || event=="N" )
    {
       cout<<"Thats the ocean right there."<<endl;
    }

    else if (event=="s"||event=="S")
    {
       if(locations_visited[red_chasm]==false)
            {
                cout<<"You appear at a giant red swirling hole in the ground. You see a sign that reads Welcome to The Red Chasm. Where all men pay their debts."<<endl;
                locations_visited[red_chasm]=true;
                current_location=red_chasm;
            }
        else
            {
                cout<<"You're back at The Red Chasm;"<<endl;
                current_location=red_chasm;
            }
    }
     else if (event=="e"||event=="E")
    {
          if(locations_visited[treasureland]==false)
            {
                cout<<"In front of you is a massive forest. There is a sign that reads Treasureland."<<endl;
                locations_visited[treasureland]=true;
                current_location=treasureland;
            }
        else
            {
                cout<<"You have returned to Treasureland"<<endl;
                current_location=treasureland;
            }
    }
      else if ( event=="sw" || event=="SW")
    {
        cout<<"Theres really nothing for you that way."<<endl;
    }

     else if ( event=="w" || event=="W")
    {
       if(locations_visited[mermaid_cove]=false)
      {
          cout<<"You arrive at a small inlet. In the water you see mermaids swimming around.One comes ashore and offers you a fish for the price of a gold coin."<<endl;
          current_location=mermaid_cove;
      }
      else
      {
          cout<<"you have returned to the mermaid cove."<<endl;
          current_location=mermaid_cove;
      }
    }

     else if (event=="ne"||event=="NE")
    {
        cout<<"Theres really nothing for you that way."<<endl;
    }
     else if (event=="nw"||event=="NW")
    {
      cout<<"lets stay focused on the task at hand"<<endl;
    }
     else if (event=="se"||event=="SE")
    {
       cout<<"you have returned to the large tower with acorns carved on its exterior walls and a large steel door that is locked."<<endl;
        current_location=leroys_tower;
    }


    //code for the go event/ command
    else if ((event=="GO"||event=="go") && !(operand.empty()) )
    {
        if( operand.substr(0)=="t" && (operand.substr(operand.length()-1))=="d")
        {

            if(locations_visited[treasureland]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
                current_location=treasureland;
            }
            else
            {
                cout<<"You have returned to Treasureland"<<endl;
                current_location=treasureland;
            }
        }
         else if( operand.substr(0)=="b" && (operand.substr(operand.length()-1))=="s")
        {

            if(locations_visited[braids]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to Braids Blacksmithing."<<endl;
               current_location=braids;
            }
        }
         else if(operand.substr(0)=="l" && (operand.substr(operand.length()-1))=="r")
        {

            if(locations_visited[leroys_tower]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to the Tower."<<endl;
               current_location=leroys_tower;
            }
        }
         else if(operand.substr(0)=="f" && (operand.substr(operand.length()-1))=="p")
        {

            if(locations_visited[falcons_keep]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to Falcons Keep"<<endl;
               current_location=falcons_keep;
            }
        }
         else if( operand.substr(0)=="h" && (operand.substr(operand.length()-1))=="k")
        {

            if(locations_visited[heavens_peak]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to Heavens Peak"<<endl;
               current_location=heavens_peak;
            }
        }
        else if( operand.substr(0)=="r" && (operand.substr(operand.length()-1))=="m")
        {

            if(locations_visited[red_chasm]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to The Red Chasm."<<endl;
               current_location=red_chasm;
            }
        }
        else if( operand.substr(0)=="w" && (operand.substr(operand.length()-1))=="l")
        {

            if(locations_visited[wish_well]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to The Wish Well"<<endl;
               current_location=wish_well;
            }
        }
        else if( operand.substr(0)=="m" && (operand.substr(operand.length()-1))=="e")
        {

            if(locations_visited[mermaid_cove]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to Mermaid Cove"<<endl;
               current_location=mermaid_cove;
            }
        }
    // the get command
    else if((event=="get" || event=="Get") && !operand.empty())
        {

            for(i=0;i<15;i++)
            {
                if(heavensPeak.items[i]==operand && LEROY.inventory[i]=="")
                {
                    LEROY.inventory[i]=heavensPeak.items[i];
                    heavensPeak.items[i]="";
                }
                else if ((heavensPeak.items[i]==operand)&& !(LEROY.inventory[i]==""))
                {
                    int k = i;
                    for (k=i;k<7;k++)
                    {
                        if(LEROY.inventory[k]=="")
                        {
                            LEROY.inventory[k]=heavensPeak.items[i];
                            heavensPeak.items[i]="";
                            itemsGained[i]=true;
                            k=7;
                        }
                         else
                        {
                            cout<<"This item isn' t available here."<<endl;
                            k=7;
                        }
                    }

                }

            }

        }

    // the drop command
    else if((event=="drop" || event=="Drop") && !operand.empty())
        {
            for(i=0;i<7;i++)
            {
                if((LEROY.inventory[i]==operand)&& (heavensPeak.items[i]==""))
                {
                    heavensPeak.items[i]=LEROY.inventory[i];
                    LEROY.inventory[i]= "";
                    itemsGained[i]=false;
                }
                else if ((LEROY.inventory[i]==operand)&& !(heavensPeak.items[i]==""))
                {
                    int j = i;
                    for(j=i;j<15;j++)
                        {
                            if(heavensPeak.items[j]=="")
                            {
                                heavensPeak.items[j]=LEROY.inventory[i];
                                LEROY.inventory[i]= "";
                                itemsGained[i]=false;
                                j=7;
                            }
                            else
                            {
                                cout<<"This item can't be dropped at this time"<<endl;
                                j=7;
                            }
                        }
                }


            }

        }
        // the use command

    else if (event == "use" || event =="Use")
        {

         cout<<"You can't use that here."<<endl;

        }
    else if(event=="look" || event=="Look")
    {
        if(operand=="handle")
        {
            cout<<"The handle is super ornate and almost certainly belonged to someone important. There are most certainly long gone. There is an acorn inscribed on it."<<endl;
        }
        else if (operand=="handle"&& itemsGained[handle]==true)
        {
            cout<<"This appears to be a very well made handle that any tool maker would love to turn into a full tool. However, being that the handle doesn't have anything attached to it it is currently useless."<<endl;
        }
        else if (operand=="key" && itemsGained[key]==true)
        {
            cout<<" You notice that the key is made of solid steel and has an acorn crest etched into it."<<endl;
        }
        else if(operand=="fish"&& itemsGained[fish]==true)
        {
            cout<<"You cant place why you think this but for some reason the fish looks exceptionally tasty."<<endl;
        }
        else if(operand=="shovel" && itemsGained[shovel]==true)
        {
            cout<<"The shovel begins to tell you its life story. Amongst the information the shovel says that its always dreamed of being used to dig up treasure. You must have been hit on the head really hard"<<endl;
        }
        else if(operand=="mirror" && itemsGained[mirror]==true)
        {
            cout<<"You gaze upon yourself in the mirror. As your eyes begin to water you notice that there is a tatoo of an acorn crest on your forehead."<<endl;
        }
    }
    else
        {
         cout<<"I'm sorry you can't do that right now."<<endl;
        }


    }
return;
}



void handleForMM(string event,string operand)
{   int i=0;

    if(event=="n" || event=="N" )
    {
       cout<<"Who do you think you are you cant walk on water."<<endl;
    }

    else if (event=="se"||event=="Se")
    {
       if(locations_visited[red_chasm]==false)
            {
                cout<<"You appear at a giant red swirling hole in the ground. You see a sign that reads Welcome to The Red Chasm. Where all men pay their debts."<<endl;
                locations_visited[red_chasm]=true;
                current_location=red_chasm;
            }
        else
            {
                cout<<"You're back at The Red Chasm;"<<endl;
                current_location=red_chasm;
            }
    }
     else if (event=="e"||event=="E")
    {
         if(locations_visited[heavens_peak]==false)
            {
                cout<<"You stand in awe of the massive Heavenly peaks. At the base of these peaks you see a camp with tools strewn everywhere "<<endl;
                locations_visited[heavens_peak]=true;
                current_location=heavens_peak;
            }
        else
            {
                cout<<"You have returned to Heaven's Peak."<<endl;
                current_location=heavens_peak;
            }
    }
      else if ( event=="sw" || event=="SW")
    {
        cout<<"Nothing but a cliff that way."<<endl;
    }

     else if ( event=="w" || event=="W")
    {
      cout<<"i see you want to go for a swim with the mermaids. Too bad you forgot your bathing suit."<<endl;
    }

     else if (event=="ne"||event=="NE")
    {
        cout<<"Theres really nothing for you that way."<<endl;
    }
     else if (event=="nw"||event=="NW")
    {
      cout<<"lets stay focused on the task at hand"<<endl;
    }
     else if (event=="s"||event=="S")
    {
       cout<<"Keep going that way and you're going for a swim."<<endl;

    }


    //code for the go event/ command
    else if ((event=="GO"||event=="go") && !(operand.empty()) )
    {
        if( operand.substr(0)=="t" && (operand.substr(operand.length()-1))=="d")
        {

            if(locations_visited[treasureland]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
                current_location=treasureland;
            }
            else
            {
                cout<<"You have returned to Treasureland"<<endl;
                current_location=treasureland;
            }
        }
         else if( operand.substr(0)=="b" && (operand.substr(operand.length()-1))=="s")
        {

            if(locations_visited[braids]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to Braids Blacksmithing."<<endl;
               current_location=braids;
            }
        }
         else if(operand.substr(0)=="l" && (operand.substr(operand.length()-1))=="r")
        {

            if(locations_visited[leroys_tower]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to the Tower."<<endl;
               current_location=leroys_tower;
            }
        }
         else if(operand.substr(0)=="f" && (operand.substr(operand.length()-1))=="p")
        {

            if(locations_visited[falcons_keep]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to Falcons Keep"<<endl;
               current_location=falcons_keep;
            }
        }
         else if( operand.substr(0)=="h" && (operand.substr(operand.length()-1))=="k")
        {

            if(locations_visited[heavens_peak]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to Heavens Peak"<<endl;
               current_location=heavens_peak;
            }
        }
        else if( operand.substr(0)=="r" && (operand.substr(operand.length()-1))=="m")
        {

            if(locations_visited[red_chasm]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to The Red Chasm."<<endl;
               current_location=red_chasm;
            }
        }
        else if( operand.substr(0)=="w" && (operand.substr(operand.length()-1))=="l")
        {

            if(locations_visited[wish_well]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to The Wish Well"<<endl;
               current_location=wish_well;
            }
        }
        else if( operand.substr(0)=="m" && (operand.substr(operand.length()-1))=="e")
        {

            if(locations_visited[mermaid_cove]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to Mermaid Cove"<<endl;
               current_location=mermaid_cove;
            }
        }
    // the get command
    else if((event=="get" || event=="Get") && !operand.empty())
        {

            for(i=0;i<15;i++)
            {
                if(mermaidCove.items[i]==operand && LEROY.inventory[i]=="")
                {
                    LEROY.inventory[i]=mermaidCove.items[i];
                    mermaidCove.items[i]="";
                }
                else if ((mermaidCove.items[i]==operand)&& !(LEROY.inventory[i]==""))
                {
                    int k = i;
                    for (k=i;k<7;k++)
                    {
                        if(LEROY.inventory[k]=="")
                        {
                            LEROY.inventory[k]=mermaidCove.items[i];
                            mermaidCove.items[i]="";
                            itemsGained[i]=true;
                            k=7;
                        }
                         else
                        {
                            cout<<"This item isn' t available here."<<endl;
                            k=7;
                        }
                    }

                }

            }

        }

    // the drop command
    else if((event=="drop" || event=="Drop") && !operand.empty())
        {
            for(i=0;i<7;i++)
            {
                if((LEROY.inventory[i]==operand)&& (mermaidCove.items[i]==""))
                {
                    mermaidCove.items[i]=LEROY.inventory[i];
                    LEROY.inventory[i]= "";
                    itemsGained[i]=false;
                }
                else if ((LEROY.inventory[i]==operand)&& !(mermaidCove.items[i]==""))
                {
                    int j = i;
                    for(j=i;j<15;j++)
                        {
                            if(mermaidCove.items[j]=="")
                            {
                                mermaidCove.items[j]=LEROY.inventory[i];
                                LEROY.inventory[i]= "";
                                itemsGained[i]=false;
                                j=7;
                            }
                            else
                            {
                                cout<<"This item can't be dropped at this time"<<endl;
                                j=7;
                            }
                        }
                }


            }

        }
        // the use command

    else if (event == "use" || event =="Use")
        {

         if (operand=="coin"&&LEROY.coins>0)
         {
             cout<<"You toss a coin at the mermaid that offered you a fish. She tosses a fish back and it hits you in the face."<<endl;
             LEROY.coins--;
             itemsGained[fish]=true;

         }

        }
    else if(event=="look" || event=="Look")
    {
        if(operand=="cove")
        {
            cout<<"This cove appears to be no larger than an olympic size swimming pool, yet, it houses many mermaids."<<endl;
        }
        else if (operand=="handle"&& itemsGained[handle]==true)
        {
            cout<<"This appears to be a very well made handle that any tool maker would love to turn into a full tool. However, being that the handle doesn't have anything attached to it it is currently useless."<<endl;
        }
        else if (operand=="key" && itemsGained[key]==true)
        {
            cout<<" You notice that the key is made of solid steel and has an acorn crest etched into it."<<endl;
        }
        else if(operand=="fish"&& itemsGained[fish]==true)
        {
            cout<<"You cant place why you think this but for some reason the fish looks exceptionally tasty."<<endl;
        }
        else if(operand=="shovel" && itemsGained[shovel]==true)
        {
            cout<<"The shovel begins to tell you its life story. Amongst the information the shovel says that its always dreamed of being used to dig up treasure. You must have been hit on the head really hard"<<endl;
        }
        else if(operand=="mirror" && itemsGained[mirror]==true)
        {
            cout<<"You gaze upon yourself in the mirror. As your eyes begin to water you notice that there is a tatoo of an acorn crest on your forehead."<<endl;
        }
    }
    else
        {
         cout<<"I'm sorry you can't do that right now."<<endl;
        }


    }
return;
}




void handleForFK(string event,string operand)
{   int i=0;

    if(event=="n" || event=="N" )
    {
       cout<<"Theres a mound in your way."<<endl;
    }

    else if (event=="se"||event=="Se")
    {
        cout<<"Nothing but a cliff that way."<<endl;
    }
     else if (event=="e"||event=="E")
    {
          cout<<"Theres a mound in your way."<<endl;
    }
      else if ( event=="sw" || event=="SW")
    {
        cout<<"Nothing but a cliff that way."<<endl;
    }

     else if ( event=="w" || event=="W")
    {
      cout<<"Theres a mound in your way."<<endl;
    }

     else if (event=="ne"||event=="NE")
    {
        if(locations_visited[braids]==false)
            {
                cout<<"Before you there are numerous weird structures. However,one of these braid like buildings appears to be a black smith's shop you enter."<<endl;
                locations_visited[braids]=true;
                current_location=braids;
            }
        else
            {
                cout<<"You have returned to Braids Blacksmithing."<<endl;
                current_location=braids;
            }
    }
     else if (event=="nw"||event=="NW")
    {
      cout<<"Lets stay focused on the task at hand."<<endl;
    }
     else if (event=="s"||event=="S")
    {
       cout<<"Keep going that way and you're going for a swim."<<endl;

    }


    //code for the go event/ command
    else if ((event=="GO"||event=="go") && !(operand.empty()) )
    {
        if( operand.substr(0)=="t" && (operand.substr(operand.length()-1))=="d")
        {

            if(locations_visited[treasureland]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
                current_location=treasureland;
            }
            else
            {
                cout<<"You have returned to Treasureland"<<endl;
                current_location=treasureland;
            }
        }
         else if( operand.substr(0)=="b" && (operand.substr(operand.length()-1))=="s")
        {

            if(locations_visited[braids]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to Braids Blacksmithing."<<endl;
               current_location=braids;
            }
        }
         else if(operand.substr(0)=="l" && (operand.substr(operand.length()-1))=="r")
        {

            if(locations_visited[leroys_tower]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to the Tower."<<endl;
               current_location=leroys_tower;
            }
        }
         else if(operand.substr(0)=="f" && (operand.substr(operand.length()-1))=="p")
        {

            if(locations_visited[falcons_keep]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to Falcons Keep"<<endl;
               current_location=falcons_keep;
            }
        }
         else if( operand.substr(0)=="h" && (operand.substr(operand.length()-1))=="k")
        {

            if(locations_visited[heavens_peak]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to Heavens Peak"<<endl;
               current_location=heavens_peak;
            }
        }
        else if( operand.substr(0)=="r" && (operand.substr(operand.length()-1))=="m")
        {

            if(locations_visited[red_chasm]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to The Red Chasm."<<endl;
               current_location=red_chasm;
            }
        }
        else if( operand.substr(0)=="w" && (operand.substr(operand.length()-1))=="l")
        {

            if(locations_visited[wish_well]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to The Wish Well"<<endl;
               current_location=wish_well;
            }
        }
        else if( operand.substr(0)=="m" && (operand.substr(operand.length()-1))=="e")
        {

            if(locations_visited[mermaid_cove]==false)
            {
                cout<<"You cannot do that at this time."<<endl;
            }
            else
            {
               cout<<"You have returned to Mermaid Cove"<<endl;
               current_location=mermaid_cove;
            }
        }
    // the get command
    else if((event=="get" || event=="Get") && !operand.empty())
        {

            for(i=0;i<15;i++)
            {
                if(falconsKeep.items[i]==operand && LEROY.inventory[i]=="")
                {
                    LEROY.inventory[i]=mermaidCove.items[i];
                    falconsKeep.items[i]="";
                }
                else if ((falconsKeep.items[i]==operand)&& !(LEROY.inventory[i]==""))
                {
                    int k = i;
                    for (k=i;k<7;k++)
                    {
                        if(LEROY.inventory[k]=="")
                        {
                            LEROY.inventory[k]=falconsKeep.items[i];
                            falconsKeep.items[i]="";
                            itemsGained[i]=true;
                            k=7;
                        }
                         else
                        {
                            cout<<"This item isn' t available here."<<endl;
                            k=7;
                        }
                    }

                }

            }

        }

    // the drop command
    else if((event=="drop" || event=="Drop") && !operand.empty())
        {
            for(i=0;i<7;i++)
            {
                if((LEROY.inventory[i]==operand)&& (falconsKeep.items[i]==""))
                {
                    falconsKeep.items[i]=LEROY.inventory[i];
                    LEROY.inventory[i]= "";
                    itemsGained[i]=false;
                }
                else if ((LEROY.inventory[i]==operand)&& !(falconsKeep.items[i]==""))
                {
                    int j = i;
                    for(j=i;j<15;j++)
                        {
                            if(falconsKeep.items[j]=="")
                            {
                                falconsKeep.items[j]=LEROY.inventory[i];
                                LEROY.inventory[i]= "";
                                itemsGained[i]=false;
                                j=7;
                            }
                            else
                            {
                                cout<<"This item can't be dropped at this time"<<endl;
                                j=7;
                            }
                        }
                }


            }

        }
        // the use command

    else if (event == "use" || event =="Use")
        {

         if (operand=="fish"&& itemsGained[fish]==true)
         {
             cout<<"You hold up the fish. The falcon that you had previously spoken too swoops down collecting the fish and leaving a mirror in its place."<<endl;
             itemsGained[mirror]=true;
             itemsGained[fish]=false;

         }

        }
    else if(event=="look" || event=="Look")
    {
        if(operand=="rocks")
        {
            cout<<"you see a mirror perched on the rocks above you"<<endl;
        }
        else if (operand=="handle"&& itemsGained[handle]==true)
        {
            cout<<"This appears to be a very well made handle that any tool maker would love to turn into a full tool. However, being that the handle doesn't have anything attached to it it is currently useless."<<endl;
        }
        else if (operand=="key" && itemsGained[key]==true)
        {
            cout<<" You notice that the key is made of solid steel and has an acorn crest etched into it."<<endl;
        }
        else if(operand=="fish"&& itemsGained[fish]==true)
        {
            cout<<"You cant place why you think this but for some reason the fish looks exceptionally tasty."<<endl;
        }
        else if(operand=="shovel" && itemsGained[shovel]==true)
        {
            cout<<"The shovel begins to tell you its life story. Amongst the information the shovel says that its always dreamed of being used to dig up treasure. You must have been hit on the head really hard"<<endl;
        }
        else if(operand=="mirror" && itemsGained[mirror]==true)
        {
            cout<<"You gaze upon yourself in the mirror. As your eyes begin to water you notice that there is a tatoo of an acorn crest on your forehead."<<endl;
        }
    }
    else
        {
         cout<<"I'm sorry you can't do that right now."<<endl;
        }


    }
return;
}
