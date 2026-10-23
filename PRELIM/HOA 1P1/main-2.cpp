#include <iostream>

// Create a function that will take two numbers and display the sum.


int sumoftwonum( int fNum, int sNum){
    int sum = fNum + sNum;
    return sum;
}

int main() {
    int num1, num2;
    std::cout<<"Enter two numbers: ";
    std::cin >> num1 >> num2;
    std::cout << "The sum of the two numbers is: " << sumoftwonum(num1, num2) << std::endl;
    return 0;
}






// Create a function that will return whether variable A is greater than variable B.

class Triangle{
private:
    double totalAngle, angleA, angleB, angleC;

public:
    Triangle(double A, double B, double C);
    void setAngles(double A, double B, double C);
    const bool validateTriangle();
    };

Triangle::Triangle(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A+B+C;
}

void Triangle::setAngles(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A+B+C;

}
const bool Triangle::validateTriangle() {
    return (totalAngle <= 180);
}


int main(){
    //driver code
    Triangle set1(40, 30, 110);
    if(set1.validateTriangle()){
        std::cout << "The shape is a valid triangle.\n";
    } else {
        std::cout << "The shape is NOT a valid triangle.\n";
    }
    return 0;
}   





// Create a function that will take two Boolean values and display the result of all logical operations then return true if it was a success

int SumofTwoNum(int fNum, int sNum);
bool isGreaterThan(float num1, float num2); 
bool BooleanValues(bool A, bool B);

int SumofTwoNum(int fNum, int sNum) {
    return fNum + sNum;
}

bool isGreaterThan(float num1, float num2){
    return num1 > num2;
}

bool BooleanValues(bool A, bool B){
    std::cout<<"A and B: "<< (A && B)<<std::endl;
    std::cout<<"A or B: "<< (A || B)<<std::endl;
    std::cout<<"Not A: "<< (!A) <<std::endl;
    std::cout<<"Not B: "<< (!B) <<std::endl;
    std::cout<<"A xor B: "<< (A ^ B)<<std::endl;

    return true;
}

int main() {
    std::cout<<"The Sum of the Two Numbers is: "<<SumofTwoNum(6, 7)<<std::endl;
    std::cout<<"Is 1 Greater Than 2?: "<<isGreaterThan(1, 2)<<std::endl;   
    
    if(BooleanValues(true, false)){
        std::cout<<"Displaying All Logical Operations"<<std::endl;
    }
    return 0;
}









