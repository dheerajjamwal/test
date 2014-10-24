#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

void extract_string(char * str)
{
char temp[200];
int i=0,j=0,flag=0;
//printf("String coming is %s\n",str);
while(str[i] && i<200 )
{
    if(str[i]==' ' && flag==0)
        flag=1;
    if(flag==1)
        temp[j++]=str[i+1];
    i++;
}
temp[j]='\0';
//printf("String is %s\n",temp);
strcpy(str,temp);

}

int main()
{
FILE *fp1,*fp2,*fp3;
int found,check;
if((fp1=fopen("Test1","r")) == NULL)
{
    printf("NOT Able to open Master \n ");
    return 0;
}
//fp2=fopen("Test1","r");
fp3=fopen("result","rw");
//char file1[100],file2[100],file3[100];
char *file1,*file2;
file1= (char *) malloc (100);
file2= (char *) malloc (100);
size_t len1=0,len2=0;

while((getline(&file1,&len1,fp1) != -1 ))
{
found=0;
check =1;
//printf("Strin is %s\n",file1);

extract_string(file1);
if((fp2=fopen("Test2","r")) == NULL)
{
    printf("Not able to open second file");
    return 0;
}

while((getline(&file2,&len2,fp2) != -1 ))
{
//printf("Second  File content is %s== %s\n",file2,file1);
    if(!(strstr(file1,"Merge branch")))
    {
        check=0;
        if(strstr(file2,file1))
        found=1;
//printf("Hello");
//printf("Found in second file == %s",file2);
//fclose(fp2);

    }   
}
fclose(fp2);
if(found==0 && check == 0)
printf("Not Found in second file == %s",file1);

}

fclose(fp1);

free(file1);
free(file2);
return 0;
}
