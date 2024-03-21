#include <stdio.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
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
    void GoFirst();
    void GoLast();
    void ShowAll();
    int FindNode(char n[]);
    struct studentNode *NowNode();
    void EditNode(char n[], int a, char s, float g);
};

void EditData(LinkedList *ll);
void AddData(LinkedList *ll);
void FindData(LinkedList *ll);
void readfile(LinkedList *ll);
void writefile(LinkedList *ll);

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
    struct studentNode *temp;
    temp = new studentNode;
    strcpy(temp->name, n);
    temp->age = a;
    temp->sex = s;
    temp->gpa = g;
    temp->next = NULL;

    *now = temp;
    now = &((*now)->next);
}

struct studentNode *LinkedList::NowNode() {
    return *now;
}

void LinkedList::DelNode() {
    if (start == NULL)
        return;
    struct studentNode *temp = start;
    start = start->next;
    delete temp;
}

void LinkedList::ShowAll() {
    struct studentNode *temp = start;
    while (temp != NULL) {
        printf("Name: %s, Age: %d, Sex: %c, GPA: %.2f\n", temp->name, temp->age, temp->sex, temp->gpa);
        temp = temp->next;
    }
}

int LinkedList::FindNode(char n[]) {
    struct studentNode *temp = start;
    while (temp != NULL) {
        if (strcmp(temp->name, n) == 0) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void LinkedList::EditNode(char n[], int a, char s, float g) {
    struct studentNode *temp = start;
    while (temp != NULL) {
        if (strcmp(temp->name, n) == 0) {
            temp->age = a;
            temp->sex = s;
            temp->gpa = g;
            break;
        }
        temp = temp->next;
    }
}

void EditData(LinkedList *ll) {
    char name[20];
    int age;
    char sex;
    float gpa;
    printf("Enter the name of the student to edit: ");
    scanf("%s", name);
    if (ll->FindNode(name)) {
        printf("Enter new age: ");
        scanf("%d", &age);
        printf("Enter new sex: ");
        scanf(" %c", &sex);
        printf("Enter new GPA: ");
        scanf("%f", &gpa);
        ll->EditNode(name, age, sex, gpa);
        printf("Data edited successfully.\n");
    } else {
        printf("Student not found.\n");
    }
}

void AddData(LinkedList *ll) {
    char name[20];
    int age;
    char sex;
    float gpa;
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter age: ");
    scanf("%d", &age);
    printf("Enter sex: ");
    scanf(" %c", &sex);
    printf("Enter GPA: ");
    scanf("%f", &gpa);
    ll->InsNode(name, age, sex, gpa);
    printf("Data added successfully.\n");
}

void FindData(LinkedList *ll) {
    char name[20];
    printf("Enter the name of the student to find: ");
    scanf("%s", name);
    if (ll->FindNode(name)) {
        printf("Student found.\n");
    } else {
        printf("Student not found.\n");
    }
}

void readfile(LinkedList *ll) {
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char name[20];
    int age;
    char sex;
    float gpa;

    while (fscanf(fp, "%s %d %c %f", name, &age, &sex, &gpa) == 4) {
        ll->InsNode(name, age, sex, gpa);
    }

    fclose(fp);
}

void writefile(LinkedList *ll) {
    FILE *fp = fopen("students.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    struct studentNode *current = ll->NowNode();
    while (current != NULL) {
        fprintf(fp, "%s %d %c %.2f\n", current->name, current->age, current->sex, current->gpa);
        current = current->next;
    }

    fclose(fp);
}

int main() {
    LinkedList listA;
    int menu;
    readfile(&listA);
    printf("Menu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Exit: ");
    scanf("%d", &menu);
    while (menu != 0) {
        switch (menu) {
            case 1: AddData(&listA); break;
            case 2: EditData(&listA); break;
            case 3: listA.DelNode(); break;
            case 4: FindData(&listA); break;
            case 5: listA.ShowAll(); break;
            default: printf("Invalid choice\n"); break;
        }
        printf("Menu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Exit: ");
        scanf("%d", &menu);
    }
    writefile(&listA);
    return 0;
}

