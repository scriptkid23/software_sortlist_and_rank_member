#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
    char key[10];
    char name[30];
    float pointMiddle;
    float pointEnd;
    float pointAll;
    char rank[3];
} STUDENT;

typedef struct{
    STUDENT *s_student[100];
    char className[10];
    int numberMember;
} CLASS;
void deleteNewline(char prop[]){
    prop[strlen(prop)-1] ='\0';
}
void rankAccept(float prop,char t_rank[]){
    if(prop < 4.0){
        strcpy(t_rank,"F");
    }
    else if((prop > 4.0) && (prop <5.5)){
        strcpy(t_rank,"D");
    }
    else if((prop > 5) && (prop <7)){
        strcpy(t_rank,"C");
    }
    else if((prop > 7) &&( prop <8)){
        strcpy(t_rank,"B");
    }
    else if((prop > 8) && (prop < 10)){
        strcpy(t_rank,"A");
    }

}
void display()
{
    printf("CHUONG TRINH TINH DIEM VA XEP LOAI SINH VIEN\n");
    printf("============================================\n");
    printf("============================================\n");
}
void inputMember(CLASS *c_class)
{
   FILE *f_member = fopen("lib/ds.txt","r");
   FILE *f_point  = fopen("lib/point.txt","r");
   char temp[3];
   char tempKey[20];
   fscanf(f_member,"%s",&c_class->className);
   fscanf(f_member,"%d",&c_class->numberMember);
   fgets(temp,sizeof(temp),f_member);
   for(int i = 0; i < c_class->numberMember; i++)
   {
       c_class->s_student[i] = (STUDENT*)malloc(sizeof(STUDENT));
       fscanf(f_member,"%s",&c_class->s_student[i]->key);
       fgets(c_class->s_student[i]->name,sizeof(c_class->s_student[i]->name),f_member);
       deleteNewline(c_class->s_student[i]->name);
   }
   for(int i =0; i < c_class->numberMember;i++)
   {
        fscanf(f_point,"%s",&tempKey);
        for(int j = 0; j < c_class->numberMember;j++){
            if(strcmp(tempKey,c_class->s_student[j]->key) == 0){
                fscanf(f_point,"%f",&c_class->s_student[j]->pointMiddle);
                fscanf(f_point,"%f",&c_class->s_student[j]->pointEnd);
                fgets(temp,sizeof(temp),f_point);
            }
        }
   }
    for(int i=0; i< c_class->numberMember;i++){
        c_class->s_student[i]->pointAll =(0.3*c_class->s_student[i]->pointMiddle) + (0.7*c_class->s_student[i]->pointEnd);
        rankAccept(c_class->s_student[i]->pointAll,c_class->s_student[i]->rank);
    }

}
void printList(CLASS *c_class){
        printf("%-10s|%-20s|%-30s|%-10s|%-5s\n","STT","KEY"," NAME","POINT","RANK");
        printf("------------------------------------------------------------------------------\n");
    for(int i = 0; i < c_class->numberMember;i++){
        printf("%-10d|%-20s|%-30s|%-10.2f|%-5s\n",i+1,c_class->s_student[i]->key,c_class->s_student[i]->name,c_class->s_student[i]->pointAll,c_class->s_student[i]->rank);
    }
}
void filterMember(STUDENT *prop[], int n){
    int k = 0;
    printf("%-10s|%-20s|%-30s|%-10s|%-5s\n","STT","KEY"," NAME","POINT","RANK");
        printf("------------------------------------------------------------------------------\n");
    for(int i = 0; i < n;i++){
        if(strcmp(prop[i]->rank,"F")==0) continue;
        else{
        printf("%-10d|%-20s|%-30s|%-10.2f|%-5s\n",k+1,prop[i]->key,prop[i]->name,prop[i]->pointAll,prop[i]->rank);
        k++;
    }
    }
}
void sortList(STUDENT *prop[], int n){
  STUDENT *temp;
  for(int i = 0; i < n-1;i++){
    for(int j = i+1;j < n;j++){
      if(prop[i]->pointAll < prop[j]->pointAll){
          temp    = prop[i];
          prop[i] = prop[j];
          prop[j] = temp;
      }
    }
  }
}
