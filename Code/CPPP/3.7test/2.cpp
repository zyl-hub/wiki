#include <iostream>
using namespace std;

void BMI(double, double, double);

int main()
{
    double heightFoot = 0;
    double heightInches = 0;
    double Weight = 0;
    cout << "Please Input Your Height and Weight:";
    cin >> heightFoot >> heightInches >> Weight;

    BMI(heightFoot, heightInches, Weight);

    return 0;
}

void BMI(double heightFoot, double heightInches, double Weight)
{
    cout << "Your BMI is " << (Weight/2.2)/((heightFoot*12 + heightInches)*0.0254)*((heightFoot*12 + heightInches)*0.0254);
}
