import java.io.*;
import java.awt.*;

public class FileDisplay{
	public static void main(String args[]){
		Frame f = new Frame("test for filedialog");
		TextArea text = new TextArea(40,40);
		f.add( text );
		f.setSize(600,500);
		f.setVisible(true);
		
		FileDialog fd=new FileDialog(f,"�ļ��Ի���",FileDialog.LOAD);
		fd.setVisible(true);
		String fpath=fd.getDirectory();
		String fname=fd.getFile();
		String si=fpath+fname;
		
		File file = new File(si);  
		try {
			BufferedReader in = new BufferedReader(new FileReader(file));
			String s;
			s = in.readLine();
			while ( s != null ) {
				s = in.readLine();
				text.append( s + "\n" );
			}
			in.close();
		} catch (IOException e2) {
			e2.printStackTrace();
		}	
	}
}