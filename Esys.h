#ifndef ESYS_H
#define ESYS_H

#include <string.h>

typedef struct Node {
    int StudentID;
    char Fullname[256];
    char Program[64];
    int Yearlevel;
    float GPA;
    struct Node* next;
} StudentList;

// Define 'Node' as a pointer to that struct
typedef StudentList* Node;

// PROTOTYPE: Must return 'Node' (which is StudentList*)
Node createStudent(int id, char* name, char* prog, int year, float gpa);

#endif
