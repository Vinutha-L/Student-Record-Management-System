#include<stdio.h>

struct Student{
  int usn;
  char name[50];
  int age;
  char branch[50];
  int semester;
};

int studentCount=0;
struct Student students[100];

void addStudent();
void displayStudent();

int main()
{
  int ch;
  printf("----Student Record Managent System----\n");
  
  do{
  printf("1.Add student\n2.Display students\n3.Search student\n4.Update student\n5.Delete student\n6.Exit\n");
  printf("Enter your choice:");
  scanf("%d", &ch);
    
  switch (ch)
  {
  case 1:
    printf("Function to add student:\n");
    addStudent();
    break;
  
  case 2:
    printf("to display students\n");
    displayStudent();
    break;

  case 3:
    printf("to search students:");
    break;

  case 4:
    printf("To update student");
    break;

  case 5:
    printf("To delete student");
    break;

  case 6:
    printf(" To exit loop:");
      break;

  default:
  printf("Select valid choice:");
  break;
  
  }
}while(ch!=6);


  return 0;

}

void addStudent()
{
  printf("Enter student's USN:\n");
  scanf("%d",&students[studentCount].usn);
  printf("Enter student's NAME:\n");
  scanf("%s",students[studentCount].name);
  printf("Enter student's AGE:\n");
  scanf("%d",&students[studentCount].age);
  printf("Enter student's BRANCH:\n");
  scanf("%s",students[studentCount].branch);
  printf("Enter student's current SEMESTER:\n");
  scanf("%d",&students[studentCount].semester);
  studentCount++;

}

void displayStudent()
{
  if(studentCount==0)
  printf("No student records found:");
  else
  {
  printf("Number of students=%d\n",studentCount);
  for(int i=0;i<studentCount;i++)
  {
    printf("Student %d:-\n",i+1);
    printf("USN:%d\n",students[i].usn);
    printf("NAME:%s\n",students[i].name);
    printf("Age:%d\n",students[i].age);
    printf("BRANCH:%s\n",students[i].branch);
    printf("SEMESTER:%d\n",students[i].semester);
  }
  }
  
}