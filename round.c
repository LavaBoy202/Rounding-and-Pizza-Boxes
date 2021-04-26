#include <assert.h>

int away_div(int num, int denom) {
  assert (denom != 0);
  if (num % denom == 0) {
    return num / denom;
  }
  else if (num < 0 && denom < 0) {
    return (num / denom) + 1;
  }
  else if (num < 0 || denom < 0) {
    return ((num / denom) - 1);
  }
  else {
    return (num / denom) + 1;
  }
}

int round_nice(int num, int denom) {
  assert (denom != 0);
  if (num == 0) {
    return (num / denom);
  }
  else if (num > 0 && denom < 0)  {
    if (((num % denom) * 3) >= denom * -1) {
      return (num / denom) - 1;
    }
    else {
      return (num / denom);
    }
  }
  else if (num < 0 && denom > 0) {
    if (((num % denom) * 3) <= denom * -1) {
      return (num / denom) - 1;
    }
    else {
      return (num / denom);
    }
  }
  else if (num < 0 && denom < 0) {
    if (((num % denom) * 3) <= denom) {
      return (num / denom) + 1;
    }
    else {
      return (num / denom);
    }
  }
  else {
    if (((num % denom) * 3) >= denom) {
      return (num / denom) + 1;
    }
    else {
      return (num / denom);
    }
  }
}

int cookie_box_counter (int min, int choc, int van, int boxes) {
  if (min > 0) {
    return cookie_box_counter (min - 22, choc, van, boxes + 1);
  }
  else if (choc > 0 || van > 0) {
    return cookie_box_counter (min, choc - 10, van - 10, boxes + 1);
  }
  else {
    return boxes;
  }
}

int cookie_order(int mint, int chocolate, int vanilla) {
  assert (mint >= 0);
  assert (chocolate >= 0);
  assert (vanilla >= 0);

  return cookie_box_counter (mint, chocolate, vanilla, 0);
}

int pizza_box_counter (int can, int haw,  int spicy, int vegan,
                       int slices_per_pizza, int box) {
  if (vegan > 0) {
    return pizza_box_counter (can, haw, spicy, vegan - slices_per_pizza,
                              slices_per_pizza, box + 1);
  }
  else if (can > slices_per_pizza / 2) {
    return pizza_box_counter (can - slices_per_pizza,
                              haw, spicy, vegan, slices_per_pizza, box + 1);
  }
  else if (haw > slices_per_pizza / 2) {
    return pizza_box_counter (can, haw - slices_per_pizza,
                              spicy, vegan, slices_per_pizza, box + 1);
  }
  else if (spicy > slices_per_pizza / 2) {
    return pizza_box_counter (can, haw, spicy - slices_per_pizza,
                              vegan, slices_per_pizza, box + 1);
  }
  else {
    if (can > 0) {
      if (haw > 0) {
        return pizza_box_counter (can - (slices_per_pizza / 2),
                                  haw - (slices_per_pizza / 2),
                                  spicy, vegan, slices_per_pizza, box + 1);
      }
      else if (spicy > 0) {
        return pizza_box_counter (can - (slices_per_pizza / 2), haw,
                                  spicy - (slices_per_pizza / 2),
                                  vegan, slices_per_pizza, box + 1);
      }
      else {
        return pizza_box_counter (can - (slices_per_pizza / 2), haw, spicy,
                                  vegan, slices_per_pizza, box + 1);
      }
    }
    else if (haw > 0) {
      if (spicy > 0) {
        return pizza_box_counter (can, haw  - (slices_per_pizza / 2),
                                  spicy - (slices_per_pizza / 2),
                                  vegan, slices_per_pizza, box + 1);
      }
      else {
        return pizza_box_counter (can, haw  - (slices_per_pizza / 2), spicy,
                                  vegan, slices_per_pizza, box + 1);
      }
    }
    else if (spicy > 0) {
      return pizza_box_counter (can, haw, spicy - (slices_per_pizza / 2),
                                vegan, slices_per_pizza, box + 1);
    }
    else {
      return box;
    }
  }
}

int pizza_order(int canadian, int hawaiian, int spicy, int vegan,
                int slices_per_pizza) {
  assert (canadian >= 0);
  assert (hawaiian >= 0);
  assert (spicy >= 0);
  assert (vegan >= 0);
  assert (slices_per_pizza > 0);

  return pizza_box_counter (canadian, hawaiian, spicy, vegan, slices_per_pizza,
                            0);
}

int main(void) {
  assert(away_div(4, 1) == 4);
  assert(away_div(-5, 2) == -3);
  assert(round_nice(4, 1) == 4);
  assert(round_nice(66, 11) == 6);
  assert(round_nice(66, 12) == 6);
  assert(round_nice(0, -2) == 0);
  assert(cookie_order(44, 20, 20) == 4);
  assert(pizza_order(8, 8, 8, 8, 8) == 4);
  assert(pizza_order(0, 1, 3, 9, 8) == 3);
  assert(pizza_order(32, 33, 1, 0, 8) == 9);
  //trace_int(pizza_order (2, 2, 2, 2, 8));
  //trace_int(pizza_order (2, 2, 0, 0, 8));
  // Try some of these tests (copy & paste into your main)

  assert(away_div(4, 1) == 4);
  assert(round_nice(4, 1) == 4);
  assert(cookie_order(44, 20, 20) == 4);
  assert(pizza_order(8, 8, 8, 8, 8) == 4);

  assert(cookie_order(1, 1, 1) == 2);
  assert(cookie_order(22, 10, 10) == 2);
  assert(cookie_order(23, 10, 10) == 3);
  assert(cookie_order(22, 11, 10) == 3);
  assert(cookie_order(22, 10, 11) == 3);
  assert(pizza_order(8, 2, 0, 0, 8) == 2);

  assert(round_nice(11, 6) == 2);
  assert(round_nice(12, 6) == 2);
  assert(round_nice(13, 6) == 2);
  assert(round_nice(14, 6) == 3);
  assert(round_nice(15, 6) == 3);
  assert(round_nice(18, 6) == 3);
  assert(round_nice(19, 6) == 3);
  assert(round_nice(20, 6) == 4);

  assert(round_nice(9, 7) == 1);
  assert(round_nice(10, 7) == 2);
  assert(round_nice(-9, 7) == -1);
  assert(round_nice(-10, 7) == -2);
  assert(round_nice(9, -7) == -1);
  assert(round_nice(10, -7) == -2);
  assert(round_nice(-9, -7) == 1);
  assert(round_nice(-10, -7) == 2);
  assert(round_nice(-5, 2) == -3);

  assert(pizza_order(1,0,0,0,16) == 1);
  assert(pizza_order(1,1,1,1,16) == 3);
  assert(pizza_order(24,24,32,16,16) == 6);
  assert(pizza_order(25,25,33,17,16) == 9);

}
