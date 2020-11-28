import java.net.URL;
import javax.swing.*;
import java.awt.*;
import javax.swing.event.*;
import javax.swing.tree.*;
import java.awt.event.*;
import javax.swing.border.*;
import javax.swing.filechooser.FileFilter;
import java.io.*;
import java.lang.*;
import javax.swing.text.*;
import javax.swing.table.*;
public class javaedit extends JFrame 
{   //class 声明
	public class KeyLis extends KeyAdapter
	{public void keyPressed(KeyEvent e)
		{if(e.getKeyCode()==e.VK_F12)
                   (new Act_ji1()).actionPerformed(e_find);     		
		else if(e.isControlDown()&&e.getKeyCode()==e.VK_S)
		 (new Act_ji2()).actionPerformed(e_find);
                else if(e.isAltDown())
                (new Act_ji4()).actionPerformed(e_find);
                 else if(e.getKeyCode()==e.VK_F3)
                 (new Act_ji4_next()).actionPerformed(e_find);   
                  else if(e.getKeyCode()==e.VK_F4)
                 (new Act_ji5()).actionPerformed(e_find);   
              else if(e.isControlDown()&&e.getKeyCode()==e.VK_N)
                 (new Act_ji0()).actionPerformed(e_find);
                 else if(e.isControlDown()&&e.getKeyCode()==e.VK_E)
                 (new Act_ji3()).actionPerformed(e_find);
             else if(e.getKeyCode()==e.VK_F5)
             (new Act_ji7()).actionPerformed(e_find);
              else if(e.getKeyCode()==e.VK_F9)
              (new Act_ji6()).actionPerformed(e_find);
                 else if(e.isControlDown()&&e.getKeyCode()==e.VK_H)
                 (new Act_ji8()).actionPerformed(e_find);
           }
	 }
		
         public class WindowLis extends WindowAdapter
         {public void windowClosing(WindowEvent e)
          {JOptionPane.showMessageDialog(null,"Exit from xuhao's JavaEdit to Windows");
             dispose();
             System.exit(0);
          }
        }

	   class chooseFile extends JFileChooser{
            public chooseFile(){
	     super("/java");
             }
             public void approveSelection()
          {  if(file_control==0)
	      { 
	      	filename=Jfc.getSelectedFile().getName();
              directory[ja_control]=Jfc.getCurrentDirectory().toString();
             ja[ja_control].setText(null);	   
	   try{
	      BufferedReader breader=new BufferedReader(new FileReader(directory[ja_control]+"/"+filename));
	      while(true){
	      str=breader.readLine();
	      if(str==null)
	      break;
           ja[ja_control].append(str+'\n');
              }
             }     
           catch(Exception e_open)
            {
	   JOptionPane.showMessageDialog(Jf.getContentPane(),"读取发生错误");
             }
               }
	   else if(file_control==1)
	    {
	      filename=Jfc.getSelectedFile().getName();
             directory[ja_control]=Jfc.getCurrentDirectory().toString();
              try{
              fwrite=new FileWriter(directory[ja_control]+"/"+filename);
              fwrite.write(ja[ja_control].getText());
              fwrite.close();
                  }
             catch(Exception e_save)
            {
	     JOptionPane.showMessageDialog(Jf.getContentPane(),"读取发生错误");
             }
       
           }
                Jf.dispose();
                root.remove(node[ja_control]);
                node[ja_control]=new DefaultMutableTreeNode(filename);
                root.add(node[ja_control]);
	    	remove(tree);
	    	tree=new JTree(root);
	    	tree.setBackground(new Color(70,80,91));
	    	jsp_line.setRightComponent(tree);
	    	jsp_line.setDividerLocation(120);
	    	tab.setTitleAt(ja_control,filename);
	    	 logic[ja_control]=false;
                  }
          public void cancelSelection()
          {logic[ja_control]=true;
          	 Jf.dispose();
          }
         }
        class Filter extends FileFilter
           {public boolean accept(File file1)
          {
	  return(file1.getName().endsWith(".java")||file1.isDirectory()||file1.getName().endsWith(".html")||file1.getName().endsWith(".txt")||file1.getName().endsWith(".cpp"));
           }
          public String getDescription()
             {
	   return(".java,*.html,*.txt,*.cpp");
           }
           }
	   
