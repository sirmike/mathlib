#ifndef MAT4_H
#define MAT4_H

#include <sstream>
#include <cmath>

/*! \file matrix.h
    \brief Contains 4x4 Matrix declaration
*/

namespace MathLib
{
	//! 4x4 Matrix class
	/*!
		Allows mathematical operations on a 4x4 Matrix.
		Includes several operators and basic functions such as inversion and transposition.
	*/
	class Mat4
	{
	public:
		union
		{
			struct
			{
				float _11, _12, _13, _14;
				float _21, _22, _23, _24;
				float _31, _32, _33, _34;
				float _41, _42, _43, _44;	// translation _41, _42, _43
			};
			float m[4][4];
		};

		/*! Default constructor */
		Mat4();

		/*! Constructor which gets values for matrix fields */
		Mat4(float _11, float _12, float _13, float _14,
			float _21, float _22, float _23, float _24,
			float _31, float _32, float _33, float _34,
			float _41, float _42, float _43, float _44);

		/*! Helper operator which allows writing matrix value to the output stream */
		friend std::ostream & operator << (std::ostream &out, const Mat4 &v);

		/*! Helper operator which allows multiplying scalar by a matrix */
		friend Mat4 operator *(const float &scalar, const Mat4 &matrix);

		/*! Assign a matrix */
		void operator =(const Mat4& matrix);

		/*! Add a matrix to another matrix */
		Mat4 operator +(const Mat4& matrix);

		/*! Add a matrix to another matrix (makes modifications to the matrix) */
		const Mat4& operator +=(const Mat4& matrix);

		/*! Multiplies a matrix by another matrix */
		Mat4 operator *(const Mat4& matrix);

		/*! Check if it is an identity matrix */
		bool IsIdentity() const;
		
		/*! Set the matrix to the identity */
		void SetIdentity();

		/*! Return transposed matrix */
		Mat4 Transposed() const;

		/*! Returns value by a row and a column */
		float GetValue(const int& row, const int& col) const;
	};

	typedef Mat4 Matrix;
}

#endif
