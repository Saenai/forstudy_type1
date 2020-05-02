using System;
namespace deltest
{
    class test
    {
        public delegate void TestDelegate(int i);
        static void Main(string[] args)
        {
            //调用委托方法
            TestDelegate d = new TestDelegate(PrintMessage1);
            d(0);
            d(1);
        }
        static void PrintMessage1(int i)
        {
            Console.WriteLine("第" + i + "个方法");
        }
    }
}