#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 10
#define MAX 30
struct node{
    char str1[MAX],str2[MAX];
    node *next;
};
node *root[SIZE];

int hashKey(char *str){
    int sum = 0;
    for(int  i = 0; i<=strlen(str) ; i++){
            if(str[i]!=',')
        sum+=str[i];
    }
    return sum%SIZE;
}
bool checkValidity(char *s1,char *s2){
    int c1=0, c2=0;
    for(int i=0;i<strlen(s1);i++){
        if(s1[i]==',')
            c1=c1+1;
    }
    if(s1[0]==','){
        return false;
    }
    if(c1>1){
        return false;
    }
    for(int i=0;i<strlen(s2);i++){
        if(s2[i]==',')
            c2=c2+1;
    }
    if(c2>=1){
        return false;
    }
}
void insert(char *s1, char *s2){
    int index = hashKey(s1);
    if(checkValidity(s1,s2)==true){

    if(root[index]==NULL){
        root[index] = new node();
        strcpy(root[index]->str1,s1);
        strcpy(root[index]->str2,s2);
        root[index]->next = 0;
    }else{
        node *n = new node();
        strcpy(n->str1,s1);
        strcpy(n->str2,s2);
        n->next = root[index];
        root[index] = n;
    }
    }else{
        printf("invalid input");
    }
}

void Display(){
    for(int i = 1; i <= SIZE ; i++){
        node *r = root[i];
        while(r != NULL){
            printf("[");
            printf("%d(%s%s)",i,r->str1,r->str2);
            r = r->next;
            printf("]\n");
        }
    }
}

void Search(char *s1, char *s2){
    if(checkValidity(s1,s2)==true){
    bool found = false;
    int index = hashKey(s1);
    node *r = root[index];
    while(r != NULL){
            if(strcmp(s1,r->str1)== 0 && strcmp(s2,r->str2)==0){
                found = true;
                break;
            }
            r = r->next;
    }
    if(found)
        printf("This value is Found.\n");
    else
        printf("This value is not Found.\n");

    }else{
        printf("invalid input");
    }
}

void Delete(char *s1, char *s2){
    if(checkValidity(s1,s2)==true){
    bool found = false;
    int index = hashKey(s1);
    node *r = root[index];
    node *p = r;
    while(r != NULL){
            if(strcmp(s1,r->str1)== 0 && strcmp(s2,r->str2)==0){
                found = true;
                break;
            }
            p = r;
            r = r->next;
    }
    if(found){
        if(p == r)
            root[index]=root[index]->next;
        else
            p->next = r->next;

        free(r);
        printf("Successfully Deleted.\n");

    }
    else{
        printf("This value is not Found.\n");
    }

    }else{
        printf("invalid input");
    }
}
void update(char *s1, char *s2,char *s3,char *s4){
    if(checkValidity(s1,s2)==true){
        if(checkValidity(s3,s4)==true){
            int index = hashKey(s1);
            node *r = root[index];
            while(r != NULL){
                    if(strcmp(s1,r->str1)== 0 && strcmp(s2,r->str2)==0){
                        strcpy(r->str1,s3);
                        strcpy(r->str2,s4);
                    }
                    r = r->next;
            }
        }else{
            printf("invalid input");
        }
    }else{
        printf("invalid input");
    }

}

int main(){

    char str1[MAX],str2[MAX],str3[MAX],str4[MAX];
    while(true){
        int x;
        printf("\n\n*************");
        printf("\n*************\n");
        printf("1. Insert\n2. Search\n3. Delete\n4. Show\n5. Update\n");
        printf("\n\n*************");
        printf("\n*************\n");
        scanf("%d",&x);
        if(x == 1){
            scanf("%s",&str1);
            scanf("%s",&str2);
            insert(str1, str2);
        }else if(x == 2){

            scanf("%s",&str1);
            scanf("%s",&str2);
            Search(str1, str2);
        }else if(x == 3){

            scanf("%s",&str1);
            scanf("%s",&str2);
            Delete(str1, str2);
        }else if(x == 4)
            Display();
        else if(x == 5){
            printf("Enter Old Value : \n");
            scanf("%s",&str1);
            scanf("%s",&str2);
            printf("Enter updated value : \n");
            scanf("%s",&str3);
            scanf("%s",&str4);
            update(str1,str2,str3,str4);
        }
    }

}

