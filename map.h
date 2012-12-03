#ifndef MAP_H
#define MAP_H

#include "map_types.h"

namespace map {

namespace coordinate {

/// @brief encode coordinates and concatenate to URL
/// @param coordinates a pre-allocated array holding a set of coordinates
/// @param coordinates_encoded a pre-allocated array for concatenating the encoded coordinates
/// @return number of encoded coordinates
int encode(Coordinate* coordinates, int coordinates_length,
    char* coordinates_encoded, int coordinates_encoded_length);

} // namespace coordinate

} // namespace map

#endif
