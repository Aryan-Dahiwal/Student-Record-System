#include <stdio.h>

struct Student {
    char name[50];
    int roll;
    float marks;
};

int main() {
    struct Student s1;
    s1.roll = 1;
    s1.marks = 85.5;
    
    printf("Roll: %d\n", s1.roll);
    printf("Marks: %.2f\n", s1.marks);
    
    return 0;
}