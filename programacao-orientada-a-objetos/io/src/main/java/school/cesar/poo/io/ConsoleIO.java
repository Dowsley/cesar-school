package school.cesar.poo.io;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class ConsoleIO {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Informe seu nome:");
        String nome = reader.readLine();
        System.out.println("Olá " + nome);
    }
}