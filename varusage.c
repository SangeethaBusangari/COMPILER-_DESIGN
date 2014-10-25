/*************************************************************************/
NAME:BUSANGARI SANGEETHA
Roll no:14MCMT40
Description:finding the var uasge and its declaration and displaying it with their line numbers.
		assuming no global variables..
Version: 1
*/
/**************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
void usage(FILE *,FILE *);
int main(int argc,char *argv[])
{
	FILE *fsrc,*fdest;
	if(argc!=3)
	{
		printf("Improper number of arguments\n");
		exit(0);
	}
	fsrc=fopen(argv[1],"r");
	fdest=fopen(argv[2],"w");
	printf("calling function\n");
	usage(fsrc,fdest);
	fclose(fsrc);
	fclose(fdest);
	printf("Scanning is done..\n");
}
void usage(FILE *input,FILE *output)
{
	char *types[3]={"int","char","float"};
	char temp[10]={0},iarr[5]={0},far[5]={0},car[5]={0};
	char *s,c;
	int i,j=0,k,l,m=0,len,count=3,flag=1;
	
	while((c=fgetc(input))!=EOF)
	{
		
		//for(i=0;i<3;i++)
		//{
		//	len=strlen(types[i]);
		//	printf("%s length is %d\n",types[i],len);
		//	c==fgetc(input);		
			if(c=='\n')
				count++;
			if(c==EOF)
				break;
			if(count==3)
			{
				while(c!='{')//staring from main
				{
					c=fgetc(input);
				}
				flag--;
			}
		/*checking for keyword*/
			do
			{
				
				c=fgetc(input);
				temp[j]=c;
				j++;
				c=fgetc(input);
				if(c==EOF)
					break;
				temp[j++]=c;
			}while(c!=' ');
			temp[j]='\0';
		//	printf("%s variables:\n",temp);
		/* taking variables into array*/
			do
			{
				c=fgetc(input);
				if(c==EOF)
				break;
				iarr[j]=c;
				printf("%c declared in line %d \n",iarr[j],count);
				j++;
				c=fgetc(input);
				if(c==EOF)
				break;
			}while(c!=';');//until end of the line
			iarr[j]='\0';
			printf("...........\n");
			c=fgetc(input);
			if(c=='\n')
			{
				count++;
			}
		/*checking for variable usage*/
			do
			{
				c=fgetc(input);
				if((c==EOF)||(c=='}'))
					break;
				if(c=='\n')
				{
					count++;
				}
				if((islower(c)))
				printf("%c used in line no %d\n",c,count);
			//	else
				//printf("%c",c);
			}while(c!=EOF);
			/*if(temp=="float")
			{
				do
				{
					c=fgetc(input);
					if(c==EOF)
					break;
					far[k]=c;
					printf("%c declared in line %d\n",far[k],count);
					k++;					
					c=fgetc(input);
					if(c==EOF)
					break;
				}while(c!=';');
			}
			if(temp=="char")
			{
				
				do
				{
					c=fgetc(input);
					car[l]=c;
					printf("%c declared in line %d\n",car[l],count);
					l++;
					c=fgetc(input);
					if(c==EOF)
					break;

				}while(c!=';');
			}*/

			
		//}
	}	
}

