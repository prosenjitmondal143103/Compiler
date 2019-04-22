#include <bits/stdc++.h>
using namespace std;
int lookval[130];
int precedence(char op){
    if(op == '+'||op == '-')
    return 1;
    if(op == '*'||op == '/')
    return 2;
    return 0;
}


int applyOp(int a, int b, char op){
    switch(op){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
}

int evaluate(string tokens){
    int i;
    stack <int> values;
    stack <char> ops;

    for(i = 0; i < tokens.length(); i++){

        if(tokens[i] == ' '){

        }
        else if(tokens[i] == '('){
            ops.push(tokens[i]);
        }

        else if(isdigit(tokens[i])){
            int val = 0;

            while(i < tokens.length() &&
                        isdigit(tokens[i]))
            {

                val = (val*10) + (tokens[i]-'0');
                i++;
            }
            values.push(val);
            i--;
        }

        else if((tokens[i] >= 'A' && tokens[i] <= 'Z') || (tokens[i] >= 'a' && tokens[i] <= 'z'))
        {
            values.push(lookval[tokens[i]]);
        }else if(tokens[i] == ')')
        {
            while(!ops.empty() && ops.top() != '(')
            {
                int val2 = values.top();
                values.pop();

                int val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }

            ops.pop();
        }


        else
        {
            while(!ops.empty() && precedence(ops.top()) >= precedence(tokens[i])){
                int val2 = values.top();
                values.pop();

                int val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }

            ops.push(tokens[i]);
        }
    }

    while(!ops.empty()){
        int val2 = values.top();
        values.pop();

        int val1 = values.top();
        values.pop();

        char op = ops.top();
        ops.pop();

        values.push(applyOp(val1, val2, op));
    }


    return values.top();
}

void Code(char str[]){
    char nstr[100],nnstr[100];
    char x;
    int i=0,j=0,p=0;
    while(str[i] != ';'){
        nnstr[p] = str[i];
        if(str[i] == '=')
            break;
        if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            x = str[i];
        i++;
        p++;
    }
    i++;
    while(str[i] != ';' && str[i]!='\0'){
        nstr[j] = str[i];
        i++;
        j++;
    }
    nstr[j] = '\0';
    nnstr[p] = '\0';
    FILE *fp2=fopen("outs.txt","a+");
    if(j==0){
        int result = evaluate(nnstr);

        cout << "Are You Save this Result:" << result<< endl;
        cout << "Yes / No (y/n)" << endl;
        char yn;
        cin >> yn;
        if(yn == 'y')
            fprintf(fp2,"%d\n",result);
    }
    else{
        lookval[x] = evaluate(nstr);

        cout << x << " = " << lookval[x] <<endl;
        cout << "Are You Save this '" << x << "' Result is :" << lookval[x]<< endl;
        cout << "Yes / No (y/n)" << endl;
        char yn;
        cin >> yn;
        if(yn == 'y')
            fprintf(fp2,"%c = %d\n",x,lookval[x]);
    }
}

int main() {
    char str[100];
    FILE *file = fopen ( "ins.txt", "r" );


while(fgets(str,sizeof str,file)!=NULL) /* read a line from a file */
{
    char x[100];
    int i = 0;
    while(str[i] != '\n'){
        x[i] = str[i];
        i++;
    }
    x[i] = '\0';
    Code(x);
}

    return 0;
}
