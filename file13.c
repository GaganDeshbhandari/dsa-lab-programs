#include<stdio.h> 
#include<stdlib.h>
struct student 
{ 
int regno; 
char name[20]; 
}; 
int main() 
{ 
struct student stud[20],temp; 
FILE *fout,*fin; 
int i,n; 
fout=fopen("student.txt","w"); 
if(fout==NULL) 
{ 
printf("Error, could not open file...."); 
return 0;
exit(0); 
} 
printf("Enter number of students:"); 
scanf("%d",&n); 
for(i=0;i<n;i++) 
{ 
printf("For student %d:\n",i+1); 
printf("Name:"); 
scanf("%s",stud[i].name); 
printf("Register no:"); 
scanf("%d",&stud[i].regno); 
} 
fwrite(stud,sizeof(struct student),n,fout); 
fclose(fout); 
fin=fopen("student.txt","r"); 
if(fin==NULL) 
{ 
printf("Error, could not read from file...."); 
return 0;
exit(0); 
} 
printf("\nData read from file is as follows:\n"); 
while(fread(&temp,sizeof(struct student),1,fin)) 
{ 
printf("Name:%s\n",temp.name); 
printf("Reg No:%d\n\n",temp.regno); 
return 0;
} 
fclose(fin); 
} 