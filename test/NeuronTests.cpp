#include "../src/Neuron/Neuron.h"
#include <gtest/gtest.h>

using namespace jnetwork;

TEST(NeuronTest, WillActivateCorrectly)
{
    // GIVEN
    double inputValue = 0.5;
    Neuron neuron(inputValue);

    // WHEN
    double expectedActivatedValue = inputValue / (1 + abs(inputValue));

    // THEN
    EXPECT_DOUBLE_EQ(neuron.GetActivatedValue(), expectedActivatedValue);
}

TEST(NeuronTest, WillDeriveCorrectly)
{
    // GIVEN
    double inputValue = 0.5;
    Neuron neuron(inputValue);

    // WHEN
    double expectedDerivedValue = neuron.GetActivatedValue() * (1 - neuron.GetActivatedValue());

    // THEN
    EXPECT_DOUBLE_EQ(neuron.GetDerivedValue(), expectedDerivedValue);
}
