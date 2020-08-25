#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

char symbolTable[20][10], filename[50];
int countSymbol=0;

void displayOperatorsAndKeywords();
void displayMenu();
void displaySymbolTable();

main()
{
	FILE *f;

	displayMenu();
}

void displayOperatorsAndKeywords()
{
	char ch, str[20];
	FILE *f;
	int i;
	countSymbol = 0;
	f = fopen(filename, "r");
	if(f)
	{
		printf("\nLIST OF KEYWORDS & OPERATORS: -\n");
		while(fscanf(f, "%s", str)!=EOF)
		{
			if(isKeyword(str))
			{
				printf("%s, is a keyword\n", str);
			}
			else if(isOperator(str))
			{
				printf("%s, is a operator\n", str);
			}
			else
			{
				strcpy(symbolTable[countSymbol++], str);
			}
		}
	}
	else
	{
		printf("File not found!");
	}
	fclose(f);
}

void displayMenu()
{
	int status;
	char symbol[20], choice;
	do {
		fflush(stdin);
		clrscr();
		printf("PROGRAM BY -MANSI PAREEK \n\n");
		printf("MENU - ");
		printf("\n1. OPEN ANOTHER FILE");
		printf("\n2. DISPLAY SYMBOL TABLE");
		printf("\n3. SEARCH INSIDE SYMBOL TABLE");
		printf("\n4. DELETE FROM SYMBOL TABLE");
		printf("\n5. EXIT");
		printf("\nEnter Choice: ");
		scanf("%c", &choice);

		switch(choice)
		{
			case '1':
				printf("Enter File name(eg: file.txt): ");
				fflush(stdin);
				gets(filename);
				displayOperatorsAndKeywords();
				break;

			case '2':
				displaySymbolTable();
				break;

			case '3': printf("Enter symbol to search: ");
				fflush(stdin);
				gets(symbol);
				status = search(symbol);
				if(status>=0)
				{
					printf("\n%s found in symbol table.\n", symbol);
				}
				else
				{
					printf("\n%s not found!\n", symbol);
				}
				break;

			case '4':
				printf("Enter symbol to delete: ");
				fflush(stdin);
				gets(symbol);
				status = deleteSymbol(symbol);
				if(status>=0)
				{
					printf("\n%s deleted from symbol table.\n", symbol);
					displaySymbolTable();
				}
				else
				{
					printf("\n%s not found!\n", symbol);
				}
				break;

			case '5': exit(0);

			default: printf("\nINVALID CHOICE!");
				break;

		}
		printf("\n(PRESS ANY KEY TO CONTINUE)");
		getch();
	}while(1);
}

void displaySymbolTable()
{
	int i;
	if(countSymbol)
	{
		printf("\nSYMBOL TALBE: -\n");
		for(i=0; i<countSymbol; i++)
		{
			printf("%s\n", symbolTable[i]);
		}
	}
	else
	{
		printf("\nSYMBOL TABLE IS EMPTY!\n");
	}
}

int search(char symbol[20])
{
	int i;
	for(i=0; i<countSymbol; i++)
	{
		if(strcmp(symbolTable[i], symbol) == 0)
			return i;
	}
	return -1;
}

int deleteSymbol(char symbol[20])
{
	int i,s = search(symbol);

	if(s>=0)
	{
		for(i=s; i<countSymbol-1; i++)
		{
			strcpy(symbolTable[i], symbolTable[i+1]);
		}
		countSymbol--;
		return 1;
	}
	else
	{
		return -1;
	}
}

int isKeyword(char str[])
{
	int i;
	char keywords[35][15] = {"auto","break","case","char", "const","continue", "default", "do", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while", "double", "else", "enum", "extern", "float", "for", "goto", "if", "#"};
	for(i=0; strcmp(keywords[i],"#")!=0; i++)
	{
		if(strcmp(str,keywords[i])==0)
		{
			return 1;
		}
	}
	return 0;
}

int isOperator(char str[])
{
	int i;
	char operators[35][7] = {"+", "-", "*", "/", "%", "++", "--", "==", "!=", ">", "<", ">=", "<=", "&&", "||", "!", "&", "|", "^", "<<", ">>", "=", "+=", "-=", "*=", "/=", "%=", "sizeof", "&", "*", "->", ",", "~", "#"};
	for(i=0; strcmp(operators[i],"#")!=0; i++)
	{
		if(strcmp(str,operators[i])==0)
		{
			return 1;
		}
	}
	return 0;
}

