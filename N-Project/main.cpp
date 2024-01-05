#include <iostream>
#include <vector>
#include "Header.h"
#include "Header_Menu.h"
#include <stdlib.h>
#include <string>
using namespace std;


int main(){

 
   MenuProgram Menu;
    Menu.MenuSetup();
    Menu.PrintMenu();
    while(Menu.GetBoolStatement()){
        Menu.MenuProg();
   }
 
    return 0;
}