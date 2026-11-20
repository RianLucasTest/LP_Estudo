''' Trabalho 1B
Programar o algoritmo HeapSort considerando que 
cada nó não folha pode ter uma quantidade qualquer
de filhos dada como entrada
'''

def sift(vetor, i, tam, qtdFilho):
    maior = i

    #Calcula o primeiro filho e o ultimo filho do nó atual 
    primeiroFilho= (qtdFilho * i) + 1
    ultimoFilho= (qtdFilho * i) + qtdFilho

    #Garante que os filhos estejam dentro do vetor
    if ultimoFilho >= tam:
        ultimoFilho = tam-1

    #Verifica entre todos os filhos qual o indice do maior
    for atual in range(primeiroFilho, ultimoFilho+1):
        if vetor[atual] > vetor[maior]:
            maior = atual

    #Se o maior for diferente do pai, a troca é realizada 
    # e repete o processo naquele ramo
    if maior != i:
        vetor[i], vetor[maior] = vetor[maior], vetor[i]
        sift(vetor, maior, tam, qtdFilho)


def build(vetor, tam, qtdFilho):
    #Começa do ultimo nó não-folha e vai até a raíz
    # montando o heap
    for i in range((tam-2) // qtdFilho, -1, -1):
        sift(vetor, i, tam, qtdFilho)


def heapSort(vetor, qtdFilho):
    tam = len(vetor)

    #monta o heap inicial
    build(vetor, tam, qtdFilho)

    #Coloca o maior valor na raíz, depois coloca-o na última posição
    # e desconsidera as posições definitivas
    for i in range(tam-1, 0, -1):
        vetor[i], vetor[0] = vetor[0], vetor[i]
        sift(vetor, 0, i, qtdFilho)

    return vetor


def main():

    vetor =  list(map(float, input("Digite os elementos do vetor(separados por espaço. Aperte 'enter' ao terminar): ").split()))

    qtdFilhos = int(input("Digite a quantidade de filhos (maior ou igual a 1): "))

    while qtdFilhos < 1:
        qtdFilhos = int(input("Digite a quantidade de filhos (maior ou igual a 1): "))


    print("Vetor antes da ordenação:", vetor)
    vetor = heapSort(vetor, qtdFilhos)
    print("Vetor depois da ordenação:", vetor)

main()