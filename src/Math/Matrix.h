#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

namespace jnetwork
{
class Matrix
{
  public:
    Matrix(const size_t rowsCount, const size_t columnsCount);

    std::shared_ptr<Matrix> Transpose();

    void SetValue(const size_t rowsCount, const size_t columnsCount, const double value);
    double GetValue(const size_t rowsCount, const size_t columnsCount) const;

    void SetRandom(bool isRandom) { m_IsRandom = isRandom; }

    size_t GetColumnsCount() const { return m_ColumnsCount; }
    size_t GetRowsCount() const { return m_RowsCount; }

    bool IsRandom() const { return m_IsRandom; }

    std::string ToString() const;

  private:
    void InitMatrix();

  private:
    size_t m_RowsCount;
    size_t m_ColumnsCount;

    bool m_IsRandom = false;
    std::vector<std::vector<double>> m_Values;
};
} // namespace jnetwork