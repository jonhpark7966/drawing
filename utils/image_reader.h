/*
 *
*/

#ifndef IMAGE_READER_DEFINED
#define IMAGE_READER_DEFINED

#include "SkAndroidCodec.h"
#include "SkAnimatedImage.h"
#include "SkAnimTimer.h"
#include "SkCanvas.h"
#include "SkPaint.h"
#include "SkPictureRecorder.h"
#include "SkRect.h"
#include "SkScalar.h"
#include "SkString.h"




static inline sk_sp<SkAnimatedImage> decode_file(const char filename[]) {

      sk_sp<SkData> file( SkData::MakeFromFileName(filename));
      std::unique_ptr<SkCodec> codec(SkCodec::MakeFromData(file));
      if (!codec) {
        //assert(0);
      }

      sk_sp<SkAnimatedImage> Image = SkAnimatedImage::Make(SkAndroidCodec::MakeFromCodec(std::move(codec)));
      if (!Image) {
        //assert(0);
      }

      return Image;
}










#endif
