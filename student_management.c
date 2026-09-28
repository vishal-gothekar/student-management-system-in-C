#include <stdio.h>
#include <string.h>

struct student{
    char name[50];
    int age;
    char course[50];
    float marks;
};
struct student students[50];
int studentcount = 0;

void addstud(){
    if(studentcount<50)
    {
        printf("enter the name of the student:");
        scanf("%s",students[studentcount].name);
        printf("enter the age:");
        scanf("%d",&students[studentcount].age);
         printf("enter the course of the student:");
        scanf("%s",students[studentcount].course);
         printf("enter the marks:");
        scanf("%f",&students[studentcount].marks);
        studentcount++;
        }
        else {
            printf("maximum capacity is reached\n");
        }
}
void displaystud(){
        int i;
        for(i=0;i<studentcount;i++){
            printf("student %d\n",i+1);
            printf("The name of %d student:%s\n",i+1,students[i].name);
            printf("The age of %d student:%d\n",i+1,students[i].age);
            printf("The course of %d student:%s\n",i+1,students[i].course);    
            printf("The marks of %d student:%.2f\n",i+1,students[i].marks);
        }
        
        
    }
void searchstud(){
    char findname[50];
    printf("enter the name of the student you want to search:");
    scanf("%s",findname);
    int i;
    int found=0;
    for ( i = 0; i < studentcount; i++)
    {
    if(strcmp(students[i].name,findname)==0){
        printf("student found he is at %d place",i+1);
        found = 1;
        break;
    }
    }
    if (found==0){
        printf("Invlid name\n");
    }
}
void deletestud(){
    char deletestud[50];
    printf("enter the name of the student you want to delete:");
    scanf("%s",deletestud);
    int i,j;
    int found=0;
    for ( i = 0; i < studentcount; i++)
    {
        if(strcmp(students[i].name,deletestud)==0){
            printf("he is at %d\n",i);
            found = 1;
            for(j=i;j<studentcount-1;j++){
                students[j]=students[j+1];
            }
            studentcount--;
            break;
        }
    }
    if(found==0){
        printf("invalid name");
    }
    

}
void updatestud(){
    char updatename[50];
    int i;
    int found = 0;
     printf("enter the name of the student you want to update:");
    scanf("%s",updatename);
    for(i=0;i<studentcount;i++){
        if(strcmp(students[i].name,updatename)==0){
            printf("he is at %d",i);
            found = 1;
            break;
        }

    }
    if(found==0){
        printf("invalid name\n");
        return;
    }
    int choice;
    printf("what do you want to update\n");
    printf("\n1 for name");
    printf("\n2 for age");
    printf("\n3 for course");
    printf("\n4 for marks");
    printf("enter your choice:");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
    char name[50];
    printf("enter the name you want to update:");
    scanf("%s",name);
        strcpy(students[i].name,name);
        break;

    case 2:
    int age;
    printf("enter the age you want to update:");
    scanf("%d",&age);
        students[i].age = age;
        break;

    case 3:
    char course[50];
    printf("enter the course you want to update:");
    scanf("%s",course);
        strcpy(students[i].course,course);
        break;

    case 4:
    float marks;
    printf("enter the marks you want to update:");
    scanf("%f",&marks);
    students[i].marks = marks;
        break;
    
    default:
    printf("invalid  choice\n");
        break;
    }
}
int main(){
    int choice;

do
{
    printf("\n1. Add Student");
    printf("\n2. Display Students");
    printf("\n3. Search Student");
    printf("\n4. Update Student");
    printf("\n5. Delete Student");
    printf("\n6. Exit");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
     case 1:
     addstud();
     break;

     case 2:
     displaystud();
     break;

     case 3:
     searchstud();
        break;
     
   case 4:
   updatestud();
   break;

   case 5:
   deletestud();
   break;

   case 6:
   printf("exiting the program\n");
   break;

   default:
   printf("invalid choice\n");

    }

} while(choice != 6);
return 0;
}
