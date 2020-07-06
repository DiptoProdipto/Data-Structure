//Single Linked List in a simplified way

#include<stdio.h>
#include<stdlib.h> //This is used for malloc() function

struct node
{
    int data;
    struct node *link;
};

struct node *start = NULL;  //Global

int n,x,e; //Global

void createList();
void displayList();
void countNodes();
void search();
void insertInBeginning();
void insertAfter();
void insertAtEnd();
void insertBefore();
void insertAtPosition();
void deleteNode();
void reverseList();

void main()
{
    int choice;

    createList();

    while(1)
    {
        printf("\n");
        printf("\t\t\t1.Display list\n");
        printf("\t\t\t2.Count the number of nodes\n");
        printf("\t\t\t3.Search for an element\n");
        printf("\t\t\t4.Add to empty list/beginning of the list\n");
        printf("\t\t\t5.Add a node at end of the list\n");
        printf("\t\t\t6.Add a node after a specified node\n");
        printf("\t\t\t7.Add a node before a specified node\n");
        printf("\t\t\t8.Add a node at a given position\n");
        printf("\t\t\t9.Delete a node\n");
        printf("\t\t\t10.Reverse the list\n");
        printf("\t\t\t11.Quit\n\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        if(choice==11)
            break;

        switch(choice)
        {
        case 1:
            displayList();
            break;

        case 2:
            countNodes();
            break;

        case 3:
            search();
            break;

        case 4:
            insertInBeginning();
            break;

        case 5:
            insertAtEnd();
            break;

        case 6:
            insertAfter();
            break;

        case 7:
            insertBefore();
            break;

        case 8:
            insertAtPosition();
            break;

        case 9:
            deleteNode();
            break;

        case 10:
            reverseList();
            break;

        default:
            printf("Wrong choice\n");

        }
    }
}


void createList()  //For creating the whole goddamn list
{
    printf("Enter the number of nodes: ");
    scanf("%d",&n);

    if(n==0)
        return; //this return statement terminates this function at this point


    printf("Enter the first element to be inserted: ");
    scanf("%d",&e);
                        //insertInBeginning()
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data=e;  //storing the input value into temp data field
    temp->link=start; //The value of start initially is null.Since temp is both first and last value, so we are assigning null into temp link field
    start=temp; //storing the address of temp into start so that start can point to temp

    for(int i=2; i<=n; i++) //i=1 is already filled with temp, so i starts from 2 here
    {
        printf("Enter the next element to be inserted: ");
        scanf("%d",&e);
                        //insertAtEnd()
        struct node *p,*temp;
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data=e;

        p=start; //the value of start is not null, since it is pointing and storing the address of first node
        while(p->link!=NULL)
            p=p->link;

        //After the while loop p->link==NULL

        p->link=temp; //so we are replacing null with the address of temp
        temp->link=NULL; //Since temp is now the last node, so the link value of temp would be null
    }

}

void displayList() //For showing the list to the fucking audience
{
    struct node *p;
    if(start==NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("List is: ");
    p=start;

    while(p!=NULL) //For printing nodes, counting nodes and searching nodes we have to use p!=NULL instead of p->link!=NULL because p->link stops at exact last node whereas p!=NULL exceeds the last node and print the data of it.
    {
        printf("%d ",p->data);
        p=p->link;
    }
    printf("\n"); //For printing a newline after executing displayList()
}

void countNodes() //For counting the nodes
{
    int n=0; //counter variable
    struct node *p=start;

    while(p!=NULL)
    {
        n++;
        p=p->link;
    }
    printf("Number of nodes in list = %d\n",n);
}

void search() //For searching a particular node by its data
{

    printf("Enter the element to be searched: ");
    scanf("%d",&x);

    struct node *p;

    int position=1; //Because position++ is executing break statement
    p=start;

    while(p!=NULL)
    {
        if(p->data==x)
            break;
        position++;
        p=p->link;

    }

    if(p==NULL)
        printf("%d not found in list\n",x);
    else
        printf("%d is at position %d\n",x,position);
}

void insertInBeginning() //For adding elements into empty or beginning of a list
{
    printf("Enter the element to be inserted: ");
    scanf("%d",&e);

    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data=e;

    temp->link=start; //Since start is holding the address of the first node, so we are assigning that address into temp link field so that it can hold the first node address as well
    start=temp; //Now we are assigning the address of temp into start which now becomes the first node

}

void insertAtEnd() //Inserting elements at last of a list
{
    printf("Enter the element to be inserted: ");
    scanf("%d",&e);

    struct node *p,*temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data=e;

    p=start;
    while(p->link!=NULL)
        p=p->link;
    //p becomes the last node after the while loop, so the link field of p is NULL.
    p->link=temp; //So we are replacing null with the address of temp
    temp->link=NULL; //Since temp now becomes the last node, so we are assigning NULL into the link field of temp
}

void insertAfter() //For inserting a node after a particular node
{
    printf("Enter the element to be  inserted: ");
    scanf("%d",&e);
    printf("Enter the element after which to insert: ");
    scanf("%d",&x);

    struct node *temp,*p;

    p=start;
    while(p!=NULL) //Since we are searching a value,that's why we are using p!=NULL. Think about it. If we are looking for a value that rests at last, we won't be able to find it because p->link!=NULL would be true and if statement inside the while loop won't be executed
    {
        if(p->data==x)
            break;
        p=p->link;
    }

    if(p==NULL)
        printf("%d not present in the list.\n",x);

    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data=e;
        temp->link=p->link; //We are assigning the address into temp->link which was pointed by the p->link
        p->link=temp; //Now p->link holds the address of temp which becomes the node we wanted to insert
    }
}

void insertBefore() //For inserting a node before a particular node
{
    printf("Enter the element to be inserted: ");
    scanf("%d",&e);
    printf("Enter the element before which to insert: ");
    scanf("%d",&x);

    struct node *temp,*p;

    if(start==NULL)
    {
        printf("List is empty\n");
        return;
    }

    if(x==start->data) //If we want to insert a  node before the first one
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data=e;
        temp->link=start; //we are assigning the address of first node into the link field of temp
        start=temp; //now we are assigning the address of temp into start which needless to say always points to the first node, now that temp becomes the first node because we are inserting it before the first node
        return; //If this if() condition executes then this insertBefore() function terminates here
    }

    p=start; //At this position start is definitely not NULL, since we have created a list and start is pointing to the first node address of that list
    while(p->link!=NULL)
    {
        if(p->link->data==x)
            break;
        p=p->link;
    }

    if(p->link==NULL)
        printf("%d not present in the list.\n",x);

    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data=e;
        temp->link=p->link;
        p->link=temp;
    }
}

