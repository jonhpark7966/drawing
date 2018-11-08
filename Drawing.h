/*
* Copyright 2017 Google Inc.
*
* Use of this source code is governed by a BSD-style license that can be
* found in the LICENSE file.
*/

#ifndef Drawing_DEFINED
#define Drawing_DEFINED

#include "sk_app/Application.h"
#include "sk_app/Window.h"

class SkCanvas;

class Drawing : public sk_app::Application, sk_app::Window::Layer {
public:
    Drawing(int argc, char** argv, void* platformData);
    ~Drawing() override;

    void onIdle() override;

    void onBackendCreated() override;
    void onPaint(SkCanvas* canvas) override;

private:

    sk_app::Window* fWindow;
    sk_app::Window::BackendType fBackendType;
};

#endif
