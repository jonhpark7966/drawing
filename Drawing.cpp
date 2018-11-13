/*
* Copyright 2017 Google Inc.
*
* Use of this source code is governed by a BSD-style license that can be
* found in the LICENSE file.
*/

#include "Drawing.h"

#include "utils/image_reader.h"

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

    sk_sp<SkAnimatedImage> images = decode_file("/home/jonhpark/workspace/skia/resources/images/alphabetAnim.gif");

    images->draw(canvas,0,0);
    images->decodeNextFrame();
    images->draw(canvas,20,20);
    images->decodeNextFrame();
    images->draw(canvas,40,40);

}

void Drawing::onIdle() {
    // Just re-paint continously
    fWindow->inval();
}

