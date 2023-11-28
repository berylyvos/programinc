#include <stdio.h>
#include <io_utils.h>
#include <sys/stat.h>

typedef struct __crt_stdio_stream_data
{
  union
  {
    FILE  _public_file;
    char* _ptr;
  };

  char*            _base;
  int              _cnt;
  long             _flags;
  long             _file;
  int              _charbuf;
  int              _bufsiz;
  char*            _tmpfname;

} WinFile;

long GetFileSize(const char *filename) {
  struct stat st;
  stat(filename, &st);
  return st.st_size;
}

int IsDirectory(const char *filename) {
  struct stat st;
  stat(filename, &st);
  return st.st_mode & S_IFDIR;
}

int main() {
  int result = remove("data_copy/io_utils.h");
  PRINT_INT(result);
  result = remove("data_copy/三国演义.txt");
  PRINT_INT(result);

//  rename("data_copy/三国演义.txt", "data_copy/sanguo.txt");

//  FILE *file = tmpfile();
//  WinFile *win_file = (WinFile *) file;
//  puts(win_file->_tmpfname);
//  fclose(file);

  PRINT_LONG(GetFileSize("data/三国演义.txt"));
  PRINT_INT(IsDirectory("data/三国演义.txt"));
  PRINT_HEX(IsDirectory("data"));
  return 0;
}
