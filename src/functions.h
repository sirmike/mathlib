#ifndef MATH_FUNCTIONS_H
#define MATH_FUNCTIONS_H

#include "vec.h"
#include "matrix.h"
#include <list>

/*! \file functions.h
    \brief Contains helper functions
*/

namespace MathLib
{
	std::ostream & operator << (std::ostream &out, const MathLib::Mat4 &v);

	/*! Defines PI value */
	const float PI = 3.14159f;

	/*! Produces a 4x4 matrix translation */
	Mat4& MatrixTranslation(Mat4 &matrix, float x, float y, float z);

	/*! Produces a 4x4 matrix rotation on X axis */
	Mat4& MatrixRotationX(Mat4 &matrix, const float radians);

	/*! Produces a 4x4 matrix rotation on Y axis */
	Mat4& MatrixRotationY(Mat4 &matrix, const float radians);

	/*! Produces a 4x4 matrix rotation on Z axis */
	Mat4& MatrixRotationZ(Mat4 &matrix, const float radians);

	/*! Produces a 4x4 matrix scale */
	Mat4& MatrixScaling(Mat4 &matrix, float x, float y, float z);

	/*! Changes degrees to radians */
	float DegreesToRadians(float degrees);

	template<class T, class Iterator> Iterator Advance(T &dataContainer, Iterator &itemPos, int skipSize);

	/*! Performs CatmullRom calculations on a dataContainer */
	Point3f CatmullRom(std::list<Point3f> &dataContainer, std::list<Point3f>::iterator &itemPos, const float &time);

	/*! Performs Bezier calculations on a dataContainer */
	Point3f Bezier(std::list<Point3f> &dataContainer, std::list<Point3f>::iterator &itemPos, const float &time);

	/*! Performs linear interpolation calculations on a dataContainer */
	Point3f LinearInterpolation(std::list<Point3f> &dataContainer, std::list<Point3f>::iterator itemPos, const float &time);
}

#endif
