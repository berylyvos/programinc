#include <string.h>
#include "console_ui.h"
#include "unit_test.h"
#include "gtk_ui.h"

int main(int argc, char **argv) {

  if (argc > 1) {
    if (strcasecmp(argv[1], "console") == 0) {
      return RunConsoleUI(argc, argv);
    } else if (strcasecmp(argv[1], "unittest") == 0) {
      return RunUnitTest(argc, argv);
    }
  }

  return RunGtkUi(argc, argv);
}
