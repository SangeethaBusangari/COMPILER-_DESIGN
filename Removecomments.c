#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void is_comment(FILE *,FILE *);
int main(int argc, char *argv[])
{
	FILE *fsrc,*fdest;
	if(argc!=3)
	{
		printf("improper no of arguments\n");
		printf("Specify input and output file names at command line\n");
		exit(0);
	}
	fsrc=fopen(argv[1],"r"); //opening input file in read mode
	fdest=fopen(argv[2],"w");
	is_comment(fsrc,fdest);
	printf("comments are removed. check it in output file\n");
	printf("Thank you\n");
	return;
}
void is_comment(FILE *input,FILE *output)
{
	char c,s[2]={0};
	while((c=fgetc(input))!=EOF)
	{
		if(c=='/')
		{
			c=fgetc(input);
			if(c=='/')
			{
				while((c=fgetc(input))!='\n')
				{
					if(c==EOF)
					break;
				}
			}
			else if(c=='*')
			{
				do
				{
					s[0]=fgetc(input);
					s[1]=fgetc(input);
					if(s[0]==EOF || s[1]==EOF)
						break;
				}while(strcmp(s,"*/"));
			}
			else
			{
				fputc('/',output);
				fputc(c,output);
			}
		}//if
		fputc(c,output);
		if(c=='\"')
		{
		   fputc(c,output);
		   while(1)
		    {  
			c=fgetc(input);
			if(c=='\"')
			{
				fputc(c,output);
				break;
			}
			else if(c==EOF)
			{
				break;
			}      	
			else
			{
                         fputc(c,output);
                        }

		    }//while
	        }//if
	}
}
