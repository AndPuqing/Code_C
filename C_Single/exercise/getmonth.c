/*要求实现函数，可以返回一个给定月份的英文名称。
函数接口定义： char *getmonth(int n);
函数getmonth应返回存储了n对应的月份英文名称的字符串头指针。如果传入的参数n不是一个代表月份的数字，则返回空指针NULL。
*/
#include <stdio.h>

char *getmonth(int n);

int main()
{
    int n;
    char *s;

    scanf("%d", &n);
    s = getmonth(n);
    if (s == NULL)
        printf("wrong input!\n");
    else
        printf("%s\n", s);

    return 0;
}

char *getmonth(int n)
{
    char *re;
    switch (n)
    {
    case 1:
        re = "January";
        break;
    case 2:
        re = "February";
        break;
    case 3:
        re = "March";
        break;
    case 4:
        re = "April";
        break;
    case 5:
        re = "May";
        break;
    case 6:
        re = "June";
        break;
    case 7:
        re = "July";
        break;
    case 8:
        re = "August";
        break;
    case 9:
        re = "September";
        break;
    case 10:
        re = "October";
        break;
    case 11:
        re = "November";
        break;
    case 12:
        re = "December";
        break;
    default:
        return NULL;
        break;
    }
    return re;
}