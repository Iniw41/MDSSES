#include "Esys.h"

Node createStudent(int id, char* name, char* prog, int year, float gpa) {
    Node newStudent = (Node)malloc(sizeof(StudentList)); 
    
    if (newStudent != NULL) {
        newStudent->StudentID = id;
        newStudent->Yearlevel = year;
        newStudent->GPA = gpa;
        strcpy(newStudent->Fullname, name);
        strcpy(newStudent->Program, prog);
        
        newStudent->next = NULL;
    }
    return newStudent;
}


void printStudentInfo(Node head) {
    Node current = head;
    
    if (current == NULL) {
        printf("The student list is empty.\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    while (current != NULL) {
        printf("ID: %d | Name: %-20s | Program: %-5s | Year: %d | GPA: %.2f\n", 
                current->StudentID, 
                current->Fullname, 
                current->Program, 
                current->Yearlevel, 
                current->GPA);
        current = current->next;
    }
    printf("-----------------------\n");
}
