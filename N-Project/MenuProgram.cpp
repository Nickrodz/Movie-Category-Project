#include <iostream>
#include <string>
#include "Header.h"
#include "Header_Menu.h"
#include <conio.h>
#include <windows.h>
using namespace std;



void MenuProgram::MenuInsert(string PositionInMenu, Options MenuOption){
    MenuNodeCLL* tmp = new MenuNodeCLL(PositionInMenu, MenuOption);
    if(head_Menu == nullptr){
        head_Menu = tmp;
        tail_Menu = tmp;
    } else {
        tail_Menu->next = tmp;
        tmp->previous = tail_Menu;
        head_Menu->previous = tmp;
        tmp->next = head_Menu;
        tail_Menu = tmp;
    }
}

void MenuProgram::MenuSetup(){
    MenuInsert(Title1, Option1);
    MenuInsert(Title2, Option2); 
    MenuInsert(Title3, Option3);
    MenuInsert(Title4, Option4);
    CurrentPositon = head_Menu;
    CurrentPositon->MenuData[1] = '>';
    CurrentPositon->MenuData[3] = '<';
}

void MenuProgram::MenuProg(){
    

    if(_kbhit()){
        switch(_getch()){
            case 'a':
               head_Menu->MenuData = Title1;
               head_Menu->next->MenuData = Title2;
               head_Menu->next->next->MenuData = Title3;
               head_Menu->next->next->next->MenuData = Title4;
               CurrentPositon = CurrentPositon->previous;
               CurrentPositon->MenuData[1] = '>';
               CurrentPositon->MenuData[3] = '<';
            break;
            case 'd':
               head_Menu->MenuData = Title1;
               head_Menu->next->MenuData = Title2;
               head_Menu->next->next->MenuData = Title3;
               head_Menu->next->next->next->MenuData = Title4;
               CurrentPositon = CurrentPositon->next;
               CurrentPositon->MenuData[1] = '>';
               CurrentPositon->MenuData[3] = '<';
            break;
            case 'x':
                RunOption(CurrentPositon->MenuOp);
            break;
        }
        system("CLS");
        PrintMenu();
        MovieAndCategoryClass.DisplayDLL();
    }
}



void MenuProgram::RunOption(Options o){

    switch (o)
    {
    case Option1:
        cout << "Enter the name of the category you would like to add" << endl;
        getline(cin, command);
        MovieAndCategoryClass.InsertDLL(command);
        break;
    case Option2:
        cout << "Enter what you would like to insert in that category" << endl;
        getline(cin, command);
        cout << "Enter the Position number of the category" << endl;
        getline(cin, Command_Data_Cat);
        if(Command_Data_Cat[0] > 58 || Command_Data_Cat[0] < 48 || Command_Data_Cat.length() > 2){
            cout << "Error Invalid Input" << endl;
            Sleep(1000);
            break;
        }
        Data_Category = stoi(Command_Data_Cat);
        if(Data_Category > MovieAndCategoryClass.getSizes() || Data_Category == 0){
            cout << "Error Number for Category doesn't exist" << endl;
            Sleep(1000);
            break;
        }
        MovieAndCategoryClass.PositionDLL(Data_Category - 1, command);
        break;
    case Option3:
        IsMenuOn = false;
        break;
    case Option4:
        system("CLS");
        MovieAndCategoryClass.MovieMenuSetup();
        MovieAndCategoryClass.DisplayDLL();
        while(MovieAndCategoryClass.GetBoolStateMent_MovieCategory()){
            MovieAndCategoryClass.MovieAndCategoryMenuProg();
        }
        system("CLS");
        PrintMenu();
        MovieAndCategoryClass.DisplayDLL();
        break;
    }

}




void MenuProgram::PrintMenu(){
    cout << "-----------------" << " " << "----------------------" << " " << "---------" << " " << "--------------------------" << endl;
    cout << head_Menu->MenuData << " " << head_Menu->next->MenuData << " " << head_Menu->next->next->MenuData << " " << head_Menu->next->next->next->MenuData<< endl;
    cout << "-----------------" << " " << "----------------------" << " " << "---------" << " " << "--------------------------" << endl;
}