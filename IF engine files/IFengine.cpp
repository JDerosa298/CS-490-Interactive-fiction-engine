#include<iostream>
#include"sqlite3.h"
#include<stdlib.h>

using namespace std;

int main(int argc, char * argv[])
{
    sqlite3 * Mansion;
    int success = sqlite3_open(argv[1] , &Mansion);
    return(EXIT_SUCCESS);
}