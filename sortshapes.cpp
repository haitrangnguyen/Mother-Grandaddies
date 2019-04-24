#include "shape.h"

void Shape::sortID(Shape shape[pointEnd+1])
{
    for (int i = 1; i <= pointEnd; i++)
    {
        if (shape[i].GetId() < shape[i - 1].GetId())
        {
            Shape tempShape[1];
            tempShape[0].SetShape(shape[i].GetShape());
            tempShape[0].SetId(shape[i].GetId());
            tempShape[0].SetPen(shape[i].GetPen());
            tempShape[0].SetBrush(shape[i].GetBrush());
            int k = i;

            do {
                shape[k].SetShape(shape[k - 1].GetShape());
                shape[k].SetId(shape[k - 1].GetId());
                shape[k].SetPen(shape[k - 1].GetPen());
                shape[k].SetBrush(shape[k - 1].GetBrush());
                k--;
            } while (k > 0 && shape[k - 1].GetId() > tempShape[0].GetId());

            shape[k].SetShape(tempShape[0].GetShape());
            shape[k].SetId(tempShape[0].GetId());
            shape[k].SetPen(tempShape[0].GetPen());
            shape[k].SetBrush(tempShape[0].GetBrush());
        }
    }
}

void Shape::sortArea(Shape shape[pointEnd+1])
{
    for (int i = 1; i <= pointEnd; i++)
    {
        if (shape[i].GetArea() < shape[i - 1].GetArea())
        {
            Shape tempShape[1];
            tempShape[0].SetShape(shape[i].GetShape());
            tempShape[0].SetId(shape[i].GetId());
            tempShape[0].SetPen(shape[i].GetPen());
            tempShape[0].SetBrush(shape[i].GetBrush());
            int k = i;

            do {
                shape[k].SetShape(shape[k - 1].GetShape());
                shape[k].SetId(shape[k - 1].GetId());
                shape[k].SetPen(shape[k - 1].GetPen());
                shape[k].SetBrush(shape[k - 1].GetBrush());
                k--;
            } while (k > 0 && shape[k - 1].GetArea() > tempShape[0].GetArea());

            shape[k].SetShape(tempShape[0].GetShape());
            shape[k].SetId(tempShape[0].GetId());
            shape[k].SetPen(tempShape[0].GetPen());
            shape[k].SetBrush(tempShape[0].GetBrush());
        }
    }
}

void Shape::sortPerimeter(Shape shape[pointEnd+1])
{
    for (int i = 1; i <= pointEnd; i++)
    {
        if (shape[i].GetPerimeter() < shape[i - 1].GetPerimeter())
        {
            Shape tempShape[1];
            tempShape[0].SetShape(shape[i].GetShape());
            tempShape[0].SetId(shape[i].GetId());
            tempShape[0].SetPen(shape[i].GetPen());
            tempShape[0].SetBrush(shape[i].GetBrush());
            int k = i;

            do {
                shape[k].SetShape(shape[k - 1].GetShape());
                shape[k].SetId(shape[k - 1].GetId());
                shape[k].SetPen(shape[k - 1].GetPen());
                shape[k].SetBrush(shape[k - 1].GetBrush());
                k--;
            } while (k > 0 && shape[k - 1].GetPerimeter() > tempShape[0].GetPerimeter());

            shape[k].SetShape(tempShape[0].GetShape());
            shape[k].SetId(tempShape[0].GetId());
            shape[k].SetPen(tempShape[0].GetPen());
            shape[k].SetBrush(tempShape[0].GetBrush());
        }
    }
}
