// Lab Assignment 7 - Working with Class
// Electric_Field and Magnetic_Field classes

#include <iostream>   // output
#include <cmath>      // sqrt

using namespace std;

// Electric_Field
class Electric_Field
{
private:
    double *E;   // E[0] = x, E[1] = y, E[2] = z

public:
    // Default constructor: allocate 3 doubles, initialize to zero
    Electric_Field()
    {
        E = new double[3];
        E[0] = 0.0;
        E[1] = 0.0;
        E[2] = 0.0;
    }

    // Component constructor: allocate array and store supplied x, y, z
    Electric_Field(double x, double y, double z)
    {
        E = new double[3];
        E[0] = x;
        E[1] = y;
        E[2] = z;
    }

    // Copy constructor
    Electric_Field(const Electric_Field &other)
    {
        E = new double[3];
        for (int i = 0; i < 3; i++)
            E[i] = other.E[i];
    }

    // Copy assignment
    Electric_Field &operator=(const Electric_Field &other)
    {
        if (this != &other)
            for (int i = 0; i < 3; i++)
                E[i] = other.E[i];
        return *this;
    }

    // free the allocated array
    ~Electric_Field()
    {
        delete[] E;
    }

    // Getters
    double getX() const { return E[0]; }
    double getY() const { return E[1]; }
    double getZ() const { return E[2]; }

    // Setters
    void setX(double x) { E[0] = x; }
    void setY(double y) { E[1] = y; }
    void setZ(double z) { E[2] = z; }

    // |E| = sqrt(x^2 + y^2 + z^2)
    double calculateMagnitude() const
    {
        return sqrt(E[0] * E[0] + E[1] * E[1] + E[2] * E[2]);
    }

    // inner product E.E = Ex^2 + Ey^2 + Ez^2
    double calculateInnerProduct() const
    {
        return E[0] * E[0] + E[1] * E[1] + E[2] * E[2];
    }
};

// Magnetic_Field

class Magnetic_Field
{
private:
    double *B;   // B[0] = x, B[1] = y, B[2] = z

public:
    // Default constructor: allocate 3 doubles, initialize to zero
    Magnetic_Field()
    {
        B = new double[3];
        B[0] = 0.0;
        B[1] = 0.0;
        B[2] = 0.0;
    }

    // Component constructor: allocate array and store supplied x, y, z
    Magnetic_Field(double x, double y, double z)
    {
        B = new double[3];
        B[0] = x;
        B[1] = y;
        B[2] = z;
    }

    // Copy constructor
    Magnetic_Field(const Magnetic_Field &other)
    {
        B = new double[3];
        for (int i = 0; i < 3; i++)
            B[i] = other.B[i];
    }

    // Copy assignment
    Magnetic_Field &operator=(const Magnetic_Field &other)
    {
        if (this != &other)
            for (int i = 0; i < 3; i++)
                B[i] = other.B[i];
        return *this;
    }

    // free the allocated array
    ~Magnetic_Field()
    {
        delete[] B;
    }

    // Getters
    double getX() const { return B[0]; }
    double getY() const { return B[1]; }
    double getZ() const { return B[2]; }

    // Setters
    void setX(double x) { B[0] = x; }
    void setY(double y) { B[1] = y; }
    void setZ(double z) { B[2] = z; }

    // |B| = sqrt(x^2 + y^2 + z^2)
    double calculateMagnitude() const
    {
        return sqrt(B[0] * B[0] + B[1] * B[1] + B[2] * B[2]);
    }

    // Unit vector B-hat = (Bx/|B|, By/|B|, Bz/|B|), stored in out[0..2].
    void calculateUnitVector(double out[3]) const
    {
        double mag = calculateMagnitude();
        if (mag == 0.0)
        {
            out[0] = 0.0;
            out[1] = 0.0;
            out[2] = 0.0;
        }
        else
        {
            out[0] = B[0] / mag;
            out[1] = B[1] / mag;
            out[2] = B[2] / mag;
        }
    }
};

// main
int main()
{
    double unit[3];

    // default constructor
    Electric_Field E1;                        // (0, 0, 0)
    cout << "Electric field: Default constructor" << endl;
    cout << "E1 = (" << E1.getX() << ", " << E1.getY() << ", " << E1.getZ() << ")" << endl;
    cout << "Electric field magnitude: " << E1.calculateMagnitude() << endl;
    cout << "Electric field inner product: " << E1.calculateInnerProduct() << endl;
    cout << endl;

    // component constructor
    Electric_Field E2(3, 4, 5);
    cout << "Electric field: Component constructor" << endl;
    cout << "E2 = (" << E2.getX() << ", " << E2.getY() << ", " << E2.getZ() << ")" << endl;
    cout << "Electric field magnitude: " << E2.calculateMagnitude() << endl;
    cout << "Electric field inner product: " << E2.calculateInnerProduct() << endl;
    cout << endl;

    // after using setters
    E1.setX(1);
    E1.setY(2);
    E1.setZ(10.5);                           
    cout << "Electric field: After using setters (E1 is the new field)" << endl;
    cout << "E1 = (" << E1.getX() << ", " << E1.getY() << ", " << E1.getZ() << ")" << endl;
    cout << "Electric field magnitude: " << E1.calculateMagnitude() << endl;
    cout << "Electric field inner product: " << E1.calculateInnerProduct() << endl;
    cout << endl;

    // Magnetic field: default constructor
    Magnetic_Field B1;                        // (0, 0, 0)
    cout << "Magnetic field: Default constructor" << endl;
    cout << "B1 = (" << B1.getX() << ", " << B1.getY() << ", " << B1.getZ() << ")" << endl;
    cout << "Magnetic field magnitude: " << B1.calculateMagnitude() << endl;
    B1.calculateUnitVector(unit);
    cout << "Magnetic field unit vector: (" << unit[0] << ", " << unit[1] << ", " << unit[2] << ")" << endl;
    cout << endl;

    // component constructor
    Magnetic_Field B2(5, 2, 3);
    cout << "Magnetic field: Component constructor" << endl;
    cout << "B2 = (" << B2.getX() << ", " << B2.getY() << ", " << B2.getZ() << ")" << endl;
    cout << "Magnetic field magnitude: " << B2.calculateMagnitude() << endl;
    B2.calculateUnitVector(unit);
    cout << "Magnetic field unit vector: (" << unit[0] << ", " << unit[1] << ", " << unit[2] << ")" << endl;
    cout << endl;

    // after using setter
    B1.setX(5);
    B1.setY(6);
    B1.setZ(7);
    cout << "Magnetic field: After using setters (B1 is the new field)" << endl;
    cout << "B1 = (" << B1.getX() << ", " << B1.getY() << ", " << B1.getZ() << ")" << endl;
    cout << "Magnetic field magnitude: " << B1.calculateMagnitude() << endl;
    B1.calculateUnitVector(unit);
    cout << "Magnetic field unit vector: (" << unit[0] << ", " << unit[1] << ", " << unit[2] << ")" << endl;

    return 0;
}
