#ifndef SHAPE_H
#define SHAPE_H

#include <QString>
#include <QPen>
#include <QBrush>
#include <QPaintDevice>
#include <QPainter>
#include <cmath>
#include <cstdlib>

#include "vector.h"

class Shape
{
public:
    enum ShapeType{NoShape, Line, Polyline, Polygon, Rectangle, Ellipse, Text};

    //Constructors
    Shape(QPaintDevice * device = nullptr, int id = -1, ShapeType shape = NoShape):
        qpainter{device},
        id{id},
        shape{shape},
        pen{Qt::SolidLine},
        brush{Qt::NoBrush}{}

    //Destructors
    virtual ~Shape(){}

    //Getters
    ShapeType GetShape() const      {return shape;}
    int GetId() const               {return id;}
    const QPen & GetPen() const     {return pen;}
    const QBrush & GetBrush() const {return brush;}

    //Setters
    void SetShape(ShapeType shape)              {this->shape = shape;}
    void SetPen(Qt::GlobalColor color, int width, Qt::PenStyle style, Qt::PenCapStyle capStyle,
                Qt::PenJoinStyle penJoinStyle)  {pen=QPen(color, width, style, capStyle, penJoinStyle);}
    void SetPen(Qt::GlobalColor color)          {pen.setColor(color);}
    void SetBrush(Qt::GlobalColor color, Qt::BrushStyle style)
    {
        brush.setColor(color);
        brush.setStyle(style);
    }

    void Default_style()
    {
        pen = Qt::SolidLine;
        brush = Qt::NoBrush;
        qpainter.setPen(pen);
        qpainter.setBrush(brush);
    }

    virtual void Draw(const int translate_x, const int translate_y) = 0;

protected:
    QPainter& GetQPainter(){return qpainter;}

private:
    QPainter qpainter;

    int id;
    ShapeType shape;
    QPen pen;
    QBrush brush;
};

class Line : public Shape
{
public:
    //Constructor
    Line(QPaintDevice * device = nullptr, int id = -1) : Shape(device, id, ShapeType::Line){}
    //Destructor
    ~Line() override{}

    void SetPoints(const QPoint& pointBegin, const QPoint& pointEnd);

    void Draw(const int translate_x = 0, const int translate_y = 0) override;

private:
    QPoint pointBegin;
    QPoint pointEnd;
};

class Polyline : public Shape
{
public:
    //Constructor
    Polyline(QPaintDevice * device = nullptr, int id = -1):
        Shape{device, id, ShapeType::Polyline},
        points{0}{}
    //Destructor
    ~Polyline() override{}

    void SetPoint(const QPoint & point){points.Push(point);}

    void Draw(const int translate_x = 0, const int translate_y = 0) override;

private:
    vector<QPoint> points;
};

class Polygon : public Shape
{
public:
    //Constructor
    Polygon(QPaintDevice * device = nullptr, int id = -1):
        Shape{device, id, ShapeType::Polygon},
        points{0}{}
    //Destructor
    ~Polygon() override{}

    void SetPoint(const QPoint & point){points.append(point);}

    void Draw(const int translate_x = 0, const int translate_y = 0) override;

private:
    QPolygon points;
};

class Rectangle : public Shape
{
public:
    //Constructors
    Rectangle(QPaintDevice * device = nullptr, int id = -1):
        Shape{device, id, ShapeType::Rectangle}{}
    //Destructor
    ~Rectangle() override{}

    bool IsSquare() const {return rect.width() == rect.height();}
    void SetRect(const QRect & rect) {this->rect = rect;}

    void Draw(const int translate_x = 0, const int translate_y = 0) override;

private:
    QRect rect;
};

class Ellipse : public Shape
{
    //Constructors
    Ellipse(QPaintDevice * device = nullptr, int id = -1):
        Shape{device, id, ShapeType::Ellipse}{}
    //Destructor
    ~Ellipse() override{}

    bool IsCircle() const{return rect.width() == rect.height();}
    void SetEllipse(const QRect & rect){this->rect = rect;}

    void Draw(const int translate_x = 0, const int translate_y = 0) override;

private:
    QRect rect;
};

class Text : public Shape
{
    //Constructors
    Text(QPaintDevice * device = nullptr, int id = -1):
        Shape{device, id, ShapeType::Text}{}
    //Destructors
    ~Text() override{}

    void SetText(const QString & text){this->text = text;}

    void Draw(const int translate_x = 0, const int translate_y = 0) override;

private:
    QString text;
};

#endif // SHAPE_H
