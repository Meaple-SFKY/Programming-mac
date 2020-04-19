package src.learn.tes;

public class Racing
{
	private Person Jack;
	private Person John;
    private boolean JackEnd = false;
    private boolean JohnEnd = false;
    private int lineLength;
    public Racing()
    {
        Jack = new Person(this, 10, "Jack");
        John = new Person(this, 15, "John");
        setLineLength(100);
    }
 
    public void start()
    {
    	//开启Jack和John线程
        //补写代码区
        Thread threadJack = new Thread(Jack);
        Thread threadJohn = new Thread(Jack);
        threadJack.start();
        threadJohn.start();
    }
 
    public synchronized void end(Person person)
    {
    	//在Jack和John线程执行结束时可以调用该函数，使用JackEnd和JohnEnd标记，
    	//通过该标记也可以判断比赛者的名次
    	//若两个线程都结束，打印胜利者姓名
        //补写代码区
    }
    public static void main(String[] args)
    {
        Racing racing = new Racing();
        racing.start();
    }

	public int getLineLength() {
		return lineLength;
	}

	public void setLineLength(int lineLength) {
		this.lineLength = lineLength;
	}
}