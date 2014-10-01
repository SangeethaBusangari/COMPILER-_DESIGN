#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void macro_replace(FILE *,FILE *);
int main(int argc,char *argv[])
{
	int i;
	FILE *fsrc,*fdest;
	if(argc!=3)
	{
		printf("Improper number of arguments\n");
		exit(0);
	}
	fsrc=fopen(argv[1],"r");
	fdest=fopen(argv[2],"w");
	macro_replace(fsrc,fdest);
	printf("macro identifier is replaced with token sequence\n");
	printf("Open the output file\n");
}
void macro_replace(FILE *input,FILE *output)
{
	int i=0,j=0,k=0;
	char c,m[5],buf[7],t[4],temp[4],x[4];
	int len,len1,len2;
	char s[7]="#define";
	while((c=fgetc(input))!=EOF)
	{
		if(c==s[0])
		{
			fputc(c,output);
			buf[0]=c;
			for(i=1;i<=6;i++)
			{
				c=fgetc(input);	
				fputc(c,output);
				if(c==s[i])
				{
					buf[i]=c;
				}
				else
				fputc(c,output);
			}
			len=strlen(buf);
			buf[len+1]='\0';//found that #define is availble in program
			//printf("\n");
			c=fgetc(input);	
			if(c==' ')
				fputc(c,output);
			do
			{
				fputc(c,output);
				m[j]=c;//to store char carried from while
				j++;
				c=fgetc(input);
				m[j]=c;
				j++;
				fputc(c,output);
				m[j]=c;
			
			}while((c=fgetc(input))!=' ');
			m[j]='\0';
			//printf(" m is %s\n ",m);
			len1=strlen(m); //macro identifier is identified
			printf("\n");
			do
			{	fputc(c,output);
				t[k]=c;//to store char carried from while
				k++;
				c=fgetc(input);
				t[k]=c;//to store next char
				k++;
				fputc(c,output);
				t[k]=c;
			
			}while((c=fgetc(input))!='\n');
			fputc('\n',output);
			t[k]='\0';
			//printf(" t is %s\n ",t);
			//printf("\n");//token sequence for macro identifer
			while(c!=EOF)
			{
				for(i=0;i<len1;i++)
				{
					c=fgetc(input);
					if(c==m[i])
					{
						temp[i]=t[i];
						
						fputc(temp[i],output);		//replacing  macro identifier with it tokensequence.
						//printf("%c",temp[i]);
					}
					else
					fputc(c,output);
				}
			}
			temp[i]='\0';
		}//if
		else
		{
			fputc(c,output);
		}			
	}
}

