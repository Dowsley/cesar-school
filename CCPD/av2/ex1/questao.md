# Questão 1

Implemente um servico REST em Flask capaz de converter velocidades entre quilômetros por hora (km/h) e milhas por hora (mph).
Não é necessário usar blueprints ou MethodViews.
A aplicação deve apresentar dois endpoints:
/api/tokmh e /api/tomph
Ambos os endpoints devem esperar receber um objeto JSON com o seguinte formato:
```
{ "speed": 100 }
```
E devolver um objeto com o mesmo formato, na velocidade convertida:
```
{ "speed": 166 }
```