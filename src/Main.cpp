#include <iostream>

#include "Math/Matrix.h"


int main()
{
    jnetwork::Matrix originalMatrix(2, 3);

    originalMatrix.SetValue(0, 0, 1);
    originalMatrix.SetValue(0, 1, 2);
    originalMatrix.SetValue(0, 2, 3);
    originalMatrix.SetValue(1, 0, 4);
    originalMatrix.SetValue(1, 1, 5);
    originalMatrix.SetValue(1, 2, 6);

    std::cout << "Original matrix" << std::endl;
    std::cout << originalMatrix.ToString() << std::endl;

    std::shared_ptr<jnetwork::Matrix> transposedMatrix = originalMatrix.Transpose();

	std::cout << "Transposed matrix" << std::endl;
    std::cout << transposedMatrix->ToString() << std::endl;


}
