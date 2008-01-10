#ifndef MATH_FUNCTIONS_H
#define MATH_FUNCTIONS_H

/*! \file functions.h
    \brief Contains helper functions
*/

namespace MathLib
{
	class Mat4;

	/*! Defines PI value */
	const float PI = 3.14159f;

	/*! Produces a matrix translation */
	Mat4& MatrixTranslation(Mat4 &matrix, float x, float y, float z);

	/*! Produces a matrix rotation on X axis */
	Mat4& MatrixRotationX(Mat4 &matrix, const float radians);

	/*! Produces a matrix rotation on Y axis */
	Mat4& MatrixRotationY(Mat4 &matrix, const float radians);

	/*! Produces a matrix rotation on Z axis */
	Mat4& MatrixRotationZ(Mat4 &matrix, const float radians);

	/*! Produces a matrix scale */
	Mat4& MatrixScaling(Mat4 &matrix, float x, float y, float z);

	/*! Changes degrees to radians */
	float DegreesToRadians(float degrees);

}

#endif