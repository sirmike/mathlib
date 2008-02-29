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
	matrix._41 = x;
	matrix._42 = y;
	matrix._43 = z;
	return matrix;
}

MathLib::Mat4& MathLib::MatrixRotationX(Mat4 &matrix, const float radians)
{
	matrix._11 = 1.0f;
	matrix._12 = 0.0f;
	matrix._13 = 0.0f;
	matrix._14 = 0.0f;

	matrix._21 = 0.0f;
	matrix._22 = cosf(radians);
	matrix._23 = sinf(radians);
	matrix._24 = 0.0f;

	matrix._31 = 0.0f;
	matrix._32 = -sinf(radians);
	matrix._33 = cosf(radians);
	matrix._34 = 0.0f;

	matrix._41 = 0.0f;
	matrix._42 = 0.0f;
	matrix._43 = 0.0f;
	matrix._44 = 1.0f;
	return matrix;
}

MathLib::Mat4& MathLib::MatrixRotationY(Mat4 &matrix, const float radians)
{
	matrix._11 = cosf(radians);
	matrix._12 = 0.0f;
	matrix._13 = -sinf(radians);
	matrix._14 = 0.0f;

	matrix._21 = 0.0f;
	matrix._22 = 1.0f;
	matrix._23 = 0.0f;
	matrix._24 = 0.0f;

	matrix._31 = sinf(radians);
	matrix._32 = 0.0f;
	matrix._33 = cosf(radians);
	matrix._34 = 0.0f;

	matrix._41 = 0.0f;
	matrix._42 = 0.0f;
	matrix._43 = 0.0f;
	matrix._44 = 1.0f;
	return matrix;
}

MathLib::Mat4& MathLib::MatrixRotationZ(Mat4 &matrix, const float radians)
{
	matrix._11 = cosf(radians);
	matrix._12 = sinf(radians);
	matrix._13 = 0.0f;
	matrix._14 = 0.0f;

	matrix._21 = -sinf(radians);
	matrix._22 = cosf(radians);
	matrix._23 = 0.0f;
	matrix._24 = 0.0f;

	matrix._31 = 0.0f;
	matrix._32 = 0.0f;
	matrix._33 = 1.0f;
	matrix._34 = 0.0f;

	matrix._41 = 0.0f;
	matrix._42 = 0.0f;
	matrix._43 = 0.0f;
	matrix._44 = 1.0f;
	return matrix;
}

MathLib::Mat4& MathLib::MatrixScaling(Mat4 &matrix, float x, float y, float z)
{
	matrix._11 = x;
	matrix._12 = 0.0f;
	matrix._13 = 0.0f;
	matrix._14 = 0.0f;

	matrix._21 = 0.0f;
	matrix._22 = y;
	matrix._23 = 0.0f;
	matrix._24 = 0.0f;

	matrix._31 = 0.0f;
	matrix._32 = 0.0f;
	matrix._33 = z;
	matrix._34 = 0.0f;

	matrix._41 = 0.0f;
	matrix._42 = 0.0f;
	matrix._43 = 0.0f;
	matrix._44 = 1.0f;
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

