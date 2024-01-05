#ifndef HEADER_MENU_H
#define HEADER_MENU_H
#include <iostream>
#include <string>
#include "Header.h"
using namespace std;


class MenuNodeCLL{
    public:
    MenuNodeCLL(){
        next = nullptr;
        previous = nullptr;
        MenuData = "";
    }
    MenuNodeCLL(string dt, Options op){
        next = nullptr;
        previous = nullptr;
        MenuData = dt;
        MenuOp = op;
    }
    ~MenuNodeCLL(){}
    MenuNodeCLL* next;
    MenuNodeCLL* previous;
    string MenuData;
    Options MenuOp;
};

class MenuProgram{
    public: 
    MenuProgram(){
        Title1 = "|(*)Add Category|";
        Title2 = "|(*)Add to a Category|";
        Title3 = "|(*)Quit|";
        Title4 = "|(*)Delete Movie/Category|";
        CurrentPositon = nullptr;
        head_Menu = nullptr;
        tail_Menu = nullptr;
        command = "";
        Command_Data_Cat = "";
        Data_Category = 0;
        IsMenuOn = true;
    }
    void MenuInsert(string PositionInMenu, Options MenuOption);
    void MenuSetup();
    void RunOption(Options o);
    void MenuProg();
    void PrintMenu();
    bool GetBoolStatement(){return IsMenuOn;}

    private:
    MenuNodeCLL* head_Menu;
    MenuNodeCLL* tail_Menu;
    MenuNodeCLL* CurrentPositon;
    string Title1;
    string Title2; 
    string Title3;
    string Title4;
    string command;
    string Command_Data_Cat;
    int Data_Category;
    bool IsMenuOn;
    CLL MovieAndCategoryClass;

};

#endif
