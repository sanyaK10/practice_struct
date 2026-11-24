#include <iostream>
#include <cmath>
using namespace std;
//number 1
struct Point {
    int x;
    int y;
};
double distance(Point a, Point b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

//number 2
struct Fraction {
    int numerator;
    int denominator;
};
int nod(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
void reduce(Fraction& f) {
    int n = nod(abs(f.numerator), abs(f.denominator));
    f.numerator /= n;
    f.denominator /= n;
    if (f.denominator < 0) {
        f.numerator *= -1;
        f.denominator *= -1;
    }
}
Fraction add(Fraction a, Fraction b) {
    Fraction result;
    result.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    result.denominator = a.denominator * b.denominator;
    reduce(result);
    return result;
}
Fraction subtract(Fraction a, Fraction b) {
    Fraction result;
    result.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
    result.denominator = a.denominator * b.denominator;
    reduce(result);
    return result;
}
Fraction multiply(Fraction a, Fraction b) {
    Fraction result;
    result.numerator = a.numerator * b.numerator;
    result.denominator = a.denominator * b.denominator;
    reduce(result);
    return result;
}
Fraction divide(Fraction a, Fraction b) {
    Fraction result;
    result.numerator = a.numerator * b.denominator;
    result.denominator = a.denominator * b.numerator;
    reduce(result);
    return result;
}
void print(Fraction f) {
    cout << f.numerator << "/" << f.denominator << endl;
}


//number 3
struct WashingMachine {
    char firm[30];
    char color[20];
    float width;
    float length;
    float height;
    int power;
    int spinSpeed;
    int temperature;
};

//number 4
struct Animal {
    char name[30];
    int type;
    char nickname[30];
};
void fillAnimal(Animal& a) {
    cout << "Enter name: ";
    cin >> a.name;
    cout << "Choose type (1 - dog, 2 - cat, 3 - cow): ";
    cin >> a.type;
    cout << "Enter nickname: ";
    cin >> a.nickname;
}
void printAnimal(Animal a) {
    cout << "Name: " << a.name << "\n";
    cout << "Type: " << a.type << "\n";
    cout << "Nickname: " << a.nickname << "\n";
}
void makeSound(Animal a) {
    switch (a.type) {
    case 1:
        cout << "Woof!\n";
        break;
    case 2:
        cout << "Meow!\n";
        break;
    case 3:
        cout << "Moo!\n";
        break;
    default:
        cout << "Unknown sound!\n";
    }
}

//numbe r 5
union Number {
    int signedNumber;
    unsigned int unsignedNumber;
};

//number 6
struct Student {
    char name[50];
    unsigned int mark1 : 1;
    unsigned int mark2 : 1;
    unsigned int mark3 : 1;
    unsigned int mark4 : 1;
    unsigned int mark5 : 1;
    unsigned int mark6 : 1;
    unsigned int mark7 : 1;
    unsigned int mark8 : 1;
    unsigned int mark9 : 1;
    unsigned int mark10 : 1;
};

void fillStudent(Student& s) {
    cout << "Enter student name: ";
    cin >> s.name;
    int m1, m2, m3, m4, m5, m6, m7, m8, m9, m10;
    cout << "Enter 10 marks (1 - passed, 0 - not passed):\n";
    cin >> m1 >> m2 >> m3 >> m4 >> m5;
    cin >> m6 >> m7 >> m8 >> m9 >> m10;
    s.mark1 = m1;
    s.mark2 = m2;
    s.mark3 = m3;
    s.mark4 = m4;
    s.mark5 = m5;
    s.mark6 = m6;
    s.mark7 = m7;
    s.mark8 = m8;
    s.mark9 = m9;
    s.mark10 = m10;
}
void printStudent(Student s) {
    cout << "Name: " << s.name << "\n";
    cout << s.mark1 << " " << s.mark2 << " "
        << s.mark3 << " " << s.mark4 << " "
        << s.mark5 << " " << s.mark6 << " "
        << s.mark7 << " " << s.mark8 << " "
        << s.mark9 << " " << s.mark10 << "\n";
}
void printAverage(Student s) {
    int sum = s.mark1 + s.mark2 + s.mark3 + s.mark4 + s.mark5 +
        s.mark6 + s.mark7 + s.mark8 + s.mark9 + s.mark10;

    cout << "Average: " << sum / 10.0 << "\n";
}
void addStudent(Student students[], int& count) {
    fillStudent(students[count]);
    count++;
}
void setMarks(Student& s) {
    int m1, m2, m3, m4, m5, m6, m7, m8, m9, m10;
    cout << "Enter 10 marks:\n";
    cin >> m1 >> m2 >> m3 >> m4 >> m5;
    cin >> m6 >> m7 >> m8 >> m9 >> m10;
    s.mark1 = m1;
    s.mark2 = m2;
    s.mark3 = m3;
    s.mark4 = m4;
    s.mark5 = m5;
    s.mark6 = m6;
    s.mark7 = m7;
    s.mark8 = m8;
    s.mark9 = m9;
    s.mark10 = m10;
}

void printStudents(Student students[], int count) {
    for (int i = 0; i < count; i++) {
        printStudent(students[i]);
        cout << "\n";
    }
}
void printDebtors(Student students[], int count) {
    for (int i = 0; i < count; i++) {
        int sum = students[i].mark1 + students[i].mark2 +
            students[i].mark3 + students[i].mark4 +
            students[i].mark5 + students[i].mark6 +
            students[i].mark7 + students[i].mark8 +
            students[i].mark9 + students[i].mark10;
        if (sum < 10) {
            cout << students[i].name << "\n";
        }
    }
}



int main()
{
    //number 1
    //Point p1, p2;
    //cout << "Enter x and y for first point: ";
    //cin >> p1.x >> p1.y;
    //cout << "Enter x and y for second point: ";
    //cin >> p2.x >> p2.y;
    //cout << "Distance: " << distance(p1, p2)<<'\n';

    //number 2
    //Fraction a, b;
    //cout << "Enter first fraction: ";
    //cin >> a.numerator >> a.denominator;
    //cout << "Enter second fraction: ";
    //cin >> b.numerator >> b.denominator;
    //if (a.denominator == 0 || b.denominator == 0 || b.numerator == 0) {
    //    cout << "Error!";
    //}
    //cout << "Addition: ";
    //print(add(a, b));
    //cout << "Subtraction: ";
    //print(subtract(a, b));
    //cout << "Multiplication: ";
    //print(multiply(a, b));
    //cout << "Division: ";
    //print(divide(a, b));

    //number 3
    //WashingMachine machine;
    //cout << "Enter firm: ";
    //cin >> machine.firm;
    //cout << "Enter color: ";
    //cin >> machine.color;
    //cout << "Enter width: ";
    //cin >> machine.width;
    //cout << "Enter length: ";
    //cin >> machine.length;
    //cout << "Enter height: ";
    //cin >> machine.height;
    //cout << "Enter power: ";
    //cin >> machine.power;
    //cout << "Enter spin speed: ";
    //cin >> machine.spinSpeed;
    //cout << "Enter temperature: ";
    //cin >> machine.temperature;
    //cout << "\nWashing machine information:\n";
    //cout << "Firm: " << machine.firm << '\n';
    //cout << "Color: " << machine.color << '\n';
    //cout << "Width: " << machine.width << '\n';
    //cout << "Length: " << machine.length << '\n';
    //cout << "Height: " << machine.height << '\n';
    //cout << "Power: " << machine.power << '\n';
    //cout << "Spin speed: " << machine.spinSpeed << '\n';
    //cout << "Temperature: " << machine.temperature << '\n';

    //number 4
    //Animal a;

    //fillAnimal(a);

    //cout << "\nAnimal information:\n";
    //printAnimal(a);

    //cout << "Animal sound: ";
    //makeSound(a);

    //number 5
    //Number number;
    //number.signedNumber = -100;
    //cout << "Signed number: " << number.signedNumber << "\n";
    //cout << "Unsigned number: " << number.unsignedNumber << "\n";
    //number.unsignedNumber = 100;
    //cout << "Signed number: " << number.signedNumber << "\n";
    //cout << "Unsigned number: " << number.unsignedNumber << "\n";

    //number 6
    Student students[100];
    int count = 0;
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        addStudent(students, count);
    }
    cout << "\nAll students:\n";
    printStudents(students, count);
    cout << "\nDebtors:\n";
    printDebtors(students, count);
    cout << "\nAverage of first student:\n";
    if (count > 0) {
        printAverage(students[0]);
    }
}