#include <commands/command.h>

namespace commands {

struct Add {
  static float invoke(float first, float second) { return first + second; }

  static float init_value() { return 0.0f; }
};
}
