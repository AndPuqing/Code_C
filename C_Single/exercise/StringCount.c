/*该代码实现一个函数，统计给定字符串中的大写字母、小写字母、空格、数字以及其它字符各有多少。
函数接口定义： void StringCount(char *s);
其中 char *s 是用户传入的字符串。函数StringCount须在一行内按照
大写字母个数 小写字母个数 空格个数 数字个数 其它字符个数 的格式输出。
*/
#include <stdio.h>
#include <stdio.h>
#define MAXS 15

void StringCount(char *s);
void ReadString(char *s); /* 由裁判实现，略去不表 */

int main()
{
    char s[MAXS];

    ReadString(s);
    StringCount(s);

    return 0;
}

void StringCount(char *s)
{
    int i = 0;
    int letterA = 0;
    int lettera = 0;
    int blank = 0;
    int digit = 0;
    int other = 0;
    while (s[i] != '\0') //字符串是以0结尾的
    {
        int a = s[i];
        if ((a > 64 && a < 91))
        {
            letterA++;
            i++;
            continue;
        }
        if ((a > 96 && a < 123))
        {
            lettera++;
            i++;
            continue;
        }
        if (a == 32)
        {
            blank++;
            i++;
            continue;
        }
        if (a > 47 && a < 58)
        {
            digit++;
            i++;
            continue;
        }
        other++;
        i++;
    }
    printf("%d %d %d %d %d", letterA, lettera, blank, digit, other);
}