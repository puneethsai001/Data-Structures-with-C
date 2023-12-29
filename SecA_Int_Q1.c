#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
    int student_id;
    char name[20];
    int age;
    double GPA;
    struct Student *next;

}Student;


Student *StudInsert(Student *start, int student_id, char name[20], int age, double GPA){

    Student *newRecord = (Student *) malloc(sizeof(Student));

    newRecord->student_id = student_id;
    newRecord->age = age;
    newRecord->GPA = GPA;

    strcpy(newRecord->name, name);

    if (start == NULL){
        newRecord->next = NULL;
        return newRecord;
    }

    else{
        newRecord->next = start;
        start = newRecord;
        return start;
    }
}

Student *StudDelete(Student *start, int student_id){

    if (start == NULL){
        printf("Cannot delete more\n");
        return start;
    }

    Student *ptr = start;
    Student *temp;

    while (ptr->student_id != student_id){

        temp = ptr;
        ptr = ptr->next;

        if (ptr == NULL){
            printf("Student ID not found\n");
            return start;
        }
    }

    temp->next = ptr->next;
    free(ptr);
    return start;
}

void StudSearch(Student *start, int student_id){

    if (start == NULL){
        printf("Student record empty\n");
    }

    Student *ptr = start;
    Student *temp;

    while (ptr->student_id != student_id){

        temp = ptr;
        ptr = ptr->next;

        if (ptr == NULL){
            printf("Student ID not found\n");
        }
    }

    printf("Student ID: %d\n", ptr->student_id);
    printf("Student Name: %s\n", ptr->name);
    printf("Student Age: %d\n", ptr->age);
    printf("Student GPA: %f\n", ptr->GPA);
}

void StudDisplay(Student *start){
    if (start == NULL){
        printf("Student records empty\n");
    }

    else{
        printf("Student Records: \n");
        Student *temp = start;
        while (temp->next != NULL){
            printf("%d | ", temp->student_id);
            printf("%s | ", temp->name);
            printf("%d | ", temp->age);
            printf("%f | \n", temp->GPA);
            temp = temp->next;
        }

        printf("%d | ", temp->student_id);
        printf("%s | ", temp->name);
        printf("%d | ", temp->age);
        printf("%f | \n", temp->GPA);
    }
}

int main(){

    Student *head = NULL;

    int student_id, age;
    char name[20];
    double GPA;

    head = StudInsert(head, 1, "Andrew", 19, 9.76);
    head = StudInsert(head, 2, "Elena", 19, 8.84);
    head = StudInsert(head, 3, "Jason", 21, 7.21);
    head = StudInsert(head, 4, "Maria", 19, 9.1);
    head = StudInsert(head, 5, "Kyle", 20, 8.5);

    StudDelete(head, 4);

    StudDisplay(head);

    printf("==========================\n");

    printf("Search Details:\n");
    StudSearch(head, 5);

    return 0;
}