''' Trabalho 1A:
Programar a versão do QuickSort para uma quantidade qualquer de pivô
dada como entrada, para um vetor também com uma quantidade qualquer 
de elementos de entrada.
'''

def quickSort(vetor, qtdPivos):
    #Tamanho do vetor seja 1(trivialmente ordenado)
    #  ou 0(vetor vazio)
    if len(vetor) <= 1:
        return
    
    #Caso tenha mais pivôs que elementos
    if qtdPivos > len(vetor):
        qtdPivos = len(vetor)
        #faz com que todos os elementos sejam pivôs 

    pivos = escolhePivo(vetor, qtdPivos)
    ordenaPivos(pivos)

    particoes = []
    #cria k+1 partições (subvetores)
    for i in range(qtdPivos+1):
        particoes.append([])


    #cria uma copia do subvetor atual 
    # e retira os pivos de dentro
    subvet = vetor.copy()
    for pivo in pivos:
        subvet.remove(pivo)


    #percorre todos os elementos do subvetor(sem os pivôs)
    # e decide em qual partição cada um vai ficar
    for elem in subvet:
        i=0

        while i<qtdPivos and elem > pivos[i]:
            i += 1

        particoes[i].append(elem)

    #Chama recursivamente para cada partição 
    # e depois junta todas as partições num unico vetor final
    vetFinal = []

    for i in range(qtdPivos):
        quickSort(particoes[i], qtdPivos)
        vetFinal.extend(particoes[i])
        vetFinal.append(pivos[i])

    quickSort(particoes[qtdPivos], qtdPivos)
    vetFinal.extend(particoes[qtdPivos])


    vetor[:] = vetFinal

def escolhePivo(vetor, k):
    pivos = []
    for i in range(0, k):
        posicao = (i*len(vetor)) // k 
        pivos.append(vetor[posicao])

    return pivos

def ordenaPivos(pivos):
    for i in range(0, len(pivos)):
        troca=0
        for j in range (0, len(pivos)-1-i):
            if pivos[j] > pivos[j+1]:
                pivos[j], pivos[j+1] = pivos[j+1], pivos[j]
                troca=1

        if not troca: break


def main():

    vetor =  list(map(float, input("Digite os elementos do vetor(separados por espaço. Aperte 'enter' ao terminar): ").split()))

    qtdPivos = int(input("Digite a quantidade de pivos(maior ou igual a 1): "))
    
    while qtdPivos < 1:
        qtdPivos = int(input("Digite a quantidade de pivos (maior ou igual a 1): "))


    print("Vetor antes da ordenação:", vetor)
    quickSort(vetor, qtdPivos)
    print("Vetor depois da ordenação:", vetor)

main()