// Program to check whether the input string is keyword or not.

#include<stdio.h>
#include<conio.h>
#include<string.h>

main()

{
int i,flag=0,m;
char s[5][10]={"if","else","goto","continue","return"},st[10];
printf("Program by Mansi Pareek");
printf("\nEnter the string : ");
gets(st);
for(i=0;i<5;i++)
{
m=strcmp(st,s[i]);
if(m==0)
flag=1;
}
if(flag==0)
printf("\n It is not a keyword");
else


printf("\n It is a keyword");

getch();
}












