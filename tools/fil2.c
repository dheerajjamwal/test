#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#define LENGTH 200
char commit_id[100];
void extract_string(char * str)
{
char temp[200];
int i=0,j=0,flag=0,k=0;
//printf("String coming is %s\n",str);
while(str[i] && i<200 )
{
    if(str[i]==' ' && flag==0)
       flag=1;

    if(flag==1)
        temp[j++]=str[i+1];
    if(flag==0)
        commit_id[k++]=str[i];
    i++;
}
temp[j]='\0';
commit_id[k]='\0';
//printf("Commit id %s\n",commit_id);
strcpy(str,temp);

}

int main()
{
FILE *fp1,*fp2,*fp3;
int found,check;
char temp[200];
if((fp1=fopen("Test1","r")) == NULL)
{
    printf("NOT Able to open Master \n ");
    return 0;
}
//fp2=fopen("Test1","r");
fp3=fopen("result","rw");
//char file1[100],file2[100],file3[100];
char *file1,*file2;
file1= (char *) malloc (200);
file2= (char *) malloc (200);
size_t len1=0,len2=0;

while((getline(&file1,&len1,fp1) != -1 ))
{
found=0;
check =1;
//printf("Strin is %s\n",file1);
strcpy(temp,file1);
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
{
   // printf("Commit  == %s",temp);
   // printf("Commit id %s\n",commit_id);
    char temp1[LENGTH] = {0};
    char output[LENGTH] = {0};
    chdir("/home/ubuntu/Desktop/i915_git/linux");
    snprintf(temp1,LENGTH,"git show %s | grep \"^+\" | wc -l",commit_id);
    FILE *fp;
    if((fp=popen(temp1,"r")) == NULL)
       {
           return(0);
       }
    fgets(output,50,fp); 
    pclose(fp);
    chdir("/home/ubuntu/Desktop/Backport/tools");
    printf("Commit  == %s and Commit lenght is %s\n",temp,output);
   // printf("Commit id %s\n",commit_id);

}
}
fclose(fp1);

free(file1);
free(file2);
return 0;
}
