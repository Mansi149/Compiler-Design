#include<stdio.h>
#include<conio.h>
void main()
 {
   FILE *fp;
   int i,count=0;
   char buffer[255];
   char key[32][10]={"auto","double","int","struct","break","else","long",
		    "switch","case","enum","register","typedef","char",
		    "extern","return","union","const","float","short",
		    "unsigned","continue","for","signed","void","default",
		    "goto","sizeof","voltile","do","if","static","while"
		    };
   clrscr();

   fp=fopen("input.txt","r");


   printf("Program by Mansi Pareek\n");

   if(fp==NULL)
     {
       printf("\nFILE DOES NOT EXIST\n");
     }
   while(fscanf(fp,"%s",buffer)!=EOF)
     {
       for(i=0;i<32;i++)
	{
	 if(strcmp(key[i],buffer)==0)
	  {
	    count+=1;
	  }
	}
     }


   printf("\nNO OF KEYWORDS :-%d",count);
   fclose(fp);
    getch();

 }
