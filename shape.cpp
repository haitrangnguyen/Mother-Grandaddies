#include "shape.h"

//Class Line
void Line::SetPoints(const QPoint & point1, const QPoint & point2)
{
    pointBegin = point1;
    pointEnd = point2;
}

void Line::Draw(const int translate_x, const int translate_y)
{
    QPainter & PAINT = GetQPainter();
    PAINT.setPen(GetPen());
    PAINT.setBrush(GetBrush());

    PAINT.save();
    PAINT.translate(translate_x, translate_y);

    PAINT.drawLine(pointBegin, pointEnd);

    PAINT.restore();
}
//End Class line

//Class Polyline
double Polyline::GetPerimeter() const
{
    double length = 0;
    for(int i = 0; i < points.Size() - 1; i++)
    {
        length += (this->points[i] - this->points[i + 1]).manhattanLength();
    }
    return length;
}

void Polyline::Draw(const int translate_x, const int translate_y)
{
    QPainter & PAINT = GetQPainter();
    PAINT.setPen(GetPen());
    PAINT.setBrush(GetBrush());

    PAINT.save();
    PAINT.translate(translate_x, translate_y);

    PAINT.drawPolyline(&points[0], points.Size());

    PAINT.restore();
}
//End Class Polyline

//Class Polygon
double Polygon::GetArea() const
{
    double area = 0;
    int j = points.size() - 1;

    for(int i = 0; i < points.size(); i++)
    {
        area += (points[j].x() + points[i].x()) * (points[j].y() + points[i].y());
    }
}

double Polygon::GetPerimeter() const
{
    double length = 0;
    int i;
    for(i = 0; i < points.size() - 1; i++)
    {
        length += (points[i] - points[i+1]).manhattanLength();
    }
    length += (points[i+1] - points[0]).manhattanLength();
    return length;
}

void Polygon::Draw(const int translate_x, const int translate_y)
{
    QPainter & PAINT = GetQPainter();
    PAINT.setPen(GetPen());
    PAINT.setBrush(GetBrush());

    PAINT.save();
    PAINT.translate(translate_x, translate_y);

    PAINT.drawPolygon(points);

    PAINT.restore();
}
//End Class Polygon

//Class Rectangle
void Rectangle::Draw(const int translate_x, const int translate_y)
{
    QPainter & PAINT = GetQPainter();
    PAINT.setPen(GetPen());
    PAINT.setBrush(GetBrush());

    PAINT.save();
    PAINT.translate(translate_x, translate_y);

    PAINT.drawRect(rect);

    PAINT.restore();
}
//End Class Rectangle

//Class Ellipse
double Ellipse::GetPerimeter() const
{
    double a = rect.width(), b = rect.height();
    double rad = sqrt(-3 * pow(a - b, 2) / pow(a + b, 2) + 4);
    double divisor = pow(a + b, 2) * (rad + 10);
    return PI * (a + b) * (3 * pow(a - b, 2) / divisor + 1);
}

void Ellipse::Draw(const int translate_x, const int translate_y)
{
    QPainter & PAINT = GetQPainter();
    PAINT.setPen(GetPen());
    PAINT.setBrush(GetBrush());

    PAINT.save();
    PAINT.translate(translate_x, translate_y);

    PAINT.drawEllipse(rect);

    PAINT.restore();
}
//End Class Ellipse

//Class Text
void Text::Draw(const int translate_x, const int translate_y)
{
    QPainter & PAINT = GetQPainter();
    PAINT.setPen(GetPen());
    PAINT.setBrush(GetBrush());

    PAINT.save();
    PAINT.translate(translate_x, translate_y);

    PAINT.drawText(translate_x, translate_y, text);

    PAINT.restore();
}
