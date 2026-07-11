from Cor import *

class Produto:
    def __init__(self, nome, preco, codigo, estqIdeal, estoque=0):
        self.nome = nome
        self.preco = preco
        self.codigo = codigo
        self.estoque = estoque
        self.estqIdeal = estqIdeal

    def printProd(self):
        return(f"|Produto: {self.nome:<10}Preço: {self.preco}\n"+
               f"|Código: {self.codigo:<11}Estoque Atual: {self.estoque}")
    
    def alterarPreco(self, new_preco):
        if new_preco >= 0:
            self.preco = new_preco
        else: 
            print("Novo preco Inválido")

    def alterar_nome(self, new_nome):
        self.nome = new_nome

    def novoEstoque(self, new_estoque):
        if new_estoque > 0:
            self.estoque = new_estoque
        else: 
            print("Erro! Estoque novo inválido!")

    def verifEstoque(self):
        if self.estoque < self.estqIdeal:
            return Cor.vermelho+f"Estoque de {self.nome} menor que o ideal. Realizar pedido!"+Cor.padrao
        else:
            return ""
        #Cor.verde+"Estoque dentro do ideal!"+Cor.padrao
        

def cadastraProd():
    nome = input("Insira o nome do Produto: ")
    preco = float(input("Insira o preço do produto: "))
    codigo = int(input("Insira o código do produto: "))
    estoqueIni = int(input("Insira o estoque inicial: "))
    estoqueIdeal = int(input("Insira o estoque ideal para o produto: "))

    return Produto(nome, preco, codigo, estoqueIdeal, estoqueIni)