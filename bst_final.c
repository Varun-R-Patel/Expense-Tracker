#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
struct expenses1{
	
    char date[50];
    int gro;
    int foo;
    int bil;
    int per;
    int tra;
    int sho;
    int total;
    struct expenses1 *next;
}*ex1,*first1=NULL,*t1,*cur1;
struct node 
{
	struct node *lchild;
	char data[50];
	char date[20];
	struct node *rchild;
	int gro;
    int foo;
    int bil;
    int per;
    int tra;
    int sho;
    int total;
};
struct node *newNode(char,char, int, int, int, int, int, int, int );
struct node *insert(struct node*,char date,int gro,int foo,int bil,int per,int tra,int sho,int total);
struct node *addtobst(struct node *,char,int,int,int,int,int,int,int);
struct node* getNode(char date){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->date=date[];
    newnode->lchild=NULL;
    newnode->rchild=NULL;
    return(newnode);
}
void inorder(struct node*);
struct node *fun1(char *mob1){
    FILE *fp;
    int row=0,column=0;
    char buffer[1024];
    char* value = strtok(buffer, ",");
    strcat(mob1,".txt");
    fp=fopen(mob1,"r");
    while(fgets(buffer,1024,fp)){
		column=0;
		row++;
        char* value = strtok(buffer, ",");
        struct expenses1 *ex1=(struct expenses1 *)malloc(sizeof(struct expenses1));
        while(value){
            if(column==0)
 	    			strcpy(ex1->date,value);
 	    		if(column==1)
 	    		    ex1->gro=atoi(value);
 	    		if(column==2)
 	    			ex1->foo=atoi(value);
                if(column==3)
 	    			ex1->bil=atoi(value);
                if(column==4)
 	    			ex1->per=atoi(value);
                if(column==5)
 	    			ex1->tra=atoi(value);
                if(column==6)
 	    			ex1->sho=atoi(value);
                if(column==7)
 	    			ex1->total=atoi(value);
 	    		value = strtok(NULL, ",");
	            column++;
            }
            ex1->next=NULL;
            if(first1==NULL){
	     		first1=ex1;
                // printf("in if");
	    	}
            else
	    	{
	    		t1=first1;
	    		while(t1->next!=NULL){
	    			t1=t1->next;
	    		}
	    		t1->next=ex1;
	    	}
    }
    fclose(fp);
    // printf("hello");
	return first1;
}
struct node* insert(struct node *root,char date,int gro,int foo,int bil,int per,int tra,int sho,int total){
    struct node *temp=root;
    struct expenses1 *t1;
    if(root==NULL){
        root=getNode(date);
        return(root);
    }
    while(1){
        if(strcmp(temp->date,date)>0){
            if(temp->lchild==NULL){  //there is no lchild
                temp->lchild=getNode(date);
                return(root);
            }
            else{
                temp=temp->lchild;
             }
        }
        else{
            if(temp->rchild==NULL){ //there is no rchild
                temp->rchild=getNode(date);
                return(root);
            }
            else{
                temp=temp->rchild;
            }
        }
        
    }
    return(root);
}
struct node* addtobst(struct node *,char,int,int,int,int,int,int,int)
{
	struct node *root=NULL;
	while(t1!=0)
	{
		root=insert(root,t1->date,t1->gro,t1->foo,t1->bil,t1->per,t1->tra,t1->sho,t1->total);
		t1=t1->next;
	}
	return root;
}
void inorder(struct node *root){
    if(root->lchild!=NULL)
        inorder(root->lchild);
    printf("%d ",root->date);
    if(root->rchild!=NULL)
        inorder(root->rchild);
}

int main()
{
	struct node*t2;
	t2=addtobst();
	inorder(t2);
}
struct node* search(struct node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
       return root;
    
    // Key is greater than root's key
    if (root->key < key)
       return search(root->rchild, key);
 
    // Key is smaller than root's key
    return search(root->lchild, key);
}
