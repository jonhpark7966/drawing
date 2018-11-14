/*
*/

#ifndef BITMAP_TIME_DEFINED
#define BITMAP_TIME_DEFINED

class SkBitmap;

// for x, y, t 3D data. array of bitmap.
class BitmapTime {
public:
    BitmapTime(const char file_path[]);
    ~BitmapTime();

    unsigned int get(const unsigned int x, const unsigned int y, const unsigned int t);

    SkBitmap makeBitmap();

private:
  unsigned int* _data;
  //time is number of frame
  unsigned int _width, _height, _time;
};

#endif
