#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define MAX 1000
#define NKey 32
#define NOpr 36

int numProgram = 0;
char token[100];

static char KeyWords[NKey][20] = {
    "auto", "break", "case", "char", "const", "continue",
    "default", "do", "double", "else", "enum", "extern",
    "float", "for", "goto", "if", "int", "long",
    "register", "return", "short", "signed", "sizeof", "static",
    "struct", "switch", "typedef", "union", "unsigned", "void",   
	"volatile", "while"
};            //32个关键词


static char Operator[NOpr][10] = {
    "+", "-", "*", "/", "<", "<=", ">", ">=", "=", "==",
    "!=", ";", "(", ")", "^", ",", "\"", "\'", "#", "&"
    "&&", "|", "||", "%", "~", "<<", ">>", "[", "]", "{",
	"}", "\\", ".", "\?", ":", "!"
};            //36个符号




int IsDigit(char num)                              //如果是数字
{
	if (num <= '9'&&num >= '0')
		return 1;
	else
		return 0;
}

int IsIdentifiner(char indentifiner)               //如果是标识符
{
	if (indentifiner >= 'a'&&indentifiner <= 'z' || indentifiner >= 'A'&&indentifiner <= 'Z' || indentifiner == '_')
		return 1;
	else
		return 0;
}

int IsKeywords(char *words)                        //如果是关键词
{
	int i;
	for (i = 0; i < NKey; i++)
		if (strcmp(words, KeyWords[i]) == 0)
			return i + 1;
	return 0;
}

int CompareOperate(char *operator)                 //比较符号
{
	int i;
	for (i = 0; i < NOpr; i++)
		if (strcmp(operator, Operator[i]) == 0)
			return i + NKey + 1;
	return 0;
}

int IsOprate(char oprate)
{
	if (oprate == '+' || oprate == '-' || oprate == '*' || oprate == '/' || oprate == '<' || oprate == '>' || oprate == '=' ||
		oprate == '!' || oprate == ';' || oprate == '(' || oprate == ')' || oprate == '`' || oprate == ',' || oprate == '\"' ||
		oprate == '\'' || oprate == '#' || oprate == '&' || oprate == '|' || oprate == '%' || oprate == '~' || oprate == '[' ||
		oprate == ']' || oprate == '{' || oprate == '}' || oprate == '\\' || oprate == '.' || oprate == '\?' || oprate == ':')
		return 1;
	else
		return 0;
}

char *skip(char *sour_program,int max);            //跳过注释和无用信息

int ScanProgram(char *cha_program);

int main(int argc, char * argv[])
{
	int syn = 0;
	char SourceProgram[100000];
	char *Chan_Program;
	//int numProgram = 0;
	int i = 0;
	int j;
	FILE *inFile;

	if (argc<2) {
		printf("ERROR:input file name is needed. \n");
		exit(0);
	}

	inFile = fopen(argv[1], "r");

	if (inFile == NULL) {
		printf("ERROR:can not open file. \n");
		exit(0);
	}
	SourceProgram[i]=fgetc(inFile);
	while (SourceProgram[i] != EOF)              //保存源程序代码
	{
		i++;
		SourceProgram[i] = fgetc(inFile);
	}
	SourceProgram[++i] = '\0';
	fclose(inFile);

	Chan_Program=skip(SourceProgram, i);        //跳过注释并返回指针
	puts(Chan_Program);
	do{
		syn=ScanProgram(Chan_Program);                          //扫描并返回编码
		
		printf("<  %-10d%-100s  >\n", syn, token);

		for (j = 0; j < 100; j++)                               //将token数组清空
			token[j] = '\0';
		//numProgram--;
	} while (syn != -1);

	free(Chan_Program);
	return 0;

}


char *skip(char *sour_program, int max)
{
	char *ChangeProgram=(char *)malloc(100000);
	memset(ChangeProgram,0,100000);
	int i;
	int j = 0;

	for(i = 0 ; i <= max ; i++)
	{
		if (sour_program[i] == '/' && sour_program[i + 1] == '/')              //跳过//类注释
			while (sour_program[i] != '\n')
				i++;
		if (sour_program[i] == '/'&&sour_program[i+1] == '*')                  //跳过/*   */类注释
		{
			while (sour_program[i] != '*' || sour_program[i + 1] != '/')
				i++;
			i += 2;
		}
		if (sour_program[i] != '\n' && sour_program[i] != '\t' && sour_program[i] != '\v' && sour_program[i] != '\r')  //跳过换行符制表符等
			ChangeProgram[j++] = sour_program[i];
	}
	ChangeProgram[j] = '\0';
	ChangeProgram[++j] = EOF;
	return ChangeProgram;
}


