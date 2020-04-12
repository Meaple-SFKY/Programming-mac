package src.learn.exercise9;

import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.net.*;
import javax.swing.*;

class ServerFrame extends Frame {
    /**
     *
     */
    private static final long serialVersionUID = 1L;
    
    ServerSocket server = null;
    Socket client = null;
    private String name;
    TextField port = new TextField("8000");
    Button start = new Button("Start");
    TextArea sTextArea = new TextArea(30, 60);
    JFileChooser sFileChooser = new JFileChooser();
    Button choose = new Button("Choose File");
    TextField chooseFile = new TextField(40);
    Button send = new Button("send");
    SListener sListener = new SListener();

    public ServerFrame(String title) {
        super(title);
        init();

        start.addActionListener(sListener);
        send.addActionListener(sListener);
        sFileChooser.setCurrentDirectory(new File("."));
        choose.addActionListener(event -> {
            int result = sFileChooser.showOpenDialog(null);

            if (result == JFileChooser.APPROVE_OPTION) {
                name = sFileChooser.getSelectedFile().getPath();
                chooseFile.setText(name);
            }
        });

        addWindowListener(
			new WindowAdapter()	{
	    		public void windowClosing(WindowEvent e) {
		    			try	{
		    				server.close();
		    			} catch(Exception ee) {
		    				ee.printStackTrace();
		    			}
		     			System.exit(0);
	    		}
	   		}
	   	);
   		this.setVisible(true);
    }

    void init() {
        setLocation(1200, 100);
        setSize(400, 400);
        setResizable(false);
        setBackground(Color.DARK_GRAY);
        sTextArea.setBackground(Color.GRAY);

        Panel North = new Panel();
        North.add(new Label("Port"));
        North.add(this.port);
        North.add(this.start);
        this.add(North, BorderLayout.NORTH);

        Panel Center = new Panel();
        Center.add(this.sTextArea);
        this.add(Center, BorderLayout.CENTER);

        Panel South = new Panel();
        South.add(this.choose);
        South.add(this.chooseFile);
        South.add(this.send);
        this.add(South, BorderLayout.SOUTH);

        pack();
    }

    class SListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            String string = e.getActionCommand();
            if ("Start" == string) {
                try {
                    start.setEnabled(false);
                    int i = Integer.parseInt(port.getText());
                    sTextArea.append("Socket Port: " + port.getText() + "\n");
                    server = new ServerSocket(i);
                    client = server.accept();
                    sTextArea.append("A Client is Connecting ...\n");

                    ServerThread serverThread = new ServerThread();
                    serverThread.start();
                } catch(Exception ce) {
                    ce.printStackTrace();
                }
            }
            else if ("Send" == string) {
                try {
                    String str = chooseFile.getText();
                    PrintWriter ss = new PrintWriter(client.getOutputStream());
                    if (str != "") {
                        sTextArea.append("Server: " + str + "\n");
                        ss.write("Server: " + str + "\n");
                        ss.flush();
                    }
                    chooseFile.setText("");
                } catch(Exception se) {
                    se.printStackTrace();
                }
            }
        }
    }

    class ServerThread extends Thread {
        public void run() {
            try {
                BufferedReader br = new BufferedReader(new InputStreamReader(client.getInputStream()));
                String s = br.readLine();
                while (!"Client: Quit".equals(s) && s != null) {
                    sTextArea.append(s + "\n");
                    s = br.readLine();
                }
            } catch(Exception re) {
                re.printStackTrace();
            }
        }
    }
}

public class FileServer {
    public static void main(String[] args) {
        ServerFrame serverFrame = new ServerFrame("Server");
    }
}