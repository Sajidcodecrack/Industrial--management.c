#include<stdio.h>
#include<string.h>
struct factory
{
    char name[1000];
    char id[1000];
    char post[2000];
    int age;
    int salary;
    float bonus;
};
//system("colour 6");
int main()
{   
    
    printf("===========================Menu==============================\n");
    printf("1) View all Record\n");
    printf("2) Insert a new record\n");
    printf("3) Search\n");
    printf("4) Update\n");
    printf("5) Delete\n");
    printf("6) Sort all data\n");
    printf("0) Exit\n");
    printf("=================== ***    Select a Menu  ***    ======================\n");
    FILE*fact;
    struct factory n[100];
    int i,x;
    for(i=0;;i++)
    {  
        scanf("%d",&x);
        if(x==0)
        {
            break;
        }
    
    switch(x)
    {
        case 1:
        {
            int j=0;
            fact=fopen("Data.txt","r");
            while(!feof(fact))
            {
                printf("\n");
                fscanf(fact,"%s",n[j].name);
                printf("Name:%s\n",n[j].name);
                fscanf(fact,"%s",n[j].id);
                printf("ID:%s\n",n[j].id);
                fscanf(fact,"%d",&n[j].age);
                printf("Age:%d\n",n[j].age);
                fscanf(fact,"%s",n[j].post);
                printf("Post:%s",n[j].post);
                fscanf(fact,"%d",&n[j].salary);
                printf("\nShowing salary:%d\n",n[j].salary);
                
                j++;
            }
            fclose(fact);
            printf("\n********Select from menu*******");
            break;
        }
        case 2:
        {
            fact=fopen("Data.txt","a");
            puts("Enter name:");
            fflush(stdin);
            scanf("%s",n[0].name);
            puts("Enter id:");
            fflush(stdin);
            scanf("%s",n[0].id);
            puts("Enter his/her age ");
            // fflush(stdin);
            scanf("%d",&n[0].age);
            puts("Enter his/her post");
             fflush(stdin);
            scanf("%s",n[0].post);
            puts("Enter his/her salary");
            // fflush(stdin);
            scanf("%d",&n[0].salary);
            
            fprintf(fact,"\n%s",n[0].name);
            fprintf(fact,"\n%s",n[0].id);
            fprintf(fact,"\n%d",n[0].age);
            fprintf(fact,"\n%s",n[0].post);
            fprintf(fact,"\n%d",n[0].salary);
            
             fclose(fact);
             printf("\n********Select from menu*******");
             break;

            
        }
       case 3:
       {
        fact=fopen("Data.txt","r");
        int i=0;
        int result=1;
        char search[1000];
        puts("Enter his/her id number to search information from our system dataabse:");
        scanf("%s",search);
        while(!feof(fact))
        {
            fscanf(fact,"%s",n[i].name);
            fscanf(fact,"%s",n[i].id);
            fscanf(fact,"%d",&n[i].age);
            fscanf(fact,"%s",n[i].post);
            fscanf(fact,"%d",&n[i].salary);
    
        
            result=strcmp(n[i].id,search);
            if(result==0)
           {
           printf("Showing information\n");
           printf("Name:%s\n",n[i].name);
           printf("ID:%s\n",n[i].id);
           printf("Age:%d\n",n[i].age);
           printf("Post:%s\n",n[i].post);
           printf("Salary:%d\n",n[i].salary);
           break;
        }
       i++;
        }

       if(result!=0)
         {
            printf("\nThis is not in match in our database");
            
         }
       fclose(fact);
       printf("\n********Select from the menu*********");
       break;  
    
    }
    case 4:
    {
        fact=fopen("Data.txt","r");
        int i=0,result;
        char update[1000];
        puts("\nEnter his/her id number for update his information:");
        scanf("%s",update);
        while(!feof(fact))
        {
            fscanf(fact,"%s",n[i].name);
            fscanf(fact,"%s",n[i].id);
            fscanf(fact,"%d",&n[i].age);
            fscanf(fact,"%s",&n[i].post);
            fscanf(fact,"%d",&n[i].salary);
            
            result=strcmp(n[i].id,update);
            if(result==0)
            {   
                puts("Enter his/her new id:");
                scanf("%s",n[i].id);
                puts("Enter his/her new post name:");
                scanf("%s",n[i].post);
                puts("Enter his/her age");
                scanf("%d",&n[i].age);
                puts("Enter his/her salary:");
                scanf("%d",&n[i].salary);
            }
            i++;

        }
        fclose(fact);
    fact=fopen("Data.txt","w");
    int m;
    for(m=0;m<i;m++)
    {
        if(m=i-1)
        {
            fprintf(fact,"%s\n",n[m].name);
            fprintf(fact,"%s\n",n[m].id);
            fprintf(fact,"%d\n",n[m].age);
            fprintf(fact,"%s\n",n[m].post);
            fprintf(fact,"%d",n[m].salary);
        }
        else
        {
            fprintf(fact,"%s\n",n[m].name);
            fprintf(fact,"%s\n",n[m].id);
            fprintf(fact,"%d\n",n[m].age);
            fprintf(fact,"%s\n",n[m].post);
            fprintf(fact,"%d\n",n[m].salary);
        }
        
    }
    fclose(fact);
    printf("\n***********Select from menu*************");
    break;

    }
    case 5:
    {
     fact=fopen("Data.txt","r");
      int i,j;
       while(!feof(fact))
      {
       fscanf(fact,"%s",n[i].name);
       fscanf(fact,"%s",n[i].id);
       fscanf(fact,"%d",&n[i].age);
       fscanf(fact,"%s",n[i].post);
        fscanf(fact,"%d",&n[i].salary);
     i++;
      }
      fclose(fact);
     fact=fopen("Data.txt","w");
     char delete[1000];
     int result;
     puts("Enter name:");
      fflush(stdin);
     scanf("%s",delete);
     for(j=0;j<i;j++)
      {
       result=strcmp(n[j].name,delete);
       if(result==0)
       {
        for(int k=j;k<i-1;k++)
        {
            strcpy(n[k].name,n[k+1].name);
            strcpy(n[k].id,n[k+1].id);
            strcpy(n[k].post,n[k+1].post);           
            n[k].age=n[k+1].age;
            n[k].salary=n[k+1].salary;

        }
        
           printf("\nDelete complete");
        }
        for(int p=0;p<i-1;p++)
        {
            if(p=i-2)
            {
                 fprintf(fact,"%s\n",n[p].name);
                 fprintf(fact,"%s\n",n[p].id);
                 fprintf(fact,"%d\n",n[p].age);
                 fprintf(fact,"%s\n",n[p].post);
                 fprintf(fact,"%d",n[p].salary);

            }
            else
            {
                fprintf(fact,"%s\n",n[p].name);
                fprintf(fact,"%s\n",n[p].id);
                fprintf(fact,"%d\n",n[p].age);
                fprintf(fact,"%s\n",n[p].post);
                fprintf(fact,"%d\n",n[p].salary);
            }
         }
     }
     fclose(fact);
     printf("\n**********Select menu*********");
      break;
    }
    case 6:
    {
        fact=fopen("Data.txt","r");
        int i=0;
        while(!feof(fact))
        {
            fscanf(fact,"%s",n[i].name);
            fscanf(fact,"%s",n[i].id);
            fscanf(fact,"%d",&n[i].age);
            fscanf(fact,"%s",n[i].post);
            fscanf(fact,"%d",&n[i].salary);
            i++;
        }
        int age1,salary1;
        char name1[100];
        char id1[100];
        char post1[100];
        for(int j=0;j<i;j++)
        {
            for(int k=0;k<i-1;k++)
            {
                if(n[j].salary<n[k].salary)
                {
                    salary1=n[j].salary;
                    n[j].salary=n[k].salary;
                    n[k].salary=salary1;
                    age1=n[j].age;
                    n[j].age=n[k].age;
                    n[k].age=age1;
                    strcpy(id1,n[j].id);
                    strcpy(n[j].id,n[k].id);
                    strcpy(n[k].id,id1);
                    strcpy(name1,n[j].name);
                    strcpy(n[j].name,n[k].name);
                    strcpy(n[k].name,name1);
                    strcpy(post1,n[j].post);
                    strcpy(n[j].post,n[k].post);
                    strcpy(n[k].post,post1);


                }
            }
        }
        fclose(fact);
        fact=fopen("Data.txt","w");
        for(int k=0;k<i;k++)
        {
            if(k==i-1)
            {
                fprintf(fact,"%s\n",n[k].name);
                fprintf(fact,"%s\n",n[k].id);
                fprintf(fact,"%d\n",n[k].age);
                fprintf(fact,"%s\n",n[k].post);
                fprintf(fact,"%d",n[k].salary);
            }
            else
            {
                fprintf(fact,"%s\n",n[k].name);
                fprintf(fact,"%s\n",n[k].id);
                fprintf(fact,"%d\n",n[k].age);
                fprintf(fact,"%s\n",n[k].post);
                fprintf(fact,"%d\n",n[k].salary);
            }
        }
        fclose(fact);
        printf("\nSuccesfully done\n");
        printf("\n**************Select the menu***********");
        break;
    }
    default :
    {
        printf("\nInvalid");
        break;
    }

    }
    }
return 0;
}
