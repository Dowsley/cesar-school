package school.cesar.poo.io;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.Writer;

public class TextFileIO {
    public static void main(String[] args) throws IOException {
        PrintWriter writer = new PrintWriter(new OutputStreamWriter(new FileOutputStream("teste.txt")));
        writer.println("teste 123");
        writer.flush();
        writer.close();
    }
}