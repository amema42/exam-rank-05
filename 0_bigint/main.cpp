#include "bigint.hpp"

int	main(void)
{
	const bigint	a(11012345);
	bigint			b(21), c, d(1337), e(d);
	bigint big(1);
	std::cout << "(big << 18) = " << (big << 18) << std::endl; // 1 seguito da 18 zeri

		
	// All are in base10
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;
	std::cout << "a + b = " << a + b << std::endl; // a + b = 63
	std::cout << "(c += a) = " << (c += a) << std::endl; // c = 42, donc (c += a) = 42
		
	std::cout << "\n\n" << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "++b = " << ++b << std::endl;
	std::cout << "b++ = " << b++ << std::endl;
	std::cout << "b = " << b << std::endl;
	int	i = 0;
	std::cout << "i = " << i << std::endl;
	std::cout << "++i = " << ++i << std::endl;
	std::cout << "i++ = " << i++ << std::endl;
	std::cout << "i = " << i << std::endl;

	std::cout << "\n\n" << std::endl;
	std::cout << "-------------------------------------------- " << b << std::endl;
	std::cout << "\"((b << 10) + 42)\" = " << ((b << 10) + 42) << std::endl;
	std::cout << "(d <<= 4) = " << (d <<= 4) << std::endl;
	std::cout << "(d >>= 2) = " << (d >>= 2) << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "(d < a) = " << (d < a) << std::endl;
	std::cout << "(d > a) = " << (d > a) << std::endl;
	std::cout << "(d == a) = " << (d == a) << std::endl;
	std::cout << "(d != a) = " << (d != a) << std::endl;
	std::cout << "(d == a) = " << (d == d) << std::endl;
	std::cout << "(d <= a) = " << (d <= a) << std::endl;
	std::cout << "(d >= a) = " << (d >= a) << std::endl;

	bigint x(1234);
	std::cout << std::endl;
	std::cout << "\"(x << 2)\"--> " << (x << 2) << "\n";   // prints 123400
	std::cout << "\"(x >>= 2)\"--> " << (x >>= 2) << "\n";   // prints   12

	std::cout << "\n\n- - - Extra Test - - - \n" << std::endl;

// Test dummy operator-
	bigint m(12345);
	bigint n(12345);
	std::cout << "m = " << m << ", n = " << n << std::endl;
	std::cout << "m - n = " << (m - n) << " (should be 0 if dummy)" << std::endl;

// Test >> vs >>=
	bigint shift1(123456789);
	bigint shift2 = shift1 >> 3;
	std::cout << "shift1 >> 3 = " << shift2 << " (shift1 unchanged: " << shift1 << ")" << std::endl;
	shift1 >>= 3;
	std::cout << "shift1 after >>= 3 = " << shift1 << std::endl;

// Test << with big shifts
	bigint huge(1);
	std::cout << "(1 << 10) = " << (huge << 10) << std::endl;  // should be 1 followed by 10 zeros
	std::cout << "(1 << 18) = " << (huge << 18) << std::endl;  // should be 1 followed by 18 zeros

// Comparison between very similar numbers
	bigint a1(1000);
	bigint a2(999);
	std::cout << "a1 = " << a1 << ", a2 = " << a2 << std::endl;
	std::cout << "a1 > a2: " << (a1 > a2) << std::endl;
	std::cout << "a1 == a2: " << (a1 == a2) << std::endl;
	std::cout << "a1 - a2 (if implemented): " << (a1 - a2) << std::endl;

// Zero subtraction edge case
	bigint zero1(0), zero2(0);
	std::cout << "0 - 0 = " << (zero1 - zero2) << std::endl;

// Comparison symmetry
	std::cout << "a1 >= a2: " << (a1 >= a2) << std::endl;
	std::cout << "a2 <= a1: " << (a2 <= a1) << std::endl;
	std::cout << "a2 < a1: " << (a2 < a1) << std::endl;
	std::cout << "a2 != a1: " << (a2 != a1) << std::endl;

	return (0);
}