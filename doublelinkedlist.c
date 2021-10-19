#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
  int data;
  struct node *next;
  struct node *prev;
}NODE;





NODE* insert(NODE *head,int val)
{
   NODE *newnode=(NODE*)malloc(sizeof(NODE));
   newnode->prev=newnode->next=NULL;
   newnode->data=val;
   NODE *temp=head;
   if(temp==NULL)
   {
      head=newnode;
      return(head);
   }
   else
   {
      int opt,m;
      printf("\n1.begin\n2.middle\n3.end\n");
      scanf("%d",&opt);
      switch(opt)
      {
          case 1: head->prev=newnode;
                  newnode->next=head;
                  head=newnode;
                  return(head);
                  break;
          case 2:printf("enter value to insert after it");
                 scanf("%d",&m);
                 while(temp->data!=m)
                 {
                     temp=temp->next;
                 }
                 newnode->next=temp->next;
                 newnode->prev=temp;
                 temp->next->prev=newnode;
                 temp->next=newnode;
                 return(head);
                 break;
         case 3:while(temp->next!=NULL)
                {
                   temp=temp->next;
                }        
                newnode->prev=temp;
                temp->next=newnode;
                return(head);
                break;
             
      }
   }
}




NODE* display(NODE *head)
{
   NODE *temp=head;
   if(temp==NULL)
   {
     printf("underflow");
     return(head);
   }
   else
   {
       while(temp!=NULL)
       {
          printf("%d->",temp->data);
          temp=temp->next;
       }
   }
   return(head);
}


NODE* delete(NODE *head)
{
   NODE *temp=head;
   if(head==NULL)
   {
     printf("underflow error");
     return(head);
   }
   else
   {
      int opt,val;
      printf("\n1.begin\n2.middle\n3.end\n");
      scanf("%d",&opt);
      NODE *oldptr=NULL;
      
      switch(opt)
      {
        case 1:head=head->next;
               head->prev=NULL;
               free(temp);
              return(head);
              break;
        case 2:printf("enter value to delete");
               scanf("%d",&val);
               while(temp->data!=val)
               {
                  oldptr=temp;
                  temp=temp->next;
               }
               temp->next->prev=oldptr;
               oldptr->next=temp->next;
               free(temp);
               return(head);
               break;
        case 3:while(temp->next!=NULL)
               {
                 oldptr=temp;
                  temp=temp->next;
               }
               oldptr->next=NULL;
               free(temp);
               return(head);
               break;
               
               
              
      }
   }

 
}


int main()
{
    int opt,val;
    NODE *head=NULL;
    while(1)
    {
       printf("\n1.insert\n2.delete\n3.display\n4.exit\n");
       scanf("%d",&opt);
       switch(opt)
       {
          case 1:printf("enter value:");
                 scanf("%d",&val);
                 head=insert(head,val);
                 break;
         case 2:head=delete(head);
                break;
         case 3:head=display(head);
                break;
         case 4:exit(4);
                break;
         default:printf("enter correct option");
       }
    }
}

