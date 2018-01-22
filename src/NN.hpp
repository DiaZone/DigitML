
#ifndef NN_HPP
#define NN_HPP

#define INPUT_SIZE (28 * 28)
#define HIDDEN_SIZE 15
#define OUTPUT_SIZE 10

#include "../lib/matrix.h"
#include "dataset.hpp"
#include <cmath>

class NeuralNetwork {
    private:
        Matrix<double> weights1 = Matrix<double>(INPUT_SIZE, HIDDEN_SIZE),
                       weights2 = Matrix<double>(HIDDEN_SIZE, OUTPUT_SIZE);
        Matrix<double> bias1 = Matrix<double>(1, HIDDEN_SIZE), 
                       bias2 = Matrix<double>(1, OUTPUT_SIZE);
        
        double sigmoid(double x);
        double sigmoid_prime(double x);
		
		Matrix<unsigned char> feedForward(Matrix<unsigned char> input, Matrix<double> weights, Matrix<double> bias);
    public:
        NeuralNetwork() = default;
        NeuralNetwork(const NeuralNetwork& rhs) = default;
        virtual ~NeuralNetwork() = default;

		unsigned int compute(Matrix<double> firstLayer);
        // void train(Example e);
        
};

#include "NN.cpp"

#endif
