#include <io_utils.h>
#include <time.h>

int main() {
  time_t current_time;
  time(&current_time);
  PRINT_LLONG(current_time);

  struct tm *calendar_time = localtime(&current_time);
  PRINT_INT(calendar_time->tm_year);
  PRINT_INT(calendar_time->tm_mon);
  PRINT_INT(calendar_time->tm_mday);
  PRINT_INT(calendar_time->tm_hour);
  PRINT_INT(calendar_time->tm_min);
  PRINT_INT(calendar_time->tm_sec);

  puts(asctime(calendar_time));
  puts(ctime(&current_time));

  //2020-11-09 06:59:47
  char current_time_s[20];
  // size_t size = strftime(current_time_s, 20, "%Y-%m-%d %H:%M:%S", calendar_time);
  size_t size = strftime(current_time_s, 20, "%F %T", calendar_time);
  PRINT_INT(size);
  puts(current_time_s);

  char *time = "2023-11-03 19:51:20.123";
  struct tm parsed_time;
  int millisecond;
  // unix
  // char *unparsed_string = strptime(time, "%F %T", &parsed_time);

  // msvc
  sscanf(time, "%4d-%2d-%2d %2d:%2d:%2d.%3d",
         &parsed_time.tm_year,
         &parsed_time.tm_mon,
         &parsed_time.tm_mday,
         &parsed_time.tm_hour,
         &parsed_time.tm_min,
         &parsed_time.tm_sec,
         &millisecond);

  parsed_time.tm_year -= 1900;
  parsed_time.tm_mon -= 1;

  mktime(&parsed_time);

  PRINT_INT(parsed_time.tm_year);
  PRINT_INT(parsed_time.tm_mon);
  PRINT_INT(parsed_time.tm_mday);
  PRINT_INT(parsed_time.tm_hour);
  PRINT_INT(parsed_time.tm_min);
  PRINT_INT(parsed_time.tm_sec);

//  puts(unparsed_string);
//  sscanf(unparsed_string, ".%3d", &millisecond);

  PRINT_INT(millisecond);

  return 0;
}
