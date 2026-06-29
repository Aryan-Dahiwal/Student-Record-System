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
void searchByRoll(Student* head);
void deleteByRoll(Student** head);
void sortByMarks(Student* head);
#endif