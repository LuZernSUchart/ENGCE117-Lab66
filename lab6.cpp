#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
    struct studentNode *back;
};

void ShowAll(struct studentNode *walk);
struct studentNode* AddNode(struct studentNode **start, char name[], int age, char sex, float gpa);
void InsNode(struct studentNode *now, char name[], int age, char sex, float gpa);
void DelNode(struct studentNode **now);
void GoBack(struct studentNode **now);

int main() {
    struct studentNode *start, *now;
    start = NULL;
    now = AddNode(&start, "one", 6, 'M', 3.11);
    ShowAll(start);
    now = AddNode(&start, "two", 8, 'F', 3.22);
    ShowAll(start);
    InsNode(now, "three", 10, 'M', 3.33);
    ShowAll(start);
    InsNode(now, "four", 12, 'F', 3.44);
    ShowAll(start);
    GoBack(&now);
    DelNode(&now);
    ShowAll(start);
    DelNode(&now);
    ShowAll(start);
    DelNode(&now);
    ShowAll(start);
    return 0;
}

struct studentNode* AddNode(struct studentNode **start, char name[], int age, char sex, float gpa) {
    struct studentNode *newNode = (struct studentNode*)malloc(sizeof(struct studentNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;
    newNode->next = NULL;
    newNode->back = *start;

    if (*start == NULL) {
        *start = newNode;
    }
    else {
        struct studentNode *temp = *start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return newNode;
}

void InsNode(struct studentNode *now, char name[], int age, char sex, float gpa) {
    struct studentNode *newNode = (struct studentNode*)malloc(sizeof(struct studentNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;
    newNode->next = now;

    if (now->back != NULL) {
        now->back->next = newNode;
    }
    now->back = newNode;
}

void DelNode(struct studentNode **now) {
    if (*now == NULL) {
        printf("Cannot delete, current node is NULL.\n");
        return;
    }

    struct studentNode *temp = *now;
    if (temp->back != NULL) {
        temp->back->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->back = temp->back;
        *now = temp->next;
    }
    else {
        *now = temp->back;
    }
    free(temp);
}

void GoBack(struct studentNode **now) {
    if (*now != NULL && (*now)->back != NULL) {
        *now = (*now)->back;
    }
}

void ShowAll(struct studentNode *walk) {
    while (walk != NULL) {
        printf("%s ", walk->name);
        walk = walk->next;
    }
    printf("\n");
}
