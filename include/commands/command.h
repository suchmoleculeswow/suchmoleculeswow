#ifndef COMMAND_H
#define COMMAND_H

namespace commands {
template <class C>
struct Command {
  static float invoke(float first, float second) {
    return C::invoke(first, second);
  }

  static float init_value() { return C::init_value(); }
};
}

#endif  // COMMAND_H
