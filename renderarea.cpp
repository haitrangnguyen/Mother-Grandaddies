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
void RenderArea::setShape(int n, const Shape & shape)
{
    *(shapes[n]) = shape;
    update();
}
//! [3]

//! [4]
void RenderArea::setPen(int n, const QPen &pen)
{
    shapes[n]->setPen(pen);
    this->pen = pen;
    update();
}
//! [4]

//! [5]
void RenderArea::setBrush(int n, const QBrush &brush)
{
    shapes[n]->setBrush(brush);
    update();
}
//! [5]

//! [6]
void RenderArea::setAntialiased(int n, bool antialiased)
{
    //shapes[n];
    this->antialiased = antialiased;
    update();
}
//! [6]

//! [7]
void RenderArea::setTransformed(int n, bool transformed)
{
    //shapes[n];
    this->transformed = transformed;
    update();
}
//! [7]

//! [8]
void RenderArea::paintEvent(QPaintEvent * /* event */)
{
    static const QPoint points[4] = {
        QPoint(10, 80),
        QPoint(20, 10),
        QPoint(80, 30),
        QPoint(90, 70)
    };

    QRect rect(10, 20, 80, 60);

    QPainterPath path;
    path.moveTo(20, 80);
    path.lineTo(20, 30);
    path.cubicTo(80, 0, 50, 50, 80, 80);

    int startAngle = 20 * 16;
    int arcLength = 120 * 16;
//! [8]

//! [9]
    QPainter painter(this);
    painter.setPen(pen);
    painter.setBrush(brush);
    if (antialiased)
        painter.setRenderHint(QPainter::Antialiasing, true);
//! [9]

//! [10]
    int x = 0, y = 0;
    for (int i = 0; i < shapes.size(); i++) {
        painter.save();
        painter.translate(x, y);
//! [10] //! [11]
        if (transformed) {
            painter.translate(50, 50);
            painter.rotate(60.0);
            painter.scale(0.6, 0.9);
            painter.translate(-50, -50);
        }
//! [11]

//! [12]
        QString shapeType = shapes[i]->getShapeType();
        if(shapeType == "Line")
            painter.drawLine(rect.bottomLeft(), rect.topRight());
        else if (shapeType == "Polyline")
            painter.drawPolyline(points, 4);
        else if(shapeType == "Polygon")
            painter.drawPolygon(points, 4);
        else if(shapeType == "Rectangle")
            painter.drawRect(rect);
        else if(shapeType == "Square")
            painter.drawRect(rect);
        else if(shapeType ==  "Ellipse")
            painter.drawEllipse(rect);
        else if(shapeType == "Circle")
            painter.drawArc(rect, startAngle, arcLength);
        else if(shapeType ==  "Text")
            painter.drawText(rect,
                             Qt::AlignCenter,
                             tr("Qt by\nThe Qt Company"));
        else
            "something went completely wrong";
        }
//! [12] //! [13]
        painter.restore();
    }

    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setPen(palette().dark().color());
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(QRect(0, 0, width() - 1, height() - 1));

    x += 100;
    y += 100;
}
//! [13]