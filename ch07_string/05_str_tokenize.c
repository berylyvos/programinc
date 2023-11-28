#include <io_utils.h>
#include <string.h>
#include <stdlib.h>

int main() {
  char string[] = "C, 1972; C++, 1983; Python, 1991; Java, 1995; Golang, 2009; Rust, 2010; Kotlin, 2011";

  typedef struct {
    char *name;
    int year;
  } Language;

  const char *language_break = ";";
  const char *field_break = ",";

  int language_cap = 2;
  int language_size = 0;

  Language *languages = malloc(sizeof(Language) * language_cap);

  char *next = strtok(string, field_break);
  char *end;
  while (next) {
    Language language;
    language.name = next;

    next = strtok(NULL, language_break);
    if (next) {
      language.year = (int)strtol(next, &end, 10);

      if (language_size + 1 > language_cap) {
        language_cap *= 2;
        languages = realloc(languages, sizeof(Language) * language_cap);
        if (!languages) {
          abort();
        }
      }

      languages[language_size++] = language;

      next = strtok(NULL, field_break);
      while (next && *next == ' ') ++next;
    }
  }

  PRINTLNF("languages: %d", language_size);
  PRINTLNF("languages capacity: %d", language_cap);

  for (int i = 0; i < language_size; ++i) {
    PRINTLNF("[%s, %d]", languages[i].name, languages[i].year);
  }

  free(languages);

  return 0;
}
