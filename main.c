#include "Esys.h"

int main() {
    Node head = NULL;
    int choice, id, year, pos, n;
    char name[256], prog[64];
    float gpa;

    while (1) {
        printf("\n===== SMART ENROLLMENT SYSTEM =====\n");
        printf("1.  Regular Enrollment\n");
        printf("2.  Priority Enrollment\n");
        printf("3.  Manual Insert\n");
        printf("4.  Late Enrollment\n");
        printf("5.  Display All Students\n");
        printf("6.  Search Student\n");
        printf("7.  Delete Student\n");
        printf("8.  Count Students\n");
        printf("9.  Promote Year Level\n");
        printf("10. Compute Average GPA\n");
        printf("11. Display Top N Students\n");
        printf("12. Reverse List\n");
        printf("13. Exit\n");
        printf("=====================================\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 13) {
            printf("Exiting system. Goodbye!\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter ID, Name, Program, Year, GPA: ");
                scanf("%d %s %s %d %f", &id, name, prog, &year, &gpa);
                regularEnrollment(&head, id, name, prog, year, gpa);
                break;

            case 2:
                printf("Enter ID, Name, Program, Year, GPA: ");
                scanf("%d %s %s %d %f", &id, name, prog, &year, &gpa);
                priorityEnrollment(&head, id, name, prog, year, gpa);
                break;

            case 3:
                printf("Enter ID, Name, Program, Year, GPA, Position: ");
                scanf("%d %s %s %d %f %d", &id, name, prog, &year, &gpa, &pos);
                manualInsert(&head, id, name, prog, year, gpa, pos);
                break;

            case 4:
                printf("Enter ID, Name, Program, Year, GPA: ");
                scanf("%d %s %s %d %f", &id, name, prog, &year, &gpa);
                lateEnrollment(&head, id, name, prog, year, gpa);
                break;

            case 5:
                displayAll(head);
                break;

            case 6:
                printf("Enter Student ID to search: ");
                scanf("%d", &id);
                searchStudent(head, id);
                break;

            case 7:
                printf("Enter Student ID to delete: ");
                scanf("%d", &id);
                deleteStudent(&head, id);
                break;

            case 8: {
                int count = countStudents(head);
                printf("Total students in system: %d\n", count);
                break;
            }

            case 9:
                promoteYear(&head);
                break;

            case 10:
                computeAverageGPA(head);
                break;

            case 11:
                printf("Enter number of top students to display: ");
                scanf("%d", &n);
                displayTopN(head, n);
                break;

            case 12:
                reverseList(&head);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
