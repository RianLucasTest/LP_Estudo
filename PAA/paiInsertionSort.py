def pairInsertionSort(vet):
    for i in range(0, len(vet)-1, 2):

        n1 = vet[i]
        n2 = vet[i+1]

        #garante sempre que n1 <= n2
        if n1 > n2:
            n1, n2 = n2, n1

        j = i-1

        #Procura a posição a ser inserido 
        #tomando o menor elemento como base
        while j >=0 and vet[j] > n1:
            j -= 1

        k = i-1

        #Garante que a proxima casa depois do j
        #terá espaço avançando tudo duas casas pra frente
        while k > j:
            vet[k+2] = vet[k]
            k -= 1

        #coloca nas casas corretas

        vet[j+1] = n1
        vet[j+2] = n2

    if len(vet)%2 == 1:
        chave = vet[len(vet)-1] #elemento a ser processado
        j = len(vet) -1 -1 #parte ordenada

        while j >=0 and vet[j] > chave:
            vet[j+1] = vet[j]
            j-=1
        vet[j+1] = chave

    return vet

def main():
    v = [8,7,6,5,4,3,10,2,1]

    print(pairInsertionSort(v))

main()