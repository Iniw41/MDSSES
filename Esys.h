#ifndef ESYS_H
#define ESYS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int StudentID;
    char Fullname[256];
    char Program[64];
    int Yearlevel;
    float GPA;
    struct Node* next;
} StudentList;

typedef StudentList* Node;

// Function Prototypes
Node createStudent(int id, char* name, char* prog, int year, float gpa);
int isDuplicate(Node head, int id);
void regularEnrollment(Node* head, int id, char* name, char* prog, int year, float gpa);
void priorityEnrollment(Node* head, int id, char* name, char* prog, int year, float gpa);
void manualInsert(Node* head, int id, char* name, char* prog, int year, float gpa, int pos);
void lateEnrollment(Node* head, int id, char* name, char* prog, int year, float gpa);
void displayAll(Node head);
void searchStudent(Node head, int id);
void deleteStudent(Node* head, int id);
int countStudents(Node head);
void promoteYear(Node* head);
void computeAverageGPA(Node head);
void displayTopN(Node head, int n);
void reverseList(Node* head);

#endif
