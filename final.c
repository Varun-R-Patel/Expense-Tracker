#include"user_final.h"
#include"mreport.h"
struct log_in{
    char name[50];
    char mobile[50];
    char password[50];
}lo;
void sign_up();
void login();
char nam[50],mob[50],pass[50];
int main(){
    int var;
    do
    {   printf("\n\t\t\tWELCOME\t\t\t\n\n");
        printf("\n1.SIGN UP\n2.LOGIN\n3.EXIT\n");
        scanf("%d",&var);
        switch(var)
        {
            case 1:
                sign_up();
                break;
            case 2:
                login();
                break;
            case 3:
                break;
            default:
                printf("WRONG OPTION SELECTED -Enter Valid Option: ");
                break;
        }
    }while(var!=3);
    return 0;
}
void sign_up(){
    FILE *fp,*fp1;
    int count=0,flag=0;
    char n[50]="Name:",m[50]="Mobile_no:",p[50]="PassWord_:",confirm_pass[50];
    printf("\n**   SIGN UP   *\n\n");
    fp=fopen("User_login.txt","a");
    printf("Enter your Name:\n");
    fflush(stdin);
    gets(nam);
    strcat(n,nam);
    printf("Enter your Mobile Number:\n");
    fflush(stdin);
    gets(mob);
    while(1){
        if(strlen(mob)!=10){
            printf("Please enter correct 10 digits phone number\n");
            gets(mob);
            count++;
            if(count>=10){
                printf("Many number of Incorrect Attempts!!\t RETURN TO HOME\n");
                return;
            }
        }
        else
            break;
    }
    fp1=fopen("User_login.txt","r");
    while(fscanf(fp1,"%s %s %s",lo.name,lo.mobile,lo.password)!= EOF)
	    {
            if((strcmp (lo.mobile+10,mob) == 0)){
                printf("\nMOBILE NUMBER ALREDY EXISTS\n");
                flag=1;
                break;
            }
	    }
    fclose(fp1);
    if(flag==1)
            return;
    strcat(m,mob);
    password:
    printf("Enter New Password:\n");
    fflush(stdin);
    gets(pass);
    strcat(p,pass);
    printf("Confirm Your Password:");
    fflush(stdin);
    gets(confirm_pass);
    if (strcmp(pass,confirm_pass)==0)
        {  
            fprintf(fp,"%s\n%s\n%s\n",n,m,p);
            printf("\nRegistration successful\n");//new line and a dashed line throughout the concole 
        }
    else
        {
            printf("\nPassword Not Matched Re-Enter Again\n");
            goto password;
    }
    fclose(fp);
}
void login(){
		struct node *array[6]={NULL,NULL,NULL,NULL,NULL,NULL};
        int x=0,var;
		FILE *fp;
        fp=fopen("User_login.txt","r");
		char mob[50],passw[50];
        printf("\t\t>>>>>>>>>>>>>LOGIN<<<<<<<<<<<<<\n\n");
        fflush(stdin);
        printf("\nEnter your Mobile NUMBER(unique_id):");
        fflush(stdin);
        gets(mob);
        printf("\nEnter your Password:");
        fflush(stdin);
        gets(passw);
		while(fscanf(fp,"%s %s %s",lo.name,lo.mobile,lo.password) != EOF)
		{
            if((strcmp (lo.mobile+10,mob) == 0) && (strcmp (lo.password+10,passw) == 0 ))
			{
                x=1;
                break;
            }
		}
        if(x==1){
            printf("*   LOGIN SUCCESSFUL  **\n\n");
            struct node *array[6]={NULL,NULL,NULL,NULL,NULL,NULL};
            printf("\t\t\t   WELCOME %s  \t\t\t\n\n",lo.name);//better display name in capital
            printf("Enter your choice:");
            printf("\n1.Daily Expense\n2.Monthly Report\n");
            scanf("%d",&var);
            switch (var)
            {
            case 1:
                daily(mob);
                break;
            case 2:
                monthly_record(mob);
                break;
            default:
                break;
            }
		} else
            printf("\nLogIn Failed!!Return HOME!\n");
    fclose(fp);
}

void monthly_record(char mob1[]){
    cur1=fun1(mob1);
    add(cur1);
}
