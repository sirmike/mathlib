#include <sstream>
#include <cmath>

/*! \file matrix.h
    \brief Contains 3x3 Matrix declaration and definition.
*/

//! 3x3 Matrix template class
/*!
	Allows mathematical operations on a 3x3 Matrix.
	Includes several operators and basic functions such as inversion and transposition.
*/
const int FIELDCOUNT = 9;

template<typename T> class Mat3
{
	public:
		T f[FIELDCOUNT]; //!< matrix fields (first row is f[0] f[1] f[2] and so on)

		// row and col is 0..2
		T value(const int &row, const int &col) const
		{
			return f[3 * row + col];
		}
	public:
		/*! Default constructor */
		Mat3()
		{
			for(int i = 0; i < FIELDCOUNT; i++)
			{
				f[i] = 0.0;
			}
		}

		/*! Init all matrix fields */
		Mat3(T v1, T v2, T v3, T v4, T v5, T v6, T v7, T v8, T v9)
		{
			f[0] = v1;
			f[1] = v2;
			f[2] = v3;
			f[3] = v4;
			f[4] = v5;
			f[5] = v6;
			f[6] = v7;
			f[7] = v8;
			f[8] = v9;
		}

		/*! Destructor. It does nothing special ;) */
		~Mat3()
		{
		}

		/*! Writes string representation of the matrix to the stream */
		friend std::ostream & operator << (std::ostream &out, const Mat3 &v)
		{
			for(int i = 0; i < FIELDCOUNT; i++)
			{
				out << v.f[i];
				if((i + 1) % 3 == 0)
				{
					out << std::endl;
				}
				else
				{
					out << ", ";
				}
			}
			return out;
		}

		/*! Multiply scalar value by a matrix */
		friend Mat3<T> operator *(const T &scalar, const Mat3<T> &matrix)
		{
			return Mat3<T>(matrix.Field(0) * scalar,
					matrix.Field(1) * scalar,
					matrix.Field(2) * scalar,
					matrix.Field(3) * scalar,
					matrix.Field(4) * scalar,
					matrix.Field(5) * scalar,
					matrix.Field(6) * scalar,
					matrix.Field(7) * scalar,
					matrix.Field(8) * scalar);
		}

		/*! Add a scalar value to the matrix */
		Mat3<T> operator +(const T scalar)
		{
			return Mat3<T>(f[0] + scalar,
					f[1] + scalar,
					f[2] + scalar,
					f[3] + scalar,
					f[4] + scalar,
					f[5] + scalar,
					f[6] + scalar,
					f[7] + scalar,
					f[8] + scalar);
		}

		/*! Subtract a scalar value from the matrix */
		Mat3<T> operator -(const T scalar)
		{
			return Mat3<T>(f[0] - scalar,
					f[1] - scalar,
					f[2] - scalar,
					f[3] - scalar,
					f[4] - scalar,
					f[5] - scalar,
					f[6] - scalar,
					f[7] - scalar,
					f[8] - scalar);
		}

		/*! Multiply the matrix by a scalar value */
		Mat3<T> operator *(const T scalar)
		{
			return Mat3<T>(f[0] * scalar,
					f[1] * scalar,
					f[2] * scalar,
					f[3] * scalar,
					f[4] * scalar,
					f[5] * scalar,
					f[6] * scalar,
					f[7] * scalar,
					f[8] * scalar);
		}

		/*! Divide the matrix by a scalar value */
		Mat3<T> operator /(const T scalar)
		{
			if(static_cast<int>(scalar) == 0)
			{
				return Mat3<T>();
			}
			else
			{
				return Mat3<T>(f[0] / scalar,
						f[1] / scalar,
						f[2] / scalar,
						f[3] / scalar,
						f[4] / scalar,
						f[5] / scalar,
						f[6] / scalar,
						f[7] / scalar,
						f[8] / scalar);
			}
		}

		/*! Multiply current matrix by a scalar value */
		Mat3<T>& operator *=(const T scalar)
		{
			for(int i = 0; i < FIELDCOUNT; i++)
			{
				f[i] *= scalar;
			}
			return *this;
		}	

		/*! Divide current matrix by a scalar value */
		Mat3<T>& operator /=(const T scalar)
		{
			if(static_cast<int>(scalar) == 0)
			{
				return *this;
			}
			for(int i = 0; i < FIELDCOUNT; i++)
			{
				f[i] /= scalar;
			}
			return *this;
		}	

		/*! Add a scalar value to the curent matrix */
		Mat3<T>& operator +=(const T scalar)
		{
			for(int i = 0; i < FIELDCOUNT; i++)
			{
				f[i] += scalar;
			}
			return *this;
		}	

		/*! Subtract a scalar value from the curent matrix */
		Mat3<T>& operator -=(const T scalar)
		{
			for(int i = 0; i < FIELDCOUNT; i++)
			{
				f[i] -= scalar;
			}
			return *this;
		}	

		/*! Return value of the matrix field (0 to 8) */
		T Field(const int index) const
		{
			if(index > 8)
			{
				return this->f[8];
			}
			if(index < 0)
			{
				return f[0];
			}
			return f[index];
		}

		/*! Add a matrix to the current one */
		Mat3<T> operator +(const Mat3<T> &matrix)
		{
			return Mat3<T>(f[0] + matrix.Field(0),
					f[1] + matrix.Field(1),
					f[2] + matrix.Field(2),
					f[3] + matrix.Field(3),
					f[4] + matrix.Field(4),
					f[5] + matrix.Field(5),
					f[6] + matrix.Field(6),
					f[7] + matrix.Field(7),
					f[8] + matrix.Field(8));
		}

		/*! Add a matrix to the current one */
		Mat3<T> operator +=(const Mat3<T> &matrix)
		{
			for(int i = 0; i < FIELDCOUNT; i++)
			{
				f[i] += matrix.Field(i);
			}
			return Mat3<T>(f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7], f[8]);
		}

		/*! Subtract a matrix from the current one */
		Mat3<T> operator -=(const Mat3<T> &matrix)
		{
			for(int i = 0; i < FIELDCOUNT; i++)
			{
				f[i] -= matrix.Field(i);
			}
			return Mat3<T>(f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7], f[8]);
		}

		/*! Multiply current matrix by another one */
		Mat3<T> operator *=(const Mat3<T> &matrix)
		{
			f[0] *= matrix.Field(0);
			f[1] *= matrix.Field(3);
			f[2] *= matrix.Field(6);
			f[3] *= matrix.Field(1);
			f[4] *= matrix.Field(4);
			f[5] *= matrix.Field(7);
			f[6] *= matrix.Field(2);
			f[7] *= matrix.Field(5);
			f[8] *= matrix.Field(8);
			return Mat3<T>(f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7], f[8]);
		}

		/*! Subtract a matrix from the current one */
		Mat3<T> operator -(const Mat3<T> &matrix)
		{
			return Mat3<T>(f[0] - matrix.Field(0),
					f[1] - matrix.Field(1),
					f[2] - matrix.Field(2),
					f[3] - matrix.Field(3),
					f[4] - matrix.Field(4),
					f[5] - matrix.Field(5),
					f[6] - matrix.Field(6),
					f[7] - matrix.Field(7),
					f[8] - matrix.Field(8));
		}

		/*! Multiply the current matrix by another one */
		Mat3<T> operator *(const Mat3<T> &matrix)
		{
			return Mat3<T>(f[0] * matrix.Field(0),
					f[1] * matrix.Field(3),
					f[2] * matrix.Field(6),
					f[3] * matrix.Field(1),
					f[4] * matrix.Field(4),
					f[5] * matrix.Field(7),
					f[6] * matrix.Field(2),
					f[7] * matrix.Field(5),
					f[8] * matrix.Field(8));
		}

		/*! Check if matrix is identity */
		bool IsIdentity() const
		{
			int sum = 0;
			for(int i = 0; i < FIELDCOUNT; i++)
			{
				if(i == 0 || i == 4 || i == 8)
				{
					sum += static_cast<int>(f[i]);
				}
				else
				{
					if(static_cast<int>(f[i]) != 0)
					{
						return false;
					}
				}
				if(sum > 3)
				{
					return false;
				}
			}
			return true;
		}

		/*! Set the matrix to be identity */
		Mat3<T>& SetIdentity()
		{
			for(int i = 0; i < FIELDCOUNT; i++)
			{
				if(i == 0 ||  i == 4 || i == 8)
				{
					f[i] = 1.0;
				}
				else
				{
					f[i] = 0.0;
				}
			}
			return *this;
		}

		/*! Inverse matrix using Gauss-Jordan elimination */
		bool InverseGaussian()
		{
			T augmentedMatrix[] = {f[0], f[1], f[2], 1.0, 0.0, 0.0,
						f[3], f[4], f[5], 0.0, 1.0, 0.0,
						f[6], f[7], f[8], 0.0, 0.0, 1.0};
			for(int j = 0; j < 3; j++)
			{
				// find the row such that M[i, j] has the largest absolute value
				int largestPivot = 0;
				T largestValue = 0.0;
				for(int i = j; i < 3; i++)
				{
					T current = static_cast<T>(fabs(augmentedMatrix[6 * i + j]));
					if(current > largestValue)
					{
						largestPivot = i;
						largestValue = current;
					}
				}
				// if largest value is 0 matrix is irreversible
				if(largestValue == 0.0)
				{
					return false;
				}
				// exchange rows
				if(largestPivot != j)
				{
					for(int x = 0; x < 6; x++)
					{
						T temp = augmentedMatrix[largestPivot * 6 + x];
						augmentedMatrix[largestPivot * 6 + x] = augmentedMatrix[j * 6 + x];
						augmentedMatrix[j * 6 + x] = temp;
					}
				}
				// mutiply row j by 1/M[j, j]
				// this sets the (j, j) entry of M to 1
				T divider = augmentedMatrix[j * 6 + j];
				for(int x = 0; x < 6; x++)
				{
					augmentedMatrix[j * 6 + x] *= (1.0 / divider);
				}
				// for each row r where 1 <= r <= n and r != j, add -M[r, j] times row j to row r
				// this step clears each entry above and below row j in column j to 0
				for(int r = 0; r < 3; r++)
				{
					T factor = -augmentedMatrix[r * 6 + j];
					if(r != j)
					{
						for(int x = 0; x < 6; x++)
						{
							augmentedMatrix[r * 6 + x] += (factor * augmentedMatrix[j * 6 + x]);
						}
					}
				}
			}
			// copy right part of augmented matrix to destination
			f[0] = augmentedMatrix[3];
			f[1] = augmentedMatrix[4];
			f[2] = augmentedMatrix[5];
			f[3] = augmentedMatrix[9];
			f[4] = augmentedMatrix[10];
			f[5] = augmentedMatrix[11];
			f[6] = augmentedMatrix[15];
			f[7] = augmentedMatrix[16];
			f[8] = augmentedMatrix[17];
			return true;
		}

		void Inverse()
		{
			*this =  (1.0 / Det()) * Mat3<T>(f[4] * f[8] - f[5] * f[7], f[2] * f[7] - f[1] * f[8], f[1] * f[5] - f[2] * f[4],
						f[5] * f[6] - f[3] * f[8], f[0] * f[8] - f[2] * f[6], f[2] * f[3] - f[0] * f[5],
						f[3] * f[7] - f[4] * f[6], f[1] * f[6] - f[0] * f[7], f[0] * f[4] - f[1] * f[3]
						);
		}

		/*! Determinant of the matrix */
		T Det() const
		{
			return f[0] * (f[4] * f[8] - f[5] * f[7]) - f[1] * (f[3] * f[8] - f[5] * f[6]) + f[2] * (f[3] * f[7] - f[4] * f[6]);
		}

		/*! Transpose matrix */
		void Transpose()
		{
			T temp[FIELDCOUNT];
			temp[0] = f[0];
			temp[1] = f[3];
			temp[2] = f[6];
			temp[3] = f[1];
			temp[4] = f[4];
			temp[5] = f[7];
			temp[6] = f[2];
			temp[7] = f[5];
			temp[8] = f[8];
			for(int i = 0; i < 9; i++)
			{
				f[i] = temp[i];
			}
		}
};

typedef Mat3<float> Mat3f;	//!< 3x3 Matrix of floats
typedef Mat3<double> Mat3d;	//!< 3x3 Matrix of doubles
typedef Mat3f Matrix;
