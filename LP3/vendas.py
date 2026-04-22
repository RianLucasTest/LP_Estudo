class Cor:
    padrao = "\033[0m" #Padrão
    ciano = "\033[36m" #Ciano
    azul = "\033[34m" #Azul
    azul_neg = "\033[1;34m" #Azul Negrito
    verde = "\033[32m" #Verde
    amarelo = "\033[33m" #Amarelo
    vermelho = "\033[31m" #Vermelho
    red_neg="\033[1;31m" #Vermelho Negrito
    negrito="\033[1m" #Negrito

def relatorio(logs):
    for msg in logs:
        print(f"|{msg}")

def addLog(msg, logs):
    logs.append(msg)

def clearLog(logs):
    logs=[]

class Venda:
    def __init__(self, num):
        self.num = num
        self.itens = []

    def inserir_item(self, item, logs):
        self.itens.append(item)
        addLog(f"Item {item.produto.nome} adicionado à venda {self.num}", logs)

    def excluir_item(self, codigo, logs):
        for item in self.itens:
            if item.produto.codigo == codigo:
                self.itens.remove(item)
                addLog(f"Item {item.produto.nome} removido da venda {self.num}", logs)
                return

        print("ERRO: Item não existe na venda")

    def calc_total(self):
        soma=0
        for item in self.itens:
            soma += item.subtotal()
        return round(soma, 2)

    def print_venda(self):
        print(Cor.ciano+"="*40+Cor.padrao)
        print(Cor.negrito+f"Venda n° {self.num}")
        print(Cor.ciano+"="*40+Cor.padrao)

        for item in self.itens:
            print("-"*30)
            print(f"{item.printItem()}")
            print("-"*30)

        print(Cor.azul_neg+f"TOTAL: {self.calc_total()}"+Cor.padrao)
        print("="*40)

class Produto:
    def __init__(self, nome, preco, codigo, estqIdeal, estoque=0):
        self.nome = nome
        self.preco = preco
        self.codigo = codigo
        self.estoque = estoque
        self.estqIdeal = estqIdeal

    def printProd(self):
        return(f"|Produto: {self.nome:<10}Preço: {self.preco}\n"+
               f"|Código: {self.codigo:<12}Estoque Atual: {self.estoque}")
    
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
            return Cor.vermelho+"Estoque menor que o ideal. Realizar pedido!"+Cor.padrao
        else:
            return Cor.verde+"Estoque dentro do ideal!"+Cor.padrao


class Item:
    def __init__(self, produto, qtd):
        self.produto = produto
        self.qtd = qtd
        self.alteraEstoque(qtd)

    def alteraEstoque(self, qtd):
        if qtd > 0:
            novo = self.produto.estoque - qtd
            self.produto.novoEstoque(novo)
        else: 
            print("Compra inválida! Não há estoque suficiente")

    def printItem(self):
        return (f"{self.produto.printProd()}\n|Quantidade: {self.qtd}\n"+
                f"|Subtotal: " + Cor.verde + f"{self.subtotal():.2f}" + Cor.padrao)

    def subtotal(self):
        return (self.qtd * self.produto.preco)
    
    def alterar_qtd(self, new_qtd):
        if new_qtd < 0:
            print("Quantidade inválida")
        else: 
            self.qtd = new_qtd


def cadastraProd():
    nome = input("Insira o nome do Produto: ")
    preco = float(input("Insira o preço do produto: "))
    codigo = int(input("Insira o código do produto: "))
    estoqueIni = int(input("Insira o estoque inicial: "))
    estoqueIdeal = int(input("Insira o estoque ideal para o produto: "))

    return Produto(nome, preco, codigo, estoqueIdeal, estoqueIni)
