/*本题要求实现一个删除字符串中的指定字符的简单函数。
函数接口定义： void delchar(char *str, char c);
其中char *str是传入的字符串，c是待删除的字符。
函数delchar的功能是将字符串str中出现的所有c字符删除。
这个函数是对字符串的考点，而字符串可谓是难点
*/

#include <stdio.h>
#define MAXN 20

void delchar(char *str, char c);
void ReadString(char s[]); /* 由裁判实现，略去不表 */

int main()
{
    char str[MAXN], c;

    scanf("%c\n", &c);
    ReadString(str);
    delchar(str, c);
    printf("%s\n", str);

    return 0;
}

//参考
void delchar(char *str, char c)
{
    //要对字符串的各个块重定向，由两线构成
    int i = 0;                 //动态
    int j = 0;                 //“静态”
    while (*(str + i) != '\0') //判断结束没
    {
        if (*(str + i) == c)
        {
            //此操作将两线拉开距离
            i++;
            continue;
        }
        else
        {
            //将指针重定向
            *(str + j) = *(str + i);
            j++;
            i++;
        }
    }
    //截断末尾
    *(str + j) = '\0';
}