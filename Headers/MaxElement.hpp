//
// Created by davidandw190 on 10/15/23.
//

#pragma once

#include "GlobalConstants.hpp"

#ifndef NEURAL_NETWORK_CPP_MAXELEMENT_H
#define NEURAL_NETWORK_CPP_MAXELEMENT_H

/**
 * Find the maximum element in a one-dimensional vector.
 *
 * @param vector The input vector.
 * @return The maximum element in the vector.
 */
float get_max_element(const vector_1d& vector);

/**
 * Find the maximum element in a two-dimensional vector.
 *
 * @param vector The input vector.
 * @return The maximum element in the vector.
 */
float get_max_element(const vector_2d& vector);

/**
 * Find the maximum element in a three-dimensional vector.
 *
 * @param vector The input vector.
 * @return The maximum element in the vector.
 */
float get_max_element(const vector_3d& vector);

#endif //NEURAL_NETWORK_CPP_MAXELEMENT_H
