#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include "Header.h"
#include <conio.h>
#include "Header_Menu.h"
using namespace std;



void CLL::InsertCLL(string x, CLLNode* pos, int s){
    CLLNode* tmp = new CLLNode(x, Movie);
    head = pos;
    tail = pos;
    for(int i = 0; i < Sizes.at(s) - 1; ++i){
        tail = tail->next;
    }
    tail->next = tmp;
    tmp->previous = tail;
    tmp->next = head;
    head->previous = tmp;
    tail = tmp;     
        /*
        up = prev
        down = next
        headup = head
        headdown = tail
        */
}

void CLL::DeletePosCLL(int pos, int pos2){  
    CLLNode* tmp = HeadUp;
    for(int i = 0; i < pos; ++i){
        tmp = tmp->down;
    }
    CLLNode* tmp2 = tmp;
    for(int j = 0; j < pos2; ++j){
        tmp = tmp->next;
    }
    if(tmp->next == nullptr){
        tmp->previous->next = tmp2;
        tmp2->previous = tmp->previous;
        tmp->next = nullptr;
        tmp->previous = nullptr;
        Sizes.at(pos)--;
        delete tmp;
    } else {
    tmp->next->previous = tmp->previous;
    tmp->previous->next = tmp->next;
    Sizes.at(pos)--;
    delete tmp;

    }
}


void CLL::DeletePosDLL(int pos){
    CLLNode* tmp = HeadUp;
    for(int i = 0; i < pos; ++i){ 
        tmp = tmp->down;
    }

    if(tmp->next != nullptr){
            int NumOfMovies = Sizes.at(pos);
         for(int j = NumOfMovies; j > 0; --j){
            DeletePosCLL(pos, j);
         }
    }

     if(tmp->up == nullptr && tmp->down == nullptr){
        HeadUp = nullptr;
        HeadDown = nullptr;
        Sizes.erase(next(Sizes.begin(), pos));
        delete tmp;
    } else if(tmp->down == nullptr){
        HeadDown = HeadDown->up;
        HeadDown->down = nullptr;
        tmp->up = nullptr;
        Sizes.erase(next(Sizes.begin(), pos));
        delete tmp;
     } else if(tmp->up == nullptr){
        HeadUp = HeadUp->down;
        tmp->down->up = nullptr;
        tmp->down = nullptr;
        Sizes.erase(next(Sizes.begin(), pos));
     } else {
        tmp->down->up = tmp->up;
         tmp->up->down = tmp->down;
        Sizes.erase(next(Sizes.begin(), pos));
        delete tmp;
        }
}

void CLL::InsertDLL(string x){
    CLLNode* tmp = new CLLNode(x, Category);
    if(HeadUp == nullptr){
        HeadUp = tmp;
        HeadDown = tmp;
    } else {
        HeadDown->down = tmp;
        tmp->up = HeadDown;
        HeadDown = tmp;
    }
    Sizes.push_back(0);
}

void CLL::PositionDLL(int pos, string x){
    CLLNode* p = HeadUp;
    for(int i = 0; i < pos; ++i){
        p = p->down;
    }
    Sizes.at(pos)++;
    InsertCLL(x, p, pos);
}



void CLL::DisplayDLL(){
CLLNode* p = HeadUp;
int Current_for_sizes = 0;
    while(p != nullptr){
        cout << Current_for_sizes + 1 << ": |" << p->data << "| ";
        CLLNode* p2 = p;
        if(p2->next != nullptr){
            p2 = p2->next; 
            for(int i = 0; i < Sizes.at(Current_for_sizes); ++i){ 
                cout <<  "[" << p2->data << "] ";
                p2 = p2->next;
            }
        }
        cout << endl;
        Current_for_sizes++;
        p = p->down;
    }
      cout << "y:" << y  << "x:" << x << endl;
}


void CLL::MovieMenuSetup(){
    if(HeadUp == nullptr){
        cout << "There is nothing to delete" << endl;
        Sleep(1000);
        MovieAndCategoryDeletion = false;
        return;
    }
    Current_Postion = HeadUp;
    P_Position = Current_Postion->down;
    c = Current_Postion->data[0]; 
    MovieAndCategoryDeletion = true;
    Current_Postion->data[0] = '#';
    Deletion = true;
    y = 0;
    x = 0;
}


void CLL::MovieAndCategoryMenuProg(){
    int Original_y = y;
    int Original_x = x;
        if(_kbhit()){
        switch(_getch()){
            case 'a':
              if(Current_Postion->previous == nullptr){
                break;
            }else {
            P_Position = Current_Postion;
            P_Position->data[0] = c;
            Current_Postion = Current_Postion->previous;
            c = Current_Postion->data[0];
            Current_Postion->data[0] = '#';
                --x;
            }
            break;
            case 'd':
               if(Current_Postion->next == nullptr){
                break;
            }else {
            P_Position = Current_Postion;
            P_Position->data[0] = c;
            Current_Postion = Current_Postion->next;
            c = Current_Postion->data[0];
            Current_Postion->data[0] = '#';
                ++x;
            }
            break;
            case 'w':
            if(Current_Postion->up == nullptr){
                break;
            }else {
            P_Position = Current_Postion;
            P_Position->data[0] = c;
            Current_Postion = Current_Postion->up;
            c = Current_Postion->data[0];
            Current_Postion->data[0] = '#';
                --y;
            }
            break;
            case 's':
            if(Current_Postion->down == nullptr){
                break;
            }else {
            P_Position = Current_Postion;
            P_Position->data[0] = c;
            Current_Postion = Current_Postion->down;
            c = Current_Postion->data[0];
            Current_Postion->data[0] = '#';
                ++y;
            }
            break;
            case 'x':
              if(Current_Postion->Type == Movie) {
                    DeletePosCLL(y, x);
                    MovieAndCategoryDeletion = false;
                    Deletion = false;
              } else if(Current_Postion->Type == Category){
                    DeletePosDLL(y);           
                    MovieAndCategoryDeletion = false;
                    Deletion = false;
              }
            break;
        }
        if(Deletion){
            if(y > Sizes.size()){
            y = Original_y;
        } else if(y < 0){
            y = Original_y;
        }

        if(x > Sizes.at(y)){
            x = 0;
        } else if(x < 0){
            x = Sizes.at(y);
          } 
        }
        
       system("CLS");
        DisplayDLL();
       
    }


}




