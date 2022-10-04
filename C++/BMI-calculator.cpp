#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
    float weight, height, bmi;
    cout << "Enter your weight in kg: ";
    cin >> weight;
    cout << "Enter your height in m: ";
    cin >> height;
    bmi = weight / pow(height, 2);
    cout << "Your BMI is: " << bmi << endl;
    if (bmi < 18.5)
    {
        cout << "You are underweight";
 }
    else if (bmi >= 18.5 && bmi <= 24.9)
    {
        cout << "You are normal weight";
    }
    else if (bmi >= 25 && bmi <= 29.9)
    {
        cout << "You are overweight";}
    else
    {
        cout << "You are obese";}
    return 0;
}