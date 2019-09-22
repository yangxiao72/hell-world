#define   FILE_OPER_SUCCESS   0
#define   FILE_OPER_FAIL      -1

#define   FILE_NAME_LEN       100
#define   ROOT_PATH           "/home/yangxiao/test"

int file_open(char *file_name, int flag, mode_t mode);
int file_create(char *file_name, mode_t mode);
int file_close(int fd);
int file_write(int fd, char *buffer, int length);
int file_read(int fd, char *buffer, int length);
int file_seek(int fd, int offset, int whence);

