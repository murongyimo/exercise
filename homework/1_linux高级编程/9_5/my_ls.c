/*************************************************************************
	> File Name: my_ls.c
	> Author: 
	> Mail: 
	> Created Time: 2016年09月10日 星期六 11时08分44秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h> 
int main( void )
{
    DIR *dir;
    struct dirent *ptr;
    if( ( dir = opendir(".") ) == NULL )
    {
        perror("opendir");
        exit(EXIT_FAILURE);
    }
    while( ( ptr = readdir(dir) ) != NULL )
        if( strcmp(ptr->d_name, ".") && strcmp(ptr->d_name , ".." )) 
            printf("%s  \t",ptr->d_name);
    printf("\n");
    closedir(dir);
}
