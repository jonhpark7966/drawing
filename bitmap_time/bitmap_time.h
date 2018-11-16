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


    SkBitmap makeXTSlice(const unsigned int y);
    SkBitmap makeYTSlice(const unsigned int x);

private:
  unsigned int getPixel(const unsigned int x, const unsigned int y, const unsigned int t);

  unsigned int* _data;
  //time is number of frame
  unsigned int _width, _height, _time;


};

#endif
