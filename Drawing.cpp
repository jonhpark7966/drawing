/*
* Copyright 2017 Google Inc.
*
* Use of this source code is governed by a BSD-style license that can be
* found in the LICENSE file.
*/

#include "Drawing.h"

#include "GrContext.h"
#include "SkCanvas.h"
#include "SkGradientShader.h"
#include "SkGraphics.h"

using namespace sk_app;

Application* Application::Create(int argc, char** argv, void* platformData) {
    return new Drawing(argc, argv, platformData);
}

Drawing::Drawing(int argc, char** argv, void* platformData)
        : fBackendType(Window::kNativeGL_BackendType)
        , fRotationAngle(0) {
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

    SkPaint paint;
    paint.setColor(SK_ColorRED);

    // Draw a rectangle with red paint
    SkRect rect = SkRect::MakeXYWH(10, 10, 128, 128);
    canvas->drawRect(rect, paint);

}

void Drawing::onIdle() {
    // Just re-paint continously
    fWindow->inval();
}

