#include <stdio.h>

struct Student {
    char name[50];
    long long roll;  
    float marks;
};

void printStudent(struct Student s) {
    printf("Name: %s\n", s.name);
    printf("Roll: %lld\n", s.roll);  
    printf("Marks: %.2f\n", s.marks);
    printf("----------\n");
}

int main() {
    struct Student s1;
    
    printf("Enter name: ");
    scanf("%s", s1.name);
    
    printf("Enter roll number: ");
    scanf("%lld", &s1.roll);  
    
    printf("Enter marks: ");
    scanf("%f", &s1.marks);
    
    printf("\n--- Student Record ---\n");
    
    printStudent(s1);
    
    return 0;
}