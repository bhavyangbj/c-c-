#include<stdio.h>
#include<stdlib.h>

struct linklist
{
    int info;
    struct linklist *next;
};

typedef struct linklist node;

node *create();
node *insert(node *record,int pos, int no);
node *delete(node *record, int pos);
void sort(node *s);
int search(node *s,int x);
int max(node *s);
void display(node *s);
void replace(node *s,int x,int y);
int length(node *s);
node *merge(node *l1, node*l2);
node *reverse(node *root);

void main()
{
    int opt;
    int m,l,s,p;
    int x,y,ax,n,pos;
    struct linklist *start , *start2, *start3;

    char r;
    do{

    printf("\n Operation: 1. To create Link list");
    printf("\n            2. Display Link list");
    printf("\n            3. To find maximum element of Link list");
    printf("\n            4. To find length of Link list");
    printf("\n            5. To find Element from Link list");
    printf("\n            6. To Replace element of Link list");
    printf("\n            7. To sort elements of Link list");
    printf("\n            8. To Reverse All element of Link list");
    printf("\n            9. To Merge two Link list");
    printf("\n           10. To Quit");

    printf("\n Enter Operation: ");
    fflush(stdin);
    scanf("%d",&opt);

    switch(opt)
    {

        case 11:    printf("\n Enter position: ");
                    scanf("%d",&pos);
                    printf("\n Enter n.: ");
                    scanf("%d",&n);
                    start=insert(start,pos,n);
                    display(start);
                    break;

        case 1: start=create();
                break;

        case 2: printf("\n Linked List...");
                display(start);
                break;

        case 3: m=max(start);
                printf("\n Maximum Element is: %d\n",m);
                break;

        case 4: l=length(start);
                printf("\n Length of Linked List: %d\n",l);
                break;

        case 5: printf("\n Enter Element to search: ");
                scanf("%d", &s);
                p=search(start,s);
                if(p!=-1)
                    printf("\n Element '%d' is at %d position. \n",s,p);
                else
                    printf("\n Element is not found !!!\n");
                break;

        case 6: printf("\n Enter Element to find: ");
                scanf("%d",&x);
                printf("\n Enter New Element To Replace: ");
                scanf("%d",&y);
                replace(start,x,y);
                break;

        case 7: sort(start);
                break;

        case 8: start=reverse(start);
                printf("\n Reversing...");
                display(start);
                break;

        case 9: printf("\n Enter new link list: ");
                start2=create();
                printf("\n Merging....");
                start3=merge(start,start2);
                display(start3);
                break;

        case 10: exit(0);


    }

    printf("\n Do You Want to Go on Another Operation(Y/N)? \n ==>  ");
    fflush(stdin);
    r=getchar();
    }while(r=='y' || r=='Y');
}


node *create()
{
    int n;
    node *root, *nnode, *prev;
    root='\0';
    printf("\n Enter number (-999 to stop): ");
    scanf("%d",&n);
    while(n!=-999)
    {
        nnode=(node*)malloc (sizeof(node));
        nnode->info=n;
        nnode->next='\0';
        if(root==NULL)
            root=nnode;
        else
            prev->next=nnode;
        prev=nnode;
        printf("\n Enter number (-999 to stop): ");
        scanf("%d",&n);
    }
    return root;
}

node* insert(node* record, int pos, int no)
{
    node *temp, *newnode;
    int i=1;
    temp=record;
    newnode=(node*)malloc(sizeof(node));
    if(pos==1)
    {
        newnode->info=no;
        newnode->next=record;
        temp=newnode;
    }
    else
    {
        while(i<pos-1 && record!='\0')
        {
            record=record->next;
            i++;
        }
        if(i<pos-1 && record=='\0')
        {
            printf("\n Invalid position.");
            return temp;
        }
        newnode->info=no;
        newnode->next=record->next;
        record->next=newnode;
    }
    return temp;
}

node *delete(node *record, int pos)
{
    node *temp, *temp1;
    int i=1;
    temp=record;
    if(pos==1)
    {
        temp1=record;
        record=record->next;
        free(temp1);
        temp=record;
    }
    else
    {
        while(i<pos-1 && record!='\0')
        {
            record=record->next;
            i++;
        }
        if(i<pos-1 && record=='\0')
        {
            printf("\n Invalid position.");
            return temp;
        }
        temp1=record->next;
        record->next=temp1->next;
        free(temp1);
    }
    return temp;
}

void sort(node *s)
{
    node *count;
    for( ; s->next!='\0'; s=s->next)
	{
		for(count = s->next; count!=NULL; count=count->next)
		{
			if(s->info > count->info)
			{
				int temp    = s->info;
				s->info     = count->info;
				count->info = temp;
			}
		}
	}
}

int search(node *s,int x)
{
    int i=1;
    while(s!='\0')
    {
        if(s->info==x)
            return i;
        else
        {
            s=s->next;
            i++;
        }
    }
    if(i==1)
        return -1;
}

int max(node *s)
{
	int i,j,maxi;
	maxi=s->info;
	while(s!='\0')
	{
        if(maxi < s->info)
		{
            maxi=s->info;
        }
        s=s->next;
	}
	return maxi;
}

node *reverse(node *root)
{
    node *t1,*t2,*t3;
    t1=root;
    if(t1=='\0')
        printf("\n List is empty.");
    else
    {
        t2='\0';
        while(t1!='\0')
        {
            t3=t2;
            t2=t1;
            t1=t1->next;
            t2->next=t3;
        }
        root=t2;
    }
    return root;
}
/*
struct linklist *reverse(node *record)
{
    node *root,*save,*prev;
    prev='\0';
    while(record!='\0')
    {
        save=record->next;
        record->next=prev;
        prev=record;
        record=save;
    }
    return record;
}
*/


void display(node *s)
{
    while(s!='\0')
    {
        printf("\n %d",s->info);
        s=s->next;
    }
}

void replace(node *s,int x,int y)
{
    while(s!='\0')
    {
        if(s->info==x)
            s->info=y;

        s=s->next;
    }
}

int length(node *s)
{
    int i=0;
    while(s!='\0')
    {
        s=s->next;
        i++;
    }
    return i;
}
/*
void marge(node *a, node *b)
{
    if( a != NULL && b!= NULL )
    {
        if (a->next == NULL)
            a->next = b;
        else
            marge(a->next,b);
    }
    else
    {
        printf("Either a or b is NULL\n");
    }
}
*/
node *merge(node *l1, node*l2)
{
    int n;
    node *root, *nnode, *prev;
    root='\0';
    while(l1!='\0')
    {
        nnode=(node*)malloc (sizeof(node));
        nnode->info=l1->info;
        nnode->next='\0';
        if(root==NULL)
            root=nnode;
        else
            prev->next=nnode;
        prev=nnode;
        l1=l1->next;
    }
    while(l2!='\0')
    {
        nnode=(node*)malloc (sizeof(node));
        nnode->info=l2->info;
        nnode->next='\0';
        if(root==NULL)
            root=nnode;
        else
            prev->next=nnode;
        prev=nnode;
        l2=l2->next;
    }
    return root;
}
