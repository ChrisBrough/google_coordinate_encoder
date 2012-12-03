# Google Coordinate Encoder

This a C++ implementation of Google's Polyline Algorithm Format. It takes
takes floating point latitude and longitude positions and encodes them for a
query to one of Google's APIs. I made use of the encoding in my [Heightmaps
with Google Elevations](http://chrisbrough.com/project/2012/11/Heightmaps-with-Google-Elevations/) project.

## Usage

Include the header/source files or compile it to a library. Then create an
array of coordinates and pass it into the `encode` function with an encoding
result array with a max length of 2048 (URL character limit).
