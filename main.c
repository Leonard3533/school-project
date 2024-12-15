/* NGOUSI LEONARD AJIMSIMBOM
SOFTWARE ENGINEERING LEVEL II
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_STUDENTS 100


   struct student{
    int ID;
    char name[MAX_NAME_LENGTH];
    int age;
    float marks;
};

struct student records[MAX_STUDENTS];
int num_students = 0;

    void Add_student(){
        printf("Enter student details:\n");
        printf("ID: ");
        scanf("%d", &records[num_students].ID);
        printf("Name: ");
        scanf("%s", &records[num_students].name);
        printf("Age; ");
        scanf("%d", &records[num_students].age);
        printf("Marks: ");
        scanf("%f", &records[num_students].marks);
        num_students++;
};

void display_records(){
        printf("Student Records: \n");
        for (int i = 0; i < num_students; i++){
            printf("ID: %d, Name: %s, Age: %d, Marks: %.2f\n",
                   records[i].ID, records[i].name, records[i].age, records[i].marks);
        }
    };
void display_students_by_grade(){
    printf("Enter the grade to filter by: \n");
    char grade[10];
    scanf("%s", grade);
    int count = 0;
    for(int i = 0; i < num_students; i++){
        if(records[i].marks >= atof(grade)){
            printf("Student: ID: %d, Name: %s, Age: %d, Marks: %.2f\n",
                   records[i].ID, records[i].name, records[i].age, records[i].marks);
            count++;
        }
    }
if (count == 0)
    printf("No students meet the grade criteria.\n");
};

void search(){
    int id;
     printf("enter id to search student:  ");
     scanf("%d",&id);
     for(int i=0; i<num_students; i++){
        if(records[i].ID == id){
            printf("%s\n",records[i].name);
        }
     }
}

void sort(){
    int id;
    struct student tmp;
    printf("enter student id to sort record: ");
    scanf("%d",&id);
    for(int i=num_students; i>1; i--){
        for(int j=0; j<i-1; j++){
            if(records[j].ID>records[j+1].ID){
                tmp = records[j+1];
                records[j+1]= records[j];
                records[j]=tmp;
            }
        }
    }
    printf("records  sorted in ascending order\n");
}

void grade(){
    float total=0;
    for(int i=0; i<num_students; i++){
        total+=records[i].marks;
    }
    printf("Total = %.2f",total);
}

void top(){
    float top;
    struct student swap;
    top = records[0].marks;
    for(int i=1; i<num_students; i++){
        if(records[i].marks>top){
            swap=records[i];
        }
    }
    printf("%s\n",swap.name);
}

void filter(){
    int op;
    printf("enter 1. to display students below input | 2. to display result above search criteria\n");
    printf("Enter choice");
    scanf("%d",&op);
    if(op == 1){
        for(int i=0; i<num_students; i++){
            if(op < records[i].marks){
                printf("%s\t%f\n",records[i].name,records[i].marks);
            }
        }
            }
            else{
                for(int i=0; i<num_students; i++){
            if(op < records[i].marks){
                printf("%s\t%f\n",records[i].name,records[i].marks);
            }
        }
    }

void Modify_Records(){
    struct student records[MAX_STUDENTS];
    int num_students = 0;

}
}

int main(){
    int choice;
    do{
        printf("\nSTUDENT RECORD MANAGEMENT SYSTEM\n");
        printf("\n");
        printf("1. Add a new student\n");
        printf("2. Display all records\n");
        printf("3. Search for a specific student\n");
        printf("4. Sort the records\n");
        printf("5. Calculate average marks\n");
        printf("6. Identify the student with the highest marks\n");
        printf("7. Display students who meet specific grade criteria\n");
        printf("8. Modify or remove a student's record\n");
        printf("9. Analyze the distribution of grades\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            Add_student();
            break;
        case 2:
            display_records();
            break;
        case 3:
            search();
            break;
        case 4:
            sort();
            break;
        case 5:
            grade();
            break;
        case 6:
            top();
            break;
        case 7:
            display_students_by_grade();
            break;
        case 8:
            filter();
            break;
        case 9:
            printf("Analyze data");
            break;
        case 10:
            printf("Exiting....................");
            break;
        default:
            printf("Invalid choice. Enter option 1-10.\n");
        }
    }while(choice != 10);
    return 0;
}
