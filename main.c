#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include"modules.c"

int main()
{

    CLASS *class_one;
    class_one = (CLASS*)malloc(sizeof(CLASS));
    inputMember(class_one);
    sortList(class_one->s_student,class_one->numberMember);
    printList(class_one);
    printf("\n");
    filterMember(class_one->s_student,class_one->numberMember);

    return 0;
}
