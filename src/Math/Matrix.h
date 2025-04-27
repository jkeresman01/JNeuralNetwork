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
    Matrix(const uint32_t rowsCount, const uint32_t columnsCount);

    std::shared_ptr<Matrix> Transpose();

    void SetValue(const uint32_t rowsCount, const uint32_t columnsCount, const double value);
    double GetValue(const uint32_t rowsCount, const uint32_t columnsCount) const;

    void SetRandom(bool isRandom) { m_IsRandom = isRandom; }

    uint32_t GetColumnsCount() const { return m_ColumnsCount; }
    uint32_t GetRowsCount() const { return m_RowsCount; }

    bool IsRandom() const { return m_IsRandom; }

    std::string ToString() const;

  private:
    void InitMatrix();

  private:
    uint32_t m_RowsCount;
    uint32_t m_ColumnsCount;
    bool m_IsRandom = false;

    std::vector<std::vector<double>> m_Values;
};
} // namespace jnetwork