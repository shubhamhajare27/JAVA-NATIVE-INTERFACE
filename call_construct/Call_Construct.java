class Demo
{
	int iNo1;
	int iNo2;

	public Demo(int iNo1,int iNo2)
	{
		System.out.println("Inside Constructor");
		this.iNo1=iNo1;
		this.iNo2=iNo2;
	}

	void Display()
	{
		System.out.println("iNo1 is "+this.iNo1+" And iNo2 is "+this.iNo2);
	}
}

class Call_Construct
{
	private native void call_construct(Demo dobj);

	public static void main(String arg[])
	{
		Demo dobj=new Demo(10,20);

		Call_Construct cobj=new Call_Construct();

		cobj.call_construct(dobj);
	}

	static
	{
		System.loadLibrary("call_construct");
	}
}
