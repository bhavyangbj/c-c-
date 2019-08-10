#include<stdio.h>
#include<stdlib.h>

struct student
{
    int roll;
    char name[50];
};

int main()
{
    struct student *s;
    int i,n;
    printf("\n Enter student number: ");
    scanf("%d",&n);
    s=(struct student*) malloc ( n * sizeof(struct student));
    for(i=0;i<n;++i)
    {
        printf("\n Enter Roll no.: ");
        scanf("%d",&(s+i)->roll);
        printf("\n Enter Name: ");
        scanf("%s",&(s+i)->name);
    }
    printf("\n Entered Details: \n");
    for(i=0;i<n;++i)
    {
        printf("\n \t %d \t %s",(s+i)->roll,(s+i)->name);
    }
}
