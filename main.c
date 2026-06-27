#include <stdio.h>
#include "student.h"

int main() {
    Student* head = NULL;
    int choice;

    while (1) {
        printf("\n===== Student Record System =====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            addStudent(&head);
        } else if (choice == 2) {
            displayAll(head);
        } else if (choice == 3) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}