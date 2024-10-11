/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vector_maths.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:57:14 by llacsivy          #+#    #+#             */
/*   Updated: 2024/10/11 12:03:58 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>
#include <math.h>

#include "../includes/maths.h"

// Helper function to compare t_tuple structs for equality
int tuples_are_equal(t_tuple a, t_tuple b) {
    return (a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w);
}

// Test for tuple_add
void test_tuple_add() {
    t_tuple a = {1, 2, 3, 0};
    t_tuple b = {4, 5, 6, 0};
    t_tuple expected = {5, 7, 9, 0};
    t_tuple result = tuple_add(a, b);
    
    assert(tuples_are_equal(result, expected) && "test_tuple_add failed");
    printf("test_tuple_add passed\n");
}

// Test for tuple_neg
void test_tuple_neg() {
    t_tuple a = {1, -2, 3, 0};
    t_tuple expected = {-1, 2, -3, 0};
    t_tuple result = tuple_neg(a);
    
    assert(tuples_are_equal(result, expected) && "test_tuple_neg failed");
    printf("test_tuple_neg passed\n");
}

// Test for tuple_subtr
void test_tuple_subtr() {
    t_tuple a = {5, 7, 9, 0};
    t_tuple b = {1, 2, 3, 0};
    t_tuple expected = {4, 5, 6, 0};
    t_tuple result = tuple_subtr(a, b);
    
    assert(tuples_are_equal(result, expected) && "test_tuple_subtr failed");
    printf("test_tuple_subtr passed\n");
}

// Test for tuple_scale
void test_tuple_scale() {
    t_tuple a = {1, 2, 3, 0};
    float k = 2.0;
    t_tuple expected = {2, 4, 6, 0};
    t_tuple result = tuple_scale(k, a);
    
    assert(tuples_are_equal(result, expected) && "test_tuple_scale failed");
    printf("test_tuple_scale passed\n");
}

// Test for tuple_magni
void test_tuple_magni() {
    t_tuple a = {1, 2, 2, 0};  // Magnitude should be sqrt(1^2 + 2^2 + 2^2) = 3
    float expected = 3.0;
    float result = tuple_magni(a);
    
    assert(result == expected && "test_tuple_magni failed");
    printf("test_tuple_magni passed\n");
}

// Test for tuple_normalize
void test_tuple_normalize() {
    t_tuple a = {4, 0, 0, 0};  // Normalized version should be {1, 0, 0, 0}
    t_tuple expected = {1, 0, 0, 0};
    t_tuple result = tuple_normalize(a);
    
    assert(tuples_are_equal(result, expected) && "test_tuple_normalize failed");
    printf("test_tuple_normalize passed\n");
}

// Test for distance
void test_distance() {
    t_tuple a = {1, 2, 3, 0};
    t_tuple b = {4, 6, 8, 0};
    float expected = 7.071068;  // distance formula sqrt((4-1)^2 + (6-2)^2 + (8-3)^2)
    float result = distance(a, b);
    
    assert(fabs(result - expected) < 0.0001 && "test_distance failed");
    printf("test_distance passed\n");
}

// Test for direction
void test_direction() {
    t_tuple a = {1, 2, 3, 0};
    t_tuple b = {4, 5, 6, 0};
    t_tuple expected = {3, 3, 3, 0};  // b - a = (4-1, 5-2, 6-3)
    t_tuple result = direction(a, b);
    
    assert(tuples_are_equal(result, expected) && "test_direction failed");
    printf("test_direction passed\n");
}

// Test for tuple_dot
void test_tuple_dot() {
    t_tuple a = {1, 2, 3, 0};
    t_tuple b = {4, 5, 6, 0};
    float expected = 32;  // Dot product = 1*4 + 2*5 + 3*6
    float result = tuple_dot(a, b);
    
    assert(result == expected && "test_tuple_dot failed");
    printf("test_tuple_dot passed\n");
}

// Test for tuple_cross
void test_tuple_cross() {
    t_tuple a = {1, 0, 0, 0};
    t_tuple b = {0, 1, 0, 0};
    t_tuple expected = {0, 0, 1, 0};  // Cross product of two perpendicular vectors
    t_tuple result = tuple_cross(a, b);
    
    assert(tuples_are_equal(result, expected) && "test_tuple_cross failed");
    printf("test_tuple_cross passed\n");
}

int main() {
    test_tuple_add();
    test_tuple_neg();
    test_tuple_subtr();
    test_tuple_scale();
    test_tuple_magni();
    test_tuple_normalize();
    test_distance();
    test_direction();
    test_tuple_dot();
    test_tuple_cross();

    printf("All tests passed!\n");
    return 0;
}
