
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


class Venda:
    def __init__(self, num):
        self.num = num
        self.itens = []

    def inserir_item(self, item):
        self.itens.append(item)

    def excluir_item(self, codigo):
        for item in self.itens:
            if item.produto.codigo == codigo:
                self.itens.remove(item)
                return

        print("ERRO: Item não existe na venda")

    def calc_total(self):
        soma=0
        for item in self.itens:
            soma += item.subtotal()
        return soma

    def print_venda(self):
        print(f"Venda n° {self.num}")
        print("="*69)
        print("|" + Cor.amarelo + "Produto\t" + Cor.padrao+
              "|" + Cor.amarelo + "Valor Unitário\t" + Cor.padrao+
              "|" + Cor.amarelo + "Código\t" + Cor.padrao+
              "|" + Cor.amarelo + "Quantidade\t" + Cor.padrao+
              "|" + Cor.amarelo + "Subtotal" + Cor.padrao)

        for item in self.itens:
            print(f"{item.printItem()}\t\t|"+Cor.verde+f"{item.subtotal()}"+Cor.padrao)

        print(Cor.azul_neg+f"TOTAL: {self.calc_total()}"+Cor.padrao)
        print("="*69)

class Produto:
    def __init__(self, nome, preco, codigo):
        self.nome = nome
        self.preco = preco
        self.codigo = codigo

    def printProd(self):
        return(f"|{self.nome}\t\t|{self.preco}\t\t|{self.codigo}")
    
    def alterarPreco(self, new_preco):
        if new_preco >= 0:
            self.preco = new_preco
        else: 
            print("Novo preco Inválido")

    def alterar_nome(self, new_nome):
        self.nome = new_nome

class Item:
    def __init__(self, produto, qtd):
        self.produto = produto
        self.qtd = qtd

    def printItem(self):
        return (f"{self.produto.printProd()}\t|{self.qtd}")

    def subtotal(self):
        return (self.qtd * self.produto.preco)
    
    def alterar_qtd(self, new_qtd):
        if new_qtd < 0:
            print("Quantidade inválida")
        else: 
            self.qtd = new_qtd


def criaItem(nome, preco, codigo, qtd):
    prod = Produto(nome, preco, codigo)
    item = Item(prod, qtd)
    return item