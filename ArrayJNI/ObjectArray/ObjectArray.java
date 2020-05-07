class ObjectArray{
	
	public static native int[][] twoDimensionalArray(int size);
	
	public static void main(String args[])
	{
		int arr[][]=twoDimensionalArray(3);

		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				System.out.println(" "+arr[i][j]);
			}
			System.out.println();
		}
	}

	static
	{
		System.loadLibrary("twosum");
	}
}
