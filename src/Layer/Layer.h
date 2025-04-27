#pragma once

#include <cstdint>
#include <memory>
#include <vector>

#include "../Neuron/Neuron.h"

namespace jnetwork
{
class Layer
{
  public:
    explicit Layer(const uint32_t size);

  private:
    uint32_t m_Size;
    std::vector<std::shared_ptr<Neuron>> m_Neurons;
};
} // namespace jnetwork