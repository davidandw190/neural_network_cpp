//
// Created by davidandw190 on 10/15/23.
//

#include <algorithm>
#include <cfloat>
#include "Headers/MaxElement.hpp"
#include "Headers/GlobalConstants.hpp"

/**
 * Find the maximum element in a one-dimensional vector.
 *
 * @param vector The input vector.
 * @return The maximum element in the vector.
 */
float get_max_element(const vector_1d& vector) {
    return *std::max_element(vector.begin(), vector.end());
}

/**
 * Find the maximum element in a two-dimensional vector.
 *
 * @param vector The input vector.
 * @return The maximum element in the vector.
 */
float get_max_element(const vector_2d& vector) {
    float output = FLT_MIN;

    for (const vector_1d& a : vector) {
        output = std::max(output, get_max_element(a));
    }

    return output;
}

/**
 * Find the maximum element in a three-dimensional vector.
 *
 * @param vector The input vector.
 * @return The maximum element in the vector.
 */
float get_max_element(const vector_3d& vector) {
    float output = FLT_MIN;

    for (const vector_2d& v : vector) {
        output = std::max(output, get_max_element(v));
    }

    return output;
}
