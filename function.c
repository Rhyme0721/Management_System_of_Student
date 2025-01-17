#include<stdio.h>
//变量声明
//学生信息结构体
typedef struct student
{
    float ID;
    float Chinese;
    float Math;
    float English;
    float Ave;
}STU;
int num;//待输入的成绩的学生人数
float search_id;//待查询的id
int flag,flag_p;//标记位flag标记成绩是否录入；flag_p标记是否完成成绩排序
STU stu[100];

void Help(void)
{
    printf("****************************************\n");
    printf("  *   学生成绩管理系统——帮助菜单    *  \n");
    printf("****************************************\n");
    printf("  *     H = 显示帮助菜单            *  \n");
    printf("  *     T = 成绩录入                *  \n");
    printf("  *     A = 计算学生平均分          *  \n");
    printf("  *     L = 列出成绩表              *  \n");
    printf("  *     P = 按平均成绩由高到低排序  *  \n");
    printf("  *     S = 按学号查询学生成绩      *  \n");
    printf("  *     C = 清屏                    *  \n");
    printf("  *     Q = 退出系统                *  \n");
    printf("****************************************\n");
    printf("  *Copyright <C> 2024.01.28 By Viki * \n");
    printf("****************************************\n");
    
}

//功能：成绩输入
void Type(void)
{
    printf("请输入学生人数：");
    scanf("%d",&num);
    printf("请输入%d名学生的三门课成绩：\n",num);
    printf("学号\t语文\t数学\t外语\n");
    for(int i=0;i<num;i++)
    {
        stu[i].ID=i+1;
        printf(" %d\t",i+1);
        scanf("%f%f%f",&stu[i].Chinese,&stu[i].Math,&stu[i].English);
        getchar();
    }
    flag = 1;//输入完成，标志置1
}

//查看成绩单
void List(void)
{
    printf("学生成绩如下：\n");
    printf("学号\t语文\t数学\t外语\t平均分\n");
    for(int i=0;i<num;i++)
        printf(" %.0f\t%.1f\t%.1f\t%.1f\t%.1f\n",stu[i].ID,stu[i].Chinese,stu[i].Math,stu[i].English,stu[i].Ave);
}

//计算每位同学成绩的平均分
void Average(void)
{
    for(int i=0;i<num;i++)
        stu[i].Ave = (stu[i].Chinese+stu[i].Math+stu[i].English)/3;    
    flag_p = 1;
    printf("平均分已计算。请使用命令L查看。\n");    
}

//根据平均分，从大到小排序
void Sort(void)
{
    for(int i=0;i<num-1;i++)//冒泡排序逻辑
    {
        for(int j=0;j<num-1-i;j++)
        {
            if(stu[j].Ave < stu[j+1].Ave)
            {
                STU temp = stu[j];
                stu[j] = stu[j+1];
                stu[j+1] = temp;
            }
        }
    }
    printf("完成排序。请使用命令L查看。\n");
}

//输入查询学号，查询该同学的成绩
int Search(void)
{
    printf("输入要查询的学生学号:");
    scanf("%f",&search_id);
    getchar();
    if(search_id > num)
    {
        printf("无效学号超出查询范围!请尝试其他指令\n");
        return 0;
    }
    for(int i=0;i<num;i++)
    {
        if(stu[i].ID == search_id)
        {
            printf("学号\t语文\t数学\t外语\t平均分\n");
            printf(" %.0f\t%.1f\t%.1f\t%.1f\t%.1f\n",stu[i].ID,stu[i].Chinese,stu[i].Math,stu[i].English,stu[i].Ave);    
        }
        
    }
    return 0;
}

