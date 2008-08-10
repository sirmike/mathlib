#include <sstream>
#include <exception>
#include <cstdlib>
#include <stdexcept>
#include "functions.h"
#include "matrix.h"

using namespace MathLib;
using namespace std;

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

template<class T, class Iterator> Iterator MathLib::Advance(T &dataContainer, Iterator &itemPos, int skipSize)
{
	Iterator result = itemPos;

	if(skipSize == 0)
	{
		return result;
	}

	for(int i = 0; i < abs(skipSize); i++)
	{
		if(skipSize > 0)
		{
			if(result == --(dataContainer.end()))
			{
				result = dataContainer.begin();
			}
			else
			{
				result++;
			}
		}
		if(skipSize < 0)
		{
			if(result == dataContainer.begin())
			{
				result = --(dataContainer.end());
			}
			else
			{
				result--;
			}
		}
	}

	return result;
}

MathLib::Point3f MathLib::CatmullRom(list<Point3f> &dataContainer, 
									 list<Point3f>::iterator &itemPos, 
									 const float &time)
{
	if(dataContainer.size() < 4)
	{
		throw std::range_error("dataContainer must have at least 4 elements.");
	}

	float t_2 = time * time;
	float t_3 = t_2 * time;

	Point3f p0 = *(Advance(dataContainer, itemPos, -1));
	Point3f p1 = *(itemPos);
	Point3f p2 = *(Advance(dataContainer, itemPos, 1));
	Point3f p3 = *(Advance(dataContainer, itemPos, 2));

	
	Point3f result(0.0f, 0.0f, 0.0f);
	
	result = 0.5f * ((2.0f * p1) + (-p0 + p2) * time + (2.0f * p0 - 5.0f * p1 + 4.0f * p2 - p3) * t_2 + (-p0 + 3.0f * p1 - 3.0f * p2 + p3) * t_3);
	
	return result;
}

MathLib::Point3f MathLib::Bezier(list<MathLib::Point3f> &dataContainer,
								 list<Point3f>::iterator &itemPos, 
								 const float &time)
{
	if(dataContainer.size() < 4)
	{
		throw std::range_error("dataContainer must have at least 4 elements.");
	}

	float t_1 = 1.0f - time;
	float t_2 = (1.0f - time) * time;
	float t_3 = (1.0f - time) * t_2;
	
	MathLib::Point3f p0 = *itemPos;
	MathLib::Point3f p1 = *(Advance(dataContainer, itemPos, 1));
	MathLib::Point3f p2 = *(Advance(dataContainer, itemPos, 2));
	MathLib::Point3f p3 = *(Advance(dataContainer, itemPos, 3));

	return t_3 * p0 + 3 * time * t_2 * p1 + 3 * time * time * t_1 * p2 + time * time * time * p3;
}

MathLib::Point3f MathLib::LinearInterpolation(list<MathLib::Point3f> &dataContainer, list<MathLib::Point3f>::iterator itemPos, const float &time)
{
	MathLib::Point3f p0 = *itemPos;
	MathLib::Point3f p1 = *++itemPos;
	
	return (p0 * (1 - time) + p1 * time);
}
