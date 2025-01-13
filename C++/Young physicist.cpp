#include <iostream>

class Vector3D {
public:
    int x, y, z;
    Vector3D(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    Vector3D() = default;
};

Vector3D rdVector() {
    int newX, newY, newZ;
    std::cin >> newX >> newY >> newZ;
    Vector3D newVector = Vector3D(newX, newY, newZ);
    return newVector;
}

Vector3D sum(Vector3D vector1, Vector3D vector2) {
    Vector3D vectorf = Vector3D();
    vectorf.x = vector1.x + vector2.x;
    vectorf.y = vector1.y + vector2.y;
    vectorf.z = vector1.z + vector2.z;

    return vectorf;
}

int main() {
    int n;
    std::cin >> n;
    Vector3D rvector = Vector3D();

    for (int i = 0; i < n; i++) {
        Vector3D newVector = rdVector();
        rvector = sum(rvector, newVector);
    }

    if (rvector.x == 0 &&
        rvector.y == 0 &&
        rvector.z == 0) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }

    return 0;
}
