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

def menuVendedor(produtos):

    while True: 
        print("="*14 + "MENU DO VENDEDOR" + "="*14)
        print("1- Listar Produtos",
            "2- Adicionar Produto",
            "3- Remover Produto",
            "4- Situação Estoque",
            "5- Alterar Estoque",
            "6- Voltar", sep="\n")
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
                produtos.append(cadastraProd())

            case "3":
                prodRemove = int(input("Insira o código do produto a ser removido: "))

                for prod in produtos:
                    if prod.codigo == prodRemove:
                        produtos.remove(prod)
                        break
                else: 
                    print("ERRO: Produto inválido ou não existe!")

            case "4":
                print("=============Estoque============")
                for prod in produtos:
                    print("-"*30)
                    print(f"|Produto: {prod.nome}\n|Estoque: {prod.estoque}")
                    print
                print("=================================")
                
            case "5":
                prodAlter = int(input("Insira o código do produto a ser alterado: "))

                for prod in produtos:
                    if prodAlter == prod.codigo:
                        novoEstq = int(input("Insira o novo estoque"))
                        prod.novoEstoque(novoEstq)
                        break
                else:
                    print("Código de produto inválido!")
                    

            case "6":
                print("Encerrando Menu do Vendedor!")
                return

            case _:
                print("Opção inválida!")
        print()


def main():
    produtos, venda1 = iniTeste()

    while True:

        print("="*20 + "MENU" + "="*20)
        print("1- Listar Produtos",
              "2- Listar Venda",
              "3- Adicionar Item",
              "4- Remover Item",
              "5- Menu de Vendedor",
              "6- Encerrar venda", sep="\n")
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
                codigoAdd = int(input("Insira o codigo do produto: "))
                
                for prod in produtos:

                    if codigoAdd == prod.codigo:
                        qtdAdd = int(input("Insira a quantidade do produto: "))
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
                menuVendedor(produtos)

            case "6":
                print("Encerrando programa!")
                break

            case _:
                print("Opção inválida!")
        print()


main()