	   class CaretLis_line implements CaretListener
	   {   public void caretUpdate(CaretEvent e) {
	   	
	   	try{
	   	line.setText("          Cursor at the "+(ja[ja_control].getLineOfOffset(ja[ja_control].getCaretPosition())+1)+" line in the file of "+tab.getTitleAt(ja_control));
	}
	      catch(BadLocationException eB)
	      { System.out.println("Io Wrong");
	      }      	
	   	}
	   }
	class CaretLis_err extends MouseAdapter
	   {   
             public void mouseClicked(MouseEvent e) 
            {  int off_err=err_ja.getCaretPosition();
	     int i=0;
            try{
             int index=-1;      
             int line_err=err_ja.getLineOfOffset(off_err-1);
             int start_err=err_ja.getLineStartOffset(line_err);
             String err_str=err_ja.getText(start_err,off_err-start_err);
             err_ja.select(start_err,off_err-1);
              for(i=0;i<1000;i++)
              { index=err_str.indexOf(":"+i+":");
               if(index>0)
                break;
              }
             if(index!=-1)
             {ja[ja_control].requestFocus();
              ja[ja_control].select(ja[ja_control].getLineStartOffset(i-1),ja[ja_control].getLineEndOffset(i-1));
             }
             }    
                                   

            catch(BadLocationException eB)
	      { System.out.println("Io Wrong");
	       }      	
               }
              }        
                
	   
	   class Changetab implements ChangeListener
	   {
	   	public void stateChanged(ChangeEvent e)
	   	{
                 ja_control=tab.getSelectedIndex();
                }
           }
             class Act_ji0 implements ActionListener
	    {public void actionPerformed(ActionEvent e_ji0)
	    {   root.add(node[tb]);
	    	remove(tree);
	    	tree=new JTree(root);
	    	tree.setBackground(new Color(70,80,91));  
                jsp_line.setRightComponent(tree);
	    	jsp_line.setDividerLocation(120);
	    	tab.addTab("File"+(tb+1),js[tb]);
	    	tab.setSelectedIndex(tb);
                 tb++;
            }
            }
         class Act_ji1 implements ActionListener
         {public void actionPerformed(ActionEvent e_ji1)
         {logic[ja_control]=false;
          file_control=0;
          Jfc.setApproveButtonText("OPEN");
          Jfc.addChoosableFileFilter(filter);
          Jf.getContentPane().add(Jfc);
          Jf.setSize(550,350);
          Jf.setTitle("Please Choose The File Your Want To Open!"); 
          Jf.setVisible(true);
          ja[ja_control].setCaretPosition(0);
          
          }
        }
        class Act_ji2 implements ActionListener
         {public void actionPerformed(ActionEvent e_ji2)
         { if(logic[ja_control])
         {	file_control=1;
         Jfc.setApproveButtonText("SAVE");
         Jfc.addChoosableFileFilter(filter);
          Jf.getContentPane().add(Jfc);
          Jf.setTitle("Please Input Your File's Name!"); 
          Jf.setSize(550,350);
          Jf.setVisible(true);
        
        
        }
        else
          {try{
              fwrite=new FileWriter(directory[ja_control]+"/"+tab.getTitleAt(ja_control));
              fwrite.write(ja[ja_control].getText());
              fwrite.close();
                  }
             catch(Exception e_save)
            {
	     JOptionPane.showMessageDialog(null,"读取发生错误");
             }
          }
                    
          }
        }
          class Act_ji3 implements ActionListener
         {public void actionPerformed(ActionEvent e_ji3)
         {         JOptionPane.showMessageDialog(null,"Exit from xuhao's JavaEdit to Windows");
              dispose();
             System.exit(0);
         
         
                }
        }
           class Act_ji4 implements ActionListener
       {public void actionPerformed(ActionEvent e_ji4)
          {    
          	find_word=JOptionPane.showInputDialog("Input the word your want to find!");
              if(find_word==null)
                    JOptionPane.showMessageDialog(null,"Can't find the word");
              else
              {  f_length=find_word.length(); 
               ja_text=ja[ja_control].getText();
               index=ja_text.indexOf(find_word);
               if(index<0)
               JOptionPane.showMessageDialog(null,"   The word is not in the file  ");
               else
               {ja[ja_control].requestFocus();
               ja[ja_control].select(index,index+f_length);}
            }
           }
        }
                   class Act_ji4_next implements ActionListener
       {
       	public void actionPerformed(ActionEvent e_ji4_next)
         { ja_text=ja[ja_control].getText();
              index=ja_text.indexOf(find_word,index+1);
           if(index<0)
               JOptionPane.showMessageDialog(null," Seeking has reached the end of the file ");
             else
              ja[ja_control].select(index,index+f_length);
         	 
           }
          }
          class Act_ji5 implements ActionListener
       {
       	public void actionPerformed(ActionEvent e_ji5)
        {   Object[] endButton1={"Replace","Cancel"};
             String message1="Are you sure to replace the word";
             ja_text=ja[ja_control].getText();
             String seek=JOptionPane.showInputDialog("Please input the word you want to seek");
             String replace=JOptionPane.showInputDialog("Please input the word you want to replace");
             if(seek!=null)
               { rp_length=seek.length(); 
                while(true){
                ja_text=ja[ja_control].getText();
                index=ja_text.indexOf(seek,index+rp_length);
                if(index<0)
                  {JOptionPane.showMessageDialog(null,"Seeking has reached the end of the file ");
                  break;}
                 else
              { ja[ja_control].requestFocus();
                ja[ja_control].select(index,index+rp_length);
                 JOptionPane end1=new JOptionPane(message1,JOptionPane.WARNING_MESSAGE,JOptionPane.DEFAULT_OPTION,null,endButton1);
                 JDialog endD1=end1.createDialog(end1,"请选择");
                 endD1.setVisible(true);
                 Object push1=end1.getValue();
                 if(push1==endButton1[0])
                  ja[ja_control].replaceSelection(replace);
              }          
               }
              }
               }     }                               


