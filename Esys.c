#include "Esys.h"

Node createStudent(int id, char* name, char* prog, int year, float gpa) {
    Node newNode = (Node)malloc(sizeof(StudentList));
    if (newNode) {
        newNode->StudentID = id;
        strcpy(newNode->Fullname, name);
        strcpy(newNode->Program, prog);
        newNode->Yearlevel = year;
        newNode->GPA = gpa;
        newNode->next = NULL;
    }
    return newNode;
}

int isDuplicate(Node head, int id) {
    Node temp = head;
    while (temp) {
        if (temp->StudentID == id) return 1;
        temp = temp->next;
    }
    return 0;
}

// 1. Regular: Insert End
void regularEnrollment(Node* head, int id, char* name, char* prog, int year, float gpa) {
    if (isDuplicate(*head, id)) { printf("Error: Duplicate ID!\n"); return; }
    Node newNode = createStudent(id, name, prog, year, gpa);
    if (*head == NULL) { *head = newNode; return; }
    Node temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

// 2. Priority: Insert Front (GPA >= 3.0)
void priorityEnrollment(Node* head, int id, char* name, char* prog, int year, float gpa) {
    if (gpa < 3.0) { printf("Rejected: GPA below 3.0\n"); return; }
    if (isDuplicate(*head, id)) { printf("Error: Duplicate ID!\n"); return; }
    Node newNode = createStudent(id, name, prog, year, gpa);
    newNode->next = *head;
    *head = newNode;
}

// 4. Late: GPA Placement (Descending)
void lateEnrollment(Node* head, int id, char* name, char* prog, int year, float gpa) {
    if (isDuplicate(*head, id)) { printf("Error: Duplicate ID!\n"); return; }
    Node newNode = createStudent(id, name, prog, year, gpa);
    if (*head == NULL || (*head)->GPA < gpa) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    Node curr = *head;
    while (curr->next != NULL && curr->next->GPA >= gpa) curr = curr->next;
    newNode->next = curr->next;
    curr->next = newNode;
}

// 7. Delete Logic
void deleteStudent(Node* head, int id) {
    Node temp = *head, prev = NULL;
    if (temp != NULL && temp->StudentID == id) {
        *head = temp->next; free(temp);
        printf("Deleted successfully.\n"); return;
    }
    while (temp != NULL && temp->StudentID != id) {
        prev = temp; temp = temp->next;
    }
    if (temp == NULL) { printf("Not found.\n"); return; }
    prev->next = temp->next; free(temp);
}

// 12. Reverse (Three-pointer technique)
void reverseList(Node* head) {
    Node prev = NULL, curr = *head, next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
    printf("List reversed.\n");
}

// Note: Add displayAll, count, average, etc. using basic traversal logic.
void displayAll(Node head) {
    if (!head) { printf("List is empty.\n"); return; }
    printf("\nID\tNAME\t\tGPA\tYEAR\n------------------------------------\n");
    while (head) {
        printf("%d\t%-15s\t%.2f\t%d\n", head->StudentID, head->Fullname, head->GPA, head->Yearlevel);
        head = head->next;
    }
}
