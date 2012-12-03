#include "map_types.h"
#include "map.h"

#include <stdio.h>

int main(int argc, char* argv[])
{
    char coordinates_encoded[2048] = "https://maps.googleapis.com/maps/api/"
        "elevation/json?sensor=false&locations=enc:";

    const int coordinates_count = 500;
    map::Coordinate coordinates[coordinates_count] = { };

    coordinates[0].latitude = 38;
    coordinates[0].longitude = 50;

    for (int i = 1; i < coordinates_count; ++i)
    {
        coordinates[i].latitude = coordinates[i - 1].latitude + 0.1f;
        coordinates[i].longitude = coordinates[i - 1].longitude + 0.1f;
    }

    int coordinates_encoded_count = map::coordinate::encode(coordinates,
        coordinates_count, coordinates_encoded, 2048);

    // note: if encoded coordinates exceed URL length, you must construct multiple URLs

    fprintf(stdout, "Encoded URL: %s\nEncoded Coordinates: %i\n",
        coordinates_encoded, coordinates_encoded_count);

    return 0;
}
