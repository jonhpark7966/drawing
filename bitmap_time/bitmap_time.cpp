#include "bitmap_time.h"
#include "../utils/image_reader.h"

#include "SkBitmap.h"
#include "SkImageInfo.h"

#include <cstring>
#include <cassert>


BitmapTime::BitmapTime(const char file_path[]){

  sk_sp<SkAnimatedImage> images = decode_file(file_path);

  if(images==nullptr){
    assert(0);
  }

  _time = images->fFrameCount;
  _width = images->fDisplayFrame.fBitmap.width();
  _height = images->fDisplayFrame.fBitmap.height();
 
  _data = new unsigned int[_width*_height*_time];

  for(unsigned int f = 0; f < _time; f++){
    memcpy((void*)(_data + _width*_height*f), images->fDisplayFrame.fBitmap.getPixels(), 4*_width*_height);
  }

}


BitmapTime::~BitmapTime(){
  if(_data)
    delete[] _data;
}

unsigned int BitmapTime::get(const unsigned int x, const unsigned int y, const unsigned int t){
  return *(_data + x + _width*y + _width*_height+t);
}

SkBitmap BitmapTime::makeBitmap(){

  //FIXME: for now make bitmap of y = 0;
  SkBitmap ret;
  //assume bitmap is BGRA 
  SkImageInfo info = SkImageInfo::MakeN32Premul(_width, _time);

  void* pixels = malloc(_width*_time*4);

  for(unsigned int j = 0; j < _time; ++j){
    for(unsigned int i = 0; i < _width; ++i){
    
      *(((unsigned int*)pixels) + i + j*_width) = get(i, 0, j);
    }
  }

  ret.installPixels(info, pixels, _width*4);

  return ret;
}
