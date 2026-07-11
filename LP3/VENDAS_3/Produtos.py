class Produto:
    def __init__(self, nome, preco, codigo, estqIdeal, estoque=0):
        self.nome = nome
        self.preco = preco
        self.codigo = codigo
        self.estoque = estoque
        self.estqIdeal = estqIdeal

    def printProd(self):
        return (f"|Produto: {self.nome:<10}Preco: {self.preco:.2f}\n" +
                f"|Codigo: {self.codigo:<11}Estoque Atual: {self.estoque}")

    def alterarPreco(self, new_preco):
        if new_preco >= 0:
            self.preco = new_preco
        else:
            raise ValueError("Novo preco invalido")

    def alterar_nome(self, new_nome):
        self.nome = new_nome

    def novoEstoque(self, new_estoque):
        if new_estoque >= 0:
            self.estoque = new_estoque
        else:
            raise ValueError("Estoque novo invalido")

    def verifEstoque(self):
        if self.estoque < self.estqIdeal:
            return f"Estoque de {self.nome} menor que o ideal. Realizar pedido!"
        return ""
