#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
int main(int argc,char* argv[])
{
    //stack
    int l=atoi(argv[2]);
    int a[l],top=-1;
    FILE *fp,*fp2;
    fp=fopen(argv[1],"r");
    fp2=fopen("stack.txt","w");
    char ch;
    ch=getc(fp);
    while(ch!=EOF)
    {
        if(ch=='+')
        {
            int x;
            if(top==(l-1)){
                fprintf(fp2,"overflow\n");
            }
            else
            {
                fscanf(fp,"%d",&x);
                top++;
                a[top]=x;
                fprintf(fp2,"pushed %d\n",x);
            }
        }

        else if(ch=='-')
        {
            int x;
            if(top==-1){
                fprintf(fp2,"underflow\n");
            }
            else
                {
                    fscanf(fp,"%d",&x);
                    fprintf(fp2,"popped %d\n",a[top]);
                    top--;
            }
        }
        else if(ch=='?')
        {
            int i,x,f=0;
            fscanf(fp,"%d",&x);
            for(i=0;i<top;i++){
                if(x==a[i])
                    f=1;
            }
            if(f==1){
                fprintf(fp2,"found %d\n",x);
            }
            else{
                fprintf(fp2,"not found %d\n",x);
        }
        }
        else if(ch=='!'){
            for(int i=top;i>=0;i--){
                fprintf(fp2,"%d ",a[i]);
            }
            fprintf(fp2,"\n");
        }
            ch=getc(fp);
        }
        fseek(fp, 0, SEEK_SET);

        //queue
        top=-1;
        int a2[l];
    FILE *fp3;
    fp3=fopen("queue.txt","w");
    ch=getc(fp);
    while(ch!=EOF)
    {
        if(ch=='+')
        {
            int x;
            if(top==(l-1)){
                fprintf(fp3,"overflow\n");
            }
            else
            {
                fscanf(fp,"%d",&x);
                top++;
                a2[top]=x;
                fprintf(fp3,"enqueued %d\n",x);
            }
        }

        else if(ch=='-')
        {
            int x;
            if(top==-1){
                fprintf(fp3,"underflow\n");
            }
            else
                {
                    fscanf(fp,"%d",&x);
                    int b=a2[0];
                    for(int i=0;i<top;i++){
                        a2[i]=a2[i+1];
                    }
                    top--;
                    fprintf(fp3,"dequeued %d\n",b);
            }
        }
        else if(ch=='?')
        {
            int i,x,f=0;
            fscanf(fp,"%d",&x);
            for(i=0;i<=top;i++){
                if(x==a2[i])
                    f=1;
            }
            if(f==1){
                fprintf(fp3,"found %d\n",x);
            }
            else{
                fprintf(fp3,"not found %d\n",x);
        }
        }
        else if(ch=='!'){
            for(int i=0;i<=top;i++){
                fprintf(fp3,"%d ",a2[i]);
            }
            fprintf(fp3,"\n");
        }
            ch=getc(fp);
        }
        fseek(fp, 0, SEEK_SET);
        //dll
        int a4[MAX];
        top=-1;
    FILE *fp4;
    fp4=fopen("dll.txt","w");
    ch=getc(fp);
    while(ch!=EOF)
    {
        if(ch=='+')
        {
            int x;
                fscanf(fp,"%d",&x);
                top++;
                a4[top]=x;
                fprintf(fp4,"inserted %d\n",x);
        }

        else if(ch=='-')
        {
            int i,x,f=0,pos;
            fscanf(fp,"%d",&x);
            for(i=0;i<top;i++){
                if(x==a4[i]){
                    f=1;
                    pos=i;
                }
            }
            if(f==1){
             fprintf(fp4,"deleted %d\n",x);
             for(i=pos;i<top;i++){
                a4[i]=a4[i+1];
             }
             top--;
        }
        else{
            fprintf(fp4,"cannot delete %d\n",x);
        }
        }
        else if(ch=='?')
        {
            int i,x,f=0;
            fscanf(fp,"%d",&x);
            for(i=0;i<top;i++){
                if(x==a4[i])
                    f=1;
            }
            if(f==1){
                fprintf(fp4,"found %d\n",x);
            }
            else{
                fprintf(fp4,"not found %d\n",x);
        }
        }
        else if(ch=='!'){
            for(int i=top;i>=0;i--){
                fprintf(fp4,"%d ",a4[i]);
            }
            fprintf(fp4,"\n");
        }
            ch=getc(fp);
        }
    }

