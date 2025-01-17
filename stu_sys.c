#include <stdio.h>
#include<stdlib.h>
#include "function.h"
//全局变量声明
char command;

int main(int argc, char const *argv[])
{
    Help();
    while (1)
    {
        printf("请输入命令=");
        scanf("%c",&command);
        getchar();//循环中回收垃圾字符--回车
        switch (command)
        {
        case 'H':
                Help();
            break;
        case 'T':
                if(flag == 0)
                    Type();
                else
                    printf("成绩录入已完毕，请尝试其他指令！\n");
            break;
        case 'A':
                if(flag == 1)
                    Average();
                else
                    printf("成绩表为空！请先使用命令 T 录入学生成绩。\n");
            break;
        case 'L':
                if(flag == 1)
                   List();
                else
                    printf("成绩表为空！请先使用命令 T 录入学生成绩。\n");
            break;
        case 'P':
                if(flag == 1)                   
                    if(flag_p == 1)
                        Sort();
                    else
                        printf("平均值未计算，无法排序！请先执行命令 A 计算平均值。\n");
                else
                    printf("成绩表为空！请先使用命令 T 录入学生成绩。\n");
           break;
        case 'S':
                if(flag == 1)                    
                    Search();
                else
                    printf("成绩表为空！请先使用命令 T 录入学生成绩。\n");        
            break;
        case 'C':
            system("clear");
            break;
        case 'Q':  
                return 0;      
            break;                    
        default:
            printf("命令有误，请重新输入\n");
            break;
        }
    }
    return 0;
}


