#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void charcount(char *filename);
void wordcount(char *filename);
int main(int argc,char* argv[])
{
	//count(argv[2]);
	if(strcmp("-c",argv[1])==0 || strcmp("-C",argv[1])==0)
	{
		charcount(argv[2]);
	}
	if(strcmp("-w",argv[1])==0 || strcmp("-W",argv[1])==0)
	{
		wordcount(argv[2]);
	}
}

void charcount(char *filename)
{
	FILE *fp;
	char c;
	char buffer[1000];
	int bufferlen;
	int charCount=0;
	int i;
	
	if((fp=fopen(filename,"rb"))==NULL)
	{
		printf("文件不能打开");
		exit(0);
	}
	
	while(fgets(buffer,1000,fp)!=NULL)
	{
		bufferlen=strlen(buffer);
		for(i=0;i<bufferlen;i++)
		{
			c=buffer[i];
			if(c==' ' || c=='\t' || c=='\n')
			{
				charCount++;
			}
		}
			
			
	}
	  fclose(fp);
	  printf("字符数：%d\n",charCount);
		
}

void wordcount(char *filename)
{
	FILE *fp;
	char c;
	char buffer[1000];
	int bufferlen;
	int isLastBlank=1;
	int flag=1;
	int wordCount=0;
	int i;	
	if((fp=fopen(filename,"rb"))==NULL)
	{
		printf("文件不能打开");
		exit(0);
	}	
	while(fgets(buffer,1000,fp)!=NULL)
	{
		bufferlen=strlen(buffer);
		for(i=0;i<bufferlen;i++)
		{
			c=buffer[i];
			if(c!=' ' && c!=',' && c!='\t' && c!='\n')
			{
				isLastBlank=0;
			}
			if(c==' ' || c==',')
			{
				if(isLastBlank==0)
				{
					wordCount++;
				}
				isLastBlank=1;
			}
			
		}		
		if(isLastBlank==0)
		{
			wordCount++;
		}		
	}
	  fclose(fp);
	  printf("单词数：%d\n",wordCount);
}



