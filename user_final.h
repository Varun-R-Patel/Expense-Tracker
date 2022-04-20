#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>
// #include"mreport.h"
#define MAX_YR  2030
#define MIN_YR  2021
struct node{
    int data;
    struct node *link;
};//we can also use typedef struct and have 6 structures
struct node *first,*cur;
struct node *array[6]={NULL,NULL,NULL,NULL,NULL,NULL};
struct expenses{
    char gro[50];
    char foo[50];
    char bil[50];
    char per[50];
    char tra[50];
    char sho[50];
    char total[50];
}*ex;
struct date{
    int yyyy;
    int mm;
    int dd;
}getdate;
int isvalid();
int leapyear();
void daily(char mob1[]);
void monthly_record();
void function(int i);
void create(int i);
void insert(int i);
void totall(int i);
char names[10][50]={"Groceries","Food and Drinks","Bills and Utilities","Personal Care","Travel","Shopping"};
int count,groceries,food,bills,personal,travel,shopping,total,sumof;
char g[50]="Groceries:",f[50]="Food_and_drinks:",b[50]="Bills_and_utilities:",p[50]="Personal_care:",t[50]="Travel:",s[50]="Shopping:",to[50]="Total:";
void daily(char mob1[]){
    FILE *fp;
    int valid,a;
    char yesno;
    printf("Enter the date DD/MM/YYYY");
    scanf("%d/%d/%d",&getdate.dd,&getdate.mm,&getdate.yyyy);
    valid=isvalid();
    if(valid!=1){
        printf("Enter Valid Date\n");
        daily(mob1);
        return;
    }
    do{
            printf("1.GROCERIES\n2.FOODS N DRINKS\n3.BILLS N UTILITIES\n4PERSONAL CARE\n5.TRAVEL\n6.SHOPPING\n7.DONE\n");
            scanf("%d",&a);
            switch (a)
            {
            case 1:
                function(0);
                groceries=sumof;
                break;
            case 2:
                function(1);
                food=sumof;
                break;
            case 3:
                function(2);
                bills=sumof;
                break;
            case 4:
                function(3);
                personal=sumof;
				break;
            case 5:
                function(4);
                travel=sumof;
				break;
            case 6:
                function(5);
                shopping=sumof;
                break;
            case 7:
            	total=groceries+food+bills+personal+travel+shopping;
            	printf("%d/%d/%d\t%s%d\t%s%d\t%s%d\t%s%d\t%s%d\t%s%d\t%s%d",getdate.dd,getdate.mm,getdate.yyyy,g,groceries,f,food,b,bills,p,personal,t,travel,s,shopping,to,total);
        		printf("\nDo you want to Confirm these details (Y or N): ");
        		fflush(stdin);
        		scanf("%c",&yesno);
        		if((yesno=='Y')||(yesno=='y'))
        		{
        			strcat(mob1,".txt");
        			fp= fopen(mob1,"a");
        			total=groceries+food+bills+personal+travel+shopping;
            	    fprintf(fp,"%d/%d/%d,%d,%d,%d,%d,%d,%d,%d\n",getdate.dd,getdate.mm,getdate.yyyy,groceries,food,bills,personal,travel,shopping,total);
            	    struct node *array[6]={NULL,NULL,NULL,NULL,NULL,NULL};
            		// fprintf(fp,"%s\t%s%d\t%s%d\t%s%d\t%s%d\t%s%d\t%s%d\n",date,g,groceries,f,food,b,bills,p,personal,t,travel,s,shopping);
                    fclose(fp);
				}
                break;
            default:
                printf("ENTER CORRECT OPION\n");
                break;
            }
            if((yesno=='Y')||(yesno=='y'))
            {
            	return;
			}
        }while(1);
        struct node *array[6]={NULL,NULL,NULL,NULL,NULL,NULL};
}
void create(int i){
    cur=(struct node *)malloc(sizeof(struct node));
    printf("Enter Amount of %s\n",names[i]);
    scanf("%d",&cur->data);
    cur->link=NULL;
    array[i]=cur;
}
void insert(int i){
    if(array[i]==NULL){
        printf("create\n"); 
        create(i);
    }
    else{
        printf("Enter Amount of %s\n",names[i]);
        cur=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&cur->data);
        cur->link=NULL;
        first=array[i];
        while(first->link!=0){
            first=first->link;
        }
        first->link=cur;
    }
}
void delete_at_pos(int i){
    int pos,z;
    struct node *temp1,*temp2;
    if(array[i]==NULL){
        printf("This Particular list is Empty\n");
    }
    else{
        printf("\n\tEnter the position<1-%d> to Delete : ",count);//
        scanf("%d",&pos);
        if(pos==1)
	    {   
            first=cur=array[i];
            first=first->link;
            array[i]=first;
            cur->link=NULL;
            printf("\n\t\t\tDeleted Element : %d\n",cur->data);
            free(cur);
	    }
        else if(pos>count)
        {
        	printf("\n\t\t\t--INVALID POSITION----");
		}
		else
		{
			temp1=array[i];
			z=1;
        	while(z<pos)
        	{
            	temp2=temp1;
            	temp1=temp1->link;
            	z++;
        	}
        	printf("\n\t\t\t\tDeleted data is = %d\n",temp1->data);
        	temp2->link=temp1->link;
        	free(temp1);
		}
    }
}
void display(int i)
{
    cur=array[i];
    count=0;
    while(cur!=NULL)
    {
        printf("%d-",cur->data);
        count++;
        cur=cur->link;
    }
}
void function(int i)
{
	int ch;
    while(1)
    {
        printf("\n\n1.INSERT\n2.DELETE AT POS\n3.Return to previous Menu\n");
        printf("\n\n\tEnter option :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                insert(i);
                display(i);
                break;
            case 2:
            	delete_at_pos(i);
            	display(i);
            	break;	
            case 3:
            	totall(i);
            	display(i);
                printf("\n\t\t--return to main --\n");
                //struct node *array[6]={NULL,NULL,NULL,NULL,NULL,NULL};
                return;
            default : printf("\t\t--INVALID OPTION--");
        }
    }
}
void totall(int i){
    cur=array[i];
    printf("\n");
    sumof=0;
    while(cur!=NULL)
    {
        sumof+=(int)cur->data;
        cur=cur->link;
    }
    printf("Total %s is: %d\n",names[i],sumof);
    return;  	
}

