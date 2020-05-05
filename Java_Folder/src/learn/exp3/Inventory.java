package src.learn.exp3;

import java.io.*;

class InventoryClass {
    String itemNumber;
    int quantity;
    String supplier;
    String description;

    public InventoryClass(String itemNumber, int quantity, String supplier, String description) {
        this.itemNumber = itemNumber;
        this.quantity = quantity;
        this.supplier = supplier;
        this.description = description;
    }

    public String getString() {
        String string = String.valueOf(quantity);
        return itemNumber + string + supplier + description;
    }
}

class Transaction {
    String type;
    String itemNumber;

    public Transaction(String type, String itemNumber) {
        this.type = type;
        this.itemNumber = itemNumber;
    }
}

class TransactionsO extends Transaction {
    int quantity;
    String supplier;

    public TransactionsO(String type, String itemNumber, int quantity, String supplier) {
        super(type, itemNumber);
        this.quantity = quantity;
        this.supplier = supplier;
    }
}

class TransactionsR extends Transaction {
    int quantity;

    public TransactionsR(String type, String itemNumber, int quantity) {
        super(type, itemNumber);
        this.quantity = quantity;
    }
}

class TransactionsA extends Transaction {
    String supplier;
    String description;

    public TransactionsA(String type, String itemNumber, String supplier, String description) {
        super(type, itemNumber);
        this.supplier = supplier;
        this.description = description;
    }
}

class TransactionD extends Transaction {
    public TransactionD(String type, String itemNumber) {
        super(type, itemNumber);
    }
}

class Err {
    String itemNumber;
    int quantity;
    String supplier;
}

public class Inventory {
    public static void main(String[] args) throws IOException, FileNotFoundException {
        try {
            File fileInventory = new File("Inventory.java");
            File fileTransactions = new File("Transactions.txt");
            File fileShipping = new File("Shipping.txt");
            File fileNewInventory = new File("NewInventory.txt");

            if (fileShipping.exists() == true) {
                fileShipping.delete();
            }
            if (fileNewInventory.exists() == true) {
                fileNewInventory.delete();
            }

            fileShipping.createNewFile();
            fileNewInventory.createNewFile();

            FileInputStream streamInventory = new FileInputStream(fileInventory);
            FileInputStream streamTransactions = new FileInputStream(fileTransactions);
            FileOutputStream streamShipping = new FileOutputStream(fileShipping);
            FileOutputStream streamNewInventory = new FileOutputStream(fileNewInventory);

            BufferedInputStream bufferInventory = new BufferedInputStream(streamInventory);
            BufferedInputStream bufferTransactions = new BufferedInputStream(streamTransactions);
            BufferedOutputStream bufferShipping = new BufferedOutputStream(streamShipping);
            BufferedOutputStream bufferNewInventory = new BufferedOutputStream(streamNewInventory);


            
        } catch(FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}