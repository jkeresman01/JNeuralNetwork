#include "Neuron.h"

#include <cmath>
#include <sstream>

namespace jnetwork
{

Neuron::Neuron(const double value)
{
    SetValue(value);
}

void Neuron::SetValue(const double value)
{
    m_Value = value;

    Activate();
    Derive();
}

void Neuron::Activate()
{
    m_ActivatedValue = m_Value / (1 + abs(m_Value));
}

void Neuron::Derive()
{
    m_DerivedValue = m_ActivatedValue * (1 - m_ActivatedValue);
}

std::string Neuron::ToString() const
{
    std::stringstream ss;

    ss << "Value: " << m_Value << "\r\n";
    ss << "Activated value: " << m_ActivatedValue << "\r\n";
    ss << "Derived value: " << m_DerivedValue << "\r\n";

    return ss.str();
}

} // namespace jnetwork