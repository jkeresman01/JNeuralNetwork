#include "../src/Math/Matrix.h"
#include <gtest/gtest.h>

using namespace jnetwork;

TEST(MatrixTest2x2, WillTranspose2x2MatrixCorrectly)
{
    // GIVEN
    Matrix originalMatrix(2, 2);

    originalMatrix.SetValue(0, 0, 1);
    originalMatrix.SetValue(0, 1, 2);
    originalMatrix.SetValue(1, 0, 3);
    originalMatrix.SetValue(1, 1, 4);

    // WHEN
    std::shared_ptr<Matrix> transposedMatrix = originalMatrix.Transpose();

    // THEN
    EXPECT_EQ(transposedMatrix->GetValue(0, 0), 1);
    EXPECT_EQ(transposedMatrix->GetValue(1, 0), 2);
    EXPECT_EQ(transposedMatrix->GetValue(0, 1), 3);
    EXPECT_EQ(transposedMatrix->GetValue(1, 1), 4);
}


TEST(MatrixTest2x3, WillTranspose2x3MatrixCorrectly)
{
    // GIVEN
    Matrix originalMatrix(2, 3);

    originalMatrix.SetValue(0, 0, 1);
    originalMatrix.SetValue(0, 1, 2);
    originalMatrix.SetValue(0, 2, 3);
    originalMatrix.SetValue(1, 0, 4);
    originalMatrix.SetValue(1, 1, 5);
    originalMatrix.SetValue(1, 2, 6);

    // WHEN
    std::shared_ptr<Matrix> transposedMatrix = originalMatrix.Transpose();

    // THEN
    EXPECT_EQ(transposedMatrix->GetValue(0, 0), 1);
    EXPECT_EQ(transposedMatrix->GetValue(1, 0), 2);
    EXPECT_EQ(transposedMatrix->GetValue(0, 1), 4);
    EXPECT_EQ(transposedMatrix->GetValue(1, 1), 5);
    EXPECT_EQ(transposedMatrix->GetValue(2, 0), 3);
    EXPECT_EQ(transposedMatrix->GetValue(2, 1), 6);
}

TEST(MatrixTest3x2, WillTranspose3x2MatrixCorrectly)
{
    // GIVEN
    Matrix originalMatrix(3, 2);

    originalMatrix.SetValue(0, 0, 1);
    originalMatrix.SetValue(0, 1, 2);
    originalMatrix.SetValue(1, 0, 3);
    originalMatrix.SetValue(1, 1, 4);
    originalMatrix.SetValue(2, 0, 5);
    originalMatrix.SetValue(2, 1, 6);

    // WHEN
    std::shared_ptr<Matrix> transposedMatrix = originalMatrix.Transpose();

    // THEN
    EXPECT_EQ(transposedMatrix->GetValue(0, 0), 1);
    EXPECT_EQ(transposedMatrix->GetValue(1, 0), 2);
    EXPECT_EQ(transposedMatrix->GetValue(0, 2), 5);
    EXPECT_EQ(transposedMatrix->GetValue(0, 1), 3);
    EXPECT_EQ(transposedMatrix->GetValue(1, 1), 4);
    EXPECT_EQ(transposedMatrix->GetValue(1, 2), 6);
}

TEST(MatrixTest4x4, WillTranspose4x4MatrixCorrectly)
{
    // GIVEN
    Matrix originalMatrix(4, 4);

    originalMatrix.SetValue(0, 0, 1);
    originalMatrix.SetValue(0, 1, 2);
    originalMatrix.SetValue(0, 2, 3);
    originalMatrix.SetValue(0, 3, 4);
    originalMatrix.SetValue(1, 0, 5);
    originalMatrix.SetValue(1, 1, 6);
    originalMatrix.SetValue(1, 2, 7);
    originalMatrix.SetValue(1, 3, 8);
    originalMatrix.SetValue(2, 0, 9);
    originalMatrix.SetValue(2, 1, 10);
    originalMatrix.SetValue(2, 2, 11);
    originalMatrix.SetValue(2, 3, 12);
    originalMatrix.SetValue(3, 0, 13);
    originalMatrix.SetValue(3, 1, 14);
    originalMatrix.SetValue(3, 2, 15);
    originalMatrix.SetValue(3, 3, 16);

    // WHEN
    std::shared_ptr<Matrix> transposedMatrix = originalMatrix.Transpose();

    // THEN
    EXPECT_EQ(transposedMatrix->GetValue(0, 0), 1);
    EXPECT_EQ(transposedMatrix->GetValue(0, 1), 5);
    EXPECT_EQ(transposedMatrix->GetValue(0, 2), 9);
    EXPECT_EQ(transposedMatrix->GetValue(0, 3), 13);

    EXPECT_EQ(transposedMatrix->GetValue(1, 0), 2);
    EXPECT_EQ(transposedMatrix->GetValue(1, 1), 6);
    EXPECT_EQ(transposedMatrix->GetValue(1, 2), 10);
    EXPECT_EQ(transposedMatrix->GetValue(1, 3), 14);

    EXPECT_EQ(transposedMatrix->GetValue(2, 0), 3);
    EXPECT_EQ(transposedMatrix->GetValue(2, 1), 7);
    EXPECT_EQ(transposedMatrix->GetValue(2, 2), 11);
    EXPECT_EQ(transposedMatrix->GetValue(2, 3), 15);

    EXPECT_EQ(transposedMatrix->GetValue(3, 0), 4);
    EXPECT_EQ(transposedMatrix->GetValue(3, 1), 8);
    EXPECT_EQ(transposedMatrix->GetValue(3, 2), 12);
    EXPECT_EQ(transposedMatrix->GetValue(3, 3), 16);
}
