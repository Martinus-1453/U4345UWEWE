using SISE_TWO;
using System;
namespace CodingBackProp
{
    class Program
    {
        static void Main(string[] args)
        {
            NeuralNet network = new NeuralNet();
            network.GenerateRandom();
            network.Run(100000);
            Console.ReadKey();
        }
        
    }
}
