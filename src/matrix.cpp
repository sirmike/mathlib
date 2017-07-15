#include "matrix.h"
#include "functions.h"
#include <cstring>

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
    this->data._11 = _11;
    this->data._12 = _12;
    this->data._13 = _13;
    this->data._14 = _14;
    this->data._21 = _21;
    this->data._22 = _22;
    this->data._23 = _23;
    this->data._24 = _24;
    this->data._31 = _31;
    this->data._32 = _32;
    this->data._33 = _33;
    this->data._34 = _34;
    this->data._41 = _41;
    this->data._42 = _42;
    this->data._43 = _43;
    this->data._44 = _44;
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
    Mat4 result;

    result.data._11 = this->data._11 * matrix.data._11 + this->data._21 * matrix.data._12 + this->data._31 * matrix.data._13 + this->data._41 * matrix.data._14;
    result.data._12 = this->data._12 * matrix.data._11 + this->data._22 * matrix.data._12 + this->data._32 * matrix.data._13 + this->data._42 * matrix.data._14;
    result.data._13 = this->data._13 * matrix.data._11 + this->data._23 * matrix.data._12 + this->data._33 * matrix.data._13 + this->data._43 * matrix.data._14;
    result.data._14 = this->data._14 * matrix.data._11 + this->data._24 * matrix.data._12 + this->data._34 * matrix.data._13 + this->data._44 * matrix.data._14;

    result.data._21 = this->data._11 * matrix.data._21 + this->data._21 * matrix.data._22 + this->data._31 * matrix.data._23 + this->data._41 * matrix.data._24;
    result.data._22 = this->data._12 * matrix.data._21 + this->data._22 * matrix.data._22 + this->data._32 * matrix.data._23 + this->data._42 * matrix.data._24;
    result.data._23 = this->data._13 * matrix.data._21 + this->data._23 * matrix.data._22 + this->data._33 * matrix.data._23 + this->data._43 * matrix.data._24;
    result.data._24 = this->data._14 * matrix.data._21 + this->data._24 * matrix.data._22 + this->data._34 * matrix.data._23 + this->data._44 * matrix.data._24;

    result.data._31 = this->data._11 * matrix.data._31 + this->data._21 * matrix.data._32 + this->data._31 * matrix.data._33 + this->data._41 * matrix.data._34;
    result.data._32 = this->data._12 * matrix.data._31 + this->data._22 * matrix.data._32 + this->data._32 * matrix.data._33 + this->data._42 * matrix.data._34;
    result.data._33 = this->data._13 * matrix.data._31 + this->data._23 * matrix.data._32 + this->data._33 * matrix.data._33 + this->data._43 * matrix.data._34;
    result.data._34 = this->data._14 * matrix.data._31 + this->data._24 * matrix.data._32 + this->data._34 * matrix.data._33 + this->data._44 * matrix.data._34;

    result.data._41 = this->data._11 * matrix.data._41 + this->data._21 * matrix.data._42 + this->data._31 * matrix.data._43 + this->data._41 * matrix.data._44;
    result.data._42 = this->data._12 * matrix.data._41 + this->data._22 * matrix.data._42 + this->data._32 * matrix.data._43 + this->data._42 * matrix.data._44;
    result.data._43 = this->data._13 * matrix.data._41 + this->data._23 * matrix.data._42 + this->data._33 * matrix.data._43 + this->data._43 * matrix.data._44;
    result.data._44 = this->data._14 * matrix.data._41 + this->data._24 * matrix.data._42 + this->data._34 * matrix.data._43 + this->data._44 * matrix.data._44;

    return result;
}

bool Mat4::IsIdentity() const
{
    return (data._11 == 1.0f &&  data._22 == 1.0f && data._33 == 1.0f && data._44 == 1.0f && 
            data._12 == 0.0f && data._13 == 0.0f && data._14 == 0.0f &&
            data._21 == 0.0f && data._23 == 0.0f && data._24 == 0.0f &&
            data._31 == 0.0f && data._32 == 0.0f && data._34 == 0.0f &&
            data._41 == 0.0f && data._42 == 0.0f && data._43 == 0.0f);
}

void Mat4::SetIdentity()
{
    data._11 = 1.0f;
    data._12 = 0.0f;
    data._13 = 0.0f;
    data._14 = 0.0f;
    data._21 = 0.0f;
    data._22 = 1.0f;
    data._23 = 0.0f;
    data._24 = 0.0f;
    data._31 = 0.0f;
    data._32 = 0.0f;
    data._33 = 1.0f;
    data._34 = 0.0f;
    data._41 = 0.0f;
    data._42 = 0.0f;
    data._43 = 0.0f;
    data._44 = 1.0f;
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

const float* Mat4::GetPointer() const
{
    return &data._11;
}
