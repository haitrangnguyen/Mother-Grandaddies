#include "shape.h"
#include <algorithm>

template <class Type>
bool Shape::selectionSort(Shape<Type> *shape, int size, bool (*comparisonFcn)(Type, Type))
{
	for (int startIndex = 0; startIndex < size, ++startIndex)
	{
		int bestIndex = startIndex;
		
		for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex)
		{
			if (comparisonFcn(shape[bestIndex], shape[currentIndex]))
			{
				bestIndex = currentIndex;
			}
		}
		
		std::swap(shape[startIndex], shape[bestIndex]);
	}
}

template <class Type>
bool Shape::compareShapeId(Shape<Type> x, Shape<Type> y)
{
	return x.GetId() > y.GetId();
}

template <class Type>
bool Shape::compareShapePerimeter(Shape<Type> x, Shape<Type> y)
{
	return x.GetPerimeter() > y.GetPerimeter();
}

template <class Type>
bool Shape::compareShapeArea(Shape<Type> x, Shape<Type> y)
{
	return x.GetArea() > y.GetArea();
}
