#include <stdio.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    studentNode *next;
};

class LinkedList {
protected:
    struct studentNode *start, **now;

public:
    LinkedList(); 
    ~LinkedList(); 
    void InsNode(char n[], int a, char s, float g); 
    void DelNode(); 
    void GoNext(); 
    virtual void ShowNode(); 
};

class NewList : public LinkedList {
public:
    void GoFirst(); 
    virtual void ShowNode(); 
};

LinkedList::LinkedList() {
    start = NULL;
    now = &start;
}

LinkedList::~LinkedList() {
    struct studentNode *temp;
    while (start != NULL) {
        temp = start;
        start = start->next;
        delete temp;
    }
}

void LinkedList::InsNode(char n[], int a, char s, float g) {
    *now = new studentNode;
    strcpy((*now)->name, n);
    (*now)->age = a;
    (*now)->sex = s;
    (*now)->gpa = g;
    (*now)->next = NULL;
    now = &((*now)->next);
}

void LinkedList::DelNode() {
    struct studentNode *temp;
    if (*now != NULL) {
        temp = *now;
        *now = (*now)->next;
        delete temp;
    }
    else {
        now = &start;
    }
}

void LinkedList::GoNext() {
    if (*now != NULL) {
        now = &((*now)->next);
    }
}

void LinkedList::ShowNode() {
    if (*now != NULL) {
        printf("%s %d %c %.2f\n", (*now)->name, (*now)->age, (*now)->sex, (*now)->gpa);
    }
}

void NewList::GoFirst() {
    now = &start;
}

void NewList::ShowNode() {
    struct studentNode *temp = start;
    while (temp != NULL) {
        printf("%s %d %c %.2f\n", temp->name, temp->age, temp->sex, temp->gpa);
        temp = temp->next;
    }
}

int main() {
    LinkedList listA;
    NewList listB;
    LinkedList *listC;

    listA.InsNode("one", 1, 'A', 1.1);
    listA.InsNode("two", 2, 'B', 2.2);
    listA.InsNode("three", 3, 'C', 3.3);
    listA.GoNext();
    listA.ShowNode();

    listB.InsNode("four", 4, 'D', 4.4);
    listB.InsNode("five", 5, 'E', 5.5);
    listB.InsNode("six", 6, 'F', 6.6);
    listB.DelNode();
    listB.ShowNode();

    listC = &listA;
    listC->GoNext();
    listC->ShowNode();

    listB.GoFirst();
    listB.ShowNode();

    return 0;
}

