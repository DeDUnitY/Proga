#include <iostream>

class Complex {
    double m_doub = 0;
    double m_comp = 0;
public:
    Complex() = default;

    Complex(double a, double b) : m_doub(a), m_comp(b) {}

    Complex(const Complex &z) : Complex(z.m_doub, z.m_comp) {}

    Complex &operator=(Complex z) {
        std::swap(m_doub, z.m_doub);
        std::swap(m_comp, z.m_comp);
        return *this;
    }

    void print() const {
        std::cout << m_doub << " " << m_comp << "i" << std::endl;
    }

    Complex &operator+=(const Complex &z) {
        (*this).m_doub += z.m_doub;
        (*this).m_comp += z.m_comp;
        return *this;
    }

    Complex operator+(const Complex &z) {
        Complex temp = *this;
        temp += z;
        return temp;
    }

    Complex &operator*=(const Complex &z) {
        Complex temp = *this;
        this->m_doub = temp.m_doub * z.m_doub - temp.m_comp * z.m_comp;
        this->m_comp = temp.m_doub * z.m_doub + temp.m_comp * z.m_comp;
        return *this;
    }

    Complex &operator*=(double z) {
        this->m_comp *= z;
        this->m_doub *= z;
        return *this;
    }

    Complex operator*(const Complex &z) {
        Complex temp = *this;
        temp *= z;
        return temp;
    }

    Complex &operator++() {
        this->m_doub += 1;
        return *this;
    }

    Complex operator++(int) {
        Complex temp = *this;
        this->m_doub += 1;
        return temp;
    }

    friend std::ostream &operator<<(std::ostream &output, Complex &z);

    friend std::istream &operator>>(std::istream &input, Complex &z);

    ~Complex() = default;
};

std::ostream &operator<<(std::ostream &output, Complex &z) {
    output << z.m_doub << " " << z.m_comp << "i";
    return output;
}

std::istream &operator>>(std::istream &input, Complex &z) {
    input >> z.m_doub >> z.m_comp;
    return input;
}

int main() {
    Complex a;
    Complex b(3, -1);
    Complex c(b);
    c += b;
    c.print();
    a = c + b;
    a.print();
    c *= b;
    std::cout << c << std::endl;
    Complex d;
    std::cin >> d;
    std::cout << d++ << std::endl;
    std::cout << d << std::endl;
}