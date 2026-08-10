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
void searchStudent();
void updateStudent();
void deleteStudent();

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
    printf("to search students:\n");
    searchStudent();
    break;

  case 4:
    printf("To update student\n");
    updateStudent();
    break;

  case 5:
    printf("To delete student\n");
    deleteStudent();
    break;

  case 6:
      printf("Exiting program...\n");
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
  printf("No student records found.\n");
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

void searchStudent()
{
 int usn;
 int found=0;
 printf("Enter usn to search:");
 scanf("%d",&usn);
 for(int i=0;i<studentCount;i++)
 {
  if(usn==students[i].usn)
  {
    printf("Student Found.\n");
    printf("Student Name:%s\n",students[i].name);
    printf("Student's Age:%d\n",students[i].age);
    printf("Student's Branch:%s\n",students[i].branch);
    printf("Student's Current semester:%d\n",students[i].semester);
    found++;
  }
  
  
 }
 if(found==0)
 {
  printf("Student not found!!\n");
 }
}

void updateStudent()
{
  int n,ch;
  int found=0;
  printf("Enter USN:");
  scanf("%d",&n);
  for(int i=0;i<studentCount;i++)
  {
    if(n==students[i].usn)
    {
      found=1;
      printf("Student Found.\n");
      do{
      printf("---Select the deatail that needs to be updated---");
      printf("\n1.NAME\n 2.USN\n 3.AGE\n 4.BRANCH\n 5.SEMESTER\n");
      printf("Enter your choice:");
      scanf("%d",&ch);

      switch (ch)
      {
      case 1:
        printf("Enter new NAME:");
        scanf("%s",students[i].name);
        printf("Updated successfully.\n");
        break;
      
      case 2:
        printf("Enter new USN:");
        scanf("%d",&students[i].usn);
        printf("Updated successfully.");
        break;

      case 3:
        printf("Enter new AGE:");
        scanf("%d",&students[i].age);
        printf("Updated successfully.");
        break;

      case 4:
        printf("Enter new BRANCH:");
        scanf("%s",students[i].branch);
        printf("Updated successfully.");
        break;

      case 5:
        printf("Enter new SEMESTER:");
        scanf("%d",&students[i].semester);
        printf("Updated successfully.");
        break;
      
      default:
        printf("Enter a valid choice.!!\n");
        break;
      }}while(ch<1||ch>5);
    }
  }

  if(found==0)
  {
    printf("Student not Found!!");
  }
}

void deleteStudent()
{
  int usn;
  int found=0;
  printf("Enter usn has to be deleted:");
  scanf("%d",&usn);

  for(int i=0;i<studentCount;i++)
  {
    if(usn==students[i].usn)
    {
      found=1;
      printf("Student Found.\n");

      for(int j=i;j<studentCount-1;j++)
      {
        students[j]=students[j+1];
        
      }
      studentCount--;
      printf("Student deleted successfully.\n");

    }
  }

  if(found==0)
  {
    printf("Student Not found.\n");
  }

}