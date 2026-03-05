#include <stdio.h>
#include <stdlib.h>
#include "Esys.h"

int main() {
    Node head = NULL;

    head = createStudent(101, "Juan Dela Cruz", "BSCS", 1, 1.25);
    head->next = createStudent(102, "Maria Clara", "BSIT", 2, 1.50);
    
    printfStudentInfo(head);

    return 0;
}
