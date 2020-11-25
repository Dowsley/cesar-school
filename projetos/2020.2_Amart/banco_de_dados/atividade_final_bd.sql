# Básicos
SELECT * FROM pessoa WHERE Sexo='F';
SELECT Nome, Sexo, Idade FROM pessoa WHERE idade>=37 AND idade<=43;
SELECT Nome, Sexo, Idade FROM pessoa WHERE Sexo='M' AND idade>40;
SELECT * FROM pessoa WHERE Nome LIKE 'R%' OR Nome LIKE 'E%';
SELECT * FROM pessoa WHERE idade%2 = 0;
SELECT COUNT(*) AS 'Total de Pessoas', MIN(Idade) AS 'Idade Mínima', MAX(Idade) AS 'Idade Máxima', AVG(Idade) AS 'Idade Média' FROM pessoa;

#Intermediários
SELECT * FROM aloca INNER JOIN pessoa ON Pessoa_CPF=pessoa.CPF ORDER BY Projeto_Codigo;
SELECT * FROM aloca INNER JOIN projeto ON Projeto_Codigo=projeto.Codigo  ORDER BY Pessoa_CPF;
SELECT * FROM aloca INNER JOIN projeto ON Projeto_Codigo=projeto.Codigo  WHERE Pessoa_CPF=123;
SELECT * FROM aloca INNER JOIN pessoa ON Pessoa_CPF=pessoa.CPF WHERE Projeto_Codigo=3344 OR Projeto_Codigo=5566;
SELECT Projeto_Codigo, count(*) FROM aloca Group By Projeto_Codigo;
SELECT Pessoa_CPF, count(*) FROM aloca Group By Pessoa_CPF;

#Avançados
SELECT (SELECT Descricao FROM projeto Where Codigo=Projeto_Codigo) AS 'Descrição', count(*) AS 'Pessoas Alocadas' FROM aloca Group By Projeto_Codigo;
SELECT (SELECT Nome FROM pessoa Where CPF=Pessoa_CPF) AS 'Nome', count(*) AS 'Projetos Alocados' FROM aloca Group By Pessoa_CPF;
SELECT um.Nome, dois.Nome FROM pessoa um INNER JOIN pessoa dois ON dois.CPF=um.Gerente_CPF;
SELECT * FROM aloca INNER JOIN pessoa ON pessoa.CPF=Pessoa_CPF INNER JOIN projeto ON projeto.Codigo=Projeto_Codigo;
SELECT projeto.Descricao, pessoa.Nome FROM aloca INNER JOIN projeto ON projeto.Codigo=aloca.Projeto_Codigo INNER JOIN pessoa ON pessoa.CPF=aloca.Pessoa_CPF;
# 6 Não Fizemos
SELECT pessoa.Nome FROM pessoa WHERE NOT EXISTS(SELECT 1 FROM aloca WHERE aloca.Pessoa_CPF=pessoa.CPF);
# 8 Não FIzemos