#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int charClass;
#define MAX_LEN 1000
char lexeme[MAX_LEN];//保存当前构建的词素
char nextChar;
char next2Char;
int lexLen;
int token;
int nextToken;
FILE * inFile;

#define LETTER 0        //字符
#define DIGIT 1      //数字
#define UNKNOWN 999

enum {WHILE=258,IF,EISE,FOR,RET,INT,ID,EQU,ERROR};
char * keywords[]={"while","if","else","for","return",0};
//指针数组，数组内每一个元素指向一个字符串
void addChar()
{   /*将nextChar中的字符放到字符串数组lexeme中*/
    if(lexLen<=MAX_LEN-2){
        lexeme[lexLen++]=nextChar;
        lexeme[lexLen]=0;
    }
    else{
        printf("ERROR:lexeme is too long. \n");
    }
}

void getChar()
{   /*getChar从输入程序中获取下一个输入字符，将它放在全局变量nextChar中。
    getChar还必须确定输入字符所属的字符类，将它放到全局变量charClass中。*/
    static int firstRun=1;
    if(firstRun){
        nextChar=getc(inFile);
        next2Char=getc(inFile);
        firstRun=0;
    }
    else{
        nextChar=next2Char;
        next2Char=getc(inFile);
    }

    if(nextChar==EOF){
        charClass=EOF;
    }
    else{
        if(isalpha(nextChar))//判断是否为英文字符
            charClass=LETTER;
            else if(isdigit(nextChar))//判断是否为数字
                charClass=DIGIT;
            else
                charClass=UNKNOWN;
    }
}

void getNonBlank()//跳过空格
{
    while(isspace(nextChar))//判断是否为空格，是则再读取下一个
        getChar();
}

int checkSymbol(char ch,char nextCh)
{
    switch(ch){
        case '(':case ')':case ';':case '+': case '-':case '{':case '}':
        addChar();
        nextToken=ch;
        break;
        case '=':
            addChar();
            nextToken=ch;
            if('='==nextCh){
                getChar();
                addChar();
                nextToken=EQU;//为判等号
            }
            break;
        case EOF:
            addChar();
            nextToken=EOF;
            break;
        default:
            printf("ERROR:unknown character '%c'. \n",ch);
            nextToken=ERROR;
    }
    return nextToken;
}

void checkKeywords(char * pword)
{
    int i=0;
    while(keywords[i]!=0){
        char * pkeyword=keywords[i];
        if(0==strcmp(pword,pkeyword)){
            nextToken=258+i;
            return;
        }
        i++;
    }
}

int lexer()
{
    lexLen=0;
    getNonBlank();
    switch(charClass){
        case LETTER:
            addChar();
            getChar();
            while(LETTER==charClass||DIGIT==charClass){
                addChar();
                getChar();
            }
            nextToken=ID;
            //检查当前标识符是否是关键字
            checkKeywords(lexeme);
            break;
        case DIGIT:
            addChar();
            getChar();
            while(DIGIT==charClass){
                addChar();
                getChar();
            }
            nextToken=INT;
            break;
        case UNKNOWN:
            checkSymbol(nextChar,next2Char);
            getChar();
            break;
        case EOF:
            nextToken=EOF;
            lexeme[0]='E';
            lexeme[1]='O';
            lexeme[2]='F';
            lexeme[3]=0;
            break;
    
    }

    printf("<%6d, %s >\n",nextToken,lexeme);
    return nextToken;
}

void main(int argc,char * argv[])
{
    if(argc<2){
        printf("ERROR:input file name is needed. \n");
        exit(0);
    }

    inFile=fopen(argv[1],"r");
    if(inFile==NULL){
        printf("ERROR:can not open file. \n");
        exit(0);
    }
    getChar();
    while(nextToken!=EOF)
        lexer();
}