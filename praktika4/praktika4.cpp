#include <iostream>
#include <string>
#include <vector>

// x |= (1 << n); записать 1 в бит Н
// x &= ~(1 << n); записать 0
// if (x & (1 << 2)) {  /* во второй бит вписана единица */ }

#define bit 4

std::vector<int> to_bin(int n)  // возвращает перевёрнутое число
{
	std::vector<int> end;
	end.resize(bit);
	end.clear();
	while (n > 0) {
		end.push_back(n % 2);
		n /= 2;
	}
	while (end.size() < bit)
		end.push_back(0);
	return end;
}

int to_dec(std::vector<int> n) {  // возвращает число
	int end = 0;
	for (int i = 0; i < bit; i++) {
		end += n[i] * pow(2, i);
	}
	return end;
}

int get_num(unsigned long long c, int n) {
	std::vector<int> num;
	num.resize(bit);
	num.clear();
	std::vector<int> buf;
	buf.resize(bit);
	buf.clear();
	for (int i = 0; i < bit; i++) {
		//std::cout << n * bit + i << "\n";
		if (c & (1 << (n * bit + i))) {
			num.push_back(1);
		}
		else num.push_back(0);
	}
	for (int i = 0; i < bit; i++) {
		buf.push_back(num[bit - i - 1]);
		//std::cout << buf[i] << "\n";
	}
	return to_dec(buf);
}

void give_num(unsigned long long& x, int n, int num) {
	std::vector buf = to_bin(num);
	std::vector<int> nums;
	nums.resize(bit);
	nums.clear();
	for (int i = 0; i < bit; i++) {
		nums.push_back(buf[bit - i - 1]);
	}

	for (int i = 0; i < bit; i++) {
		if (nums[i]) {
			x |= (1 << (bit * n + i));
		}
		else x &= ~(1 << (bit * n + i));
	}
}


int main() {
	/*std::vector <int> test(bit);
	test = to_bin(63);
	for (int i = 0; i < test.size(); i++)
		std::cout << test[test.size() - i-1] << "\n";
	std::cout << to_dec(to_bin(63));*/
	unsigned long long c = 0;
	give_num(c, 0, 0);
	give_num(c, 1, 10);
	std::cout << get_num(c, 1) << "\n";
	std::cout << get_num(c, 0);
}