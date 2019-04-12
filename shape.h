#ifndef SHAPE_H
#define SHAPE_H

//#include <QString>
#include <QPen>
#include <QBrush>
#include <QPaintDevice>
#include <cmath>
#include <cstdlib>

class Shape
{
public:
    enum class ShapeType{NoShape, Line, Polyline, Polygon, Rectangle, Ellipse, Text};

    //Constructors
    Shape(QPaintDevice * device = nullptr, int id = -1, ShapeType shape = ShapeType::NoShape);

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
    void SetBrush(Qt::GlobalColor, Qt::BrushStyle);

    void Default_style();

    virtual void Draw(const int translate_x, const int translate_y) = 0;

protected:
    QPainter& GetQPainter();

private:
    QPainter qpainter();

    int id;
    ShapeType shape;
    QPen pen;
    QBrush brush;
};

#endif // SHAPE_H
