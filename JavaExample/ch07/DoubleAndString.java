class DoubleAndString 
{
	public static void main(String[] args) 
	{
		double d ; String s;

		//doubleת��string�ļ��ַ���
		d=3.14159;
		s = "" + d;
		s = Double.toString( d );
		s = new Double(d).toString();
		s = String.valueOf( d );

		// Stringת��double�ļ��ַ���
		s = "A3.14159";
		try{
			d = Double.parseDouble( s );
			d = new Double(s).doubleValue();
			d = Double.valueOf( s ).doubleValue();
		}
		catch(NumberFormatException e )
		{
			e.printStackTrace();
		}
	}
}
