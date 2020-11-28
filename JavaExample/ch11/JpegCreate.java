import java.io.*;
import java.util.*;
import com.sun.image.codec.jpeg.*;
import java.awt.image.*;
import java.awt.*;

public class JpegCreate {
 BufferedImage image;
 
 // 创建 jpg 文件到指定路径下
 public void createJpg(String path) {
   try {
     FileOutputStream fos = new FileOutputStream(path);
     BufferedOutputStream bos = new BufferedOutputStream(fos);
     JPEGImageEncoder encoder = JPEGCodec.createJPEGEncoder(bos);
     encoder.encode(image);
     bos.close(); 
   } catch(FileNotFoundException fnfe) {
     System.out.println(fnfe);
   } catch(IOException ioe) {
     System.out.println(ioe);
   }
 }  
 
 public static void main(String[] args) {
   int width=400, height=200;
   int xLength=300, yLength=150; 
   int count=5;
   
   Vector data=new Vector(); 
   data.addElement(new Integer(100));
   data.addElement(new Integer(120));
   data.addElement(new Integer(150));
   data.addElement(new Integer(40));
   data.addElement(new Integer(5));
   
   JpegCreate jg = new JpegCreate();
   jg.image = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB); 
   Graphics g = jg.image.getGraphics();
   
   // 画坐标
   g.setColor(Color.white);
   g.fillRect(0, 0, width, height);
   g.setColor(Color.blue);
   g.drawLine(10,height-10,10,height-10-yLength);
   g.drawLine(10,height-10,10+xLength,height-10);

   // 连线
   int yTo;
   int yFrom = ((Integer)(data.elementAt(0))).intValue();
   for (int i=1; i<count; i++) {
     yTo=((Integer)(data.elementAt(i))).intValue();
     g.drawLine(10+i*xLength/count,height-10,10+i*xLength/count,height-15);
     g.drawLine(10+(i-1)*xLength/count,yFrom,10+i*xLength/count,yTo);
     yFrom=yTo;
   }
   
   jg.createJpg("d:\\aaa.jpg"); 
 
 }
} 

 
 
