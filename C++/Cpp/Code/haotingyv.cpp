//字符串赋值不能直接画等号。需要字符串拷贝函数 
#include<stdio.h>
#include<math.h>
#include<string.h>
#define A 3 
struct Student
{
    char number;
    char name[100];
    char location[100];
    float score;
}
stu[A];
int main()
{
    int i,j,a=0,b=0,c=0,d=0;
    char t[100];
    float max=0,min=100,average,sum=0,variance=0;
    printf("输入所以学生信息:\n");
    for(i=0; i<A; i++)
    {
        scanf("%s",&stu[i].number);
        scanf("%s",&stu[i].name);
        scanf("%s",&stu[i].location);
        scanf("%f",&stu[i].score);
    }
    for(i=0; i<A; i++)
    {
        if(stu[i].score>=0&&stu[i].score<60) a++;
        if(stu[i].score>=60&&stu[i].score<75) b++;
        if(stu[i].score>=75&&stu[i].score<90) c++;
        if(stu[i].score>=90&&stu[i].score<=1000) d++;
    }
    printf("优秀的人数为%d\n良好的人数为%d\n及格的人数为%d\n不及格的人数为%d\n",d,c,b,a);
    for(i=0; i<A; i++)
    {
        sum=sum+stu[i].score;
        if(stu[i].score>max) max=stu[i].score;
        if(stu[i].score<min) min=stu[i].score;
    }
    average=sum/A;
    for(i=0; i<A; i++)
        variance=variance+(stu[i].score-average)*(stu[i].score-average);
    variance=variance/A;
    
	
	printf("最高分是%f\n最低分是%f\n成绩均值为%f\n方差为%f\n",max,min,average,variance);
    for(j=0; j<(A-1); j++)
        for(i=0; i<(A-1-j); i++)
        {
            if(strcmp(stu[i].location,stu[i+1].location)>0)
            {
            	  strcpy(t,stu[i].location);
            	  strcpy(stu[i].location,stu[i+1].location);
            	  strcpy(stu[i+1].location,t);
//                t=stu[i].location;
//                stu[i].location=stu[i+1].location;
//                stu[i+1].location=t;
            }
        }
    for(i=0; i<(A-1); i++)
        if(strcmp(stu[i].location,stu[i+1].location)==0)
            stu[i+1].score=stu[i].score+stu[i+1].score;
    for(i=0; i<(A-1); i++)
        if(strcmp(stu[i].location,stu[i+1].location)!=0)
            printf("%s的总成绩是%f\n",stu[i].location,stu[i].score);
}

