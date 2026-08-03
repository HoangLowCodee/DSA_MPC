#include<iostream>
using namespace std;
struct Svien{
    string ten,ms;
    char DoB={11};
    char queQuan={100};
};
struct Node{
    Node*next;
    Svien inf;
};
struct List{
    Node*head;
};
void init(List&l){
l.head=nullptr;
}
bool isEmpty(List &l){
    return l.head==nullptr;
}

    
