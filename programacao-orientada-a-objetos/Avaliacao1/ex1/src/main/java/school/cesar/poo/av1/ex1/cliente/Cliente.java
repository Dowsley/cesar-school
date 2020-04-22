package school.cesar.poo.av1.ex1.cliente;

public class Cliente {
    private String nome;
    private String cpf;
    private boolean vip;
    private int idade;
    private double renda;

    /* Setters */
    public Cliente setNome(String nome) throws Exception {
        if (nome == null || nome.equals("")) throw new Exception("Nome não pode ser vazio ou nulo");  
        this.nome = nome;
        return this;
    }
    public Cliente setCpf(String cpf) throws Exception {
        if (cpf == null || cpf.equals("")) throw new Exception("CPF não pode ser vazio ou nulo"); 
        this.cpf = cpf;
        return this;
    }
    public Cliente setVip(boolean vip) {
        this.vip = vip;
        return this;
    }
    public Cliente setIdade(Integer idade) throws Exception {
        if (idade == null || idade < 0) throw new Exception("Idade não pode ser negativa ou nula");
        this.idade = idade;
        return this;
    }
    public Cliente setRenda(Double renda) throws Exception {
        if (renda == null || renda < 0) throw new Exception("Renda não pode ser negativa ou nula");
        this.renda = renda;
        return this;
    }

    /* Getters */
    public String getNome() {
        return this.nome;
    }
    public String getCpf() {
        return this.cpf;
    }
    public boolean isVip() {
        return this.vip;
    }
    public int getIdade() {
        return this.idade;
    }
    public double getRenda() {
        return this.renda;
    }
}
