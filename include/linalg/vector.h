#ifndef VECTOR_H
#define VECTOR_H

#include <type_traits>

namespace linalg
{
	template<typename T>
	class Vector
	{
	public:
		Vector<T> operator+(const Vector<T>& a);


	private:
		static_assert(std::is_arithmetic_v, "T must be a numeric type");
		T data[];


	};
}


#endif






