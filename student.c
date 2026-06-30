#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void addStudent(Student** head) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    
    printf("Enter name: ");
    scanf("%s", newStudent->name);
    printf("Enter roll number: ");
    scanf("%lld", &newStudent->roll);
    printf("Enter marks: ");
    scanf("%f", &newStudent->marks);
    newStudent->next = NULL;

    if (*head == NULL) {
        *head = newStudent;
    } else {
        Student* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
    printf("Student added successfully.\n");
}

void displayAll(Student* head) {
    if (head == NULL) {
        printf("No records found.\n");
        return;
    }
    Student* temp = head;
    while (temp != NULL) {
        printf("Name: %s\n", temp->name);
        printf("Roll: %lld\n", temp->roll);
        printf("Marks: %.2f\n", temp->marks);
        printf("----------\n");
        temp = temp->next;
    }
}

void searchByRoll(Student* head) {
    long long roll;
    printf("Enter roll number to search: ");
    scanf("%lld", &roll);

    Student* temp = head;
    while (temp != NULL) {
        if (temp->roll == roll) {
            printf("Student found:\n");
            printf("Name: %s\n", temp->name);
            printf("Roll: %lld\n", temp->roll);
            printf("Marks: %.2f\n", temp->marks);
            return;
        }
        temp = temp->next;
    }
    printf("Student with roll %lld not found.\n", roll);
}

void deleteByRoll(Student** head) {
    long long roll;
    printf("Enter roll number to delete: ");
    scanf("%lld", &roll);

    if (*head == NULL) {
        printf("No records found.\n");
        return;
    }

    
    if ((*head)->roll == roll) {
        Student* temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("Student deleted successfully.\n");
        return;
    }

    
    Student* prev = *head;
    Student* curr = (*head)->next;
    while (curr != NULL) {
        if (curr->roll == roll) {
            prev->next = curr->next;
            free(curr);
            printf("Student deleted successfully.\n");
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Student with roll %lld not found.\n", roll);
}

void sortByMarks(Student* head) {
    if (head == NULL) return;

    int swapped;
    Student* ptr;
    char tempName[50];
    long long tempRoll;
    float tempMarks;

    do {
        swapped = 0;
        ptr = head;

        while (ptr->next != NULL) {
            if (ptr->marks > ptr->next->marks) {
                // swap data between nodes
                // swap marks
                tempMarks = ptr->marks;
                ptr->marks = ptr->next->marks;
                ptr->next->marks = tempMarks;

                // swap roll
                tempRoll = ptr->roll;
                ptr->roll = ptr->next->roll;
                ptr->next->roll = tempRoll;

                // swap name
                strcpy(tempName, ptr->name);
                strcpy(ptr->name, ptr->next->name);
                strcpy(ptr->next->name, tempName);

                swapped = 1;
            }
            ptr = ptr->next;
        }
    } while (swapped);

    printf("Students sorted by marks (lowest to highest).\n");
}

void saveToFile(Student* head) {
    FILE* file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    Student* temp = head;
    while (temp != NULL) {
        fprintf(file, "%s %lld %.2f\n", temp->name, temp->roll, temp->marks);
        temp = temp->next;
    }

    fclose(file);
    printf("Records saved to file.\n");
}

void loadFromFile(Student** head) {
    FILE* file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("No existing records found.\n");
        return;
    }

    char name[50];
    long long roll;
    float marks;

    while (fscanf(file, "%s %lld %f", name, &roll, &marks) == 3) {
        Student* newStudent = (Student*)malloc(sizeof(Student));
        strcpy(newStudent->name, name);
        newStudent->roll = roll;
        newStudent->marks = marks;
        newStudent->next = NULL;

        if (*head == NULL) {
            *head = newStudent;
        } else {
            Student* curr = *head;
            while (curr->next != NULL) curr = curr->next;
            curr->next = newStudent;
        }
    }

    fclose(file);
    printf("Records loaded from file.\n");
}