#include <iostream>
#include <type_traits>

using namespace std;


// Notice that these errors happen in order of their declaration:

void first(int arg) {
  static_assert(sizeof(int) == 7, "first");
}

void second() {
  static_assert(sizeof(int) == 7, "second");
}

// But these happen out of order of their declaration,
// because the static_asserts happen at expansion time:

template<typename B>
int outer(int arg) {
  static_assert(sizeof(B*) == 7, "outer");
  return 0;
}

template<typename A>
int inner() {
  static_assert(sizeof(A*) == 7, "inner");
  return 0;
}

// And the order of the errors suggests that
// 'inner' is expanded before 'outer':

int main() {
  return outer<int>(inner<int>());
}
