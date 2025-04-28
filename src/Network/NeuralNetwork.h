#pragma once

#include <memory>
#include <string>
#include <vector>

#include "../Layer/Layer.h"
#include "../Math/Matrix.h"
#include "../Neuron/Neuron.h"

namespace jnetwork
{
class NeuralNetwork
{
  public:
    explicit NeuralNetwork(const std::vector<uint32_t> &topology);

    std::string ToString() const;

  private:
    void InitLayers();
    void InitMatrices();

  private:
    std::vector<uint32_t> m_Topology;
    uint32_t m_TopologySize;

    std::vector<std::unique_ptr<Layer>> m_Layers;
    std::vector<std::shared_ptr<Matrix>> m_Matrices;
};
} // namespace jnetwork