#include <iostream>
#include <vector>
#include <cmath>
#include <complex>

std::complex<float> pluginEquation(const std::vector<float> coefficients, std::complex<float> x)
{
 std::complex<float> result = 0;
 int degree = coefficients.size() - 1;
 for (int i = 0; i <= degree; i++)
 {
  result += coefficients[i] * std::pow(x, i);
 }
 return result;
}

std::complex<float> deriveEquation(const std::vector<float> coefficients, std::complex<float> x)
{
 std::complex<float> result = 0;
 int degree = coefficients.size() - 1;
 for (int i = 1; i <= degree; i++)
 {
  result += i * coefficients[i] * std::pow(x, i - 1);
 }
 return result;
}

int main()
{
 int degree{};

 std::cout << "Enter the degree of the polynomial";
 std::cin >> degree;

 std::vector<float> coefficients(degree + 1);

 for (int i = degree; i >= 0; --i)
 {
  std::cout << "Enter coefficient of x^" << i << " ";
  std::cin >> coefficients[i];
 }
}