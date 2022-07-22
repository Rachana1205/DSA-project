#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
typedef struct list add;
struct list
{
char name[40];
long int phno;
char address[40];
char city[40];
add* next;
};

int i=1,size=0,count=0;

void Insert(add** head)
{
    long phno;
add* temp=((add*)malloc(sizeof(add)));
printf("");
gets(temp->name);
printf("Contact name : ");
gets(temp->name);
printf("Mobile Number : ");
scanf("%li",&temp->phno);
count=(temp->phno==0)?1:log10(temp->phno)+1;
if(count!=10){
printf("phno must be 10 digits");
return;
}
gets(temp->address);
printf("Address: ");
gets(temp->address);
printf("City : ");
gets(temp->city);
temp->next = NULL;
size++;
if(size == 50)
{
printf("\nTelephone directory is full!!!");
printf("\nIf you want to add more contact,You have to delete some contact from your list...\n");
return;
}
else
{
if(*head == NULL)
{
*head = temp;
printf("Done!!!\n");
return;
}
else
{
add* p = *head;
while(p->next != NULL)
{
p = p->next;
}
p->next = temp;
printf("\nDone!!!\n");
}
return;
}
}


void Search(add*head)
{
char ch[40];
printf("\nContact name : ");
scanf("%s",ch);
if(head == NULL)
{
printf("No Contact exists in this Directory!!!\n");
return;
}
else
{
add*p = head;
while(p != NULL)
{
if(strcmp((p->name),ch) == 0)
{
printf("Number : %li\t",p->phno);
printf("Address : %s\t",p->address);
printf("City: %s\n",p->city);
return;
}
p = p->next;
}
printf("This Contact does not exist");
}
}


void Delete(add** head)
{
char ch[40];
gets(ch);
printf("\nContact name : ");
gets(ch);
if(*head == NULL)
{
printf("\nNo Contact exists in this Phone Book List!\n");
return;
}
else
{
if(strcmp(((*head)->name),ch) == 0)
{
add*p=*head;
*head = (*head)->next;
free(p);
printf("\nDone!!!\n");
return;
}
else
{
add*p = *head;
while(p->next != NULL)
{
if(strcmp((p->next->name),ch) == 0)
{
p->next = p->next->next;
size--;
return;
}
p = p->next;
}
printf("\nInvalid Contact!!!\n");
}
}
}


void Display(add* head)
{
if(head == NULL)
{
printf("\nNo Contact exists in this Phone Book List!");
return;
}
else
{
add*p = head;
while(p != NULL)
{
printf("\n%d.%c%s",i,32,p->name);
printf("\tNumber : %li",p->phno);
printf("\tAddress : %s",p->address);
printf("\tCity : %s",p->city);
p = p->next;
i++;
}
i=1;
return;
}
}


void main()
{
add* head=NULL;
int ch;
printf("\n\t\t|!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!|");
printf("\n\t\t|!!!!!!!!!!!!!!!!!!! TELEPHONE DIRECTORY !!!!!!!!!!!!!!!!!|");
printf("\n\t\t|!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!|\n");
while(1)
{
printf("\nMenu");
printf("\n-------------------------------------------------");
printf("\n1.Create A Contact\n2.Remove A Contact");
printf("\n3.Show The Contact List\n4.Find A Contact");
printf("\n5.Quit");
printf("\nEnter a choice: ");
scanf("%d",&ch);
switch(ch)
{
case 1 :Insert(&head);
break;
case 2 :Delete(&head);
break;
case 3 :Display(head);
break;
case 4 :Search(head);
break;
case 5 :exit(0);
break;
default :printf("\n\t\tInvalid Choice!Try again!!!");
}
}
return 0;
}