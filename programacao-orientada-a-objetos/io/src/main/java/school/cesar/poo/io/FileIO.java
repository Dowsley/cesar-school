package school.cesar.poo.io;

import java.io.FileOutputStream;
import java.io.IOException;

public class FileIO {
    public static void main(String[] args) throws IOException {
        FileOutputStream fos = new FileOutputStream("teste.bin");
        fos.write(new byte[]{123, 19, -2, 18});
        fos.flush();
        fos.close();
    }
}