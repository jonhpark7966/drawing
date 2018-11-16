/*
* Copyright 2017 Google Inc.
*
* Use of this source code is governed by a BSD-style license that can be
* found in the LICENSE file.
*/

#include "Drawing.h"

#include "utils/image_reader.h"
#include "bitmap_time/bitmap_time.h"

#include "GrContext.h"
#include "SkCanvas.h"
#include "SkGradientShader.h"
#include "SkGraphics.h"

using namespace sk_app;

Application* Application::Create(int argc, char** argv, void* platformData) {
    return new Drawing(argc, argv, platformData);
}

Drawing::Drawing(int argc, char** argv, void* platformData)
        : fBackendType(Window::kNativeGL_BackendType)   {
    SkGraphics::Init();

    fWindow = Window::CreateNativeWindow(platformData);
    fWindow->setRequestedDisplayParams(DisplayParams());

    // register callbacks
    fWindow->pushLayer(this);

    fWindow->attach(fBackendType);
}

Drawing::~Drawing() {
    fWindow->detach();
    delete fWindow;
}

void Drawing::onBackendCreated() {
    fWindow->show();
    fWindow->inval();
}

void Drawing::onPaint(SkCanvas* canvas) {
    // Clear background
    canvas->clear(SK_ColorWHITE);
    
    BitmapTime bmtm("/home/jonhpark/Downloads/colorloop.gif");

    canvas->drawBitmap(bmtm.makeXTSlice(325), 0,0);

    canvas->drawBitmap(bmtm.makeYTSlice(325), 800,0);


}

void Drawing::onIdle() {
    // Just re-paint continously
    fWindow->inval();
}

