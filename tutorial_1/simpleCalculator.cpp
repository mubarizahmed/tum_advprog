#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

double sum(double a, double b) {
  return a + b;
}

double subtract(double a, double b) {
  return a - b;
}

double multiply(double a, double b) {
  return a * b;
}

double divide(double a, double b) {
  if (b != 0) {
    return a / b;
  } else {
    // error
    cout << "Error: Divide by 0 is undefined!" << endl;
    return 0;
  }
}

double mean(double a, double b) {
  return sum(a, b) / 2;
}

double square(double a) {
  return pow(a, 2);
}

double sin_x_pi(double a) {
  return sin(a * M_PI);
}

double cos_x_pi(double a) {
  return cos(a * M_PI);
}

double tan_x_pi(double a) {
  return tan(a * M_PI);
}

void base(double a, double b) {
  printf("%lf in base-%d is: ", a, (int)b);

  vector<int> digits;

  while (a != 0) {
    int remainder = (int)a % (int)b;
    a = (int)a / (int)b;
    digits.push_back(remainder);
  }

  for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
    printf("%d", *it);
  }
}

void getNumber(double* a) {
  printf("Enter one number: ");
  scanf("%lf", a);
}

void getNumbers(double* a, double* b) {
  printf("Enter two numbers: ");
  scanf("%lf %lf", a, b);
}

void menu() {
  printf("____Calculator____\n");

  while (true) {
    printf("Select op + - / * m [MEAN] 2 [SQUARE] s [SIN(PI*X)] c [COS(PI*X)] t [TAN(PI*X)] b [BASE]: ");
    char op;
    scanf(" %c", &op);

    double a, b, result;

    if (op == '+') {
      getNumbers(&a, &b);
      result = sum(a, b);
    } else if (op == '-') {
      getNumbers(&a, &b);
      result = subtract(a, b);
    } else if (op == '*') {
      getNumbers(&a, &b);
      result = multiply(a, b);
    } else if (op == '/') {
      getNumbers(&a, &b);
      result = divide(a, b);
    } else if (op == 'm') {
      getNumbers(&a, &b);
      result = mean(a, b);
    } else if (op == '2') {
      getNumber(&a);
      result = square(a);
    } else if (op == 's') {
      getNumber(&a);
      result = sin_x_pi(a);
    } else if (op == 'c') {
      getNumber(&a);
      result = cos_x_pi(a);
    } else if (op == 't') {
      getNumber(&a);
      result = tan_x_pi(a);
    } else if (op == 'b') {
      getNumbers(&a, &b);
      base(a, b);
      printf("\n\n");
      continue;
    } else {
      printf("Error: Select valid operator!\n\n");
      continue;
    }

    printf("Result = %lf \n\n", result);
  }
}

int main(int argc, char const* argv[]) {

  menu();
  return 0;
}
