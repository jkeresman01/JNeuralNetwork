#include "NeuralNetwork.h"

namespace jnetwork
{
NeuralNetwork::NeuralNetwork(const std::vector<uint32_t> &topology)
    : m_Topology(topology), m_TopologySize(topology.size())
{
    InitLayers();
    InitMatrices();
}

void NeuralNetwork::InitLayers()
{
    m_Layers.reserve(m_TopologySize);

    for (size_t i = 0; i < m_TopologySize; ++i)
    {
        m_Layers.emplace_back(std::make_unique<Layer>(m_TopologySize));
    }
}

void NeuralNetwork::InitMatrices()
{
    m_Matrices.reserve(m_TopologySize);

    for (size_t i = 0; i < m_TopologySize - 1; ++i)
    {
        std::shared_ptr<Matrix> matrix = std::make_shared<Matrix>(m_Topology[i], m_Topology[i + 1]);
        matrix->SetRandom(true);

        m_Matrices.emplace_back(matrix);
    }
}

std::string NeuralNetwork::ToString() const
{
    // TODO
    return std::string();
}

} // namespace jnetwork