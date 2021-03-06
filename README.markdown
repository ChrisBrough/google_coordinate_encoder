# Google Coordinate Encoder

This a C++ implementation of Google's Polyline Algorithm Format. It takes
takes floating point latitude and longitude positions and encodes them for a
query to one of Google's APIs. I made use of the encoding in my [Heightmaps
with Google Elevations](http://chrisbrough.com/project/2012/11/Heightmaps-with-Google-Elevations/) project.

## Usage

Include the header/source files or compile it to a library. Then create an
array of coordinates and pass it into the `encode` function with an encoding
result array with a max length of 2048 (URL character limit). Before passing in
coordinates to be encoded, you should either clamp or wrap the numbers within
the bounds of latitude and longitude; anything out of bounds will result in an
`INVALID_REQUEST` when querying Google.

    coordinates[500] : Coordinate
    coordinates_encoded[2048] : char
    coordinates_encoded_count : int

    coordinates_encoded_count = encode(coordinates, 500, coordinates_encoded, 2048);

See `test.cpp` for complete example. Once you have the encoded coordinates
appended to the Google API query URL, a request can be made, and the data can
be processed.
