#pragma once

#include <string>

namespace jnetwork
{

class Neuron
{
  public:
      explicit Neuron(const double value);

      void Activate();
      void Derive();

      void SetValue(const double value);

      double GetValue() const { return m_Value; }
      double GetActivatedValue() const { return m_ActivatedValue; }
      double GetDerivedValue() const { return m_DerivedValue; }

      std::string ToString() const;

  private:
    double m_Value;
    double m_ActivatedValue;
    double m_DerivedValue;
};

}
