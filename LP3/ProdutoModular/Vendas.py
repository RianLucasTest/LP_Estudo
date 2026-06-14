from Cor import *

def relatorio(logs):
    
    print("="*16 + "RELATÓRIO" + "="*15)
    for msg in logs:
        print(f"|{msg}")
    print("="*44)

def addLog(msg, logs):
    if msg == "":
        return
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
        addLog(item.produto.verifEstoque(), logs)

    def excluir_item(self, codigo, logs):
        for item in self.itens:

            if item.produto.codigo == codigo:

                item.produto.novoEstoque(item.produto.estoque + item.qtd)
                self.itens.remove(item)
                addLog(f"Item {item.produto.nome} removido da venda {self.num}", logs)
                addLog(item.produto.verifEstoque(), logs)
                
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
        print(Cor.ciano+"="*40+Cor.padrao)