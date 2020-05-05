/*------------------  Inventory.java  --------------*/

package src.learn.exp3;

import java.io.*;
import java.util.Vector;
 
 
//存放Inventory.txt文件内容的类
class InventoryClass {
	String itemNumber;
	int quantity;
	String Supplier;
	String Description;
}
 
	
//存放Transactions.txt文件出货内容的类
class TransactionsO {
	String itemNumber;
	int quantity;
	String custom;
	String itemNumbers;
}
 
//存放Transactions.txt文件增加货物的类
class TransactionsA {
    String itemNumber;
	int quantity;
	String custom;
	String itemNumbers;
}

//存放Transactions.txt文件到货内容的类
class TransactionsR {
	String itemNumber;
	String itemNumbers;
	int quantity;
}
 
//存放Transactions.txt文件删除货物内容的类
class TransactionsD {
	String itemNumber;
	String itemNumbers;
}
 
 
public class Inventory {
	
	//创建存放InventoryClass,TransactionsO，TransactionsR,TransactionsA,TransactionsD对象的数组
	static Vector<InventoryClass> vecInventory = new Vector<InventoryClass>();
	static Vector<TransactionsO> vecTransactionOs = new Vector<TransactionsO>();
	static Vector<TransactionsR> vecTransactionRs = new Vector<TransactionsR>();
	static Vector<TransactionsA> vecTransactionAs = new Vector<TransactionsA>();
	static Vector<TransactionsD> vecTransactionDs = new Vector<TransactionsD>();
	
