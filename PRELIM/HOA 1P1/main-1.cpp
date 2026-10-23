#include <iostream>
#include <cmath>

// TASK 1 
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void task1() {
   
    int num1;
    int num2;

    std::cout << "--TASK 1: Swap Numbers--\n";
    std::cout << "Enter value for num1: ";
    std::cin >> num1;
    std::cout << "Enter value for num2: ";
    std::cin >> num2;

    std::cout << "Before swap: num1 = " << num1 << ", num2 = " << num2 << "\n";
    
    swap(num1, num2);
    
    std::cout << "After swap: num1 = " << num1 << ", num2 = " << num2 << "\n";

}

// TASK 2 
void task2() {
    double kelvin;
    std::cout << "--TASK 2: Kelvin to Fahrenheit--\n";
    std::cout << "Enter temperature in Kelvin: ";
    std::cin >> kelvin;

    double fahrenheit = (kelvin - 273.15) * 9.0/5.0 + 32.0;
    std::cout << kelvin << " K is equal to " << fahrenheit << " °F\n";
}

// TASK 3
void task3() {
    double x1, y1, x2, y2;
    std::cout << "--TASK 3: Distance between two points--\n";
    std::cout << "Enter coordinates of point 1 (x1 y1): ";
    std::cin >> x1 >> y1;
    std::cout << "Enter coordinates of point 2 (x2 y2): ";
    std::cin >> x2 >> y2;

    double distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    std::cout << "Distance between points: " << distance << "\n";
}

// TASK 4
void task4() {
    double a, b, c;
    std::cout << "--TASK 4: Area of a Triangle--\n";
    std::cout << "Enter lengths of the three sides of the triangle (a b c): ";
    std::cin >> a >> b >> c;

    double s = (a + b + c) / 2.0; // semi-perimeter
    double area = sqrt(s * (s - a) * (s - b) * (s - c));
    std::cout << "Area of the triangle: " << area << "\n";
}

// TASK 5
void task5() {
    double a, b, c;
    std::cout << "--TASK 5: Perimeter of a Triangle--\n";
    std::cout << "Enter lengths of the three sides of the triangle (a b c): ";
    std::cin >> a >> b >> c;

    double perimeter = a + b + c;
    std::cout << "Perimeter of the triangle: " << perimeter << "\n";
}

// TASK 6
void task6() {
    double a, b, c;
    std::cout << "--TASK 6: Triangle Type--\n";
    std::cout << "Enter lengths of the three sides of the triangle (a b c): ";
    std::cin >> a >> b >> c;

    // Check if it's a valid triangle
    if (a + b <= c || a + c <= b || b + c <= a) {
        std::cout << "Invalid triangle!\n";
        return;
    }

    // Determine the type of triangle
    double a2 = a * a;
    double b2 = b * b;
    double c2 = c * c;

    if (a2 == b2 + c2 || b2 == a2 + c2 || c2 == a2 + b2) {
        std::cout << "The triangle is right-angled.\n";
    } else if (a2 > b2 + c2 || b2 > a2 + c2 || c2 > a2 + b2) {
        std::cout << "The triangle is obtuse-angled.\n";
    } else {
        std::cout << "The triangle is acute-angled.\n";
    }
}

int main() {
    int choice;
    std::cout << "Select a program to run:\n";
    std::cout << "1 - Swap Numbers\n";
    std::cout << "2 - Kelvin to Fahrenheit\n";
    std::cout << "3 - Distance between two points\n";
    std::cout << "4 - Area of a Triangle\n";
    std::cout << "5 - Perimeter of a Triangle\n";
    std::cout << "6 - Classify Triangle\n";
    std::cout << "Enter choice (1-6): ";
    std::cin >> choice;

    switch(choice) {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        case 4:
            task4();
            break;
        case 5:
            task5();
            break;
        case 6:
            task6();
            break;
        default:
            std::cout << "Invalid choice!\n";
    }
    return 0;
}


