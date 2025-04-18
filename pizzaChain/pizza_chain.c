#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
/*
The main challenge was to recognize how to not scroll all the characters inside
the loop that evaluate the presence of a pizza place. To increase the
performance I created two variables,  west and east. In the variable east, there
is the limit that the loop should arrive and in the west, the starting search of
the position contains a pizza as many pizza places. Further, the memePizza
variable counts when there is a match with value one ( reference of pizza place)
and the position.
*/

bool constraint_n(int n) {

  bool evaluaton = false;
  if (n < 1 || n > 100000)
    evaluaton = true;
  return evaluaton;
}

bool constraint_m_r(int m, int r) {

  bool evaluaton = false;
  if (m < 1 || r < 1)
    evaluaton = true;
  return evaluaton;
}

int set_position_est_west(int h, int r, int n, int verify) {
  int position = 0;
  // O IS EST 1 IS WEST
  if (verify == 0) {
    position = (h - 1) + r;
    if (position > n) {
      position = n - 1;
    }
  }
  if (verify == 1) {
    position = (h - 1) - r;
    if (position < 0) {
      position = 0;
    }
  }
  return position;
}

int evaluation_position(int westPositon, int estPosition, char *character) {
  int numberPizza = 0;
  // https://cplusplus.com/reference/cstring/memmove/
  // IT BEGIN FROM THE POSITION
  for (int nn = westPositon; nn <= estPosition; nn++) {
    if (character[nn] == 49) {
      numberPizza++;
    }
  }
  return numberPizza;
}

int recoverInput() {
  int memePizza = 0;
  int n = 0;
  int m = 0;
  int r = 0;
  scanf("%d %d %d", &n, &m, &r);
  if (constraint_n(n) || constraint_m_r(m, r)) {
    return 0;
  }
  char *character = malloc(sizeof(char) * (n + 1));
  scanf("%s", character);
  int h;
  for (int i = 0; i < m; i++) {
    scanf("%d", &h); // **Reads multiple values in the same line**
    int west_location = set_position_est_west(h, r, n, 1);
    int east_location = set_position_est_west(h, r, n, 0);

    // https://cplusplus.com/reference/cstring/memmove/
    // IT BEGIN FROM THE POSITION
    int numberPizza =
        evaluation_position(west_location, east_location, character);
    if (numberPizza > memePizza) {
      memePizza = numberPizza;
    }
  }
  free(character);

  return memePizza;
}

int main() {
  int number = recoverInput();
  printf("%d\n", number);
}
