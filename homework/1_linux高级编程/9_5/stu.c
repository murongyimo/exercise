/*************************************************************************
	> File Name: stu.c
	> Author: 
	> Mail: 
	> Created Time: 2016年09月10日 星期六 13时08分32秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

#define MAX_NAME_SIZE 20
#define MAX_SNO_SIZE 10

typedef struct STU{
    char name[MAX_NAME_SIZE];  //姓名
    char sno[MAX_SNO_SIZE];    //学号
    int score;      //成绩
}stu;


//添加学生信息
void input_stu()
{
    int fd;
    stu info;   //临时存储信息，等待写入
    if( ( fd = open("student",O_WRONLY|O_CREAT|O_APPEND,S_IRUSR|S_IWUSR ) ) == -1 ){
        perror("file open faild , can't input students' information");
        exit(-1);
    }else{
        //进行信息的录入，并存入文件，将文件关闭
        printf("请输入学生姓名：");
        scanf("%s",info.name);
        if( strlen( info.name ) > MAX_NAME_SIZE ){
            printf("字符串超长！\n");
            close(fd);
            return;
        }
        printf("请输入学生学号：");
        scanf("%s",info.sno);
        if( strlen(info.sno) > MAX_SNO_SIZE ){
            printf("学号超长！\n");
            close(fd);
            return;
        }
        printf("请输入学生linux课程成绩：");
        scanf("%d",&info.score);
        write( fd , (void *)(&info) , sizeof(info) );
        close(fd);
    }
}

//输出学生信息
void output_stu()
{
    int fd;
    stu info;   //暂时存储学生信息，在文件中读出后进行输出
    if( (fd = open("student",O_RDONLY)) == -1 ){
        printf("还没有信息被录入\n");
        return;
    }else{
        printf("**************学生信息表*****************\n");
        printf("\tName\t\tSNO\t\tGrade\n");
        while( read( fd , (void*)(&info) ,sizeof(info)) ){
            //读取所有的文件信息
            printf("\t%s\t\t%s\t\t%d\n",info.name,info.sno,info.score);
        }
    }

}

int main( void )
{
    int  cmd;
    printf("**************×××××Linux成绩管理系统×××××*****************\n");
    do{
        //根据提示，输入命令代号
        printf("**************×××××可执行操作内容×××××*****************\n");
        printf("\t\t0-录入学生信息\n\t\t1-输出学生信息\n\t\t2-退出系统\n");
        printf("**************××××××××××××××××××××××××*****************\n");
        printf("请输入操作代号：");
        scanf("%d",&cmd);
        //若cmd为0，打开文件，追加学生信息
        if( cmd == 0 )
            input_stu();
        //若cmd为1，只读打开文件，读出学生信息，打印出来
        else if( cmd == 1 )
            output_stu();
    }while( cmd != 2 );
    printf("**************××××××××××××××××××××××××××××*****************\n");
    return 0;
}
