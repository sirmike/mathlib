#include <sstream>
#include "functions.h"
#include "matrix.h"

using namespace MathLib;

float MathLib::DegreesToRadians(float degrees) 
{
	return degrees * (PI / 180.0f);
}

MathLib::Mat4& MathLib::MatrixTranslation(Mat4 &matrix, float x, float y, float z)
{
	matrix.SetIdentity();
	matrix.data._41 = x;
	matrix.data._42 = y;
	matrix.data._43 = z;
	return matrix;
}

MathLib::Mat4& MathLib::MatrixRotationX(Mat4 &matrix, const float radians)
{
	matrix.data._11 = 1.0f;
	matrix.data._12 = 0.0f;
	matrix.data._13 = 0.0f;
	matrix.data._14 = 0.0f;

	matrix.data._21 = 0.0f;
	matrix.data._22 = cosf(radians);
	matrix.data._23 = sinf(radians);
	matrix.data._24 = 0.0f;

	matrix.data._31 = 0.0f;
	matrix.data._32 = -sinf(radians);
	matrix.data._33 = cosf(radians);
	matrix.data._34 = 0.0f;

	matrix.data._41 = 0.0f;
	matrix.data._42 = 0.0f;
	matrix.data._43 = 0.0f;
	matrix.data._44 = 1.0f;
	return matrix;
}

MathLib::Mat4& MathLib::MatrixRotationY(Mat4 &matrix, const float radians)
{
	matrix.data._11 = cosf(radians);
	matrix.data._12 = 0.0f;
	matrix.data._13 = -sinf(radians);
	matrix.data._14 = 0.0f;

	matrix.data._21 = 0.0f;
	matrix.data._22 = 1.0f;
	matrix.data._23 = 0.0f;
	matrix.data._24 = 0.0f;

	matrix.data._31 = sinf(radians);
	matrix.data._32 = 0.0f;
	matrix.data._33 = cosf(radians);
	matrix.data._34 = 0.0f;

	matrix.data._41 = 0.0f;
	matrix.data._42 = 0.0f;
	matrix.data._43 = 0.0f;
	matrix.data._44 = 1.0f;
	return matrix;
}

MathLib::Mat4& MathLib::MatrixRotationZ(Mat4 &matrix, const float radians)
{
	matrix.data._11 = cosf(radians);
	matrix.data._12 = sinf(radians);
	matrix.data._13 = 0.0f;
	matrix.data._14 = 0.0f;

	matrix.data._21 = -sinf(radians);
	matrix.data._22 = cosf(radians);
	matrix.data._23 = 0.0f;
	matrix.data._24 = 0.0f;

	matrix.data._31 = 0.0f;
	matrix.data._32 = 0.0f;
	matrix.data._33 = 1.0f;
	matrix.data._34 = 0.0f;

	matrix.data._41 = 0.0f;
	matrix.data._42 = 0.0f;
	matrix.data._43 = 0.0f;
	matrix.data._44 = 1.0f;
	return matrix;
}

MathLib::Mat4& MathLib::MatrixScaling(Mat4 &matrix, float x, float y, float z)
{
	matrix.data._11 = x;
	matrix.data._12 = 0.0f;
	matrix.data._13 = 0.0f;
	matrix.data._14 = 0.0f;

	matrix.data._21 = 0.0f;
	matrix.data._22 = y;
	matrix.data._23 = 0.0f;
	matrix.data._24 = 0.0f;

	matrix.data._31 = 0.0f;
	matrix.data._32 = 0.0f;
	matrix.data._33 = z;
	matrix.data._34 = 0.0f;

	matrix.data._41 = 0.0f;
	matrix.data._42 = 0.0f;
	matrix.data._43 = 0.0f;
	matrix.data._44 = 1.0f;
	return matrix;
}

std::ostream & MathLib::operator << (std::ostream &out, const MathLib::Mat4 &v)
{
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			out << v.m[i][j];
			out << ", ";
		}
		out << std::endl;
	}
	return out;
}

