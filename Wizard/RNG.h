#pragma once
#include <random>
#include <cassert>
#include <type_traits>

class RNG
{
	std::mt19937 mt;

public:

	RNG()
		: mt{ std::random_device{}() }
	{
		mt.discard(700000);
	}

	template <typename NumberType>
	NumberType rand(NumberType min, NumberType max)
	{
		assert(min < max);

		if constexpr (std::is_floating_point<NumberType>())
		{
			std::uniform_real_distribution<float> ud(min, max);
			return ud(mt);
		}
		else if constexpr (std::is_integral<NumberType>())
		{
			std::uniform_int_distribution<NumberType> ud(min, max);
			return ud(mt);
		}
		else
		{
			assert(false);
		}
	}

	bool flip(float oddsOfTrue)
	{
		std::bernoulli_distribution distribution(oddsOfTrue);
		return distribution(mt);
	}
};