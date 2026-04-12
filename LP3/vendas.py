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
        print("|Produto\t|Valor Unitário\t|Código\t|Quantidade\t|Subtotal")

        for item in self.itens:
            print(f"{item.printItem()}\t|{item.subtotal()}")

        print("\033[1m"+f"TOTAL: {self.calc_total()}"+"\033[0m")
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
        return (f"{self.produto.printProd()}\t\t|{self.qtd}")

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