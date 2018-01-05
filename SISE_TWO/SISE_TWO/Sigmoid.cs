using System;

namespace Perceptron
{
    internal class Sigmoid
    {
        public static double Derivative(double x)
        {
            return (1 - x) * x;
        }

        public static double Func(double x)
        {
            return 1 / (1 + Math.Pow(Math.E, -x));
        }
    }
}