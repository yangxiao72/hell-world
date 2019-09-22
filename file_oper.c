#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <file_oper.h>

/* open file, flat:O_RDONLY, O_WRONLY, O_RDWRE, O_CREAT, O_APPEND */
int file_open(char *file_name, int flag, mode_t mode)
{
    int fd;

    if(flag & O_CREAT)
    {
         fd = open(file_name, flag, mode);
    }
    else
    {
        fd = open(file_name, flag);
    }

    if(fd <= 0)
    {
        printf("open file:%s fail, retcode:%u", file_name, fd);
        return FILE_OPER_FAIL;
    }

    return fd;
}

int file_close(int fd)
{
    int retcode;

    retcode = close(fd);
    if(retcode <= 0)
    {
        printf("close file:%s fail", file_name);
        return FILE_OPER_FAIL;
    }

    return FILE_OPER_SUCCESS;
}

/* create a file with mode:O_CREAT, O_WRONLY, O_TRUNC */
int file_create(char *file_name, mode_t mode)
{
    int fd;

    fd = creat(file_name, mode);
    if(fd <= 0)
    {
        printf("create file:%s fail", file_name);
        return FILE_OPER_FAIL;
    }
    
    return fd;
}

int file_write(char *file_name, char *buffer, int length)
{
    int write_len;

    if(buffer == NULL)
    {
        printf("write file:%s fail, buffer is NULL", file_name);
        return FILE_OPER_FAIL;
    }

    write_len = write(file_name, buffer, length);

    if(write_len != length || write_len <= 0)
    {
        printf("write file:%s fail", file_name);
        return FILE_OPER_FAIL;
    }

    return write_len;
}

int file_read(char *file_name, char *buffer, int length)
{
    int read_len;

    if(buffer == NULL)
    {
        printf("read file:%s fail, buffer is NULL\n", file_name);
        return FILE_OPER_FAIL;
    }

    read_len = read(file_name, char *buffer, int length);
    if(read_len < 0)
    {
        printf("read file:%s fail\n", file_name);
        return FILE_OPER_FAIL;
    }

    return read_len;
}

/* whence:SEEK_SET, SEEK_CUR, SEEK_END */
int file_seek(int fd, int offset, int whence)
{
    int cur_position;

    position = lseek(int fd, int offset, int whence);
    if(position < 0)
    {
        printf("seek file:%s fail\n", file_name);
        return FILE_OPER_FAIL;
    }

    return position;
}




