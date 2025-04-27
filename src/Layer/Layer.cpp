#include "Layer.h"

namespace jnetwork
{
Layer::Layer(const uint32_t size) : m_Size(size)
{
    m_Neurons.reserve(size);

    for (size_t i = 0; i < size; ++i)
    {
        m_Neurons.emplace_back(std::make_shared<Neuron>(0.00f));
    }
}
} // namespace jnetwork