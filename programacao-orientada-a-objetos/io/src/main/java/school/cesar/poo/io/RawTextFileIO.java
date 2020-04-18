package school.cesar.poo.io;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;

public class RawTextFileIO {
    public static void main(String[] args) throws IOException {
        Writer writer = new OutputStreamWriter(new FileOutputStream("teste-raw.txt"));
        writer.write("teste 123");
        writer.flush();
        writer.close();
    }
}