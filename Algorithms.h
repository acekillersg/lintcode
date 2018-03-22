//
// Created by john on 22/3/18.
//

#ifndef LINTCODE_ALGORITHMS_H
#define LINTCODE_ALGORITHMS_H

class Adder {
public:
    int add(int a, int b);
};

/**
 * add two numbers a and b without '+'
 * @param a
 * @param b
 * @return
 */
int Adder::add(int a, int b) {
    int reserve = a ^ b;
    int carry = (a & b) << 1;
    if (carry == 0)
        return reserve;
    else
        return add(carry, reserve);
}
#endif //LINTCODE_ALGORITHMS_H