         class Act_ji6 implements ActionListener
       {
       	public void actionPerformed(ActionEvent e_ji6)
             {err_ja.setText(null);
           try
        {  
           int count;
            byte input[]=new byte[256];
            String InputString;
            String[] command = {"javac",directory[ja_control]+"/"+tab.getTitleAt(ja_control)};
            Process p = Runtime.getRuntime().exec(command);
            BufferedInputStream bufin=new BufferedInputStream(p.getErrorStream());
            bufin.mark(256);
            count=bufin.read(input);
             if(count<=0)
             err_ja.append("Compile to "+tab.getTitleAt(ja_control)+" Success");
           else 
            {InputString=new String(input,0,count); 
            err_ja.append("Compile to "+tab.getTitleAt(ja_control)+" Fail\n"+InputString);}
                }
        catch (IOException e)
        {
            System.err.println("IO error: " + e);
        }         
           
        }
        } 
        class Act_ji7 implements ActionListener
        {
        public void actionPerformed(ActionEvent e_ji7)
             {
             	err_ja.setText(null);
            if((tab.getTitleAt(ja_control)).indexOf(".java")>-1)
             {
               try
           {        int count;
            byte input[]=new byte[256];
            String InputString;
            String class_name;
            int length=(tab.getTitleAt(ja_control)).length();
            class_name=(tab.getTitleAt(ja_control)).substring(0,length-5);
             String[] command = {"java","-classpath",directory[ja_control],class_name};
            Process p = Runtime.getRuntime().exec(command);
            BufferedInputStream bufin=new BufferedInputStream(p.getErrorStream());
            bufin.mark(256);
            count=bufin.read(input);
             if(count<=0)
             err_ja.append("Build to "+tab.getTitleAt(ja_control)+" Success");
           else 
               {InputString=new String(input,0,count); 
               err_ja.append("Builld to "+tab.getTitleAt(ja_control)+" Fail\n"+InputString);}
                }
        catch (IOException e)
        {
            System.err.println("IO error: " + e);
        }         
        catch (IndexOutOfBoundsException e2)
        {
            System.err.println("IO error: " + e2);
        }}
        else
              err_ja.append(tab.getTitleAt(ja_control)+" is not a java File !\n Please Check it again!");
        }
        } 
        class Act_ji8 implements ActionListener
        {JTextArea ja_help=new JTextArea();
        public void actionPerformed(ActionEvent e_ji9)
         {JFrame jtable=new JFrame("Help");
            String[] field={"MenuItem","ShortCut Key"};
              Object[][] data=
                {{"     New           ","    Ctrl+N    "},
                 {"     Open          ","    F12       "},
                 {"    Save          ","    Ctrl+S    "},
                 {"    Exit          ","    Ctrl+X    "},
                 {"    Find          ","    Alt       "},
                 {"    Find Next     ","    F3        "},
                 {"    Compile       ","    F9        "},
                 {"    Build         ","    F5        "},
                 {"    Copy          ","    Ctrl+C    "},
                 {"    Cut           ","    Ctrl+X    "},
                 {"    Paste         ","    Ctrl+Y    "},
                 {"    Help          ","    Ctrl+H    "},
               }; 
           
           JTable jt=new JTable(data,field);
          jt.setFont(ft);
          ja_help.setFont(new Font("Courier",Font.TRUETYPE_FONT ,16));
          jtable.getContentPane().setLayout(new FlowLayout());
          jt.setForeground(Color.pink);
          ja_help.setForeground(Color.pink);
          jt.setBackground(new Color(70,80,91));
          jt.setSelectionBackground(new Color(70,80,91));
          ja_help.setBackground(new Color(70,80,91));
          ja_help.setText(" If you want to use this software with all functions,\n     You must do the things following:\n     1: install jdk_1.3 or Higher than it ;\n     2: set your classpath and path correctly;\n     3: if you want to use the compile and build functions,\n       you should save your edited File in the save directory\n       with  this software.\n      If you has some problem ,Mail to me !\n       My Email:wenzhouahao@sina.com.cn\n "  );
          jtable.getContentPane().add(new JScrollPane(jt,JScrollPane.VERTICAL_SCROLLBAR_ALWAYS,JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS));
          jt.setEnabled(false);
          jtable.getContentPane().add(new JScrollPane(ja_help,JScrollPane.VERTICAL_SCROLLBAR_ALWAYS,JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS));
          jtable.setVisible(true);
          jtable.setSize(500,790);
          jtable.requestFocus();
          jtable.setLocation(200,0);              
            }
       }
     
           
                                                    
           
               



