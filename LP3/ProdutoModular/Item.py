from Cor import *

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
    