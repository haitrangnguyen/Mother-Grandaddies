#ifndef SHAPE_H
#define SHAPE_H

#include <qstring.h>

class Shape
{
public:
    //Constructors
    Shape():
        id{""},
        penColor{""},
        penWidth{""},
        penStyle{""},
        penCapStyle{""},
        penJoinStyle{""},
        brushColor{""},
        brushStyle{""}{}
    Shape(QString id, QString penColor, QString penWidth, QString penStyle, QString penCapStyle, QString penJoinStyle,
          QString brushColor, QString brushStyle):
        id{id},
        penColor{penColor},
        penWidth{penWidth},
        penStyle{penStyle},
        penCapStyle{penCapStyle},
        penJoinStyle{penJoinStyle},
        brushColor{brushColor},
        brushStyle{brushStyle}{}

    //Destructors
    virtual ~Shape();

    //virtual functions
    virtual void draw() = 0;
    virtual void move() = 0;
    virtual void perimeter() = 0;
    virtual void area() = 0;

    //Getters
    QString getId() const {return id;}
    QString getPenColor() const {return penColor;}
    QString getPenWidth() const {return penWidth;}
    QString getPenStyle() const {return penStyle;}
    QString getPenCapStyle() const {return penCapStyle;}
    QString getPenJoinStyle() const {return penJoinStyle;}
    QString getBrushColor() const {return brushColor;}
    QString getBrushStyle() const {return brushStyle;}

    //Setters
    void setId(QString id) {this->id=id;}
    void setPenColor(QString penColor) {this->penColor = penColor;}
    void setPenWidth(QString penWidth) {this->penWidth = penWidth;}
    void setPenStyle(QString penStyle) {this->penStyle = penStyle;}
    void setPenCapStyle(QString penCapStyle) {this->penCapStyle = penCapStyle;}
    void setPenJoinStyle(QString penJoinStyle) {this->penJoinStyle = penJoinStyle;}
    void setBrushColor(QString brushColor) {this->brushColor = brushColor;}
    void setBrushStyle(QString brushStyle) {this->brushStyle = brushStyle;}

private:
    QString id;
    QString penColor;
    QString penWidth;
    QString penStyle;
    QString penCapStyle;
    QString penJoinStyle;
    QString brushColor;
    QString brushStyle;

};

#endif // SHAPE_H
