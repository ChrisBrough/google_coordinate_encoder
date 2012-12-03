#include "map.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

namespace map {

namespace coordinate {

void encode(float number, char* polyline);

int encode(Coordinate* coordinates, int coordinates_length,
    char* coordinates_encoded, int coordinates_encoded_length)
{
    char buffer[64] = { 0 };

    // encode first position (absolute)

    encode(coordinates[0].latitude, buffer);
    encode(coordinates[0].longitude, buffer);

    if (strlen(coordinates_encoded) + strlen(buffer) < coordinates_encoded_length)
    {
        strcat(coordinates_encoded, buffer);
    }
    else
    {
        return 0;
    }

    for (int i = 1; i < coordinates_length; ++i)
    {
        char buffer[64] = { 0 };

        // encode positions (relative)

        encode(coordinates[i].latitude - coordinates[i - 1].latitude, buffer);
        encode(coordinates[i].longitude - coordinates[i - 1].longitude, buffer);

        const int buffer_length = strlen(buffer);

        for (int k = 0; k < buffer_length; ++k)
        {
            // url encoding

            if ((buffer[k] > 31 && buffer[k] < 48) ||
                (buffer[k] > 57 && buffer[k] < 65) ||
                (buffer[k] > 90 && buffer[k] < 97) ||
                (buffer[k] > 122))
            {
                coordinates_encoded_length -= 2;
            }
        }

        if (strlen(coordinates_encoded) + strlen(buffer) < coordinates_encoded_length)
        {
            strcat(coordinates_encoded, buffer);
        }
        else
        {
            return i;
        }
    }

    return coordinates_length;
}

void encode(float number, char* polyline)
{
    char buffer[32] = { 0 };

    int number5 = (int)(number * 1e5);
    int number_signed = number5 << 1;

    if (number5 < 0)
    {
        number_signed = ~(number_signed);
    }

    while (number_signed >= 0x20)
    {
        sprintf(buffer, "%c", (char)(0x20 | (number_signed & 0x1f)) + 63);
        strcat(polyline, buffer);
        number_signed >>= 5;
    }

    sprintf(buffer, "%c", (char)(number_signed + 63));
    strcat(polyline, buffer);
}

} // namespace coordinate

} // namespace map
