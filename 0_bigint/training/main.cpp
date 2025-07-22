#include "bigint.hpp"
#include <iostream>

int main() {
	bigint a(42);
	bigint b(21), c, d(1337), e(d);
	bigint big(1);

	std::cout << "(big << 18) = " << (big << 18) << "\n\n";

	std::cout << "a = " << a << "\n";
	std::cout << "b = " << b << "\n";
	std::cout << "c = " << c << "\n";
	std::cout << "d = " << d << "\n";
	std::cout << "e = " << e << "\n\n";

	std::cout << "a + b = " << (a + b) << "\n";
	std::cout << "(c += a) = " << (c += a) << "\n\n";

	std::cout << "b = " << b << "\n";
	std::cout << "++b = " << ++b << "\n";
	std::cout << "b++ = " << b++ << "\n";
	std::cout << "b (after b++) = " << b << "\n\n";

	std::cout << "(b << 10) + 42 = " << ((b << 10) + 42) << "\n";
	std::cout << "(d <<= 4) = " << (d <<= 4) << "\n";
	std::cout << "(d >>= 2) = " << (d >>= 2) << "\n\n";

	std::cout << "a = " << a << "\n";
	std::cout << "d = " << d << "\n";
	std::cout << "(d < a) = " << (d < a) << "\n";
	std::cout << "(d <= a) = " << (d <= a) << "\n";
	std::cout << "(d > a) = " << (d > a) << "\n";
	std::cout << "(d >= a) = " << (d >= a) << "\n";
	std::cout << "(d == a) = " << (d == a) << "\n";
	std::cout << "(d != a) = " << (d != a) << "\n\n";

	bigint x(1234);
	std::cout << "(x << 2) = " << (x << 2) << "\n";
	std::cout << "(x >>= 2) = " << (x >>= 2) << "\n\n";

	std::cout << "--- Extra Tests ---\n";

	bigint m(12345), n(12345);
	std::cout << "m = " << m << ", n = " << n << "\n";
	std::cout << "m - n = " << (m - n) << " (dummy)\n\n";

	bigint shift1(123456789);
	std::cout << "shift1 >> 3 = " << (shift1 >> 3) << "\n";
	shift1 >>= 3;
	std::cout << "shift1 after >>= 3 = " << shift1 << "\n\n";

	bigint huge(1);
	std::cout << "(1 << 10) = " << (huge << 10) << "\n";
	std::cout << "(1 << 18) = " << (huge << 18) << "\n\n";

	bigint a1(1000), a2(999);
	std::cout << "a1 = " << a1 << ", a2 = " << a2 << "\n";
	std::cout << "a1 > a2: " << (a1 > a2) << "\n";
	std::cout << "a1 == a2: " << (a1 == a2) << "\n";
	std::cout << "a1 - a2 (dummy): " << (a1 - a2) << "\n\n";

	bigint z1(0), z2(0);
	std::cout << "0 - 0 = " << (z1 - z2) << "\n";

	std::cout << "a1 >= a2: " << (a1 >= a2) << "\n";
	std::cout << "a2 <= a1: " << (a2 <= a1) << "\n";
	std::cout << "a2 < a1: " << (a2 < a1) << "\n";
	std::cout << "a2 != a1: " << (a2 != a1) << "\n";

	return 0;
}
