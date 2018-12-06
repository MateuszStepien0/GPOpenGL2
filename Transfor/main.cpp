/// <summary>
/// Mateusz Stepien	
/// 12 hours
/// 
/// Bugs:
/// 
/// </summary>
#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 


#include "MyVector3.h"
#include "MyMatrix3.h"
#include <SFML\Graphics.hpp>
#include <string>


int main()
{
	MyMatrix3 matrix1{};
	MyMatrix3 matrix2{ 3, -1, 1, -15, 6, -5, 5, -2, 2 };

	MyVector3 vector1{ 2,3,4 };
	MyVector3 vector2{ 6,8,9 };
	MyVector3 vector3{ 5,7,1 };
	MyVector3 vector4{ 1,1,1 };

	MyMatrix3 matrix3{ vector1, vector2, vector3 };
	MyMatrix3 matrix4{ vector2, vector1, vector3 };

	std::cout << "Empty constructed matrix" << std::endl;
	std::cout << matrix1.toString() << std::endl << std::endl;

	std::cout << "Normally constructed matrix (inputted values)" << std::endl;
	std::cout << matrix2.toString() << std::endl << std::endl;

	std::cout << "Matrix made of vectors" << std::endl;
	std::cout << matrix3.toString() << std::endl << std::endl;

	bool equalityCheck = matrix3 == matrix2;

	std::cout << "Matrix2 == Matrix3" << std::endl;
	std::cout << "Check for equality: " << equalityCheck << std::endl << std::endl;

	std::cout << "Adding 2 matrices" << std::endl;
	MyMatrix3 matrixAdd = matrix3 + matrix4;

	std::cout << matrixAdd.toString() << std::endl << std::endl;

	std::cout << "Subtracting 2 matrices" << std::endl;
	MyMatrix3 matrixSub = matrix3 - matrix4;

	std::cout << matrixSub.toString() << std::endl << std::endl;

	std::cout << "Multiplying 2 matrices" << std::endl;
	MyMatrix3 matrixByMatrix = matrix3 * matrix4;

	std::cout << matrixByMatrix.toString() << std::endl << std::endl;

	std::cout << "Multiplying matrix by vector" << std::endl;
	MyVector3 matrixByVector = matrix3 * vector3;

	std::cout << matrixByVector.toString() << std::endl << std::endl;

	std::cout << "Multiplying matrix by scalar" << std::endl;
	MyMatrix3 matrixByScalar = matrix3 * 2.1;

	std::cout << matrixByScalar.toString() << std::endl << std::endl;

	std::cout << "Transpose of a matrix" << std::endl;
	MyMatrix3 matrixTranspose = matrix3.transpose();

	std::cout << matrixTranspose.toString() << std::endl << std::endl;

	std::cout << "Inverse of a matrix" << std::endl;
	MyMatrix3 matrixInverse = matrix2.inverse();

	std::cout << matrixInverse.toString() << std::endl << std::endl;

	std::cout << "Row 2 of matrix2" << std::endl;
	MyVector3 row2OfMatrix2 = matrix2.row(1);

	std::cout << row2OfMatrix2.toString() << std::endl << std::endl;

	std::cout << "Column 3 of matrix2" << std::endl;
	MyVector3 col2OfMatrix2 = matrix2.column(2);

	std::cout << col2OfMatrix2.toString() << std::endl << std::endl;

	std::cout << "Matrix Rotation on the x-axis" << std::endl;
	MyVector3 rotX = MyMatrix3::rotationX(PI / 2) * vector4;

	std::cout << rotX.toString() << std::endl << std::endl;

	std::cout << "Matrix Rotation on the y-axis" << std::endl;
	MyVector3 rotY = MyMatrix3::rotationY(PI / 2) * vector4;

	std::cout << rotY.toString() << std::endl << std::endl;

	std::cout << "Matrix Rotation on the z-axis" << std::endl;
	MyVector3 rotZ = MyMatrix3::rotationZ(PI / 2) * vector4;

	std::cout << rotZ.toString() << std::endl << std::endl;

	std::cout << "Matrix Translation" << std::endl;
	MyMatrix3 transMat = MyMatrix3::translation(MyVector3{ 5,6,1 });
	MyVector3 myNewPoint1 = transMat * MyVector3{ 2,2,1 };

	std::cout << myNewPoint1.toString() << std::endl << std::endl;

	std::cout << "Matrix Scaling" << std::endl;
	MyMatrix3 scalingMat = MyMatrix3::scale(3.0);
	MyVector3 myNewPoint2 = scalingMat * vector4;

	std::cout << myNewPoint2.toString() << std::endl << std::endl;

	std::system("pause");

	return EXIT_SUCCESS;
}