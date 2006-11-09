#include <cmath>
#include <sstream>

/*! \file vector.h
    \brief Contains 3D Vector declaration and definition.
*/

//! 3D Vector template class
/*!
	Allows mathematical operations on a 3D vector.
	Includes several operators and basic functions such as dot or cross product.
*/

template <typename T> class Vec3
{
	public:
		/*! Default constructor. Sets all vector components to zeroes */
		Vec3()
		{
			x = y = z = 0;
		}

		/*! Inits all vector components
		\param x Initial value of x component
		\param y Initial value of y component
		\param z Initial value of z component
		*/
		Vec3(T x, T y, T z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}

		/*! Destructor. It does nothing special ;) */
		~Vec3()
		{
		}

		// operators

		/*! Adds two vectors */
		Vec3<T> operator +(const Vec3<T>& v)
		{
			return Vec3(x + v.x, y + v.y, z + v.z);
		}

		/*! Subtracts two vectors */
		Vec3<T> operator -(const Vec3<T>& v)
		{
			return Vec3(x - v.x, y - v.y, z - v.z);
		}


		/*! Multiplies two vectors */
		Vec3<T> operator *(const Vec3<T>& v)
		{
			return Vec3(x * v.x, y * v.y, z * v.z);
		}

		/*! Divides one vector by another */
		Vec3<T> operator /(const Vec3<T>& v)
		{
			return Vec3(x / v.x, y / v.y, z / v.z);
		}


		/*! Adds scalar value to the vector */
		Vec3<T> operator +(const T scalar)
		{
			return Vec3(x + scalar, y + scalar, z + scalar);
		}

		/*! Subtracts scalar value from the vector */
		Vec3<T> operator -(const T scalar)
		{
			return Vec3(x - scalar, y - scalar, z - scalar);
		}

		/*! Multiplies the vector by a scalar value */
		Vec3<T> operator *(const T scalar)
		{
			return Vec3(x * scalar, y * scalar, z * scalar);
		}

		/*! Divides the vector by a scalar value */
		Vec3<T> operator /(const T scalar)
		{
			return Vec3<T>(x / scalar, y / scalar, z / scalar);
		}

		/*! Negates the vectors components */
		Vec3<T> operator -() const
		{
			return Vec3<T>(-x, -y, -z);
		}

		/*! Adds a vector to the current one */
		Vec3<T>& operator +=(const Vec3<T> &v)
		{
			x += v.x;
			y += v.y;
			z += v.z;
			return *this;
		}

		/*! Subtracts a vector from the current one */
		Vec3<T>& operator -=(const Vec3<T> &v)
		{
			x -= v.x;
			y -= v.y;
			z -= v.z;
			return *this;
		}

		/*! Multiplies the current vector by another one */
		Vec3<T>& operator *=(const Vec3<T> &v)
		{
			x *= v.x;
			y *= v.y;
			z *= v.z;
			return *this;
		}

		/*! Multiplies the current vector by a scalar value */
		Vec3<T>& operator *=(const T scalar)
		{
			x *= scalar;
			y *= scalar;
			z *= scalar;
			return *this;
		}

		/*! Divides the current vector by a scalar value */
		Vec3<T>& operator /=(const T scalar)
		{
			*this *= (1.0f / scalar);
			return *this;
		}

		/*! Adds a scalar value to the current vector */
		Vec3<T>& operator +=(const T scalar)
		{
			x += scalar;
			y += scalar;
			z += scalar;
			return *this;
		}

		/*! Subtracts a scalar value from the current vector */
		Vec3<T>& operator -=(const T scalar)
		{
			x -= scalar;
			y -= scalar;
			z -= scalar;
			return *this;
		}

		/*! Returns true if two vectors are equal */
		bool operator ==(const Vec3<T> &v)
		{
			return (x == v.x && y == v.y && z == v.z);
		}

		/*! Returns true if two vectors are not equal */
		bool operator !=(const Vec3<T> &v)
		{
			return !(*this == v);
		}

		/*!
		*	Multiplies a scalar value by the vector when a scalar is on the left side.\n
		*	For example:
		* \code
		* Vec3d r(1.0, 0.0, 0.0);
		* r = 4 * P;
		* \endcode
		*/
		friend Vec3<T> operator *(const T scalar, const Vec3<T> &v)
		{
			return Vec3<T>(v.x * scalar, v.y * scalar, v.z * scalar);
		}

		/*! Writes string representation of the vector to the stream */
		friend std::ostream & operator << (std::ostream &out, const Vec3 &v)
		{
			out << v.x << ", " << v.y << ", " << v.z;
			return out;
		}

		// functions
		/*! Compares two vectors using tolerance parameter
		\param v Vector to compare
		\param tolerance Indicates how much vectors can differ to treat them as equal
		*/
		bool Equals(const Vec3<T> &v, T tolerance = 0.00001f) const
		{
			T xd = x - v.x;
			T yd = y - v.y;
			T zd = z - v.z;
			return (xd * xd + yd * yd + zd * zd) <= tolerance;
		}

		/*! Negates the vector components */
		void Negate() const
		{
			*this = -*this;
		}

		/*! Calculates the vector length */
		T Length() const
		{
			return std::sqrt(x * x + y * y + z * z);
		}

		/*! Calculates a dot product between two vectors
		\param v Second vector to calculate the Dot Product
		*/
		T Dot(const Vec3<T> &v) const
		{
			return(x * v.x + y * v.y + z * v.z);
		}

		/*! Calculates a cross product between two vectors
		\param v Second vector to calculate the Cross Product
		*/
		Vec3<T> Cross(const Vec3<T> &v) const
		{
			return Vec3<T>(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
		}

		/*! Normalizes the vector */
		void Normalize()
		{
			T magnitude = Length();
			if(magnitude > 0.0f)
			{
				(*this) *= static_cast<T>(1.0 / magnitude);
			}
			return magnitude;
		}

		/*! Projects the vector onto another one
		\param v Vector which the current vector will be projected on
		*/
		Vec3<T> ProjectOn(const Vec3<T> &v) const
		{
			T vLength = v.Length();
			return (this->Dot(v) / (vLength * vLength)) * v;
		}

		// vector components
		T x; //!< x component of a vector
		T y; //!< y component of a vector
		T z; //!< z component of a vector
};

typedef Vec3<float> Vec3f;	//!< 3d Vector of floats
typedef Vec3<double> Vec3d;	//!< 3d Vector of doubles
typedef Vec3<int> Vec3i;	//!< 3d Vector of integers
