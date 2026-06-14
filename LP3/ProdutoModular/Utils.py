from Vendas import *
from Item import *
from Produtos import *
import os

def limpaTela():
    sistema = os.name
    if sistema == "nt":
        os.system("cls")
    if sistema == "posix":
        os.system("clear")

def iniTeste(logs):
    venda1=Venda(1)

    prod1 = Produto("Arroz", 8.9, 1, 30)
    prod2 = Produto("Feijão", 9.7, 2, 30)
    prod3 = Produto("Açúcar", 5.6, 3, 20)
    prod4 = Produto("Maçã", 2.3, 4, 20)

    produtos = [prod1, prod2, prod3, prod4]

    i=65
    for prods in produtos:
        prods.novoEstoque(i)
        i = i-10

    for prods in produtos:
        print(prods.printProd())
    print("")
    
    venda1.inserir_item(Item(prod1, 38), logs)
    venda1.inserir_item(Item(prod2, 23), logs)
    venda1.inserir_item(Item(prod3, 22), logs)
    venda1.inserir_item(Item(prod4, 30), logs)

    venda1.print_venda()

    return produtos, venda1