        class Act_ji9 implements ActionListener
        {
        public void actionPerformed(ActionEvent e_ji9)
        {ja[ja_control].copy();
        }
        }
        class Act_ji10 implements ActionListener
        {
        public void actionPerformed(ActionEvent e_ji10)
        {ja[ja_control].cut();
        }
        }
        class Act_ji11 implements ActionListener
        {
        public void actionPerformed(ActionEvent e_ji11)
        {ja[ja_control].paste();
        }
        }
       class Act_time implements  ActionListener
       {
       	public void actionPerformed(ActionEvent e_time)
        {if(time_control>4)
          time_control=0;
          java.setIcon(new ImageIcon(loadImage("image/Juggler"+time_control+".gif")));
          time_control++;
        }
       }      
       class Act_stop implements  ActionListener
       {
       	public void actionPerformed(ActionEvent E_stop)
       	{	timer.stop();
          ji_start.setEnabled(true);
          ji_stop.setEnabled(false);
                }
       }
        
        class Act_start implements  ActionListener
       {
       	public void actionPerformed(ActionEvent E_start)
       	{	timer.start();
          ji_start.setEnabled(false);
          ji_stop.setEnabled(true);
                }
       }
        	
       
//临时变量
       
         ActionEvent e_find;
        int tb=1;
        int find_control=0;
        int ja_control=0;
        int file_control=0;
        boolean logic[]=new boolean[10];
        String filename;
        String directory[]=new String[10];
        String str;
        String find_word;
        int f_length;
        String ja_text;
        int index;
        int index_rp=-1; 
        int rp_length=0;
        int time_control=0;
//临时变量	
        Timer timer=new Timer(100,new Act_time());	
	JTree tree;
	JSplitPane jsp_V;
	JSplitPane jsp_H;
	JSplitPane jsp_line;
	JSplitPane jsp_java;
	JMenu jm1=new JMenu("File");
        JMenu jm2=new JMenu("Option");
	JMenu jm3=new JMenu("Advance");
	JMenu jm4=new JMenu("Help");
        JMenu jm5=new JMenu("Edit");         
        JMenuItem ji0=new JMenuItem("new");
        JMenuItem ji1=new JMenuItem("Open");
        JMenuItem ji2=new JMenuItem("Save");
        JMenuItem ji3=new JMenuItem("exit");
        JMenuItem ji4=new JMenuItem("Find");
        JMenuItem ji4_next=new JMenuItem("Find Next");
        JMenuItem ji5=new JMenuItem("Replace");
        JMenuItem ji6=new JMenuItem("Compile");
        JMenuItem ji7=new JMenuItem("Build");
        JMenuItem ji_stop=new JMenuItem("Stop Flash");
        JMenuItem ji_start=new JMenuItem("Start Flash");
        JMenuItem ji8=new JMenuItem("Help");
        JMenuItem ji9=new JMenuItem("Copy");
        JMenuItem ji10=new JMenuItem("Cut");
        JMenuItem ji11=new JMenuItem("Paste");
        JMenuBar  jb =new JMenuBar();
        JTextArea ja[]=new JTextArea[10];
        JTextArea err_ja=new JTextArea();
        JScrollPane  err_js;
        JScrollPane js[]=new JScrollPane[10];
        JTabbedPane tab=new JTabbedPane();
        JToolBar jtb=new JToolBar();
        JButton jb_open=new JButton(new ImageIcon(loadImage("image/open.gif")));
        JButton jb_new=new JButton(new ImageIcon(loadImage("image/new.gif")));
        JButton jb_save=new JButton(new ImageIcon(loadImage("image/save.gif")));
        JButton jb_help=new JButton(new ImageIcon(loadImage("image/help.gif")));
        JButton jb_exit=new JButton(new ImageIcon(loadImage("image/close.gif")));
        JButton jb_compile=new JButton(new ImageIcon(loadImage ("image/compile.gif")));
        JButton jb_build=new JButton(new ImageIcon(loadImage("image/build.gif")));
        JButton jb_copy=new JButton(new ImageIcon(loadImage("image/copy.gif")));
        JButton jb_cut=new JButton(new ImageIcon(loadImage("image/cut.gif")));
        JButton jb_paste=new JButton(new ImageIcon(loadImage("image/paste.gif")));
        JTextArea line=new JTextArea();
        JFrame Jf=new JFrame();
        JLabel java=new JLabel(new ImageIcon(loadImage("image/Juggler0.gif")));
        Filter filter=new Filter();
        chooseFile Jfc=new chooseFile();
        FileWriter fwrite;
        DefaultMutableTreeNode root;
        DefaultMutableTreeNode node[]=new  DefaultMutableTreeNode[10];
        Font ft=new Font("Courier",Font.TRUETYPE_FONT ,14);
       
