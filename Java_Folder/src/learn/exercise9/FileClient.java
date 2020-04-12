package src.learn.exercise9;

import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.net.*;
import javax.swing.*;

class ClientFrame extends JFrame {
    /**
     *
     */
    private static final long serialVersionUID = 1L;
    
    Socket client = null;
    private String name;
    TextField ip = new TextField("127.0.0.1");
    TextField port = new TextField("19000");
    Button connect = new Button("Connect");
    TextArea cTextArea = new TextArea(30, 60);
    JFileChooser cFileChooser = new JFileChooser();
    Button choose = new Button("Choose File");
    TextField chooseFile = new TextField(40);
    Button send = new Button("send");
    CListener cListener = new CListener();

    public ClientFrame(String title) {
        super(title);
        init();

        connect.addActionListener(cListener);
        send.addActionListener(cListener);
        cFileChooser.setCurrentDirectory(new File("."));
        choose.addActionListener(event -> {
            int result = cFileChooser.showOpenDialog(null);

            if (result == JFileChooser.APPROVE_OPTION) {
                name = cFileChooser.getSelectedFile().getPath();
                chooseFile.setText(name);
            }
        });

        addWindowListener(
			new WindowAdapter()	{
	    		public void windowClosing(WindowEvent e) {
		    		try	{
		    			client.close();
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
        setLocation(300, 100);
        setSize(400, 400);
        setResizable(false);
        setBackground(Color.DARK_GRAY);
        cTextArea.setBackground(Color.GRAY);

        Panel North = new Panel();
        North.add(new Label("IP"));
        North.add(this.ip);
        North.add(new Label("Port"));
        North.add(this.port);
        North.add(this.connect);
        this.add(North, BorderLayout.NORTH);

        Panel Center = new Panel();
        Center.add(this.cTextArea);
        this.add(Center, BorderLayout.CENTER);

        Panel South = new Panel();
        South.add(this.choose);
        South.add(this.chooseFile);
        South.add(this.send);
        this.add(South, BorderLayout.SOUTH);

        pack();
    }

    class CListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            String string = e.getActionCommand();
            if ("Connect" == string) {
                try {
                    connect.setEnabled(false);
                    int i = Integer.parseInt(port.getText());
                    cTextArea.append("Server Connect IP: " + ip.getText() + "\nConnect Port: " + port.getText() + "\n");
                    client = new Socket(ip.getText(), i);
                    cTextArea.append("Connecting ...\n");

                    ClientThread clientThread = new ClientThread();
                    clientThread.start();
                } catch(Exception ce) {
                    ce.printStackTrace();
                }
            }
            else if ("Send" == string) {
                try {
                    String str = chooseFile.getText();
                    PrintWriter cc = new PrintWriter(client.getOutputStream());
                    if (str != "") {
                        cc.write("Client: " + str + "\n");
                        cc.flush();
                        cTextArea.append("Client: " + str + "\n");
                    }
                    chooseFile.setText("");
                } catch(Exception se) {
                    se.printStackTrace();
                }
            }
        }
    }

    class ClientThread extends Thread {
        public void run() {
            try {
                BufferedReader br = new BufferedReader(new InputStreamReader(client.getInputStream()));
                String s = br.readLine();
                while (!"Server: Quit".equals(s) && s != null) {
                    cTextArea.append(s + "\n");
                    s = br.readLine();
                }
            } catch(Exception re) {
                re.printStackTrace();
            }
        }
    }
}

public class FileClient {
    public static void main(String[] args) {
        ClientFrame clientFrame = new ClientFrame("Client");
    }
}