#ifndef SHAPE_H
#define SHAPE_H

//#include <QString>
#include <QPen>
#include <QBrush>
#include <cmath>
#include <cstdlib>

class Shape
{
public:
    //Constructors
    Shape():
        id{0},
//        penColor{""},
//        penWidth{""},
//        penStyle{""},
//        penCapStyle{""},
//        penJoinStyle{""},
//        brushColor{""},
//        brushStyle{""},
//        shapeType{""},
        pen{QPen()},
        brush{QBrush()},
        dimensions{nullptr},
        numDimensions{0}{}
    Shape(int id, /*const QString & penColor, const QString & penWidth, const QString & penStyle, const QString & penCapStyle, const QString & penJoinStyle, const QString & brushColor, const QString & brushStyle, const QString & shapeType, */
          const QPen & pen, const QBrush & brush):
        id{id},
//        penColor{penColor},
//        penWidth{penWidth},
//        penStyle{penStyle},
//        penCapStyle{penCapStyle},
//        penJoinStyle{penJoinStyle},
//        brushColor{brushColor},
//        brushStyle{brushStyle},
//        shapeType{shapeType},
        pen{pen},
        brush{brush},
        numDimensions{0},
        dimensions{nullptr}{}
    Shape(int id, const QPen & pen, const QBrush & brush, int numDimensions, int * dimensions):
        id{id},
        pen{pen},
        brush{brush},
        numDimensions{numDimensions},
        dimensions{dimensions}{}

    //Destructors
    virtual ~Shape() {delete [] dimensions;}

    //virtual functions
//    virtual void draw() = 0;
//    virtual void move() = 0;
    virtual double perimeter() = 0;
    virtual double area() = 0;

    //Getters
    int getId() const {return id;}
//    QString getPenColor() const {return penColor;}
//    QString getPenWidth() const {return penWidth;}
//    QString getPenStyle() const {return penStyle;}
//    QString getPenCapStyle() const {return penCapStyle;}
//    QString getPenJoinStyle() const {return penJoinStyle;}
//    QString getBrushColor() const {return brushColor;}
//    QString getBrushStyle() const {return brushStyle;}
//    QString getShapeType() const {return shapeType;}
    QPen getPen() const {return pen;}
    QBrush getBrush() const {return brush;}
    int * getDimensions() const {return dimensions;}
    unsigned int getNumDimensions() const{return numDimensions;}

    //Setters
//    void setId(int id) {this->id=id;}
//    void setPenColor(const QString & penColor) {this->penColor = penColor;}
//    void setPenWidth(const QString & penWidth) {this->penWidth = penWidth;}
//    void setPenStyle(const QString & penStyle) {this->penStyle = penStyle;}
//    void setPenCapStyle(const QString & penCapStyle) {this->penCapStyle = penCapStyle;}
//    void setPenJoinStyle(const QString & penJoinStyle) {this->penJoinStyle = penJoinStyle;}
//    void setBrushColor(const QString & brushColor) {this->brushColor = brushColor;}
//    void setBrushStyle(const QString & brushStyle) {this->brushStyle = brushStyle;}
//    void setShapeType(const QString & shapeType) {this->shapeType = shapeType;}
    void setPen(const QPen & pen) {this->pen = pen;}
    void setBrush(const QBrush & brush){this->brush = brush;}
    void setDimensions(int * dimensions)
    {
        delete this->dimensions;
        this->dimensions = dimensions;
    }
    void setNumDimensions(int numDimensions){this->numDimensions = numDimensions;}

private:
    int id;
//    QString penColor;
//    QString penWidth;
//    QString penStyle;
//    QString penCapStyle;
//    QString penJoinStyle;
//    QString brushColor;
//    QString brushStyle;
//    QString shapeType;
    QPen pen;
    QBrush brush;
    unsigned int numDimensions;  //Number of values in the array
    int * dimensions;   //Array of the dimensions
};

#endif // SHAPE_H