void insertAtPosition() //For inserting a node at a particular position
{
    int i,k;
    printf("Enter the element to be inserted: ");
    scanf("%d",&e);
    printf("Enter the position at which to insert: ");
    scanf("%d",&k);

    struct node *temp,*p;


    if(k==1) //If it is in the position-1
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data=e;
        temp->link=start;
        start=temp;
        return;
    }

    p=start;
    for(i=1; i<k-1 && p!=NULL; i++) //For example if we want to insert a node at position 3 then it will stop at index-1 and p will hold the address of node 2
        p=p->link;

    if(p==NULL)
        printf("You can insert only up to %d th position\n",i);
    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data=e;
        temp->link=p->link;
        p->link=temp;
    }

}

void deleteNode()
{
    printf("Enter the element to be deleted: ");
    scanf("%d",&e);

    struct node *temp,*p;

    if(start==NULL)
    {
        printf("List is empty\n");
        return;
    }

    if(start->data==e) //If the data we want to delete rests in the first node
    {
        temp=start;
        start=start->link;
        temp->link=NULL; //For cutting the right hand side link of temp as well
        free(temp);
        return;
    }


    p=start;
    while(p->link!=NULL)
    {
        if(p->link->data==e) //We have to know the step ahead of the value we want to delete so that we can link the step ahead and step after node
            break;
        p=p->link;
    }

    if(p->link==NULL)
        printf("Element %d not in list\n",e);
    else
    {
        temp=p->link; //p->link contains the link value of step ahead node. By assigning this value to temp, temp becomes the scape goat
        p->link=temp->link; //temp->link contains the step after node address. We are assigning this address to the link field of step ahead node and linking them together
        free(temp);
    }


}

void reverseList()
{
    struct node *prev,*ptr,*next;
    prev=NULL; //Because it will contain the link field of first node which will become the last node
    ptr=start;
    while(ptr!=NULL)
    {
        next=ptr->link;
        ptr->link=prev;
        prev=ptr;
        ptr=next;
    }
    start=prev;

}

