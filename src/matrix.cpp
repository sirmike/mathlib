#include "matrix.h"
#include "functions.h"
#include <memory>

using namespace MathLib;

float Mat4::GetValue(const int& row, const int& col) const
{
	return m[row][col];
}

Mat4::Mat4()
{
	memset(&this->m, 0, 16 * sizeof(float));
}

Mat4::Mat4(float _11, float _12, float _13, float _14,
	float _21, float _22, float _23, float _24,
	float _31, float _32, float _33, float _34,
	float _41, float _42, float _43, float _44)
{
	this->_11 = _11;
	this->_12 = _12;
	this->_13 = _13;
	this->_14 = _14;
	this->_21 = _21;
	this->_22 = _22;
	this->_23 = _23;
	this->_24 = _24;
	this->_31 = _31;
	this->_32 = _32;
	this->_33 = _33;
	this->_34 = _34;
	this->_41 = _41;
	this->_42 = _42;
	this->_43 = _43;
	this->_44 = _44;
}

Mat4 operator *(const float &scalar, const Mat4 &matrix)
{
	Mat4 result;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			result.m[i][j] = matrix.m[i][j] * scalar;
		}
	}
	return result;
}

void Mat4::operator =(const Mat4& matrix)
{
	memcpy(&this->m, &matrix.m, 16 * sizeof(float));
}

Mat4 Mat4::operator +(const float& scalar) const
{
	Mat4 result;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			result.m[i][j] = this->m[i][j] + scalar;
		}
	}
	return result;
}

Mat4 Mat4::operator -(const float& scalar) const
{
	Mat4 result;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			result.m[i][j] = this->m[i][j] - scalar;
		}
	}
	return result;
}

Mat4 Mat4::operator *(const float& scalar) const
{
	Mat4 result;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			result.m[i][j] = this->m[i][j] * scalar;
		}
	}
	return result;
}


Mat4 Mat4::operator /(const float& scalar) const
{
	Mat4 result;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			result.m[i][j] = this->m[i][j] / scalar;
		}
	}
	return result;
}


const Mat4& Mat4::operator +=(const float& scalar)
{
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			this->m[i][j] += scalar;
		}
	}
	return *this;
}

const Mat4& Mat4::operator -=(const float& scalar)
{
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			this->m[i][j] -= scalar;
		}
	}
	return *this;
}

const Mat4& Mat4::operator *=(const float& scalar)
{
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			this->m[i][j] *= scalar;
		}
	}
	return *this;
}

const Mat4& Mat4::operator /=(const float& scalar)
{
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			this->m[i][j] /= scalar;
		}
	}
	return *this;
}

Mat4 Mat4::operator +(const Mat4& matrix)
{
	Mat4 result;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			result.m[i][j] += matrix.m[i][j];
		}
	}
	return result;
}

const Mat4& Mat4::operator +=(const Mat4& matrix)
{
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			this->m[i][j] += matrix.m[i][j];
		}
	}
	return *this;
}

Mat4 Mat4::operator *(const Mat4& matrix)
{
	Mat4 result(*this);
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			result.m[i][j] *= matrix.m[j][i];
		}
	}
	return result;
}

const Mat4& Mat4::operator *=(const Mat4& matrix)
{
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			this->m[i][j] *= matrix.m[j][i];
		}
	}
	return *this;
}

bool Mat4::IsIdentity() const
{
	return (_11 == 1.0f &&  _22 == 1.0f && _33 == 1.0f && _44 == 1.0f && 
		_12 == 0.0f && _13 == 0.0f && _14 == 0.0f &&
		_21 == 0.0f && _23 == 0.0f && _24 == 0.0f &&
		_31 == 0.0f && _32 == 0.0f && _34 == 0.0f &&
		_41 == 0.0f && _42 == 0.0f && _43 == 0.0f);
}

void Mat4::SetIdentity()
{
	_11 = 1.0f;
	_12 = 0.0f;
	_13 = 0.0f;
	_14 = 0.0f;
	_21 = 0.0f;
	_22 = 1.0f;
	_23 = 0.0f;
	_24 = 0.0f;
	_31 = 0.0f;
	_32 = 0.0f;
	_33 = 1.0f;
	_34 = 0.0f;
	_41 = 0.0f;
	_42 = 0.0f;
	_43 = 0.0f;
	_44 = 1.0f;
}

Mat4 Mat4::Transposed() const
{
	Mat4 result(*this);
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			result.m[i][j] = this->m[j][i];
		}
	}
	return result;
}
