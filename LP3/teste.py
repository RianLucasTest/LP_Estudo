lista = []
j=2

for i in range(0,5):
    atividade = (int)(input(f"Insira o {i} elemento da lista"))
    lista.append(atividade)

for item in lista:
    print(f"lista[{item}]=", item)
