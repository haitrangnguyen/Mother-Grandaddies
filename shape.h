#ifndef SHAPE_H
#define SHAPE_H

//#include <QString>
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
    enum class ShapeType{NoShape, Line, Polyline, Polygon, Rectangle, Ellipse, Text};

    //Constructors
    Shape(QPaintDevice * device = nullptr, int id = -1, ShapeType shape = ShapeType::NoShape):
        qpainter{device},
        id{id},
        shape{shape}{}

    //Destructors
    virtual ~Shape(){}

    //Getters
    ShapeType GetShape() const {return shape;}
    int GetId() const {return id;}
    QPen GetPen() const {return pen;}
    QBrush GetBrush() const {return brush;}

    //Setters
    void SetShape(ShapeType shape){this->shape = shape;}
    void SetPen(Qt::GlobalColor color, int width, Qt::PenStyle style, Qt::PenCapStyle capStyle,
                Qt::PenJoinStyle penJoinStyle){this->pen=QPen(color, width, style, capStyle, penJoinStyle);}
    void SetPen(Qt::GlobalColor color){pen.setColor(color);}
    void SetBrush(Qt::GlobalColor color, Qt::BrushStyle style)
    {
        brush.setColor(color);
        brush.setStyle(style);
    }

    void Default_style()
    {
        this->pen=QPen();
        this->brush=QBrush();
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

    void SetPoint(const QPoint & point);

private:
    vector<QPoint> points;
};

class Polygon : Shape
{
public:
    //Constructor
    Polygon(QPaintDevice * device = nullptr, int id = -1):
        Shape{device, id, ShapeType::Polygon},
        points{0}{}
    //Destructor
    ~Polygon() override{}

    void SetPoint(const QPoint & point);

    void Draw(const int translate_x = 0, const int translate_y = 0) override;

private:
    vector<QPoint> points;
};

class Rectangle : public Shape
{
public:
    //Constructors
    Rectangle(QPaintDevice * device = nullptr, int id = -1):
        Shape{device, id, ShapeType::Rectangle}{}
    //Destructor
    ~Rectangle() override{}

    bool isSquare() const {return rect.width() == rect.height();}
    void SetRect(const QRect & rect) {this->rect = rect;}

    void Draw(const int translate_x = 0, const int translate_y = 0) override;

private:
    QRect rect;
};

#endif // SHAPE_H
