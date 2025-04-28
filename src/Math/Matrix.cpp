#include "Matrix.h"

#include <sstream>

#include "../Common/Logger.h"
#include "../Utils/RandomUtil.h"

namespace jnetwork
{

Matrix::Matrix(const size_t rowsCount, const size_t columnsCount)
    : m_RowsCount(rowsCount), m_ColumnsCount(columnsCount)
{
    JNETWORK_INFO(TEXT("Initializing Matrix with size %d x %d", rowsCount, columnsCount));

    Random::Init();
    InitMatrix();
}

void Matrix::InitMatrix()
{
    JNETWORK_DEBUG("Initializing matrix values");

    m_Values.resize(m_RowsCount);

    for (size_t i = 0; i < m_RowsCount; ++i)
    {
        std::vector<double> coulumnValues(m_ColumnsCount, 0.00f);

        if (m_IsRandom)
        {
            JNETWORK_DEBUG(TEXT("Filling row %d with random values", i));
            std::generate(coulumnValues.begin(), coulumnValues.end(), []() { return Random::Generate(1); });
        }

        m_Values[i] = coulumnValues;
    }

    JNETWORK_INFO("Matrix initialized successfully");
}

std::shared_ptr<Matrix> Matrix::Transpose()
{
    JNETWORK_INFO("Transposing matrix of size %d x %d", m_RowsCount, m_ColumnsCount);

    std::shared_ptr<Matrix> transposedMatrix = std::make_shared<Matrix>(m_ColumnsCount, m_RowsCount);

    for (size_t i = 0; i < m_RowsCount; ++i)
    {
        for (size_t j = 0; j < m_ColumnsCount; ++j)
        {
            transposedMatrix->m_Values[j][i] = m_Values[i][j];
        }
    }

    JNETWORK_INFO("Matrix transposed successfully");

    return transposedMatrix;
}

void Matrix::SetValue(const size_t row, const size_t column, const double value)
{
    if (row >= m_RowsCount || column >= m_ColumnsCount)
    {
        JENTWORK_ERROR(
            TEXT("Invalid index (%d, %d) for SetValue: Index out of bounds", row, column));
        return;
    }

    JNETWORK_DEBUG(TEXT("Setting value at (%d, %d) to %f", row, column, value));
    m_Values[row][column] = value;
}

double Matrix::GetValue(const size_t row, const size_t column) const
{
    if (row >= m_RowsCount || column >= m_ColumnsCount)
    {
        JENTWORK_ERROR(
            TEXT("Invalid index (%d, %d) for GetValue: Index out of bounds", row, column));
        return 0.0f;
    }

    JNETWORK_DEBUG(TEXT("Getting value at (%d, %d)", row, column));
    return m_Values[row][column];
}

std::string Matrix::ToString() const
{
    std::stringstream ss;

    for (size_t i = 0; i < m_RowsCount; ++i)
    {
        for (size_t j = 0; j < m_ColumnsCount; ++j)
        {
            ss << m_Values[i][j] << "\t";
        }

        ss << "\r\n";
    }

    return ss.str();
}

} // namespace jnetwork
