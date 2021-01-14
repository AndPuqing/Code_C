/*
这是ccf 2020 09第三题
对数字逻辑信号进行模拟，完成输出
变量定义：
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct //定义了逻辑机的结构
{
    int kind;        //种类
    int **input;     //指针数组，将会指向输入指针
    int inputNumber; //输入的数量
    int *output;     //输出指针
    int condition;
} machine;

int main()
{
    int n = 0; //结构数量
    scanf("%d", &n);
    int i;
    for (i = 0; i < n; i++)
    {
        int inputNumber, machineNumber; //输入数量，机器数量
        scanf("%d %d", &inputNumber, &machineNumber);
        machine machineline[machineNumber]; //结构数组
        char tmp[5];                        //读入机器字符匹配字符
        int j;
        int *inputio = (int *)malloc(sizeof(int) * inputNumber); //为输入指针分配空间，为一维数组
        for (j = 0; j < machineNumber; j++)
        {
            int ionumber = 0; //是机器的输入接口数量
            scanf("%s %d", tmp, &ionumber);
            if (!strcmp(tmp, "NOT"))
            {
                machineline[j].kind = 0;                                         //种类
                machineline[j].output = (int *)malloc(sizeof(int));              //为输出分配空间
                machineline[j].input = (int **)malloc(sizeof(int *) * ionumber); //为指针数组开辟空间
                machineline[j].inputNumber = ionumber;                           //输入数量
            }
            if (!strcmp(tmp, "AND"))
            {
                machineline[j].kind = 1;
                machineline[j].output = (int *)malloc(sizeof(int));
                machineline[j].input = (int **)malloc(sizeof(int *) * ionumber);
                machineline[j].inputNumber = ionumber;
            }
            if (!strcmp(tmp, "OR"))
            {
                machineline[j].kind = 2;
                machineline[j].output = (int *)malloc(sizeof(int));
                machineline[j].input = (int **)malloc(sizeof(int *) * ionumber);
                machineline[j].inputNumber = ionumber;
            }
            if (!strcmp(tmp, "XOR"))
            {
                machineline[j].kind = 3;
                machineline[j].output = (int *)malloc(sizeof(int));
                machineline[j].input = (int **)malloc(sizeof(int *) * ionumber);
                machineline[j].inputNumber = ionumber;
            }
            if (!strcmp(tmp, "NAND"))
            {
                machineline[j].kind = 4;
                machineline[j].output = (int *)malloc(sizeof(int));
                machineline[j].input = (int **)malloc(sizeof(int *) * ionumber);
                machineline[j].inputNumber = ionumber;
            }
            if (!strcmp(tmp, "NOR"))
            {
                machineline[j].kind = 5;
                machineline[j].output = (int *)malloc(sizeof(int));
                machineline[j].input = (int **)malloc(sizeof(int *) * ionumber);
                machineline[j].inputNumber = ionumber;
            }
            int itemp;
            char iotemp[3]; //读入接口连接定义
            for (itemp = 0; itemp < ionumber; itemp++)
            {
                scanf("%s", iotemp);
                int tmp_1 = iotemp[1] - 49; //将字符1,2...转化为整数型
                if (iotemp[0] = 'I')
                {
                    machineline[j].input[itemp] = &inputio[tmp_1]; //将机器输入指针数组指向，输入数据地址
                    machineline[j].condition++;
                }
                else
                {
                    machineline[j].input[itemp] = machineline[tmp_1].output; //指向机器的输出地址
                    machineline[j].condition++;
                }
            }
            int problemNumber; //对多个问题求解
            scanf("%d", &problemNumber);
            int i_1;
            int **question = (int **)malloc(sizeof(int *) * problemNumber); //是储存问题的二维数组
            for (i_1 = 0; i_1 < ionumber; i_1++)
            {
                question[i_1] = (int *)malloc(sizeof(int) * ionumber); //为每个一维指针分配空间，成为二维数组
            }
            for (i_1 = 0; i_1 < problemNumber; i_1++)
            {
                int i_2;
                for (i_2 = 0; i_2 < inputNumber; i++)
                {
                    scanf("%d", &question[i_1][i_2]); //读入数据
                }
            }
            int answerRequire[problemNumber][3];
            for (i_1 = 0; i_1 < problemNumber; i_1++)
            {
                int i_2;
                for (i_2 = 0; i_2 < 3; i_2++)
                {
                    scanf("%d", &answerRequire[i_1][i_2]); //读入数据要求
                }
            }
        }
    }
}