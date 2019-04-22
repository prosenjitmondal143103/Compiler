#include<stdio.h>
#define size 20


int allInteger(char a[])
{
    bool isInt=false;

    for(int i=0; a[i]!='\0';i++){

        if(a[0]=='+'|| a[0]=='-'||a[i]=='1'||a[i]=='2'||a[i]=='3'|| a[i]=='4'|| a[i]=='5'|| a[i]=='6'|| a[i]=='7'|| a[i]=='8'|| a[i]=='9'|| a[i]=='0'){
            if(a[0]=='0'|| a[0]=='_'){
                isInt=false;
                break;
            }else{
                isInt=true;  //
            }
        }else{
            isInt=false;
            break;
        }
    }

    if(isInt)
        printf("\tAccepted\n");
    else
        printf("\tNot Accepted\n");
}








bool allVariable(char a[])
{
    bool isbool=false;
    for(int i=0; a[i]!='\0';i++)
    {
        if(a[0]=='0'||a[0]=='1'||a[0]=='2'||a[0]=='3'||a[0]=='4'||a[0]=='5'||a[0]=='6'||a[0]=='7'||a[0]=='8'||a[0]=='9')
        {
            return false;
        }
    }
    for(int i=0; a[i]!='\0';i++)
    {
        if(a[i]=='*'||a[i]=='#'||a[i]=='+'||a[i]==',')
        {
            return false;
        }

    }
    for(int i=0; a[i]!='\0';i++)
    {
        if(a[0]=='0'||a[0]=='1'||a[0]=='2'||a[0]=='3'||a[0]=='4'||a[0]=='5'||a[0]=='6'||a[0]=='7'||a[0]=='8'||a[0]=='9')
        {
            return false;
        }
        else if((a[i]>='a'&&a[i]<='z')||a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9'||a[i]=='0'||a[i]=='_')
        {
            isbool=true;
        }
    }
    if(isbool)
        return true;
    else{
        return false;
    }
}


void floatVar(char a[]){
    int i=0;
    if(a[i] == '+' || a[i]=='-')
        i++;
    for( ; a[i] !='.' && a[i] != '\0' ; i++){
        if(!(a[i]>= 48 && a[i] <= (48+9))){
            break;
        }
    }
    if(a[i] == '.'){
        i++;
        if(a[i]>= 48 && a[i] <= (48+9)){
            for( ; a[i] != '\0' ; i++){
                if(!(a[i]>= 48 && a[i] <= (48+9))){
                    break;
                }
            }
            if(a[i] == '\0'){
                printf("Yes");
            }else{
                printf("no");
            }
        }else{
            printf("no");
        }
    }else{
        printf("No");
    }
}

void expNum(char a[]){
      int i=0;
    if(a[i] == '+' || a[i]=='-')
        i++;
    for( ; a[i] !='.' && a[i] != '\0' ; i++){
        if(!(a[i]>= 48 && a[i] <= (48+9))){
            break;
        }
    }
    if(a[i] == '.'){
        i++;
        if(a[i]>= 48 && a[i] <= (48+9)){
            for( ; a[i]!='E' && a[i] != '\0' ; i++){
                if(!(a[i]>= 48 && a[i] <= (48+9))){
                    break;
                }
            }

            if(a[i] == 'E'){
                i++;
                if(a[i] == '+' || a[i]=='-')
                    i++;
                if(a[i]>= 48 && a[i] <= (48+9)){
                    for( ; a[i] != '\0' ; i++){
                        if(!(a[i]>= 48 && a[i] <= (48+9))){
                            break;
                        }
                    }
                    if(a[i] == '\0'){
                        printf("Yes");
                    }else{
                        printf("no");
                    }
                }else{
                    printf("no");
                }
            }else{
                printf("no");
            }
        }else{
            printf("no");
        }
    }else{
        printf("No");
    }
}



void startWith_n(char a[])
{
    for(int i=0; a[i]!='\0';i++)
    {
        if(a[0]=='n')
        {
            for(int i=0; a[i]!='\0';i++)
            {
                if(a[1]=='1'||a[1]=='2'||a[1]=='3'||a[1]=='4'||a[1]=='5'||a[1]=='6'||a[1]=='7'||a[1]=='8'||a[1]=='9'||a[1]=='0')
                {
                    printf("\n\t  No\n\n");
                    printf("\tComment: 2nd character is digit.\n\n");
                    break;
                }
                else
                    printf("\n\t Yes\n\n");
                    printf("\tComment: Your input is correct. \n\n");
                    break;
            }
        }
        else
            printf("\t\n  No\n\n");
           // printf("\tComment: Wrong Input.\n\n");
            break;
    }
}

int main()
{
    while(true)
    {
        int n;
        char a[size];
        printf("\t*************************\n");
        printf("\t*************************\n\n");
        printf("\tFunction List:      \n");
        printf(" \t1. Integer number \n \t2. All the variables \n\t3. All floating point numbers\n\t4. All the exponent numbers.\n\t5. Start with n and 2nd char cannot be digit.\n");
        printf("\n\t*************************\n");
        printf("\t*************************\n");
        printf("\n\tEnter your option: ");
        scanf("%d",&n);
    switch(n)
    {
    case 1:
        {
            printf("\n\tEnter value(Integer) : ");
            scanf("%s",a);
            allInteger(a);
            break;
        }
    case 2:
        {
            printf("\n\tEnter value(Variables) : ");
            scanf("%s",a);
            if(allVariable(a)){
                printf("Variable accepted\n");
            }else{
                printf("Variable not accepted\n");
            }

            break;
        }
    case 3:
        {
            printf("\tEnter value(Floating Number : ");
            scanf("%s",a);
            floatVar(a);
            break;
        }
    case 4:
        {
            printf("\n\tEnter value(Exp. Number) : ");
            scanf("%s",a);
            expNum(a);
            break;
        }
    case 5:
        {
            printf("\n\tEnter value(Start with 'n' and 2nd no can't be digit) : ");
            scanf("%s",a);
            startWith_n(a);
            break;
        }
    }
    }
return 0;
}
