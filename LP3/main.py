from vendas import *

def iniTeste():
    venda1=Venda(1)

    prod1 = Produto("Arroz", 8.9, 1)
    prod2 = Produto("Feijão", 9.7, 2)
    prod3 = Produto("Açúcar", 5.6, 3)
    prod4 = Produto("Maçã", 2.3, 4)

    produtos = [prod1, prod2, prod3, prod4]

    i=35
    for prods in produtos:
        prods.novoEstoque(i)
        i = i+10

    for prods in produtos:
        print(prods.printProd())
    print("")
    
    venda1.inserir_item(Item(prod1, 8))
    venda1.inserir_item(Item(prod2, 10))
    venda1.inserir_item(Item(prod3, 22))
    venda1.inserir_item(Item(prod4, 30))

    venda1.print_venda()

    return produtos, venda1


def main():
    produtos, venda1 = iniTeste()

    while True:

        print("="*20 + "MENU" + "="*20)
        print("1- Listar Produtos",
              "2- Listar Venda",
              "3- Adicionar Item",
              "4- Remover Item",
              "5- Encerrar venda", sep="\n")
        print("="*44)
        
        opcao = input("  Selecione a sua opção: ")
        print()
        
        match opcao:
            case "1":
                print("=============Produtos============")
                for prod in produtos:
                    print("-"*40)
                    print(prod.printProd())
                print("=================================")
                
            case "2":
                venda1.print_venda()

            case "3":
                prodAdd = int(input("Insira o codigo do produto: "))
                
                for prod in produtos:
                    qtdAdd = int(input("Insira a quantidade do produto: "))
                    if prodAdd == prod.codigo:
                        venda1.inserir_item(Item(prod, qtdAdd))
                        break
                else:
                    print("Produto não encontrado no estoque!")
                
            case "4":
                codigoRemove = int(input("Insira o código do produto a ser removido: "))
                for item in venda1.itens:
                    if codigoRemove == item.produto.codigo:
                        venda1.excluir_item(codigoRemove)
                        break
                else:
                    print("Produto não encontrado na venda!")

            case "5":
                print("Encerrando programa!")
                break

            case _:
                print("Opção inválida!")


main()