int isvalid(){
    if (getdate.yyyy >  MAX_YR||getdate.yyyy < MIN_YR)
        return 0;
    if(getdate.mm<1 || getdate.mm>12)
        return 0;
    if(getdate.dd<1 || getdate.dd>31)
        return 0;
    if(getdate.mm==2){
        if(leapyear()){
            if(getdate.dd>29)
                return 0;}
        else{
            if(getdate.dd>28)
                return 0;}}
    if(getdate.mm==4||getdate.mm==6||getdate.mm==9||getdate.mm==11){
        if(getdate.dd>30)
            return 0;}
    return 1;
}
int  leapyear()
{
    if(((getdate.yyyy % 4 == 0) && (getdate.yyyy % 100 != 0)) ||(getdate.yyyy % 400 == 0))
        return 1;
}
//int main(){
//    int var;
//    printf("\t\t\tWELCOME\t\t\t\n\n");
//    do{
//        printf("1.INSERT DAILY EXPENSES\n2.VIEW MONTHLY REPORT\n3.CLOSE");
//        scanf("%d",&var);
//        switch(var){
//            case 1:
//                daily();
//                break;
//            case 2:
//                monthly_record();
//                break;
//            case 3:
//                break;
//            default:
//                printf("Enter Correct Choice\n");
//        }
//    }while(var!=3);
//}
