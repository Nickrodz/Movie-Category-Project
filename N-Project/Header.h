#ifndef HEADER_H
#define HEADER_H    
#include <iostream>
#include <vector>
#include <string>
using namespace std;


enum Options{
    Option1,
    Option2,
    Option3,
    Option4,
    Movie,
    Category
};

class CLLNode{
    public:
    CLLNode(){
        data = "";
        next = nullptr;
        previous = nullptr;
        up = nullptr;
        down = nullptr;
    }
    CLLNode(string dt, Options o){
        data = dt;
        next = nullptr;
        previous = nullptr;
        up = nullptr;
        down = nullptr;
        Type = o;
    }
    ~CLLNode(){}
    CLLNode* next;
    CLLNode* previous;
    CLLNode* up;
    CLLNode* down;
    string data; 
    Options Type;
};


class CLL{
public: 
    CLL(){
        head = nullptr;
        tail = nullptr; 
        HeadUp = nullptr;
        HeadDown = nullptr;
        MovieAndCategoryDeletion = true;
        y = 0;
        x = 0;
        c = ' ';
    }
    void InsertCLL(string x, CLLNode* pos, int s);
    void InsertDLL(string x);
    void PositionDLL(int pos, string x);
    void DeletePosCLL(int pos, int pos2);
    void DeletePosDLL(int pos);
    bool GetBoolStateMent_MovieCategory(){return MovieAndCategoryDeletion;}
    void MovieMenuSetup();
    int getSizes(){return Sizes.size();}
    void MovieAndCategoryMenuProg();
    void DisplayDLL();



private:
    int x;
    int y;
    char c;
    CLLNode* head;
    CLLNode* tail;
    CLLNode* HeadUp;
    CLLNode* HeadDown;
    CLLNode* Current_Postion;
    CLLNode* P_Position;
    bool MovieAndCategoryDeletion;
    bool Deletion;
    vector<int> Sizes;
};



#endif