          public javaedit()
           {     addKeyListener(new KeyLis());
        	addWindowListener(new WindowLis());
        	for(int i=0;i<10;i++)
                {node[i]=new DefaultMutableTreeNode("File"+(i+1));
                logic[i]=true;
                ja[i]=new JTextArea();
                	ja[i].setFont(ft);
                	ja[i].setCaretColor(Color.yellow);
                        ja[i].setBackground(new Color(70,80,91));
                        ja[i].setForeground(Color.pink);         
                        ja[i].addCaretListener(new CaretLis_line());   
                directory[i]=new String("/");            
                js[i]=new JScrollPane(ja[i],JScrollPane.VERTICAL_SCROLLBAR_ALWAYS,JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);}
                err_ja.setFont(ft);
                err_js=new JScrollPane(err_ja,JScrollPane.VERTICAL_SCROLLBAR_ALWAYS,JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
                err_ja.setForeground(new Color(200,150,10)); 
                err_ja.setBackground(new Color(70,80,91));
                err_ja.addMouseListener(new CaretLis_err()); 
                line.setEnabled(false);
                 line.setFont(ft);
                line.setBackground(new Color(70,80,91));
                line.setDisabledTextColor(Color.yellow);
                ji0.addActionListener(new Act_ji0());
                ji1.addActionListener(new Act_ji1());
                ji2.addActionListener(new Act_ji2());
                ji3.addActionListener(new Act_ji3());
                ji4.addActionListener(new Act_ji4());
                ji4_next.addActionListener(new Act_ji4_next());
                ji5.addActionListener(new Act_ji5());
                ji6.addActionListener(new Act_ji6());
                ji7.addActionListener(new Act_ji7());
                ji8.addActionListener(new Act_ji8());
                ji9.addActionListener(new Act_ji9());
                ji10.addActionListener(new Act_ji10());
                ji11.addActionListener(new Act_ji11());
                ji_stop.addActionListener(new Act_stop());
                ji_start.addActionListener(new Act_start());
                jb_new.addActionListener(new Act_ji0());
                jb_open.addActionListener(new Act_ji1());
                jb_save.addActionListener(new Act_ji2());
                jb_exit.addActionListener(new Act_ji3());
                jb_compile.addActionListener(new Act_ji6());
                jb_build.addActionListener(new Act_ji7());
                jb_help.addActionListener(new Act_ji8());
                jb_copy.addActionListener(new Act_ji9());
                jb_cut.addActionListener(new Act_ji10());
                jb_paste.addActionListener(new Act_ji11());
                root= new DefaultMutableTreeNode("File Visible");
                root.add(node[0]);
                tree=new JTree(root);
            	tree.setEditable(true);
                tree.setForeground(new Color(200,150,10));  
                tree.setBackground(new Color(70,80,91));
            	setJMenuBar(jb);
        	jm1.add(ji0);
        	jm1.add(ji1);
        	jm1.add(ji2);
        	jm1.add(ji3);
        	jm2.add(ji4);
        	jm2.add(ji4_next);
        	jm2.add(ji5);
        	jm3.add(ji6);
        	jm3.add(ji7);
        	jm3.addSeparator() ;
                jm3.add(ji_stop);
                jm3.add(ji_start);
                jm4.add(ji8);
        	jm5.add(ji9);
        	jm5.add(ji10);
        	jm5.add(ji11);
        	jb.add(jm1);
        	jb.add(jm2);
        	jb.add(jm3);
        	jb.add(jm5);
        	jb.add(jm4);
        	jb_new.setToolTipText("New");
        	jb_open.setToolTipText("Open");
        	jb_save.setToolTipText("Save");
        	jb_exit.setToolTipText("Exit");
        	jb_help.setToolTipText("Help");
        	jb_compile.setToolTipText("Compile");
        	jb_build.setToolTipText("Build");
        	jb_copy.setToolTipText("Copy");
        	jb_cut.setToolTipText("Cut");
        	jb_paste.setToolTipText("Paste");
        	ji_start.setEnabled(false);
        	jb_new.setBorder(new BevelBorder(BevelBorder.RAISED));
        	jb_open.setBorder(new BevelBorder(BevelBorder.RAISED));
        	jb_save.setBorder(new BevelBorder(BevelBorder.RAISED));
        	jb_exit.setBorder(new BevelBorder(BevelBorder.RAISED));
        	jb_help.setBorder(new BevelBorder(BevelBorder.RAISED));
        	jb_compile.setBorder(new BevelBorder(BevelBorder.RAISED));
        	jb_build.setBorder(new BevelBorder(BevelBorder.RAISED));
        	jb_cut.setBorder(new BevelBorder(BevelBorder.RAISED));
        	jb_copy.setBorder(new BevelBorder(BevelBorder.RAISED));
        	jb_paste.setBorder(new BevelBorder(BevelBorder.RAISED));
        	jtb.add(jb_new);
        	jtb.add(jb_open);
        	jtb.add(jb_save);
        	jtb.add(jb_copy);
        	jtb.add(jb_cut);
        	jtb.add(jb_paste);
        	jtb.add(jb_compile);
        	jtb.add(jb_build);
      		jtb.add(jb_exit);
      		jtb.add(jb_help);
                tab.addTab("File1",js[0]);
        	tab.addChangeListener(new Changetab());
        	jsp_line=new JSplitPane(JSplitPane.VERTICAL_SPLIT,true,java,tree);
        	jsp_java=new JSplitPane(JSplitPane.VERTICAL_SPLIT,true,tab,line);
        	jsp_H=new JSplitPane(JSplitPane.VERTICAL_SPLIT,true,jsp_java,err_js);
        	jsp_V=new JSplitPane(JSplitPane.HORIZONTAL_SPLIT,true,jsp_line,jsp_H);
        	jsp_V.setDividerLocation(150);
        	jsp_java.setDividerLocation(460);
        	jsp_H.setDividerLocation(500);
        	jsp_line.setDividerLocation(120);
        	getContentPane().setLayout(new BorderLayout());
        	getContentPane().add(jtb,BorderLayout.NORTH);     
        	getContentPane().add(jsp_V);
        	setLocation(135,0);
        setVisible(true);
        setSize(800,790);
        timer.start();
       }    
       public   static  void main(String args[])
       {new javaedit();
      
       } 
        private java.awt.Image loadImage(String name) {
           try {
	    java.net.URL url = getClass().getResource(name);
	    return createImage((java.awt.image.ImageProducer) url.getContent());
	} catch (Exception ex) {
	    return null;
	}
    }
  
  } 
           
        	
        	
        	
        	
