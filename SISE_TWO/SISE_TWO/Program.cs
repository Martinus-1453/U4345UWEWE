using System;
using Perceptron;

namespace ConsoleApp
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            var network = new NeuralNetwork();
            network.InitRandom();
            network.Execute(100000);
            Console.ReadKey();
        }
    }
}