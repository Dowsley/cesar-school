# Avaliação 3 - POO
# Aluno: João Felipe Costa Dowsley

### 1. O Java oferece quatro modificadores de acesso para métodos e atributos de classes. Explique a diferença e as aplicações de cada um deles. (2 pontos)

Em Java, pode-se definir a visibilidade dos atributos e métodos das classes. Para este fim, existem 4 modificadores de acesso à disposição: public, protected, private e default (nenhuma palavra-chave especificada, ou seja, padrão).
- **Public**: Este modificador permite com que que um método ou atributo seja visível e de livre acesso para qualquer outra classe na aplicação, interna ou externa ao pacote. Por ter o escopo mais abrangente entre os quatro modificadores, é recomendado que seja usado em métodos de getters e setters para permitir a criação de uma interface de acesso aos atributos de uma classe sem a necessidade de torna-los públicos.

- **Private**: Quase uma antítese do *Public*, o *Private* é a forma mais pura do conceito de ENCAPSULAÇÃO, limitando a visibilidade e acesso de um método/atributo apenas para a própria classe que os contêm. Como complemento para a usabilidade do *Public* em getters e setters, o *private* é recomendado para os atributos, tornando-os apenas acessíveis pela própria classe. Afinal, em orientação a objeto, é ideal que classes possuam a responsabilidade de comunicar seus próprios atributos ao ambiente externo, se importando apenas com formas de tratar a saída e entrada dos valores.

- **Protected**: A diferença entre um método e/ou atributo *Private*, e um *Protected*, é que no segundo somente subclasses ou classes no mesmo pacote podem acessa-los, além da própria classe em si. Isto é, para uma classe acessar um membro *protected* de uma outra classe, é preciso que a primeira seja do mesmo pacote e/ou tenha herança da classe cujo atributo será acessado. Dito isto, este modificador é adequado para classes que foram projetadas para herança, ou também quando classes derivadas oferecem uma funcionalidade para a classe "base". 

- **Default**: Como já citado, métodos e atributos declarados sem modificador são implicitamente *Default*. Membros *default*  podem ser acessados apenas por classes no mesmo pacote. Por ser o padrão, é claro que possui o escopo mais simples, ideal para aplicações simples, embora não seja o recomendado para respeitar o princípio da encapsulação.

---

### 2. No Java temos duas principais hierarquias de exceções: Exception e RuntimeException. Explique as diferenças e aplicações das duas hierarquias. (2 pontos)

Antes de examinar a diferença entre ambas, é necessária uma visão geral da hierarquia de exceções. Ambas as classes *Exception* e *Error* são derivadas da classe *Throwable* (que deriva de *Object*). E a classe *RuntimeException* é derivada da classe Exception. Sobre estas, toda e qualquer classe derivada de *RuntimeException* é uma exceção **não-verificada**, e todas as outras derivadas de Exception que não são a Runtime, são consideradas **verificadas**.

Exceções verificadas dentro de *Exception* precisam ser tratadas de forma explícita no código, ou o compilador não permitirá sua execução. Normalmente é recomendado emitir uma exceção verificada se é esperado que o operador de uma API trate a exceção. 

Por outro lado, as RuntimeExceptions (não-verificadas) não precisam ser tratadas explicitamente. De forma auto-descritiva, este tipo de exceção pode ser lançado quando não é esperado que o programador a trate.

---

### 3. Diferente do Python e do C++, o Java não oferece herança múltipla. Entretanto, há quem argumente que a limitação pode ser contornada através da implementação de múltiplas interfaces. Explique a aplicação de interfaces em softwares orientados a objetos. (2 pontos)

As interfaces em Java foram projetadas para permitir a definição de assinaturas de métodos "*stateless*", que podem ser utilizados e implementados diferentemente por diversas classes. 

Assim, o objetivo de uma interface, até no sentido da palavra, é de servir como uma **API** pública, totalmente abstrata. Elas não só podem resolver o problema da herança múltipla, como podem permitir o polimorfismo de métodos entre classes diferentes que não possuem relação entre si, e também servir como uma forma de implementar o conceito de *Loose Coupling*.

---

### 4. Padrões de projeto oferecem soluções para problemas recorrentes no desenvolvimento de software. Explique os padrões Observer e Singleton vistos em sala de aula. (4 pontos)

O padrão Singleton serve para garantir a existência de uma e somente uma instância global de uma determinada classe na aplicação. Embora não tenha uma forma de definida de aplicar este padrão em Java, pode ser feito através da criação de um escopo *estático*. Os usos e implementações do Singleton falam por si próprios: Serve quando-se necessita de uma e apenas uma instância de uma classe, como por exemplo, um repositório para comunicação com um banco de dados. Por mais que seja citado aqui como um padrão, o Singleton pode facilmente virar um anti-padrão se não utilizado cautelosamente.

O padrão Observer define uma relação de objetos do tipo "um-para-muitos" que consiste de um ou mais "observadores" dependentes de um objeto, que são notificados quando este muda de estado. Este padrão é amplamente utilizado em diversas situações, como por exemplo:

- Modelos de arquitetura de redes sociais, onde objetos de usuários são notificados das ações de um outro usuário que eles "seguem".

- Object-Relational Mapping, uma forma de comunicação com bancos de dados SQL, utilizado em Frameworks de back-end. Nestes, como classes definem tabelas, e instâncias definem linhas (rows), o uso do padrão Observer é especialmente útil para uma relação "one-to-many", onde um objeto pode ser referenciado por vários outros diferentes, mas não tem visibilidade de quais estes são. Logo, a responsabilidade da "notificação" caso o estado deste objeto referenciado mude é dos observadores, que possuem uma referência a ele, e não o contrário.

---