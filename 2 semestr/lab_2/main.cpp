#include <iostream>
#include <cstring>

class String {
    size_t m_size;
    char *m_str = nullptr;
public:
    String() = default;

    String(const char *str) : m_size(strlen(str)), m_str(new char[m_size + 1]) {
        std::copy(str, str + m_size + 1, m_str);
    }

    String(const String &other) : String(other.m_str) {
    }

    String &operator=(const String &other) {
        if (m_str != nullptr)
            delete[] m_str;
        m_size = other.m_size;
        m_str = new char[m_size + 1];
        std::copy(other.m_str, other.m_str + m_size + 1, m_str);
        return *this;
    }

    String &operator+=(const String &other) {
        m_size = m_size + other.m_size;
        auto temp = m_str;
        m_str = new char[m_size + 1];
        std::copy(temp, temp + strlen(temp), m_str);
        std::copy(other.m_str, other.m_str + other.m_size + 1, m_str + strlen(temp));
        delete[] temp;
        return *this;
    }

    String operator+(const String &other) {
        String temp;
        temp = *this;
        temp += other;

        return temp;
    }

    char &operator[](int index) {
        return m_str[index];
    }

    char &at(int index) {
        if (0 <= index && index < m_size)
            return m_str[index];
    }

    bool operator==(const String &other) {
        return std::strcmp(m_str, other.m_str) == 0;
    }

    bool operator>(const String &other) {
        return std::strcmp(m_str, other.m_str) > 0;
    }

    bool operator<(const String &other) {
        return std::strcmp(m_str, other.m_str) < 0;
    }


    char *Find(const char &need) {
        for (int i = 0; i < m_size; i++) {
            if (m_str[i] == need) {
                return (char *) m_str[i];
            }
        }
    }


    char *C_str() {
        return m_str;
    }

    size_t length() const {
        return m_size;
    }

    void print() const {
        for (int i = 0; i < m_size; i++)
            std::cout << m_str[i];
        std::cout << std::endl;
    }


    ~String() {
        if (m_str != nullptr)
            delete[] m_str;
    }

    friend std::ostream &operator<<(std::ostream &out, const String &str);

    friend std::istream &operator>>(std::istream &in, String &str);
};

std::ostream &operator<<(std::ostream &out, const String &str) {
    out << str.m_str;
    return out;
}

std::istream &operator>>(std::istream &in, String &str) {
    char *temp = new char[1000000000];
    in >> temp;
    str.m_size = strlen(temp);
    str.m_str = new char[str.m_size + 1];
    std::copy(temp, temp + strlen(temp) + 1, str.m_str);
    delete[] temp;
    return in;
}

int main() {
    String s("Hello, world!");
    s.print();
    String s1(" 111111111");
    s += s1;
    s.print();
    String s2;
    s2 = s + s1;
    s2.print();
    char z = s2[7];
    std::cout << s2[7] << "\t" << z << "\n";
    String s3;
    std::cin >> s3;
    std::cout << s3;
    return 0;
}