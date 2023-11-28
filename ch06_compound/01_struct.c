#include <stdio.h>
#include <io_utils.h>

int main() {

  typedef struct Company {
    char *name;
    char *id;
    char *location;
  } Company;

  typedef struct Person {
    char *name;
    int age;
    char *id;
    Company *company;
    Company company2;
    struct {
      int extra;
      char *extra_str;
    } extra_value;
    struct Person *partner;
  } Person;

  Company company = {.name = "Google", .id = "1212121"};
  Person person = {.name = "shingo", .id = "123456789", .company = &company,
      .company2 = {.name = "Huawei", .id = "114514"}, .extra_value = {.extra = 21, .extra_str = ""}
  };

  PRINT_INT(person.age);
  person.age = 30;

  //person.company->name
  //person.extra_value.extra

  PRINT_HEX(&person);

  Person *person_ptr = &person;

  puts(person_ptr->name);

  PRINT_INT((int)sizeof(Person));
  PRINT_INT((int)sizeof(person));

  struct {
    char *name;
    int age;
    char *id;
  } anonymous_person;

  Person person1 = {.name = "andy", .age = 20};
  PRINT_INT(person1.age);

  return 0;
}
