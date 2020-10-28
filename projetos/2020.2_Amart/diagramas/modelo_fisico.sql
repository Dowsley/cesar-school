-- DDL
CREATE TABLE Cliente(
	cpf CHAR(11) NOT NULL,
	nome VARCHAR(255) NOT NULL,
	email VARCHAR(255) NOT NULL UNIQUE,
	telefone VARCHAR(20),
	PRIMARY KEY (cpf)
);

CREATE TABLE Pedido(
	cod INT NOT NULL AUTO_INCREMENT,
	preco_total FLOAT(2) NOT NULL,
	parcelas INT NOT NULL,
	data_compra TIMESTAMP NOT NULL,
	cod_rastreio VARCHAR(255) NOT NULL,
	total_itens INT NOT NULL,
	fk_Cliente_cpf CHAR(11) NOT NULL,
	PRIMARY KEY (cod),
	FOREIGN KEY (fk_Cliente_cpf) REFERENCES Cliente(cpf)
);

CREATE TABLE Produto(
	cod INT NOT NULL AUTO_INCREMENT,
	cor VARCHAR(50) NOT NULL,
	tipo VARCHAR(50) NOT NULL,
	tamanho VARCHAR(3) NOT NULL,
  nome VARCHAR(255) NOT NULL,
	material VARCHAR(50) NOT NULL,
	PRIMARY KEY (cod)
);

CREATE TABLE intermediaria_pedido_produto(
	fk_Produto_cod INT NOT NULL,
	fk_Pedido_cod INT NOT NULL,
	FOREIGN KEY (fk_Produto_cod) REFERENCES Produto(cod),
	FOREIGN KEY (fk_Pedido_cod) REFERENCES Pedido(cod)
);

CREATE TABLE Camisa(
	FK_Produto_cod INT NOT NULL,
	medida_ombro FLOAT(2) NOT NULL,
	medida_manga FLOAT(2) NOT NULL,
	comprimento FLOAT(2) NOT NULL,
	medida_torax FLOAT(2) NOT NULL,
  PRIMARY KEY (fk_Produto_cod),
	FOREIGN KEY (fk_Produto_cod) REFERENCES Produto(cod)
);

CREATE TABLE Calça(
	FK_Produto_cod INT NOT NULL,
	medida_cintura FLOAT(2) NOT NULL,
	medida_quadril FLOAT(2) NOT NULL,
	comprimento FLOAT(2) NOT NULL,
  PRIMARY KEY (fk_Produto_cod),
	FOREIGN KEY (fk_Produto_cod) REFERENCES Produto(cod)
);

CREATE TABLE Perfil_de_Medida(
	cod INT NOT NULL AUTO_INCREMENT,
	cintura FLOAT(2) NOT NULL,
	quadril FLOAT(2) NOT NULL,
	altura FLOAT(2) NOT NULL,
	peso FLOAT(2) NOT NULL,
	busto FLOAT(2) NOT NULL,
	fk_Cliente_cpf CHAR(11) NOT NULL,
	PRIMARY KEY (cod),
	FOREIGN KEY (fk_Cliente_cpf) REFERENCES Cliente(cpf)
);

-- DML
INSERT INTO Cliente (cpf,nome,email,telefone)
VALUES (
  '11122233344',
  'Letícia Cavalcanti',
  'lc9@gmail.com',
  '81 9 1111-4444'
);

INSERT INTO Pedido (
  preco_total,parcelas,data_compra,
  cod_rastreio,total_itens,fk_Cliente_cpf
) VALUES (
  50.13, 3, NOW(),
  'EUW7a3FcbQ$JU', 2, '11122233344'
);

INSERT INTO Produto (cor,tipo,tamanho,nome,material)
VALUES (
  '#9fa8f0',
  'blusa',
  'GG',
  'Blusa de Lã Premium',
  'lã',
);

INSERT INTO intermediaria_pedido_produto (
  fk_Produto_cod, fk_Pedido_cod
) VALUES (
  92652, 18123
)

INSERT INTO Camisa (
  FK_Produto_cod,medida_ombro,
  medida_manga,comprimento,medida_torax
) VALUES (
  92652, 50.2,
  43.5, 73.5, 82,
);

INSERT INTO Calça (
  FK_Produto_cod,medida_cintura,
  medida_quadril,comprimento
) VALUES (
  92652, 94.3,
  108, 114
);

INSERT INTO Perfil_de_Medida (
  cintura,quadril,altura,
  peso,busto,fk_Cliente_cpf
) VALUES (
  85.7, 102.1, 182,
  105, 111, '11122233344'
);