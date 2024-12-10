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

std::complex<float> newton(const std::vector<float> &coefficients, std::complex<float> initialGuess, float tolerance, int maxIterations)
{

 std::complex<float> x = initialGuess;

 for (int i = 0; i < maxIterations; ++i)
 {
		std::complex<float> fx = pluginEquation(coefficients, x);
		std::complex<float> fPrimeX = deriveEquation(coefficients, x);

		/*if (std::abs(fPrimeX) < 1e-10f) // Small derivative check
		{
			std::cerr << "Derivative is too small. Stopping to prevent division by zero." << '\n';
			break;
		}
*/
		std::complex<float> xNew = x - fx / fPrimeX;

		if (std::abs(xNew - x) < tolerance) // Convergence check
		{
			return xNew;
		}

		x = xNew;
 }

 return x; // Return last computed value
}

int main()
{
 int degree{};
 float tolerance = 1e-6f;
 std::complex<float> initialGuess = 0.001f;
 std::cout << "Enter the degree of the polynomial";
 std::cin >> degree;

 std::vector<float> coefficients(degree + 1);

 for (int i = degree; i >= 0; --i)
 {
		std::cout << "Enter coefficient of x^" << i << " ";
		std::cin >> coefficients[i];
 }
}
