#include <commands/command.h>

namespace commands {
/*!
    \class Add
    \brief Add command for a reduce-like worker.
*/
struct Add : public Command<Add> {
  static float invoke(float first, float second) { return first + second; }

  static float init_value() { return 0.0f; }
};
}
