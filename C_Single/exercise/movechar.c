//将输入字符串的前3个字符移到最后。
//其中char s[]是用户传入的字符串，题目保证其长度不小于3；
//函数Shift须将按照要求变换后的字符串仍然存在s[]里。
#include <stdio.h>
#include <string.h>

#define MAXS 10

void Shift(char s[]);

void GetString(char s[]); /* 实现细节在此不表 */

int main()
{
    char s[MAXS];

    GetString(s);
    Shift(s);
    printf("%s\n", s);

    return 0;
}

void Shift(char s[])
{
    int len = strlen(s);
    char t[4];
    for (int i = 0; i < 3; i++)
        t[i] = s[i];
    for (int i = 0; i < len - 3; i++)
        s[i] = s[i + 3];
    for (int i = len - 3; i < len; i++)
        s[i] = t[3 - len + i];
}