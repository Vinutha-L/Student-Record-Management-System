#include<stdio.h>

struct Student{
  int usn;
  char name[50];
  int age;
  char branch[50];
  int semester;
};

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
    printf("Function to add student:");
    break;
  
  case 2:
    printf("to display students");
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