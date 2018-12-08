/****学生成绩管理系统****/

#include<stdio.h>
#include<string.h>

#define N 5
#define M 3

struct Student
{
    char name[10];
    int number;
    float score[M];
    float average;

};

struct Student a[N];
void information (struct Student *a);
void everyonesumaver(struct Student *a );
void everylessionsumaver(struct Student *a);
void segment_number(struct Student *a );
void search (struct Student *a);

int main (void)
{
    int n;
    
    do
    {
        printf("学生成绩管理系统\n");
        printf("请选择功能菜单，按0退出程序\n");
        printf("1 从文件中导入原始数据\n");
        printf("2 添加学生信息\n");
        printf("3 统计每位同学的平均分\n");
        printf("4 统计每门课程的平均分\n");
        printf("5 分段统计人数\n");
        printf("6 查询学生\n");
        printf("7 报表输出\n");
        scanf("%d",&n);

        switch (n)
    {
        case 1:
            
            break;

        case 2:
            
            information(a);
     
            break;
        
        case 3:
                everyonesumaver(a);
            break;

        case 4:
                everylessionsumaver(a);
            break;

        case 5:
                segment_number(a);
            break;

        case 6:
                search(a);
            break;

        case 7:

            break;
        default:
            break;
    }
    } while (n!=0);
    
    
    
    return 0;
}

void information (struct Student *a)
{
    int i;
    int j;
    
    for( i = 0; i < N; i++)
    {
        printf("请输入第%d个同学的名字",i+1);
        scanf("%s",&a[i].name);
        printf("请输入第%d个同学的学号",i+1);
        scanf("%d",&a[i].number);
        for(j=0;j<M;j++){
            printf("请输入第%d个同学的第%d门成绩",i+1,j+1);
            scanf("%f",&a[i].score[j]);
        }
    }

}

void everyonesumaver (struct Student *a)
{
    int i,j;
    float sum=0;
    
    for( i = 0; i < N; i++)
    {
        
        for( j = 0; j < M; j++)
        {
            sum+=a[i].score[j];
        }
            a[i].average=sum/3.0;
            printf("第%d个同学的每门功课的平均分是%.2f\n",i+1,sum/3.0);
            sum=0;
    }
    
}

void everylessionsumaver (struct Student *a)
{
    int i,j;
    float sum=0;
    
    for( i = 0; i < M; i++)
    {
        
        for( j = 0; j < N; j++)
        {
            sum+=a[j].score[i];
            
        }
         printf("第%d门功课的平均分是%f\n",i+1,sum/5.0);
         sum=0;
    }
    
}

void segment_number(struct Student *a)
{
    int i,j;
    int count[4]={0};

    
    for( i = 0; i < N; i++)
    {
        
        if (a[i].average>=90) {
            count[0]++;
        }
        
        else if (a[i].average<90&&a[i].average>=70) {
            count[1]++;
        }
        else if(a[i].average<70&&a[i].average>=60) {
            count[2]++;
        }
        else {
            count[3]++;
        }
        
    }
    printf("\t平均分大于90的有%d人\n",count[0]);
    printf("\t平均分在70到90之间的有%d人\n",count[1]);
    printf("\t平均分在70到60有%d人\n",count[2]);
    printf("\t平均分小与60的有%d人\n",count[3]);  
}

void search (struct Student *a)
{
    char b[10];
    int i;
    int j;
    printf("请输入你要查找的名字\n");
    scanf("%s",b);
    
    for( i = 0; i < N; i++)
    {
       
        if( strcmp(a[i].name,b)==0){
            printf("name=%s\n",a[i].name);
            printf("average=%f\n",a[i].average);
            printf("number=%d\n",a[i].number);
            
            for( j = 0; j < M; j++)
            {
                printf("第%d门成绩=%f\n",j+1,a[i].score[j]);
            }
            
        }
    }
    
}