	public static void main(String[] args) throws IOException {
		//创建文件对象
		File fileInventory = new File("Inventory.txt");
		File fileTransaction = new File("Transactions.txt");
				
		//读入Inventory.txt内容并存入InventoryClass对象中
		try {
			
			FileReader fileReader = new FileReader(fileInventory);
			BufferedReader bufferedReader = new BufferedReader(fileReader);
			String s = null;
			
			while((s = bufferedReader.readLine()) != null) {			
				//利用正则表达式将读取到的每行字符串分解
				String regex = "\\s+";
				String temp[] = s.split(regex);				
				//创建InventoryClass对象存放数据并将对象存入数组
				InventoryClass i = new InventoryClass();
				i.itemNumber = temp[0];
				i.quantity = Integer.parseInt(temp[1]);
				i.Supplier = temp[2];
				i.Description = temp[3];
				vecInventory.add(i);
			}
			fileReader.close();
			bufferedReader.close();
			
			//逐行读入Transactions.txt内内容并存入Transactions对象中
			FileReader fileReaders = new FileReader(fileTransaction);
			BufferedReader bufferedReaders = new BufferedReader(fileReaders);
			String s1 = null;
			while((s1 = bufferedReaders.readLine()) != null) {			
				//利用正则表达式将读取到的每行字符串分解
				String regex = "\\s+";
				String temp[] = s1.split(regex);								
				//对Transactions中格式不同的命令分别储存
				//创建Transactions对象存放出货命令并将对象存入数组
 
				if(temp[0].equals("O")) {
				TransactionsO i = new TransactionsO();
				i.itemNumber = temp[0];
				i.quantity = Integer.parseInt(temp[2]);
				i.custom = temp[3];
				i.itemNumbers = temp[1];
				vecTransactionOs.add(i);
				}
				else if(temp[0].equals("A")) {
					TransactionsA i = new TransactionsA();
					i.itemNumber = temp[0];
					i.quantity = Integer.parseInt(temp[2]);
					i.custom = temp[3];
					i.itemNumbers = temp[1];
					vecTransactionAs.add(i);
				}
				else if(temp[0].equals("R")) {
					TransactionsR i = new TransactionsR();
					i.itemNumber = temp[0];
					i.quantity = Integer.parseInt(temp[2]);
					i.itemNumbers = temp[1];
					vecTransactionRs.add(i);
				}
				else if(temp[0].equals("D")) {
					TransactionsD i = new TransactionsD();
					i.itemNumber = temp[0];
					i.itemNumbers = temp[1];
					vecTransactionDs.add(i);
				}				
			}
			fileReaders.close();
			bufferedReaders.close();
		} catch (IOException e) {
			System.out.println("Failed to read!");
		}
		
		//创建文件对象
		File fileNew = new File("NewInventory.txt");
		File fileS = new File("Shipping.txt");	
		File fileError = new File("Errors.txt");
		FileWriter fileWriterNew = new FileWriter(fileNew);
		FileWriter fileWriterS = new FileWriter(fileS);
		FileWriter fileWriterError = new FileWriter(fileError);
		BufferedWriter bufferedWriterNew = new BufferedWriter(fileWriterNew);
		BufferedWriter bufferedWriterS = new BufferedWriter(fileWriterS);
		BufferedWriter bufferedWriterError = new BufferedWriter(fileWriterError);	
		//执行增加货物的方法
		for(int i = 0; i < vecTransactionAs.size(); i++) {					
			TransactionsA transactionsA = new TransactionsA();
			transactionsA = vecTransactionAs.get(i);				
				try {
					//将a对象中的数据存入字符串并写入文件中					
					String str = transactionsA.itemNumbers + "\t" + String.valueOf(transactionsA.quantity) + "\t"+transactionsA.custom;
					bufferedWriterNew.write(str);
					bufferedWriterNew.newLine();					
				} catch (IOException e) {
					System.out.println("Failed to add item;");
				}															
		}
		//执行到货方法
		for(int i = 0; i < vecTransactionRs.size(); i++) {
			TransactionsR transactionsR = new TransactionsR();
			transactionsR = vecTransactionRs.get(i);
			//获取到货指令中的货物编号和数量
			String rItemNumber = transactionsR.itemNumbers;
			int rQuantity = transactionsR.quantity;
			//获取对应的货物对象并进行操作
			for(int i1 = 0; i1 < vecInventory.size(); i1++) {
				if(vecInventory.get(i1).itemNumber.equals(rItemNumber))
					vecInventory.get(i1).quantity += rQuantity;
			}
		}
		
		//对发货指令的数组按发货数目从小到大进行排序	
		for(int i = 0; i < vecTransactionOs.size() - 1; i++) {
			for(int j = i + 1; j < vecTransactionOs.size(); j++) {
			    String itemNumber1 = vecTransactionOs.get(i).itemNumbers;
                String Supplier1 = vecTransactionOs.get(j).custom;
                String itemNumber2 = vecTransactionOs.get(j).itemNumbers;
                String Supplier2 = vecTransactionOs.get(j).custom;
			    int quantity1 = vecTransactionOs.get(i).quantity;
			    int quantity2 = vecTransactionOs.get(j).quantity;
                //交换对象内的数据
		        if(vecTransactionOs.get(i).quantity > vecTransactionOs.get(j).quantity) {
		        	vecTransactionOs.get(i).itemNumbers = itemNumber2;
		        	vecTransactionOs.get(i).quantity = quantity2;
		        	vecTransactionOs.get(i).custom = Supplier2;
		        	vecTransactionOs.get(j).itemNumbers = itemNumber1;
		        	vecTransactionOs.get(j).quantity = quantity1;
		        	vecTransactionOs.get(j).custom = Supplier1;
		        }
			}
		}
		//执行发货方法
		for(int i = 0; i < vecTransactionOs.size(); i++) {
			//获取发货指令中的编号和数目
			TransactionsO O = vecTransactionOs.get(i);
			String itemString = vecTransactionOs.get(i).itemNumbers;
			int quantity = vecTransactionOs.get(i).quantity;
			//获取对应的货物对象并进行操作
			for(int j = 0; j < vecInventory.size(); j++) {
				if(vecInventory.get(j).itemNumber.equals(itemString)) {
					//判断剩余货物足够
					if(quantity <= vecInventory.get(j).quantity) {
						//执行发货并记录
						vecInventory.get(j).quantity -= quantity;											
						String str = O.itemNumber + "\t" + O.itemNumbers + "\t" + String.valueOf(O.quantity) + "\t" + O.custom;
						bufferedWriterS.write(str);
						bufferedWriterS.newLine();
					}
					//
					else if(quantity>vecInventory.get(j).quantity) {
						//记录错误信息
						String str = "itemNumber " + O.itemNumbers + " Insufficient goods";
						bufferedWriterError.write(str);
						bufferedWriterError.newLine();
					}
				}
			}
        }
        
		//执行删除方法
		for(int i = 0; i < vecTransactionDs.size(); i++) {
			String str = vecTransactionDs.get(i).itemNumbers;
			for(int j = 0; j < vecInventory.size(); j++) {
				if(vecInventory.get(j).itemNumber.equals(str)) {
					vecInventory.removeElementAt(j);
				}
			}
		}		
		//更新NewInventory
		for(int i = 0; i < vecInventory.size(); i++) {
			InventoryClass i1 = new InventoryClass();
			i1.itemNumber = vecInventory.get(i).itemNumber;
			i1.quantity = vecInventory.get(i).quantity;
			i1.Supplier = vecInventory.get(i).Supplier;
			i1.Description = vecInventory.get(i).Description;
			String str = i1.itemNumber + "\t" + String.valueOf(i1.quantity) + "\t"+i1.Supplier + "\t" + i1.Description;
			bufferedWriterNew.write(str);
			bufferedWriterNew.newLine();		
		}
		//关闭流
		bufferedWriterError.close();
		fileWriterError.close();	
		bufferedWriterS.close();
		fileWriterS.close();
		bufferedWriterNew.close();
		fileWriterNew.close();
	}
}