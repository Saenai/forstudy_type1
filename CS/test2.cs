namespace 自定义事件
{
    //事件传递参数类
    class AlarmEventArgs : EventArgs
    {
        public int numberOfThief;
        public AlarmEventArgs(int n)
        {
            numberOfThief = n;
        }
    }
    //事件触发类
    class Dog
    {
        //委托
        public delegate void AlarmEventHandler(Object sender, AlarmEventArgs e);
        //事件
        public event AlarmEventHandler Alarm;
        //处理事件传递参数的函数
        public void OnAlarm(AlarmEventArgs e)
        {
            if (this.Alarm != null)
            {
                Console.WriteLine("The dog is Wangwang...");
                this.Alarm(this, e);
            }
        }
    }
    //事件处理类
    class Host
    {
        //绑定事件触发类
        public Host(Dog dog)
        {
            dog.Alarm += new Dog.AlarmEventHandler(HostHandleEvent);
        }
        //事件处理
        public void HostHandleEvent(Object sender, AlarmEventArgs e)
        {
            Console.WriteLine("Host caught the thief! The sum is " + e.numberOfThief);
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Program is running...");
            Dog dog = new Dog();
            Host host = new Host(dog);
            Console.WriteLine("Someone is coming...");
            //向事件触发类传递事件传递参数从而引发和使用事件
            AlarmEventArgs alarmEventArgs = new AlarmEventArgs(3);
            dog.OnAlarm(alarmEventArgs);
            Console.ReadKey();
        }
    }
}