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
