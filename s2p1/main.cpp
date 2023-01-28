#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Encryption
{
private:
	std::vector <int> m_Fib;
	std::vector <int> m_key;
	std::string m_message = "";
	bool m_flag = 1;
	int num = 0;

	std::vector <std::string> processing_message(std::string message)
	{
		std::string temp,s;
		m_message = message;
		std::string word = "";
		std::vector <std::string> words;
		//std::cout << "Input message: ";
		//std::cin >> s;
		//m_message = "my Ivan. is Hello, name";

		for (int i = 0; i < m_message.size(); i++)
		{
			if (m_message[i] != ' ')
				word += m_message[i];
			else
			{
				words.push_back(word);
				word = "";
			}
			if (i == m_message.size()-1)
			words.push_back(word);
		}
		return words;
	}
public:
	Encryption(){}

	void InputKey()
	{
		std::vector <int> key;
		std::cout << "Input key len: ";
		std::cin >> num;
		std::cout << "Input key through \"Enter\": ";
		for (int i = 0; i < num; i++)
		{
			int num;
			std::cin >> num;
			if (num == 0)
				break;
			else
				key.push_back(num);
		}
		m_key = key;
	}

	void create_Fib(int num) {
		m_Fib.clear();
		m_Fib.push_back(1);
		m_Fib.push_back(2);
		for (int i = 2; i < num; i++)
		{
			m_Fib.push_back(m_Fib[i - 1] + m_Fib[i - 2]);
		}

	}

	int find_in_vector(std::vector <int> vec, int num) {
		for (int i = 0; i < vec.size(); i++) {
			if (vec[i] == num)
				return i;
		}
		return 0;
	}

	void print_vector(std::vector <int> vec) {
		for (int i = 0; i < vec.size(); i++) {
			std::cout << vec[i]<< " ";
		}
		std::cout << std::endl;
		
	}

	std::string Fusion(std::vector <std::string> message)
	{
		for (int i = 1; i < message.size(); i++)
		{
			message[0] += (" " + message[i]);
		}
		return message[0];
	}

	std::string encode(std::string messages)
	{
		int temp;
		create_Fib(m_key.size());
		std::vector <int> key = m_key;
		std::vector <std::string> message = processing_message(messages);

		if (Error(key, message) != "")
		{
			return "!ERROR!: " + Error(key, message);
		}
		int i = 0;

		while (key != m_Fib) {
			if (key[i] != m_Fib[i]) {
				temp = find_in_vector(key, m_Fib[i]);
				std::swap(m_Fib[i], m_Fib[temp]);
				std::swap(message[i], message[temp]);
			}
			if (i < key.size() - 1)
				i++;
			else i = 0;
		}
		return Fusion(message);

	}

	std::string decode(std::string messages)
	{
		int temp;
		create_Fib(m_key.size());
		std::vector <int> key = m_key;
		std::vector <std::string> message = processing_message(messages);

		if (Error(key, message) != "")
		{
			return "!ERROR!: " + Error(key, message);
		}
		int i = 0;

		while (key != m_Fib) {
			if (key[i] != m_Fib[i]) {
				temp = find_in_vector(key, m_Fib[i]);
				std::swap(key[i], key[temp]);
				std::swap(message[i], message[temp]);
			}
			if (i < key.size() - 1)
				i++;
			else i = 0;
		}
		return Fusion(message);

	}

	std::string Error(std::vector <int> key, std::vector <std::string> message)
	{
		sort(key.begin(), key.end());
		for (int i = 0; i < key.size(); i++)
		{
			if (key[i] == m_Fib[i])
				continue;
			else
				return "the key does not match the Fibonacci sequence";
		}

		if (message.size() > 30)
			return "invalid message size";

		if (message.size() < key.size())
			return "message size does not match key size";

		return "";
	}
};

int main()
{
	std::string str,res;
	
	Encryption code1;
	std::cout << "Input message: ";
	std::getline(std::cin, str);
	code1.InputKey();
	res = code1.encode(str);
	std::cout << "encode message: " << res << std::endl;
	std::cout << "decode message: " << code1.decode(res)<< std::endl;
	
	

}
