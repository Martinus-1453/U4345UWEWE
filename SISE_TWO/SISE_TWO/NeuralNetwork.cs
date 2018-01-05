using System;

namespace Perceptron
{
    internal class NeuralNetwork
    {
        private readonly double[] _expectedOutput;
        private readonly double[] _hiddenWeights;

        private readonly double[] _inputData;

        private readonly double[,] _inputWeights;
        private readonly double _learnRate;
        private readonly int _numInputData;
        private readonly int _numLearnNeurons;
        private readonly int _numNeurons;
        private readonly int _numOutputData;
        private readonly double[] _outputData;

        public NeuralNetwork()
        {
            _numNeurons = 100;
            _numInputData = 5;
            _numOutputData = 5;
            _numLearnNeurons = 8;
            _learnRate = 0.001;
            _inputData = new double[_numInputData];
            _expectedOutput = new double[_numOutputData];
            _inputWeights = new double[_numLearnNeurons, _numNeurons];
            _hiddenWeights = new double[_numNeurons];
            _outputData = new double[_numOutputData];
        }

        public void InitRandom()
        {
            var rand = new Random();
            for (var i = 0; i < _numInputData; i++)
            {
                //_inputData[i] = rand.Next(1, 100) + (double) rand.Next(1, 10) / 10;
                _inputData[i] = rand.NextDouble() * (100 - 1) + 1;
                _expectedOutput[i] = Math.Sqrt(_inputData[i]);
            }
            for (var i = 0; i < _numNeurons; i++)
                _hiddenWeights[i] = (rand.NextDouble() - 0.5) / 10.0;
            for (var i = 0; i < _numLearnNeurons; i++)
            for (var j = 0; j < _numNeurons; j++)
                _inputWeights[i, j] = (rand.NextDouble() - 0.5) / 10.0;
        }


        public void Execute(int iter)
        {
            for (var i = 0; i <= iter; i++)
            {
                var error = 0.0;
                for (var j = 0; j < _numInputData; j++)
                {
                    var values = new double[_numNeurons];
                    Train(j, values);
                    error += Math.Pow(_outputData[j] - _expectedOutput[j], 2);
                    AdjustWeights(j, values);
                }
                error = Math.Sqrt(error / _numInputData);

                for (var j = 0; j < _numInputData; j++)
                    if (i == 0 || i == 100 || i % 2000 == 0)
                        Console.WriteLine("Epoch: " + i + " initial input: " + _inputData[j].ToString("0.0000") +
                                          " expected: " + _expectedOutput[j].ToString("0.0000") + " computed: " +
                                          _outputData[j].ToString("0.0000") + " error " +
                                          Math.Abs((_expectedOutput[j] - _outputData[j]) / _outputData[j] * 100)
                                              .ToString("0.0000"));
            }
        }

        public void Train(int inputIndex, double[] inputs)
        {
            for (var i = 0; i < _numNeurons; i++) //neuron
            {
                inputs[i] = 0.0;
                for (var j = 0; j < _numLearnNeurons; j++) //weight
                    inputs[i] += _inputData[inputIndex] * _inputWeights[j, i];
                inputs[i] = Sigmoid.Func(inputs[i]);
            }
            _outputData[inputIndex] = 0.0;
            for (var i = 0; i < _numNeurons; i++)
                _outputData[inputIndex] += _hiddenWeights[i] * inputs[i];
        }

        public void AdjustWeights(int inputIndex, double[] inputs)
        {
            for (var i = 0; i < _numNeurons; i++)
            {
                _hiddenWeights[i] -= (_outputData[inputIndex] - _expectedOutput[inputIndex]) * inputs[i] * _learnRate;
                for (var j = 0; j < _numLearnNeurons; j++)
                    _inputWeights[j, i] -= (_outputData[inputIndex] - _expectedOutput[inputIndex]) *
                                          Sigmoid.Derivative(inputs[i]) * _hiddenWeights[i] * _outputData[inputIndex] *
                                          _learnRate;
            }
        }
    }
}