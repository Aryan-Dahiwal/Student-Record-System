#include <stdio.h>
#include <stdlib.h>
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