#ifndef VECTOR_H
#define VECTOR_H


#include <stdexcept>
#include <array>
#include <random>


namespace linalg {

template<typename T>
concept numeric = std::is_arithmetic_v<T>;

template<numeric T, size_t N>
class Vector
{
public:
	Vector(bool is_row = false) : is_row(is_row) {}

	Vector(T nums[N])
	{
		data = std::to_array(nums);
	}

	Vector(std::initializer_list<T> init)
	{
		if (init.size() != N)
			throw std::invalid_argument("Initialiser list does not match size of vector");

		auto it = init.begin();
		for (size_t i = 0; i < N; ++i)
			data[i] = *it++;
	}

	size_t size() const { return N; }

	std::pair<int, int> Dim()
	{
		return std::pair(rows, cols);
	}

	static Vector random(double min = 0, double max = 1, bool is_row_vector = false)
	{
		std::default_random_engine re;
		std::uniform_real_distribution distribution(min, max);

		auto result = Vector<T, N>(is_row_vector);

		for (int i = 0; i < N; ++i)
		{
			if constexpr (std::is_same_v<T, double>)
				result[i] = distribution(re);
		}

		return result;
	}

	Vector<T, N> operator+(const Vector<T, N>& a) 
	{
		Vector<T, N> result = Vector<T, N>(is_row);
		for (int i = 0; i < size(); ++i)
		{
			result.data[i] = a.data[i] + data[i];
		}

		return result;
	}

	Vector<T, N> operator-(const Vector<T, N>& a) 
	{
		if (size() != a.size())
			throw std::runtime_error("Vector sizes are not equal."); // should this be compile time error?

		Vector<T, N> result = Vector<T, N>(is_row);
		for (int i = 0; i < size(); ++i)
		{
			result.data[i] = a.data[i] - data[i];
		}

		return result;
	}

	double dot(const Vector<T, N>& a)
	{
		
	}

	Vector<T, 3> cross(const Vector<T, 3>& other)
	{
		
	}

	T& operator[](int i)
	{
		if (i > data.size() - 1)
			throw std::out_of_range("Index is out of range");

		return data[i];
	}

private:
	std::array<T, N> data {};

	bool is_row = false;

	int rows = is_row ? 1 : N;

	int cols = is_row ? N : 1;
};



}

#endif






