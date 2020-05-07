class IntArray
{
	private native int sumArray(int[] arr);

	public static void main(String[] args)
	{
		IntArray iarr=new IntArray();
		int arr[]=new int[10];
		for(int i=0;i<10;i++)
		{
			arr[i]=i;
		}
		int sum=iarr.sumArray(arr);
		System.out.println("Sum= "+sum);
	}

	static
	{
		System.loadLibrary("sum");
	}
}
