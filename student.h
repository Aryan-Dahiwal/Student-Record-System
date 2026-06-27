#ifndef STUDENT_H
#define STUDENT_H

typedef struct Student {
    char name[50];
    long long roll;
    float marks;
    struct Student* next;
} Student;

void addStudent(Student** head);
void displayAll(Student* head);

#endif