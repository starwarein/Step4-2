#include<stdio.h>

int func(int a,int b){

    printf("This is function.");
    return a+b;
}


/*这是第一种注释*/
int main(){
    float a=1.0;float b=10.0;//这是第二种注释
    char *ch="Hello,world!";
    if(a<b){
        a=a+1;
        b=a+b;
    }
    int c;
    scanf("%d",&c);
    printf("result:");
    printf("%f,%f,%d\n",a,b,c);
    int end=func(2,4);
    printf("end:%d",end);
    return 0;
}
