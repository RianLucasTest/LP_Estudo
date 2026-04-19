class Produto:
    def __init__(self, codigo, nome, preco):
        self.codigo = codigo
        self.nome = nome
        self.preco = preco

    def alterar_preco(self, novo_preco):
        if novo_preco > 0:
            self.preco = novo_preco
        else:
            print("Preco invalido.")

    def exibir_dados(self):
        print(f"Codigo: {self.codigo}")
        print(f"Nome: {self.nome}")
        print(f"Preco: R$ {self.preco:.2f}")


class ItemVenda:
    def __init__(self, produto, quantidade):
        self.produto = produto
        self.quantidade = quantidade

    def calcular_subtotal(self):
        return self.produto.preco * self.quantidade

    def exibir_item(self):
        print(f"Produto: {self.produto.nome}")
        print(f"Quantidade: {self.quantidade}")
        print(f"Preco unitario: R$ {self.produto.preco:.2f}")
        print(f"Subtotal: R$ {self.calcular_subtotal():.2f}")


class Venda:
    def __init__(self, numero):
        self.numero = numero
        self.itens = []

    def adicionar_item(self, item_venda):
        self.itens.append(item_venda)

    def remover_item(self, codigo_produto):
        for item in self.itens:
            if item.produto.codigo == codigo_produto:
                self.itens.remove(item)
                print("Item removido com sucesso.")
                return
        print("Produto nao encontrado na venda.")

    def calcular_total(self):
        total = 0
        for item in self.itens:
            total += item.calcular_subtotal()
        return total

    def exibir_venda(self):
        print("=" * 40)
        print(f"VENDA N. {self.numero}")
        print("=" * 40)
        if len(self.itens) == 0:
            print("Nenhum item na venda.")
        else:
            for item in self.itens:
                item.exibir_item()
                print("-" * 40)
            print(f"TOTAL DA VENDA: R$ {self.calcular_total():.2f}")
        print("=" * 40)


# Programa principal
def main():
    # Cadastro de alguns produtos
    p1 = Produto(1, "Arroz 5kg", 28.90)
    p2 = Produto(2, "Feijao 1kg", 8.50)
    p3 = Produto(3, "Oleo de Soja", 6.99)
    p4 = Produto(4, "Macarrao", 4.75)
    

    produtos = [p1, p2, p3, p4]

    venda = Venda(1234)

    while True:
        print("\n=== SISTEMA DE VENDAS ===")
        print("1 - Listar produtos")
        print("2 - Adicionar item a venda")
        print("3 - Remover item da venda")
        print("4 - Exibir venda")
        print("5 - Finalizar venda")
        print("0 - Sair")

        opcao = input("Escolha uma opcao: ")

        if opcao == "1":
            print("\n--- PRODUTOS DISPONIVEIS ---")
            for produto in produtos:
                produto.exibir_dados()
                print("-" * 30)

        elif opcao == "2":
            codigo = int(input("Digite o codigo do produto: "))
            quantidade = int(input("Digite a quantidade: "))

            produto_encontrado = None
            for produto in produtos:
                if produto.codigo == codigo:
                    produto_encontrado = produto
                    break

            if produto_encontrado is not None:
                item = ItemVenda(produto_encontrado, quantidade)
                venda.adicionar_item(item)
                print("Item adicionado com sucesso.")
            else:
                print("Produto nao encontrado.")

        elif opcao == "3":
            codigo = int(input("Digite o codigo do produto a remover: "))
            venda.remover_item(codigo)

        elif opcao == "4":
            venda.exibir_venda()

        elif opcao == "5":
            print("\nVenda finalizada.")
            venda.exibir_venda()
            break

        elif opcao == "0":
            print("Encerrando o sistema.")
            break

        else:
            print("Opcao invalida.")


main()