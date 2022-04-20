#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
float gro_sum,foo_sum,bil_sum,per_sum,tra_sum,sho_sum,total_sum;
float gro_percentage,foo_percentage,bil_percentage,per_percentage,tra_percentage,sho_percentage;
void add(struct expenses1 *);
struct expenses1 *fun1(char *);
struct expenses1 *fun1(char *mob1){
    
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
void add(struct expenses1 * first1){
    t1=first1;
    while(t1!=NULL){
        gro_sum+=t1->gro;
        foo_sum+=t1->foo;
        bil_sum+=t1->bil;
        per_sum+=t1->per;
        tra_sum+=t1->tra;
        sho_sum+=t1->sho; 
        total_sum+=t1->total; 
        t1=t1->next;
    }
    printf("\t\t\t\t******summary******\n");
    printf("\n");
    printf("\n\t\t\t*****Monthly Expenses of each Commodity*****\n");
    printf("\n");
    printf("\nGroceries:%.1f Food:%.1f Bill:%.1f Personal:%.1f Travel:%.1f Shopping:%.1f Total:%.1f",gro_sum,foo_sum,bil_sum,per_sum,tra_sum,sho_sum,total_sum);
    printf("\n");
    gro_percentage=(gro_sum*100)/total_sum;
    foo_percentage=(foo_sum*100)/total_sum;
    bil_percentage=(bil_sum*100)/total_sum;
    per_percentage=(per_sum*100)/total_sum;
    tra_percentage=(tra_sum*100)/total_sum;
    sho_percentage=(sho_sum*100)/total_sum;
    printf("\n\t\t\t*****Overall Percentage of each Commodity*****\n");
    printf("\n");
    printf("\nGroceries_percentage:%.2f,  Food_Percentage:%.2f,  Bill_Percentage:%.2f,   Personal_Percentage:%.2f,   Travel_Percentage:%.2f,   Shopping_Percentage:%.2f",gro_percentage,foo_percentage,bil_percentage,per_percentage,tra_percentage,sho_percentage);
	printf("\n");
}
// void main(){
//     struct expenses1 *cur1;
//     char mob[50]="8125533480";
//     // strcat(mob,".txt");
//     cur1=fun1(mob);
//     add(cur1);
// }
