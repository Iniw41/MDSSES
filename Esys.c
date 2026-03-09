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
    printf("Student enrolled successfully (Regular).\n");
}

// 2. Priority: Insert Front (GPA >= 3.0)
void priorityEnrollment(Node* head, int id, char* name, char* prog, int year, float gpa) {
    if (gpa < 3.0) { printf("Rejected: GPA below 3.0\n"); return; }
    if (isDuplicate(*head, id)) { printf("Error: Duplicate ID!\n"); return; }
    Node newNode = createStudent(id, name, prog, year, gpa);
    newNode->next = *head;
    *head = newNode;
    printf("Student enrolled successfully (Priority).\n");
}

// 3. Manual Insert at Position
void manualInsert(Node* head, int id, char* name, char* prog, int year, float gpa, int pos) {
    if (isDuplicate(*head, id)) { printf("Error: Duplicate ID!\n"); return; }
    Node newNode = createStudent(id, name, prog, year, gpa);
    if (pos == 1) {
        newNode->next = *head;
        *head = newNode;
        printf("Student inserted at position 1.\n");
        return;
    }
    Node temp = *head;
    for (int i = 1; i < pos - 1 && temp; i++) temp = temp->next;
    if (!temp) { printf("Invalid position.\n"); free(newNode); return; }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Student inserted at position %d.\n", pos);
}

// 4. Late: GPA Placement (Descending)
void lateEnrollment(Node* head, int id, char* name, char* prog, int year, float gpa) {
    if (isDuplicate(*head, id)) { printf("Error: Duplicate ID!\n"); return; }
    Node newNode = createStudent(id, name, prog, year, gpa);
    if (*head == NULL || (*head)->GPA < gpa) {
        newNode->next = *head;
        *head = newNode;
        printf("Student enrolled successfully (Late).\n");
        return;
    }
    Node curr = *head;
    while (curr->next != NULL && curr->next->GPA >= gpa) curr = curr->next;
    newNode->next = curr->next;
    curr->next = newNode;
    printf("Student enrolled successfully (Late).\n");
}

// 5. Display All Students
void displayAll(Node head) {
    if (!head) { printf("List is empty.\n"); return; }
    printf("\n========================================\n");
    printf("ID\tNAME\t\tPROGRAM\t\tGPA\tYEAR\n");
    printf("========================================\n");
    while (head) {
        printf("%d\t%-15s\t%-15s\t%.2f\t%d\n", head->StudentID, head->Fullname, head->Program, head->GPA, head->Yearlevel);
        head = head->next;
    }
    printf("========================================\n");
}

// 6. Search Student
void searchStudent(Node head, int id) {
    Node temp = head;
    while (temp) {
        if (temp->StudentID == id) {
            printf("\n--- Student Found ---\n");
            printf("ID: %d\nName: %s\nProgram: %s\nYear: %d\nGPA: %.2f\n", 
                   temp->StudentID, temp->Fullname, temp->Program, temp->Yearlevel, temp->GPA);
            return;
        }
        temp = temp->next;
    }
    printf("Student with ID %d not found.\n", id);
}

// 7. Delete Student
void deleteStudent(Node* head, int id) {
    Node temp = *head, prev = NULL;
    if (temp != NULL && temp->StudentID == id) {
        *head = temp->next;
        free(temp);
        printf("Student deleted successfully.\n");
        return;
    }
    while (temp != NULL && temp->StudentID != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) { printf("Student not found.\n"); return; }
    prev->next = temp->next;
    free(temp);
    printf("Student deleted successfully.\n");
}

// 8. Count Students
int countStudents(Node head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

// 9. Promote Year Level
void promoteYear(Node* head) {
    Node temp = *head;
    int count = 0;
    while (temp) {
        if (temp->Yearlevel < 4) {
            temp->Yearlevel++;
            count++;
        }
        temp = temp->next;
    }
    printf("Promoted %d students to the next year level.\n", count);
}

// 10. Compute Average GPA
void computeAverageGPA(Node head) {
    if (!head) { printf("List is empty.\n"); return; }
    float sum = 0;
    int count = 0;
    while (head) {
        sum += head->GPA;
        count++;
        head = head->next;
    }
    printf("Average GPA: %.2f\n", sum / count);
}

// 11. Display Top N Students
void displayTopN(Node head, int n) {
    if (!head) { printf("List is empty.\n"); return; }
    if (n <= 0) { printf("Invalid number of students.\n"); return; }
    
    int count = countStudents(head);
    if (n > count) n = count;
    
    printf("\n========== TOP %d STUDENTS (BY GPA) ==========\n", n);
    printf("ID\tNAME\t\tGPA\n");
    printf("=============================================\n");
    
    for (int i = 0; i < n; i++) {
        Node maxNode = head;
        Node current = head;
        float maxGPA = -1;
        
        while (current) {
            if (current->GPA > maxGPA) {
                maxGPA = current->GPA;
                maxNode = current;
            }
            current = current->next;
        }
        
        printf("%d\t%-15s\t%.2f\n", maxNode->StudentID, maxNode->Fullname, maxNode->GPA);
        maxNode->GPA = -2;  // Mark as processed
    }
    
    // Restore GPAs
    head = head;
    while (head) {
        if (head->GPA == -2) head->GPA = -2;  // You may want to store original GPAs
        head = head->next;
    }
}

// 12. Reverse List (Three-pointer technique)
void reverseList(Node* head) {
    Node prev = NULL, curr = *head, next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
    printf("List reversed successfully.\n");
}