int ScanProgram(char *cha_program)               //扫描改变过后灯程序代码
{
	int i=0;
	static int tag = 0;                         //tag标注是第几个"
	if (cha_program[numProgram - 1] == '\"' && tag == 0 &&cha_program[numProgram-2] != '\\')            //如果是字符串就返回260
	{
		
		while (cha_program[numProgram] != '\"')
		{
			token[i++] = cha_program[numProgram];
			numProgram++;
		}
		tag = 1;
		token[i] = '\0';
		return 260;
	}

	if (cha_program[numProgram] != '\"')
		tag = 0;

	while (cha_program[numProgram] == ' ')          //跳过空格
		numProgram++;

	if (IsDigit(cha_program[numProgram]))        //如果是数字就返回258
	{
		while (IsDigit(cha_program[numProgram]))
		{
			token[i++] = cha_program[numProgram];
			numProgram++;
		}

		token[i] = '\0';
		return 258;
	}

	else if (IsIdentifiner(cha_program[numProgram]))    //如果是关键字或者标识符
	{
		token[i++] = cha_program[numProgram];
		numProgram++;
		while (IsDigit(cha_program[numProgram]) || IsIdentifiner(cha_program[numProgram]))
		{
			token[i++] = cha_program[numProgram];
			numProgram++;
		}

		token[i] = '\0';

		if (IsKeywords(token))                         //如果是关键字就返回对应编码
		{
			return IsKeywords(token);
		}

		else                                           //如果是标识符就返回259
			return 259;
	}
        //如果是符号
	else if (IsOprate(cha_program[numProgram]))
	{
		int N;
		if (cha_program[numProgram] == '<')            //<,<<,<=
		{
			token[i++] = cha_program[numProgram];
			numProgram++;

			if (cha_program[numProgram] == '=')
			{
				token[i++] = cha_program[numProgram];
				numProgram++;
			}

			else if (cha_program[numProgram] == '<')
			{
				token[i++] = cha_program[numProgram];
				numProgram++;
			}
		}

		else if (cha_program[numProgram] == '>')                 //>,>>,>=
		{
			token[i++] = cha_program[numProgram];
			numProgram++;

			if (cha_program[numProgram] == '=')
			{
				token[i++] = cha_program[numProgram];
				numProgram++;
			}


			else if (cha_program[numProgram] == '>')
			{
				token[i++] = cha_program[numProgram];
				numProgram++;
			}
		}

		else if (cha_program[numProgram] == '=')                    //=,==
		{
			token[i++] = cha_program[numProgram];
			numProgram++;

			if (cha_program[numProgram] == '=')
			{
				token[i++] = cha_program[numProgram];
				numProgram++;
			}
		}

		else if (cha_program[numProgram] == '!')                  //!,!=
		{
			token[i++] = cha_program[numProgram];
			numProgram++;

			if (cha_program[numProgram] == '=')
			{
				token[i++] = cha_program[numProgram];
				numProgram++;
			}
		}

		else if (cha_program[numProgram] == '&')                    //&,&&
		{
			token[i++] = cha_program[numProgram];
			numProgram++;

			if (cha_program[numProgram] == '&')
			{
				token[i++] = cha_program[numProgram];
				numProgram++;
			}
		}

		else if (cha_program[numProgram] == '|')                   //|,||
		{
			token[i++] = cha_program[numProgram];
			numProgram++;

			if (cha_program[numProgram] == '|')
			{
				token[i++] = cha_program[numProgram];
				numProgram++;
			}
		}

		else                                                       //其他符号
		{
			token[i++] = cha_program[numProgram];
			numProgram++;
		}
		token[i] = '\0';
		N = CompareOperate(token);                             //返回符号对应编码
		
		return N;
	}

	else if (cha_program[numProgram] == EOF)                   //如果是结束返回-1
	{
		token[0] = 'E';
		token[1] = 'O';
		token[2] = 'F';

		//printf("<  -1       %s  >\n", token);
		return -1;

	}
}
