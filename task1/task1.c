#include <stdio.h>
#include <string.h>
// Define a structure for student data
struct Student {
	int id; // Student ID
	char name[50]; // Student name
	float gpa; // Student GPA
};

int main() {
	int num;
// prompt number of entered
	printf("Enter the number of students: ");
	scanf("%d",&num);
	struct Student student[num];

// Creating an instance of the Student structure
//struct Student student1;
// Assigning values to the fields of student1
	for (int i=0 ; i<num; i++){
		printf("Enter the ID for student %d:",i+1);
		scanf("%d",&student[i].id);
		printf("Enter the name for student %d:",i+1);
    		scanf("%s",&student[i].name);
                printf("Enter the GPA for student %d:",i+1);
                scanf("%f",&student[i].gpa);


	}
printf("students info:\n");
// Displaying the contents of student1
	for (int i=0 ; i<num; i++){
	printf("ID: %d, ", student[i].id);
	printf("Name: %s, ", student[i].name);
	printf("GPA: %.2f", student[i].gpa);
	printf("\n");}
	return 0;}

