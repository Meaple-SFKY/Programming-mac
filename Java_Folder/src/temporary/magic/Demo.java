package src.temporary.magic;

import javax.swing.JFrame;
import javax.swing.JTextField;
import javax.swing.JComponent;

public class Demo {
	public static void main(String[] args) {
		JFrame jFrame = new JFrame("Hello World!");
		JTextField jTextField = new JTextField(10);
		String s = new String("Google");
		jTextField.setText(s);
		jFrame.addNotify();
	}
}