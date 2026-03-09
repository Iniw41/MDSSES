#include "Esys.h"

int main() {
    Node head = NULL;
    int choice, id, year, pos;
    char name[256], prog[64];
    float gpa;

    while (1) {
        printf("\n===== SMART ENROLLMENT SYSTEM =====\n");
        printf("1. Regular Enrollment\n2. Priority Enrollment\n4. Late Enrollment\n5. Display All\n7. Delete Student\n12. Reverse List\n13. Exit\nChoice: ");
        scanf("%d", &choice);

        if (choice == 13) break;

        if (choice == 1 || choice == 2 || choice == 4) {
            printf("Enter ID, Name, Program, Year, GPA: ");
            scanf("%d %s %s %d %f", &id, name, prog, &year, &gpa);
        }

        switch (choice) {
            case 1: regularEnrollment(&head, id, name, prog, year, gpa); break;
            case 2: priorityEnrollment(&head, id, name, prog, year, gpa); break;
            case 4: lateEnrollment(&head, id, name, prog, year, gpa); break;
            case 5: displayAll(head); break;
            case 7: printf("ID to delete: "); scanf("%d", &id); deleteStudent(&head, id); break;
            case 12: reverseList(&head); break;
        }
    }
    return 0;
}

