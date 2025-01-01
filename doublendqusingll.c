#include<stdio.h> 
 
#include<stdlib.h> 
struct node 
{ 
 int data; 
 struct node *link; 
}; 
typedef struct node *NODE; 
 
NODE insert_rear(); 
NODE insert_front(); 
NODE delete_rear(); 
NODE delete_front(); 
NODE getnode(); 
void display(); 
 NODE first=NULL; 
 
int main() 
{ 
 int option;
 while(1) 
 { 
  printf("\nDouble ended queue operations\n"); 
  printf("1.Entry restricted queue\n2.Exit restricted queue\n3.Display\n4.Exit\n"); 
  printf("Enter your choice: "); 
  scanf("%d",&option); 
  switch(option) 
  { 
   case 1: printf("\nEntry restricted operations\n"); 
   printf("1.Insert\n2.Delete from front\n3.Delete from rear\n"); 
   printf("Enter your choice: "); 
   scanf("%d",&option); 
   switch(option) 
   { 
    case 1: insert_rear(); 

    break; 
    case 2: delete_front(); 
   
    break; 
    case 3: delete_rear(); 
   
    break; 
    default: printf("Invalid choice\n"); 
   } 
   break; 
   case 2: printf("\nExit restricted operations\n"); 
   printf("1.Delete\n2.Insert from front\n3.Insert from rear\n"); 
   printf("Enter your choice: "); 
   scanf("%d",&option); 
   switch(option) 
   { 
    case 1: delete_front(); 
    
    break; 
    case 2: insert_front(); 
   
    break; 
    case 3: insert_rear(); 
   
    break; 
    default: printf("Invalid choice\n"); 
   } 
   break; 
   case 3: display(); 
    
    break; 
   case 4: exit(0); 
   default: printf("Invalid choice\n"); 
  } 
 } 
 return 0;
} 
 
NODE getnode() 
{ 
 NODE temp; 
 temp=(NODE)malloc(sizeof(struct node)); 
 return temp; 
} 
 
NODE insert_front() 
{ 
 NODE temp; 
 temp=getnode(); 
 printf("Enter the data: "); 
 scanf("%d",&temp->data); 
 temp->link=first; 
 first=temp; 
 printf("%d is successfully inserted\n",temp->data); 
 return first; 
} 
 
NODE delete_front() 
{ 
 NODE temp; 
 if(first==NULL) 
 { 
  printf("No nodes present"); 
  return first; 
 } 
 temp=first; 
 first=first->link; 
 printf("%d is successfully deleted\n",temp->data); 
 free(temp); 
 return first; 
} 
 
NODE insert_rear() 
{ 
 NODE temp,ptr; 
 temp=getnode(); 
 printf("Enter the data: "); 
 scanf("%d",&temp->data); 
 printf("%d is successfully inserted\n",temp->data); 
 temp->link=NULL; 
 if(first==NULL) 
 { 
  first=temp; 
  return first; 
 } 
 ptr=first; 
 while(ptr->link!=NULL) 
 ptr=ptr->link; 
 ptr->link=temp; 
 return first; 
} 
 
NODE delete_rear() 
{ 
 NODE ptr,prev; 
 if(first==NULL) 
 { 
  printf("No nodes present\n"); 
  return first; 
 } 
 ptr=first; 
 while(ptr->link!=NULL) 
 { 
  prev=ptr; 
  ptr=ptr->link; 
 } 
 printf("%d is successfully removed\n",ptr->data); 
 prev->link=NULL; 
 free(ptr); 
 return first; 
} 
void display() 
{ 
NODE temp; 
if(first==NULL) 
printf("No nodes present\n"); 
else 
{ 
for(temp=first;temp->link!=NULL;temp=temp->link) 
printf("%d=>",temp->data); 
printf("%d=>",temp->data); 
} 
} 