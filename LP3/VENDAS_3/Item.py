class Item:
    def __init__(self, produto, qtd):
        self.produto = produto
        self.qtd = qtd
        self.alteraEstoque(qtd)

    def alteraEstoque(self, qtd):
        if qtd > 0 and qtd <= self.produto.estoque:
            novo = self.produto.estoque - qtd
            self.produto.novoEstoque(novo)
        else:
            raise ValueError("Quantidade invalida ou estoque insuficiente!")

    def printItem(self):
        return (f"{self.produto.printProd()}\n|Quantidade: {self.qtd}\n" +
                f"|Subtotal: {self.subtotal():.2f}")

    def subtotal(self):
        return self.qtd * self.produto.preco

    def alterar_qtd(self, new_qtd):
        if new_qtd < 0:
            raise ValueError("Quantidade invalida")
        self.qtd = new_qtd
