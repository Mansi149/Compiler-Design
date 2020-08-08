#include<stdio.h>
#include<conio.h>
main()
 {
   FILE *fp;
   int i,count=0;
   char buffer[255];
   char operator[32][10]={"+","-","*","/","%","++","--",
		    "==","!=",">","<",">=","<=",
		    "&&","||","!","&","|","^",
		    "~","<<",">>","=","+=","-=",
		    "*=","/="
		    };
   fp=fopen("input4.txt","r");
   printf("Program by Mansi Pareek\n");

   if(fp==NULL)
     {
       printf("\nFILE DOES NOT EXIST\n");
     }
   while(fscanf(fp,"%s",buffer)!=EOF)
     {
       for(i=0;i<32;i++)
	{
	 if(strcmp(operator[i],buffer)==0)
	  {
	    count+=1;
	  }
	}
     }


   printf("\nNO OF OPERATORS:-%d",count);
   fclose(fp);
    getch();

 }
