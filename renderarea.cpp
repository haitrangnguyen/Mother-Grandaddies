/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "renderarea.h"

#include <QPainter>

//! [0]
RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent), shapes(10)
{
    antialiased = false;
    transformed = false;
    pixmap.load(":/images/qt-logo.png");

    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}
//! [0]

//! [1]
QSize RenderArea::minimumSizeHint() const
{
    return QSize(100, 100);
}
//! [1]

//! [2]
QSize RenderArea::sizeHint() const
{
    return QSize(400, 200);
}
//! [2]

//! [3]
void RenderArea::setShape(const Shape::ShapeType & shape)
{
    update();
}
//! [3]

//! [4]
void RenderArea::setPen(const QPen &pen)
{
    this->pen = pen;
    update();
}
//! [4]

//! [5]
void RenderArea::setBrush(const QBrush &brush)
{
    update();
}
//! [5]

//! [6]
void RenderArea::setAntialiased(bool antialiased)
{
    this->antialiased = antialiased;
    update();
}
//! [6]

//! [7]
void RenderArea::setTransformed(bool transformed)
{
    this->transformed = transformed;
    update();
}
//! [7]

//! [8]
void RenderArea::paintEvent(QPaintEvent * /* event */)
{
    for(int x = 0; x < 1000; x += 25)
    {
        for(int y = 0; y < 1000; y += 25)
        {
            QPainter(this).drawPoint(x, y);
        }
    }

    Line line(this);

    line.SetPoints(QPoint(20, 50), QPoint(100, 20));

    line.SetPen(Qt::blue, 2, Qt::DashDotLine, Qt::FlatCap, Qt::MiterJoin);

    line.Draw();

    line.Default_style();
    QPainter(this).drawRect(QRect(0, 0, width() - 1, height() - 1));

    Polyline polyline(this);

    polyline.SetPoint(QPoint(300, 100));
    polyline.SetPoint(QPoint(350, 20));
    polyline.SetPoint(QPoint(400, 40));
    polyline.SetPoint(QPoint(450, 80));
    polyline.SetPoint(QPoint(500, 500));

    polyline.SetPen(Qt::green, 6, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin);

    polyline.Draw();

    Polygon polygon(this);

    polygon.SetPoint(QPoint(10, 200));
    polygon.SetPoint(QPoint(20, 300));
    polygon.SetPoint(QPoint(30, 200));
    polygon.SetPoint(QPoint(80, 500));

    polygon.SetPen(Qt::black, 6, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin);

    polygon.Draw();
}
//! [13]
